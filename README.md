# gmod_cheat — база + bhop + ESP (GMod x64)

База содержит:

- ожидание `client.dll` / `engine.dll`;
- разрешение интерфейсов через `CreateInterface`;
- хуки `CreateMove`, `GetUserCmd` (VMT[8] + VMT[9]), `FrameStageNotify`;
- bhop в `hkCreateMove` после вызова `oCreateMove`;
- ESP (box/name/health/distance) через ImGui + DX9/DX11 overlay;
- логирование в `cheat_log.txt`;
- утилиты чтения памяти/VMT и загрузку `config.ini`.

Aim/thirdperson отсутствуют.

## ESP

ESP собирает игроков в `hkFrameStageNotify` на стадии
`FRAME_NET_UPDATE_END` (4) и рисует их в хуке `Present`:

- `src\esp.hpp` — сбор данных, `WorldToScreen`, отрисовка ImGui;
- `src\overlay.hpp` / `src\overlay.cpp` — определение DX9/DX11, хук
  `Present`, инициализация ImGui;
- `src\third_party\imgui\` — Dear ImGui (ядро + `imgui_impl_dx9` взяты из
  `E:\GMod-SDK-main\GMod-SDK\ImGui`, `imgui_impl_dx11` написан минимальный
  под ту же версию ядра, `imgui_shim.cpp` закрывает меню-заглушки).

GMod x64 рендерит через `shaderapidx9.dll` (DX9). Поэтому при наличии
`shaderapidx9.dll`/`d3d9.dll` выбирается DX9, даже если `d3d11.dll` тоже
загружен (его может тянуть Chromium/ANGLE или сторонний оверлей).

У `IDirect3DDevice9` в D3D9 своя vtable на каждый экземпляр, поэтому
dummy-device хук не подходит. Оверлей создаёт dummy `IDirect3DDevice9Ex`,
берёт из его vtable настоящие указатели `BeginScene/Clear/SetTransform/
GetTransform`, затем ищет в приватной памяти vtable живого устройства с
теми же указателями и хукает в нём `Present` (VMT[17]). Для DX11
используется обычный dummy swapchain + `Present` (VMT[8]).


## Сборка

```bat
build.bat
```

Результат: `build\gmodcheat.dll`.

Используется MSVC x64, C++20, `/MT`, вывод в `build\`.
Линкуются `d3d9.lib`, `d3d11.lib`, `dxgi.lib`, `d3dcompiler.lib`.

## Запуск

1. Запустить Garry's Mod (x64).
2. Загрузить `build\gmodcheat.dll` любым инжектором (Process Hacker,
   Cheat Engine, Xenos и т.п.).
3. Открыть `C:\Users\Kompukter\Desktop\gmod_cheat\cheat_log.txt`.
   Если файл создать не удалось, лог будет в `%TEMP%\gmod_cheat_log.txt`.

Инжектить можно до загрузки карты: поток сам ждёт `client.dll` и
`engine.dll` до 60 секунд.

## Что должно быть в логе

Успешный старт:

```text
=== gmod_cheat base ===
[MAIN] log path = C:\Users\Kompukter\Desktop\gmod_cheat\cheat_log.txt
[MAIN] client.dll=... engine.dll=...
[MAIN] core interfaces ready after ... ms
[IFACE] client.dll!VClient017                          = ...
[IFACE] engine.dll!VEngineClient015                    = ...
[IFACE] client.dll!VClientEntityList003                = ...
[CLIENTMODE] VClient017 VMT[10] GetClientMode = ...
[CLIENTMODE] GetClientMode returned ...
[CLIENTMODE] using returned value as vtable (confirmed)
[CLIENTMODE] VMT[21] = ... bytes: 40 53 48 83 EC 30 ...
[CINPUT] ClientMode::CreateMove+0x50: mov rcx,[...] -> ... ACCEPT
[CINPUT] CHLClient::CreateMove+0x0: mov rcx,[...] -> ... ACCEPT
[WARN] [CINPUT] candidates differ: CHLClient=... ClientMode=... (using CHLClient::CreateMove, probing both)
[CINPUT] g_pInput = ... (source=CHLClient::CreateMove)
[CINPUT] g_pInputAlt = ... (source=ClientMode::CreateMove)
[CINPUT] object = ... vtable = ... source=CHLClient::CreateMove
[CINPUT] vmt[08] = ...  <- GetUserCmd (CInput.h)
[CINPUT] vmt[09] = ...  <- MakeWeaponSelection (probe)
[CINPUT:ALT] object = ... vtable = ... source=ClientMode::CreateMove
[CONFIG] loaded from ...config.ini
[CONFIG] bhop=1 watermark=0 esp=1 box=1 name=1 health=1 dist=1 team=0 aimbot=0 thirdperson=0 verboseLog=0 logUserCmd=1
[HOOK] CHLClient::CreateMove CInput VMT[8] original=... hook=...
[HOOK] CHLClient::CreateMove CInput VMT[9] original=... hook=...
[HOOK] ClientMode::CreateMove CInput VMT[8] original=... hook=...
[HOOK] ClientMode::CreateMove CInput VMT[9] original=... hook=...
[HOOK] ClientMode::CreateMove VMT[21] original=... hook=...
[FSN] VClient017 VMT[35] = ... bytes: ...
[FSN] VClient017 VMT[36] = ... bytes: ...
[FSN] VClient017 VMT[37] = ... bytes: ...
[HOOK] FrameStageNotify VMT[35] original=... hook=...
[BHOP] enabled (config.bhop=1, applied in CreateMove after oCreateMove)
[DX] using DX9
[OVERLAY] D3D9 signatures: 1 (Ex=... plain=...)
[OVERLAY] D3D9 vtable scan (exact): ... MB private memory, candidates=...
[OVERLAY] DX9 Present hook: vtable=... original=...
[OVERLAY] Present hooked (DX9, 1 vtable)
[ESP] enabled (config.esp=1)
[OVERLAY] first frame rendered
[DIAG] attempt=0 localIdx=... local=... flags=0x... onGround=...
...
[MAIN] base initialized, hooks stay active
```

После загрузки карты:

```text
[CM] #500 cmd=... num=... tick=... buttons=0x... flags=0x... onGround=...
[UC] #500 seq=... num=... tick=... buttons=0x... flags=0x... onGround=...
[BHOP] calls=500 triggered=...
[FSN] stage=... (FRAME_...) calls=...
[ESP] players collected: N
[ESP] rendered: N
[CInput] GetUserCmd confirmed at VMT[8] (previous=-1, seq=...) source=CHLClient::CreateMove
```

Важно: `command_number == 0` — мусорный cmd, он пропускается.
`[CM]` и `[UC]` должны показывать растущий `num` и нормальный `tick`.
`[UC]` и `[CM]` пишутся раз в 500 вызовов, `[FSN]` — только при смене
stage и не чаще одного раза на 200 вызовов. `[BHOP]` пишется раз в 500
валидных `GetUserCmd`, если `config.bhop=1`.

`[CM]` печатается уже после `oCreateMove` и после bhop-логики, поэтому
`buttons` в нём — итоговые: при зажатом пробеле на земле содержит `0x2`
(`IN_JUMP`), в воздухе без `0x2`. Без пробела `IN_JUMP` не появляется.
`triggered` в `[BHOP]` растёт при каждом переходе «в воздухе → на земле».

## Диагностика по логу

- Нет `core interfaces ready` / `VClient017 = nullptr`:
  `CreateInterface` не нашёл интерфейс. Проверить `client.dll`/`engine.dll`
  и имена `VClient017`, `VEngineClient015`.
- `GetClientMode returned ...` есть, но `neither vtable nor object`:
  изменился VMT[10] или сигнатура. Смотреть первые 25 указателей
  возвращённого значения.
- `[CINPUT] not found`: в первых `0x200` байтах `CreateMove` нет
  `48 8B 0D` либо кандидат не проходит проверку VMT[8]/VMT[9].
  В логе будут строки `reject` — смотреть адреса и содержимое VMT.
- `GetUserCmd confirmed` не появляется: `command_number` не совпал с
  аргументом. Для отладки поставить `verboseLog=1` — появятся первые
  5 строк `[CInput] ... call #...` и hex-дамп `[UC] raw`.
