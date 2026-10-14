# Tutorial popups

The game shows short help texts in a framed popup on the HUD, for example
`Press [A] to push the button.` with the button drawn as an icon. This page explains where
the texts come from, how the button icons get into them, and which files of the mod hold the
VR versions. The VR versions are not applied in the game yet.

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

`profile\tutorial_messages.ini` holds every row as `RowName = text`. It was written by
`scripts\export-tutorial-texts.py`, which reads the cooked table from `dumps\`. The texts in
it are the game's own until someone edits them. Edit the text after `=`; keep the row name.

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

The action names used by the game's texts: `Real_Interact`, `Real_PrimaryAttack`,
`Real_ToggleMFD`, `Real_Crouch`, `Real_Reload`, `Real_ModeNext`, `Real_AcquireTarget`,
`Real_Sprint`, `Real_Jump`, `Real_HotbarCyclePrevious`, `Real_HotbarCycleNext` and the axis
`Locked_ZoomAxis`.

## How a key becomes an icon

`WIDGET_ButtonLegend_Key` draws one key. For a keyboard key it shows the key name on a key
cap from `INST_KeyboardButton`; for a mouse button it uses `MAT_MouseButton`; for a gamepad key
it puts `MAT_PlatformButton` on its mesh with the platform's atlas as `ButtonTextureSheet`
(`T_XboxButtonLayout` on PC) and sets `ButtonIndex` to the cell of the key. The atlas is a
4 x 4 grid of 256 pixel cells; the material cuts one cell out with `ButtonIndex`, `ColCount`
and `RowCount`. The HUD draws a gamepad icon 38 x 38 pixels.

The VR atlas `T_VRButtonLayout.png` follows the same layout and channels; `menu-icons.md`
describes it and `tools\UEVRBridgeGen\Resources\MenuGen\draw_vr_button_icons.py` lists its
cells. It is not loaded by the game yet. Showing VR icons in the popups needs two more
things: a texture and material instance for the atlas in the Core pak, and a way to pick a
cell for a VR control where the key widget picks a gamepad cell today.

## Changing the texts

The texts shown in VR come from `profile\tutorial_messages.ini` once the plugin applies the
file; that part is not written yet. The plan is to replace the `DisplayMessage` of each row
in the loaded table with the text from the ini, so every reader of the table, including
`GetTutorialMessage`, sees the VR text. Rows missing from the ini keep the game's text.
