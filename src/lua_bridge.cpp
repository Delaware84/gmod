#include "config.hpp"
#include "lua_bridge.hpp"

namespace LuaBridge {

    lua_State* g_L = nullptr;

    fn_pcall        p_pcall = nullptr;
    fn_gettop       p_gettop = nullptr;
    fn_settop       p_settop = nullptr;
    fn_type         p_type = nullptr;
    fn_tolstring    p_tolstring = nullptr;
    fn_pushnumber   p_pushnumber = nullptr;
    fn_pushinteger  p_pushinteger = nullptr;
    fn_pushboolean  p_pushboolean = nullptr;
    fn_getfield     p_getfield = nullptr;
    fn_setfield     p_setfield = nullptr;
    fn_loadbuffer   p_loadbuffer = nullptr;
    fn_createtable  p_createtable = nullptr;
    fn_toboolean    p_toboolean = nullptr;
    fn_pushcclosure p_pushcclosure = nullptr;
    fn_tointeger    p_tointeger = nullptr;
    fn_tonumber     p_tonumber = nullptr;

    std::vector<Feature> g_features;

    bool ResolveApi() {
        HMODULE lua = GetModuleHandleA("lua_shared.dll");
        if (!lua) { LogErr("[LUA] lua_shared.dll not loaded"); return false; }

        p_pcall = (fn_pcall)GetProcAddress(lua, "lua_pcall");
        p_gettop = (fn_gettop)GetProcAddress(lua, "lua_gettop");
        p_settop = (fn_settop)GetProcAddress(lua, "lua_settop");
        p_type = (fn_type)GetProcAddress(lua, "lua_type");
        p_tolstring = (fn_tolstring)GetProcAddress(lua, "lua_tolstring");
        p_pushnumber = (fn_pushnumber)GetProcAddress(lua, "lua_pushnumber");
        p_pushboolean = (fn_pushboolean)GetProcAddress(lua, "lua_pushboolean");
        p_pushinteger = (fn_pushinteger)GetProcAddress(lua, "lua_pushinteger");
        p_getfield = (fn_getfield)GetProcAddress(lua, "lua_getfield");
        p_setfield = (fn_setfield)GetProcAddress(lua, "lua_setfield");
        p_loadbuffer = (fn_loadbuffer)GetProcAddress(lua, "luaL_loadbuffer");
        p_createtable = (fn_createtable)GetProcAddress(lua, "lua_createtable");
        p_toboolean = (fn_toboolean)GetProcAddress(lua, "lua_toboolean");
        p_pushcclosure = (fn_pushcclosure)GetProcAddress(lua, "lua_pushcclosure");
        p_tointeger = (fn_tointeger)GetProcAddress(lua, "lua_tointeger");
        p_tonumber = (fn_tonumber)GetProcAddress(lua, "lua_tonumber");

        if (!p_pcall || !p_gettop || !p_settop || !p_type || !p_tolstring ||
            !p_pushnumber || !p_pushboolean || !p_pushinteger || !p_getfield ||
            !p_setfield || !p_loadbuffer || !p_createtable || !p_toboolean ||
            !p_pushcclosure || !p_tointeger || !p_tonumber) {
            LogErr("[LUA] missing exports");
            return false;
        }
        return true;
    }

    bool ResolveState() {
        if (g_L) {
            if (IsStateAlive()) return true;
            LogWarn("[LUA] stale lua_State %p, re-resolving", g_L);
            g_L = nullptr;
        }

        void* pLuaShared = SDK::InterfaceManager::get<void*>("lua_shared.dll", "LUASHARED003");
        if (!pLuaShared) return false;
        void** vmt = GetVmt(pLuaShared);
        if (!vmt) return false;

        using GetLuaInterfaceFn = void* (__fastcall*)(void*, int);
        void* iface = nullptr;
        __try {
            iface = ((GetLuaInterfaceFn)vmt[6])(pLuaShared, 0);
        }
        __except (EXCEPTION_EXECUTE_HANDLER) { return false; }

        if (!iface) return false;
        g_L = *reinterpret_cast<lua_State**>(reinterpret_cast<uint8_t*>(iface) + 0x8);
        if (!g_L) return false;
        return true;
    }

