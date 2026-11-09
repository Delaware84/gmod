#pragma once
#include <windows.h>
#include <cstdint>
#include <cstddef>
#include <string_view>

bool IsReadable(const void* ptr, size_t size);
bool IsExecutable(const void* ptr);

void* FindPattern(const char* moduleName, std::string_view signature);
void* ResolveRipRelative(void* instruction);

template <typename T>
inline T VMT_HookRaw(void** vmt, void* hook, int index) {
    if (!vmt || index < 0) return nullptr;

    void* original = vmt[index];
    DWORD oldProtect = 0;
    if (!VirtualProtect(&vmt[index], sizeof(void*), PAGE_EXECUTE_READWRITE, &oldProtect))
        return nullptr;

    vmt[index] = hook;
    VirtualProtect(&vmt[index], sizeof(void*), oldProtect, &oldProtect);
    FlushInstructionCache(GetCurrentProcess(), &vmt[index], sizeof(void*));
    return reinterpret_cast<T>(original);
}

template <typename T>
inline T VMT_HookObject(void* object, void* hook, int index) {
    if (!object) return nullptr;
    return VMT_HookRaw<T>(*reinterpret_cast<void***>(object), hook, index);
}

inline void** GetVmt(void* object) {
    return object ? *reinterpret_cast<void***>(object) : nullptr;
}
