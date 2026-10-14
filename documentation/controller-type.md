# How the game decides the active controller type

The game keeps one value that says which kind of controller the player is using. Menus, the
HUD and the button icons in texts read it to choose between keyboard key caps, mouse buttons
and gamepad icons. This page explains where the value lives, what changes it, who reads it,
and what the plugin does to it in VR.

## The value

`ActiveControllerType` is a variable of the player controller `CON_Hacker`
(`/Game/Blueprints/Characters/Hacker/CON_Hacker`). Its type is the Blueprint enum
`ENUM_ControllerType` with three values:

| Value | Meaning | Action name prefix |
|---|---|---|
| 0 | Keyboard and mouse | none, for example `Real_Interact` |
| 1 | Gamepad | `Gamepad_`, for example `Gamepad_Real_Interact` |
| 2 | JCMS: a Nintendo Switch Joy-Con used as a mouse | `JCMS_`, for example `JCMS_Real_Interact` |

The prefixes come from `FUNCLIB_GameSettings` (`GetGamepadInputActionPrefix`,
`GetJCMSInputActionPrefix`). Every input action exists once per controller type under these
names, and the key bound to an action is looked up by the prefixed name.

Two Boolean variables of `CON_Hacker` feed the value:

- `WasUsingGamepad`: true after the last key the player pressed was a gamepad key.
- `WasJoyConMouseEnabled`: true while the Joy-Con mouse sensor is preferred. Only set on the
  Switch build; on PC it is false from `InitializeJoyConMouseMode` on.

## What changes it

`UpdateControllerMode` on `CON_Hacker` computes the value from the two Booleans and
broadcasts `OnActiveControllerTypeChanged` when it changed:

```
if not WasUsingGamepad:        ActiveControllerType = 0   (keyboard and mouse)
else if not WasJoyConMouseEnabled: ActiveControllerType = 1   (gamepad)
else:                          ActiveControllerType = 2   (JCMS)
```

Three things lead to that function:

1. **Any key press.** `CON_Hacker` has an input event for the key `AnyKey`. Its handler computes
   `Key.IsGamepadKey() OR COMP_JCMS.ShouldPreferJoyConMouseSensor()` and passes the result to
   `SetIsUsingGamepad`. So a gamepad button or stick sets gamepad mode, and a keyboard key or a
   mouse button sets keyboard mode. Mouse movement alone is not a key and changes nothing.
2. **`SetIsUsingGamepad(State)`.** Stores `WasUsingGamepad` when it differs from the current
   value, broadcasts `OnUsingGamepadChanged`, then calls `UpdateControllerMode`. A call with the
   value that is already set does nothing.
3. **Joy-Con mouse state.** `COMP_JCMS` raises `OnJoyConMouseStateChange`; the handler stores
   `WasJoyConMouseEnabled`, sets the console variable
   `npad.JCMSControllerBackButtonsAreMiceButtons` and calls `UpdateControllerMode`.

At start, `InitializeIsUsingGamepad` sets `WasUsingGamepad` to true on consoles only. On PC it
starts false, so the game begins in keyboard and mouse mode until a gamepad key is pressed.

## Who reads it

Widgets read `ActiveControllerType` from the player controller and bind to
`OnActiveControllerTypeChanged` to refresh. These classes do, per the SDK:

- `WIDGET_ButtonLegend_Key` and `WIDGET_ButtonLegend_KeyComposite`: the button icons in texts
  and legends. They copy the value into their own `ControllerMode`, pick the action name with
  the matching prefix, look up its key and draw a key cap, a mouse button or a gamepad atlas
  cell. `tutorial-popups.md` describes that chain.
- `WIDGET_PlayerHUD`, `WIDGET_SimpleHUD`, `WIDGET_PseudospaceHUD`, `WIDGET_GameOverScreen`,
  `WIDGET_DifficultyConfigScreen`, `WIDGET_SplashScreen_Title` and `COMP_Scanner`.

`OnUsingGamepadChanged` is a second, older signal with only the gamepad yes or no; some of the
same classes bind to it.

## What the plugin does in VR

UEVR feeds the VR controllers to the game as an XInput gamepad, so every button press would
set gamepad mode. The plugin undoes that: `SystemShockVR\plugin.cpp` calls
`SetIsUsingGamepad(false)` on every input tick in `handle_xinput` (focusable interactions),
`handle_citadel_station_xinput` (normal play) and `handle_mfd_interactions` (the MFD). The
game therefore stays in keyboard and mouse mode in VR, as a live read of
`ActiveControllerType` confirms (value 0). The reason is that the game plays differently in
gamepad mode. For example, gamepad mode forces the focusable interaction with keypads and
vending machines, where the camera locks onto the device, which does not work in VR. The
plugin also drives the menus and the MFD with a mouse cursor and mouse clicks sent through
`SendInput`, which fits keyboard and mouse mode.

The visible result in the tutorial popups: a placeholder such as `{Real_Interact}` shows the
keyboard binding, the right mouse button from the mouse atlas, instead of a gamepad icon.
Showing the VR controller icons from `T_VRButtonLayout.png` in those texts needs gamepad mode
for the key widgets, or a plugin hook that draws the gamepad atlas in keyboard mode too.
Switching the whole game to gamepad mode would also change how the menus take input, so the
two must be weighed together.
