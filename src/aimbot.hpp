#pragma once
#include <windows.h>
#include <atomic>
#include <cmath>
#include <cstring>
#include <mutex>
#include "config.hpp"
#include "globals.hpp"
#include "logger.hpp"
#include "util.hpp"
#include "sdk.hpp"
#include "lua_bridge.hpp"

namespace Aimbot {

    constexpr float kPi = 3.14159265358979323846f;
    constexpr float kRadToDeg = 180.0f / kPi;
    constexpr float kDegToRad = kPi / 180.0f;

    struct Vec3 { float x, y, z; };

    inline void VectorAngles(const Vec3& forward, SDK::QAngle& angles) {
        float hyp = std::sqrt(forward.x * forward.x + forward.y * forward.y);
        angles.pitch = std::atan2(-forward.z, hyp) * kRadToDeg;
        angles.yaw = std::atan2(forward.y, forward.x) * kRadToDeg;
        angles.roll = 0.0f;
    }

    inline float NormalizeAngle(float a) {
        while (a > 180.0f) a -= 360.0f;
        while (a < -180.0f) a += 360.0f;
        return a;
    }

    inline float AngleDelta(float a, float b) {
        return NormalizeAngle(a - b);
    }

    inline float ClampF(float v, float lo, float hi) {
        if (v < lo) return lo;
        if (v > hi) return hi;
        return v;
    }

    inline int      g_stickyTarget = -1;
    inline uint32_t g_stickyTime = 0;
    inline SDK::QAngle g_lastAimAngles{};
    inline bool     g_lastAimValid = false;
    inline uint32_t g_lastLogTick = 0;

    struct Candidate {
        int index = -1;
        SDK::Vector3D point{};
        float fov = 0.0f;
        bool visible = true;
        bool sticky = false;
    };

    inline bool GetFallbackHead(int index, SDK::Vector3D& out, void* entity) {
        {
            std::lock_guard<std::mutex> lock(LuaBridge::g_boneMutex);
            const LuaBridge::PlayerBoneData& b = LuaBridge::g_bonesByIndex[index];
            if (b.valid[6] && b.lastUpdate != 0 && (GetTickCount() - b.lastUpdate) < 500) {
                out = { b.x[6], b.y[6], b.z[6] + 4.0f };
                return true;
            }
        }
        if (entity) {
            SDK::Vector3D o = ReadNetvarFast<SDK::Vector3D>(entity, 0x438);
            if (std::isfinite(o.x) && std::isfinite(o.y) && std::isfinite(o.z)) {
                out = { o.x, o.y, o.z + 64.0f };
                return true;
            }
        }
        return false;
    }

    inline float ComputeLatencySec(bool isLocal) {
        if (!g_Config.aimbotVelocityComp) return 0.0f;
        if (isLocal) return 0.0f;
        if (!g_Config.aimbotPingComp) return 0.0f;
        float pingMs = g_Config.aimbotPing;
        if (pingMs < 0.0f) pingMs = 0.0f;
        float interp = g_Config.aimbotInterp;
        if (interp < 0.0f) interp = 0.0f;
        return pingMs * 0.001f + interp;
    }

    inline bool IsLocalGame() {
        return g_Config.aimbotPing <= 5.0f;
    }

