#pragma once
#include <windows.h>
#include <cstdio>
#include <string>
#include <fstream>
#include <sstream>
#include "logger.hpp"

struct Config {
    bool bhop = false;

    bool watermark = false;
    bool thirdperson = false;
    bool verboseLog = false;
    bool logUserCmd = true;

    bool esp = true;
    bool espBox = true;
    bool espName = true;
    bool espHealth = true;
    bool espDistance = true;
    bool espTeamCheck = false;
    bool espUseLua = false;

    int    espBoxStyle = 1;
    float  espBoxThickness = 1.5f;
    float  espBoxWidthScale = 0.5f;
    bool   espSkeleton = false;
    bool   espLines = false;
    bool   espVisibleCheck = false;
    float  espDistanceMax = 5000.0f;
    int    espTeamFilter = 0;
    bool   espShowStatus = true;
    bool   espShowRole = false;

    float espVisibleColor[4] = { 0.2f, 1.0f, 0.2f, 1.0f };
    float espInvisibleColor[4] = { 1.0f, 0.2f, 0.2f, 1.0f };
    float espSnaplineColor[4] = { 1.0f, 1.0f, 0.2f, 1.0f };
    float espSkeletonColor[4] = { 1.0f, 1.0f, 1.0f, 1.0f };
    float espFillColor[4] = { 1.0f, 0.2f, 0.2f, 0.15f };
    float espTeammateColor[4] = { 0.2f, 0.4f, 1.0f, 1.0f };
    float espTraitorAllyColor[4] = { 1.0f, 0.6f, 0.0f, 1.0f };
    float espTraitorEnemyColor[4] = { 1.0f, 0.1f, 0.1f, 1.0f };

    bool norecoilEnabled = false;
    bool norecoilPunch = true;
    bool norecoilSpread = true;
    bool norecoilSpray = true;

    bool  aimbotEnabled = false;
    bool  aimbotOnRMB = false;         // NEW: hold RMB (IN_ATTACK2) to aim
    bool  aimbotAutoFire = false;
    bool  aimbotVisibleCheck = true;
    bool  aimbotVelocityComp = true;
    bool  aimbotPingComp = true;
    int   aimbotTarget = 0;
    int   aimbotSmooth = 8;
    float aimbotFov = 15.0f;
    float aimbotPing = 60.0f;
    float aimbotInterp = 0.1f;

    void Load();
    void Save() const;
    void Dump() const;
};

inline Config g_Config;

inline constexpr const char* kConfigDir = "C:\\Users\\Kompukter\\Desktop\\gmod_cheat";
inline constexpr const char* kConfigPath = "C:\\Users\\Kompukter\\Desktop\\gmod_cheat\\config.ini";

inline bool ParseBool(const std::string& value, bool fallback) {
    if (value == "1" || value == "true" || value == "yes" || value == "on") return true;
    if (value == "0" || value == "false" || value == "no" || value == "off") return false;
    return fallback;
}

inline int ParseInt(const std::string& value, int fallback) {
    try { return std::stoi(value); }
    catch (...) { return fallback; }
}

inline float ParseFloat(const std::string& value, float fallback) {
    try { return std::stof(value); }
    catch (...) { return fallback; }
}