    int lua_RegisterFeature(lua_State* L) {
        const char* name = p_tolstring(L, 1, nullptr);
        int def = p_toboolean(L, 2);
        if (!name) { p_pushboolean(L, 0); return 1; }

        for (auto& f : g_features) {
            if (f.name == name) { p_pushboolean(L, 0); return 1; }
        }
        g_features.push_back({ name, def != 0 });
        Log("[LUA] Feature registered: %s", name);
        p_pushboolean(L, 1);
        return 1;
    }

    int lua_IsFeatureEnabled(lua_State* L) {
        const char* name = p_tolstring(L, 1, nullptr);
        if (!name) { p_pushboolean(L, 0); return 1; }

        if (!g_Config.espUseLua && strcmp(name, "esp_boxes") == 0) {
            p_pushboolean(L, 0);
            return 1;
        }

        for (auto& f : g_features) {
            if (f.name == name) { p_pushboolean(L, f.enabled ? 1 : 0); return 1; }
        }
        p_pushboolean(L, 0);
        return 1;
    }

    bool RunLua(const char* script) {
        if (!g_L || !p_settop || !p_gettop || !p_loadbuffer || !p_pcall) return false;
        int top = p_gettop(g_L);
        int rc = p_loadbuffer(g_L, script, strlen(script), "@dll_script");
        if (rc != LUA_OK) {
            const char* err = p_tolstring(g_L, -1, nullptr);
            LogErr("[LUA] loadbuffer failed: %s", err ? err : "?");
            p_settop(g_L, top);
            return false;
        }
        rc = p_pcall(g_L, 0, 0, 0);
        if (rc != LUA_OK) {
            const char* err = p_tolstring(g_L, -1, nullptr);
            LogErr("[LUA] pcall failed: %s", err ? err : "?");
            p_settop(g_L, top);
            return false;
        }
        p_settop(g_L, top);
        return true;
    }

    int lua_GetEspSetting(lua_State* L) {
        if (p_type(L, 1) != LUA_TSTRING) { p_pushboolean(L, 0); return 1; }
        const char* name = p_tolstring(L, 1, nullptr);
        if (!name) { p_pushboolean(L, 0); return 1; }

        if (strcmp(name, "esp") == 0)                 p_pushboolean(L, (g_Config.esp && g_Config.espUseLua) ? 1 : 0);
        else if (strcmp(name, "espBox") == 0)         p_pushboolean(L, g_Config.espBox ? 1 : 0);
        else if (strcmp(name, "espBoxStyle") == 0)    p_pushnumber(L, g_Config.espBoxStyle);
        else if (strcmp(name, "espBoxThickness") == 0)p_pushnumber(L, g_Config.espBoxThickness);
        else if (strcmp(name, "espBoxWidthScale") == 0)p_pushnumber(L, g_Config.espBoxWidthScale);
        else if (strcmp(name, "espSkeleton") == 0)    p_pushboolean(L, g_Config.espSkeleton ? 1 : 0);
        else if (strcmp(name, "espLines") == 0)       p_pushboolean(L, g_Config.espLines ? 1 : 0);
        else if (strcmp(name, "espVisibleCheck") == 0)p_pushboolean(L, g_Config.espVisibleCheck ? 1 : 0);
        else if (strcmp(name, "espDistanceMax") == 0) p_pushnumber(L, g_Config.espDistanceMax);
        else if (strcmp(name, "espTeamFilter") == 0)  p_pushnumber(L, g_Config.espTeamFilter);
        else if (strcmp(name, "espShowStatus") == 0)  p_pushboolean(L, g_Config.espShowStatus ? 1 : 0);
        else if (strcmp(name, "espShowRole") == 0)    p_pushboolean(L, g_Config.espShowRole ? 1 : 0);
        else if (strcmp(name, "espName") == 0)        p_pushboolean(L, g_Config.espName ? 1 : 0);
        else if (strcmp(name, "espHealth") == 0)      p_pushboolean(L, g_Config.espHealth ? 1 : 0);
        else if (strcmp(name, "espDistance") == 0)    p_pushboolean(L, g_Config.espDistance ? 1 : 0);
        else if (strcmp(name, "espTeamCheck") == 0)   p_pushboolean(L, g_Config.espTeamCheck ? 1 : 0);
        else if (strcmp(name, "norecoil") == 0)       p_pushboolean(L, g_Config.norecoilEnabled ? 1 : 0);
        else if (strcmp(name, "norecoilPunch") == 0)  p_pushboolean(L, g_Config.norecoilPunch ? 1 : 0);
        else if (strcmp(name, "norecoilSpread") == 0) p_pushboolean(L, g_Config.norecoilSpread ? 1 : 0);
        else if (strcmp(name, "norecoilSpray") == 0)  p_pushboolean(L, g_Config.norecoilSpray ? 1 : 0);
        else if (strcmp(name, "aimbot") == 0)         p_pushboolean(L, g_Config.aimbotEnabled ? 1 : 0);
        else if (strcmp(name, "aimbotFov") == 0)      p_pushnumber(L, g_Config.aimbotFov);
        else if (strcmp(name, "aimbotSmooth") == 0)   p_pushnumber(L, g_Config.aimbotSmooth);
        else if (strcmp(name, "aimbotTarget") == 0)   p_pushnumber(L, g_Config.aimbotTarget);
        else if (strcmp(name, "aimbotVisibleCheck") == 0) p_pushboolean(L, g_Config.aimbotVisibleCheck ? 1 : 0);
        else if (strcmp(name, "aimbotVelocityComp") == 0) p_pushboolean(L, g_Config.aimbotVelocityComp ? 1 : 0);
        else if (strcmp(name, "aimbotPingComp") == 0) p_pushboolean(L, g_Config.aimbotPingComp ? 1 : 0);
        else if (strcmp(name, "aimbotAutoFire") == 0) p_pushboolean(L, g_Config.aimbotAutoFire ? 1 : 0);
        else p_pushboolean(L, 0);

        return 1;
    }

