# UEVR MCP Testing & Interaction Guide

## Architecture

Three layers:
1. **UEVR Plugin** (`uevr_mcp.dll`) - C++ DLL inside game process, HTTP API (port 8899) + named pipe (`\\.\pipe\UEVR_MCP`)
2. **MCP Server** (`UevrMcpServer.exe`) - .NET 9, bridges MCP protocol to plugin HTTP/pipe
3. **Claude / MCP Client** - consumes MCP tools

## Correct HTTP API Endpoints

| MCP Tool | Method | Route |
|----------|--------|-------|
| `uevr_get_status` | Pipe | `get_status` |
| `uevr_exec_command` | POST | `/api/console/command` |
| `uevr_invoke_method` | POST | **`/api/explorer/method`** |
| `uevr_get_singletons` | GET | `/api/explorer/singletons` |
| `uevr_search` | GET | `/api/explorer/search` |
| `uevr_read_field` | GET | `/api/explorer/read_field` |
| `uevr_write_field` | POST | `/api/explorer/write_field` |
| `uevr_inspect_object` | GET | `/api/explorer/object` |
| `uevr_world_actors` | GET | `/api/world/actors` |
| `uevr_world_hierarchy` | GET | `/api/world/hierarchy` |
| `uevr_vr_status` | GET | `/api/vr/status` |
| `uevr_diagnostics` | GET | `/api/diagnostics/plugins` |
| `uevr_lua_exec` | POST | **`/api/lua/exec`** |
| `uevr_lua_state` | GET | `/api/lua/state` |
| `uevr_lua_globals` | GET | `/api/lua/globals` |
| `uevr_input_keyboard` | POST | `/api/input/keyboard` |
| `uevr_input_mouse` | POST | `/api/input/mouse` |
| `uevr_input_gamepad` | POST | `/api/input/gamepad` |
| `uevr_asset_search` | GET | `/api/asset/search` |
| `uevr_asset_load` | POST | `/api/asset/load` |

### Critical Mistakes to Avoid

- **Wrong Lua endpoint**: `/api/lua/exec` NOT `/api/lua/execute`
- **Wrong invoke endpoint**: `/api/explorer/method` NOT `/api/mutate/invoke`
- **Lua colon syntax**: UEVR API functions are **plain functions**, NOT methods.
  - WRONG: `uevr.api:find_uobject(name)` - passes self as table, causes "expected string, received table"
  - RIGHT: `uevr.api.find_uobject(name)` - plain function call
  - WRONG: `uevr.api:execute_command(cmd)` - same error
  - RIGHT: `uevr.api.execute_command(cmd)` - works
  - **Exception**: `get_player_controller`, `get_engine`, `get_local_pawn` DO use colon (true methods on userdata)

## UEVR Lua API Reference

### Globals

```lua
-- uevr.api methods (use COLON - these are real methods on userdata)
uevr.api:get_player_controller()  -- PlayerController
uevr.api:get_engine()             -- GameEngine
uevr.api:get_local_pawn()         -- Local Pawn

-- uevr.api functions (use DOT - plain functions, NO colon)
uevr.api.find_uobject(fullNameString)   -- Find UObject by full path string
uevr.api.execute_command(consoleCmd)    -- Execute UE console command
uevr.api.spawn_object(...)             -- Spawn object
uevr.api.add_component_by_class(...)   -- Add component
uevr.api.dispatch_lua_event(...)       -- Dispatch event
uevr.api.get_persistent_dir()          -- Get persistent directory

-- mcp helpers (plain functions)
mcp.read_ptr(address)          -- Read pointer from memory address
mcp.read_int(address)          -- Read integer
mcp.read_float(address)        -- Read float
mcp.read_double(address)       -- Read double
mcp.read_bool(address)         -- Read boolean
mcp.read_property(obj, name)   -- Read UProperty value
mcp.write_property(obj, name, value) -- Write UProperty value
mcp.write_int(address, value)  -- Write integer to memory
mcp.write_float(address, value)
mcp.write_bool(address, value)
mcp.write_double(address, value)
mcp.log(msg)                   -- Log message
mcp.on_frame(callback)         -- Register per-frame callback
mcp.set_timer(callback, ms)    -- Set timer
mcp.clear_timer(id)            -- Clear timer
mcp.async(callback)            -- Async operation
```

### UObject Methods (on instances returned by find_uobject etc.)

```lua
obj:get_full_name()    -- Full object path string
obj:get_class()        -- UClass
obj:get_outer()        -- Outer/parent UObject
obj:call_function(fn)  -- Call UFunction via ProcessEvent
```

### UStruct/UClass Methods

```lua
cls:find_function(name)  -- Find UFunction by short name
cls:get_child()          -- First child field
cls:get_fname()          -- FName
```

### UObject Memory Layout

```
Offset 0x00: VTable pointer (8 bytes)
Offset 0x08: ObjectFlags + InternalIndex (8 bytes)
Offset 0x10: ClassPrivate pointer (8 bytes)
Offset 0x18: NamePrivate (8 bytes)
Offset 0x20: OuterPrivate pointer (8 bytes)
```

Use `mcp.read_ptr(address + 0x20)` to walk the Outer chain when API doesn't expose it.

## Testing Workflow

### Prerequisites
- OpenXR Simulator: `E:\Github\OpenXR-Simulator\bin\openxr_simulator.dll`
- Active runtime: `C:\Users\ellio\AppData\Local\openxr\1\active_runtime.json` must point to simulator
- UEVR: `C:\Users\ellio\OneDrive\Documents\UEVR`
- UEVR must be in **OpenXR** mode (not OpenVR)