inline void Config::Load() {
    CreateDirectoryA(kConfigDir, nullptr);
    std::ifstream file(kConfigPath);
    if (!file.is_open()) {
        LogWarn("[CONFIG] %s not found, writing defaults", kConfigPath);
        Save();
        return;
    }
    std::string line;
    while (std::getline(file, line)) {
        if (line.empty() || line[0] == '#') continue;
        size_t eq = line.find('=');
        if (eq == std::string::npos) continue;
        std::string key = line.substr(0, eq);
        std::string value = line.substr(eq + 1);
        auto trim = [](std::string& s) {
            while (!s.empty() && (s.front() == ' ' || s.front() == '\t' || s.front() == '\r')) s.erase(s.begin());
            while (!s.empty() && (s.back() == ' ' || s.back() == '\t' || s.back() == '\r')) s.pop_back();
            };
        trim(key);
        trim(value);

        if (key == "bhop")                  bhop = ParseBool(value, bhop);
        else if (key == "watermark")        watermark = ParseBool(value, watermark);
        else if (key == "thirdperson")      thirdperson = ParseBool(value, thirdperson);
        else if (key == "verboseLog")       verboseLog = ParseBool(value, verboseLog);
        else if (key == "logUserCmd")       logUserCmd = ParseBool(value, logUserCmd);

        else if (key == "esp")              esp = ParseBool(value, esp);
        else if (key == "esp_use_lua")      espUseLua = ParseBool(value, espUseLua);
        else if (key == "esp_box")          espBox = ParseBool(value, espBox);
        else if (key == "esp_name")         espName = ParseBool(value, espName);
        else if (key == "esp_health")       espHealth = ParseBool(value, espHealth);
        else if (key == "esp_distance")     espDistance = ParseBool(value, espDistance);
        else if (key == "esp_team_check")   espTeamCheck = ParseBool(value, espTeamCheck);

        else if (key == "esp_box_style")    espBoxStyle = ParseInt(value, espBoxStyle);
        else if (key == "esp_box_thickness")espBoxThickness = ParseFloat(value, espBoxThickness);
        else if (key == "esp_box_width")    espBoxWidthScale = ParseFloat(value, espBoxWidthScale);
        else if (key == "esp_skeleton")     espSkeleton = ParseBool(value, espSkeleton);
        else if (key == "esp_lines")        espLines = ParseBool(value, espLines);
        else if (key == "esp_visible_check")espVisibleCheck = ParseBool(value, espVisibleCheck);
        else if (key == "esp_distance_max") espDistanceMax = ParseFloat(value, espDistanceMax);
        else if (key == "esp_team_filter")  espTeamFilter = ParseInt(value, espTeamFilter);
        else if (key == "esp_show_status")  espShowStatus = ParseBool(value, espShowStatus);
        else if (key == "esp_show_role")    espShowRole = ParseBool(value, espShowRole);

        else if (key == "norecoil")         norecoilEnabled = ParseBool(value, norecoilEnabled);
        else if (key == "norecoil_punch")   norecoilPunch = ParseBool(value, norecoilPunch);
        else if (key == "norecoil_spread")  norecoilSpread = ParseBool(value, norecoilSpread);
        else if (key == "norecoil_spray")   norecoilSpray = ParseBool(value, norecoilSpray);

        else if (key == "aimbot")           aimbotEnabled = ParseBool(value, aimbotEnabled);
        else if (key == "aimbot_on_rmb")    aimbotOnRMB = ParseBool(value, aimbotOnRMB);
        else if (key == "aimbot_autofire")  aimbotAutoFire = ParseBool(value, aimbotAutoFire);
        else if (key == "aimbot_visible")   aimbotVisibleCheck = ParseBool(value, aimbotVisibleCheck);
        else if (key == "aimbot_velcomp")   aimbotVelocityComp = ParseBool(value, aimbotVelocityComp);
        else if (key == "aimbot_pingcomp")  aimbotPingComp = ParseBool(value, aimbotPingComp);
        else if (key == "aimbot_target")    aimbotTarget = ParseInt(value, aimbotTarget);
        else if (key == "aimbot_smooth")    aimbotSmooth = ParseInt(value, aimbotSmooth);
        else if (key == "aimbot_fov")       aimbotFov = ParseFloat(value, aimbotFov);
        else if (key == "aimbot_ping")      aimbotPing = ParseFloat(value, aimbotPing);
        else if (key == "aimbot_interp")    aimbotInterp = ParseFloat(value, aimbotInterp);
    }
    Log("[CONFIG] loaded from %s", kConfigPath);
}

