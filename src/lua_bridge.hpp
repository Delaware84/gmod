#pragma once
#include <windows.h>
#include <cstring>
#include <string>
#include <vector>
#include <cstdio>
#include <mutex>
#include <atomic>
#include <cstdint>
#include "logger.hpp"
#include "sdk.hpp"
#include "Memory.h"

namespace LuaBridge {

    struct lua_State;

    using fn_pcall = int (*)(lua_State*, int, int, int);
    using fn_gettop = int (*)(lua_State*);
    using fn_settop = void(*)(lua_State*, int);
    using fn_type = int (*)(lua_State*, int);
    using fn_tolstring = const char* (*)(lua_State*, int, size_t*);
    using fn_pushnumber = void(*)(lua_State*, double);
    using fn_pushinteger = void(*)(lua_State*, long long);
    using fn_pushboolean = void(*)(lua_State*, int);
    using fn_getfield = int (*)(lua_State*, int, const char*);
    using fn_setfield = void(*)(lua_State*, int, const char*);
    using fn_loadbuffer = int (*)(lua_State*, const char*, size_t, const char*);
    using fn_createtable = void(*)(lua_State*, int, int);
    using fn_toboolean = int (*)(lua_State*, int);
    using fn_pushcclosure = void(*)(lua_State*, int(*)(lua_State*), int);
    using fn_tointeger = long long (*)(lua_State*, int);
    using fn_tonumber = double (*)(lua_State*, int);

    constexpr int LUA_TNIL = 0;
    constexpr int LUA_TBOOLEAN = 1;
    constexpr int LUA_TNUMBER = 3;
    constexpr int LUA_TSTRING = 4;
    constexpr int LUA_TTABLE = 5;
    constexpr int LUA_TFUNCTION = 6;
    constexpr int LUA_OK = 0;
    constexpr int LUA_GLOBALSINDEX = -10002;

    constexpr int kMaxPlayers = 65;
    constexpr int kMaxBones = 32;

    extern lua_State* g_L;

    extern fn_pcall       p_pcall;
    extern fn_gettop      p_gettop;
    extern fn_settop      p_settop;
    extern fn_type        p_type;
    extern fn_tolstring   p_tolstring;
    extern fn_pushnumber  p_pushnumber;
    extern fn_pushinteger p_pushinteger;
    extern fn_pushboolean p_pushboolean;
    extern fn_getfield    p_getfield;
    extern fn_setfield    p_setfield;
    extern fn_loadbuffer  p_loadbuffer;
    extern fn_createtable p_createtable;
    extern fn_toboolean   p_toboolean;
    extern fn_pushcclosure p_pushcclosure;
    extern fn_tointeger   p_tointeger;
    extern fn_tonumber    p_tonumber;

    struct Feature {
        std::string name;
        bool enabled;
    };
    extern std::vector<Feature> g_features;

    struct PlayerRoleInfo {
        bool traitor = false;
        bool itemTraitor = false;
        bool traitorAlly = false;
        bool visible = true;
        bool inRagdoll = false;
        uint32_t lastUpdate = 0;
    };

    struct PlayerBoneData {
        float x[kMaxBones] = {};
        float y[kMaxBones] = {};
        float z[kMaxBones] = {};
        bool valid[kMaxBones] = {};
        int count = 0;
        uint32_t lastUpdate = 0;
    };

    struct PlayerAimPoints {
        float head[3] = {};
        float chest[3] = {};
        float pelvis[3] = {};
        bool valid = false;
        uint32_t lastUpdate = 0;
    };

    struct PlayerVelocity {
        float vx = 0, vy = 0, vz = 0;
        uint32_t lastUpdate = 0;
    };

    inline std::mutex g_roleMutex;
    inline PlayerRoleInfo g_roleByIndex[kMaxPlayers] = {};
    inline std::atomic<uint32_t> g_roleFrame{ 0 };

    inline std::mutex g_boneMutex;
    inline PlayerBoneData g_bonesByIndex[kMaxPlayers] = {};

    inline std::mutex g_aimMutex;
    inline PlayerAimPoints g_aimByIndex[kMaxPlayers] = {};
    inline PlayerVelocity g_velByIndex[kMaxPlayers] = {};

    inline std::mutex g_muzzleMutex;
    inline float g_localMuzzle[3] = { 0, 0, 0 };
    inline bool  g_localMuzzleValid = false;
    inline uint32_t g_localMuzzleTime = 0;

    inline std::mutex g_weaponAngMutex;
    inline float g_localWeaponAng[2] = { 0, 0 }; // pitch, yaw
    inline bool  g_localWeaponAngValid = false;
    inline uint32_t g_localWeaponAngTime = 0;

    bool ResolveApi();
    bool ResolveState();
    bool Init();
    bool RunLua(const char* script);

    inline void ResetState() {
        g_L = nullptr;
        g_features.clear();
        {
            std::lock_guard<std::mutex> lock(g_roleMutex);
            for (int i = 0; i < kMaxPlayers; ++i) g_roleByIndex[i] = PlayerRoleInfo{};
        }
        {
            std::lock_guard<std::mutex> lock(g_boneMutex);
            for (int i = 0; i < kMaxPlayers; ++i) g_bonesByIndex[i] = PlayerBoneData{};
        }
        {
            std::lock_guard<std::mutex> lock(g_aimMutex);
            for (int i = 0; i < kMaxPlayers; ++i) {
                g_aimByIndex[i] = PlayerAimPoints{};
                g_velByIndex[i] = PlayerVelocity{};
            }
        }
        {
            std::lock_guard<std::mutex> lock(g_muzzleMutex);
            g_localMuzzle[0] = g_localMuzzle[1] = g_localMuzzle[2] = 0;
            g_localMuzzleValid = false;
            g_localMuzzleTime = 0;
        }
        {
            std::lock_guard<std::mutex> lock(g_weaponAngMutex);
            g_localWeaponAng[0] = g_localWeaponAng[1] = 0;
            g_localWeaponAngValid = false;
            g_localWeaponAngTime = 0;
        }
    }

    inline bool IsStateAlive() {
        if (!g_L) return false;
        if (!p_gettop || !p_type) return false;
        if (!IsReadable(g_L, 0x100)) return false;
        int top = p_gettop(g_L);
        return top >= 0 && top < 100000;
    }

    int lua_RegisterFeature(lua_State* L);
    int lua_IsFeatureEnabled(lua_State* L);
    int lua_GetEspSetting(lua_State* L);
    int lua_GetEspColor(lua_State* L);
    int lua_SetPlayerRole(lua_State* L);
    int lua_MarkRoleFrame(lua_State* L);
    int lua_SetPlayerBone(lua_State* L);
    int lua_ClearPlayerBones(lua_State* L);
    int lua_SetPlayerAimPoints(lua_State* L);
    int lua_SetPlayerVelocity(lua_State* L);
    int lua_SetLocalMuzzle(lua_State* L);
    int lua_SetLocalWeaponAng(lua_State* L);

} // namespace LuaBridge