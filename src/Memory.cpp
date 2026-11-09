#include "Memory.h"

#include <psapi.h>
#include <cstring>
#include <string>
#include <vector>

bool IsReadable(const void* ptr, size_t size) {
    if (!ptr || size == 0) return false;

    uintptr_t start = reinterpret_cast<uintptr_t>(ptr);
    uintptr_t end = start + size;
    if (end < start) return false;

    while (start < end) {
        MEMORY_BASIC_INFORMATION mbi{};
        if (!VirtualQuery(reinterpret_cast<LPCVOID>(start), &mbi, sizeof(mbi)))
            return false;
        if (mbi.State != MEM_COMMIT)
            return false;

        DWORD p = mbi.Protect;
        if (p & (PAGE_NOACCESS | PAGE_GUARD))
            return false;

        const DWORD readable = PAGE_READONLY | PAGE_READWRITE | PAGE_WRITECOPY |
                               PAGE_EXECUTE | PAGE_EXECUTE_READ |
                               PAGE_EXECUTE_READWRITE | PAGE_EXECUTE_WRITECOPY;
        if (!(p & readable))
            return false;

        uintptr_t regionEnd = reinterpret_cast<uintptr_t>(mbi.BaseAddress) + mbi.RegionSize;
        if (regionEnd <= start) return false;
        start = regionEnd;
    }
    return true;
}

bool IsExecutable(const void* ptr) {
    if (!ptr) return false;

    MEMORY_BASIC_INFORMATION mbi{};
    if (!VirtualQuery(ptr, &mbi, sizeof(mbi)))
        return false;
    if (mbi.State != MEM_COMMIT)
        return false;

    DWORD p = mbi.Protect;
    if (p & (PAGE_NOACCESS | PAGE_GUARD))
        return false;

    return (p & (PAGE_EXECUTE | PAGE_EXECUTE_READ |
                 PAGE_EXECUTE_READWRITE | PAGE_EXECUTE_WRITECOPY)) != 0;
}

static bool ParsePattern(std::string_view text, std::vector<int>& out) {
    out.clear();

    for (size_t i = 0; i < text.size();) {
        while (i < text.size() && (text[i] == ' ' || text[i] == '\t')) ++i;
        if (i >= text.size()) break;

        if (text[i] == '?') {
            while (i < text.size() && text[i] == '?') ++i;
            out.push_back(-1);
            continue;
        }

        auto hex = [](char c) -> int {
            if (c >= '0' && c <= '9') return c - '0';
            if (c >= 'a' && c <= 'f') return c - 'a' + 10;
            if (c >= 'A' && c <= 'F') return c - 'A' + 10;
            return -1;
        };

        if (i + 1 >= text.size()) return false;
        int hi = hex(text[i]);
        int lo = hex(text[i + 1]);
        if (hi < 0 || lo < 0) return false;
        out.push_back((hi << 4) | lo);
        i += 2;
    }

    return !out.empty();
}

void* FindPattern(const char* moduleName, std::string_view signature) {
    HMODULE module = GetModuleHandleA(moduleName);
    if (!module) return nullptr;

    MODULEINFO info{};
    if (!GetModuleInformation(GetCurrentProcess(), module, &info, sizeof(info)))
        return nullptr;

    std::vector<int> pattern;
    if (!ParsePattern(signature, pattern))
        return nullptr;

    const uint8_t* base = static_cast<const uint8_t*>(info.lpBaseOfDll);
    const size_t size = info.SizeOfImage;
    const size_t count = pattern.size();
    if (size < count) return nullptr;

    for (size_t i = 0; i <= size - count; ++i) {
        bool match = true;
        for (size_t j = 0; j < count; ++j) {
            if (pattern[j] >= 0 && base[i + j] != static_cast<uint8_t>(pattern[j])) {
                match = false;
                break;
            }
        }
        if (match) return const_cast<uint8_t*>(base + i);
    }
    return nullptr;
}

void* ResolveRipRelative(void* instruction) {
    if (!instruction || !IsReadable(instruction, 7))
        return nullptr;

    auto* p = static_cast<uint8_t*>(instruction);
    int32_t disp = 0;
    std::memcpy(&disp, p + 3, sizeof(disp));
    return p + 7 + disp;
}
