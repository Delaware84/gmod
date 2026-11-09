#include "install.hpp"

#include <windows.h>
#include <psapi.h>
#include <cstring>
#include "../globals.hpp"
#include "../logger.hpp"
#include "../util.hpp"
#include "../Memory.h"
#include "../sdk.hpp"
#include "create_move.hpp"
#include "get_user_cmd.hpp"
#include "frame_stage_notify.hpp"

namespace {

    bool EnsureModule(const char* name) {
        if (GetModuleHandleA(name)) return true;

        HMODULE module = LoadLibraryA(name);
        if (module) {
            LogWarn("[MODULE] %s loaded manually (%p)", name, module);
            return true;
        }

        LogErr("[MODULE] %s not loaded, LoadLibrary failed (%lu)", name, GetLastError());
        return false;
    }

    void SetOnce(void*& slot, void* value, const char* id) {
        if (slot) return;
        slot = value;
        if (value) Log("[IFACE] %-46s = %p", id, value);
        else       LogErr("[IFACE] %-46s = nullptr", id);
    }

    bool LooksLikeVmt(void** vmt, int count) {
        if (!vmt || !IsReadable(vmt, count * sizeof(void*))) return false;

        int executable = 0;
        for (int i = 0; i < count; ++i) {
            if (IsExecutable(vmt[i])) ++executable;
        }
        return executable >= count - 3;
    }

    HMODULE ModuleFromAddress(const void* address) {
        if (!address) return nullptr;
        HMODULE mod = nullptr;
        if (!GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS |
            GET_MODULE_HANDLE_EX_FLAG_UNCHANGED_REFCOUNT,
            reinterpret_cast<LPCSTR>(address), &mod))
            return nullptr;
        return mod;
    }

    bool InModule(HMODULE module, const void* ptr) {
        if (!module || !ptr) return false;
        MODULEINFO info{};
        if (!GetModuleInformation(GetCurrentProcess(), module, &info, sizeof(info)))
            return false;
        uintptr_t base = reinterpret_cast<uintptr_t>(info.lpBaseOfDll);
        uintptr_t end = base + info.SizeOfImage;
        uintptr_t p = reinterpret_cast<uintptr_t>(ptr);
        return p >= base && p < end;
    }

    bool LooksLikeCInput(void* object) {
        if (!object || !IsReadable(object, sizeof(void*))) return false;

        void** vmt = nullptr;
        std::memcpy(&vmt, object, sizeof(vmt));
        if (!LooksLikeVmt(vmt, 15)) return false;

        if (!IsExecutable(vmt[8]) || !IsExecutable(vmt[9])) return false;

        HMODULE vmtMod = ModuleFromAddress(vmt);
        HMODULE clientMod = GetModuleHandleA("client.dll");
        if (!vmtMod || !clientMod) return false;
        return vmtMod == clientMod;
    }

    void* FindInputInFunction(void* function, const char* tag) {
        if (!function || !IsExecutable(function)) {
            LogWarn("[CINPUT] %s is not executable (%p)", tag, function);
            return nullptr;
        }

        auto* code = static_cast<uint8_t*>(function);
        int reported = 0;

        for (size_t offset = 0; offset < 0x200; ++offset) {
            if (!IsReadable(code + offset, 7)) break;

            if (!(code[offset] == 0x48 && code[offset + 1] == 0x8B && code[offset + 2] == 0x0D))
                continue;

            int32_t disp = 0;
            std::memcpy(&disp, code + offset + 3, sizeof(disp));

            uint8_t* slotAddress = code + offset + 7 + disp;
            if (!IsReadable(slotAddress, sizeof(void*))) {
                if (reported < 8)
                    LogWarn("[CINPUT] %s+0x%X: slot %p not readable", tag, (unsigned)offset, slotAddress);
                ++reported;
                continue;
            }

            void* candidate = nullptr;
            std::memcpy(&candidate, slotAddress, sizeof(candidate));

            bool valid = LooksLikeCInput(candidate);
            if (reported < 8) {
                Log("[CINPUT] %s+0x%X: mov rcx,[%p] -> %p %s",
                    tag, (unsigned)offset, slotAddress, candidate, valid ? "ACCEPT" : "reject");
                ++reported;
            }

            if (valid) return candidate;
        }

        return nullptr;
    }

} // namespace

