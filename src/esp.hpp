#pragma once
#include <windows.h>
#include <atomic>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <mutex>
#include "config.hpp"
#include "globals.hpp"
#include "logger.hpp"
#include "util.hpp"
#include "sdk.hpp"
#include "lua_bridge.hpp"
#include "third_party/imgui/imgui.h"

namespace Esp {

    constexpr int   kMaxPlayers = 64;
    constexpr int   kMaxClients = 64;
    constexpr int   kHealthOffset = 0xD8;
    constexpr int   kHealthOffsetAlt = 0x100;
    constexpr int   kMaxHealthOffset = 0xDC;
    constexpr int   kLifeStateOffset = 0xD7;
    constexpr int   kTeamOffset = 0xE4;
    constexpr int   kOriginOffset = 0x438;
    constexpr int   kViewOffsetOffset = 0x144;
    constexpr int   kDuckedOffset = 0x29D0;
    constexpr int   kFlagsOffset = 0x450;
    constexpr float kStandEyeHeight = 64.0f;
    constexpr float kDuckEyeHeight = 28.0f;
    constexpr size_t kEntityReadSize = 0x460;
    constexpr int   kInfoRefreshPasses = 60;

    struct BonePair { int a; int b; };
    static const BonePair kBonePairs[] = {
        {6, 5}, {5, 3}, {3, 2}, {2, 1}, {1, 0},
        {0, 15}, {15, 16}, {16, 17},
        {0, 19}, {19, 20}, {20, 21},
        {3, 7}, {7, 8}, {8, 9},
        {3, 11}, {11, 12}, {12, 13},
    };
    static const int kBonePairCount = sizeof(kBonePairs) / sizeof(kBonePairs[0]);

    struct PlayerInfo {
        char name[128];
        int userID;
        char guid[33];
        unsigned int friendsid;
        char friendsname[128];
        bool fakeplayer;
        bool ishltv;
        unsigned int customfiles[4];
        unsigned char filesdownloaded;
    };

    struct Player {
        int index = 0;
        void* entity = nullptr;
        SDK::Vector3D origin{};
        SDK::Vector3D viewOffset{};
        int health = 0;
        int team = 0;
        int ducked = 0;
        char name[128] = {};

        bool traitor = false;
        bool itemTraitor = false;
        bool traitorAlly = false;
        bool visible = true;
        bool roleKnown = false;

        bool inRagdoll = false;
        bool bonesValid = false;
        LuaBridge::PlayerBoneData bones{};
    };

    inline std::mutex g_mutex;
    inline Player g_players[kMaxPlayers] = {};
    inline std::atomic<int> g_playerCount{ 0 };
    inline SDK::Vector3D g_localOrigin{};
    inline int g_localTeam = 0;
    inline std::atomic<int> g_collectCalls{ 0 };
    inline std::atomic<int> g_localRefreshCalls{ 0 };

    inline PlayerInfo g_cachedInfo[kMaxClients + 1] = {};
    inline bool g_cachedInfoValid[kMaxClients + 1] = {};
    inline int g_infoRefreshCounter = 0;

    inline float g_cachedMatrix[16] = {};
    inline std::mutex g_matrixMutex;
    inline int g_cachedScreenW = 0;
    inline int g_cachedScreenH = 0;
    inline std::atomic<bool> g_renderStateValid{ false };

    inline std::atomic<int> g_screenWidth{ 0 };
    inline std::atomic<int> g_screenHeight{ 0 };

    inline bool IsInGame() {
        if (!g_pEngine) return false;
        void** vmt = GetVmt(g_pEngine);
        if (!vmt || !IsExecutable(vmt[26])) return false;
        using Fn = bool(__fastcall*)(void*);
        return reinterpret_cast<Fn>(vmt[26])(g_pEngine);
    }

