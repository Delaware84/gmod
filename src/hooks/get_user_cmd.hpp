#pragma once
#include <windows.h>
#include <atomic>
#include <cstring>
#include "../logger.hpp"
#include "../globals.hpp"
#include "../util.hpp"
#include "../config.hpp"
#include "../Memory.h"
#include "../sdk.hpp"
#include "bhop.hpp"

using UserCmdSlotFn = void* (__fastcall*)(void* self, uintptr_t arg);

inline UserCmdSlotFn oGetUserCmd8 = nullptr;
inline UserCmdSlotFn oGetUserCmd9 = nullptr;

inline UserCmdSlotFn oAltGetUserCmd8 = nullptr;
inline UserCmdSlotFn oAltGetUserCmd9 = nullptr;

inline std::atomic<int> g_getUserCmdIndex{-1};

constexpr size_t kCmdReadSize = 0x40;

inline int ReadCmdInt(const SDK::CUserCmd* raw, int offset) {
    int value = 0;
    if (!raw) return 0;
    std::memcpy(&value, reinterpret_cast<const uint8_t*>(raw) + offset, sizeof(value));
    return value;
}

inline void DetectUserCmdLayout(SDK::CUserCmd* raw, int sequenceNumber, int index, const char* source) {
    int number0 = ReadCmdInt(raw, 0x00);
    int number8 = ReadCmdInt(raw, 0x08);

    int shift = -1;
    if (number0 == sequenceNumber && number0 != 0) shift = 0;
    else if (number8 == sequenceNumber && number8 != 0) shift = 8;

    if (shift < 0) return;

    if (!SDK::g_userCmdShiftDetected.exchange(true)) {
        SDK::g_userCmdShift.store(shift, std::memory_order_relaxed);
    } else if (g_Config.verboseLog &&
               SDK::g_userCmdShift.load(std::memory_order_relaxed) != shift) {
        LogWarn("[CUserCmd] layout mismatch (%s): detected +0x%02X, earlier +0x%02X",
                source, shift, SDK::g_userCmdShift.load(std::memory_order_relaxed));
    }
}

// Prints vtable[0..limit) of the given object. Uses IsExecutable as a sanity
// check on each slot, so garbage slots are marked, not read.
inline void DumpInputVmtEx(const char* tag, void* object, const char* source, int limit) {
    if (!object) {
        LogErr("[CINPUT%s] object is null", tag);
        return;
    }

    void** vmt = nullptr;
    std::memcpy(&vmt, object, sizeof(vmt));
    if (!IsReadable(vmt, limit * sizeof(void*))) {
        LogErr("[CINPUT%s] vtable %p not readable for %d slots", tag, vmt, limit);
        return;
    }

    Log("[CINPUT%s] object = %p vtable = %p source=%s", tag, object, vmt, source);
    for (int i = 0; i < limit; ++i) {
        const char* note = "";
        if (i == 8)  note = "  <- GetUserCmd (old CInput.h)";
        if (i == 9)  note = "  <- MakeWeaponSelection (old CInput.h)";
        if (i == 14) note = "  <- AccumulateMouse (old CInput.h)";
        if (i == 15) note = "  <- ActivateMouse (old CInput.h)";
        if (i == 16) note = "  <- DeactivateMouse (old CInput.h)";
        if (i == 17) note = "  <- ClearStates (old CInput.h)";
        if (i == 18) note = "  <- GetLookSpring (old CInput.h)";
        if (i == 21) note = "  <- ResetMouse (old CInput.h)";

        const char* exec = IsExecutable(vmt[i]) ? "" : " [NOT EXECUTABLE]";
        Log("[CINPUT%s] vmt[%02d] = %p%s%s", tag, i, vmt[i], note, exec);
    }
}

inline void ProcessGetUserCmd(void* self, SDK::CUserCmd* raw, int sequenceNumber,
                              int index, const char* source) {
    if (!raw) return;
    if (!IsReadable(raw, kCmdReadSize)) return;

    int number0 = ReadCmdInt(raw, 0x00);
    int number8 = ReadCmdInt(raw, 0x08);

    bool match0 = (number0 == sequenceNumber && number0 != 0);
    bool match8 = (number8 == sequenceNumber && number8 != 0);
    if (!match0 && !match8) return;

    DetectUserCmdLayout(raw, sequenceNumber, index, source);

    if (!g_pActiveInput) {
        g_pActiveInput = self;
        Log("[CInput] active input = %p (source=%s, VMT[%d])", self, source, index);
    }

    int previous = g_getUserCmdIndex.exchange(index);
    if (previous != index) {
        Log("[CInput] GetUserCmd confirmed at VMT[%d] (previous=%d, seq=%d) source=%s",
            index, previous, sequenceNumber, source);
    }

    SDK::CUserCmd* cmd = SDK::CmdAt(raw);
    if (!cmd) return;

    static std::atomic<int> calls{0};
    int callCount = ++calls;

    if (g_Config.verboseLog && callCount <= 2)
        LogHexDump("[UC] raw", raw, kCmdReadSize);

    if (g_OnGetUserCmd)
        g_OnGetUserCmd(cmd);

    if (callCount % 500 != 0) return;

    if (g_Config.logUserCmd) {
        int flags = g_localFlags.load(std::memory_order_relaxed);
        Log("[UC] #%d seq=%d num=%d tick=%d buttons=0x%X flags=0x%X onGround=%d",
            callCount, sequenceNumber, cmd->command_number, cmd->tick_count,
            cmd->buttons, flags, (flags & kBhopOnGroundFlag) != 0);
    }

    if (g_Config.bhop) {
        Log("[BHOP] calls=%d triggered=%llu", callCount,
            static_cast<unsigned long long>(
                g_bhopCounter.load(std::memory_order_relaxed)));
    }
}

inline void* RunUserCmdSlot(void* self, uintptr_t arg, int index, const char* source,
                            UserCmdSlotFn original, std::atomic<int>& counter) {
    int callCount = ++counter;
    if (g_Config.verboseLog && (callCount <= 5 || callCount % 5000 == 0)) {
        Log("[CInput] %s VMT[%d] call #%d self=%p arg=%d",
            source, index, callCount, self, static_cast<int>(arg));
    }

    void* result = original ? original(self, arg) : nullptr;
    ProcessGetUserCmd(self, static_cast<SDK::CUserCmd*>(result),
                      static_cast<int>(arg), index, source);
    return result;
}

inline void* __fastcall hkGetUserCmd8(void* self, uintptr_t arg) {
    static std::atomic<int> calls{0};
    return RunUserCmdSlot(self, arg, 8, g_inputSource, oGetUserCmd8, calls);
}

inline void* __fastcall hkGetUserCmd9(void* self, uintptr_t arg) {
    static std::atomic<int> calls{0};
    return RunUserCmdSlot(self, arg, 9, g_inputSource, oGetUserCmd9, calls);
}

inline void* __fastcall hkAltGetUserCmd8(void* self, uintptr_t arg) {
    static std::atomic<int> calls{0};
    return RunUserCmdSlot(self, arg, 8, g_inputAltSource, oAltGetUserCmd8, calls);
}

inline void* __fastcall hkAltGetUserCmd9(void* self, uintptr_t arg) {
    static std::atomic<int> calls{0};
    return RunUserCmdSlot(self, arg, 9, g_inputAltSource, oAltGetUserCmd9, calls);
}