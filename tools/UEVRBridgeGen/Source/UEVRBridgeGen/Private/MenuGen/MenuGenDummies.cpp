#include "MenuGenDummies.h"

#include "Animation/WidgetAnimation.h"
#include "Blueprint/UserWidget.h"
#include "BridgeGenLog.h"
#include "Components/PanelWidget.h"
#include "Components/VerticalBox.h"
#include "Engine/UserDefinedEnum.h"
#include "Kismet2/EnumEditorUtils.h"
#include "MenuGenAsset.h"
#include "MenuGenBlueprint.h"
#include "MenuGenStore.h"
#include "MenuGenTypes.h"

using namespace MenuGenPins;

namespace
{
using FFill = TFunctionRef<void(FMenuGenBlueprint&)>;

FMenuGenParam P(const TCHAR* Name, const FEdGraphPinType& Type)
{
    return FMenuGenParam{ FName(Name), Type };
}

// Creates one dummy widget Blueprint, or keeps the existing one, and records its class under Key.
bool Dummy(FMenuGenStore& Store, const FMenuGenOptions& Options, FName Key, const FString& Path, UClass* Parent, FFill Fill)
{
    TSharedPtr<FMenuGenBlueprint> BP;
    if (MenuGenAsset::Exists(Path) && !Options.bOverwrite)
    {
        BP = FMenuGenBlueprint::Load(Path);
    }
    else
    {
        BP = FMenuGenBlueprint::Create(Path, Parent, true);
        if (BP.IsValid())
        {
            Fill(*BP);
            if (!BP->Compile(TEXT("dummy")) || !BP->Save({})) return false;
        }
    }
    if (!BP.IsValid()) return false;
    Store.Add(Key, BP->Class());
    return true;
}

bool MakeEnum(FMenuGenStore& Store, const FMenuGenOptions& Options)
{
    const FString Path = MenuGenPaths::Categories;
    if (MenuGenAsset::Exists(Path) && !Options.bOverwrite)
    {
        Store.Categories = LoadObject<UUserDefinedEnum>(nullptr, *MenuGenAsset::ObjectPath(Path));
        return Store.Categories != nullptr;
    }
    UPackage* Package = MenuGenAsset::NewPackage(Path);
    UUserDefinedEnum* Enum = Cast<UUserDefinedEnum>(FEnumEditorUtils::CreateUserDefinedEnum(Package, *MenuGenAsset::NameOf(Path), RF_Public | RF_Standalone));
    if (Enum == nullptr) return false;

    const TCHAR* Names[] = { TEXT("Gameplay"), TEXT("Controls"), TEXT("Display"), TEXT("Graphics"), TEXT("Audio"), TEXT("Accessibility + Interface") };
    for (int32 i = 0; i < UE_ARRAY_COUNT(Names); ++i)
    {
        FEnumEditorUtils::AddNewEnumeratorForUserDefinedEnum(Enum);
        FEnumEditorUtils::SetEnumeratorDisplayName(Enum, i, FText::FromString(Names[i]));
    }
    Store.Categories = Enum;
    return MenuGenAsset::Save(Enum, {});
}

bool MakeMenuBase(FMenuGenStore& Store, const FMenuGenOptions& Options)
{
    return Dummy(Store, Options, TEXT("MenuBase"), MenuGenPaths::MenuBase, UUserWidget::StaticClass(), [](FMenuGenBlueprint& BP)
    {
        UClass* Self = BP.Class();
        BP.AddVariable(TEXT("ParentMenu"), Object(Self));
        BP.AddVariable(TEXT("ActiveMenuList"), Object(UUserWidget::StaticClass()));
        BP.AddVariable(TEXT("OpenedSubMenu"), Object(Self));
        BP.AddDispatcher(TEXT("OnCanApply"), { P(TEXT("CanApply"), Bool()) });
        BP.AddDispatcher(TEXT("OnCanReset"), { P(TEXT("CanReset"), Bool()) });
        BP.AddFunction(TEXT("InitializeMenu"), { P(TEXT("ParentMenuWidget"), Object(Self)) }, {}, false);
        BP.AddFunction(TEXT("OnMenuOpen"), {}, {}, false);
        BP.AddFunction(TEXT("OnMenuClose"), {}, {}, false);
        BP.AddFunction(TEXT("SetActiveMenuList"), { P(TEXT("Value"), Object(UUserWidget::StaticClass())) }, {}, false);
        BP.AddFunction(TEXT("TryOpenSubMenu"), { P(TEXT("SubMenu"), Object(Self)) }, {}, false);
        BP.AddFunction(TEXT("TryCloseSubMenu"), {}, {}, false);
    });
}

bool MakeItemBase(FMenuGenStore& Store, const FMenuGenOptions& Options)
{
    return Dummy(Store, Options, TEXT("ItemBase"), MenuGenPaths::ItemBase, UUserWidget::StaticClass(), [](FMenuGenBlueprint& BP)
    {
        BP.AddVariable(TEXT("ItemName"), Text(), true);
        BP.AddVariable(TEXT("ItemDescription"), Text(), true);
        BP.AddVariable(TEXT("IndexInList"), Int());
        BP.AddFunction(TEXT("InitializeMenuListItem"), { P(TEXT("ParentList"), Object(UUserWidget::StaticClass())), P(TEXT("Index"), Int()) }, {}, false);
    });
}

bool MakeListBase(FMenuGenStore& Store, const FMenuGenOptions& Options)
{
    UClass* MenuBase = Store.Find(TEXT("MenuBase"));
    UClass* ItemBase = Store.Find(TEXT("ItemBase"));
    return Dummy(Store, Options, TEXT("ListBase"), MenuGenPaths::ListBase, UUserWidget::StaticClass(), [&](FMenuGenBlueprint& BP)
    {
        BP.AddVariable(TEXT("MenuListItemArray"), Array(Object(ItemBase)));
        BP.AddVariable(TEXT("ParentScreenWidget"), Object(MenuBase));
        BP.AddVariable(TEXT("PanelItemListWidget"), Object(UPanelWidget::StaticClass()));
        BP.AddFunction(TEXT("InitializeList"), { P(TEXT("ParentScreen"), Object(MenuBase)) }, {}, false);
        BP.AddFunction(TEXT("InitializeItemArray"), {}, { P(TEXT("MenuListItems"), Array(Object(ItemBase))) }, false);
        BP.AddFunction(TEXT("EVENT_OnOptionChanged"), {}, {}, false);
    });
}

bool MakeOptionsMenuBase(FMenuGenStore& Store, const FMenuGenOptions& Options)
{
    return Dummy(Store, Options, TEXT("OptionsMenuBase"), MenuGenPaths::OptionsMenuBase, Store.Find(TEXT("MenuBase")), [](FMenuGenBlueprint&) {});
}

bool MakeOptionBase(FMenuGenStore& Store, const FMenuGenOptions& Options)
{
    return Dummy(Store, Options, TEXT("OptionBase"), MenuGenPaths::OptionBase, Store.Find(TEXT("ItemBase")), [](FMenuGenBlueprint& BP)
    {
        BP.AddDispatcher(TEXT("OnOptionChanged"), {});
        BP.AddFunction(TEXT("ApplyDirtyValue"), {}, {}, false);
        BP.AddFunction(TEXT("ApplyCleanValue"), {}, {}, false);
        BP.AddFunction(TEXT("IsDirty"), {}, { P(TEXT("IsDirty"), Bool()) }, true);
        BP.AddFunction(TEXT("SaveNewValue"), {}, {}, false);
        BP.AddFunction(TEXT("AcceptCurrentValue"), {}, {}, false);
        BP.AddFunction(TEXT("UpdateVisuals"), {}, {}, false);
        BP.AddFunction(TEXT("SelectDefaultValue"), {}, {}, false);
        BP.AddFunction(TEXT("IsDefault"), {}, { P(TEXT("Result"), Bool()) }, true);
    });
}

bool MakeToggle(FMenuGenStore& Store, const FMenuGenOptions& Options)
{
    return Dummy(Store, Options, TEXT("Toggle"), MenuGenPaths::Toggle, Store.Find(TEXT("OptionBase")), [](FMenuGenBlueprint& BP)
    {
        BP.AddFunction(TEXT("SetCheckboxValue"), { P(TEXT("Value"), Bool()) }, {}, false);
        BP.AddFunction(TEXT("GetCheckboxValue"), {}, { P(TEXT("Result"), Bool()) }, true);
        BP.AddFunction(TEXT("ToggleCheckbox"), {}, {}, false);
    });
}

bool MakeItem(FMenuGenStore& Store, const FMenuGenOptions& Options)
{
    UEnum* Categories = Store.Categories;
    return Dummy(Store, Options, TEXT("Item"), MenuGenPaths::Item, Store.Find(TEXT("ItemBase")), [&](FMenuGenBlueprint& BP)
    {
        BP.AddVariable(TEXT("ENUM_OptionCategories"), Byte(Categories), true);
        BP.AddVariable(TEXT("IsExpanded"), Bool());
        BP.AddDispatcher(TEXT("OnCategoryButtonClicked"), { P(TEXT("ItemIndex"), Int()) });
        BP.AddFunction(TEXT("SetExpandedState"), { P(TEXT("NewExpandedState"), Bool()) }, {}, false);
        BP.AddFunction(TEXT("SetCategorySelected"), { P(TEXT("NewSelectedState"), Bool()) }, {}, false);
    });
}

bool MakeCategoryList(FMenuGenStore& Store, const FMenuGenOptions& Options)
{
    return Dummy(Store, Options, TEXT("CategoryList"), MenuGenPaths::CategoryList, Store.Find(TEXT("ListBase")), [](FMenuGenBlueprint& BP)
    {
        BP.AddVariable(TEXT("VBOX_OptionCategoryWidgetList"), Object(UVerticalBox::StaticClass()));
        BP.AddFunction(TEXT("SetSelectedItem"), { P(TEXT("ItemIndex"), Int()) }, { P(TEXT("CategoryText"), Text()) }, false);
    });
}

bool MakeButtonLegend(FMenuGenStore& Store, const FMenuGenOptions& Options)
{
    return Dummy(Store, Options, TEXT("ButtonLegend"), MenuGenPaths::ButtonLegend, UUserWidget::StaticClass(), [](FMenuGenBlueprint& BP)
    {
        BP.AddFunction(TEXT("ToggleInteractivity"), { P(TEXT("IsInteractive"), Bool()) }, {}, false);
    });
}

bool MakeScreen(FMenuGenStore& Store, const FMenuGenOptions& Options)
{
    UClass* CategoryList = Store.Find(TEXT("CategoryList"));
    UClass* ButtonLegend = Store.Find(TEXT("ButtonLegend"));
    return Dummy(Store, Options, TEXT("Screen"), MenuGenPaths::Screen, Store.Find(TEXT("MenuBase")), [&](FMenuGenBlueprint& BP)
    {
        BP.AddVariable(TEXT("WIDGET_OptionsCategoryMenuList"), Object(CategoryList));
        BP.AddVariable(TEXT("WIDGET_OptionsMenu_Gameplay"), Object(UUserWidget::StaticClass()));
        BP.AddVariable(TEXT("WIDGET_ButtonLegend_ApplyButton"), Object(ButtonLegend));
        BP.AddVariable(TEXT("WIDGET_ButtonLegend_ResetToDefaults"), Object(ButtonLegend));
        BP.AddVariable(TEXT("ANIM_OpenOptionsSubscreen"), Object(UWidgetAnimation::StaticClass()));
        BP.AddVariable(TEXT("ANIM_ShowResetApplyButtons"), Object(UWidgetAnimation::StaticClass()));
        BP.AddFunction(TEXT("TryUpdateCategoryList"), {}, {}, false);
    });
}
} // namespace

bool MenuGenDummies::Generate(FMenuGenStore& Store, const FMenuGenOptions& Options)
{
    return MakeEnum(Store, Options)
        && MakeMenuBase(Store, Options)
        && MakeItemBase(Store, Options)
        && MakeListBase(Store, Options)
        && MakeOptionsMenuBase(Store, Options)
        && MakeOptionBase(Store, Options)
        && MakeToggle(Store, Options)
        && MakeItem(Store, Options)
        && MakeCategoryList(Store, Options)
        && MakeButtonLegend(Store, Options)
        && MakeScreen(Store, Options);
}
