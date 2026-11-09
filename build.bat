@echo off
setlocal

call "E:\VS2022\VC\Auxiliary\Build\vcvars64.bat"

set IMGUI=src\third_party\imgui
set SRC=src\dllmain.cpp src\Memory.cpp src\lua_bridge.cpp src\hooks\install.cpp src\overlay.cpp ^
        %IMGUI%\imgui.cpp %IMGUI%\imgui_draw.cpp %IMGUI%\imgui_widgets.cpp %IMGUI%\imgui_tables.cpp ^
        %IMGUI%\imgui_impl_dx9.cpp %IMGUI%\imgui_impl_dx11.cpp %IMGUI%\imgui_impl_win32.cpp
set OUT=build
set NAME=gmodcheat.dll

if not exist %OUT% mkdir %OUT%
del /q %OUT%\*.obj 2>nul

cl /utf-8 /nologo /LD /EHsc /std:c++20 /O2 /MT /GS- /guard:cf- ^
   /D_WIN64 /DNDEBUG /DUNICODE /D_UNICODE ^
   /I src /I src\sdk ^
   %SRC% ^
   /Fe:%OUT%\%NAME% ^
   /Fo:%OUT%\ ^
   /link /DLL /SUBSYSTEM:WINDOWS ^
   user32.lib kernel32.lib psapi.lib d3d9.lib d3d11.lib dxgi.lib d3dcompiler.lib

if errorlevel 1 (
    echo BUILD FAILED
    exit /b 1
)
echo BUILD OK: %OUT%\%NAME%
endlocal