#pragma once
#include <atomic>
#include "sdk/usercmd.hpp"

// Interface pointers. Resolved once in Base::ResolveInterfaces().
inline void* g_pClient = nullptr;
inline void* g_pEngine = nullptr;
inline void* g_pEntityList = nullptr;
inline void* g_pCvar = nullptr;
// Primary CInput candidate (CHLClient::CreateMove has priority).
inline void* g_pInput = nullptr;
// Secondary CInput candidate, probed in parallel when it differs (ClientMode).
inline void* g_pInputAlt = nullptr;
inline const char* g_inputSource = "unknown";
inline const char* g_inputAltSource = "unknown";
// Set on the first real GetUserCmd hit (the candidate the game actually uses).
inline void* g_pActiveInput = nullptr;
inline void* g_pInputSystem = nullptr;
inline void* g_pVGuiPanel = nullptr;
inline void* g_pVGuiSurface = nullptr;
inline void* g_pEngineVGui = nullptr;
inline void* g_pMaterialSystem = nullptr;
inline void* g_pEngineTrace = nullptr;
inline void* g_pModelInfo = nullptr;
inline void* g_pEngineModel = nullptr;
inline void* g_pGameMovement = nullptr;

// GetClientMode (VClient017 VMT[10]) returns the vtable pointer itself in
// GMod x64, not the object. Hooks therefore operate on this array directly.
inline void** g_pClientMode = nullptr;

// ---------------------------------------------------------------------------
// Per-frame cache. Refreshed once per FRAME_NET_UPDATE_END, read from
// CreateMove/GetUserCmd without touching VirtualQuery.
// ---------------------------------------------------------------------------
inline std::atomic<bool>  g_localCacheValid{false};
inline std::atomic<void*> g_localEntity{nullptr};
inline std::atomic<int>   g_localFlags{0};
inline std::atomic<int>   g_localIndex{-1};
inline SDK::Vector3D      g_localOriginCache{};
inline std::atomic<bool>  g_localOriginValid{false};

// Extension points. Hooks contain no feature logic.
inline void (*g_OnCreateMove)(float sampleTime, SDK::CUserCmd* cmd) = nullptr;
inline void (*g_OnGetUserCmd)(SDK::CUserCmd* cmd) = nullptr;
inline void (*g_OnFrameStageNotify)(int stage) = nullptr;