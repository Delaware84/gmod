#include "overlay.hpp"

#include <windows.h>
#include <psapi.h>
#include <d3d9.h>
#include <d3d11.h>
#include <dxgi.h>
#include <atomic>
#include <cstring>
#include <unordered_map>
#include <vector>

#include "logger.hpp"
#include "config.hpp"
#include "globals.hpp"
#include "esp.hpp"
#include "Memory.h"
#include "third_party/imgui/imgui.h"
#include "third_party/imgui/imgui_impl_dx9.h"
#include "third_party/imgui/imgui_impl_dx11.h"
#include "third_party/imgui/imgui_impl_win32.h"
#include "lua_bridge.hpp"
#include "lua_scripts.hpp"

extern IMGUI_IMPL_API LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

namespace {

    enum class Api { None, DX9, DX11 };
    enum class RenderApi { None, DX9, DX11 };

    using PresentDX9Fn = HRESULT(__stdcall*)(IDirect3DDevice9*, const RECT*, const RECT*, HWND, const RGNDATA*);
    using PresentDX11Fn = HRESULT(__stdcall*)(IDXGISwapChain*, UINT, UINT);

    HRESULT __stdcall hkPresent9(IDirect3DDevice9* device, const RECT* sourceRect,
        const RECT* destRect, HWND destWindow, const RGNDATA* dirtyRegion);
    HRESULT __stdcall hkPresent11(IDXGISwapChain* swapChain, UINT syncInterval, UINT flags);

    Api g_api = Api::None;
    RenderApi g_renderApi = RenderApi::None;

    HWND g_hiddenWindow = nullptr;
    HWND g_gameWindow = nullptr;
    bool g_windowClassRegistered = false;

    // ---------------------------------------------------------------- DX9 state
    IDirect3D9Ex* g_d3d9 = nullptr;
    IDirect3DDevice9Ex* g_dummyDevice9Ex = nullptr;
    IDirect3DDevice9* g_dummyDevice9 = nullptr;
    void** g_dummyVmt9Ex = nullptr;
    void** g_dummyVmt9 = nullptr;

    struct D3D9Signature {
        void* beginScene = nullptr;
        void* clear = nullptr;
        void* setTransform = nullptr;
        void* getTransform = nullptr;
    };

    D3D9Signature g_signatures9[2];
    int g_signatureCount9 = 0;

    uintptr_t g_d3d9Base = 0;
    uintptr_t g_d3d9End = 0;
    uintptr_t g_overlayBase = 0;
    uintptr_t g_overlayEnd = 0;

    inline bool InD3D9Code(const void* ptr) {
        uintptr_t value = reinterpret_cast<uintptr_t>(ptr);
        return value >= g_d3d9Base && value < g_d3d9End;
    }

    inline bool InOverlayCode(const void* ptr) {
        uintptr_t value = reinterpret_cast<uintptr_t>(ptr);
        return g_overlayBase != 0 && value >= g_overlayBase && value < g_overlayEnd;
    }

    std::unordered_map<void*, PresentDX9Fn> g_present9Originals;
    PresentDX9Fn g_fallbackPresent9 = nullptr;
    IDirect3DDevice9* g_gameDevice9 = nullptr;
    int g_dx9VtableCount = 0;

    bool g_device9IsGame = false;
    IDirect3DDevice9* g_cachedDevice9 = nullptr;

    // ---------------------------------------------------------------- DX11 state
    IDXGISwapChain* g_dummySwapChain = nullptr;
    ID3D11Device* g_dummyDevice11 = nullptr;
    ID3D11DeviceContext* g_dummyContext11 = nullptr;
    ID3D11Device* g_device11 = nullptr;
    ID3D11DeviceContext* g_context11 = nullptr;
    IDXGISwapChain* g_gameSwapChain11 = nullptr;
    PresentDX11Fn g_oPresent11 = nullptr;

    // ---------------------------------------------------------------- ImGui / menu
    bool g_imguiContext = false;
    bool g_backendReady = false;
    bool g_firstFrameLogged = false;
    uint64_t g_frameCount = 0;
    ULONGLONG g_lastFrameTick = 0;

    std::atomic<bool> g_menuOpen{ false };
    WNDPROC g_originalWndProc = nullptr;
    HWND g_wndProcWindow = nullptr;

