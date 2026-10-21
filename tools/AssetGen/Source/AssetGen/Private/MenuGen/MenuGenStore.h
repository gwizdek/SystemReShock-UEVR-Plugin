#pragma once

#include "AssetGen/AssetGenContext.h"
#include "CoreMinimal.h"

// Options of the VR options page generator, set by MenuGen::Generate.
struct FMenuGenOptions
{
    // Content path that receives the mod's widgets, for example /Game/Mods/UI/Options.
    FString ModRoot;
    // Create an asset again although its package already exists.
    bool bOverwrite = false;
};

// Package paths of the game's classes that get a dummy, keyed by a short name.
namespace MenuGenPaths
{
constexpr const TCHAR* MenuBase = TEXT("/Game/Blueprints/UI/Generic/WIDGET_MenuBase");
constexpr const TCHAR* ListBase = TEXT("/Game/Blueprints/UI/Generic/WIDGET_MenuListBase");
constexpr const TCHAR* ItemBase = TEXT("/Game/Blueprints/UI/Generic/WIDGET_MenuListItemBase");
constexpr const TCHAR* OptionsMenuBase = TEXT("/Game/Blueprints/UI/MainMenu/OptionsScreen/WIDGET_OptionsMenu_Base");
constexpr const TCHAR* OptionBase = TEXT("/Game/Blueprints/UI/MainMenu/OptionsScreen/OptionsCategories/OPTION_Base");
constexpr const TCHAR* Toggle = TEXT("/Game/Blueprints/UI/MainMenu/OptionsScreen/OptionsCategories/WIDGET_Settings_BinaryToggle");
constexpr const TCHAR* Slider = TEXT("/Game/Blueprints/UI/MainMenu/OptionsScreen/OptionsCategories/WIDGET_Settings_Slider");
constexpr const TCHAR* SliderWidget = TEXT("/Game/Blueprints/UI/MainMenu/OptionsScreen/OptionsCategories/WIDGET_Slider");
constexpr const TCHAR* Item = TEXT("/Game/Blueprints/UI/MainMenu/OptionsScreen/WIDGET_OptionCategoryMenuListItem");
constexpr const TCHAR* CategoryList = TEXT("/Game/Blueprints/UI/MainMenu/OptionsScreen/WIDGET_OptionsCategoryMenuList");
constexpr const TCHAR* Screen = TEXT("/Game/Blueprints/UI/MainMenu/OptionsScreen/WIDGET_OptionsScreen");
// A group title in an options list, for example "General". A plain UserWidget, not a list item.
constexpr const TCHAR* CategoryHeader = TEXT("/Game/Blueprints/UI/MainMenu/OptionsScreen/OptionsCategories/Controls/WIDGET_ListCategoryHeader");
constexpr const TCHAR* ButtonLegend = TEXT("/Game/Blueprints/UI/HUD/Widgets/ButtonLegend/WIDGET_ButtonLegend_Button");
constexpr const TCHAR* Categories = TEXT("/Game/Blueprints/UI/MainMenu/OptionsScreen/ENUM_OptionCategories");

constexpr const TCHAR* IconTexture = TEXT("T_OptionsIcons_VR");
constexpr const TCHAR* IconMaterial = TEXT("MAT_OptionsIcons_VR");
// The icon image, relative to the generator plugin's folder. Drawn by draw_vr_icon.py there.
constexpr const TCHAR* IconSource = TEXT("Resources/MenuGen/T_OptionsIcons_VR.png");

constexpr const TCHAR* VRToggle = TEXT("_OPTION_VR_Toggle");
constexpr const TCHAR* VRSlider = TEXT("_OPTION_VR_Slider");
constexpr const TCHAR* VRList = TEXT("_WIDGET_OptionsMenu_VRList");
constexpr const TCHAR* VRPage = TEXT("_WIDGET_OptionsMenu_VR");
} // namespace MenuGenPaths

// Generated classes, keyed by the short names above, so later assets can refer to earlier ones.
struct FMenuGenStore
{
    TMap<FName, UClass*> Classes;
    UEnum* Categories = nullptr;
    // The VR category icon, set on the category item by the page's Install function.
    class UMaterial* IconMaterial = nullptr;
    // The dummy of the game's tint collection, from FAssetGenContext. The icon material reads it.
    class UMaterialParameterCollection* TintCollection = nullptr;

    void Add(FName Key, UClass* Class) { Classes.Add(Key, Class); }

    UClass* Find(FName Key) const
    {
        UClass* const* Found = Classes.Find(Key);
        return Found != nullptr ? *Found : nullptr;
    }
};
