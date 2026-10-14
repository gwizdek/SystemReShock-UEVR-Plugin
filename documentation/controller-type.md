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

UEVR feeds the VR controllers to the game as an XInput gamepad, so the game switches to gamepad
mode at the first button press and back to keyboard and mouse mode at the first mouse click
the plugin sends through `SendInput` for the menus and the MFD. The plugin leaves that alone.

Gamepad mode has one effect on play that does not work in VR: `ShouldFocusOnInteract` on
`INTERACT_Focusable_Base`, overridden by `INTERACT_Keypad` and `PUZZLE_Base`, returns
`IsUsingGamepad() OR the "focus on puzzles" setting`, and a true result locks the camera onto
a keypad, a vending machine or a puzzle. `SystemShockVR\focus_interaction_patch.cpp` makes the
three functions always return false by patching their bytecode in memory: the first
instruction becomes a jump to a `Result = false` that a return follows. The keypad and puzzle
scripts end with such an epilogue; the base class has it as its "already channeling" branch. The
functions are only called from other Blueprint functions, which a UFunction hook does not see,
so the patch is the only way in. It is checked again every few seconds in case a class was
loaded anew. The "focus on puzzles" option therefore has no effect in VR either.

While the game is in keyboard and mouse mode, a placeholder such as `{Real_Interact}` in a
tutorial popup would show the keyboard binding, the right mouse button from the mouse atlas,
instead of a gamepad icon. So the plugin lies to the key widgets inside texts: `SystemShockVR\button_legend_mode.cpp` hooks
`GetDecoratorSizeFromPayload`, `Construct` and `PreConstruct` of `WIDGET_ButtonLegend_KeyComposite`
and `WIDGET_ButtonLegend_Key`, writes 1 into the field before each call and the old value back
after it. Those are the calls during which the widgets read `ActiveControllerType`: the text
mesh calls the first, and `Construct` runs the widget's initialize function through an
internal Blueprint call. Each call runs on the game thread and resolves the key at once, so
nothing else sees the gamepad value and no change event is broadcast. Only widgets created by
a `TextMeshWidget` are affected; they have the game instance as outer, while menu legends keep
their key widgets in a widget tree. A rebuild of the text creates the widgets anew and runs
the hooked functions again, which is why the hook is needed instead of setting the mode on a
widget once.

UEVR's UFunction hook replaces the function's native pointer, which the engine only uses when
it enters the function through `ProcessEvent`: native code, delegates, input events, interface
calls from native code. A Blueprint function calling another Blueprint function runs the callee
directly, so a hook on the callee never fires. Hook the event or function that native code
calls, not the helper it calls in turn.
