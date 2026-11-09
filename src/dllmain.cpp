#include <windows.h>

#include "logger.hpp"
#include "globals.hpp"
#include "util.hpp"
#include "config.hpp"
#include "sdk.hpp"
#include "hooks/install.hpp"
#include "overlay.hpp"
#include "lua_bridge.hpp"
#include "lua_scripts.hpp"

static bool WaitForModules(DWORD timeoutMs) {
    const DWORD start = GetTickCount();
    while (GetTickCount() - start < timeoutMs) {
        if (GetModuleHandleA("client.dll") && GetModuleHandleA("engine.dll"))
            return true;
        Sleep(100);
    }
    return false;
}

static DWORD WINAPI MainThread(LPVOID) {
    LogInit();
    Log("=== Zalupaware base ===");
    Log("[MAIN] log path = %s", LogPath());

    if (!WaitForModules(5000)) {
        LogErr("[MAIN] timeout waiting for client.dll/engine.dll");
        return 0;
    }

    Log("[MAIN] client.dll=%p engine.dll=%p",
        GetModuleHandleA("client.dll"), GetModuleHandleA("engine.dll"));

    for (int i = 0; i < 5; ++i) {
        void* client = SDK::InterfaceManager::get<void*>("client.dll", SDK::Interfaces::client::VClient017);
        void* engine = SDK::InterfaceManager::get<void*>("engine.dll", SDK::Interfaces::engine::VEngineClient015);
        if (client && engine) {
            Log("[MAIN] core interfaces ready after %d ms", i * 50);
            break;
        }
        Sleep(50);
    }

    if (!Base::ResolveInterfaces())
        LogErr("[MAIN] core interfaces not fully resolved");

    if (LuaBridge::Init()) {
        LoadAllLuaScripts();
        Log("[LUA] initialized successfully on inject");
    }
    else {
        LogWarn("[LUA] lua_shared.dll not ready, will retry on map load");
    }

    g_OnFrameStageNotify = [](int stage) {
        if (stage != 4) return;

        if (!LuaBridge::g_L || !LuaBridge::IsStateAlive()) {
            LuaBridge::ResetState();
            if (LuaBridge::Init()) {
                LoadAllLuaScripts();
                Log("[LUA] (re)initialized on FRAME_NET_UPDATE_END");
            }
        }
        };

    bool clientMode = false;
    for (int i = 0; i < 40 && !(clientMode = Base::ResolveClientMode()); ++i)
        Sleep(250);

    if (!clientMode)
        LogErr("[MAIN] ClientModeShared not resolved");

    bool input = false;
    for (int i = 0; i < 40 && !(input = Base::ResolveInput()); ++i)
        Sleep(250);

    if (!input)
        LogErr("[MAIN] CInput not resolved");

    Base::DumpInputVmt();

    g_Config.Load();
    g_Config.Dump();

    if (!Base::InstallHooks())
        LogErr("[MAIN] some hooks were not installed");

    g_OnGetUserCmd = nullptr;
    Log("[BHOP] %s (config.bhop=%d, applied in CreateMove after oCreateMove)",
        g_Config.bhop ? "enabled" : "disabled", g_Config.bhop);

    if (!Overlay::Install())
        LogErr("[OVERLAY] installation failed; ESP will not render");
    Log("[ESP] %s (config.esp=%d)", g_Config.esp ? "enabled" : "disabled", g_Config.esp);

    Base::Diagnostics();

    Log("[MAIN] base initialized, hooks stay active");
    return 0;
}

BOOL APIENTRY DllMain(HMODULE module, DWORD reason, LPVOID) {
    if (reason == DLL_PROCESS_ATTACH) {
        DisableThreadLibraryCalls(module);
        CreateThread(nullptr, 0, MainThread, nullptr, 0, nullptr);
    }
    return TRUE;
}