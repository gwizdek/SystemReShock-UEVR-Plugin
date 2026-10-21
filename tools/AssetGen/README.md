# AssetGen

An Unreal Engine 4.27 editor plugin. It runs as a commandlet, `ModAssetGen`, and creates the
mod's generated assets in the Unreal project: the VR options page, replacement HUD materials and
textures, and the VR controller button atlas. They are cooked into the mod's Core pak (chunk 10).
Stand-ins that only exist so those assets can be made are cooked into chunk 0, which is never
shipped.

The C++ headers for the plugin are made by a different editor plugin, `tools/UEVRBridgeGen/`.
The two do not depend on each other.

## Where the plugin lives

The source is kept here, in the UEVR plugin repository. The Unreal project gets a directory
junction to this folder:

```cmd
mklink /J "D:\Unreal Engine\Projects\SystemReShock-UE4-Project\Plugins\AssetGen" "C:\_Dev\mods\SystemReShock-UEVR-Plugin\tools\AssetGen"
```

`assetgen.config.json` in this folder holds the engine folder, the Unreal project and the
editor build target. Change them for another machine.

## Running it

Close the Unreal editor, then run from the repository root:

```powershell
.\tools\AssetGen\GenerateAssets.ps1                            # all, create what is missing
.\tools\AssetGen\GenerateAssets.ps1 -RebuildGen                # after a change under Source\
.\tools\AssetGen\GenerateAssets.ps1 -Only CyberHud -Overwrite  # one, create again
```

An asset whose package exists is kept, unless `-Overwrite` is given. `-RebuildGen` builds the
editor target first; it builds every plugin of the project, so `UEVRBridgeGen` too. The logs go
to `Intermediate\Generate\`.

## Generators

Each generator has its own source folder under `Source/AssetGen/Private/` and its own folder
under `Resources/` for its PNGs and the scripts that make them:

| Generator | Source folder | Resources folder | Creates | Documentation |
|---|---|---|---|---|
| `Menu` | `MenuGen/` | `Resources/MenuGen/` | The VR options page and its category icon | `documentation/vr-options-menu.md`, `documentation/menu-icons.md` |
| `HudIcon` | `HudIconGen/` | `Resources/HudIcon/` | The HUD email icon | `documentation/hud-materials-in-vr.md` |
| `ButtonAtlas` | `ButtonAtlasGen/` | `Resources/ButtonAtlas/` | The VR controller button atlas | `documentation/menu-icons.md` |
| `CyberHud` | `CyberHudGen/` | `Resources/CyberHud/` | The cyberspace HUD materials and textures | `documentation/hud-materials-in-vr.md` |

`AssetGen/` holds the commandlet and what the generators share: the asset and material helpers
and the dummy of the game's tint collection, which is made before any generator runs.

A new generator gets its own folder with a `Generate(const FAssetGenContext&)` function, one
line in `Generators` in `AssetGen/ModAssetGenCommandlet.cpp`, and its name in the `-Only` list
of `GenerateAssets.ps1`. The module is a unity build, so every file-local name must be unique
across the whole module.

## PNGs made from the game's textures

PNGs that hold pixels of the game's own textures are not in git, because the game's art is not
ours to share. `.gitignore` lists them. Make them again before running `GenerateAssets.ps1` on a
new machine. Each script reads the cooked textures from the asset dump in `dumps\` at the
repository root, which must exist first:

| PNG | Made by |
|---|---|
| `Resources/CyberHud/T_ConnectionIntegrity*.png`, `T_ConnectionStatus*.png` | `Resources/CyberHud/export-cooked-texture.ps1`, once per texture |
| `Resources/CyberHud/T_CyberspaceFlightReticle.png` | `Resources/CyberHud/make_flight_reticle.py` |
| `Resources/CyberHud/T_ICEDrillReticle_*.png` | `Resources/CyberHud/make_ice_drill_reticle.py` |
| `Resources/HudIcon/T_MediaIcon_UnreadMessages_VR.png` | `Resources/HudIcon/make_media_icon.ps1` |
| `Resources/ButtonAtlas/T_VRButtonLayout.png` (and `_preview.png`) | `Resources/ButtonAtlas/draw_vr_button_icons.py` |

`Resources/MenuGen/T_OptionsIcons_VR.png` and the two hand-edited cells
`Resources/ButtonAtlas/T_VRButtonLayout_Hand*.png` hold no game pixels and stay in git.