bool Base::ResolveInterfaces() {
    EnsureModule("client.dll");
    EnsureModule("engine.dll");
    EnsureModule("vstdlib.dll");
    EnsureModule("inputsystem.dll");
    EnsureModule("vgui2.dll");
    EnsureModule("vguimatsurface.dll");
    EnsureModule("materialsystem.dll");

    SetOnce(g_pClient,
        SDK::InterfaceManager::get<void*>("client.dll", SDK::Interfaces::client::VClient017),
        "client.dll!VClient017");

    SetOnce(g_pEngine,
        SDK::InterfaceManager::get<void*>("engine.dll", SDK::Interfaces::engine::VEngineClient015),
        "engine.dll!VEngineClient015");

    SetOnce(g_pEntityList,
        SDK::InterfaceManager::get<void*>("client.dll", SDK::Interfaces::client::VClientEntityList003),
        "client.dll!VClientEntityList003");

    if (!g_pCvar) {
        void* cvar = SDK::InterfaceManager::get<void*>("vstdlib.dll", SDK::Interfaces::vstdlib::VEngineCvar007);
        if (cvar) {
            g_pCvar = cvar;
            Log("[IFACE] %-46s = %p", "vstdlib.dll!VEngineCvar007", cvar);
        }
        else {
            cvar = SDK::InterfaceManager::get<void*>("materialsystem.dll", SDK::Interfaces::materialsystem::VEngineCvar007);
            if (cvar) {
                g_pCvar = cvar;
                LogWarn("[IFACE] VEngineCvar007 taken from materialsystem.dll = %p", cvar);
            }
            else {
                LogErr("[IFACE] %-46s = nullptr", "VEngineCvar007");
            }
        }
    }

    SetOnce(g_pInputSystem,
        SDK::InterfaceManager::get<void*>("inputsystem.dll", SDK::Interfaces::inputsystem::InputSystemVersion001),
        "inputsystem.dll!InputSystemVersion001");

    SetOnce(g_pVGuiPanel,
        SDK::InterfaceManager::get<void*>("vgui2.dll", SDK::Interfaces::vgui2::VGUI_Panel009),
        "vgui2.dll!VGUI_Panel009");

    SetOnce(g_pEngineVGui,
        SDK::InterfaceManager::get<void*>("engine.dll", SDK::Interfaces::engine::VEngineVGui001),
        "engine.dll!VEngineVGui001");

    SetOnce(g_pMaterialSystem,
        SDK::InterfaceManager::get<void*>("materialsystem.dll", SDK::Interfaces::materialsystem::VMaterialSystem080),
        "materialsystem.dll!VMaterialSystem080");

    if (!g_pVGuiSurface) {
        void* surface = SDK::InterfaceManager::get<void*>("vguimatsurface.dll", SDK::Interfaces::vguimatsurface::VGUI_Surface030);
        if (!surface)
            surface = SDK::InterfaceManager::get<void*>("vgui2.dll", SDK::Interfaces::vgui2::VGUI_Surface030);

        SetOnce(g_pVGuiSurface, surface, "VGUI_Surface030");
    }

    SetOnce(g_pEngineTrace,
        SDK::InterfaceManager::get<void*>("engine.dll", SDK::Interfaces::engine::EngineTraceClient003),
        "engine.dll!EngineTraceClient003");

    SetOnce(g_pEngineModel,
        SDK::InterfaceManager::get<void*>("engine.dll", SDK::Interfaces::engine::VEngineModel016),
        "engine.dll!VEngineModel016");

    SetOnce(g_pModelInfo,
        SDK::InterfaceManager::get<void*>("engine.dll", SDK::Interfaces::engine::VModelInfoClient006),
        "engine.dll!VModelInfoClient006");

    SetOnce(g_pGameMovement,
        SDK::InterfaceManager::get<void*>("client.dll", SDK::Interfaces::client::GameMovement001),
        "client.dll!GameMovement001");

    return g_pClient && g_pEngine && g_pEntityList;
}

bool Base::ResolveClientMode() {
    if (g_pClientMode) return true;
    if (!g_pClient) return false;

    void** clientVmt = GetVmt(g_pClient);
    if (!LooksLikeVmt(clientVmt, 30)) {
        LogErr("[CLIENTMODE] VClient017 vtable is not valid (%p)", clientVmt);
        return false;
    }

    using GetClientModeFn = void* (__fastcall*)(void*);
    auto getClientMode = reinterpret_cast<GetClientModeFn>(clientVmt[10]);
    Log("[CLIENTMODE] VClient017 VMT[10] GetClientMode = %p", reinterpret_cast<void*>(getClientMode));

    if (!IsExecutable(reinterpret_cast<void*>(getClientMode))) {
        LogErr("[CLIENTMODE] GetClientMode is not executable");
        return false;
    }

    void* returned = getClientMode(g_pClient);
    Log("[CLIENTMODE] GetClientMode returned %p", returned);
    if (!returned) return false;

    void** direct = static_cast<void**>(returned);
    if (LooksLikeVmt(direct, 25)) {
        g_pClientMode = direct;
        Log("[CLIENTMODE] using returned value as vtable (confirmed)");
    }
    else {
        void** indirect = *reinterpret_cast<void***>(returned);
        if (LooksLikeVmt(indirect, 25)) {
            g_pClientMode = indirect;
            LogWarn("[CLIENTMODE] returned value is an object, using its vtable %p", indirect);
        }
        else {
            LogErr("[CLIENTMODE] returned %p is neither vtable nor object", returned);
            return false;
        }
    }

    uint8_t* createMove = reinterpret_cast<uint8_t*>(g_pClientMode[21]);
    if (IsReadable(createMove, 12)) {
        Log("[CLIENTMODE] VMT[21] = %p bytes: %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X",
            createMove,
            createMove[0], createMove[1], createMove[2], createMove[3],
            createMove[4], createMove[5], createMove[6], createMove[7],
            createMove[8], createMove[9], createMove[10], createMove[11]);
    }

    return true;
}

