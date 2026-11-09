#pragma once
#include <windows.h>
#include <cstring>
#include <cstdio>
#include <cmath>
#include "logger.hpp"
#include "globals.hpp"
#include "Memory.h"
#include "sdk.hpp"

inline int GetLocalPlayerIndex() {
    if (!g_pEngine) return -1;
    void** vmt = GetVmt(g_pEngine);
    if (!vmt || !IsExecutable(vmt[12])) return -1;
    using Fn = int(__fastcall*)(void*);
    return reinterpret_cast<Fn>(vmt[12])(g_pEngine);
}

inline void* GetClientEntity(int index) {
    if (!g_pEntityList || index < 0) return nullptr;
    void** vmt = GetVmt(g_pEntityList);
    if (!vmt || !IsExecutable(vmt[3])) return nullptr;
    using Fn = void* (__fastcall*)(void*, int);
    return reinterpret_cast<Fn>(vmt[3])(g_pEntityList, index);
}

inline void* GetLocalPlayer() {
    int index = GetLocalPlayerIndex();
    if (index <= 0) return nullptr;
    return GetClientEntity(index);
}

template <typename T>
inline T ReadNetvar(const void* base, size_t offset) {
    T value{};
    if (!base || !IsReadable(static_cast<const uint8_t*>(base) + offset, sizeof(T)))
        return value;
    std::memcpy(&value, static_cast<const uint8_t*>(base) + offset, sizeof(T));
    return value;
}

template <typename T>
inline T ReadNetvarFast(const void* base, size_t offset) {
    T value{};
    if (!base) return value;
    std::memcpy(&value, static_cast<const uint8_t*>(base) + offset, sizeof(T));
    return value;
}

template <typename T>
inline bool WriteNetvar(void* base, size_t offset, const T& value) {
    if (!base) return false;
    auto* addr = static_cast<uint8_t*>(base) + offset;
    if (!IsReadable(addr, sizeof(T))) return false;
    DWORD oldProtect = 0;
    if (!VirtualProtect(addr, sizeof(T), PAGE_READWRITE, &oldProtect))
        return false;
    std::memcpy(addr, &value, sizeof(T));
    VirtualProtect(addr, sizeof(T), oldProtect, &oldProtect);
    return true;
}

// A real player entity in GMod x64 client:
//   m_iHealth (0xD8) in 1..1000
//   m_lifeState (0xD7) not 1/2
//   m_iTeamNum (0xE4) in 0..4
//   m_vecViewOffset.z (0x144+8) in 20..90 (props have 0 or garbage)
//   m_angEyeAngles (0x35D8) finite
inline bool IsPlayerEntity(void* entity) {
    if (!entity) return false;
    if (!IsReadable(static_cast<const uint8_t*>(entity) + 0xD7, 1)) return false;
    if (!IsReadable(static_cast<const uint8_t*>(entity) + 0xD8, 4)) return false;
    if (!IsReadable(static_cast<const uint8_t*>(entity) + 0xE4, 4)) return false;
    if (!IsReadable(static_cast<const uint8_t*>(entity) + 0x144, 12)) return false;
    if (!IsReadable(static_cast<const uint8_t*>(entity) + 0x35D8, 12)) return false;

    int health = ReadNetvarFast<int>(entity, 0xD8);
    if (health < 1 || health > 1000) return false;

    uint8_t life = ReadNetvarFast<uint8_t>(entity, 0xD7);
    if (life == 1 || life == 2) return false;

    int team = ReadNetvarFast<int>(entity, 0xE4);
    if (team < -1) return false;   // �������� �����, �� ������� ����� ������� team

    SDK::Vector3D viewOff = ReadNetvarFast<SDK::Vector3D>(entity, 0x144);
    if (!std::isfinite(viewOff.z)) return false;
    if (viewOff.z < 1.0f || viewOff.z > 120.0f) return false;

    SDK::QAngle eye = ReadNetvarFast<SDK::QAngle>(entity, 0x35D8);
    if (!std::isfinite(eye.pitch) || !std::isfinite(eye.yaw)) return false;

    return true;
}

inline int GetFlags(void* local) {
    return local ? ReadNetvar<int>(local, 0x450) : 0;
}

inline bool IsOnGround(void* local) {
    return (GetFlags(local) & 1) != 0;
}

inline bool IsOnGround() {
    return IsOnGround(GetLocalPlayer());
}

inline void LogHexDump(const char* label, const void* data, size_t size) {
    if (!data || !IsReadable(data, size)) {
        LogWarn("%s: pointer %p not readable for 0x%X bytes", label, data, (unsigned)size);
        return;
    }
    const auto* bytes = static_cast<const uint8_t*>(data);
    char line[320];
    for (size_t offset = 0; offset < size; offset += 16) {
        int n = sprintf_s(line, sizeof(line), "%s +0x%03X:", label, (unsigned)offset);
        if (n < 0) continue;
        for (size_t j = 0; j < 16 && offset + j < size; ++j) {
            int w = sprintf_s(line + n, sizeof(line) - n, " %02X", bytes[offset + j]);
            if (w < 0) break;
            n += w;
        }
        Log("%s", line);
    }
}