    inline bool GetEngineScreenSize(int& width, int& height) {
        width = 0; height = 0;
        if (!g_pEngine) return false;
        void** vmt = GetVmt(g_pEngine);
        if (!vmt || !IsExecutable(vmt[5])) return false;
        using Fn = void(__fastcall*)(void*, int&, int&);
        reinterpret_cast<Fn>(vmt[5])(g_pEngine, width, height);
        return width > 0 && height > 0;
    }

    inline bool GetWorldToScreenMatrix(float out[16]) {
        if (!g_pEngine) return false;
        void** vmt = GetVmt(g_pEngine);
        if (!vmt || !IsExecutable(vmt[36])) return false;
        using Fn = const float* (__fastcall*)(void*);
        const float* matrix = reinterpret_cast<Fn>(vmt[36])(g_pEngine);
        if (!matrix || !IsReadable(matrix, sizeof(float) * 16)) return false;
        std::memcpy(out, matrix, sizeof(float) * 16);
        return true;
    }

    inline bool GetPlayerInfo(int index, PlayerInfo& info) {
        std::memset(&info, 0, sizeof(info));
        if (!g_pEngine) return false;
        void** vmt = GetVmt(g_pEngine);
        if (!vmt || !IsExecutable(vmt[8])) return false;
        using Fn = bool(__fastcall*)(void*, int, PlayerInfo*);
        return reinterpret_cast<Fn>(vmt[8])(g_pEngine, index, &info);
    }

    inline bool WorldToScreen(const SDK::Vector3D& world, SDK::Vector3D& screen,
        const float matrix[16], int screenW, int screenH) {
        float w = matrix[12] * world.x + matrix[13] * world.y + matrix[14] * world.z + matrix[15];
        if (w < 0.01f) return false;
        float x = matrix[0] * world.x + matrix[1] * world.y + matrix[2] * world.z + matrix[3];
        float y = matrix[4] * world.x + matrix[5] * world.y + matrix[6] * world.z + matrix[7];
        screen.x = (screenW / 2.0f) * (1.0f + x / w);
        screen.y = (screenH / 2.0f) * (1.0f - y / w);
        return std::isfinite(screen.x) && std::isfinite(screen.y);
    }

    inline bool IsFiniteVector(const SDK::Vector3D& v) {
        return std::isfinite(v.x) && std::isfinite(v.y) && std::isfinite(v.z) &&
            std::fabs(v.x) < 1.0e6f && std::fabs(v.y) < 1.0e6f && std::fabs(v.z) < 1.0e6f;
    }

    inline float Distance(const SDK::Vector3D& a, const SDK::Vector3D& b) {
        float dx = a.x - b.x;
        float dy = a.y - b.y;
        float dz = a.z - b.z;
        return std::sqrt(dx * dx + dy * dy + dz * dz);
    }

    inline int ReadEntityHealthFast(void* entity) {
        int health = ReadNetvarFast<int>(entity, kHealthOffset);
        int maxHealth = ReadNetvarFast<int>(entity, kMaxHealthOffset);
        bool plausible = health >= 1 && health <= 1000 &&
            (maxHealth <= 0 || maxHealth > 1000 || health <= maxHealth + 100);
        if (!plausible) {
            int alt = ReadNetvarFast<int>(entity, kHealthOffsetAlt);
            if (alt >= 1 && alt <= 1000) health = alt;
        }
        return health;
    }

    inline void RefreshLocalCache() {
        int localIndex = GetLocalPlayerIndex();
        void* localEntity = localIndex > 0 ? GetClientEntity(localIndex) : nullptr;

        SDK::Vector3D origin{};
        int flags = 0;
        int team = 0;

        if (localEntity && IsReadable(localEntity, kEntityReadSize)) {
            origin = ReadNetvarFast<SDK::Vector3D>(localEntity, kOriginOffset);
            flags = ReadNetvarFast<int>(localEntity, kFlagsOffset);
            team = ReadNetvarFast<int>(localEntity, kTeamOffset);
        }

        g_localEntity.store(localEntity, std::memory_order_relaxed);
        g_localIndex.store(localIndex, std::memory_order_relaxed);
        g_localFlags.store(flags, std::memory_order_relaxed);
        g_localOriginCache = origin;
        g_localOriginValid.store(true, std::memory_order_relaxed);
        g_localCacheValid.store(true, std::memory_order_relaxed);

        {
            std::lock_guard<std::mutex> lock(g_mutex);
            g_localOrigin = origin;
            g_localTeam = team;
        }

        int calls = ++g_localRefreshCalls;
        if (calls % 500 == 0)
            Log("[ESP] local refresh: idx=%d flags=0x%X", localIndex, flags);
    }