    LRESULT CALLBACK HiddenWindowProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
        return DefWindowProcA(hwnd, msg, wParam, lParam);
    }

    LRESULT CALLBACK GameWndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
        if (msg == WM_KEYDOWN && wParam == VK_INSERT) {
            bool open = !g_menuOpen.load(std::memory_order_relaxed);
            g_menuOpen.store(open, std::memory_order_relaxed);
            if (open) {
                if (g_gameWindow) ReleaseCapture();
                ClipCursor(nullptr);
            }
            else {
                if (g_gameWindow) SetCapture(g_gameWindow);
            }
            return 1;
        }

        if (msg == WM_KEYDOWN && wParam == VK_F9) {
            LoadAllLuaScripts();
            return 1;
        }

        if (g_menuOpen.load(std::memory_order_relaxed)) {
            ImGui_ImplWin32_WndProcHandler(hwnd, msg, wParam, lParam);

            if (msg == WM_KEYDOWN || msg == WM_KEYUP ||
                msg == WM_SYSKEYDOWN || msg == WM_SYSKEYUP ||
                msg == WM_LBUTTONDOWN || msg == WM_LBUTTONUP ||
                msg == WM_RBUTTONDOWN || msg == WM_RBUTTONUP ||
                msg == WM_MBUTTONDOWN || msg == WM_MBUTTONUP ||
                msg == WM_MOUSEWHEEL || msg == WM_CHAR ||
                msg == WM_MOUSEMOVE || msg == WM_INPUT)
                return 1;
        }

        return CallWindowProcA(g_originalWndProc, hwnd, msg, wParam, lParam);
    }

    bool EnsureHiddenWindow() {
        if (g_hiddenWindow) return true;

        HMODULE instance = GetModuleHandleA(nullptr);
        const char* className = "gmodcheat_overlay_hidden";

        if (!g_windowClassRegistered) {
            WNDCLASSEXA wc{};
            wc.cbSize = sizeof(wc);
            wc.lpfnWndProc = HiddenWindowProc;
            wc.hInstance = instance;
            wc.lpszClassName = className;
            if (!RegisterClassExA(&wc) && GetLastError() != ERROR_CLASS_ALREADY_EXISTS) {
                LogErr("[OVERLAY] RegisterClassExA failed (%lu)", GetLastError());
                return false;
            }
            g_windowClassRegistered = true;
        }

        g_hiddenWindow = CreateWindowExA(0, className, "gmodcheat_overlay", WS_POPUP,
            0, 0, 1, 1, nullptr, nullptr, instance, nullptr);
        if (!g_hiddenWindow) {
            LogErr("[OVERLAY] CreateWindowExA failed (%lu)", GetLastError());
            return false;
        }
        return true;
    }

    BOOL CALLBACK FindGameWindowProc(HWND hwnd, LPARAM param) {
        DWORD pid = 0;
        GetWindowThreadProcessId(hwnd, &pid);
        if (pid != GetCurrentProcessId()) return TRUE;
        if (hwnd == g_hiddenWindow) return TRUE;
        if (!IsWindowVisible(hwnd)) return TRUE;
        if (GetWindow(hwnd, GW_OWNER) != nullptr) return TRUE;

        RECT rect{};
        if (!GetClientRect(hwnd, &rect)) return TRUE;
        if (rect.right < 16 || rect.bottom < 16) return TRUE;

        *reinterpret_cast<HWND*>(param) = hwnd;
        return FALSE;
    }

    HWND GetGameWindow() {
        if (g_gameWindow && IsWindow(g_gameWindow)) return g_gameWindow;

        HWND found = FindWindowA("Valve001", nullptr);
        if (!found)
            EnumWindows(FindGameWindowProc, reinterpret_cast<LPARAM>(&found));

        if (!found) {
            found = GetForegroundWindow();
            DWORD pid;
            GetWindowThreadProcessId(found, &pid);
            if (pid != GetCurrentProcessId()) found = nullptr;
        }

        if (found) {
            g_gameWindow = found;
            Log("[OVERLAY] game window = %p", found);
        }
        return found;
    }

    bool IsGameDevice9(IDirect3DDevice9* device) {
        if (!device) return false;

        IDirect3DSwapChain9* chain = nullptr;
        if (FAILED(device->GetSwapChain(0, &chain)) || !chain)
            return true;

        D3DPRESENT_PARAMETERS pp{};
        HRESULT hr = chain->GetPresentParameters(&pp);
        chain->Release();
        if (FAILED(hr)) return true;

        HWND game = GetGameWindow();
        if (!game) return true;
        return pp.hDeviceWindow == game;
    }

    bool EnsureImGuiContext() {
        if (g_imguiContext) return true;

        IMGUI_CHECKVERSION();
        ImGui::CreateContext();

        ImGuiIO& io = ImGui::GetIO();
        io.IniFilename = nullptr;
        io.LogFilename = nullptr;
        io.DisplaySize = ImVec2(1920.0f, 1080.0f);
        io.DeltaTime = 1.0f / 60.0f;
        io.ConfigFlags = 0;

        g_imguiContext = true;
        return true;
    }

    void InstallWndProcHook(HWND gameWindow) {
        if (!gameWindow || g_wndProcWindow == gameWindow) return;

        if (g_wndProcWindow && g_originalWndProc) {
            SetWindowLongPtrA(g_wndProcWindow, GWLP_WNDPROC,
                reinterpret_cast<LONG_PTR>(g_originalWndProc));
        }

        g_originalWndProc = reinterpret_cast<WNDPROC>(
            SetWindowLongPtrA(gameWindow, GWLP_WNDPROC,
                reinterpret_cast<LONG_PTR>(GameWndProc)));
        g_wndProcWindow = gameWindow;
        Log("[OVERLAY] WndProc hooked on %p", gameWindow);
    }

    void RemoveWndProcHook() {
        if (g_wndProcWindow && g_originalWndProc) {
            SetWindowLongPtrA(g_wndProcWindow, GWLP_WNDPROC,
                reinterpret_cast<LONG_PTR>(g_originalWndProc));
            Log("[OVERLAY] WndProc hook removed");
        }
        g_wndProcWindow = nullptr;
        g_originalWndProc = nullptr;
    }

    bool InitImGuiDX9(IDirect3DDevice9* device) {
        if (g_backendReady) return g_renderApi == RenderApi::DX9;
        if (!device) return false;

        if (!EnsureImGuiContext()) return false;
        if (!ImGui_ImplDX9_Init(device)) {
            LogErr("[OVERLAY] ImGui_ImplDX9_Init failed");
            return false;
        }

        HWND game = GetGameWindow();
        if (game) {
            ImGui_ImplWin32_Init(game);
            InstallWndProcHook(game);
        }
        else {
            LogWarn("[OVERLAY] game window not found; ImGui Win32 backend not initialized");
        }

        g_gameDevice9 = device;
        g_renderApi = RenderApi::DX9;
        g_backendReady = true;
        Log("[OVERLAY] ImGui initialized (DX9) device=%p", device);
        return true;
    }

    bool InitImGuiDX11(IDXGISwapChain* swapChain) {
        if (g_backendReady) return g_renderApi == RenderApi::DX11;
        if (!swapChain) return false;

        ID3D11Device* device = nullptr;
        ID3D11DeviceContext* context = nullptr;
        if (FAILED(swapChain->GetDevice(__uuidof(ID3D11Device), reinterpret_cast<void**>(&device))) || !device) {
            LogErr("[OVERLAY] IDXGISwapChain::GetDevice failed");
            return false;
        }
        device->GetImmediateContext(&context);
        if (!context) {
            device->Release();
            LogErr("[OVERLAY] ID3D11Device::GetImmediateContext failed");
            return false;
        }

        if (!EnsureImGuiContext()) {
            context->Release();
            device->Release();
            return false;
        }
        if (!ImGui_ImplDX11_Init(device, context)) {
            context->Release();
            device->Release();
            LogErr("[OVERLAY] ImGui_ImplDX11_Init failed");
            return false;
        }

        HWND game = GetGameWindow();
        if (game) {
            ImGui_ImplWin32_Init(game);
            InstallWndProcHook(game);
        }

        g_device11 = device;
        g_context11 = context;
        g_gameSwapChain11 = swapChain;
        g_renderApi = RenderApi::DX11;
        g_backendReady = true;
        Log("[OVERLAY] ImGui initialized (DX11) device=%p context=%p", device, context);
        return true;
    }

    void DrawMenu() {
        bool open = g_menuOpen.load(std::memory_order_relaxed);
        if (!open) return;

        static bool styleInitialized = false;
        if (!styleInitialized) {
            ImGuiStyle& style = ImGui::GetStyle();
            style.WindowRounding = 8.0f;
            style.FrameRounding = 4.0f;
            style.PopupRounding = 4.0f;
            style.ScrollbarRounding = 4.0f;
            style.GrabRounding = 4.0f;
            style.TabRounding = 4.0f;

            style.WindowBorderSize = 1.0f;
            style.FrameBorderSize = 0.0f;
            style.PopupBorderSize = 1.0f;

            style.ItemSpacing = ImVec2(8, 6);
            style.ItemInnerSpacing = ImVec2(6, 4);
            style.WindowPadding = ImVec2(12, 12);
            style.FramePadding = ImVec2(6, 4);

            ImVec4* colors = style.Colors;
            colors[ImGuiCol_WindowBg] = ImVec4(0.08f, 0.08f, 0.09f, 0.98f);
            colors[ImGuiCol_ChildBg] = ImVec4(0.10f, 0.10f, 0.11f, 0.50f);
            colors[ImGuiCol_PopupBg] = ImVec4(0.08f, 0.08f, 0.09f, 0.98f);
            colors[ImGuiCol_Border] = ImVec4(0.20f, 0.20f, 0.22f, 0.50f);
            colors[ImGuiCol_FrameBg] = ImVec4(0.12f, 0.12f, 0.14f, 1.00f);
            colors[ImGuiCol_FrameBgHovered] = ImVec4(0.18f, 0.18f, 0.20f, 1.00f);
            colors[ImGuiCol_FrameBgActive] = ImVec4(0.25f, 0.25f, 0.28f, 1.00f);
            colors[ImGuiCol_TitleBg] = ImVec4(0.05f, 0.05f, 0.06f, 1.00f);
            colors[ImGuiCol_TitleBgActive] = ImVec4(0.10f, 0.10f, 0.11f, 1.00f);
            colors[ImGuiCol_MenuBarBg] = ImVec4(0.08f, 0.08f, 0.09f, 1.00f);
            colors[ImGuiCol_ScrollbarBg] = ImVec4(0.05f, 0.05f, 0.06f, 1.00f);
            colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.25f, 0.25f, 0.28f, 1.00f);
            colors[ImGuiCol_CheckMark] = ImVec4(0.80f, 0.15f, 0.15f, 1.00f);
            colors[ImGuiCol_SliderGrab] = ImVec4(0.80f, 0.15f, 0.15f, 1.00f);
            colors[ImGuiCol_SliderGrabActive] = ImVec4(0.90f, 0.20f, 0.20f, 1.00f);
            colors[ImGuiCol_Button] = ImVec4(0.15f, 0.15f, 0.17f, 1.00f);
            colors[ImGuiCol_ButtonHovered] = ImVec4(0.80f, 0.15f, 0.15f, 0.60f);
            colors[ImGuiCol_ButtonActive] = ImVec4(0.80f, 0.15f, 0.15f, 0.80f);
            colors[ImGuiCol_Header] = ImVec4(0.15f, 0.15f, 0.17f, 1.00f);
            colors[ImGuiCol_HeaderHovered] = ImVec4(0.80f, 0.15f, 0.15f, 0.30f);
            colors[ImGuiCol_HeaderActive] = ImVec4(0.80f, 0.15f, 0.15f, 0.50f);
            colors[ImGuiCol_Separator] = ImVec4(0.20f, 0.20f, 0.22f, 0.50f);
            colors[ImGuiCol_Tab] = ImVec4(0.10f, 0.10f, 0.11f, 1.00f);
            colors[ImGuiCol_TabHovered] = ImVec4(0.80f, 0.15f, 0.15f, 0.30f);

            styleInitialized = true;
        }

        ImGuiIO& io = ImGui::GetIO();
        ImGui::SetNextWindowSize(ImVec2(520.0f, 480.0f), ImGuiCond_FirstUseEver);

        static bool firstRun = true;
        if (firstRun) {
            ImVec2 center = ImVec2(io.DisplaySize.x * 0.5f, io.DisplaySize.y * 0.5f);
            ImGui::SetNextWindowPos(center, ImGuiCond_Always, ImVec2(0.5f, 0.5f));
            firstRun = false;
        }

        bool windowOpen = open;

        ImGui::Begin("##MainMenu", &windowOpen, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoCollapse);

        ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(0.80f, 0.15f, 0.15f, 1.0f));
        ImGui::Text("Govno");
        ImGui::PopStyleColor();
        ImGui::SameLine();
        ImGui::TextColored(ImVec4(0.5f, 0.5f, 0.5f, 1.0f), "| v0.2 | by 4yTTaTT");

        ImGui::Separator();

        bool changed = false;

        if (ImGui::BeginTabBar("##tabs", ImGuiTabBarFlags_None)) {

            if (ImGui::BeginTabItem("Combat & Movement")) {
                ImGui::BeginChild("##combat_child", ImVec2(0, 0), true);

                ImGui::TextColored(ImVec4(0.8f, 0.8f, 0.8f, 1.0f), "Movement");
                if (ImGui::Checkbox("Bhop", &g_Config.bhop)) changed = true;

                ImGui::Spacing();
                ImGui::Separator();
                ImGui::Spacing();

                ImGui::TextColored(ImVec4(0.8f, 0.8f, 0.8f, 1.0f), "NoRecoil");
                if (ImGui::Checkbox("Enable NoRecoil", &g_Config.norecoilEnabled)) changed = true;

                ImGui::BeginDisabled(!g_Config.norecoilEnabled);
                if (ImGui::Checkbox("No ViewPunch", &g_Config.norecoilPunch)) changed = true;
                if (ImGui::Checkbox("No Spread (PrimarySpread)", &g_Config.norecoilSpread)) changed = true;
                if (ImGui::Checkbox("No EyeSpray", &g_Config.norecoilSpray)) changed = true;
                ImGui::EndDisabled();

                ImGui::EndChild();
                ImGui::EndTabItem();
            }

            if (ImGui::BeginTabItem("Visuals (ESP)")) {
                ImGui::BeginChild("##esp_child", ImVec2(0, 0), true);

                if (ImGui::Checkbox("Master Switch (Enable ESP)", &g_Config.esp)) changed = true;

                ImGui::Spacing();
                ImGui::TextColored(ImVec4(0.80f, 0.15f, 0.15f, 1.0f), "ESP Backend");
                ImGui::SameLine();
                int backend = g_Config.espUseLua ? 1 : 0;
                if (ImGui::RadioButton("C++", &backend, 0)) { g_Config.espUseLua = false; changed = true; }
                ImGui::SameLine();
                if (ImGui::RadioButton("Lua", &backend, 1)) { g_Config.espUseLua = true; changed = true; }
                ImGui::SameLine();
                ImGui::TextColored(
                    g_Config.espUseLua ? ImVec4(0.2f, 1.0f, 0.2f, 1.0f) : ImVec4(1.0f, 0.6f, 0.2f, 1.0f),
                    "| active: %s", g_Config.espUseLua ? "Lua" : "C++");
                ImGui::Spacing();
                ImGui::Separator();
                ImGui::Spacing();

                ImGui::BeginDisabled(!g_Config.esp);

                ImGui::Spacing();
                ImGui::Separator();
                ImGui::Spacing();

                ImGui::TextColored(ImVec4(0.80f, 0.15f, 0.15f, 1.0f), "Box Settings");
                if (ImGui::Checkbox("Draw Box", &g_Config.espBox)) changed = true;

                ImGui::BeginDisabled(!g_Config.espBox);
                if (ImGui::SliderFloat("Thickness", &g_Config.espBoxThickness, 1.0f, 4.0f, "%.1f")) changed = true;
                if (ImGui::SliderFloat("Width Scale", &g_Config.espBoxWidthScale, 0.2f, 1.0f, "%.2f")) changed = true;

                ImGui::Text("Box Style:");
                ImGui::SameLine();
                if (ImGui::RadioButton("Corner", &g_Config.espBoxStyle, 0)) changed = true;
                ImGui::SameLine();
                if (ImGui::RadioButton("Full", &g_Config.espBoxStyle, 1)) changed = true;
                ImGui::SameLine();
                if (ImGui::RadioButton("Corner+Fill", &g_Config.espBoxStyle, 2)) changed = true;
                ImGui::EndDisabled();

                ImGui::Spacing();
                ImGui::Separator();
                ImGui::Spacing();

                ImGui::TextColored(ImVec4(0.80f, 0.15f, 0.15f, 1.0f), "Info Elements");
                if (ImGui::Checkbox("Show Name", &g_Config.espName)) changed = true;
                if (ImGui::Checkbox("Show Health", &g_Config.espHealth)) changed = true;
                if (ImGui::Checkbox("Show Distance", &g_Config.espDistance)) changed = true;
                if (ImGui::Checkbox("Show HP Bar", &g_Config.espShowStatus)) changed = true;
                if (ImGui::Checkbox("Show Role (Traitor/Team)", &g_Config.espShowRole)) changed = true;

                ImGui::Spacing();
                ImGui::Separator();
                ImGui::Spacing();

                ImGui::TextColored(ImVec4(0.80f, 0.15f, 0.15f, 1.0f), "Visual Elements");
                if (ImGui::Checkbox("Skeleton", &g_Config.espSkeleton)) changed = true;
                if (ImGui::Checkbox("Snaplines", &g_Config.espLines)) changed = true;
                if (ImGui::Checkbox("Visible Check", &g_Config.espVisibleCheck)) changed = true;
                if (ImGui::SliderFloat("Max Distance", &g_Config.espDistanceMax, 100.0f, 10000.0f, "%.0f")) changed = true;

                ImGui::Spacing();
                ImGui::Separator();
                ImGui::Spacing();

                ImGui::TextColored(ImVec4(0.80f, 0.15f, 0.15f, 1.0f), "Filter");
                if (ImGui::SliderInt("Team Filter (0=all, 1=enemies)", &g_Config.espTeamFilter, 0, 2)) changed = true;

                ImGui::Spacing();
                ImGui::Separator();
                ImGui::Spacing();

                if (ImGui::CollapsingHeader("Colors")) {
                    if (ImGui::ColorEdit4("Visible", &g_Config.espVisibleColor[0], ImGuiColorEditFlags_NoInputs)) changed = true;
                    if (ImGui::ColorEdit4("Invisible", &g_Config.espInvisibleColor[0], ImGuiColorEditFlags_NoInputs)) changed = true;
                    if (ImGui::ColorEdit4("Snapline", &g_Config.espSnaplineColor[0], ImGuiColorEditFlags_NoInputs)) changed = true;
                    if (ImGui::ColorEdit4("Skeleton", &g_Config.espSkeletonColor[0], ImGuiColorEditFlags_NoInputs)) changed = true;
                    if (ImGui::ColorEdit4("Fill", &g_Config.espFillColor[0], ImGuiColorEditFlags_NoInputs)) changed = true;

                    ImGui::Spacing();
                    ImGui::TextColored(ImVec4(0.8f, 0.8f, 0.8f, 1.0f), "Role / Team Colors");
                    if (ImGui::ColorEdit4("Teammate", &g_Config.espTeammateColor[0], ImGuiColorEditFlags_NoInputs)) changed = true;
                    if (ImGui::ColorEdit4("Traitor Ally", &g_Config.espTraitorAllyColor[0], ImGuiColorEditFlags_NoInputs)) changed = true;
                    if (ImGui::ColorEdit4("Traitor Enemy", &g_Config.espTraitorEnemyColor[0], ImGuiColorEditFlags_NoInputs)) changed = true;
                }

                ImGui::EndDisabled();
                ImGui::EndChild();
                ImGui::EndTabItem();
            }

            if (ImGui::BeginTabItem("Aimbot")) {
                ImGui::BeginChild("##aim_child", ImVec2(0, 0), true);

                if (ImGui::Checkbox("Enable Aimbot", &g_Config.aimbotEnabled)) changed = true;

                if (ImGui::Checkbox("Aim on RMB (hold right mouse)", &g_Config.aimbotOnRMB)) changed = true;

                ImGui::BeginDisabled(!g_Config.aimbotEnabled);

                ImGui::Spacing();
                if (ImGui::SliderFloat("FOV", &g_Config.aimbotFov, 1.0f, 180.0f, "%.1f deg")) changed = true;
                if (ImGui::SliderInt("Smooth", &g_Config.aimbotSmooth, 1, 30)) changed = true;

                ImGui::Spacing();
                ImGui::Text("Target:");
                ImGui::SameLine();
                if (ImGui::RadioButton("Head", &g_Config.aimbotTarget, 0)) changed = true;
                ImGui::SameLine();
                if (ImGui::RadioButton("Chest", &g_Config.aimbotTarget, 1)) changed = true;
                ImGui::SameLine();
                if (ImGui::RadioButton("Nearest", &g_Config.aimbotTarget, 2)) changed = true;

                ImGui::Spacing();
                if (ImGui::Checkbox("Visible Check", &g_Config.aimbotVisibleCheck)) changed = true;
                if (ImGui::Checkbox("Velocity Compensation", &g_Config.aimbotVelocityComp)) changed = true;
                if (ImGui::Checkbox("Ping Compensation", &g_Config.aimbotPingComp)) changed = true;
                if (ImGui::Checkbox("Auto Fire", &g_Config.aimbotAutoFire)) changed = true;

                ImGui::Spacing();
                if (ImGui::SliderFloat("Ping (ms, fallback)", &g_Config.aimbotPing, 0.0f, 300.0f, "%.0f")) changed = true;
                if (ImGui::SliderFloat("Interp (sec)", &g_Config.aimbotInterp, 0.0f, 0.5f, "%.2f")) changed = true;

                ImGui::EndDisabled();
                ImGui::EndChild();
                ImGui::EndTabItem();
            }

            if (ImGui::BeginTabItem("Misc")) {
                ImGui::BeginChild("##misc_child", ImVec2(0, 0), true);

                ImGui::TextColored(ImVec4(0.8f, 0.8f, 0.8f, 1.0f), "Game Settings");
                if (ImGui::Checkbox("Thirdperson", &g_Config.thirdperson)) changed = true;

                ImGui::Spacing();
                ImGui::Separator();
                ImGui::Spacing();

                ImGui::TextColored(ImVec4(0.8f, 0.8f, 0.8f, 1.0f), "Logging");
                if (ImGui::Checkbox("Verbose Log", &g_Config.verboseLog)) changed = true;
                if (ImGui::Checkbox("Log UserCmd", &g_Config.logUserCmd)) changed = true;

                ImGui::Spacing();
                ImGui::Separator();
                ImGui::Spacing();

                ImGui::TextColored(ImVec4(0.8f, 0.8f, 0.8f, 1.0f), "Lua");
                if (ImGui::Button("Reinit Lua / Reload Scripts")) {
                    LuaBridge::ResetState();
                    if (LuaBridge::Init()) {
                        LoadAllLuaScripts();
                        Log("[LUA] manual reinit from menu");
                    }
                    else {
                        LogErr("[LUA] manual reinit failed");
                    }
                }

                ImGui::EndChild();
                ImGui::EndTabItem();
            }

            ImGui::EndTabBar();
        }

        ImGui::Spacing();
        ImGui::Separator();
        ImGui::TextColored(ImVec4(0.5f, 0.5f, 0.5f, 1.0f), "FPS: %.1f | Press INSERT to close", io.Framerate);

        ImGui::End();

        if (windowOpen != open) {
            g_menuOpen.store(windowOpen, std::memory_order_relaxed);
            if (!windowOpen) {
                if (g_gameWindow) SetCapture(g_gameWindow);
            }
        }

        if (changed) {
            g_Config.Save();
        }
    }

    void RenderFrame() {
        if (!g_backendReady || !g_imguiContext) return;

        int width = 0, height = 0;
        RECT rect{};
        if (g_gameWindow && GetClientRect(g_gameWindow, &rect)) {
            width = rect.right;
            height = rect.bottom;
        }
        if (width <= 0 || height <= 0) return;

        ULONGLONG now = GetTickCount64();
        float delta = g_lastFrameTick ? static_cast<float>(now - g_lastFrameTick) / 1000.0f
            : 1.0f / 60.0f;
        if (delta <= 0.0f || delta > 1.0f) delta = 1.0f / 60.0f;
        g_lastFrameTick = now;

        ImGuiIO& io = ImGui::GetIO();
        io.DisplaySize = ImVec2(static_cast<float>(width), static_cast<float>(height));
        io.DeltaTime = delta;
        io.MouseDrawCursor = g_menuOpen.load(std::memory_order_relaxed);

        if (g_renderApi == RenderApi::DX9)
            ImGui_ImplDX9_NewFrame();
        else if (g_renderApi == RenderApi::DX11)
            ImGui_ImplDX11_NewFrame();
        else
            return;

        ImGui_ImplWin32_NewFrame();
        ImGui::NewFrame();

        // C++ ESP — рисуется всегда, когда выбран C++ бэкенд и включён ESP.
        if (g_Config.esp && !g_Config.espUseLua) {
            Esp::Render();
        }

        DrawMenu();

        ImGui::Render();

        if (g_renderApi == RenderApi::DX9)
            ImGui_ImplDX9_RenderDrawData(ImGui::GetDrawData());
        else
            ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());

        ++g_frameCount;
        if (!g_firstFrameLogged) {
            g_firstFrameLogged = true;
            Log("[OVERLAY] first frame rendered");
        }
    }

    bool CreateDummyDX9() {
        if (g_dummyDevice9Ex && g_dummyDevice9) return true;
        if (!EnsureHiddenWindow()) return false;

        D3DPRESENT_PARAMETERS pp{};
        pp.Windowed = TRUE;
        pp.SwapEffect = D3DSWAPEFFECT_DISCARD;
        pp.hDeviceWindow = g_hiddenWindow;
        pp.BackBufferWidth = 1;
        pp.BackBufferHeight = 1;
        pp.BackBufferFormat = D3DFMT_UNKNOWN;

        if (!g_d3d9) {
            HRESULT hr = Direct3DCreate9Ex(D3D_SDK_VERSION, &g_d3d9);
            if (FAILED(hr) || !g_d3d9) {
                LogWarn("[OVERLAY] Direct3DCreate9Ex failed (hr=0x%08X)", hr);
            }
        }

        if (g_d3d9 && !g_dummyDevice9Ex) {
            HRESULT hr = g_d3d9->CreateDeviceEx(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, g_hiddenWindow,
                D3DCREATE_SOFTWARE_VERTEXPROCESSING, &pp, nullptr,
                &g_dummyDevice9Ex);
            if (SUCCEEDED(hr) && g_dummyDevice9Ex) {
                g_dummyVmt9Ex = *reinterpret_cast<void***>(g_dummyDevice9Ex);
            }
            else {
                LogWarn("[OVERLAY] dummy IDirect3DDevice9Ex creation failed (hr=0x%08X)", hr);
            }
        }

        if (!g_dummyDevice9) {
            IDirect3D9* d3d = Direct3DCreate9(D3D_SDK_VERSION);
            if (d3d) {
                HRESULT hr = d3d->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, g_hiddenWindow,
                    D3DCREATE_SOFTWARE_VERTEXPROCESSING, &pp,
                    &g_dummyDevice9);
                if (SUCCEEDED(hr) && g_dummyDevice9) {
                    g_dummyVmt9 = *reinterpret_cast<void***>(g_dummyDevice9);
                }
                else {
                    LogWarn("[OVERLAY] dummy IDirect3DDevice9 creation failed (hr=0x%08X)", hr);
                }
                d3d->Release();
            }
        }

        auto addSignature = [](void** vmt) {
            if (!vmt || g_signatureCount9 >= 2) return;
            if (!IsExecutable(vmt[41]) || !IsExecutable(vmt[43]) ||
                !IsExecutable(vmt[44]) || !IsExecutable(vmt[45]))
                return;

            D3D9Signature sig;
            sig.beginScene = vmt[41];
            sig.clear = vmt[43];
            sig.setTransform = vmt[44];
            sig.getTransform = vmt[45];

            for (int i = 0; i < g_signatureCount9; ++i) {
                if (g_signatures9[i].beginScene == sig.beginScene &&
                    g_signatures9[i].clear == sig.clear &&
                    g_signatures9[i].setTransform == sig.setTransform &&
                    g_signatures9[i].getTransform == sig.getTransform)
                    return;
            }
            g_signatures9[g_signatureCount9++] = sig;
            };

        addSignature(g_dummyVmt9Ex);
        addSignature(g_dummyVmt9);

        if (g_signatureCount9 == 0) {
            LogErr("[OVERLAY] no usable D3D9 vtable signature (dummy devices unavailable)");
            return false;
        }

        Log("[OVERLAY] D3D9 signatures: %d (Ex=%p plain=%p)", g_signatureCount9,
            reinterpret_cast<void*>(g_dummyVmt9Ex), reinterpret_cast<void*>(g_dummyVmt9));
        return true;
    }

    std::vector<void**> FindD3D9Vtables(bool loose) {
        std::vector<void**> result;

        uintptr_t address = 0x10000;
        MEMORY_BASIC_INFORMATION mbi{};
        size_t scanned = 0;

        while (VirtualQuery(reinterpret_cast<LPCVOID>(address), &mbi, sizeof(mbi))) {
            uintptr_t base = reinterpret_cast<uintptr_t>(mbi.BaseAddress);
            uintptr_t end = base + mbi.RegionSize;
            if (end <= address) break;
            address = end;

            if (mbi.State != MEM_COMMIT) continue;
            if (mbi.Type != MEM_PRIVATE) continue;

            DWORD protect = mbi.Protect;
            if (protect & (PAGE_NOACCESS | PAGE_GUARD)) continue;
            if (!(protect & (PAGE_READWRITE | PAGE_EXECUTE_READWRITE | PAGE_WRITECOPY))) continue;

            uint8_t* cursor = reinterpret_cast<uint8_t*>(base);
            uint8_t* limit = reinterpret_cast<uint8_t*>(end);
            if (limit - cursor < static_cast<ptrdiff_t>(46 * sizeof(void*))) continue;

            uint8_t* last = limit - 46 * sizeof(void*);
            for (; cursor <= last; cursor += sizeof(void*)) {
                void* candidate = *reinterpret_cast<void**>(cursor);
                if (!candidate) continue;

                void** vmt = reinterpret_cast<void**>(cursor - 41 * sizeof(void*));

                bool matched = false;
                if (!loose) {
                    for (int i = 0; i < g_signatureCount9; ++i) {
                        const D3D9Signature& sig = g_signatures9[i];
                        if (candidate != sig.beginScene) continue;
                        if (vmt[43] != sig.clear) continue;
                        if (vmt[44] != sig.setTransform) continue;
                        if (vmt[45] != sig.getTransform) continue;
                        matched = true;
                        break;
                    }
                }
                else {
                    if (InD3D9Code(vmt[41]) && InD3D9Code(vmt[43]) &&
                        InD3D9Code(vmt[44]) && InD3D9Code(vmt[45]) &&
                        (InD3D9Code(vmt[17]) || InOverlayCode(vmt[17])))
                        matched = true;
                }
                if (!matched) continue;

                bool duplicate = false;
                for (void** existing : result) {
                    if (existing == vmt) {
                        duplicate = true;
                        break;
                    }
                }
                if (!duplicate) result.push_back(vmt);
            }

            scanned += static_cast<size_t>(mbi.RegionSize);
        }

        Log("[OVERLAY] D3D9 vtable scan (%s): %zu MB private memory, candidates=%zu",
            loose ? "loose" : "exact", scanned / (1024 * 1024), result.size());
        return result;
    }

    HRESULT __stdcall hkPresent9(IDirect3DDevice9* device, const RECT* sourceRect,
        const RECT* destRect, HWND destWindow, const RGNDATA* dirtyRegion) {
        void** vmt = device ? *reinterpret_cast<void***>(device) : nullptr;

        PresentDX9Fn original = g_fallbackPresent9;
        auto it = g_present9Originals.find(vmt);
        if (it != g_present9Originals.end()) original = it->second;

        if (device != g_cachedDevice9) {
            g_cachedDevice9 = device;
            g_device9IsGame = IsGameDevice9(device);

            if (g_device9IsGame && g_renderApi == RenderApi::DX9 && g_gameDevice9 != device) {
                LogWarn("[OVERLAY] D3D9 device changed (%p -> %p), reinitializing ImGui",
                    reinterpret_cast<void*>(g_gameDevice9),
                    reinterpret_cast<void*>(device));
                ImGui_ImplDX9_Shutdown();
                g_backendReady = false;
                g_gameDevice9 = nullptr;
                g_frameCount = 0;
                g_firstFrameLogged = false;
            }
        }

        if (g_device9IsGame) {
            if (!g_backendReady) {
                InitImGuiDX9(device);
            }
            if (g_renderApi == RenderApi::DX9 && g_gameDevice9 == device)
                RenderFrame();
        }

        if (original)
            return original(device, sourceRect, destRect, destWindow, dirtyRegion);
        return D3DERR_INVALIDCALL;
    }

    bool HookDX9() {
        if (!CreateDummyDX9()) return false;

        if (HMODULE d3d9Module = GetModuleHandleA("d3d9.dll")) {
            MODULEINFO info{};
            if (GetModuleInformation(GetCurrentProcess(), d3d9Module, &info, sizeof(info))) {
                g_d3d9Base = reinterpret_cast<uintptr_t>(info.lpBaseOfDll);
                g_d3d9End = g_d3d9Base + info.SizeOfImage;
            }
        }
        if (HMODULE overlayModule = GetModuleHandleA("gameoverlayrenderer64.dll")) {
            MODULEINFO info{};
            if (GetModuleInformation(GetCurrentProcess(), overlayModule, &info, sizeof(info))) {
                g_overlayBase = reinterpret_cast<uintptr_t>(info.lpBaseOfDll);
                g_overlayEnd = g_overlayBase + info.SizeOfImage;
            }
        }

        Log("[OVERLAY] Scanning for D3D9 VTable in shaderapidx9.dll...");
        std::vector<void**> vtables;

        HMODULE shaderMod = GetModuleHandleA("shaderapidx9.dll");
        if (!shaderMod) shaderMod = GetModuleHandleA("d3d9.dll");

        if (shaderMod) {
            MODULEINFO info{};
            if (GetModuleInformation(GetCurrentProcess(), shaderMod, &info, sizeof(info))) {
                uint8_t* base = (uint8_t*)info.lpBaseOfDll;
                uint8_t* end = base + info.SizeOfImage;

                for (uint8_t* ptr = base; ptr < end - 46 * sizeof(void*); ptr += sizeof(void*)) {
                    void* candidate = *(void**)ptr;
                    if (!candidate) continue;
                    void** vmt = (void**)(ptr - 41 * sizeof(void*));

                    if (IsExecutable(vmt[41]) && IsExecutable(vmt[43]) && IsExecutable(vmt[44])) {
                        if (g_signatureCount9 > 0 && candidate == g_signatures9[0].beginScene) {
                            vtables.push_back(vmt);
                            Log("[OVERLAY] Found VTable in module base %p", info.lpBaseOfDll);
                            break;
                        }
                    }
                }
            }
        }

        if (vtables.empty()) {
            LogWarn("[OVERLAY] Fast scan failed, doing full memory scan (this may take a few seconds)");
            vtables = FindD3D9Vtables(false);
        }

        int hooked = 0;
        for (void** vmt : vtables) {
            if (vmt == g_dummyVmt9Ex || vmt == g_dummyVmt9) continue;
            if (g_present9Originals.count(vmt)) continue;
            if (!IsExecutable(vmt[17])) continue;
            if (vmt[17] == reinterpret_cast<void*>(hkPresent9)) continue;

            PresentDX9Fn original = VMT_HookRaw<PresentDX9Fn>(vmt, reinterpret_cast<void*>(hkPresent9), 17);
            if (!original) continue;

            g_present9Originals[vmt] = original;
            if (!g_fallbackPresent9) g_fallbackPresent9 = original;
            ++hooked;
            Log("[OVERLAY] DX9 Present hook: vtable=%p original=%p", vmt, reinterpret_cast<void*>(original));
        }

        g_dx9VtableCount = hooked;
        if (hooked == 0) {
            LogErr("[OVERLAY] no live D3D9 device vtable found (ESP cannot render)");
            return false;
        }

        Log("[OVERLAY] Present hooked (DX9, %d vtable%s)", hooked, hooked == 1 ? "" : "s");
        return true;
    }

    bool HookDX11() {
        if (!EnsureHiddenWindow()) return false;

        DXGI_SWAP_CHAIN_DESC sd{};
        sd.BufferCount = 1;
        sd.BufferDesc.Width = 1;
        sd.BufferDesc.Height = 1;
        sd.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
        sd.BufferDesc.RefreshRate.Numerator = 60;
        sd.BufferDesc.RefreshRate.Denominator = 1;
        sd.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
        sd.OutputWindow = g_hiddenWindow;
        sd.SampleDesc.Count = 1;
        sd.Windowed = TRUE;
        sd.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;

        D3D_FEATURE_LEVEL levels[] = { D3D_FEATURE_LEVEL_11_0, D3D_FEATURE_LEVEL_10_0 };
        UINT flags = 0;

        HRESULT hr = D3D11CreateDeviceAndSwapChain(nullptr, D3D_DRIVER_TYPE_HARDWARE, nullptr, flags,
            levels, 2, D3D11_SDK_VERSION, &sd,
            &g_dummySwapChain, &g_dummyDevice11, nullptr,
            &g_dummyContext11);
        if (FAILED(hr)) {
            LogWarn("[OVERLAY] hardware D3D11 device failed (hr=0x%08X), trying WARP", hr);
            hr = D3D11CreateDeviceAndSwapChain(nullptr, D3D_DRIVER_TYPE_WARP, nullptr, flags,
                levels, 2, D3D11_SDK_VERSION, &sd,
                &g_dummySwapChain, &g_dummyDevice11, nullptr,
                &g_dummyContext11);
        }
        if (FAILED(hr) || !g_dummySwapChain) {
            LogErr("[OVERLAY] D3D11CreateDeviceAndSwapChain failed (hr=0x%08X)", hr);
            return false;
        }

        void** vmt = *reinterpret_cast<void***>(g_dummySwapChain);
        if (!vmt || !IsExecutable(vmt[8])) {
            LogErr("[OVERLAY] dummy IDXGISwapChain VMT[8] is not executable");
            return false;
        }

        g_oPresent11 = VMT_HookRaw<PresentDX11Fn>(vmt, reinterpret_cast<void*>(hkPresent11), 8);
        if (!g_oPresent11) {
            LogErr("[OVERLAY] DX11 Present VMT hook failed");
            return false;
        }

        Log("[OVERLAY] Present hooked (DX11) vtable=%p original=%p",
            vmt, reinterpret_cast<void*>(g_oPresent11));
        return true;
    }

    HRESULT __stdcall hkPresent11(IDXGISwapChain* swapChain, UINT syncInterval, UINT flags) {
        if (swapChain && !g_backendReady)
            InitImGuiDX11(swapChain);

        if (g_renderApi == RenderApi::DX11 && g_gameSwapChain11 == swapChain &&
            g_device11 && g_context11) {
            ID3D11Texture2D* backBuffer = nullptr;
            if (SUCCEEDED(swapChain->GetBuffer(0, __uuidof(ID3D11Texture2D),
                reinterpret_cast<void**>(&backBuffer))) &&
                backBuffer) {
                ID3D11RenderTargetView* rtv = nullptr;
                if (SUCCEEDED(g_device11->CreateRenderTargetView(backBuffer, nullptr, &rtv)) && rtv) {
                    g_context11->OMSetRenderTargets(1, &rtv, nullptr);
                    RenderFrame();
                    rtv->Release();
                }
                backBuffer->Release();
            }
        }

        if (g_oPresent11)
            return g_oPresent11(swapChain, syncInterval, flags);
        return S_OK;
    }

} // namespace