inline void Config::Save() const {
    CreateDirectoryA(kConfigDir, nullptr);
    std::ofstream file(kConfigPath, std::ios::trunc);
    if (!file.is_open()) {
        LogErr("[CONFIG] failed to write %s", kConfigPath);
        return;
    }
    file << "# gmod_cheat config\n";
    file << "bhop=" << (bhop ? 1 : 0) << "\n";
    file << "watermark=" << (watermark ? 1 : 0) << "\n";
    file << "thirdperson=" << (thirdperson ? 1 : 0) << "\n";
    file << "verboseLog=" << (verboseLog ? 1 : 0) << "\n";
    file << "logUserCmd=" << (logUserCmd ? 1 : 0) << "\n";

    file << "esp=" << (esp ? 1 : 0) << "\n";
    file << "esp_use_lua=" << (espUseLua ? 1 : 0) << "\n";
    file << "esp_box=" << (espBox ? 1 : 0) << "\n";
    file << "esp_name=" << (espName ? 1 : 0) << "\n";
    file << "esp_health=" << (espHealth ? 1 : 0) << "\n";
    file << "esp_distance=" << (espDistance ? 1 : 0) << "\n";
    file << "esp_team_check=" << (espTeamCheck ? 1 : 0) << "\n";

    file << "esp_box_style=" << espBoxStyle << "\n";
    file << "esp_box_thickness=" << espBoxThickness << "\n";
    file << "esp_box_width=" << espBoxWidthScale << "\n";
    file << "esp_skeleton=" << (espSkeleton ? 1 : 0) << "\n";
    file << "esp_lines=" << (espLines ? 1 : 0) << "\n";
    file << "esp_visible_check=" << (espVisibleCheck ? 1 : 0) << "\n";
    file << "esp_distance_max=" << espDistanceMax << "\n";
    file << "esp_team_filter=" << espTeamFilter << "\n";
    file << "esp_show_status=" << (espShowStatus ? 1 : 0) << "\n";
    file << "esp_show_role=" << (espShowRole ? 1 : 0) << "\n";

    file << "norecoil=" << (norecoilEnabled ? 1 : 0) << "\n";
    file << "norecoil_punch=" << (norecoilPunch ? 1 : 0) << "\n";
    file << "norecoil_spread=" << (norecoilSpread ? 1 : 0) << "\n";
    file << "norecoil_spray=" << (norecoilSpray ? 1 : 0) << "\n";

    file << "aimbot=" << (aimbotEnabled ? 1 : 0) << "\n";
    file << "aimbot_on_rmb=" << (aimbotOnRMB ? 1 : 0) << "\n";
    file << "aimbot_autofire=" << (aimbotAutoFire ? 1 : 0) << "\n";
    file << "aimbot_visible=" << (aimbotVisibleCheck ? 1 : 0) << "\n";
    file << "aimbot_velcomp=" << (aimbotVelocityComp ? 1 : 0) << "\n";
    file << "aimbot_pingcomp=" << (aimbotPingComp ? 1 : 0) << "\n";
    file << "aimbot_target=" << aimbotTarget << "\n";
    file << "aimbot_smooth=" << aimbotSmooth << "\n";
    file << "aimbot_fov=" << aimbotFov << "\n";
    file << "aimbot_ping=" << aimbotPing << "\n";
    file << "aimbot_interp=" << aimbotInterp << "\n";
    Log("[CONFIG] saved to %s", kConfigPath);
}

inline void Config::Dump() const {
    Log("[CONFIG] bhop=%d watermark=%d esp=%d box=%d name=%d health=%d dist=%d team=%d "
        "style=%d thick=%.2f width=%.2f skel=%d lines=%d vis=%d dmax=%.0f tfilter=%d status=%d role=%d "
        "norecoil=%d aimbot=%d rmb=%d fov=%.1f smooth=%d target=%d autofire=%d",
        bhop, watermark, esp, espBox, espName, espHealth, espDistance, espTeamCheck,
        espBoxStyle, espBoxThickness, espBoxWidthScale, espSkeleton, espLines,
        espVisibleCheck, espDistanceMax, espTeamFilter, espShowStatus, espShowRole,
        norecoilEnabled, aimbotEnabled, aimbotOnRMB, aimbotFov, aimbotSmooth, aimbotTarget, aimbotAutoFire);
}