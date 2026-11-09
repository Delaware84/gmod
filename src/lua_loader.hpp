#pragma once
#include <vector>
#include <string>
#include "lua_bridge.hpp"
#include "logger.hpp"

struct LuaScriptEntry {
    const char* name;
    const char* code;
};

// Реализация в lua_scripts.hpp
inline void RegisterAllScripts(std::vector<LuaScriptEntry>& out);

inline void LoadAllLuaScripts() {
    if (!LuaBridge::g_L) {
        LogErr("[LUA] Cannot load scripts: lua_State is null");
        return;
    }

    std::vector<LuaScriptEntry> scripts;
    RegisterAllScripts(scripts);

    for (const auto& script : scripts) {
        Log("[LUA] Loading script: %s", script.name);

        if (!LuaBridge::RunLua(script.code)) {
            LogErr("[LUA] Failed to load script: %s (likely syntax error in Lua)", script.name);
        }
    }
}