### UEVR OpenXR/OpenVR Config

Config at `C:\Users\ellio\AppData\Local\praydog\UEVRInjector_Path_*\1.0.0.0\user.config`:
```xml
<setting name="OpenXRRadio" serializeAs="String"><value>True</value></setting>
<setting name="OpenVRRadio" serializeAs="String"><value>False</value></setting>
```

### UEVR Plugin Deployment

Copy `uevr_mcp.dll` to game-specific plugin dir:
`C:\Users\ellio\AppData\Roaming\UnrealVRMod\<ExeName>\plugins\`

Example: `C:\Users\ellio\AppData\Roaming\UnrealVRMod\VOIDBREAKER-Win64-Shipping\plugins\uevr_mcp.dll`

### Launch Sequence

1. Build OpenXR Simulator: `cd E:/Github/OpenXR-Simulator/build && cmake --build . --config Release`
2. Clean logs: `rm -f E:/Github/OpenXR-Simulator/bin/openxr_simulator.log E:/Github/OpenXR-Simulator/bin/runtime_status.json`
3. Launch game:
   - Steam game: `cmd.exe //c "start steam://rungameid/<appid>"`
   - Standalone: run exe directly
4. Wait for game to load (~20-30s, memory > 2GB)
5. Launch UEVR: `C:/Users/ellio/OneDrive/Documents/UEVR/UEVRInjector.exe`
6. User injects via UEVR GUI (select process, click Inject)
7. Monitor: `curl -s http://localhost:8899/api/status`
8. Monitor OpenXR: check `E:/Github/OpenXR-Simulator/bin/runtime_status.json`

### D3D12 + Steam Overlay Crash Fix

**Problem**: `EXCEPTION_STACK_OVERFLOW` — Steam's `gameoverlayrenderer64.dll` and UEVR both hook `IDXGISwapChain::Present`, infinite recursion.

**Fix**: OpenXR Simulator uses GDI-based rendering (`StretchDIBits`) instead of DXGI `Present` for D3D12 preview. No swapchain created, no Present called, no hook conflicts.

**Note**: Disabling Steam overlay in settings does NOT unload the DLL or remove hooks. Must avoid calling `Present` entirely.

## Navigating Game Menus Programmatically

UEVR captures mouse/keyboard for VR view control, so direct input injection often doesn't reach UMG widgets. Instead, invoke button click handlers via ProcessEvent.

### Step 1: Find Button Event Handlers

```bash
# Search for bound event functions on a widget class
curl -s "http://localhost:8899/api/explorer/search?query=WBP_PlayMenu.WBP_PlayMenu_C.BndEvt&limit=20"
```

Handler names follow pattern: `BndEvt__<Widget>_BTN_<Name>_K2Node_ComponentBoundEvent_<N>_CommonButtonBaseClicked__DelegateSignature`

### Step 2: Find Live Widget Instance Address

The object search often only finds CDO (class default objects) and children, not the live widget instance. To find the live instance:

1. Find a child object in the `/Engine/Transient.*` path (live objects are under Transient)
2. Walk the Outer chain using `mcp.read_ptr`:

```lua
-- Lua: walk Outer chain from a known child address
local child_addr = 0x14546161E70  -- known child WidgetTree address
local outer1 = mcp.read_ptr(child_addr + 0x20)  -- BTN widget
local outer2 = mcp.read_ptr(outer1 + 0x20)      -- WidgetTree of parent
local outer3 = mcp.read_ptr(outer2 + 0x20)      -- The menu widget we want
print('Menu addr: 0x' .. string.format('%X', outer3))
```

3. Verify with HTTP: `GET /api/explorer/object?address=0x<addr>&depth=0`

### Step 3: Invoke the Click Handler

```bash
curl -s -X POST http://localhost:8899/api/explorer/method \
  -H "Content-Type: application/json" \
  -d '{"address":"0x<LIVE_WIDGET_ADDR>","methodName":"BndEvt__WBP_PlayMenu_BTN_Continue_K2Node_ComponentBoundEvent_4_CommonButtonBaseClicked__DelegateSignature"}'
```

### Step 4: Verify Level Change

```bash
curl -s http://localhost:8899/api/explorer/singletons | grep "World /Game"
```

### VOIDBREAKER Specific

- Steam App ID: 2615540
- Menu level: `LV_LimaMainMenu`
- Tutorial level: `LV_00_Tutorial_02`
- GameInstance: `GI_LimaGameInstance_C`
- Gameplay GameMode: `GM_LimaGameMode_C`
- Player character: `CH_LimaCharacter_C`
- Menu widget hierarchy: `VB_RootPlayerWidget_C` > `WBP_LimaMainMenu_C` > `WBP_PlayMenu_C`
- Buttons in PlayMenu: BTN_NewGame, BTN_Continue, BTN_Settings, BTN_QuitGame, BTN_Credits, BTN_Community, BTN_Survey

### Console Commands (may not work for level loading in all games)

```bash
# Execute console command
curl -s -X POST http://localhost:8899/api/console/command \
  -H "Content-Type: application/json" \
  -d '{"command":"open /Game/Path/To/Level"}'
```

Note: `open` returns success even if the map doesn't exist. For games with complex menu/save systems, prefer clicking UI buttons programmatically.
