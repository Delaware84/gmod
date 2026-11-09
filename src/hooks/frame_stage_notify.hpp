#pragma once
#include <windows.h>
#include <atomic>
#include "../logger.hpp"
#include "../globals.hpp"
#include "../sdk.hpp"
#include "../esp.hpp"

// GMod-SDK-main/GMod-SDK/client/CHLClient.h: FrameStageNotify is /*35*/.
inline constexpr int kFrameStageNotifyIndex = SDK::VMT::CHLClient_FrameStageNotify;

using FrameStageNotifyFn = void(__fastcall*)(void* self, int stage);
inline FrameStageNotifyFn oFrameStageNotify = nullptr;

inline const char* FrameStageName(int stage) {
    switch (stage) {
    case 0: return "FRAME_START";
    case 1: return "FRAME_NET_UPDATE_START";
    case 2: return "FRAME_NET_UPDATE_POSTDATAUPDATE_START";
    case 3: return "FRAME_NET_UPDATE_POSTDATAUPDATE_END";
    case 4: return "FRAME_NET_UPDATE_END";
    case 5: return "FRAME_RENDER_START";
    case 6: return "FRAME_RENDER_END";
    default: return "UNKNOWN";
    }
}

inline void __fastcall hkFrameStageNotify(void* self, int stage) {
    if (g_OnFrameStageNotify) g_OnFrameStageNotify(stage); // <--- ВАЖНО

    if (oFrameStageNotify) oFrameStageNotify(self, stage);

    if (stage == 4) {
        Esp::RefreshLocalCache();
        Esp::CollectPlayers();
    }

    static std::atomic<int> calls{ 0 };
    static std::atomic<int> lastLoggedStage{ -999 };

    int callCount = ++calls;
    if (callCount == 1 ||
        (callCount % 200 == 0 &&
            lastLoggedStage.load(std::memory_order_relaxed) != stage)) {
        lastLoggedStage.store(stage, std::memory_order_relaxed);
        Log("[FSN] stage=%d (%s) calls=%d", stage, FrameStageName(stage), callCount);
    }
}