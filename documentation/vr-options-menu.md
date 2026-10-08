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

Not started: the dummy assets, the mod widgets, the installer Blueprint, the plugin trigger and
the settings store. The Unreal project (`D:\Unreal Engine\Projects\SystemReShock-UE4-Project`,
its own git lfs repository) is on branch `vr-menu` and clean.

## Goal

Add a seventh category, "VR", to the Options screen of the pause menu. It opens a page that
looks like the other option pages (same background, same row widgets, same Apply, Reset and
Back buttons, same description box) and holds the mod's settings. Values live in a mod-owned
settings object that the plugin reads.

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

Three kinds of assets in the Unreal project, plus one plugin change.

### 1. Dummy game classes (chunk 0, not shipped)

Blueprints at the game's own paths, so the mod's Blueprints can subclass them and call their
functions. They have no logic and no widget tree. They are cooked into `pakchunk0`, which the
installer never ships, so they never override the game's assets. Only the mod's own assets
(chunk 10) reach the game; in the game every reference by path resolves to the real class.

A dummy only needs the members the mod's Blueprints use. Signatures must match the game exactly
(names, parameter names, types, flags such as pure). Functions that the game declares as
`BlueprintEvent` are created as overridable functions so the mod's children can override them.

| Dummy (path under `/Game/Blueprints/UI/`) | Parent | Members needed |
|---|---|---|
| `Generic/BPI_MenuNavigationRecipient` | interface | optional; only if a mod widget overrides a `ReceiveNav*` function. |
| `Generic/WIDGET_MenuBase` | UserWidget | vars `ParentMenu`, `ActiveMenuList`, `OpenedSubMenu`; dispatchers `OnCanApply(bool)`, `OnCanReset(bool)`, `OnSubMenuOpened(WIDGET_MenuBase)`, `OnSubMenuClosed(WIDGET_MenuBase)`; functions `InitializeMenu(ParentMenuWidget)`, `OnMenuOpen()`, `OnMenuClose()`, `SetActiveMenuList(Value)`, `TryOpenSubMenu(SubMenu)`, `TryCloseSubMenu()`, `InvokeNavManager(InputType, InputState)`. |
| `MainMenu/OptionsScreen/WIDGET_OptionsMenu_Base` | WIDGET_MenuBase | nothing extra (`OnMenuOpen`, `OnMenuClose` overrides exist in the game and are inherited at runtime). |
| `Generic/WIDGET_MenuListBase` | UserWidget | vars `MenuListItemArray`, `ParentScreenWidget`, `PanelItemListWidget`; functions `InitializeList(ParentScreen)`, `InitializeItemArray() -> MenuListItems`, `GetAllMenuListItems() -> Options`, `EVENT_OnOptionChanged()`. |
| `Generic/WIDGET_MenuListItemBase` | UserWidget | vars `ItemName`, `ItemDescription`, `IndexInList`, `ParentListWidget`; function `InitializeMenuListItem(ParentList, Index)`. |
| `MainMenu/OptionsScreen/OptionsCategories/OPTION_Base` | WIDGET_MenuListItemBase | the six overridable functions, `ApplyCleanValue()`, dispatcher `OnOptionChanged()`. |
| `.../OptionsCategories/WIDGET_Settings_BinaryToggle` | OPTION_Base | `SetCheckboxValue(Value)`, `GetCheckboxValue() -> Result` (pure), `ToggleCheckbox()`. |
| `.../OptionsCategories/WIDGET_Settings_Slider` | OPTION_Base | the six `Slider*` instance variables, `GetScaledCurrentSliderValue() -> Result` (pure), var `WIDGET_Slider` typed as a dummy `WIDGET_Slider` with `SetSliderRealValue(Value)`. |
| `MainMenu/OptionsScreen/WIDGET_OptionCategoryMenuListItem` | WIDGET_MenuListItemBase | vars `ENUM_OptionCategories` (byte of the dummy enum), `OptionCategoryIcon` (Material array), `IMAGE_OptionCategoryIcon` (Image), `IsExpanded`; dispatcher `OnCategoryButtonClicked(int ItemIndex)`; functions `SetExpandedState(NewExpandedState)`, `SetCategorySelected(NewSelectedState)`. |
| `MainMenu/OptionsScreen/WIDGET_OptionsCategoryMenuList` | WIDGET_MenuListBase | var `VBOX_OptionCategoryWidgetList` (VerticalBox); function `SetSelectedItem(ItemIndex) -> CategoryText`. |
| `MainMenu/OptionsScreen/WIDGET_OptionsScreen` | WIDGET_MenuBase | vars `WIDGET_OptionsCategoryMenuList`, `WIDGET_OptionsMenu_Gameplay` (typed `UserWidget`; only used to reach `GridPanel_221` through `GetParent` twice), `WIDGET_ButtonLegend_ApplyButton`, `WIDGET_ButtonLegend_ResetToDefaults`, `ANIM_OpenOptionsSubscreen`, `ANIM_ShowResetApplyButtons` (WidgetAnimation). |
| `HUD/Widgets/ButtonLegend/WIDGET_ButtonLegend_Button` | UserWidget | `ToggleInteractivity(IsInteractive)`. |
| `MainMenu/OptionsScreen/ENUM_OptionCategories` | user enum | the six entries in the game's order. |