    inline void Run(SDK::CUserCmd* cmd, float sampleTime) {
        if (!cmd) return;
        if (!g_Config.aimbotEnabled) {
            g_stickyTarget = -1;
            g_lastAimValid = false;
            return;
        }

        // RMB gate: aimbot only while player holds right mouse button.
        if (g_Config.aimbotOnRMB && !(cmd->buttons & SDK::IN_ATTACK2)) {
            g_stickyTarget = -1;
            g_lastAimValid = false;
            return;
        }

        int localIndex = GetLocalPlayerIndex();
        void* local = GetLocalPlayer();
        if (!local || localIndex <= 0) return;

        SDK::Vector3D eye = ReadNetvarFast<SDK::Vector3D>(local, 0x438);
        SDK::Vector3D viewOffset = ReadNetvarFast<SDK::Vector3D>(local, 0x144);
        if (!std::isfinite(viewOffset.z)) viewOffset.z = 64.0f;
        eye.x += viewOffset.x; eye.y += viewOffset.y; eye.z += viewOffset.z;

        SDK::Vector3D muzzle = eye;
        bool haveMuzzle = false;
        {
            std::lock_guard<std::mutex> lock(LuaBridge::g_muzzleMutex);
            uint32_t age = GetTickCount() - LuaBridge::g_localMuzzleTime;
            if (LuaBridge::g_localMuzzleValid && LuaBridge::g_localMuzzleTime != 0 && age < 500) {
                muzzle.x = LuaBridge::g_localMuzzle[0];
                muzzle.y = LuaBridge::g_localMuzzle[1];
                muzzle.z = LuaBridge::g_localMuzzle[2];
                haveMuzzle = true;
            }
        }

        float weaponPitch = 0.0f, weaponYaw = 0.0f;
        bool haveWeaponAng = false;
        {
            std::lock_guard<std::mutex> lock(LuaBridge::g_weaponAngMutex);
            uint32_t age = GetTickCount() - LuaBridge::g_localWeaponAngTime;
            if (LuaBridge::g_localWeaponAngValid && LuaBridge::g_localWeaponAngTime != 0 && age < 500) {
                weaponPitch = LuaBridge::g_localWeaponAng[0];
                weaponYaw = LuaBridge::g_localWeaponAng[1];
                haveWeaponAng = true;
            }
        }

        SDK::QAngle baseAngles = cmd->viewangles;
        if (g_lastAimValid) baseAngles = g_lastAimAngles;

        float offsetPitch = 0.0f, offsetYaw = 0.0f;
        bool haveOffset = false;
        if (haveWeaponAng) {
            offsetPitch = AngleDelta(weaponPitch, baseAngles.pitch);
            offsetYaw = AngleDelta(weaponYaw, baseAngles.yaw);
            if (std::fabs(offsetPitch) > 30.0f || std::fabs(offsetYaw) > 30.0f) {
                haveOffset = false;
            }
            else {
                haveOffset = true;
            }
        }

        bool isLocal = IsLocalGame();
        float latencySec = ComputeLatencySec(isLocal);

        float fovNew = g_Config.aimbotFov;
        float fovSticky = g_Config.aimbotFov * 2.0f;

        Candidate best{};
        float bestScore = 1e9f;

        uint32_t now = GetTickCount();

        int stickyIdx = g_stickyTarget;
        if (stickyIdx > 0 && stickyIdx <= 64 && now - g_stickyTime > 2000) {
            g_stickyTarget = -1;
        }

        auto evaluate = [&](int i, bool sticky) -> bool {
            if (i == localIndex) return false;
            void* entity = GetClientEntity(i);
            if (!entity) return false;

            LuaBridge::PlayerAimPoints ap;
            LuaBridge::PlayerVelocity vel;
            LuaBridge::PlayerRoleInfo role;
            {
                std::lock_guard<std::mutex> lock(LuaBridge::g_aimMutex);
                ap = LuaBridge::g_aimByIndex[i];
                vel = LuaBridge::g_velByIndex[i];
            }
            {
                std::lock_guard<std::mutex> lock(LuaBridge::g_roleMutex);
                role = LuaBridge::g_roleByIndex[i];
            }

            bool roleValid = role.lastUpdate != 0 && (now - role.lastUpdate) < 2000;
            if (!roleValid) return false;

            bool apFresh = ap.valid && ap.lastUpdate != 0 && (now - ap.lastUpdate) < 500;

            SDK::Vector3D pts[3];
            pts[0] = { ap.head[0], ap.head[1], ap.head[2] };
            pts[1] = { ap.chest[0], ap.chest[1], ap.chest[2] };
            pts[2] = { ap.pelvis[0], ap.pelvis[1], ap.pelvis[2] };

            if ((pts[0].x == 0 && pts[0].y == 0 && pts[0].z == 0)) {
                SDK::Vector3D fb{};
                if (GetFallbackHead(i, fb, entity)) pts[0] = fb;
            }
            if ((pts[1].x == 0 && pts[1].y == 0 && pts[1].z == 0)) {
                std::lock_guard<std::mutex> lock(LuaBridge::g_boneMutex);
                const LuaBridge::PlayerBoneData& b = LuaBridge::g_bonesByIndex[i];
                if (b.valid[3] && b.lastUpdate != 0 && (now - b.lastUpdate) < 500) {
                    pts[1] = { b.x[3], b.y[3], b.z[3] };
                }
            }

            if (!apFresh && (pts[0].x == 0 && pts[1].x == 0 && pts[2].x == 0)) return false;

            float vx = 0, vy = 0, vz = 0;
            if (g_Config.aimbotVelocityComp && (now - vel.lastUpdate) < 500) {
                vx = vel.vx; vy = vel.vy; vz = vel.vz;
            }

            int first = 0, last = 2;
            if (g_Config.aimbotTarget == 0) { first = 0; last = 0; }
            else if (g_Config.aimbotTarget == 1) { first = 1; last = 1; }

            bool anyGood = false;

            for (int p = first; p <= last; ++p) {
                SDK::Vector3D target = pts[p];
                if (target.x == 0 && target.y == 0 && target.z == 0) continue;
                if (!std::isfinite(target.x) || !std::isfinite(target.y) || !std::isfinite(target.z)) continue;

                if (latencySec > 0.0f) {
                    target.x += vx * latencySec;
                    target.y += vy * latencySec;
                    target.z += vz * latencySec;
                }

                if (g_Config.aimbotVisibleCheck && !role.visible) continue;

                SDK::Vector3D origin = haveMuzzle ? muzzle : eye;
                SDK::Vector3D delta = { target.x - origin.x, target.y - origin.y, target.z - origin.z };
                SDK::QAngle want{};
                VectorAngles({ delta.x, delta.y, delta.z }, want);

                float comparePitch = baseAngles.pitch + offsetPitch;
                float compareYaw = baseAngles.yaw + offsetYaw;

                float dPitch = AngleDelta(want.pitch, comparePitch);
                float dYaw = AngleDelta(want.yaw, compareYaw);
                float fov = std::sqrt(dPitch * dPitch + dYaw * dYaw);

                float limit = sticky ? fovSticky : fovNew;
                if (fov > limit) continue;

                float score = fov - (sticky ? 2.0f : 0.0f);

                if (score < bestScore) {
                    bestScore = score;
                    best.index = i;
                    best.point = target;
                    best.fov = fov;
                    best.visible = role.visible;
                    best.sticky = sticky;
                    anyGood = true;
                }
            }

            return anyGood;
            };

        if (g_stickyTarget > 0) {
            evaluate(g_stickyTarget, true);
        }

        for (int i = 1; i <= 64; ++i) {
            if (i == localIndex) continue;
            if (i == g_stickyTarget) continue;
            evaluate(i, false);
        }

        uint32_t nowTick = GetTickCount();
        if (g_Config.verboseLog && (nowTick - g_lastLogTick) > 500) {
            g_lastLogTick = nowTick;
            Log("[AIM] local=%d lat=%.3f muzzle=%d wang=%d off=%.2f/%.2f sticky=%d best=%d fov=%.2f vis=%d rmb=%d",
                isLocal ? 1 : 0, latencySec, haveMuzzle ? 1 : 0, haveOffset ? 1 : 0,
                offsetPitch, offsetYaw,
                g_stickyTarget, best.index, best.fov, best.visible ? 1 : 0,
                (cmd->buttons & SDK::IN_ATTACK2) ? 1 : 0);
        }

        if (best.index < 0) {
            g_lastAimValid = false;
            return;
        }

        g_stickyTarget = best.index;
        g_stickyTime = nowTick;

        SDK::Vector3D origin = haveMuzzle ? muzzle : eye;
        SDK::Vector3D delta = { best.point.x - origin.x, best.point.y - origin.y, best.point.z - origin.z };
        SDK::QAngle want{};
        VectorAngles({ delta.x, delta.y, delta.z }, want);

        int smooth = g_Config.aimbotSmooth;
        if (smooth < 0) smooth = 0;
        if (smooth > 30) smooth = 30;

        float newPitch, newYaw;
        if (smooth == 0) {
            newPitch = want.pitch;
            newYaw = want.yaw;
        }
        else {
            float factor = 1.0f / (float)smooth;
            float curBarrelPitch = baseAngles.pitch + offsetPitch;
            float curBarrelYaw = baseAngles.yaw + offsetYaw;
            newPitch = curBarrelPitch + AngleDelta(want.pitch, curBarrelPitch) * factor;
            newYaw = curBarrelYaw + AngleDelta(want.yaw, curBarrelYaw) * factor;
        }

        if (haveOffset) {
            newPitch = newPitch - offsetPitch;
            newYaw = newYaw - offsetYaw;
        }

        newPitch = ClampF(newPitch, -89.0f, 89.0f);
        newYaw = NormalizeAngle(newYaw);

        g_lastAimAngles = { newPitch, newYaw, 0.0f };
        g_lastAimValid = true;

        cmd->viewangles.pitch = newPitch;
        cmd->viewangles.yaw = newYaw;
        cmd->viewangles.roll = 0.0f;

        if (g_Config.aimbotAutoFire) {
            cmd->buttons |= SDK::IN_ATTACK;
        }
    }

} // namespace Aimbot
