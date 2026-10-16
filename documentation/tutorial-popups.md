# Tutorial popups

The game shows short help texts in a framed popup on the HUD, for example
`Press [A] to push the button.` with the button drawn as an icon. This page explains where
the texts come from, how the button icons get into them, and how the mod replaces both
with VR versions.

## Where the texts come from

All popup texts are rows of the data table
`/Game/Blueprints/Interactables/Triggers/DT_Tutorials` (76 rows, struct
`STRUCT_TutorialData`, one `FText` field `DisplayMessage`). The row name says what the popup
is about, for example `DoorInteract`, `OutOfAmmo` or `InspectNavUnit`. The English locres
has no entry for these texts, so the source string in the asset is what the player sees.

The player pawn `PAWN_Hacker_Simple` keeps the active tutorials. `GetTutorialMessage` looks a
row up by name and returns its text. `WIDGET_TutorialMessage` on the player HUD shows the
text of the highest priority tutorial in a `TextMeshWidget` and draws a line to the actor the
tutorial belongs to. Tutorial volumes (`VOLUME_Tutorial`) and timed tutorials name the rows
they show.

`profile\tutorial_messages.ini` holds every row as `RowName = text`. It was first written by
`scripts\export-tutorial-texts.py`, which reads the cooked table from `dumps\`. The texts were
then rewritten for the VR controls and gestures in `README.md`: grabbing instead of the
interact button, the wrist gesture for the Neural Interface, the item selector on the right
thumb, and so on. Edit the text after `=`; keep the row name.

A VR button that the game reads through its own action keeps the game's placeholder, for
example `{Real_Interact}` for B or `{Real_Aim}` for the left trigger; the icon follows a
rebind in the options menu, as it should. A VR button that the plugin reads itself from the
XInput state (both grips, the right thumb for the item selector, the right trigger for the
laser pointer) uses one of the fixed placeholders below. The pointing hand pose has the
placeholder `{VR_HandPoint}`; the grip pose has none yet and the texts describe it in words.

## Button placeholders

A text names a button with a placeholder in braces. The `TextMeshWidget` replaces each
placeholder with a `WIDGET_ButtonLegend_KeyComposite`, which draws the icon of the key that the
named input action is bound to for the active controller type. The controller types are
keyboard and mouse (0), gamepad (1) and a third scheme the game calls JCMS (2).

| Placeholder | Meaning |
|---|---|
| `{Real_Interact}` | One action name. The widget uses it for the keyboard and adds the prefixes itself for the gamepad (`Gamepad_Real_Interact`) and JCMS (`JCMS_Real_Interact`). This is the usual form. |
| `{Real_Reload,Gamepad_Real_Interact,JCMS_Real_Reload}` | Three action names, one per controller type in the order keyboard, gamepad, JCMS. Used when the gamepad action differs. |
| `{Locked_ZoomAxis,Gamepad_Real_HotbarCyclePrevious:Gamepad_Real_HotbarCycleNext,...}` | A token with `:` names two keys for one controller type. The widget shows both icons with a separator. |
| `{VR_LeftGrip}`, `{VR_RightGrip}`, `{VR_LeftThumb}`, `{VR_RightThumb}`, `{VR_RightTrigger}`, `{VR_HandPoint}` | Fixed VR buttons and the pointing hand, registered by the plugin, see below. Same single-name form; the widget adds the prefixes. |

The action names used by the game's texts: `Real_Interact`, `Real_PrimaryAttack`,
`Real_ToggleMFD`, `Real_Crouch`, `Real_Reload`, `Real_ModeNext`, `Real_AcquireTarget`,
`Real_Sprint`, `Real_Jump`, `Real_HotbarCyclePrevious`, `Real_HotbarCycleNext` and the axis
`Locked_ZoomAxis`. The VR texts in the ini also use `Real_Aim`.

### Fixed VR placeholders

`FUNCLIB_GameSettings::GetBoundKeyForCurrentUser` resolves a placeholder name in two steps.
It strips the `Gamepad_` or `JCMS_` prefix and checks whether the rest starts with `Real_`,
`Cyber_` or `Minigame_`. If so, it reads the key from the player's bindings in the settings
save, which the options menu edits. Any other name goes to the engine's `UInputSettings`
action mappings, indexed by rank (primary or secondary), and those the player cannot change.

`SystemShockVR\vr_input_actions.cpp` uses this. On the first engine tick it adds one action
mapping per VR button the plugin handles itself, under the plain name and under the
`Gamepad_` and `JCMS_` prefixes that the composite widget adds for the other controller
types. The key is the gamepad key UEVR sends for that button:

| Placeholder | Key | Used for |
|---|---|---|
| `{VR_LeftGrip}` | `Gamepad_LeftShoulder` | grab, pointing pose, Access Card, flashlight gesture |
| `{VR_RightGrip}` | `Gamepad_RightShoulder` | grab, MFD gesture, holster, MFD context menu |
| `{VR_LeftThumb}` | `Gamepad_LeftThumbstick` | recenter VR (over the left shoulder) |
| `{VR_RightThumb}` | `Gamepad_RightThumbstick` | item selector |
| `{VR_RightTrigger}` | `Gamepad_RightTrigger` | laser pointer with an empty hand, MFD select |
| `{VR_HandPoint}` | `Gamepad_RightStick_Up` | the pointing hand pose (no button) |

The mappings are lookup entries only; no input event is bound to them. A mapping is skipped
when its name exists already, so the hot loader can swap the plugin without adding duplicates.

`WIDGET_ButtonLegend_Key::UpdateLegend` picks the icon style by the key's own type
(`Key_IsKeyboardKey`, `Key_IsMouseButton`, `Key_IsGamepadKey`), not by the controller mode.
So these placeholders draw a gamepad icon even while the game is in keyboard and mouse mode,
which is the case while the MFD is open.

### The pointing hand

`{VR_HandPoint}` needs a gamepad key whose atlas cell is the pointing hand (cell 24).
`FUNCLIB_UserInterface::GetGamepadButtonAtlasIndex` picks the cell with one branch per key
and gives every other key -1, which draws no icon:

| Gamepad key | Cell |
|---|---|
| `Gamepad_FaceButton_Bottom`, `_Right`, `_Left`, `_Top` | 0, 1, 2, 3 |
| `Gamepad_Special_Left`, `Gamepad_Special_Right` | 4, 5 |
| `Gamepad_DPad_Up`, `_Down`, `_Left`, `_Right` | 6, turned by 0, 0.5, 0.25, 0.75 |
| `Gamepad_LeftTrigger`, `Gamepad_RightTrigger` | 8, 9 |
| `Gamepad_LeftShoulder`, `Gamepad_RightShoulder` | 10, 11 |
| `Gamepad_LeftX` or `Gamepad_LeftY`, `Gamepad_LeftThumbstick` | 12, 13 |
| `Gamepad_RightX` or `Gamepad_RightY`, `Gamepad_RightThumbstick` | 14, 15 |

On the Nintendo Switch the face buttons jump to four other branches at the end of the
function, which swap their cells. On PC that code never runs.
`SystemShockVR\vr_button_atlas_index_patch.cpp` copies the `Gamepad_RightThumbstick` branch
over the start of that code, changes its key to `Gamepad_RightStick_Up` and its cell to 24,
and moves the "-1" default behind it. It fills the rest of the Switch code with `EX_Nothing`.
`Gamepad_RightStick_Up` is a registered gamepad key that no other branch handles. The engine
has no hand pose keys in this build: `OculusTouch_Right_IndexPointing` is not registered and
the `MotionController_` keys are not gamepad keys. The log line
`[vr_button_atlas_index_patch][patch]` confirms the patch.

## How a key becomes an icon

`WIDGET_ButtonLegend_Key` draws one key. For a keyboard key it shows the key name on a key
cap from `INST_KeyboardButton`; for a mouse button it uses `MAT_MouseButton`; for a gamepad key
it puts `MAT_PlatformButton` on its mesh with the platform's atlas as `ButtonTextureSheet`
(`T_XboxButtonLayout` on PC) and sets `ButtonIndex` to the cell of the key. The atlas is a
4 x 4 grid of 256 pixel cells; the material cuts one cell out with `ButtonIndex`, `ColCount`
and `RowCount`.

`UpdateLegend` also sets `PanelSize`, the size the widget reports to the text around it
through `GetDecoratorSizeFromPayload`: 38 x 38 for a gamepad key, 30 x 30 for a mouse button,
and for a keyboard key a width from `PanelSizeX` by `DefaultHeight` (25). The 38 and the 30 are
literals in the bytecode. `PanelSize` is only the space the key takes; the picture is
`MESH_KeyBackground`, centred in the key's canvas, and `TryUpdateLegendSize` sets its canvas
slot to another literal: 64 x 64, or 128 x 128 when the key shows text.

`icon_size` in the ini's `[popup]` section changes both. `SystemShockVR\legend_icon_size_patch.cpp`
finds the statements `Temp_float_Variable = 30.0` and `Temp_float_Variable_1 = 38.0` in the
loaded `UpdateLegend` and writes the ini value over the 38.0. It finds
`Temp_struct_Variable = {64, 64}` followed by `Temp_struct_Variable_1 = {128, 128}` in
`TryUpdateLegendSize` and writes 64 x `icon_size` / 38 over the 64s, so the picture grows with
its space. This changes every gamepad icon of every button legend, not only those in popups.
A mouse button keeps its 30 x 30 space but gets the larger picture. A legend key made before
the patch keeps its size until it updates again. The log lines
`[legend_icon_size_patch][patch_panel_size]` and `[legend_icon_size_patch][patch_picture_size]`
confirm the patch.

In VR the widget draws from the mod's atlas instead. `T_VRButtonLayout` in the Core pak is a
4 x 7 atlas with the same channels; its cells 0 to 15 follow the game's index function, so a
key picks the same cell as in the Xbox atlas, and that cell shows the VR controller button
that produces the key. `MI_VRButtonLayout`, an instance of `MAT_PlatformButton` in the Core
pak, sets the atlas and `RowCount` to 7. The widget keeps the material and the atlas in two
variables, `PlatformButtonMaterial` and `GamepadLayoutAtlas`, and loads the game's assets
into them only while they are unset. `SystemShockVR\vr_button_atlas.cpp` sets both on the
widget's class default object, so every legend key made afterwards starts with the VR
assets, and once on every legend key that exists already, including the templates inside
loaded widget trees. Live keys redraw through `UpdateMapping`. The plugin checks every few
seconds that the default object still holds the assets. `menu-icons.md` describes the atlas
and the generator assets; `tools\UEVRBridgeGen\Resources\MenuGen\draw_vr_button_icons.py`
lists the cells.

## Changing the texts

`SystemShockVR\tutorial_messages.cpp` applies `tutorial_messages.ini` from the UEVR profile
folder. On the first tick it reads the `[tutorials]` section, loads `DT_Tutorials`, roots
the table so every later reader gets that one object, and writes each ini text into the
`DisplayMessage` of the row with that name. The new text is made with the engine's string
to text conversion, so the popup widget finds the button placeholders in it as in the
game's own texts. Rows missing from the ini keep the game's text; a missing file leaves
every text as it is. The table is checked every few seconds and patched again when it is
a new object, which also covers a plugin swap by the hot loader. The log line
`[tutorial_messages][apply]` says how many rows were replaced. Row names are compared in
lower case, because the ini reader lower-cases keys. An ini value is one line, so a line
break in a text is written as the two characters `\n`; the plugin turns it into a newline.

The ini's `[popup]` section sizes the popup on the HUD: `width` and `height` of the text box
and `font_size`, all in screen units, applied when the plugin sets up the HUD. The game's box is 500 x 75 and the frame mesh
around it 576 x 160; the plugin keeps that difference, so the frame follows the box. Word
wrap is on, so a wider box gives longer lines and a taller box more rows. A missing section or
a value of 0 keeps the game's value. The game's font size is 20 with 5 units of extra line
spacing, so a row takes about 25 units at that size.

## How long a popup stays

`duration` in the `[popup]` section sets how many seconds a timed popup stays on the HUD.
`SystemShockVR\tutorial_popup_duration.cpp` applies it.

The game has two kinds of popups. A tutorial volume adds its rows with `AddVolumeTutorial`;
they have `Duration` 0 and stay until the player leaves the volume. Pickups, weapons, mod kits
and Power Stations call `PAWN_Hacker_Simple::ActivateTimedTutorial` with the literal 5.0 in
all six places that call it. That function adds an `STRUCT_TutorialInstance` with `Timestamp`
(the play time) and `Duration` to the pawn's `TutorialsToDisplay` array. A 1 second timer
calls `TryCompleteTimedTutorials`, which removes an entry once `Duration` is above 0 and the
play time since `Timestamp` has reached it. So a timed popup stays between 5 and 6 seconds.

The plugin reads `TutorialsToDisplay` every 30 ticks and sets `Duration` of each entry that
still holds 5.0 to the ini value. A changed entry no longer holds 5.0, so it is changed once,
and the plugin needs no state of its own; a new entry for the same row starts at 5.0 again.
The time counts from the entry's own `Timestamp`, so `duration = 10` keeps a popup for 10
seconds in total. A missing key, 0 or 5 leaves the game's duration. The log line
`[tutorial_popup_duration][read_ini]` shows the value in use.
