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

// ---- row: _OPTION_VR_Slider -------------------------------------------------------------
//
// Same store as the toggle row, with float values. The current value is read with the
// game's GetScaledCurrentSliderValue (slider position mapped into min..max) and written
// with SetSliderRealValue on the slider control that GetSlider returns.

// GetCurrentValue() -> Value: the slider position mapped into min..max and snapped to Step.
// The game's slider does not snap a mouse drag to its discrete positions, so without this a
// row would report 5.32 while its text shows 5.
void SliderRowCurrentValue(FMenuGenBlueprint& BP)
{
    FMenuGenGraph G(BP.AddFunction(TEXT("GetCurrentValue"), {}, { FMenuGenParam{ TEXT("Value"), Float() } }, true));
    UEdGraphNode* Scaled = G.Call(BP.Class(), TEXT("GetScaledCurrentSliderValue"));
    UEdGraphNode* Snap = G.Call(UKismetMathLibrary::StaticClass(), TEXT("GridSnap_Float"));
    G.Link(Scaled, TEXT("Result"), Snap, TEXT("Location"));
    G.Link(G.Get(TEXT("Step")), TEXT("Step"), Snap, TEXT("GridSize"));
    G.Link(Snap, UEdGraphSchema_K2::PN_ReturnValue, G.Result(), TEXT("Value"));
    G.Then(G.Entry(), G.Result());
}

bool SliderRowMembers(FMenuGenBlueprint& BP)
{
    BP.AddVariable(TEXT("SettingName"), Name(), true);
    BP.AddVariable(TEXT("SavedValue"), Float(), true);
    BP.AddVariable(TEXT("DefaultValue"), Float(), true);
    BP.AddVariable(TEXT("Step"), Float(), true, TEXT("1.0"));
    SliderRowCurrentValue(BP);
    return true;
}

// Override body: parent call, then GetSlider().SetSliderRealValue(Variable) and
// GetSlider().UpdateBackgroundFill(). The second call is what the game's mouse path does
// through SetSliderValue; SetSliderRealValue alone leaves the bar's fill at the old value.
void SliderRowSetValue(FMenuGenBlueprint& BP, UClass* SliderWidget, const TCHAR* Function, const TCHAR* Variable)
{
    FMenuGenGraph G(BP.AddOverride(Function));
    UEdGraphNode* Slider = G.Call(BP.Class(), TEXT("GetSlider"));
    UEdGraphNode* Set = G.Call(SliderWidget, TEXT("SetSliderRealValue"));
    UEdGraphNode* Fill = G.Call(SliderWidget, TEXT("UpdateBackgroundFill"));
    G.Link(G.Pin(Slider, TEXT("Result"), EGPD_Output), G.SelfPin(Set));
    G.Link(G.Pin(Slider, TEXT("Result"), EGPD_Output), G.SelfPin(Fill));
    G.Then(G.Start(), Set);
    G.Link(G.Get(Variable), Variable, Set, TEXT("RealValue"));
    G.Then(Set, Fill);
    if (G.Result() != nullptr) G.Then(Fill, G.Result());
}

// Override body: NearlyEqual(GetCurrentValue(), Variable), negated for IsDirty. A tolerance
// instead of equality, because the value comes from a normalized slider position and can
// differ from the stored value in the last digits.
void SliderRowCompare(FMenuGenBlueprint& BP, const TCHAR* Function, const TCHAR* Variable, const TCHAR* OutPin, bool bNegate)
{
    FMenuGenGraph G(BP.AddOverride(Function));
    UEdGraphNode* Current = G.Call(BP.Class(), TEXT("GetCurrentValue"));
    UEdGraphNode* Near = G.Call(UKismetMathLibrary::StaticClass(), TEXT("NearlyEqual_FloatFloat"));
    G.Link(Current, TEXT("Value"), Near, TEXT("A"));
    G.Link(G.Get(Variable), Variable, Near, TEXT("B"));
    G.SetDefault(Near, TEXT("ErrorTolerance"), TEXT("0.001"));
    UEdGraphNode* Out = Near;
    if (bNegate)
    {
        Out = G.Call(UKismetMathLibrary::StaticClass(), TEXT("Not_PreBool"));
        G.Link(Near, UEdGraphSchema_K2::PN_ReturnValue, Out, TEXT("A"));
    }
    G.Link(Out, UEdGraphSchema_K2::PN_ReturnValue, G.Result(), OutPin);
    G.Then(G.Entry(), G.Result());
}

// Stores the snapped value, then UpdateVisuals() moves the handle onto that value, so a
// drag that stopped between two steps ends on the step after Apply.
void SliderRowAccept(FMenuGenBlueprint& BP)
{
    FMenuGenGraph G(BP.AddOverride(TEXT("AcceptCurrentValue")));
    UEdGraphNode* Current = G.Call(BP.Class(), TEXT("GetCurrentValue"));
    UEdGraphNode* Set = G.Set(TEXT("SavedValue"));
    UEdGraphNode* Visuals = G.Call(BP.Class(), TEXT("UpdateVisuals"));
    G.Then(G.Start(), Set);
    G.Link(Current, TEXT("Value"), Set, TEXT("SavedValue"));
    G.Then(Set, Visuals);
    if (G.Result() != nullptr) G.Then(Visuals, G.Result());
}

bool SliderRowLogic(FMenuGenBlueprint& BP, UClass* SliderWidget)
{
    SliderRowSetValue(BP, SliderWidget, TEXT("UpdateVisuals"), TEXT("SavedValue"));
    SliderRowSetValue(BP, SliderWidget, TEXT("SelectDefaultValue"), TEXT("DefaultValue"));
    SliderRowCompare(BP, TEXT("IsDirty"), TEXT("SavedValue"), TEXT("IsDirty"), true);
    SliderRowCompare(BP, TEXT("IsDefault"), TEXT("DefaultValue"), TEXT("Result"), false);
    SliderRowAccept(BP);
    return true;
}

