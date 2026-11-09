// The bundled ImGui in GMod-SDK-main is slightly modified: it declares a few
// menu-only helpers that reference the original cheat's globals. The ESP only
// uses core draw functions, so provide inert definitions instead of pulling in
// the whole menu subsystem.
#include "imgui.h"

ImFont* boldMenuFont = nullptr;
ImFont* menuFont = nullptr;

enum ButtonCode_t {
    BUTTON_CODE_INVALID = -1
};

ButtonCode_t VKToButtonCode(int) {
    return BUTTON_CODE_INVALID;
}