bool Base::ResolveInput() {
    if (g_pInput) return true;

    void* fromClientMode = nullptr;
    void* fromClient = nullptr;

    if (g_pClientMode && IsReadable(g_pClientMode, 22 * sizeof(void*))) {
        fromClientMode = FindInputInFunction(g_pClientMode[21], "ClientMode::CreateMove");
    }

    if (g_pClient && IsReadable(g_pClient, sizeof(void*))) {
        void** clientVmt = GetVmt(g_pClient);
        if (LooksLikeVmt(clientVmt, 21)) {
            fromClient = FindInputInFunction(clientVmt[20], "CHLClient::CreateMove");
        }
    }

    void* input = fromClient ? fromClient : fromClientMode;
    const char* source = fromClient ? "CHLClient::CreateMove" : "ClientMode::CreateMove";

    if (!input) {
        LogErr("[CINPUT] not found: pattern 48 8B 0D in first 0x200 bytes");
        return false;
    }

    g_pInput = input;
    g_inputSource = source;

    HMODULE clientModule = GetModuleHandleA("client.dll");
    HMODULE engineModule = GetModuleHandleA("engine.dll");

    if (fromClient && fromClientMode && fromClientMode != fromClient) {
        bool altValid = InModule(clientModule, fromClientMode) ||
            InModule(engineModule, fromClientMode);

        if (altValid) {
            g_pInputAlt = fromClientMode;
            g_inputAltSource = "ClientMode::CreateMove";
            LogWarn("[CINPUT] candidates differ: CHLClient=%p ClientMode=%p (using CHLClient::CreateMove, probing both)",
                fromClient, fromClientMode);
        }
        else {
            g_pInputAlt = nullptr;
            g_inputAltSource = "unknown";
            Log("[CINPUT] ALT candidate %p rejected: outside client.dll/engine.dll", fromClientMode);
        }
    }
    else {
        g_pInputAlt = nullptr;
        g_inputAltSource = "unknown";
    }

    Log("[CINPUT] g_pInput = %p (source=%s)", input, source);
    if (g_pInputAlt)
        Log("[CINPUT] g_pInputAlt = %p (source=%s)", g_pInputAlt, g_inputAltSource);
    return true;
}

void Base::DumpInputVmt() {
    auto dump = [](void* object, const char* tag, const char* source) {
        if (!object) {
            LogErr("[CINPUT%s] DumpInputVmt: object is null", tag);
            return;
        }

        void** vmt = nullptr;
        std::memcpy(&vmt, object, sizeof(vmt));
        if (!IsReadable(vmt, 15 * sizeof(void*))) {
            LogErr("[CINPUT%s] vtable %p not readable", tag, vmt);
            return;
        }

        Log("[CINPUT%s] object = %p vtable = %p source=%s", tag, object, vmt, source);
        for (int i = 0; i < 15; ++i) {
            const char* note = "";
            if (i == 8) note = "  <- GetUserCmd (CInput.h)";
            if (i == 9) note = "  <- MakeWeaponSelection (probe)";
            Log("[CINPUT%s] vmt[%02d] = %p%s", tag, i, vmt[i], note);
        }
        };

    dump(g_pInput, "", g_inputSource);
    if (g_pInputAlt)
        dump(g_pInputAlt, ":ALT", g_inputAltSource);
}