    int lua_GetEspColor(lua_State* L) {
        if (p_type(L, 1) != LUA_TSTRING) {
            p_createtable(L, 0, 4);
            p_pushinteger(L, 255); p_setfield(L, -2, "r");
            p_pushinteger(L, 255); p_setfield(L, -2, "g");
            p_pushinteger(L, 255); p_setfield(L, -2, "b");
            p_pushinteger(L, 255); p_setfield(L, -2, "a");
            return 1;
        }
        const char* name = p_tolstring(L, 1, nullptr);
        float r = 1, g = 1, b = 1, a = 1;
        if (name) {
            if (strcmp(name, "espVisibleColor") == 0) { r = g_Config.espVisibleColor[0];   g = g_Config.espVisibleColor[1];   b = g_Config.espVisibleColor[2];   a = g_Config.espVisibleColor[3]; }
            else if (strcmp(name, "espInvisibleColor") == 0) { r = g_Config.espInvisibleColor[0]; g = g_Config.espInvisibleColor[1]; b = g_Config.espInvisibleColor[2]; a = g_Config.espInvisibleColor[3]; }
            else if (strcmp(name, "espSnaplineColor") == 0) { r = g_Config.espSnaplineColor[0];  g = g_Config.espSnaplineColor[1];  b = g_Config.espSnaplineColor[2];  a = g_Config.espSnaplineColor[3]; }
            else if (strcmp(name, "espSkeletonColor") == 0) { r = g_Config.espSkeletonColor[0];  g = g_Config.espSkeletonColor[1];  b = g_Config.espSkeletonColor[2];  a = g_Config.espSkeletonColor[3]; }
            else if (strcmp(name, "espFillColor") == 0) { r = g_Config.espFillColor[0];      g = g_Config.espFillColor[1];      b = g_Config.espFillColor[2];      a = g_Config.espFillColor[3]; }

            else if (strcmp(name, "espTeammateColor") == 0) { r = g_Config.espTeammateColor[0];      g = g_Config.espTeammateColor[1];      b = g_Config.espTeammateColor[2];      a = g_Config.espTeammateColor[3]; }
            else if (strcmp(name, "espTraitorAllyColor") == 0) { r = g_Config.espTraitorAllyColor[0];   g = g_Config.espTraitorAllyColor[1];   b = g_Config.espTraitorAllyColor[2];   a = g_Config.espTraitorAllyColor[3]; }
            else if (strcmp(name, "espTraitorEnemyColor") == 0) { r = g_Config.espTraitorEnemyColor[0];  g = g_Config.espTraitorEnemyColor[1];  b = g_Config.espTraitorEnemyColor[2];  a = g_Config.espTraitorEnemyColor[3]; }
        }
        p_createtable(L, 0, 4);
        p_pushinteger(L, (int)(r * 255)); p_setfield(L, -2, "r");
        p_pushinteger(L, (int)(g * 255)); p_setfield(L, -2, "g");
        p_pushinteger(L, (int)(b * 255)); p_setfield(L, -2, "b");
        p_pushinteger(L, (int)(a * 255)); p_setfield(L, -2, "a");
        return 1;
    }

