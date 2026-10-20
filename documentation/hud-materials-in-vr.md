# HUD elements that show on the desktop but not in the headset

Some parts of the game's HUD are drawn on the desktop window but are missing in the HMD. The
cause is the blend mode of the material that draws them. The fix is a replacement material in
the Core pak. This page explains the problem, how to find which material is at fault, and how
to add a replacement with the generator. The replacements that exist today are listed at the
end.

## The cause

UEVR draws the game's flat HUD into a texture and composites that texture onto its UI quad by
alpha. The game's HUD widgets (`GridMeshWidget`, `TextMeshWidget`) draw with materials. A
material with the **Additive** blend mode writes colour but no alpha, so its pixels have alpha
0 in UEVR's texture and are dropped. The desktop window shows them because the game's own
backbuffer ignores alpha. Materials with the **Translucent** or **AlphaComposite** blend mode
write alpha and show in both places.

Changing the blend mode of the loaded material at run time does not help: the compiled shader
still writes alpha 0. The shader must be built for a translucent material, so the material has
to be replaced.

## How to find the material

1. Start the game with UEVR and the MCP plugin (see `.claude/skills/uevr-mcp/SKILL.md`).
2. Find the widget: `uevr_search_objects` with the widget's name, for example
   `WIDGET_ConnectionIntegrity`. Live instances live under `/Engine/Transient`.
3. For each mesh widget in it, read `Materials` with `uevr_read_field`. Then read `BlendMode`
   on each material. The values: 0 Opaque, 1 Masked, 2 Translucent, 3 Additive, 4 Modulate,
   5 AlphaComposite. Every material with value 3 is invisible in the headset.
4. Read `CachedExpressionData` on the material. `ReferencedTextures` lists its textures and
   `Parameters.ScalarValues` / `VectorValues` tell how many parameters the widget sets on it.
5. The parameter names are in the widget's Blueprint. Export its bytecode with
   `scripts\export-bytecode.ps1 <WidgetName>` and look for `SetScalarParameterValue` calls and
   the `NameConst` values next to them.