bool Base::InstallHooks() {
    bool ok = true;

    auto hookInput = [&ok](void* object, const char* source,
        UserCmdSlotFn& original8, UserCmdSlotFn& original9,
        void* hook8, void* hook9) {
            if (!object) {
                ok = false;
                LogErr("[HOOK] %s CInput skipped: object is null", source);
                return;
            }

            void** vmt = nullptr;
            std::memcpy(&vmt, object, sizeof(vmt));

            if (vmt && IsExecutable(vmt[8])) {
                if (vmt[8] == hook8) {
                    LogWarn("[HOOK] %s CInput VMT[8] already hooked", source);
                }
                else {
                    original8 = VMT_HookRaw<UserCmdSlotFn>(vmt, hook8, 8);
                    Log("[HOOK] %s CInput VMT[8] original=%p hook=%p",
                        source, reinterpret_cast<void*>(original8), hook8);
                }
            }
            else {
                ok = false;
                LogErr("[HOOK] %s CInput VMT[8] is not executable", source);
            }

            if (vmt && IsExecutable(vmt[9])) {
                if (vmt[9] == hook9) {
                    LogWarn("[HOOK] %s CInput VMT[9] already hooked", source);
                }
                else {
                    original9 = VMT_HookRaw<UserCmdSlotFn>(vmt, hook9, 9);
                    Log("[HOOK] %s CInput VMT[9] original=%p hook=%p",
                        source, reinterpret_cast<void*>(original9), hook9);
                }
            }
            else {
                ok = false;
                LogErr("[HOOK] %s CInput VMT[9] is not executable", source);
            }
        };

    hookInput(g_pInput, g_inputSource, oGetUserCmd8, oGetUserCmd9,
        reinterpret_cast<void*>(hkGetUserCmd8),
        reinterpret_cast<void*>(hkGetUserCmd9));

    if (g_pInputAlt) {
        void** primaryVmt = nullptr;
        void** altVmt = nullptr;
        if (g_pInput)
            std::memcpy(&primaryVmt, g_pInput, sizeof(primaryVmt));
        std::memcpy(&altVmt, g_pInputAlt, sizeof(altVmt));

        if (primaryVmt && primaryVmt == altVmt) {
            LogWarn("[HOOK] %s shares vtable with %s, skipping duplicate hook",
                g_inputAltSource, g_inputSource);
        }
        else {
            hookInput(g_pInputAlt, g_inputAltSource, oAltGetUserCmd8, oAltGetUserCmd9,
                reinterpret_cast<void*>(hkAltGetUserCmd8),
                reinterpret_cast<void*>(hkAltGetUserCmd9));
        }
    }

    if (g_pClientMode && IsExecutable(g_pClientMode[21])) {
        if (g_pClientMode[21] == reinterpret_cast<void*>(hkCreateMove)) {
            LogWarn("[HOOK] ClientMode::CreateMove already hooked");
        }
        else {
            oCreateMove = VMT_HookRaw<CreateMoveFn>(
                g_pClientMode, reinterpret_cast<void*>(hkCreateMove), 21);
            Log("[HOOK] ClientMode::CreateMove VMT[21] original=%p hook=%p",
                reinterpret_cast<void*>(oCreateMove),
                reinterpret_cast<void*>(hkCreateMove));
        }
    }
    else {
        ok = false;
        LogErr("[HOOK] ClientMode::CreateMove skipped (client mode null or VMT[21] invalid)");
    }

    if (g_pClient) {
        void** clientVmt = GetVmt(g_pClient);
        if (LooksLikeVmt(clientVmt, 38)) {
            int index = kFrameStageNotifyIndex;
            if (clientVmt[index] == reinterpret_cast<void*>(hkFrameStageNotify)) {
                LogWarn("[HOOK] FrameStageNotify already hooked");
            }
            else {
                oFrameStageNotify = VMT_HookRaw<FrameStageNotifyFn>(
                    clientVmt, reinterpret_cast<void*>(hkFrameStageNotify), index);
                Log("[HOOK] FrameStageNotify VMT[%d] original=%p hook=%p",
                    index,
                    reinterpret_cast<void*>(oFrameStageNotify),
                    reinterpret_cast<void*>(hkFrameStageNotify));
            }
        }
        else {
            ok = false;
            LogErr("[HOOK] FrameStageNotify skipped: VClient017 vtable invalid");
        }
    }
    else {
        ok = false;
        LogErr("[HOOK] FrameStageNotify skipped: g_pClient null");
    }

    return ok;
}

void Base::Diagnostics() {
    for (int attempt = 0; attempt < 8; ++attempt) {
        int index = GetLocalPlayerIndex();
        void* local = GetClientEntity(index);
        int flags = GetFlags(local);

        Log("[DIAG] attempt=%d localIdx=%d local=%p flags=0x%X onGround=%d",
            attempt, index, local, flags, (flags & 1) != 0);

        if (attempt < 4) Sleep(1000);
        else if (attempt < 7) Sleep(10000);
    }
}