Art assets (materials, fonts) get no dummies. The one game material the mod page needs is loaded
by path at runtime (see the page below).

### 2. Mod widgets (chunk 10, `/Game/Mods/UI/Options/`)

**`_WIDGET_OptionsMenu_VR`**, child of `WIDGET_OptionsMenu_Base`. Tree copied from the Gameplay
page: `CanvasPanel` with `IMAGE_PanelBackground` (anchors 0,0 to 1,1, offsets 0, brush margin 1,
`HitTestInvisible`) and `_WIDGET_OptionsMenu_VRList` (anchors 0,0 to 1,1, offsets 0).
`InitializeMenu` override: parent call, `list.InitializeList(self)`, `SetActiveMenuList(list)`.
`Construct` (or `PreConstruct`): load `/Game/Art/UI/HUD/MainMenu/SubMenuGeneric/MAT_SubMenu_ListPanel`
by soft path and `SetBrushFromMaterial` on the background. In the editor the background is empty; in
the game it is the real panel.

**`_WIDGET_OptionsMenu_VRList`**, child of `WIDGET_MenuListBase`. Tree copied from the Gameplay
list: `CanvasPanel` with `SCROLLBOX_OptionsMenuList` (anchors 0,0 to 1,1, offsets top 25 and bottom
25, scrollbar thickness 8 x 8, padding 10) holding the `_OPTION_VR_*` rows, each in a `ScrollBoxSlot`
with padding 20. `InitializeList` override: parent call, `PanelItemListWidget = SCROLLBOX_OptionsMenuList`.
`InitializeItemArray` override: every child of the scroll box that casts to `WIDGET_MenuListItemBase`
(same as the game). The scrollbar materials can be set at runtime by path later; this is cosmetic.

**`_OPTION_VR_Toggle`**, child of `WIDGET_Settings_BinaryToggle`, and **`_OPTION_VR_Slider`**, child
of `WIDGET_Settings_Slider`. No tree, no own widgets. One instance variable `SettingName` (Name,
editable per instance) that keys into the settings store. Overrides, mirroring the game's rows:

| Function | Toggle | Slider |
|---|---|---|
| `UpdateVisuals` | `SetCheckboxValue(store.GetBool(SettingName))` | `WIDGET_Slider.SetSliderRealValue(store.GetFloat(SettingName))` |
| `IsDirty` | `GetCheckboxValue() != store.GetBool(SettingName)` | scaled slider value != stored |
| `IsDefault` | `GetCheckboxValue() == store.GetDefaultBool(SettingName)` | same with default |
| `ApplyDirtyValue` | `store.ApplyBool(SettingName, GetCheckboxValue())` (takes effect at once) | same with float |
| `AcceptCurrentValue` | `store.SetBool(SettingName, GetCheckboxValue())` (becomes the saved value) | same with float |
| `SelectDefaultValue` | `SetCheckboxValue(store.GetDefaultBool(SettingName))` | same with float |

Row instances in the list set `ItemName`, `ItemDescription`, `SettingName` and, for sliders, the
`Slider*` values. Both `ItemName` and `ItemDescription` are plain `Text`; the game's rows use
localised text, the mod's rows do not need to.

**Settings store `_BP_VRSettings`** (step 3). A Blueprint object the installer creates once and keeps
on the page, or a `SaveGame` subclass. Holds a map of setting name to value, a map of defaults, and
the functions used above. Where the values live on disk and how the plugin reads them is decided in
step 3; the first spike holds one toggle in memory.

### 3. Installer `_BP_VROptionsInstaller` (chunk 10)

A Blueprint function library or an object with one function `Install(WIDGET_OptionsScreen Screen)`.
It is called once per screen instance, after the game's `OnInitialized` has run (that is, after
`WIDGET_OptionsCategoryMenuList.MenuListItemArray` holds six items).

1. `CategoryList = Screen.WIDGET_OptionsCategoryMenuList`. If `VBOX_OptionCategoryWidgetList` already
   has seven children, return.
2. Create the category item: `CreateWidget(WIDGET_OptionCategoryMenuListItem)`. Before adding it to
   any panel: `ItemName = "VR"`, `ItemDescription = "..."`, `ENUM_OptionCategories = 0`, and replace
   `OptionCategoryIcon[0]` on the instance with the mod's icon material. `PreConstruct` then picks
   index 0, which is the mod's material, and writes the label. `AddChildToVerticalBox` on
   `VBOX_OptionCategoryWidgetList`, then copy the slot settings of the sixth item (padding and
   alignment; read them from `widgets.json` when building the generator).