6. Look at the textures. `tools\UEVRBridgeGen\Resources\MenuGen\export-cooked-texture.ps1`
   writes a cooked BGRA8 texture from `dumps\` as a PNG. Check which channel holds what, and
   whether the alpha channel is a shape or just 255 everywhere.

To see what the headset shows without putting it on, capture the Mixed Reality Portal window
(`PrintWindow` from PowerShell works). `uevr_screenshot` shows only the desktop view.

## How the fix works

The generator (`tools\UEVRBridgeGen`, run with `GenerateMenu.ps1`) writes a translucent UI
material at the **game's own asset path** and marks it for chunk 10. The Core pak mounts
above the game's pak, so the game loads the mod's material instead of its own, and the game's
widget draws with it unchanged. The plugin does nothing for the drawing.

The material's textures are written at the game's paths too. Two choices:

- **Chunk 0, never shipped.** The cooked material refers to the path, and in the game the
  path resolves to the game's own texture. Use this when the texture is not changed. The
  cyberspace widget's textures work this way.
- **Chunk 10, shipped.** The mod's copy replaces the game's texture. Use this when the
  texture itself is changed. The email icon's texture works this way: its glow is reduced.

Rules for the replacement material, all applied by the helpers in `MenuGenMaterial.h`:

- UI domain, Translucent blend. `NewUiMaterial` sets both.
- Multiply colour and opacity by the vertex colour and vertex alpha
  (`ConnectThroughVertexColor`). The game's mesh widgets pass their `Color` as the vertex
  colour, so the game keeps its tints and fades.
- Keep the game's parameter names and their meaning, so the widget's Blueprint keeps working.
  The defaults matter: values set on a material instance after the mesh was first drawn did
  not show in tests, while values set before the first draw did.
- When the texture's alpha is 255 everywhere, take the opacity from the brightest colour
  channel. An additive material never needed alpha; a translucent one does.
- When the material does maths on the texture coordinates, take `frac` of them first. The
  game's `GridMeshWidget` passes V from -1 to 0. A plain sample does not notice because the
  texture wraps; a frame offset for a flipbook does.
- A vector from the tint collection is a float4. Mask it to RGB before multiplying it with
  the float3 vertex colour, or the shader does not compile.

Each replacement is a small function in a generator module: `MenuGenHudIcon.cpp` for the email
icon, `MenuGenCyberHud.cpp` for the cyberspace widget. A new one follows the same shape: add
the asset paths and the PNG path to `MenuGenPaths` in `MenuGenStore.h`, write the texture with
`MakeTexture`, build the material with the helpers, and call the module from
`VROptionsMenuGenCommandlet.cpp`. The generator is a unity build, so every file-local function
name must be unique across the `MenuGen` folder.

## Build and test

1. Close the Unreal editor. Run `.\tools\UEVRBridgeGen\GenerateMenu.ps1 -RebuildGen`. Assets
   that exist are kept; delete an asset in the Unreal project to make it again.
2. Package the project from the editor, or from PowerShell with the editor closed (one line):

   ```powershell
   & "D:\Unreal Engine\UE_4.27\Engine\Binaries\DotNET\AutomationTool.exe" BuildCookRun -nocompileeditor -installed -nop4 -project="D:/Unreal Engine/Projects/SystemReShock-UE4-Project/SystemShock.uproject" -cook -stage -archive -archivedirectory="D:/Unreal Engine/Projects/SystemReShock-UE4-Project" -package -ue4exe="D:\Unreal Engine\UE_4.27\Engine\Binaries\Win64\UE4Editor-Cmd.exe" -compressed -ddc=InstalledDerivedDataBackendGraph -pak -prereqs -nodebuginfo -manifests -targetplatform=Win64 -build -clientconfig=Shipping -utf8output
   ```

   The paths are the ones in `tools\UEVRBridgeGen\bridgegen.config.json`. A full cook takes
   about ten minutes; a cook after a small change about one. The cook log must not say
   `Failed to compile Material` for the new material; the error text is on the next line.
3. Close the game and run `.\scripts\build-and-deploy.ps1 -Target Paks`.
4. Start the game. The pak hot reload cannot replace these materials: the HUD loads them at
   start and keeps them, so every change needs a restart.
5. Compare the desktop window with the Mixed Reality Portal preview.

A diagnostic material helps when the result is wrong and the reason is not clear: colour =
(U, V, parameter), opacity 1. One screenshot then shows what the shader receives. That is how
the V range of the mesh widgets was found.

Do not call `SetMaterial` with a material instance on a game mesh widget through the MCP tools;
it crashed the game. `SetMaterial` with a plain material worked.

## The email icon

The HUD's unread media (email) icon is drawn by `WIDGET_UnreadMediaIcon` with
`MAT_MediaIcon_UnreadMessages`, an additive material. The game also pins the icon to the left
screen edge, outside the headset view, so the plugin moves its slot to the top centre of the
HUD, just below the compass (`VRBody::initialize_unread_media_icon` in `vr_body.cpp`).

| File | Role |
|---|---|
| `tools\UEVRBridgeGen\Resources\MenuGen\make_media_icon.ps1` | Writes the PNG below from the game's cooked `T_MediaIcon_UnreadMessages.uexp` in `dumps\` (104 x 86 BGRA8 pixels from byte 326). It reduces the glow outside the envelope to a tenth, so the icon does not show as a box. |
| `tools\UEVRBridgeGen\Resources\MenuGen\T_MediaIcon_UnreadMessages_VR.png` | The script's output, the generator's input. |
| `MenuGenHudIcon.cpp` | Creates the texture and the material. |
| `/Game/Art/UI/HUD/Media/T_MediaIcon_UnreadMessages` | The texture, chunk 10. Replaces the game's. |
| `/Game/Art/UI/HUD/Media/MAT_MediaIcon_UnreadMessages` | The material, chunk 10. Replaces the game's. |

**The texture's channels.** R is the crisp outline. G is a soft fill inside the envelope, with
a faint rest of the game's glow outside it. B is empty. Alpha is like G and is not used.

**The material.** Colour = `(R * OutlineColor + G * FillColor)` times the vertex colour.
Opacity = `(R + G * FillOpacity)` times the vertex alpha. The parameters and their defaults,
in linear colour, tuned in the running game against the game's additive icon:

| Parameter | Type | Default |
|---|---|---|
| `Icon` | texture | the texture above |
| `OutlineColor` | colour | (1.0, 0.38, 0.04) orange |
| `FillColor` | colour | (0.12, 0.008, 0.0) dark red |
| `FillOpacity` | scalar | 0.35 |

## The cyberspace connection integrity widget

`WIDGET_ConnectionIntegrity` in the cyberspace HUD draws its panel, its health bar and its
SECURE and THREAT tags with four additive materials. Its icon material is translucent and its
label is a text block, so those two never needed help.

`MenuGenCyberHud.cpp` writes the four materials in chunk 10 and their textures in chunk 0.
`export-cooked-texture.ps1` writes the texture PNGs into `Resources\MenuGen\CyberHud\`.

| Material | Texture | What the material does |
|---|---|---|
| `/Game/Art/Cyberspace/GUI/MAT_ConnectionIntegrityPanel` | `T_ConnectionIntegrityWindow` | The panel. G of the texture is the fill gradient, R and B the two edge lines, A the shape. Colour = `UIBackgroundTint1` of the tint collection times `R + G + B`. Opacity = `(R + B + G * FillOpacity) * A * PanelOpacity` with `FillOpacity` 0.35 and `PanelOpacity` 0.9: solid lines, a see-through fill that fades out to the right, and a readable label on top. |
| `/Game/Art/Cyberspace/GUI/MAT_ConnectionIntegrityHealth` | `T_ConnectionIntegrityHealth` | The health bar. The texture is a flipbook of 21 frames in 2 columns and 11 rows (the last slot is empty); frame n has n dark segments. `HealthRatio` (1 = full) picks the frame: `round((1 - ratio) * 20)`. The texture's alpha is 1 everywhere, so the opacity is the brightest colour channel. |
| `/Game/Art/Cyberspace/GUI/zz_Archive/MAT_ConnectionStatusSecure` | `T_ConnectionStatusSecure` | The SECURE tag, drawn as in the texture. Opacity = A times `HealthGood` (0 or 1). |
| `/Game/Art/Cyberspace/GUI/zz_Archive/MAT_ConnectionStatusThreat` | `T_ConnectionStatusThreat` | The THREAT tag. Opacity = A times `HealthCritical` (0 or 1). |

The parameter names come from the widget's function `Set Integrity Value`, which makes a
dynamic instance of each mesh widget's material and sets `HealthRatio`, `HealthGood` (ratio
above 0.28) and `HealthCritical` (ratio at or below 0.28).

The panel reads the player's tint from the dummy of `MPC_UserTintParameters` that the
generator makes for the menu icons. `documentation\menu-icons.md` explains the dummy and why
it must not be edited in the editor.

## The cyberspace flight reticle

The flight reticle in the middle of the cyberspace HUD (`WIDGET_FlightReticle`) draws the
game's `MAT_CyberspaceFlightReticle`, a translucent UI material that only samples
`T_CyberspaceFlightReticle` (2048 x 2048, DXT5): a large ring with side bars, a small circle in
the middle, two small triangles over the side bars and one triangle at the top, the "up"
marker. In VR only that top triangle is shown.

The material stays the game's. The Core pak replaces the texture at the game's path
`/Game/Art/Cyberspace/GUI/T_CyberspaceFlightReticle`, in chunk 10, with a 1024 x 1024 texture
that holds only the top triangle. `tools\UEVRBridgeGen\Resources\MenuGen\make_flight_reticle.py`
writes it to `Resources\MenuGen\CyberHud\T_CyberspaceFlightReticle.png` from the cooked
texture in `dumps\`, and `MenuGenCyberHud.cpp` imports it. The script needs Pillow to decode
DXT5. The plugin turns the reticle so the triangle points to world up (see
`cyberspace-controls.md`, "The flight reticle").

## The drill lock-on outline

The I.C.E. drill lock-on (`WIDGET_IceDrillLockOn`) draws its arcs and chevrons with
`MAT_ICEDrillReticle_LockOnBracket` and `MAT_ICEDrillReticle_LockOnPointer`. Their textures
hold several masks:

| Texture | R | G | B | A |
|---|---|---|---|---|
| `T_ICEDrillReticle_LockOnBracket` (512 x 512) | the thin arc | almost empty | a wide band around the arc, empty under it | the arc with a soft glow |
| `T_ICEDrillReticle_LockOnPointer` (256 x 256) | the chevron | a blurred shadow | a wide band around the chevron, empty under it | the chevron with a soft glow |

Where the glow in A has no line colour (R), the materials draw black at that opacity. On the
monitor it keeps the lines readable; in VR, where the plugin shows the lock-on in the world
(see `cyberspace-controls.md`, "Drill lock-on"), it looked like a thick dark outline. The
Core pak replaces both textures at the game's paths in chunk 10 with copies whose A and B are
only a thin rim around the line: R widened by 2 px (arcs) or 1 px (chevrons), softened by
0.5 px and never more than the game's values. R and G stay. A live check showed that cutting
only B changed nothing; the dark outline comes from A.
`tools\UEVRBridgeGen\Resources\MenuGen\make_ice_drill_reticle.py` writes the PNGs from the
cooked textures in `dumps\` (BGRA8, uncompressed), and `MenuGenCyberHud.cpp` imports them.
Like the game's, the textures keep sRGB on and use `TC_EditorIcon`.
