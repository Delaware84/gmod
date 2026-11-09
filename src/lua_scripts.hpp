#pragma once
#include "lua_loader.hpp"
#include "lua_esp.hpp"
#include "lua_norecoil.hpp" // Добавили

inline void RegisterAllScripts(std::vector<LuaScriptEntry>& out) {
    out.push_back({ "esp", kEspScript });
    out.push_back({ "norecoil", kNoRecoilScript }); // Добавили
}