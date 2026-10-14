# Menu icons

This page explains how to make an icon for the game's menus that looks like the game's own icons
and takes the player's colour theme. The VR category icon of the Options screen is made this way
and works in the game. Use it as the pattern for the next icon.

## How the game's icons are built

The six category icons of the Options screen follow one recipe. Other menu icons in the game use
the same style.

| Part | What the game does |
|---|---|
| Size | 256 x 256 pixels. The menu draws a category icon at 64 x 64. |
| Texture settings | Compression `TC_EditorIcon` (uncompressed BGRA8), texture group `TEXTUREGROUP_UI`, one mip. |
| Shape | A white silhouette on black. It fills the square to 4 to 8 pixels from the edge. Details are cut out as negative space: thick bars, stripes, dashed lines, round holes. |
| Corners | Chamfers (the Gameplay hexagon) and soft rounding (the monitor, the pages). |
| Subjects | Retro hardware: an arcade stick, a CRT monitor, a tape reel, stacked pages. |
| Packing | Three icons per texture, one per colour channel. Alpha is unused and always 255. |
| Colour | None in the texture. A material per icon colours the mask with the player's tint. |
| Material | UI domain, translucent. Colour = tint parameter `UIBackgroundTint1` of the game's collection `/Game/Blueprints/UI/Tinting/MPC_UserTintParameters`. Opacity = the icon's channel. |