    inline void ResetSnapshotLocked() {
        g_playerCount.store(0, std::memory_order_relaxed);
        std::memset(g_cachedInfoValid, 0, sizeof(g_cachedInfoValid));
        g_infoRefreshCounter = 0;
    }

    inline void CollectPlayers() {
        if (!g_Config.esp) return;
        if (g_Config.espUseLua) return;

        int localIndex = g_localIndex.load(std::memory_order_relaxed);
        void* localEntity = g_localEntity.load(std::memory_order_relaxed);
        SDK::Vector3D localOrigin = g_localOriginCache;

        if (localIndex <= 0 || !localEntity) {
            std::lock_guard<std::mutex> lock(g_mutex);
            ResetSnapshotLocked();
            return;
        }

        if (g_screenWidth.load(std::memory_order_relaxed) <= 0 ||
            g_screenHeight.load(std::memory_order_relaxed) <= 0) {
            int w = 0, h = 0;
            if (GetEngineScreenSize(w, h)) {
                g_screenWidth.store(w, std::memory_order_relaxed);
                g_screenHeight.store(h, std::memory_order_relaxed);
            }
        }

        float matrix[16] = {};
        if (GetWorldToScreenMatrix(matrix)) {
            int w = g_screenWidth.load(std::memory_order_relaxed);
            int h = g_screenHeight.load(std::memory_order_relaxed);
            if (w > 0 && h > 0) {
                std::lock_guard<std::mutex> lock(g_matrixMutex);
                std::memcpy(g_cachedMatrix, matrix, sizeof(matrix));
                g_cachedScreenW = w;
                g_cachedScreenH = h;
                g_renderStateValid.store(true, std::memory_order_relaxed);
            }
        }

        bool refreshInfo = (g_infoRefreshCounter++ % kInfoRefreshPasses) == 0;

        Player snapshot[kMaxPlayers] = {};
        int count = 0;

        int localTeam = 0;
        {
            std::lock_guard<std::mutex> lock(g_mutex);
            localTeam = g_localTeam;
        }

        float distanceMax = g_Config.espDistanceMax;
        uint32_t now = GetTickCount();

        for (int i = 1; i <= kMaxClients; ++i) {
            if (i == localIndex) continue;

            void* entity = GetClientEntity(i);
            if (!entity || entity == localEntity) continue;
            if (!IsPlayerEntity(entity)) continue;

            if (refreshInfo || !g_cachedInfoValid[i]) {
                if (GetPlayerInfo(i, g_cachedInfo[i]))
                    g_cachedInfoValid[i] = g_cachedInfo[i].name[0] != '\0';
                else
                    g_cachedInfoValid[i] = false;
            }
            const PlayerInfo& info = g_cachedInfo[i];

            if (!IsReadable(entity, kEntityReadSize)) continue;

            int lifeState = ReadNetvarFast<uint8_t>(entity, kLifeStateOffset);
            if (lifeState == 1 || lifeState == 2) continue;

            int health = ReadEntityHealthFast(entity);
            if (health <= 0) continue;

            SDK::Vector3D origin = ReadNetvarFast<SDK::Vector3D>(entity, kOriginOffset);
            if (!IsFiniteVector(origin)) continue;

            SDK::Vector3D vOff = ReadNetvarFast<SDK::Vector3D>(entity, kViewOffsetOffset);
            if (!std::isfinite(vOff.z) || vOff.z < 20.0f || vOff.z > 90.0f)
                vOff.z = kStandEyeHeight;

            int team = ReadNetvarFast<int>(entity, kTeamOffset);
            if (g_Config.espTeamCheck && localTeam != 0 && team == localTeam) continue;
            if (distanceMax > 0.0f && Distance(localOrigin, origin) > distanceMax) continue;

            Player& p = snapshot[count];
            p.index = i;
            p.entity = entity;
            p.origin = origin;
            p.health = health;
            p.team = team;
            p.viewOffset = vOff;
            p.ducked = ReadNetvarFast<int>(entity, kDuckedOffset);
            std::strncpy(p.name, info.name[0] ? info.name : "player", sizeof(p.name) - 1);

            {
                std::lock_guard<std::mutex> lock(LuaBridge::g_roleMutex);
                const LuaBridge::PlayerRoleInfo& r = LuaBridge::g_roleByIndex[i];
                uint32_t age = now - r.lastUpdate;
                if (r.lastUpdate != 0 && age < 2000) {
                    p.traitor = r.traitor;
                    p.itemTraitor = r.itemTraitor;
                    p.traitorAlly = r.traitorAlly;
                    p.visible = r.visible;
                    p.inRagdoll = r.inRagdoll;
                    p.roleKnown = true;
                }
            }

            // Bones are read always (alive model or ragdoll). Lua sends them
            // from whichever entity GetCharacter returns (player or ragdoll).
            {
                std::lock_guard<std::mutex> lock(LuaBridge::g_boneMutex);
                const LuaBridge::PlayerBoneData& b = LuaBridge::g_bonesByIndex[i];
                uint32_t age = now - b.lastUpdate;
                if (b.lastUpdate != 0 && age < 500) {
                    p.bones = b;
                    p.bonesValid = true;
                }
            }

            ++count;
        }

        {
            std::lock_guard<std::mutex> lock(g_mutex);
            std::memcpy(g_players, snapshot, sizeof(Player) * count);
            g_playerCount.store(count, std::memory_order_relaxed);
        }

        int calls = ++g_collectCalls;
        if (calls <= 10) {
            Log("[ESP] collect #%d: localIdx=%d localEnt=%p count=%d", calls, localIndex, localEntity, count);
        }
        else if (calls % 500 == 0) {
            Log("[ESP] players collected: %d", count);
        }
    }