    int lua_SetPlayerRole(lua_State* L) {
        int index = (int)p_tointeger(L, 1);
        if (index <= 0 || index >= kMaxPlayers) { p_pushboolean(L, 0); return 1; }

        bool traitor = p_toboolean(L, 2) != 0;
        bool itemTraitor = p_toboolean(L, 3) != 0;
        bool traitorAlly = p_toboolean(L, 4) != 0;
        bool visible = p_toboolean(L, 5) != 0;
        bool inRagdoll = p_toboolean(L, 6) != 0;

        {
            std::lock_guard<std::mutex> lock(g_roleMutex);
            PlayerRoleInfo& r = g_roleByIndex[index];
            r.traitor = traitor;
            r.itemTraitor = itemTraitor;
            r.traitorAlly = traitorAlly;
            r.visible = visible;
            r.inRagdoll = inRagdoll;
            r.lastUpdate = GetTickCount();
        }
        p_pushboolean(L, 1);
        return 1;
    }

    int lua_MarkRoleFrame(lua_State* L) {
        g_roleFrame.fetch_add(1, std::memory_order_relaxed);
        p_pushboolean(L, 1);
        return 1;
    }

    int lua_SetPlayerBone(lua_State* L) {
        int index = (int)p_tointeger(L, 1);
        int bone = (int)p_tointeger(L, 2);
        if (index <= 0 || index >= kMaxPlayers) { p_pushboolean(L, 0); return 1; }
        if (bone < 0 || bone >= kMaxBones) { p_pushboolean(L, 0); return 1; }

        double x = p_tonumber(L, 3);
        double y = p_tonumber(L, 4);
        double z = p_tonumber(L, 5);

        {
            std::lock_guard<std::mutex> lock(g_boneMutex);
            PlayerBoneData& d = g_bonesByIndex[index];
            d.x[bone] = (float)x;
            d.y[bone] = (float)y;
            d.z[bone] = (float)z;
            d.valid[bone] = true;
            if (bone + 1 > d.count) d.count = bone + 1;
            d.lastUpdate = GetTickCount();
        }
        p_pushboolean(L, 1);
        return 1;
    }

    int lua_ClearPlayerBones(lua_State* L) {
        int index = (int)p_tointeger(L, 1);
        if (index <= 0 || index >= kMaxPlayers) { p_pushboolean(L, 0); return 1; }

        {
            std::lock_guard<std::mutex> lock(g_boneMutex);
            PlayerBoneData& d = g_bonesByIndex[index];
            for (int i = 0; i < kMaxBones; ++i) d.valid[i] = false;
            d.count = 0;
            d.lastUpdate = GetTickCount();
        }
        p_pushboolean(L, 1);
        return 1;
    }

    int lua_SetPlayerAimPoints(lua_State* L) {
        int index = (int)p_tointeger(L, 1);
        if (index <= 0 || index >= kMaxPlayers) { p_pushboolean(L, 0); return 1; }

        double hx = p_tonumber(L, 2), hy = p_tonumber(L, 3), hz = p_tonumber(L, 4);
        double cx = p_tonumber(L, 5), cy = p_tonumber(L, 6), cz = p_tonumber(L, 7);
        double px = p_tonumber(L, 8), py = p_tonumber(L, 9), pz = p_tonumber(L, 10);

        {
            std::lock_guard<std::mutex> lock(g_aimMutex);
            PlayerAimPoints& p = g_aimByIndex[index];
            p.head[0] = (float)hx; p.head[1] = (float)hy; p.head[2] = (float)hz;
            p.chest[0] = (float)cx; p.chest[1] = (float)cy; p.chest[2] = (float)cz;
            p.pelvis[0] = (float)px; p.pelvis[1] = (float)py; p.pelvis[2] = (float)pz;
            p.valid = (hx != 0.0 || hy != 0.0 || hz != 0.0);
            p.lastUpdate = GetTickCount();
        }
        p_pushboolean(L, 1);
        return 1;
    }