The game's icon textures are in
`dumps\assets\SystemShock\Content\Art\UI\HUD\MainMenu\OptionsScreen\`:
`T_OptionsIcons_Gameplay-Controls-Interface` (red, green, blue) and
`T_OptionsIcons_Display-Graphics-Audio` (red, green, blue). Their materials are the
`MAT_OptionsIcons_<Name>` files next to them.

**Reading a game icon for reference.** No viewer is needed. In the cooked `.uexp` of these
textures the pixels start at byte 300: 256 x 256 pixels, 4 bytes each in the order B, G, R, A,
row by row from the top. Take one channel and write it as a grey PNG to see one icon. This is
useful to compare a new icon with the game's at the same size.

## The VR icon's files

| File | Role |
|---|---|
| `tools\UEVRBridgeGen\Resources\MenuGen\draw_vr_icon.py` | Draws the icon. Plain Python 3, no packages. |
| `tools\UEVRBridgeGen\Resources\MenuGen\T_OptionsIcons_VR.png` | The drawn icon, the generator's input. |
| `tools\UEVRBridgeGen\Source\UEVRBridgeGen\Private\MenuGen\MenuGenIcon.cpp` | Creates the texture, the material and the tint collection dummy in the Unreal project. |
| `MenuGenPageLogic.cpp`, function `InstallSetIcon` | Puts the material on the VR category item. |
| `/Game/Mods/UI/Options/T_OptionsIcons_VR` | The texture asset, chunk 10. |
| `/Game/Mods/UI/Options/MAT_OptionsIcons_VR` | The material asset, chunk 10. |
| `/Game/Blueprints/UI/Tinting/MPC_UserTintParameters` | The tint collection dummy, chunk 0, never shipped. |

## Making a new icon

### 1. Draw it

Copy `draw_vr_icon.py` and change the `shape` function. A shape is built from signed distances:
`sd_poly` for any polygon, `sd_circle` for a circle, `chamfer` for a rectangle with cut corners.
Combine them with `max` (add a part) and `min(a, 1 - coverage(...))` (cut a part out). The edges
get one pixel of anti-aliasing.

Any drawing tool works too. The PNG must follow these rules:

- 256 x 256, 8-bit RGBA, white shape on black, alpha 255 everywhere. The generator decodes the PNG
  to BGRA; RGBA input needs no colour conversion.
- The same value in R, G and B. The material reads R.
- Keep the shape's line width close to the game's: about 14 to 20 pixels at 256, which is 4 to 5
  pixels at the 64 pixel display size. Thinner lines disappear in the headset.
- Fill the square. A wide shape still needs height, or it looks smaller than its neighbours.

### 2. Compare it with the game's icons

Shrink the new icon and two game icons to 64 x 64, colour them with the tint (about RGB 60, 235,
140 on a dark green background is close to the default theme) and put them side by side. Check
that the line weight and the filled area look the same. A box filter of 4 x 4 pixels is enough
for the shrinking.

### 3. Add it to the generator

`MenuGenIcon.cpp` makes one icon today. Its two functions `MakeIconTexture` and
`MakeIconMaterial` take the asset names from `MenuGenPaths` in `MenuGenStore.h` (`IconTexture`,
`IconMaterial`, `IconSource`). For a second icon, give both functions the names and the PNG path
as parameters, call them once per icon from `MenuGenIcon::Generate`, and keep each material in
`FMenuGenStore` for the code that uses it. Name the assets like the game does:
`T_OptionsIcons_<Name>` and `MAT_OptionsIcons_<Name>`.

Do not change `MakeTintCollection`. Every icon material uses the same dummy collection.

### 4. Put it on the widget

- **A category item** of the Options screen. The item's `PreConstruct` shows
  `OptionCategoryIcon[ENUM_OptionCategories]`. Set the item's `OptionCategoryIcon` array to the
  new material before the item is added to the category list. Adding it to the live list builds
  the widget and runs `PreConstruct`, so a later change does not show. `InstallSetIcon` does this.
- **Any other `Image` widget.** Call `SetBrushFromMaterial` with the material, in the Blueprint or
  from the plugin. The plugin does this for the page background in `vr_options_menu.cpp`
  (`apply_panel_material`).

A material that a mod Blueprint references is cooked with it. A material that only the plugin
uses must be loaded by path from the plugin, as `create_page` loads the page class.

### 5. Build and test

1. Close the Unreal editor and run `.\tools\UEVRBridgeGen\GenerateMenu.ps1 -RebuildGen -Overwrite`.
   The log ends with `Done: N classes.` and must show no error.
2. Package the project, then deploy the Core pak with `.\scripts\build-and-deploy.ps1 -Target Paks`.
   The game must be closed; it locks the mounted pak.
3. In the game, the icon must have the same colour as the game's icons. Change the colour theme in
   the Interface options: the new icon must change with the others.

## HUD materials for VR

The generator also replaces HUD materials that UEVR drops in the headset: the email icon and
the cyberspace connection integrity widget. `documentation\hud-materials-in-vr.md` explains
the problem and those replacements. They are built with the same helpers as the icon here and
read the same tint collection dummy.
## VR controller button atlas

`tools\UEVRBridgeGen\Resources\MenuGen\draw_vr_button_icons.py` draws `T_VRButtonLayout.png`
next to it: an atlas of VR controller buttons in the style of the game's gamepad atlases
(`Art\UI\Icons\ControllerButtons\T_XboxButtonLayout` and the others). The game's tutorial
popups and button legends draw their button icons from such an atlas through
`MAT_PlatformButton`, which cuts one cell out of it with the parameters `ButtonIndex`,
`ColCount` and `RowCount`. The script needs `numpy` and `Pillow` and reads the Xbox atlas from
the asset dump under `dumps\`. With `--preview` it also writes `T_VRButtonLayout_preview.png`,
the cells tinted and scaled as the HUD shows them.

| Part | What the game's atlases do, and what the script copies |
|---|---|
| Grid | 4 x 4 cells of 256 x 256 pixels. The VR atlas has 4 x 6 cells, so its material instance must set `RowCount` to 6. |
| R | The rim of the button, its label and arrows. Drawn in the highlight tint. The rim is about 6.5 pixels wide at the sides and thicker at the bottom of a round button. |
| G | The face of the button. Drawn in the background tint. |
| B and A | A soft glow around the shape, about 37 pixels wide. B is 255 where the glow is, A is its strength. |
| A | 255 inside the shape. |
| Labels | 28 pixel letters. The script cuts `L`, `T` and `R` out of the Xbox atlas and draws a matching `G`. |

The face buttons `A`, `B`, `X`, `Y`, the menu button and the plain and pressed sticks are
copied pixel for pixel from the Xbox atlas. The pointing hand is a hand-edited cell,
`T_VRButtonLayout_HandPoint.png` next to the script. The triggers and grips are outlines traced
from a reference sheet: `trace_button_shapes.py` segments a cell of the sheet, traces it with
`potrace` (`scoop install potrace`) and writes the outline as points to `vr_button_shapes.json`,
which the drawing script reads; LT is RT mirrored. The stick directions and the grip pose are
drawn from signed distance fields. The docstring of the script lists the cells and
their `ButtonIndex`. The atlas is not yet used by the game; wiring it to the tutorial texts is
separate work.

## The tint collection

The game sets the player's theme colours in `MPC_UserTintParameters` at run time. It has 19 colour
parameters and no scalar parameters. The ones for menus are `UIBackgroundTint0`,
`UIBackgroundTint1`, `UIHighlightTint0` and `UIHighlightTint1`; the rest are map icon colours.
The themes are rows of `/Game/Blueprints/UI/Tinting/DT_UserTintOptions`. In the default theme
`UIBackgroundTint1` is (0, 1, 0.23) in linear colour, which shows as about RGB (0, 250, 129).

A mod material can read this collection only through the dummy, and only because the dummy
matches the game's collection exactly. A material that reads a collection is compiled against the
order of its parameters and records the collection's `StateId`. In the game the reference resolves
to the real collection, and the material gets the live colours only when the `StateId` is the
same. The dummy therefore copies the `StateId`, all 19 parameters in the game's order and the `Id`
of each parameter. `MenuGenIcon.cpp` holds these values; they were read from the cooked asset in
`dumps\assets\SystemShock\Content\Blueprints\UI\Tinting\`.

## Mistakes to avoid

- **Editing the dummy collection in the editor.** Any change gives it a new `StateId`. Every mod
  material compiled after that gets no tint in the game. Run the generator with `-Overwrite` to
  restore it, then regenerate the materials.
- **Putting the icon in the alpha channel.** The game's icons leave alpha at 255, and the
  generator's material reads R.
- **Setting the item's icon after it is added.** `PreConstruct` has already run; the item keeps
  the old icon.
- **Using the Gameplay icon's material with a new texture.** The game's icon materials have no
  texture parameter; the texture is fixed in each material. A new icon needs its own material.
- **Copying the game's tint function.** `UserTintBackground` is cooked empty and cannot be
  referenced from a mod material. The icon colour is the plain tint parameter, so the function is
  not needed.