    inline ImU32 ColorFromFloat(const float rgba[4]) {
        return IM_COL32(
            (int)(rgba[0] * 255),
            (int)(rgba[1] * 255),
            (int)(rgba[2] * 255),
            (int)(rgba[3] * 255));
    }

    inline void DrawSkeleton(ImDrawList* draw, const Player& p,
        const float matrix[16], int screenW, int screenH) {
        if (!p.bonesValid) return;

        ImU32 color = ColorFromFloat(g_Config.espSkeletonColor);

        for (int i = 0; i < kBonePairCount; ++i) {
            int a = kBonePairs[i].a;
            int b = kBonePairs[i].b;
            if (a >= p.bones.count || b >= p.bones.count) continue;
            if (!p.bones.valid[a] || !p.bones.valid[b]) continue;

            SDK::Vector3D wa{ p.bones.x[a], p.bones.y[a], p.bones.z[a] };
            SDK::Vector3D wb{ p.bones.x[b], p.bones.y[b], p.bones.z[b] };

            SDK::Vector3D sa{}, sb{};
            if (!WorldToScreen(wa, sa, matrix, screenW, screenH)) continue;
            if (!WorldToScreen(wb, sb, matrix, screenW, screenH)) continue;

            draw->AddLine(ImVec2(sa.x, sa.y), ImVec2(sb.x, sb.y), color, 1.5f);
        }
    }