namespace Overlay {

    bool Install() {
        if (g_api != Api::None) return g_backendReady || g_dx9VtableCount > 0 || g_oPresent11 != nullptr;

        const bool hasD3D9 = GetModuleHandleA("d3d9.dll") != nullptr ||
            GetModuleHandleA("shaderapidx9.dll") != nullptr;
        const bool hasD3D11 = GetModuleHandleA("d3d11.dll") != nullptr;

        if (hasD3D9) {
            g_api = Api::DX9;
            if (hasD3D11)
                Log("[DX] using DX9 (d3d11.dll is also loaded; GMod renderer is shaderapidx9)");
            else
                Log("[DX] using DX9");
            return HookDX9();
        }

        if (hasD3D11) {
            g_api = Api::DX11;
            Log("[DX] using DX11");
            return HookDX11();
        }

        LogErr("[OVERLAY] neither d3d9.dll/shaderapidx9.dll nor d3d11.dll is loaded; overlay disabled");
        return false;
    }

    bool IsMenuOpen() {
        return g_menuOpen.load(std::memory_order_relaxed);
    }

    void Shutdown() {
        if (g_backendReady) {
            if (g_renderApi == RenderApi::DX9)
                ImGui_ImplDX9_Shutdown();
            else if (g_renderApi == RenderApi::DX11)
                ImGui_ImplDX11_Shutdown();
            ImGui_ImplWin32_Shutdown();
        }

        RemoveWndProcHook();

        if (g_imguiContext) {
            ImGui::DestroyContext();
            g_imguiContext = false;
        }

        g_backendReady = false;
        g_renderApi = RenderApi::None;
    }

} // namespace Overlay