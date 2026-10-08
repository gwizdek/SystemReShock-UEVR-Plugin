#include "MenuGenPageLogic.h"

#include "Blueprint/UserWidget.h"
#include "Blueprint/WidgetBlueprintLibrary.h"
#include "Components/GridPanel.h"
#include "Components/GridSlot.h"
#include "Components/VerticalBox.h"
#include "Components/Widget.h"
#include "K2Node_AddDelegate.h"
#include "K2Node_CreateDelegate.h"
#include "K2Node_DynamicCast.h"
#include "K2Node_FunctionEntry.h"
#include "K2Node_IfThenElse.h"
#include "Kismet/KismetMathLibrary.h"
#include "Kismet/KismetSystemLibrary.h"
#include "MenuGenBlueprint.h"
#include "MenuGenGraph.h"
#include "MenuGenStore.h"
#include "MenuGenTypes.h"

using namespace MenuGenPins;

namespace
{
// The game classes a page function talks to.
struct FPageClasses
{
    UClass* MenuBase;
    UClass* ListBase;
    UClass* ItemBase;
    UClass* Item;
    UClass* CategoryList;
    UClass* Screen;
    UClass* ButtonLegend;
    UClass* List;
};

FPageClasses ClassesOf(const FMenuGenStore& Store)
{
    return FPageClasses{
        Store.Find(TEXT("MenuBase")), Store.Find(TEXT("ListBase")), Store.Find(TEXT("ItemBase")), Store.Find(TEXT("Item")),
        Store.Find(TEXT("CategoryList")), Store.Find(TEXT("Screen")), Store.Find(TEXT("ButtonLegend")), Store.Find(MenuGenPaths::VRList) };
}

// Links a row of nodes exec-to-exec, starting after the function entry (or its parent call).
void Chain(FMenuGenGraph& G, std::initializer_list<UEdGraphNode*> Nodes)
{
    UEdGraphNode* Previous = G.Start();
    for (UEdGraphNode* Node : Nodes)
    {
        G.Then(Previous, Node);
        Previous = Node;
    }
}

// Output pin of a "Get Screen" node, or of a variable read on the screen.
UEdGraphPin* ScreenPin(FMenuGenGraph& G)
{
    return G.Pin(G.Get(TEXT("Screen")), TEXT("Screen"), EGPD_Output);
}

UEdGraphPin* ScreenMember(FMenuGenGraph& G, const FPageClasses& C, const TCHAR* Variable, UClass* Owner = nullptr)
{
    UEdGraphNode* Get = G.Get(Variable, Owner != nullptr ? Owner : C.Screen);
    G.Link(ScreenPin(G), G.SelfPin(Get));
    return G.Pin(Get, Variable, EGPD_Output);
}

UEdGraphPin* CategoryListPin(FMenuGenGraph& G, const FPageClasses& C)
{
    return ScreenMember(G, C, TEXT("WIDGET_OptionsCategoryMenuList"));
}

UEdGraphPin* OpenedSubMenuPin(FMenuGenGraph& G, const FPageClasses& C)
{
    return ScreenMember(G, C, TEXT("OpenedSubMenu"), C.MenuBase);
}

UEdGraphPin* IsValidPin(FMenuGenGraph& G, UEdGraphPin* Object)
{
    UEdGraphNode* IsValid = G.Call(UKismetSystemLibrary::StaticClass(), TEXT("IsValid"));
    G.Link(Object, G.Pin(IsValid, TEXT("Object"), EGPD_Input));
    return G.ReturnPin(IsValid);
}

UEdGraphPin* SelfOutPin(FMenuGenGraph& G)
{
    return G.Pin(G.Self(), UEdGraphSchema_K2::PN_Self, EGPD_Output);
}

// ---- InitializeMenu --------------------------------------------------------------------

void BuildInitializeMenu(FMenuGenBlueprint& Page, const FPageClasses& C)
{
    FMenuGenGraph G(Page.AddOverride(TEXT("InitializeMenu")));
    UEdGraphNode* Parent = G.Start();
    UEdGraphNode* InitList = G.Call(C.ListBase, TEXT("InitializeList"));
    UEdGraphNode* SetActive = G.Call(C.MenuBase, TEXT("SetActiveMenuList"));
    Chain(G, { InitList, SetActive });
    G.Link(G.Entry(), TEXT("ParentMenuWidget"), Parent, TEXT("ParentMenuWidget"));
    G.Link(G.Get(MenuGenPaths::VRList), MenuGenPaths::VRList, InitList, UEdGraphSchema_K2::PN_Self);
    G.Link(SelfOutPin(G), G.Pin(InitList, TEXT("ParentScreen"), EGPD_Input));
    G.Link(G.Get(MenuGenPaths::VRList), MenuGenPaths::VRList, SetActive, TEXT("Value"));
    if (G.Result() != nullptr) G.Then(SetActive, G.Result());
}

// ---- Install ---------------------------------------------------------------------------

// Creates the category item and stores it in CategoryItem. Returns the last exec node.
UEdGraphNode* InstallCreateItem(FMenuGenGraph& G, const FPageClasses& C)
{
    UEdGraphNode* Create = G.Call(UWidgetBlueprintLibrary::StaticClass(), TEXT("Create"));
    G.SetDefaultObject(Create, TEXT("WidgetType"), C.Item);
    UK2Node_DynamicCast* Cast = G.Cast(C.Item, true);
    G.Link(G.ReturnPin(Create), Cast->GetCastSourcePin());
    UEdGraphNode* Store = G.Set(TEXT("CategoryItem"));
    G.Link(Cast->GetCastResultPin(), G.Pin(Store, TEXT("CategoryItem"), EGPD_Input));

    UEdGraphNode* SetName = G.Set(TEXT("ItemName"), C.ItemBase);
    G.Link(G.Get(TEXT("CategoryItem")), TEXT("CategoryItem"), SetName, UEdGraphSchema_K2::PN_Self);
    G.SetDefaultText(SetName, TEXT("ItemName"), FText::FromString(TEXT("VR")));
    UEdGraphNode* SetDescription = G.Set(TEXT("ItemDescription"), C.ItemBase);
    G.Link(G.Get(TEXT("CategoryItem")), TEXT("CategoryItem"), SetDescription, UEdGraphSchema_K2::PN_Self);
    G.SetDefaultText(SetDescription, TEXT("ItemDescription"), FText::FromString(TEXT("Settings of the VR mod.")));

    UEdGraphNode* StoreScreen = G.Set(TEXT("Screen"));
    G.Link(G.Entry(), TEXT("Screen"), StoreScreen, TEXT("Screen"));
    Chain(G, { StoreScreen, Create, Store, SetName, SetDescription });
    return SetDescription;
}

// Adds the item to the category list and re-numbers the list.
UEdGraphNode* InstallAddItem(FMenuGenGraph& G, const FPageClasses& C, UEdGraphNode* After)
{
    UEdGraphNode* Add = G.Call(UVerticalBox::StaticClass(), TEXT("AddChildToVerticalBox"));
    UEdGraphNode* VBox = G.Get(TEXT("VBOX_OptionCategoryWidgetList"), C.CategoryList);
    G.Link(CategoryListPin(G, C), G.SelfPin(VBox));
    G.Link(VBox, TEXT("VBOX_OptionCategoryWidgetList"), Add, UEdGraphSchema_K2::PN_Self);
    G.Link(G.Get(TEXT("CategoryItem")), TEXT("CategoryItem"), Add, TEXT("Content"));

    UEdGraphNode* Init = G.Call(C.ListBase, TEXT("InitializeList"));
    G.Link(CategoryListPin(G, C), G.SelfPin(Init));
    G.Link(ScreenPin(G), G.Pin(Init, TEXT("ParentScreen"), EGPD_Input));

    G.Then(After, Add);
    G.Then(Add, Init);
    return Init;
}

// Puts the page into the grid cell that holds the game's pages, hidden, and initialises it.
UEdGraphNode* InstallAddPage(FMenuGenGraph& G, const FPageClasses& C, UEdGraphNode* After)
{
    UEdGraphNode* ParentOfGameplay = G.Call(UWidget::StaticClass(), TEXT("GetParent"));
    G.Link(ScreenMember(G, C, TEXT("WIDGET_OptionsMenu_Gameplay")), G.SelfPin(ParentOfGameplay));
    UEdGraphNode* Grid = G.Call(UWidget::StaticClass(), TEXT("GetParent"));
    G.Link(G.ReturnPin(ParentOfGameplay), G.SelfPin(Grid));
    UK2Node_DynamicCast* AsGrid = G.Cast(UGridPanel::StaticClass(), true);
    G.Link(G.ReturnPin(Grid), AsGrid->GetCastSourcePin());

    UEdGraphNode* Add = G.Call(UGridPanel::StaticClass(), TEXT("AddChildToGrid"));
    G.Link(AsGrid->GetCastResultPin(), G.SelfPin(Add));
    G.Link(SelfOutPin(G), G.Pin(Add, TEXT("Content"), EGPD_Input));
    UEdGraphNode* Row = G.Call(UGridSlot::StaticClass(), TEXT("SetRow"));
    G.Link(G.ReturnPin(Add), G.SelfPin(Row));
    G.SetDefault(Row, TEXT("InRow"), TEXT("1"));
    UEdGraphNode* Column = G.Call(UGridSlot::StaticClass(), TEXT("SetColumn"));
    G.Link(G.ReturnPin(Add), G.SelfPin(Column));
    G.SetDefault(Column, TEXT("InColumn"), TEXT("1"));

    UEdGraphNode* Hide = G.Call(UWidget::StaticClass(), TEXT("SetVisibility"));
    G.SetDefault(Hide, TEXT("InVisibility"), TEXT("Hidden"));
    UEdGraphNode* Init = G.Call(C.MenuBase, TEXT("InitializeMenu"));
    G.Link(ScreenPin(G), G.Pin(Init, TEXT("ParentMenuWidget"), EGPD_Input));

    G.Then(After, Add);
    G.Then(Add, Row);
    G.Then(Row, Column);
    G.Then(Column, Hide);
    G.Then(Hide, Init);
    return Init;
}

UEdGraphNode* BindHandler(FMenuGenGraph& G, FName Dispatcher, UClass* Owner, UEdGraphPin* Target, const TCHAR* Handler, UEdGraphNode* After)
{
    UK2Node_AddDelegate* Bind = G.Bind(Dispatcher, Owner);
    if (Target != nullptr) G.Link(Target, G.SelfPin(Bind));
    UK2Node_CreateDelegate* Event = G.Delegate(Handler);
    G.Link(Event->GetDelegateOutPin(), Bind->GetDelegatePin());
    G.Then(After, Bind);
    return Bind;
}

// Connects the item click and the page's Apply and Reset state to the page's handlers.
UEdGraphNode* InstallBind(FMenuGenGraph& G, const FPageClasses& C, UEdGraphNode* After)
{
    UEdGraphPin* Item = G.Pin(G.Get(TEXT("CategoryItem")), TEXT("CategoryItem"), EGPD_Output);
    UEdGraphNode* Last = BindHandler(G, TEXT("OnCategoryButtonClicked"), C.Item, Item, TEXT("OnVRCategoryClicked"), After);
    Last = BindHandler(G, TEXT("OnCanApply"), nullptr, nullptr, TEXT("OnVRCanApply"), Last);
    Last = BindHandler(G, TEXT("OnCanReset"), nullptr, nullptr, TEXT("OnVRCanReset"), Last);

    UEdGraphNode* Expand = G.Call(C.Item, TEXT("SetExpandedState"));
    G.Link(G.Get(TEXT("CategoryItem")), TEXT("CategoryItem"), Expand, UEdGraphSchema_K2::PN_Self);
    G.Link(IsValidPin(G, OpenedSubMenuPin(G, C)), G.Pin(Expand, TEXT("NewExpandedState"), EGPD_Input));
    G.Then(Last, Expand);
    return Expand;
}

void BuildInstall(FMenuGenBlueprint& Page, const FPageClasses& C)
{
    FMenuGenGraph G(Page.AddFunction(TEXT("Install"), { FMenuGenParam{ TEXT("Screen"), Object(C.Screen) } }, {}, false));
    UEdGraphNode* Last = InstallCreateItem(G, C);
    Last = InstallAddItem(G, C, Last);
    Last = InstallAddPage(G, C, Last);
    InstallBind(G, C, Last);
}

// ---- OnVRCategoryClicked ---------------------------------------------------------------

// Returns when the page is already open; otherwise remembers whether any page was open and closes it.
UEdGraphNode* ClickClosePrevious(FMenuGenGraph& G, const FPageClasses& C, UEdGraphNode*& OutOpenNext)
{
    UEdGraphNode* Same = G.Call(UKismetMathLibrary::StaticClass(), TEXT("EqualEqual_ObjectObject"));
    G.Link(OpenedSubMenuPin(G, C), G.Pin(Same, TEXT("A"), EGPD_Input));
    G.Link(SelfOutPin(G), G.Pin(Same, TEXT("B"), EGPD_Input));
    UK2Node_IfThenElse* IfSame = G.Branch();
    G.Link(G.ReturnPin(Same), IfSame->GetConditionPin());
    G.Then(G.Entry(), IfSame);

    UEdGraphNode* Remember = G.Set(TEXT("WasSubMenuOpen"));
    G.Link(IsValidPin(G, OpenedSubMenuPin(G, C)), G.Pin(Remember, TEXT("WasSubMenuOpen"), EGPD_Input));
    G.Link(IfSame->GetElsePin(), G.Pin(Remember, UEdGraphSchema_K2::PN_Execute, EGPD_Input));

    UK2Node_IfThenElse* IfOpen = G.Branch();
    G.Link(G.Get(TEXT("WasSubMenuOpen")), TEXT("WasSubMenuOpen"), IfOpen, UEdGraphSchema_K2::PN_Condition);
    G.Then(Remember, IfOpen);
    UEdGraphNode* Close = G.Call(C.MenuBase, TEXT("OnMenuClose"));
    G.Link(OpenedSubMenuPin(G, C), G.SelfPin(Close));
    G.Link(IfOpen->GetThenPin(), G.Pin(Close, UEdGraphSchema_K2::PN_Execute, EGPD_Input));

    OutOpenNext = IfOpen;
    return Close;
}

// Opens this page, selects the category item, and plays the open animations when nothing was open.
void ClickOpenSelf(FMenuGenGraph& G, const FPageClasses& C, UEdGraphNode* AfterClose, UK2Node_IfThenElse* IfOpen)
{
    UEdGraphNode* Open = G.Call(C.MenuBase, TEXT("TryOpenSubMenu"));
    G.Link(ScreenPin(G), G.SelfPin(Open));
    G.Link(SelfOutPin(G), G.Pin(Open, TEXT("SubMenu"), EGPD_Input));
    G.Then(AfterClose, Open);
    G.Link(IfOpen->GetElsePin(), G.Pin(Open, UEdGraphSchema_K2::PN_Execute, EGPD_Input));

    UEdGraphNode* Select = G.Call(C.CategoryList, TEXT("SetSelectedItem"));
    G.Link(CategoryListPin(G, C), G.SelfPin(Select));
    G.Link(G.Entry(), TEXT("ItemIndex"), Select, TEXT("ItemIndex"));
    G.Then(Open, Select);

    UK2Node_IfThenElse* IfWasOpen = G.Branch();
    G.Link(G.Get(TEXT("WasSubMenuOpen")), TEXT("WasSubMenuOpen"), IfWasOpen, UEdGraphSchema_K2::PN_Condition);
    G.Then(Select, IfWasOpen);
    UEdGraphNode* Update = G.Call(C.Screen, TEXT("TryUpdateCategoryList"));
    G.Link(ScreenPin(G), G.SelfPin(Update));
    G.Link(IfWasOpen->GetElsePin(), G.Pin(Update, UEdGraphSchema_K2::PN_Execute, EGPD_Input));
    UEdGraphNode* Buttons = G.Call(UUserWidget::StaticClass(), TEXT("PlayAnimation"));
    G.Link(ScreenPin(G), G.SelfPin(Buttons));
    G.Link(ScreenMember(G, C, TEXT("ANIM_ShowResetApplyButtons")), G.Pin(Buttons, TEXT("InAnimation"), EGPD_Input));
    G.Then(Update, Buttons);
}

void BuildCategoryClicked(FMenuGenBlueprint& Page, const FPageClasses& C)
{
    FMenuGenGraph G(Page.AddFunction(TEXT("OnVRCategoryClicked"), { FMenuGenParam{ TEXT("ItemIndex"), Int() } }, {}, false));
    UEdGraphNode* IfOpen = nullptr;
    UEdGraphNode* Close = ClickClosePrevious(G, C, IfOpen);
    ClickOpenSelf(G, C, Close, static_cast<UK2Node_IfThenElse*>(IfOpen));
}

// ---- OnVRCanApply / OnVRCanReset -------------------------------------------------------

void BuildButtonHandler(FMenuGenBlueprint& Page, const FPageClasses& C, const TCHAR* Function, const TCHAR* Param, const TCHAR* Button, bool bInvert)
{
    FMenuGenGraph G(Page.AddFunction(Function, { FMenuGenParam{ Param, Bool() } }, {}, false));
    UEdGraphNode* Toggle = G.Call(C.ButtonLegend, TEXT("ToggleInteractivity"));
    G.Link(ScreenMember(G, C, Button), G.SelfPin(Toggle));
    UEdGraphPin* Value = G.Pin(G.Entry(), Param, EGPD_Output);
    if (bInvert)
    {
        UEdGraphNode* Not = G.Call(UKismetMathLibrary::StaticClass(), TEXT("Not_PreBool"));
        G.Link(Value, G.Pin(Not, TEXT("A"), EGPD_Input));
        Value = G.ReturnPin(Not);
    }
    G.Link(Value, G.Pin(Toggle, TEXT("IsInteractive"), EGPD_Input));
    G.Then(G.Entry(), Toggle);
}
} // namespace

bool MenuGenPageLogic::Build(FMenuGenBlueprint& Page, const FMenuGenStore& Store)
{
    const FPageClasses C = ClassesOf(Store);
    BuildInitializeMenu(Page, C);
    BuildButtonHandler(Page, C, TEXT("OnVRCanApply"), TEXT("CanApply"), TEXT("WIDGET_ButtonLegend_ApplyButton"), false);
    BuildButtonHandler(Page, C, TEXT("OnVRCanReset"), TEXT("CanReset"), TEXT("WIDGET_ButtonLegend_ResetToDefaults"), true);
    BuildCategoryClicked(Page, C);
    BuildInstall(Page, C);
    return true;
}