    inline bool TryGetBoneBoxScreen(const Player& p,
        const float matrix[16], int screenW, int screenH,
        float& top, float& bottom, float& centerX) {
        if (!p.bonesValid || p.bones.count <= 6) return false;
        if (!p.bones.valid[6]) return false;

        int footBone = -1;
        if (p.bones.count > 17 && p.bones.valid[17]) footBone = 17;
        else if (p.bones.count > 21 && p.bones.valid[21]) footBone = 21;
        else return false;

        SDK::Vector3D headW{ p.bones.x[6], p.bones.y[6], p.bones.z[6] };
        headW.z += 6.0f;
        SDK::Vector3D feetW{ p.bones.x[footBone], p.bones.y[footBone], p.bones.z[footBone] };

        SDK::Vector3D headS{}, feetS{};
        if (!WorldToScreen(headW, headS, matrix, screenW, screenH)) return false;
        if (!WorldToScreen(feetW, feetS, matrix, screenW, screenH)) return false;

        if (headS.y > feetS.y) { float t = headS.y; headS.y = feetS.y; feetS.y = t; }
        top = headS.y;
        bottom = feetS.y;
        centerX = (headS.x + feetS.x) * 0.5f;
        return true;
    }

    inline int Render() {
        if (!g_Config.esp) return 0;
        if (g_Config.espUseLua) return 0;
        if (!g_renderStateValid.load(std::memory_order_relaxed)) return 0;
        if (!IsInGame()) return 0;

        int count = g_playerCount.load(std::memory_order_relaxed);
        if (count <= 0) return 0;

        ImDrawList* draw = ImGui::GetForegroundDrawList();
        if (!draw) return 0;

        float matrix[16] = {};
        int screenW = 0, screenH = 0;
        {
            std::lock_guard<std::mutex> lock(g_matrixMutex);
            std::memcpy(matrix, g_cachedMatrix, sizeof(matrix));
            screenW = g_cachedScreenW;
            screenH = g_cachedScreenH;
        }
        if (screenW <= 0 || screenH <= 0) return 0;

        Player snapshot[kMaxPlayers];
        {
            std::lock_guard<std::mutex> lock(g_mutex);
            std::memcpy(snapshot, g_players, sizeof(Player) * count);
        }

        SDK::Vector3D localOrigin{};
        {
            std::lock_guard<std::mutex> lock(g_mutex);
            localOrigin = g_localOrigin;
        }

        int rendered = 0;
        for (int i = 0; i < count; ++i) {
            const Player& p = snapshot[i];

            float top = 0.0f, bottom = 0.0f, centerX = 0.0f;
            bool haveBox = false;

            // Bone-based box works for both alive player and ragdoll,
            // since bones are sent from whichever entity GetCharacter returned.
            if (p.bonesValid) {
                haveBox = TryGetBoneBoxScreen(p, matrix, screenW, screenH, top, bottom, centerX);
            }

            if (!haveBox) {
                float eyeH = p.viewOffset.z;
                if (eyeH < 20.0f || eyeH > 90.0f)
                    eyeH = p.ducked ? kDuckEyeHeight : kStandEyeHeight;

                SDK::Vector3D head = p.origin;
                head.z += eyeH + 8.0f;
                SDK::Vector3D feet = p.origin;
                feet.z -= 2.0f;

                SDK::Vector3D headScreen{}, feetScreen{};
                if (!WorldToScreen(head, headScreen, matrix, screenW, screenH)) continue;
                if (!WorldToScreen(feet, feetScreen, matrix, screenW, screenH)) continue;

                top = headScreen.y;
                bottom = feetScreen.y;
                if (top > bottom) { float t = top; top = bottom; bottom = t; }
                centerX = headScreen.x;
            }

            float height = bottom - top;
            if (height < 2.0f || height > 4000.0f) continue;

            float width = height * g_Config.espBoxWidthScale;
            float left = centerX - width / 2.0f;
            float right = centerX + width / 2.0f;

            ImU32 boxColor = 0;

            if (p.traitor) {
                boxColor = ColorFromFloat(p.traitorAlly
                    ? g_Config.espTraitorAllyColor
                    : g_Config.espTraitorEnemyColor);
            }
            else if (p.itemTraitor) {
                boxColor = IM_COL32(255, 165, 0, 255);
            }
            else if (!p.visible) {
                boxColor = ColorFromFloat(g_Config.espInvisibleColor);
            }
            else {
                boxColor = ColorFromFloat(g_Config.espVisibleColor);
            }

            if (g_Config.espSkeleton && p.bonesValid) {
                DrawSkeleton(draw, p, matrix, screenW, screenH);
            }

            if (g_Config.espBox) {
                if (g_Config.espBoxStyle == 0) {
                    float len = width * 0.25f;
                    draw->AddLine(ImVec2(left, top), ImVec2(left + len, top), boxColor, g_Config.espBoxThickness);
                    draw->AddLine(ImVec2(left, top), ImVec2(left, top + len), boxColor, g_Config.espBoxThickness);
                    draw->AddLine(ImVec2(right - len, top), ImVec2(right, top), boxColor, g_Config.espBoxThickness);
                    draw->AddLine(ImVec2(right, top), ImVec2(right, top + len), boxColor, g_Config.espBoxThickness);
                    draw->AddLine(ImVec2(left, bottom - len), ImVec2(left, bottom), boxColor, g_Config.espBoxThickness);
                    draw->AddLine(ImVec2(left, bottom), ImVec2(left + len, bottom), boxColor, g_Config.espBoxThickness);
                    draw->AddLine(ImVec2(right - len, bottom), ImVec2(right, bottom), boxColor, g_Config.espBoxThickness);
                    draw->AddLine(ImVec2(right, bottom - len), ImVec2(right, bottom), boxColor, g_Config.espBoxThickness);
                }
                else if (g_Config.espBoxStyle == 1) {
                    draw->AddRect(ImVec2(left, top), ImVec2(right, bottom),
                        boxColor, 0.0f, g_Config.espBoxThickness);
                }
                else {
                    ImU32 fillColor = ColorFromFloat(g_Config.espFillColor);
                    draw->AddRectFilled(ImVec2(left, top), ImVec2(right, bottom), fillColor);
                    draw->AddRect(ImVec2(left, top), ImVec2(right, bottom),
                        boxColor, 0.0f, g_Config.espBoxThickness);
                }
            }

            if (g_Config.espLines) {
                ImU32 lineColor = ColorFromFloat(g_Config.espSnaplineColor);
                draw->AddLine(ImVec2(screenW / 2.0f, (float)screenH),
                    ImVec2(centerX, bottom), lineColor, 1.0f);
            }

            if (g_Config.espName)
                draw->AddText(ImVec2(left, top - 13.0f), IM_COL32(255, 255, 255, 255), p.name);

            if (g_Config.espShowRole && p.roleKnown) {
                const char* roleText = nullptr;
                ImU32 roleColor = 0;
                if (p.traitor) {
                    roleText = "TRAITOR";
                    roleColor = ColorFromFloat(g_Config.espTraitorEnemyColor);
                }
                else if (p.itemTraitor) {
                    roleText = "ITEM_T";
                    roleColor = IM_COL32(255, 165, 0, 255);
                }
                if (roleText)
                    draw->AddText(ImVec2(left, top - 28.0f), roleColor, roleText);
            }

            if (g_Config.espHealth) {
                char buf[32];
                sprintf_s(buf, sizeof(buf), "HP: %d", p.health);
                draw->AddText(ImVec2(left, bottom + 2.0f), IM_COL32(120, 255, 120, 255), buf);
            }

            if (g_Config.espDistance) {
                char buf[32];
                float dist = Distance(localOrigin, p.origin);
                sprintf_s(buf, sizeof(buf), "D: %.0f", dist);
                draw->AddText(ImVec2(left, bottom + 15.0f), IM_COL32(220, 220, 220, 255), buf);
            }
            ++rendered;
        }
        return rendered;
    }

    inline void Reset() {
        std::lock_guard<std::mutex> lock(g_mutex);
        ResetSnapshotLocked();
        g_renderStateValid.store(false, std::memory_order_relaxed);
    }

} // namespace Esp