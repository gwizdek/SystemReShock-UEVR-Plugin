# Disabling rows on the VR options page

A row on the VR options page (`_OPTION_VR_Toggle`, `_OPTION_VR_Slider`) can be disabled. A
disabled row is greyed out and the controller cannot reach it. The mouse can still drag a disabled
slider. This document explains how to disable a row and what a disabled row still lets through.
For the page itself, see `vr-options-menu.md`.

## How to disable a row

Call the game's `SetOptionEnabled(bool IsOptionEnabled, bool& Result)` on the row. Pass `false`
to disable it and `true` to enable it again. `Result` returns the value that was passed in, so it
carries no information.

The mod's rows do not override this function. They use the game's version:

| Row | Game parent that implements it | What it does |
|---|---|---|
| `_OPTION_VR_Toggle` | `WIDGET_Settings_BinaryToggle` | Calls the `OPTION_Base` version, then `SetIsEnabled` on its `WIDGET_Checkbox`. |
| `_OPTION_VR_Slider` | `OPTION_Base` (`WIDGET_Settings_Slider` has no own version) | `SetIsEnabled` on the row widget. |

### From a Blueprint

The function is on the dummy parents in the Unreal project, so any mod Blueprint that holds a row
can call it. For example, `_WIDGET_OptionsMenu_VRList` could disable the Angle and Deadzone rows
while Snap Turn is off.

### From the plugin

The BridgeSDK headers of the mod's rows do not list `SetOptionEnabled`. The generator only writes
the functions that the mod class defines or overrides. Call it through the Dumper-7 SDK parent class instead.
The VR rows derive from it:

```cpp
bool result = false;
if (auto* row = list->OPTION_VR_SnapTurn()) row->SetOptionEnabled(false, &result);        // UWIDGET_Settings_BinaryToggle_C
if (auto* row = list->OPTION_VR_SnapTurnAngle()) row->SetOptionEnabled(false, &result);   // UOPTION_Base_C
```

The plugin does not do this yet. The call has been tested only through the UEVR MCP server (see
below), not from plugin code.

### For a quick test in the running game

With the `uevr-mcp` skill:

1. Find the row. `uevr_search_objects` with a path part such as
   `WIDGET_MainMenu_InGame.WidgetTree.WIDGET_OptionsScreen.WidgetTree._WIDGET_OptionsMenu_VR_C`
   gives the pause menu's page and its name, for example `_WIDGET_OptionsMenu_VR_C_2147478181`.
   Then search for `<page name>.WidgetTree._WIDGET_OptionsMenu_VRList.WidgetTree.OPTION_VR_` to get
   the rows. A search for the row name alone returns the title screen's copy first.
2. `uevr_invoke_method` with method `SetOptionEnabled` and args `{"IsOptionEnabled": false}`.
3. `uevr_read_field` on `bIsEnabled` confirms the change.

## What a disabled row does

Tested in the game on the pause menu's page:

| | Toggle row | Slider row |
|---|---|---|
| Greyed out | Yes | Yes |
| Controller can move onto it | No, up and down skip it | No, up and down skip it |
| Controller can change it | No | No |
| Mouse can change it | No | **Yes**, the handle can still be dragged |

Up and down skip the row because the game's list (`WIDGET_MenuListBase.ReceiveNavUp` and
`ReceiveNavDown`) passes over items whose `bIsEnabled` is false. The row's own `ReceiveNavLeft`,
`ReceiveNavRight` and `ReceiveNavAccept` also check `bIsEnabled`.

## Restrictions

**The mouse can still drag a disabled slider.** The game's slider control `WIDGET_Slider` handles
the mouse in `EVENT_OnMouseDown` and `EVENT_OnMouseMove`. Neither checks whether the widget is
enabled, and UE4 still sends these events to a disabled widget. Setting `WIDGET_Slider` to
`HitTestInvisible` did not stop the drag either. The game never disables its own sliders, so it
never needed a fix. The mod targets controllers, so this is accepted and not fixed.

**A drag on a disabled slider can be saved.** The drag changes the value, so the row becomes dirty.
Apply (`ReceiveNavAlt1` on the list) applies every dirty row and does not check whether the row is
enabled. The new value then reaches the ini through the plugin's settings sync.

**Reset changes disabled rows.** Reset (`ReceiveNavAlt2` on the list) calls `SelectDefaultValue` on
every row. It does not skip disabled rows.

**The state is not stored anywhere.** A row starts enabled every time a page is created. The
plugin creates a new page for each options screen: one for the title screen, and one for the pause
menu each time a level loads (see "Plugin trigger" in `vr-options-menu.md`). The title screen's
page and the pause menu's page are separate objects, and disabling a row on one does not change the
other. To keep a row disabled, set the state each time a page is installed or adopted, for example
in `VROptionsSync::push` and `VROptionsSync::adopt`.