// ---- list: _WIDGET_OptionsMenu_VRList --------------------------------------------------

// Adds one row widget to the scroll box as a named variable with the game's row padding.
UUserWidget* AddRow(FMenuGenBlueprint& BP, UScrollBox* Scroll, UClass* RowClass, const TCHAR* Name)
{
    UUserWidget* Row = BP.Widget()->WidgetTree->ConstructWidget<UUserWidget>(RowClass, Name);
    Row->bIsVariable = true;
    CastChecked<UScrollBoxSlot>(Scroll->AddChild(Row))->SetPadding(FMargin(20.f));
    return Row;
}

void FillSpikeToggle(UUserWidget* Row)
{
    SetProperty<FTextProperty>(Row, TEXT("ItemName"), FText::FromString(TEXT("VR spike toggle")));
    SetProperty<FTextProperty>(Row, TEXT("ItemDescription"), FText::FromString(TEXT("A test option of the VR mod. It does nothing yet.")));
    SetProperty<FNameProperty>(Row, TEXT("SettingName"), FName(TEXT("spike")));
    SetProperty<FBoolProperty>(Row, TEXT("DefaultValue"), true);
    SetProperty<FBoolProperty>(Row, TEXT("SavedValue"), true);
}

// Whole numbers 1..10, default 5. Ten discrete positions give the whole-number steps.
void FillLookSensitivity(UUserWidget* Row)
{
    SetProperty<FTextProperty>(Row, TEXT("ItemName"), FText::FromString(TEXT("VR Look Sensitivity")));
    SetProperty<FTextProperty>(Row, TEXT("ItemDescription"), FText::FromString(TEXT("How fast the view turns with the right thumbstick. 1 is the slowest, 10 the fastest.")));
    SetProperty<FNameProperty>(Row, TEXT("SettingName"), FName(TEXT("vr_look_sensitivity")));
    SetProperty<FFloatProperty>(Row, TEXT("DefaultValue"), 5.f);
    SetProperty<FFloatProperty>(Row, TEXT("SavedValue"), 5.f);
    SetProperty<FIntProperty>(Row, TEXT("SliderDiscreteValues"), 10);
    SetProperty<FFloatProperty>(Row, TEXT("SliderInitialValue"), 5.f);
    SetProperty<FFloatProperty>(Row, TEXT("SliderValueMin"), 1.f);
    SetProperty<FFloatProperty>(Row, TEXT("SliderValueMax"), 10.f);
    SetProperty<FIntProperty>(Row, TEXT("SliderFractionalDigits"), 0);
}

bool ListMembers(FMenuGenBlueprint& BP, const FMenuGenStore& Store)
{
    UCanvasPanel* Root = RootCanvas(BP.Widget());
    UScrollBox* Scroll = BP.Widget()->WidgetTree->ConstructWidget<UScrollBox>(UScrollBox::StaticClass(), TEXT("SCROLLBOX_OptionsMenuList"));
    Scroll->ScrollbarThickness = FVector2D(8.f, 8.f);
    Scroll->ScrollbarPadding = FMargin(10.f);
    FillCanvas(Root, Scroll, FMargin(0.f, 25.f, 0.f, 25.f));

    FillSpikeToggle(AddRow(BP, Scroll, Store.Find(MenuGenPaths::VRToggle), TEXT("OPTION_VR_Spike")));
    FillLookSensitivity(AddRow(BP, Scroll, Store.Find(MenuGenPaths::VRSlider), TEXT("OPTION_VR_LookSensitivity")));
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

// Returns the rows as an array of the item base class, in the order they sit in the scroll box.
void ListInitializeItemArray(FMenuGenBlueprint& BP, UClass* ItemBase)
{
    const TCHAR* Rows[] = { TEXT("OPTION_VR_Spike"), TEXT("OPTION_VR_LookSensitivity") };
    FMenuGenGraph G(BP.AddOverride(TEXT("InitializeItemArray")));
    UEdGraphNode* Array = G.MakeArray(UE_ARRAY_COUNT(Rows));
    for (int32 i = 0; i < UE_ARRAY_COUNT(Rows); ++i)
    {
        UK2Node_DynamicCast* Cast = G.Cast(ItemBase, true);
        G.Link(G.Get(Rows[i]), Rows[i], Cast, TEXT("Object"));
        G.Link(Cast->GetCastResultPin(), G.Pin(Array, *FString::Printf(TEXT("[%d]"), i), EGPD_Input));
    }
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

    UClass* SliderWidget = Store.Find(TEXT("SliderWidget"));
    const bool bSlider = ModWidget(Store, Options, MenuGenPaths::VRSlider, Store.Find(TEXT("Slider")), SliderRowMembers,
        [&](FMenuGenBlueprint& BP) { return SliderRowLogic(BP, SliderWidget); });
    if (!bSlider) return false;

    const bool bList = ModWidget(Store, Options, MenuGenPaths::VRList, Store.Find(TEXT("ListBase")),
        [&](FMenuGenBlueprint& BP) { return ListMembers(BP, Store); },
        [&](FMenuGenBlueprint& BP) { return ListLogic(BP, ItemBase); });
    if (!bList) return false;

    return ModWidget(Store, Options, MenuGenPaths::VRPage, Store.Find(TEXT("OptionsMenuBase")),
        [&](FMenuGenBlueprint& BP) { return PageMembers(BP, Store); },
        [&](FMenuGenBlueprint& BP) { return MenuGenPageLogic::Build(BP, Store); });
}
