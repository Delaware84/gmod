#pragma once
#include <atomic>
#include <cstdint>
#include "../sdk/usercmd.hpp"

// IN_JUMP = (1 << 1) = 2, FL_ONGROUND = 1.
inline constexpr int kBhopJumpButton   = SDK::IN_JUMP;
inline constexpr int kBhopOnGroundFlag = 1;

// Number of IN_JUMP presses removed by the bhop extension point.
inline std::atomic<uint64_t> g_bhopCounter{0};