- `GetUserCmd confirmed` идёт с `source=ClientMode::CreateMove`, а не
  `CHLClient`: значит, на этой сборке реальный CInput — ClientMode-кандидат;
  оба хука уже стоят, менять приоритет не нужно.
- `[FSN]` не появляется совсем: возможно, индекс не 35.
  В логе уже печатаются прологи VMT[35..37]; если `35` не похож на
  `FrameStageNotify`, поменять `kFrameStageNotifyIndex` в
  `src/hooks/frame_stage_notify.hpp` на 36 или 37 и пересобрать.
- `[CM]` не появляется: `CreateMove` VMT[21] не тот индекс либо
  ClientMode определён неверно.
- ESP не рисуется:
  - нет `[DX] using DX9` — не загрузился `d3d9.dll`/`shaderapidx9.dll`;
  - `candidates=0` — vtable живого устройства не найдена. Смотреть
    `[OVERLAY] D3D9 signatures`: если dummy-устройства не создались,
    проверить, что игра запущена не в серверном режиме;
  - `[OVERLAY] first frame rendered` есть, но боксов нет — проверить
    `[ESP] health probe local` (правильный ли `m_iHealth`), а также
    `[ESP] players collected: N` (N > 0);
  - пустой экран/чёрный кадр — попробовать `esp_box=1` при остальных
    выключенных флагах, чтобы исключить шрифт.

## Конфиг

`config.ini` создаётся автоматически:

```ini
bhop=1
watermark=0
esp=1
esp_box=1
esp_name=1
esp_health=1
esp_distance=1
esp_team_check=0
aimbot=0
thirdperson=0
verboseLog=0
logUserCmd=1
```

- `esp=1` — включить ESP. При `esp=0` оверлей всё равно инициализируется
  и вызывает `NewFrame`/`Render`, но не рисует ни одного элемента.
- `esp_box`, `esp_name`, `esp_health`, `esp_distance` — отдельные элементы.
- `esp_team_check=1` — не рисовать союзников (при известной локальной
  команде).
- `bhop=1` — включить bhop: если пробел зажат, `IN_JUMP` ставится на
  земле и снимается в воздухе (`hkCreateMove` после `oCreateMove`). Без
  зажатого пробела логика не вмешивается, авто-прыжка нет.
- `verboseLog=1` — включить подробный лог: hex-дамп `[UC] raw`,
  hex-дамп `[CM] cmd` и первые/редкие строки `[CInput] ... call #...`.
- `logUserCmd=0` — отключить строки `[UC]`, extension-point продолжает
  вызываться.

Флаги `watermark`/`aimbot`/`thirdperson` — только заготовки.
