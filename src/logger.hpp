#pragma once
#include <windows.h>
#include <cstdio>
#include <cstdarg>
#include <mutex>

enum class LogLevel { Info, Warn, Error, Debug };

inline std::mutex g_logMutex;
inline char g_logPath[MAX_PATH] = {};

inline const char* LogPath() {
    return g_logPath;
}

inline void LogInit() {
    std::lock_guard<std::mutex> lock(g_logMutex);

    const char* dir = "C:\\Users\\Kompukter\\Desktop\\gmod_cheat";
    CreateDirectoryA(dir, nullptr);

    sprintf_s(g_logPath, "%s\\cheat_log.txt", dir);

    FILE* f = nullptr;
    fopen_s(&f, g_logPath, "w");
    if (!f) {
        char tempPath[MAX_PATH] = {};
        DWORD n = GetTempPathA(MAX_PATH, tempPath);
        if (n > 0 && n < MAX_PATH) {
            sprintf_s(g_logPath, "%sgmod_cheat_log.txt", tempPath);
            fopen_s(&f, g_logPath, "w");
        }
    }

    if (f) {
        SYSTEMTIME st{};
        GetLocalTime(&st);
        fprintf(f, "[%02d:%02d:%02d] === session start === path=%s ===\n",
                st.wHour, st.wMinute, st.wSecond, g_logPath);
        fclose(f);
    }
}

inline void LogV(LogLevel level, const char* fmt, va_list args) {
    std::lock_guard<std::mutex> lock(g_logMutex);
    if (!g_logPath[0]) return;

    FILE* f = nullptr;
    fopen_s(&f, g_logPath, "a");
    if (!f) return;

    const char* tag = "INFO";
    switch (level) {
        case LogLevel::Warn:  tag = "WARN"; break;
        case LogLevel::Error: tag = "ERR "; break;
        case LogLevel::Debug: tag = "DBG "; break;
        default: break;
    }

    SYSTEMTIME st{};
    GetLocalTime(&st);
    fprintf(f, "[%02d:%02d:%02d.%03d] [%s] ",
            st.wHour, st.wMinute, st.wSecond, st.wMilliseconds, tag);

    vfprintf(f, fmt, args);
    fprintf(f, "\n");
    fclose(f);
}

inline void Log(const char* fmt, ...) {
    va_list args;
    va_start(args, fmt);
    LogV(LogLevel::Info, fmt, args);
    va_end(args);
}

inline void LogWarn(const char* fmt, ...) {
    va_list args;
    va_start(args, fmt);
    LogV(LogLevel::Warn, fmt, args);
    va_end(args);
}

inline void LogErr(const char* fmt, ...) {
    va_list args;
    va_start(args, fmt);
    LogV(LogLevel::Error, fmt, args);
    va_end(args);
}

inline void LogDebug(const char* fmt, ...) {
    va_list args;
    va_start(args, fmt);
    LogV(LogLevel::Debug, fmt, args);
    va_end(args);
}
