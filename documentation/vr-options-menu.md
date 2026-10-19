# VR options page in the game's Options screen

This document is a specification for work in progress on branch `vr-menu`. The first section
says what exists today. Everything after it describes what will be built and the facts it rests
on. The facts come from the game's Blueprint bytecode and widget trees, exported with
`scripts\export-bytecode.ps1` into `dumps\assets\...\<Widget>\` (`*.bytecode`, `variables.json`,
`widgets.json`, `enums.json`).

## Status

Done:

- The bytecode exporter writes widget trees (`widgets.json`), enums (`enums.json`), inherited
  default values and resolved object references. See `tools\BytecodeExporter\README.md`.
- The game's Options screen is fully mapped (this document).
- The generator (`tools\UEVRBridgeGen\GenerateMenu.ps1`, commandlet `VROptionsMenuGen`) creates
  the dummies and the mod widgets. They exist in the Unreal project
  (`D:\Unreal Engine\Projects\SystemReShock-UE4-Project`, its own git lfs repository, branch `vr-menu`).
- The plugin trigger (`SystemShockVR\vr_options_menu.cpp`) creates the page and installs it.

- The toggle row `_OPTION_VR_Toggle`, the slider row `_OPTION_VR_Slider` and their dummies.

- The page content: three groups with the game's group header, "General" (Player Height, Auto
  Aim Down Sights), "Movement" (VR Look Sensitivity, Snap Turn, Angle, Deadzone) and "Cyberspace"
  (Pitch Snap Turn, Pitch Deadzone, Pitch Snap Speed). See the list below.

- The settings sync in the plugin (`SystemShockVR\vr_options_sync.cpp`, `vr_setting_store.cpp`,
  `vr_settings.cpp`): the rows get their values from their stores after the install and each
  time the page opens, and Apply writes them back. Most rows are stored in
  `system_reshock_vr_config.ini`; the three snap turn rows are UEVR's own settings.

- The VR category icon: texture `T_OptionsIcons_VR`, material `MAT_OptionsIcons_VR` and a dummy of
  the game's tint collection. The page's `Install` puts the material on the category item.

All of the above works in the game, except the page content and the snap turn rows: they are
generated and the plugin builds, but they are not yet tested in the game.

## Goal

Add a seventh category, "VR", to the Options screen of the pause menu. It opens a page that
looks like the other option pages (same background, same row widgets, same Apply, Reset and
Back buttons, same description box) and holds the mod's settings. The rows hold the values; the
plugin copies them to and from the ini file and UEVR's settings.

## How the game's Options screen works

All class names below are Blueprint classes under `/Game/Blueprints/UI/`. `MainMenu/OptionsScreen/`
is written `OS/`, `MainMenu/OptionsScreen/OptionsCategories/` is written `OC/`, and `Generic/` is
written `G/`.

### Widgets

| Widget | Parent | Role |
|---|---|---|
| `MainMenu/WIDGET_MainMenu_InGame` | UserWidget | Pause menu. Holds one `WIDGET_OptionsScreen` in its tree. Calls `WIDGET_OptionsScreen.SetMainMenu(self)` from `SetPlayerHUD`, and `WIDGET_OptionsScreen.OnMenuOpen()` when the player picks Options. Forwards nav input with `WIDGET_OptionsScreen.InvokeNavManager`. |
| `OS/WIDGET_OptionsScreen` | `G/WIDGET_MenuBase` | The screen. Root `CanvasPanel_0` holds `GridPanel_221` (ColumnFill 10,50,3,30,10; RowFill 8,25,1,5). Cell row 1, column 1 holds seven `ScaleBox` widgets with `Stretch = None`: one per option page (`WIDGET_OptionsMenu_Gameplay` ... `_Interface`, all `Visibility = Hidden`) and `SCALEBOX_Menu` with the category list. Row 1, column 3 holds `WIDGET_OptionsDescriptionBox`. Row 3, column 3 holds `HBOX_NavButtons` with three `WIDGET_ButtonLegend_Button`: Reset (`MenuNav_Alt2`), Apply (`MenuNav_Alt1`), Back (`MenuNav_Back`). Animations `ANIM_OpenOptionsSubscreen` (moves the category list) and `ANIM_ShowResetApplyButtons` (fades the two buttons in). |
| `OS/WIDGET_OptionsCategoryMenuList` | `G/WIDGET_MenuListBase` | The category list. `VBOX_OptionCategoryWidgetList` (VerticalBox) holds six `WIDGET_OptionCategoryMenuListItem` named `WIDGET_OptionMenuCategory_<Name>`. |
| `OS/WIDGET_OptionCategoryMenuListItem` | `G/WIDGET_MenuListItemBase` | One category button. Tree: `IMAGE_BackgroundCollapsed`, `IMAGE_BackgroundExpanded` (material `MAT_UIPrimaryColor_Highlighted`, alpha 0.4), `IMAGE_IconSelectedBorder` (`MAT_OptionCategory_IconFrame`), `IMAGE_OptionCategoryIcon` (64 x 64 at left 20), `TEXT_OptionCategoryLabel` (font `FONT_UnitedSansReg` 26, material `MAT_UIPrimaryColor`, upper case), two invisible `Button`s `BTN_InputCollapsed` (100 x 100) and `BTN_InputExpanded` (full width). Animation `ANIM_OnHighlighted` on the label colour. |
| `OS/WIDGET_OptionsMenu_Base` | `G/WIDGET_MenuBase` | Base of every option page. `OnMenuOpen` calls the parent, then `ActiveMenuList.EVENT_OnOptionChanged()`. `OnMenuClose` calls the parent, then `ActiveMenuList.OnListClose()`. |
| `OC/Gameplay/WIDGET_OptionsMenu_Gameplay` | `WIDGET_OptionsMenu_Base` | A page. Tree: `IMAGE_PanelBackground` (full size, brush material `/Game/Art/UI/HUD/MainMenu/SubMenuGeneric/MAT_SubMenu_ListPanel`, margin 1, `HitTestInvisible`) and `WIDGET_OptionsMenu_GameplayList` (full size). `InitializeMenu(parent)`: parent call, `list.InitializeList(self)`, `SetActiveMenuList(list)`. |
| `OC/Gameplay/WIDGET_OptionsMenu_GameplayList` | `G/WIDGET_MenuListBase` | A page's list. Tree: `SCROLLBOX_OptionsMenuList` (full size, top and bottom offset 25, scrollbar thickness 8, padding 10, bar style materials `MAT_UIPrimaryColor`, `_Highlighted`, `_Accent`) with seven `OPTION_Gameplay_*` rows, each in a `ScrollBoxSlot` with padding 20 (the last one none). `InitializeList`: parent call, then `PanelItemListWidget = SCROLLBOX_OptionsMenuList`. `InitializeItemArray`: every child of the scroll box that casts to `WIDGET_MenuListItemBase`. |
| `OC/Gameplay/OPTION_Gameplay_AutoReload` and the other rows | `OC/WIDGET_Settings_BinaryToggle` (or `_Slider`, `_MultiSelector`) | A row. Has no widget tree and no variables of its own. The default object sets `ItemName` and `ItemDescription`. It overrides six functions: `AcceptCurrentValue`, `ApplyDirtyValue`, `IsDirty`, `UpdateVisuals`, `SelectDefaultValue`, `IsDefault`, all against `SAVE_Settings` through `FUNCLIB_GameSettings.GetShockSettingsForCurrentUser`. |
| `OC/WIDGET_Settings_BinaryToggle` | `OC/OPTION_Base` | Toggle row. Tree: `IMAGE_SelectedBackground` and `MESH_SelectedBackground` (`MAT_MainMenuSelection`), a `GridPanel` (ColumnFill 0.04, 0.6, 0.4, 0.04) with `TEXT_SettingNameLabel` (font `FONT_UnitedSansReg` 20, upper case) in column 1 and `WIDGET_Checkbox` in column 2, and `MESH_Input` (a `GridMeshWidget`, native class of the game module). `PreConstruct` writes `ItemName` into the label. Functions `SetCheckboxValue(bool)`, `GetCheckboxValue()`, `ToggleCheckbox()`. The checkbox change broadcasts `OnOptionChanged`. |
| `OC/WIDGET_Settings_Slider` | `OC/OPTION_Base` | Slider row. Same layout with `WIDGET_Slider` in column 2. Instance variables `SliderDiscreteValues`, `SliderInitialValue`, `SliderValueMin`, `SliderValueMax`, `SliderPostfix`, `SliderFractionalDigits`. `InitializeMenuListItem` pushes them into the slider. `GetScaledCurrentSliderValue()` maps the normalized slider value into min..max. `WIDGET_Slider.SetSliderRealValue(float)` sets it. |
| `OC/OPTION_Base` | `G/WIDGET_MenuListItemBase` | Base of every row. Declares the six functions above as empty, plus `ApplyCleanValue`, `SaveNewValue`, `SetOptionEnabled`, `GetPreviousSavedValue`, `ShowDirtyIcon`, `GetSaveSettings`, and the event dispatcher `OnOptionChanged`. `InitializeMenuListItem` calls the parent, then `UpdateVisuals()`. Variables `IsMutator`, `ShowExampleImage`, `ExampleImagesArray`. |
| `G/WIDGET_MenuListItemBase` | UserWidget | Base of every list item. Variables `ItemName` (Text), `ItemDescription` (Text), `IndexInList`, `IsHighlighted`, `ParentListWidget`, `SoundCueHighlighted`, `SoundCueActivated`, `SupportedPlatforms`, dispatcher `OnHighlightedEvent`. `InitializeMenuListItem(ParentList, Index)` sets `ParentListWidget` and `IndexInList`, then `SetVisibilityBasedOnPlatform()`. Implements interface `G/BPI_MenuNavigationRecipient` (`ReceiveNavUp/Down/Left/Right/Accept/Back/Alt1/Alt2/TabLeft/TabRight/LeftRelease/RightRelease`, each `(bool InputState) -> bool Result`). |
| `G/WIDGET_MenuListBase` | UserWidget | Base of every list. Variables `MenuListItemArray`, `HighlightedItemIndex`, `HighlightedMenuListItemWidget`, `ParentScreenWidget`, `PanelItemListWidget`, `CanListClose`, `IsListInteractive`, dispatchers `OnMenuAction`, `OnListDirty(bool)`, `OnListFullyDefault(bool)`. Same interface as the item. |
| `G/WIDGET_MenuBase` | UserWidget | Base of every screen and page. Variables `ParentMenu`, `Header`, `ActiveMenuList`, `OpenedSubMenu`, `MenuLabel`, `DimBackgroundWhenOpened`, `CanMenuClose`, dispatchers `OnMenuOpened(self)`, `OnMenuClosed(self)`, `OnSubMenuOpened(sub)`, `OnSubMenuClosed(sub)`, `OnCanApply(bool)`, `OnCanReset(bool)`. |
| `HUD/Widgets/ButtonLegend/WIDGET_ButtonLegend_Button` | UserWidget | A nav button. `ToggleInteractivity(bool IsInteractive)` enables or disables it. Dispatcher `OnClicked`. Variables `ButtonActionText`, `ButtonInputAction`, `ShowBackground`. |

Rows inherit their widget tree. `OPTION_Gameplay_AutoReload` has an empty `WidgetTree`; at runtime
the engine walks up to `WIDGET_Settings_BinaryToggle` and uses its tree. The mod's rows use the
same mechanism, so they need no tree and no native `GridMeshWidget` class in the editor.

### Enums

`OS/ENUM_OptionCategories` (user defined, six entries, byte values): 0 Gameplay, 1 Controls,
2 Display, 3 Graphics, 4 Audio, 5 Accessibility + Interface. `G/ENUM_MenuNavigationInput`:
0 Up, 1 Down, 2 Left, 3 Right, 4 Accept, 5 Back, 6 Alt1, 7 Alt2, 8 Alt3, 9 Alt4, 10 TabLeft,
11 TabRight.

### Start up

`WIDGET_OptionsScreen.OnInitialized` calls `InitializeMenu(null)`:

1. `WIDGET_MenuBase.InitializeMenu` stores `ParentMenu` (null here).
2. `WIDGET_OptionsCategoryMenuList.InitializeList(self)`.
3. `SetActiveMenuList(WIDGET_OptionsCategoryMenuList)`.
4. `InitializeMenu(self)` on each of the six pages. A page stores `ParentMenu = screen`, calls
   `list.InitializeList(page)` and `SetActiveMenuList(list)`.

`WIDGET_MenuListBase.InitializeList(ParentScreen)`:

1. `ParentScreenWidget = ParentScreen`; clears `MenuListItemArray`.
2. `MenuListItemArray = InitializeItemArray()`. For the category list that is every child of
   `VBOX_OptionCategoryWidgetList` that casts to `WIDGET_MenuListItemBase`; it also writes the
   platform-specific descriptions of the six game items. For a page list it is every such child of
   the scroll box.
3. For each item `i`: `item.InitializeMenuListItem(self, i)`. This is what sets `IndexInList`, so
   calling `InitializeList` again after adding a child re-numbers every item.
4. For each item that is an `OPTION_Base`: adds `EVENT_OnOptionChanged` to its `OnOptionChanged`.
   This uses Add, not AddUnique, so a second `InitializeList` on a page list binds rows twice. The
   category list has no `OPTION_Base` items, so a second call there is safe.

`WIDGET_MenuBase.SetActiveMenuList(list)` unbinds the old list and binds the new list's
`OnListDirty` to `EVENT_ActiveListDirtyValueChanged` (broadcasts `OnCanApply`) and
`OnListFullyDefault` to `EVENT_ActivateListDefaultValueChanged` (broadcasts `OnCanReset`).

### Opening a category

1. A click on a category item fires its button's `OnPressed` and then `OnClicked`. Both run
   `EVENT_OnMousePress`, which ends in `ReceiveNavAccept`: broadcast `OnCategoryButtonClicked(IndexInList)`,
   then `OnItemAccepted()`. So the delegate fires twice per click.
2. `WIDGET_OptionsCategoryMenuList` has six compile-time bindings, one per named item, that each
   re-broadcast `OnOptionCategoryClicked(index)`. A seventh item gets no such binding.
3. `WIDGET_OptionsScreen` turns the index into `ENUM_OptionCategories` by identity, default
   Gameplay, and calls `TryOpenOptionSubMenu(category)`:
   - `NewSubMenu` = switch on the byte over the six page variables, default null.
   - If `OpenedSubMenu == NewSubMenu`: return. (This makes the double fire harmless.)
   - `PlayMenuAnimation = (OpenedSubMenu is not valid)`. If it is valid: `OpenedSubMenu.OnMenuClose()`.
   - `TryOpenSubMenu(NewSubMenu)`, then `WIDGET_OptionsCategoryMenuList.SetSelectedItem(index)`.
   - If `PlayMenuAnimation` and `NewSubMenu` valid: play `ANIM_OpenOptionsSubscreen` and
     `ANIM_ShowResetApplyButtons` forward.
   - For every item of the category list: `SetExpandedState(OpenedSubMenu is valid)`.
4. `WIDGET_MenuBase.TryOpenSubMenu(sub)`: `OpenedSubMenu = sub`; if valid, `sub.OnMenuOpen()` and
   broadcast `OnSubMenuOpened(sub)`; else print a warning. It adds nothing to any panel. The page
   must already be in the screen's widget tree.
5. `WIDGET_MenuBase.OnMenuOpen`: `SetVisibility(Visible)`, broadcast `OnMenuOpened(self)`, then
   `ActiveMenuList.SetHighlightedListItem(-1, false)` and `ActiveMenuList.OnListOpen()` (shows the
   list, and on gamepad highlights the first row). `WIDGET_OptionsMenu_Base` adds
   `ActiveMenuList.EVENT_OnOptionChanged()`, which broadcasts `OnListDirty` and `OnListFullyDefault`.
6. `WIDGET_OptionsCategoryMenuList.SetSelectedItem(index)`: `SetCategorySelected(false)` on the item at
   the old `SelectedItemIndex`, stores the new index, `SetCategorySelected(true)` on the new item
   (shows `IMAGE_IconSelectedBorder`), returns its `ItemName`. It reads `GetAllMenuListItems()`, so
   it works for any index in `MenuListItemArray`.
7. `WIDGET_OptionCategoryMenuListItem.SetExpandedState(bool)`: expanded shows the full-width button,
   background and label; collapsed shows the 100 x 100 button and hides the label.
8. The item's `PreConstruct` writes `ItemName` into the label and picks the icon material with
   `OptionCategoryIcon[switch(ENUM_OptionCategories)]`. The switch maps bytes 0..5 to 0..5 and anything
   else to an uninitialised local, which is 0. The array has six materials
   (`/Game/Art/UI/HUD/MainMenu/OptionsScreen/MAT_OptionsIcons_<Name>`).

### Highlight and description

A row that becomes highlighted makes its list call `SetHighlightedListItem(index, true)`. The list
stores the index and, if `ParentScreenWidget` casts to `WIDGET_OptionsScreen`, calls
`screen.SetHighlightedListItem(item)`; otherwise it tries `ParentScreenWidget.ParentMenu`. For a page
list the parent screen is the page and the page's `ParentMenu` is the screen, so the second branch
is taken. The screen shows `WIDGET_OptionsDescriptionBox` and calls
`SetNameAndDescription(ItemName upper case, ItemDescription)`. The list also scrolls the item into
view when `PanelItemListWidget` is a `ScrollBox`.

### Apply, Reset, Back

All three go through `WIDGET_OptionsScreen.InvokeNavManager(input, true)`: Apply is Alt1 (6), Reset
is Alt2 (7), Back is Back (5). The buttons' `OnClicked` bindings call it; gamepad input arrives
through `WIDGET_MainMenu_InGame.InvokeNavManager`.

- `WIDGET_OptionsScreen.InvokeNavManager` first calls `WIDGET_MenuBase.InvokeNavManager`, which forwards
  to `OpenedSubMenu.InvokeNavManager` when a page is open. The page's `WIDGET_MenuBase.InvokeNavManager`
  has no sub menu, so it dispatches on the input to its `ActiveMenuList`:
  - Alt1: `list.ReceiveNavAlt1`: `ApplyDirtyValue()` then `AcceptCurrentValue()` on every dirty row
    (`GetDirtyChildOptions` = rows whose `IsDirty()` is true), then `EVENT_OnOptionChanged()`.
  - Alt2: `list.ReceiveNavAlt2`: `SelectDefaultValue()` on every row, then `EVENT_OnOptionChanged()`.
  - Back: `list.ReceiveNavBack` (closes the list when `CanListClose` is false), then
    `ParentMenu.TryCloseSubMenu()`.
- Then the screen itself: on Alt1 it calls `GI_SinglePlayer.SaveShockSettings(ShockSettings, 0)`.
  On Back with no page open it returns to the pause menu.
- `WIDGET_OptionsScreen.TryCloseSubMenu`: parent call (`OpenedSubMenu.OnMenuClose()`, broadcast
  `OnSubMenuClosed`, `OpenedSubMenu = null`), plays both animations backwards, collapses every
  category item.
- `WIDGET_MenuListBase.OnListClose`: `ApplyCleanValue()` and `UpdateVisuals()` on every dirty row,
  clears the highlight, hides the list.
- Apply and Reset buttons: the screen has compile-time bindings from each page's `OnCanApply` and
  `OnCanReset` to `ToggleInteractivity` on `WIDGET_ButtonLegend_ApplyButton` and
  `WIDGET_ButtonLegend_ResetToDefaults`. A seventh page gets no such binding.

## What blocks a plain seventh category

- `OnOptionCategoryClicked` is only re-broadcast for the six named items.
- `TryOpenOptionSubMenu` knows six pages and six enum values. Index 6 becomes Gameplay.
- `TryOpenSubMenu` does not add the page to the screen. The page must be placed in `GridPanel_221`
  first.
- Apply and Reset enable state is only wired for the six pages.
- The item's icon array has six materials.

None of this needs the game's assets to change. Everything is reachable from a Blueprint that
holds references to the live widgets.

## Design

Three kinds of assets in the Unreal project, plus one plugin change. The commandlet in
`tools\UEVRBridgeGen\Source\UEVRBridgeGen\Private\MenuGen\` creates every asset:
`MenuGenDummies.cpp` holds the dummy list, `MenuGenModWidgets.cpp` the trees and the row and
list functions, `MenuGenPageLogic.cpp` the page functions. Run it from the repository root with
the Unreal editor closed:

```powershell
.\tools\UEVRBridgeGen\GenerateMenu.ps1              # create what is missing
.\tools\UEVRBridgeGen\GenerateMenu.ps1 -RebuildGen  # after a change under Source\
.\tools\UEVRBridgeGen\GenerateMenu.ps1 -Overwrite   # create every asset again
```

An asset whose package already exists is kept and loaded, so the generator can be run again
after a failure or to add new assets. `-Overwrite` writes a new asset over the file without
loading the old one. Mod assets are marked for chunk 10 when saved; dummies get no chunk.

### 1. Dummy game classes (chunk 0, not shipped)

Blueprints at the game's own paths, so the mod's Blueprints can subclass them and call their
functions. They have no logic and no widget tree. They are cooked into `pakchunk0`, which the
installer never ships, so they never override the game's assets. Only the mod's own assets
(chunk 10) reach the game; in the game every reference by path resolves to the real class.

A dummy only needs the members the mod's Blueprints use. Names, parameter names and flags such as
pure must match the game. Parameter and variable types may be wider than the game's (for example
`UserWidget` instead of a menu class) because the cooked bytecode links by name and passes object
pointers. Every function is created as a normal Blueprint function, which is overridable.

| Dummy (path under `/Game/Blueprints/UI/`) | Parent | Members needed |
|---|---|---|
| `Generic/BPI_MenuNavigationRecipient` | interface | optional; only if a mod widget overrides a `ReceiveNav*` function. |
| `Generic/WIDGET_MenuBase` | UserWidget | vars `ParentMenu`, `ActiveMenuList` (typed `UserWidget`), `OpenedSubMenu`; dispatchers `OnCanApply(CanApply)`, `OnCanReset(CanReset)`; functions `InitializeMenu(ParentMenuWidget)`, `OnMenuOpen()`, `OnMenuClose()`, `SetActiveMenuList(Value)`, `TryOpenSubMenu(SubMenu)`, `TryCloseSubMenu()`. |
| `MainMenu/OptionsScreen/WIDGET_OptionsMenu_Base` | WIDGET_MenuBase | nothing extra (`OnMenuOpen`, `OnMenuClose` overrides exist in the game and are inherited at runtime). |
| `Generic/WIDGET_MenuListBase` | UserWidget | vars `MenuListItemArray`, `ParentScreenWidget`, `PanelItemListWidget`; functions `InitializeList(ParentScreen)`, `InitializeItemArray() -> MenuListItems`, `EVENT_OnOptionChanged()`. |
| `Generic/WIDGET_MenuListItemBase` | UserWidget | vars `ItemName`, `ItemDescription`, `IndexInList`; function `InitializeMenuListItem(ParentList, Index)`. |
| `MainMenu/OptionsScreen/OptionsCategories/OPTION_Base` | WIDGET_MenuListItemBase | the six overridable functions, `ApplyCleanValue()`, `SaveNewValue()`, dispatcher `OnOptionChanged()`. |
| `.../OptionsCategories/WIDGET_Settings_BinaryToggle` | OPTION_Base | `SetCheckboxValue(Value)`, `GetCheckboxValue() -> Result` (pure), `ToggleCheckbox()`. |
| `.../OptionsCategories/WIDGET_Settings_Slider` | OPTION_Base | the six instance variables `SliderDiscreteValues` (Int), `SliderInitialValue`, `SliderValueMin`, `SliderValueMax` (Float), `SliderPostfix` (Text), `SliderFractionalDigits` (Int); `GetScaledCurrentSliderValue() -> Result` (pure, the slider position mapped into min..max); `GetSlider() -> Result` (pure, the `WIDGET_Slider` control). |
| `.../OptionsCategories/WIDGET_Slider` | UserWidget | `SetSliderRealValue(RealValue)`, `GetRealValue() -> RealValue` (pure). |
| `MainMenu/OptionsScreen/WIDGET_OptionCategoryMenuListItem` | WIDGET_MenuListItemBase | vars `ENUM_OptionCategories` (byte of the dummy enum), `IsExpanded`, `OptionCategoryIcon` (array of `Material`); dispatcher `OnCategoryButtonClicked(ItemIndex)`; functions `SetExpandedState(NewExpandedState)`, `SetCategorySelected(NewSelectedState)`. |
| `MainMenu/OptionsScreen/WIDGET_OptionsCategoryMenuList` | WIDGET_MenuListBase | var `VBOX_OptionCategoryWidgetList` (VerticalBox); function `SetSelectedItem(ItemIndex) -> CategoryText`. |
| `MainMenu/OptionsScreen/WIDGET_OptionsScreen` | WIDGET_MenuBase | vars `WIDGET_OptionsCategoryMenuList`, `WIDGET_OptionsMenu_Gameplay` (typed `UserWidget`; only used to reach `GridPanel_221` through `GetParent` twice), `WIDGET_ButtonLegend_ApplyButton`, `WIDGET_ButtonLegend_ResetToDefaults`, `ANIM_OpenOptionsSubscreen`, `ANIM_ShowResetApplyButtons` (WidgetAnimation); function `TryUpdateCategoryList()`. |
| `HUD/Widgets/ButtonLegend/WIDGET_ButtonLegend_Button` | UserWidget | `ToggleInteractivity(IsInteractive)`. |
| `.../OptionsCategories/Controls/WIDGET_ListCategoryHeader` | UserWidget | var `HeaderText` (Text). The game's group title in an options list; its `PreConstruct` writes `HeaderText` into the title text. |
| `MainMenu/OptionsScreen/ENUM_OptionCategories` | user enum | the six entries in the game's order. |
| `/Game/Blueprints/UI/Tinting/MPC_UserTintParameters` | material parameter collection | the game's 19 vector parameters in the game's order, with the game's parameter `Id`s and the game's `StateId`. See "Category icon" below. |

Other art assets (materials, fonts, textures) get no dummies. The one game material the mod page
needs is set by the plugin at runtime (see the plugin trigger below).

### 2. Mod widgets (chunk 10, `/Game/Mods/UI/Options/`)

**`_WIDGET_OptionsMenu_VR`**, child of `WIDGET_OptionsMenu_Base`. Tree copied from the Gameplay
page: `CanvasPanel` with `IMAGE_PanelBackground` (anchors 0,0 to 1,1, offsets 0, brush margin 1,
`HitTestInvisible`) and `_WIDGET_OptionsMenu_VRList` (anchors 0,0 to 1,1, offsets 0).
`InitializeMenu` override: parent call, `list.InitializeList(self)`, `SetActiveMenuList(list)`.
The background image has no material in the asset; the plugin sets the game's panel material on
it after the install. The page also holds the install logic, see below. Variables: `Screen`,
`CategoryItem`, `WasSubMenuOpen`.

**`_WIDGET_OptionsMenu_VRList`**, child of `WIDGET_MenuListBase`. Tree copied from the Gameplay
list: `CanvasPanel` with `SCROLLBOX_OptionsMenuList` (anchors 0,0 to 1,1, offsets top 25 and bottom
25, scrollbar thickness 8 x 8, scrollbar padding 10 on the right). The scroll box holds group
headers and rows, each in a `ScrollBoxSlot` with 20 units of bottom padding (the last one none),
as in the game's Interface list. `InitializeList` override: parent call,
`PanelItemListWidget = SCROLLBOX_OptionsMenuList`. `InitializeItemArray` override: returns an
array made of the row variables, in list order (no loop, since the generator knows every row).
The headers are not list items, so they are not in that array and the controller skips them.
The list scrolls when the rows do not fit, with the mouse wheel, by dragging the scrollbar, and
with the controller: the game's list base scrolls the highlighted row into view. The scroll box
has the engine's default scrollbar style; the plugin gives its thumb the game's materials (see
the plugin trigger below).

The content is one table in the generator (`ListEntries` in `MenuGenModWidgets.cpp`), top to bottom:

| Widget | Kind | Label | Setting name | Range, step | Default | Stored in |
|---|---|---|---|---|---|---|
| `WIDGET_ListCategoryHeader_General` | header | General | | | | |
| `OPTION_VR_PlayerHeight` | slider | Player Height | `player_height` | 165 to 185 cm, 1 | 175 | ini `[general]` |
| `OPTION_VR_AutoAimDownSights` | toggle | Auto Aim Down Sights | `auto_ads` | | on | ini `[general]` |
| `WIDGET_ListCategoryHeader_Movement` | header | Movement | | | | |
| `OPTION_VR_LookSensitivity` | slider | VR Look Sensitivity | `vr_look_sensitivity` | 1 to 10, 1 | 5 | ini `[movement]` |
| `OPTION_VR_SnapTurn` | toggle | Snap Turn | `VR_SnapTurn` | | off | UEVR |
| `OPTION_VR_SnapTurnAngle` | slider | Angle | `VR_SnapturnTurnAngle` | 10 to 90, 1 | 50 | UEVR |
| `OPTION_VR_SnapTurnDeadzone` | slider | Deadzone | `VR_SnapturnJoystickDeadzone` | 0.05 to 0.50, 0.01 | 0.20 | UEVR |
| `WIDGET_ListCategoryHeader_Cyberspace` | header | Cyberspace | | | | |
| `OPTION_VR_CyberPitchSnapTurn` | toggle | Pitch Snap Turn | `pitch_snap_turn` | | off | ini `[cyberspace]` |
| `OPTION_VR_CyberPitchDeadzone` | slider | Pitch Deadzone | `pitch_deadzone` | 0.00 to 1.00, 0.01 | 0.80 | ini `[cyberspace]` |
| `OPTION_VR_CyberPitchSnapSpeed` | slider | Pitch Snap Speed | `pitch_snap_speed` | 0.00 to 1.00, 0.01 | 0.50 | ini `[cyberspace]` |

The "Stored in" column is decided in the plugin, not in the Blueprint (see "Settings sync").
The cyberspace rows are used by `CyberspacePitchSnap`, see `cyberspace-controls.md`.

**`_OPTION_VR_Toggle`**, child of `WIDGET_Settings_BinaryToggle`, and **`_OPTION_VR_Slider`**,
child of `WIDGET_Settings_Slider`. No tree, no own widgets. A row is its own store: instance
variables `SettingName` (Name), `SavedValue` and `DefaultValue` (bool for the toggle, float for
the slider), all editable per instance. Overrides, mirroring the game's rows:

| Function | Toggle | Slider |
|---|---|---|
| `UpdateVisuals` | `SetCheckboxValue(SavedValue)` | `GetSlider().SetSliderRealValue(SavedValue)`, then `GetSlider().UpdateBackgroundFill()` |
| `IsDirty` | `GetCheckboxValue() != SavedValue` | not `NearlyEqual(GetCurrentValue(), SavedValue)` |
| `IsDefault` | `GetCheckboxValue() == DefaultValue` | `NearlyEqual(GetCurrentValue(), DefaultValue)` |
| `ApplyDirtyValue` | parent call only | parent call only |
| `AcceptCurrentValue` | `SavedValue = GetCheckboxValue()` | `SavedValue = GetCurrentValue()`, then `UpdateVisuals()` |
| `SelectDefaultValue` | `SetCheckboxValue(DefaultValue)` | same as `UpdateVisuals` with `DefaultValue` |

Every override starts with a call to the parent implementation, as the game's rows do. Two facts
about the game's slider control shape the slider row:

- `SetSliderRealValue` moves the handle and the text but not the bar's fill. The mouse path goes
  through `SetSliderValue`, which ends with `UpdateBackgroundFill`. So the row calls
  `UpdateBackgroundFill` itself after every set, or the fill shows the old value.
- A mouse drag is not snapped to the discrete positions, so the slider can rest at 5.32 while its
  text shows 5. The row's own pure function `GetCurrentValue()` snaps `GetScaledCurrentSliderValue()`
  to the instance variable `Step` (default 1), and every compare and the accept use it. After Apply
  the handle is moved onto the stored step. The compares use a tolerance of 0.001.

Row instances in the list set `ItemName`, `ItemDescription`, `SettingName`, `DefaultValue` and
`SavedValue`. A slider row also sets `Step` and the six `Slider*` variables of its parent;
`SliderDiscreteValues` is the number of positions, (max - min) / step + 1, so 1 to 10 in whole
numbers needs 10 and the deadzone needs 46. Both texts
are plain `Text`; the game's rows use localised text, the mod's rows do not need to.

There is no settings object. The values persist in the plugin's ini, see "Settings sync" under
the plugin trigger below.

A row can be greyed out and blocked for the controller with the game's `SetOptionEnabled`. See
`option-rows-disabled-state.md` for how, and for what a disabled row still lets through.

### Category icon

`documentation\menu-icons.md` explains how to make the next icon step by step. In short, the game's
six category icons follow one recipe, and the VR icon copies it:

- **Texture.** 256 x 256, compression `TC_EditorIcon` (uncompressed BGRA8), group
  `TEXTUREGROUP_UI`, one mip. The shape is a white silhouette on black that fills the square to a
  few pixels from the edge, with details cut out as negative space. The game packs three icons
  into one texture, one per colour channel, and leaves alpha at 255. The mod's
  `T_OptionsIcons_VR` holds one icon in R, G and B alike. Its source is
  `tools\UEVRBridgeGen\Resources\MenuGen\T_OptionsIcons_VR.png`, drawn by `draw_vr_icon.py` next to
  it: a chamfered headset with two lenses, a nose notch and strap tabs.
- **Material.** A UI-domain, translucent material per icon. Colour is the collection parameter
  `UIBackgroundTint1` of `MPC_UserTintParameters`, opacity is the mask. In the game the icons are
  exactly that colour: the default theme's tint, (0, 1, 0.23) in linear space, shows as about
  (0, 250, 129). The game's materials also reference a radial gradient through the material
  function `UserTintBackground`; it does not show in the icons. `MAT_OptionsIcons_VR` has the
  colour and the opacity only.

A material that reads a parameter collection is compiled against the collection's parameter list
and records its `StateId`. In the game the reference resolves to the real collection, and the
material gets the live tint buffer only when the `StateId` matches. So the dummy collection at the
game's path copies the `StateId`, every vector parameter in the game's order and each parameter's
`Id`, all read from the cooked asset. The values are in `MenuGenIcon.cpp`. The dummy is in chunk 0,
like the other dummies, and never ships.

### 3. The page's `Install` function

The install logic lives on the page itself, so no extra object is needed to bind events.
`Install(WIDGET_OptionsScreen Screen)` is called once per screen instance, after the game's
`OnInitialized` has run (that is, after `WIDGET_OptionsCategoryMenuList.MenuListItemArray` holds
six items). The plugin checks that before calling it.

1. `Screen = Screen`. Create the category item with `WidgetBlueprintLibrary.Create`
   (`WIDGET_OptionCategoryMenuListItem`), store it in `CategoryItem`, set `ItemName = "VR"` and
   `ItemDescription`. Then `CategoryItem.OptionCategoryIcon = [MAT_OptionsIcons_VR]`. The item keeps
   `ENUM_OptionCategories = 0`, so its `PreConstruct` shows element 0. This must come before step 2:
   adding the item to the live list builds its widget, and that runs `PreConstruct`.
2. `AddChildToVerticalBox` on `Screen.WIDGET_OptionsCategoryMenuList.VBOX_OptionCategoryWidgetList`.
3. `Screen.WIDGET_OptionsCategoryMenuList.InitializeList(Screen)`. This re-numbers the items; the
   new one is index 6. It is safe because the category list has no `OPTION_Base` rows.
4. `Grid = Screen.WIDGET_OptionsMenu_Gameplay.GetParent().GetParent()` cast to `GridPanel`;
   `Grid.AddChildToGrid(self)`, then on the returned `GridSlot`: `SetRow(1)`, `SetColumn(1)`. The
   game's pages sit in `ScaleBox`es with `Stretch = None`, which changes nothing, so the page goes
   straight into the cell. `SetVisibility(Hidden)`.
5. `InitializeMenu(Screen)`.
6. Bind `CategoryItem.OnCategoryButtonClicked` to `OnVRCategoryClicked`, the page's own `OnCanApply`
   to `OnVRCanApply` and `OnCanReset` to `OnVRCanReset`. The handlers call `ToggleInteractivity`
   on `Screen.WIDGET_ButtonLegend_ApplyButton` and `Screen.WIDGET_ButtonLegend_ResetToDefaults`.
   Reset is inverted: `CanReset` true means "everything is default", so the Reset button is
   disabled when it is true.
7. `CategoryItem.SetExpandedState(Screen.OpenedSubMenu is valid)`.

`OnVRCategoryClicked(ItemIndex)` mirrors `TryOpenOptionSubMenu`:

1. If `Screen.OpenedSubMenu == self`: return (second fire of the click).
2. `WasSubMenuOpen = IsValid(Screen.OpenedSubMenu)`. If it was: `Screen.OpenedSubMenu.OnMenuClose()`.
3. `Screen.TryOpenSubMenu(self)`; `Screen.WIDGET_OptionsCategoryMenuList.SetSelectedItem(ItemIndex)`.
4. If nothing was open: `Screen.TryUpdateCategoryList()`, which plays `ANIM_OpenOptionsSubscreen`
   and expands every category item, then `Screen.PlayAnimation(ANIM_ShowResetApplyButtons)` with
   the game's arguments (start 0, loops 1, forward, speed 1). When a page was already open the
   items are expanded already, and the game's own loop handles them on its clicks.

Nothing else is needed for the other directions:

- Clicking a game category while the VR page is open: `TryOpenOptionSubMenu` calls
  `OpenedSubMenu.OnMenuClose()` on the VR page and `SetSelectedItem` deselects item 6.
- Back, Apply, Reset: the nav chain reaches the VR page through `OpenedSubMenu`, exactly as for the
  game's pages. Apply also saves the game's own settings, which is harmless.
- Description box: works through `ParentScreenWidget.ParentMenu`, see above.

### 4. Plugin trigger

`VROptionsMenu::handle` in `SystemShockVR\vr_options_menu.cpp` runs every engine tick on the game
thread with the player HUD and the pawn. The pawn picks the screen:

| Pawn | Screen |
|---|---|
| `PAWN_PlayerGhost` (title screen) | `PAWN_PlayerGhost.PreGameScreenWidget.WIDGET_SplashScreen_Title.WIDGET_OptionsScreen` |
| `PAWN_Avatar` (cyberspace) | `PAWN_Avatar.CyberspaceUI.WIDGET_MainMenu_InGame.WIDGET_OptionsScreen` |
| any other pawn (station) | `WIDGET_PlayerHUD.WIDGET_MainMenu_InGame.WIDGET_OptionsScreen` |

The HUD pointer alone cannot decide. The plugin clears that pointer on level change, and a
freed widget can still pass a validity check. In cyberspace the station pawn and its HUD still
exist below the map, so the HUD would give a pause menu that is not shown. Each screen is a
separate instance, so each gets its own page.
It stops for that screen after three failed attempts, counting both the install and the
settings sync, so a pak and plugin that do not match cannot log an error every tick.
`cleanup_pointers` resets the count on level change. When the screen is the one already
installed, it only runs the settings sync. Otherwise it waits until `MenuListItemArray` holds six
items. If the category box already has a seventh child (the page survives a plugin reload), it
adopts that page: it finds the page in the screen's grid and sets the background material, the
scrollbar style and the list shift again. All three are safe to repeat. Else it loads the page
class with `load_class_for_bridge`, creates the page with `WidgetBlueprintLibrary.Create`, calls
`Install(screen)` through the BridgeSDK wrapper, sets the game's `MAT_SubMenu_ListPanel` material
on `IMAGE_PanelBackground`, sets the scrollbar style, moves the category box up by
`kCategoryListShift` units (its canvas slot gets a negative top offset) so the seventh item stays
on screen, and only then syncs the settings. A failing sync therefore cannot hide the category.

The scrollbar style: the game's lists keep the engine's default scrollbar style and set only the
`ResourceObject` of the thumb's three brushes, to `MAT_UIPrimaryColor`, `_Highlighted` and
`_Accent`. The mod pak holds no game art, so `apply_scrollbar_style` copies those three pointers
from the Gameplay list's scroll box into `WidgetBarStyle` of the VR list's scroll box. Without it
the VR list shows the engine's grey thumb. Slate reads the brushes when it paints, so the change
also shows on a page that is already in the screen.

### Settings sync

`VROptionsSync` (`SystemShockVR\vr_options_sync.cpp`) binds each row to a store, a
`SettingStore` (`vr_setting_store.cpp`). The row's `SettingName` is the key in that store. The
binding lists (`s_sliders`, `s_toggles`) hold one line per row:

- `IniSectionStore` is one section of `system_reshock_vr_config.ini` in the UEVR profile folder,
  read and written through `VRSettings` (`vr_settings.cpp`). That class reads the file once on
  first use and writes it back with the other sections and keys kept. A bool is written as `1`
  or `0`. The file looks like this:

  ```ini
  [general]
  auto_ads = 1
  player_height = 175

  [movement]
  vr_look_sensitivity = 5

  [cyberspace]
  pitch_snap_turn = 0
  pitch_deadzone = 0.8
  pitch_snap_speed = 0.5
  ```

  Older plugin versions kept `vr_look_sensitivity` in `[general]`. When `VRSettings` reads the
  file, it moves that key to `[movement]` (`kMovedKeys` in `vr_settings.cpp`). The old value is
  kept only if `[movement]` has none. The file is written at once. This can be removed when no
  install has the old key left.

- `UevrSettingStore` is UEVR's own settings, read with `get_mod_value` and written with
  `set_mod_value`, so a change applies at once in the running UEVR. Its save calls UEVR's
  `save_config`, which writes `config.txt` in the profile folder. The snap turn rows use it, so
  the page and UEVR's overlay show the same values.

The sync runs from `VROptionsMenu`:

- After `Install`, and each time the VR page opens (`Screen.OpenedSubMenu` becomes the page),
  `VROptionsSync::push` writes each store value into the row's `SavedValue` and calls
  `UpdateVisuals`. A key that is missing leaves the row's value. A slider value is first put on
  the row's `Step` and range, so a value set elsewhere, such as UEVR's deadzone 0.203, does not
  make the row dirty. Then it calls the list's `EVENT_OnOptionChanged`, because the page
  computed its Apply and Reset state from the old values when it opened. The push on open is
  what shows a change made in UEVR's overlay; it comes one tick after the page opens.
- Every tick while the installed screen exists, `VROptionsSync::pull` compares each row's
  `SavedValue` with the value last seen. `SavedValue` changes only in `AcceptCurrentValue`, that
  is on Apply, so a difference means the player pressed Apply. The new value goes into its
  store, and each store that changed is saved. Reset and Back do not reach `SavedValue`, so they
  save nothing.
- When the page is already in the screen (plugin reload), `adopt_page` finds it in the screen's
  grid, and `VROptionsSync::adopt` takes the last-seen values from its rows without changing them.
- The plugin reads the ini values it acts on through `VRSettings`: `look_sensitivity()` for the
  right thumbstick turn speed (clamped to 1..10), `player_height()`, `auto_ads()`, and
  `pitch_snap_turn()`, `pitch_deadzone()` and `pitch_snap_speed()` for cyberspace. The
  cyberspace values are read when they are used, so Apply needs no extra step for them.
- After a save, `consume_settings_change` returns true once, and `plugin.cpp` calls
  `apply_vr_options_menu_settings`. It sets `m_ui_option_auto_ads_enabled` from `auto_ads()` and
  calls `VRBody::apply_custom_vr_game_options`. That function also runs after every VR body
  spawn. It stores `player_height()` in the movement component's `DefaultPlayerHeight` and calls
  `AdjustComponentsToPlayerHeight` with it. When auto ADS is turned off while the player aims,
  `handle_ads` releases the aim once.

A new row needs an entry in the generator's `ListEntries`, a run of `GenerateMenu.ps1 -Overwrite`
and `Generate.ps1`, and one line in the binding lists in `vr_options_sync.cpp`.

## Risks and checks for the spike (step 2)

- A mod widget whose parent is a dummy with an empty tree must still get the parent's real tree in
  the game. The game's rows prove the engine does this for a cooked child; the spike confirms it
  for a child cooked in another package.
- The dummy `WIDGET_OptionsScreen` declares `ANIM_ShowResetApplyButtons` as a plain variable. The
  game's class has it as a transient animation variable. Reading it by name should work; if
  `PlayAnimation` gets null, the buttons stay hidden on the first open and the handler needs
  another way to reach the animation.
- The icon material reads the tint through the dummy collection. If the dummy's `StateId` or
  parameter order ever differs from the game's, the material finds no tint buffer in the game and the
  icon shows the wrong colour or none. Opening the dummy in the editor and changing it makes a new
  `StateId`; run the generator with `-Overwrite` afterwards.
- Gamepad navigation: `WIDGET_OptionsCategoryMenuList` navigates with `ReceiveNavUp/Down` over
  `MenuListItemArray`, so item 6 is reachable. `ReceiveNavAccept` on the item broadcasts the
  delegate the installer bound. To be confirmed in the headset.
- `WIDGET_OptionsCategoryMenuList.GetListItemByCategory` and `SelectedCategory` are not used for
  opening pages, so the seventh item needs no enum value.

## Testing the spike

1. Open the Unreal project once and check that the three mod widgets and the dummies compile
   without errors (they compiled in the generator, so this is a double check).
2. Package the project (Shipping, Windows 64-bit) and take `pakchunk10-WindowsNoEditor.pak` as the
   Core pak, as `documentation\building.md` describes. The dummies land in chunk 0 and stay out.
3. Run the game with the plugin from `hot_plugins\`. Open the pause menu, then Options. The log
   shows `[vr_options_menu][handle] VR options page installed, categories: 7` once per level.
4. Expected: a seventh category "VR" with the headset icon in the same colour as the other icons,
   following the tint picked in the Interface options, its page with its rows, the
   description box text on hover, Apply enabled after a change, Reset enabled while the value is not
   the default, Back closing the page, and the game's categories still working.

## Work split

Claude writes the generator, the plugin code and this document. The user runs the generator and
the cook, confirms the Blueprints compile in the editor, tests in the headset, and picks the first
set of VR options.
