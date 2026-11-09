#pragma once
#include <cstdint>
#include <cstddef>
#include <atomic>

namespace SDK {

struct Vector3D { float x, y, z; };
struct QAngle   { float pitch, yaw, roll; };

// GMod x64 CUserCmd.
// Layout confirmed by cheat_log.txt hex dump of ClientMode::CreateMove's cmd:
//   0x00 command_number, 0x04 tick_count, 0x08 viewangles,
//   0x14 forwardmove, 0x18 sidemove, 0x1C upmove, 0x20 buttons, ...
// The old header had a virtual destructor, which added a vptr and shifted
// every field by +8. GMod's CUserCmd has no vptr.
struct CUserCmd {
    int      command_number;   // 0x00
    int      tick_count;       // 0x04
    QAngle   viewangles;       // 0x08
    float    forwardmove;      // 0x14
    float    sidemove;         // 0x18
    float    upmove;           // 0x1C
    int      buttons;          // 0x20
    uint8_t  impulse;          // 0x24
    uint8_t  pad0[3];          // 0x25
    int      weaponselect;     // 0x28
    int      weaponsubtype;    // 0x2C
    int      random_seed;      // 0x30
    int16_t  mousedx;          // 0x34
    int16_t  mousedy;          // 0x36
    bool     hasbeenpredicted; // 0x38
    uint8_t  pad1[3];          // 0x39
    // GMod-specific tail follows (buttons_pressed, world click, etc.).
};

static_assert(offsetof(CUserCmd, command_number)   == 0x00);
static_assert(offsetof(CUserCmd, tick_count)       == 0x04);
static_assert(offsetof(CUserCmd, viewangles)       == 0x08);
static_assert(offsetof(CUserCmd, forwardmove)      == 0x14);
static_assert(offsetof(CUserCmd, sidemove)         == 0x18);
static_assert(offsetof(CUserCmd, upmove)           == 0x1C);
static_assert(offsetof(CUserCmd, buttons)          == 0x20);
static_assert(offsetof(CUserCmd, impulse)          == 0x24);
static_assert(offsetof(CUserCmd, weaponselect)     == 0x28);
static_assert(offsetof(CUserCmd, weaponsubtype)    == 0x2C);
static_assert(offsetof(CUserCmd, random_seed)      == 0x30);
static_assert(offsetof(CUserCmd, mousedx)          == 0x34);
static_assert(offsetof(CUserCmd, mousedy)          == 0x36);
static_assert(offsetof(CUserCmd, hasbeenpredicted) == 0x38);

// GetUserCmd may return a shifted view. The base is detected at runtime by
// comparing command_number against the requested sequence number.
inline std::atomic<int>  g_userCmdShift{0};
inline std::atomic<bool> g_userCmdShiftDetected{false};

inline CUserCmd* CmdAt(CUserCmd* raw) {
    if (!raw) return nullptr;
    return reinterpret_cast<CUserCmd*>(
        reinterpret_cast<uint8_t*>(raw) + g_userCmdShift.load(std::memory_order_relaxed));
}

inline const CUserCmd* CmdAt(const CUserCmd* raw) {
    if (!raw) return nullptr;
    return reinterpret_cast<const CUserCmd*>(
        reinterpret_cast<const uint8_t*>(raw) + g_userCmdShift.load(std::memory_order_relaxed));
}

// CInput: only the vtable pointer is used. Full layout is not reconstructed.
struct CInput {
    void* vtable; // 0x00
};

enum : int {
    IN_ATTACK     = (1 << 0),
    IN_JUMP       = (1 << 1),
    IN_DUCK       = (1 << 2),
    IN_FORWARD    = (1 << 3),
    IN_BACK       = (1 << 4),
    IN_USE        = (1 << 5),
    IN_CANCEL     = (1 << 6),
    IN_LEFT       = (1 << 7),
    IN_RIGHT      = (1 << 8),
    IN_MOVELEFT   = (1 << 9),
    IN_MOVERIGHT  = (1 << 10),
    IN_ATTACK2    = (1 << 11),
    IN_RUN        = (1 << 12),
    IN_RELOAD     = (1 << 13),
    IN_ALT1       = (1 << 14),
    IN_ALT2       = (1 << 15),
    IN_SCORE      = (1 << 16),
    IN_SPEED      = (1 << 17),
    IN_WALK       = (1 << 18),
    IN_ZOOM       = (1 << 19),
    IN_WEAPON1    = (1 << 20),
    IN_WEAPON2    = (1 << 21),
    IN_BULLRUSH   = (1 << 22),
    IN_GRENADE1   = (1 << 23),
    IN_GRENADE2   = (1 << 24),
    IN_LOOKSPIN   = (1 << 25),
};

} // namespace SDK