3. `CategoryList.InitializeList(Screen)`. This re-numbers the items; the new one is index 6. It is
   safe because the category list has no `OPTION_Base` rows.
4. Create the page: `CreateWidget(_WIDGET_OptionsMenu_VR)`, `SetVisibility(Hidden)`.
   `Grid = Screen.WIDGET_OptionsMenu_Gameplay.GetParent().GetParent()` cast to `GridPanel`;
   `Grid.AddChildToGrid(Page)`, then on the returned `GridSlot`: `SetRow(1)`, `SetColumn(1)`. The
   game's pages sit in `ScaleBox`es with `Stretch = None`, which changes nothing, so the page goes
   straight into the cell.
5. `Page.InitializeMenu(Screen)`.
6. Bind `Item.OnCategoryButtonClicked` to `OnVRCategoryClicked`, bind `Page.OnCanApply` to
   `Screen.WIDGET_ButtonLegend_ApplyButton.ToggleInteractivity` and `Page.OnCanReset` to
   `Screen.WIDGET_ButtonLegend_ResetToDefaults.ToggleInteractivity` (through two small event
   functions, because the game's handler for Reset inverts the value: `CanReset` true means
   "everything is default", so the Reset button is disabled when it is true).
7. `Item.SetExpandedState(Screen.OpenedSubMenu is valid)`.

`OnVRCategoryClicked(int)` mirrors `TryOpenOptionSubMenu`:

1. If `Screen.OpenedSubMenu == Page`: return (second fire of the click).
2. `PlayAnimation = (Screen.OpenedSubMenu is not valid)`. If it is valid: `Screen.OpenedSubMenu.OnMenuClose()`.
3. `Screen.TryOpenSubMenu(Page)`; `CategoryList.SetSelectedItem(6)`.
4. If `PlayAnimation`: `Screen.PlayAnimation(ANIM_OpenOptionsSubscreen)` and
   `Screen.PlayAnimation(ANIM_ShowResetApplyButtons)` with the game's arguments (start 0, loops 1,
   forward, speed 1).
5. `SetExpandedState(true)` on every item of `CategoryList.MenuListItemArray`.

Nothing else is needed for the other directions:

- Clicking a game category while the VR page is open: `TryOpenOptionSubMenu` calls
  `OpenedSubMenu.OnMenuClose()` on the VR page and `SetSelectedItem` deselects item 6.
- Back, Apply, Reset: the nav chain reaches the VR page through `OpenedSubMenu`, exactly as for the
  game's pages. Apply also saves the game's own settings, which is harmless.
- Description box: works through `ParentScreenWidget.ParentMenu`, see above.

### 4. Plugin trigger

The plugin finds the live `WIDGET_OptionsScreen_C` instance and calls `Install` once for it. The
screen lives inside `WIDGET_MainMenu_InGame`, which is created with the HUD, so there is one
instance per level load. The check runs on the game thread, at most once per level change and
again only if the instance pointer changes: find the object, confirm its category list has six
items in `MenuListItemArray` (OnInitialized has run), call the installer through the BridgeSDK.
The installer's own "already has seven children" guard makes a repeated call safe.

## Risks and checks for the spike (step 2)

- A mod widget whose parent is a dummy with an empty tree must still get the parent's real tree in
  the game. The game's rows prove the engine does this for a cooked child; the spike confirms it
  for a child cooked in another package.
- The dummy `WIDGET_OptionsScreen` declares `ANIM_*` as plain variables. The game's class has them
  as transient animation variables. Reading them by name should work; if `PlayAnimation` gets null,
  skip the animation on the first spike and find another way to reach it afterwards.
- `OptionCategoryIcon` on the created item must be set on the instance before `PreConstruct` runs,
  which is when the item is first built in Slate, after `AddChildToVerticalBox`. Setting it before
  the add is enough.
- Gamepad navigation: `WIDGET_OptionsCategoryMenuList` navigates with `ReceiveNavUp/Down` over
  `MenuListItemArray`, so item 6 is reachable. `ReceiveNavAccept` on the item broadcasts the
  delegate the installer bound. To be confirmed in the headset.
- `WIDGET_OptionsCategoryMenuList.GetListItemByCategory` and `SelectedCategory` are not used for
  opening pages, so the seventh item needs no enum value.

## Work split

Claude writes the generator commandlet in `tools\UEVRBridgeGen\Source` that creates the dummies and
the mod widgets, the installer Blueprint, the plugin trigger, the settings store, and this document.
The user runs the generator and the cook, confirms the Blueprints compile in the editor, tests in
the headset, and picks the first set of VR options. The generator refuses to overwrite an asset that
already exists unless told to.