    int lua_SetPlayerVelocity(lua_State* L) {
        int index = (int)p_tointeger(L, 1);
        if (index <= 0 || index >= kMaxPlayers) { p_pushboolean(L, 0); return 1; }

        double vx = p_tonumber(L, 2);
        double vy = p_tonumber(L, 3);
        double vz = p_tonumber(L, 4);

        {
            std::lock_guard<std::mutex> lock(g_aimMutex);
            PlayerVelocity& v = g_velByIndex[index];
            v.vx = (float)vx; v.vy = (float)vy; v.vz = (float)vz;
            v.lastUpdate = GetTickCount();
        }
        p_pushboolean(L, 1);
        return 1;
    }

    int lua_SetLocalMuzzle(lua_State* L) {
        double x = p_tonumber(L, 1);
        double y = p_tonumber(L, 2);
        double z = p_tonumber(L, 3);

        {
            std::lock_guard<std::mutex> lock(g_muzzleMutex);
            g_localMuzzle[0] = (float)x;
            g_localMuzzle[1] = (float)y;
            g_localMuzzle[2] = (float)z;
            g_localMuzzleValid = (x != 0.0 || y != 0.0 || z != 0.0);
            g_localMuzzleTime = GetTickCount();
        }
        p_pushboolean(L, 1);
        return 1;
    }

    // __dll_SetLocalWeaponAng(pitch, yaw)
    int lua_SetLocalWeaponAng(lua_State* L) {
        double pitch = p_tonumber(L, 1);
        double yaw = p_tonumber(L, 2);

        {
            std::lock_guard<std::mutex> lock(g_weaponAngMutex);
            g_localWeaponAng[0] = (float)pitch;
            g_localWeaponAng[1] = (float)yaw;
            g_localWeaponAngValid = (pitch != 0.0 || yaw != 0.0);
            g_localWeaponAngTime = GetTickCount();
        }
        p_pushboolean(L, 1);
        return 1;
    }

    bool Init() {
        if (!ResolveApi()) return false;
        if (!ResolveState()) return false;

        p_settop(g_L, 0);

        p_pushcclosure(g_L, lua_RegisterFeature, 0);
        p_setfield(g_L, LUA_GLOBALSINDEX, "__dll_RegisterFeature");

        p_pushcclosure(g_L, lua_IsFeatureEnabled, 0);
        p_setfield(g_L, LUA_GLOBALSINDEX, "__dll_IsFeatureEnabled");

        p_pushcclosure(g_L, lua_GetEspSetting, 0);
        p_setfield(g_L, LUA_GLOBALSINDEX, "__dll_GetEspSetting");

        p_pushcclosure(g_L, lua_GetEspColor, 0);
        p_setfield(g_L, LUA_GLOBALSINDEX, "__dll_GetEspColor");

        p_pushcclosure(g_L, lua_SetPlayerRole, 0);
        p_setfield(g_L, LUA_GLOBALSINDEX, "__dll_SetPlayerRole");

        p_pushcclosure(g_L, lua_MarkRoleFrame, 0);
        p_setfield(g_L, LUA_GLOBALSINDEX, "__dll_MarkRoleFrame");

        p_pushcclosure(g_L, lua_SetPlayerBone, 0);
        p_setfield(g_L, LUA_GLOBALSINDEX, "__dll_SetPlayerBone");

        p_pushcclosure(g_L, lua_ClearPlayerBones, 0);
        p_setfield(g_L, LUA_GLOBALSINDEX, "__dll_ClearPlayerBones");

        p_pushcclosure(g_L, lua_SetPlayerAimPoints, 0);
        p_setfield(g_L, LUA_GLOBALSINDEX, "__dll_SetPlayerAimPoints");

        p_pushcclosure(g_L, lua_SetPlayerVelocity, 0);
        p_setfield(g_L, LUA_GLOBALSINDEX, "__dll_SetPlayerVelocity");

        p_pushcclosure(g_L, lua_SetLocalMuzzle, 0);
        p_setfield(g_L, LUA_GLOBALSINDEX, "__dll_SetLocalMuzzle");

        p_pushcclosure(g_L, lua_SetLocalWeaponAng, 0);
        p_setfield(g_L, LUA_GLOBALSINDEX, "__dll_SetLocalWeaponAng");

        p_settop(g_L, 0);
        return true;
    }

} // namespace LuaBridge