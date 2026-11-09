#pragma once
#include <windows.h>
#include <atomic>
#include "../logger.hpp"
#include "../globals.hpp"
#include "../util.hpp"
#include "../config.hpp"
#include "../Memory.h"
#include "../sdk.hpp"
#include "bhop.hpp"
#include "../aimbot.hpp"

using CreateMoveFn = bool(__fastcall*)(void* self, float sampleTime, SDK::CUserCmd* cmd);
inline CreateMoveFn oCreateMove = nullptr;

constexpr size_t kCmdHeadSize = 0x40;

inline int GetCachedLocalFlags() {
    return g_localFlags.load(std::memory_order_relaxed);
}

inline void* GetCachedLocalEntity() {
    return g_localEntity.load(std::memory_order_relaxed);
}

inline void LogCreateMove(SDK::CUserCmd* cmd, int calls) {
    if (calls % 500 != 0) return;
    int commandNumber = cmd->command_number;
    if (commandNumber == 0) {
        Log("[CM] #%d cmd=%p command_number=0 (garbage cmd, skipped)", calls, cmd);
        return;
    }
    int flags = GetCachedLocalFlags();
    Log("[CM] #%d cmd=%p num=%d tick=%d buttons=0x%X flags=0x%X onGround=%d",
        calls, cmd, commandNumber, cmd->tick_count, cmd->buttons,
        flags, (flags & kBhopOnGroundFlag) != 0);
}

inline void ApplyBhop(SDK::CUserCmd* cmd) {
    if (!cmd) return;
    bool wantsJump = (cmd->buttons & kBhopJumpButton) != 0;
    if (!wantsJump) return;

    int flags = GetCachedLocalFlags();
    bool onGround = (flags & kBhopOnGroundFlag) != 0;

    static bool wasOnGround = false;
    if (onGround) {
        cmd->buttons |= kBhopJumpButton;
        if (!wasOnGround)
            g_bhopCounter.fetch_add(1, std::memory_order_relaxed);
    }
    else {
        cmd->buttons &= ~kBhopJumpButton;
    }
    wasOnGround = onGround;
}

inline bool __fastcall hkCreateMove(void* self, float sampleTime, SDK::CUserCmd* cmd) {
    bool cmdValid = cmd && IsReadable(cmd, kCmdHeadSize) && cmd->command_number != 0;

    if (cmdValid) {
        if (g_OnCreateMove) g_OnCreateMove(sampleTime, cmd);
    }

    bool result = oCreateMove ? oCreateMove(self, sampleTime, cmd) : false;

    if (cmdValid) {
        Aimbot::Run(cmd, sampleTime);
    }

    if (g_Config.bhop && cmdValid) {
        ApplyBhop(cmd);
    }

    static std::atomic<int> calls{ 0 };
    if (cmdValid) {
        int n = ++calls;
        LogCreateMove(cmd, n);
    }

    return result;
}