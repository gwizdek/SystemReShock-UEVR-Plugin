#include "MenuGenModWidgets.h"

#include "Blueprint/UserWidget.h"
#include "Blueprint/WidgetTree.h"
#include "BridgeGenLog.h"
#include "Components/CanvasPanel.h"
#include "Components/CanvasPanelSlot.h"
#include "Components/Image.h"
#include "Components/ScrollBox.h"
#include "Components/ScrollBoxSlot.h"
#include "Kismet/KismetMathLibrary.h"
#include "MenuGenAsset.h"
#include "MenuGenBlueprint.h"
#include "MenuGenGraph.h"
#include "MenuGenPageLogic.h"
#include "MenuGenStore.h"
#include "MenuGenTypes.h"
#include "WidgetBlueprint.h"

using namespace MenuGenPins;

namespace
{
// Sets a Blueprint property of a widget template by name. Used for values of the dummy
// parent classes, which have no C++ members.
template <class PropertyType, class ValueType>
void SetProperty(UObject* Object, const TCHAR* Name, const ValueType& Value)
{
    PropertyType* Property = FindFProperty<PropertyType>(Object->GetClass(), Name);
    if (Property == nullptr)
    {
        UE_LOG(LogUEVRBridgeGen, Error, TEXT("%s has no property %s"), *Object->GetClass()->GetName(), Name);
        return;
    }
    Property->SetPropertyValue_InContainer(Object, Value);
}

UCanvasPanel* RootCanvas(UWidgetBlueprint* Widget)
{
    UCanvasPanel* Root = Widget->WidgetTree->ConstructWidget<UCanvasPanel>(UCanvasPanel::StaticClass(), TEXT("CanvasPanel_0"));
    Widget->WidgetTree->RootWidget = Root;
    return Root;
}

// Adds a child that fills the whole canvas, with the given extra offsets.
UCanvasPanelSlot* FillCanvas(UCanvasPanel* Canvas, UWidget* Child, const FMargin& Offsets)
{
    Child->bIsVariable = true;
    UCanvasPanelSlot* Slot = Canvas->AddChildToCanvas(Child);
    Slot->SetAnchors(FAnchors(0.f, 0.f, 1.f, 1.f));
    Slot->SetOffsets(Offsets);
    return Slot;
}

// Runs the asset steps shared by the three widgets: exists check, create, members, trees, logic, save.
using FBuild = TFunctionRef<bool(FMenuGenBlueprint&)>;

bool ModWidget(FMenuGenStore& Store, const FMenuGenOptions& Options, FName Key, UClass* Parent, FBuild Members, FBuild Logic)
{
    const FString Path = Options.ModRoot / Key.ToString();
    TSharedPtr<FMenuGenBlueprint> BP;
    if (MenuGenAsset::Exists(Path) && !Options.bOverwrite)
    {
        BP = FMenuGenBlueprint::Load(Path);
        if (!BP.IsValid()) return false;
        Store.Add(Key, BP->Class());
        return true;
    }
    BP = FMenuGenBlueprint::Create(Path, Parent, true);
    if (!BP.IsValid() || !Members(*BP) || !BP->Compile(TEXT("members"))) return false;
    if (!Logic(*BP) || !BP->Compile(TEXT("logic")) || !BP->Save({ MenuGenPaths::ModChunk })) return false;
    Store.Add(Key, BP->Class());
    return true;
}

// ---- row: _OPTION_VR_Toggle -------------------------------------------------------------

bool RowMembers(FMenuGenBlueprint& BP)
{
    BP.AddVariable(TEXT("SettingName"), Name(), true);
    BP.AddVariable(TEXT("SavedValue"), Bool(), true);
    BP.AddVariable(TEXT("DefaultValue"), Bool(), true);
    return true;
}

void RowSetCheckbox(FMenuGenBlueprint& BP, const TCHAR* Function, const TCHAR* Variable)
{
    FMenuGenGraph G(BP.AddOverride(Function));
    UEdGraphNode* Call = G.Call(BP.Class(), TEXT("SetCheckboxValue"));
    G.Then(G.Start(), Call);
    G.Link(G.Get(Variable), Variable, Call, TEXT("Value"));
    if (G.Result() != nullptr) G.Then(Call, G.Result());
}

void RowCompare(FMenuGenBlueprint& BP, const TCHAR* Function, const TCHAR* Variable, const TCHAR* Compare, const TCHAR* OutPin)
{
    FMenuGenGraph G(BP.AddOverride(Function));
    UEdGraphNode* Current = G.Call(BP.Class(), TEXT("GetCheckboxValue"));
    UEdGraphNode* Cmp = G.Call(UKismetMathLibrary::StaticClass(), Compare);
    G.Link(Current, TEXT("Result"), Cmp, TEXT("A"));
    G.Link(G.Get(Variable), Variable, Cmp, TEXT("B"));
    G.Link(Cmp, UEdGraphSchema_K2::PN_ReturnValue, G.Result(), OutPin);
    G.Then(G.Entry(), G.Result());
}

void RowAccept(FMenuGenBlueprint& BP)
{
    FMenuGenGraph G(BP.AddOverride(TEXT("AcceptCurrentValue")));
    UEdGraphNode* Current = G.Call(BP.Class(), TEXT("GetCheckboxValue"));
    UEdGraphNode* Set = G.Set(TEXT("SavedValue"));
    G.Then(G.Start(), Set);
    G.Link(Current, TEXT("Result"), Set, TEXT("SavedValue"));
    if (G.Result() != nullptr) G.Then(Set, G.Result());
}

bool RowLogic(FMenuGenBlueprint& BP)
{
    RowSetCheckbox(BP, TEXT("UpdateVisuals"), TEXT("SavedValue"));
    RowSetCheckbox(BP, TEXT("SelectDefaultValue"), TEXT("DefaultValue"));
    RowCompare(BP, TEXT("IsDirty"), TEXT("SavedValue"), TEXT("NotEqual_BoolBool"), TEXT("IsDirty"));
    RowCompare(BP, TEXT("IsDefault"), TEXT("DefaultValue"), TEXT("EqualEqual_BoolBool"), TEXT("Result"));
    RowAccept(BP);
    return true;
}

// ---- list: _WIDGET_OptionsMenu_VRList --------------------------------------------------

bool ListMembers(FMenuGenBlueprint& BP, UClass* RowClass)
{
    UCanvasPanel* Root = RootCanvas(BP.Widget());
    UScrollBox* Scroll = BP.Widget()->WidgetTree->ConstructWidget<UScrollBox>(UScrollBox::StaticClass(), TEXT("SCROLLBOX_OptionsMenuList"));
    Scroll->ScrollbarThickness = FVector2D(8.f, 8.f);
    Scroll->ScrollbarPadding = FMargin(10.f);
    FillCanvas(Root, Scroll, FMargin(0.f, 25.f, 0.f, 25.f));

    UUserWidget* Row = BP.Widget()->WidgetTree->ConstructWidget<UUserWidget>(RowClass, TEXT("OPTION_VR_Spike"));
    Row->bIsVariable = true;
    SetProperty<FTextProperty>(Row, TEXT("ItemName"), FText::FromString(TEXT("VR spike toggle")));
    SetProperty<FTextProperty>(Row, TEXT("ItemDescription"), FText::FromString(TEXT("A test option of the VR mod. It does nothing yet.")));
    SetProperty<FNameProperty>(Row, TEXT("SettingName"), FName(TEXT("spike")));
    SetProperty<FBoolProperty>(Row, TEXT("DefaultValue"), true);
    SetProperty<FBoolProperty>(Row, TEXT("SavedValue"), true);
    CastChecked<UScrollBoxSlot>(Scroll->AddChild(Row))->SetPadding(FMargin(20.f));
    return true;
}

void ListInitializeList(FMenuGenBlueprint& BP)
{
    FMenuGenGraph G(BP.AddOverride(TEXT("InitializeList")));
    UEdGraphNode* Parent = G.Start();
    UEdGraphNode* Set = G.Set(TEXT("PanelItemListWidget"));
    G.Link(G.Entry(), TEXT("ParentScreen"), Parent, TEXT("ParentScreen"));
    G.Then(Parent, Set);
    G.Link(G.Get(TEXT("SCROLLBOX_OptionsMenuList")), TEXT("SCROLLBOX_OptionsMenuList"), Set, TEXT("PanelItemListWidget"));
    if (G.Result() != nullptr) G.Then(Set, G.Result());
}

void ListInitializeItemArray(FMenuGenBlueprint& BP, UClass* ItemBase)
{
    FMenuGenGraph G(BP.AddOverride(TEXT("InitializeItemArray")));
    UK2Node_DynamicCast* Cast = G.Cast(ItemBase, true);
    G.Link(G.Get(TEXT("OPTION_VR_Spike")), TEXT("OPTION_VR_Spike"), Cast, TEXT("Object"));
    UEdGraphNode* Array = G.MakeArray(1);
    G.Link(Cast->GetCastResultPin(), G.Pin(Array, TEXT("[0]"), EGPD_Input));
    G.Link(Array, TEXT("Array"), G.Result(), TEXT("MenuListItems"));
    G.Then(G.Start(), G.Result());
}

bool ListLogic(FMenuGenBlueprint& BP, UClass* ItemBase)
{
    ListInitializeList(BP);
    ListInitializeItemArray(BP, ItemBase);
    return true;
}

// ---- page: _WIDGET_OptionsMenu_VR ------------------------------------------------------

bool PageMembers(FMenuGenBlueprint& BP, const FMenuGenStore& Store)
{
    BP.AddVariable(TEXT("Screen"), Object(Store.Find(TEXT("Screen"))));
    BP.AddVariable(TEXT("CategoryItem"), Object(Store.Find(TEXT("Item"))));
    BP.AddVariable(TEXT("WasSubMenuOpen"), Bool());

    UCanvasPanel* Root = RootCanvas(BP.Widget());
    UImage* Background = BP.Widget()->WidgetTree->ConstructWidget<UImage>(UImage::StaticClass(), TEXT("IMAGE_PanelBackground"));
    Background->Brush.Margin = FMargin(1.f);
    Background->SetVisibility(ESlateVisibility::HitTestInvisible);
    FillCanvas(Root, Background, FMargin(0.f));

    UUserWidget* List = BP.Widget()->WidgetTree->ConstructWidget<UUserWidget>(Store.Find(MenuGenPaths::VRList), MenuGenPaths::VRList);
    FillCanvas(Root, List, FMargin(0.f));
    return true;
}
} // namespace

bool MenuGenModWidgets::Generate(FMenuGenStore& Store, const FMenuGenOptions& Options)
{
    UClass* ItemBase = Store.Find(TEXT("ItemBase"));
    const bool bRow = ModWidget(Store, Options, MenuGenPaths::VRToggle, Store.Find(TEXT("Toggle")), RowMembers, RowLogic);
    if (!bRow) return false;

    const bool bList = ModWidget(Store, Options, MenuGenPaths::VRList, Store.Find(TEXT("ListBase")),
        [&](FMenuGenBlueprint& BP) { return ListMembers(BP, Store.Find(MenuGenPaths::VRToggle)); },
        [&](FMenuGenBlueprint& BP) { return ListLogic(BP, ItemBase); });
    if (!bList) return false;

    return ModWidget(Store, Options, MenuGenPaths::VRPage, Store.Find(TEXT("OptionsMenuBase")),
        [&](FMenuGenBlueprint& BP) { return PageMembers(BP, Store); },
        [&](FMenuGenBlueprint& BP) { return MenuGenPageLogic::Build(BP, Store); });
}
