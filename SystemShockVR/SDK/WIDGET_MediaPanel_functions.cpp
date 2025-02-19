#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: WIDGET_MediaPanel

#include "Basic.hpp"

#include "WIDGET_MediaPanel_classes.hpp"
#include "WIDGET_MediaPanel_parameters.hpp"


namespace SDK
{

// Function WIDGET_MediaPanel.WIDGET_MediaPanel_C.InitializeMediaPanel
// (Public, HasDefaults, BlueprintCallable, BlueprintEvent)
// Parameters:
// class UWIDGET_PlayerHUD_C*              HUD                                                    (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UWIDGET_MediaPanel_C::InitializeMediaPanel(class UWIDGET_PlayerHUD_C* HUD)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WIDGET_MediaPanel_C", "InitializeMediaPanel");

	Params::WIDGET_MediaPanel_C_InitializeMediaPanel Parms{};

	Parms.HUD = HUD;

	UObject::ProcessEvent(Func, &Parms);
}


// Function WIDGET_MediaPanel.WIDGET_MediaPanel_C.UpdateMediaListItems
// (Public, HasOutParams, HasDefaults, BlueprintCallable, BlueprintEvent)
// Parameters:
// TArray<class UITEM_MediaBase_C*>        NewMediaItems                                          (BlueprintVisible, BlueprintReadOnly, Parm, OutParm, ReferenceParm)
// bool                                    AutoHighlight                                          (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor)

void UWIDGET_MediaPanel_C::UpdateMediaListItems(TArray<class UITEM_MediaBase_C*>& NewMediaItems, bool AutoHighlight)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WIDGET_MediaPanel_C", "UpdateMediaListItems");

	Params::WIDGET_MediaPanel_C_UpdateMediaListItems Parms{};

	Parms.NewMediaItems = std::move(NewMediaItems);
	Parms.AutoHighlight = AutoHighlight;

	UObject::ProcessEvent(Func, &Parms);

	NewMediaItems = std::move(Parms.NewMediaItems);
}


// Function WIDGET_MediaPanel.WIDGET_MediaPanel_C.EVENT_OnAudiologsBagChanged
// (Public, HasDefaults, BlueprintCallable, BlueprintEvent)
// Parameters:
// int32                                   SlotIndex                                              (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UWIDGET_MediaPanel_C::EVENT_OnAudiologsBagChanged(int32 SlotIndex)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WIDGET_MediaPanel_C", "EVENT_OnAudiologsBagChanged");

	Params::WIDGET_MediaPanel_C_EVENT_OnAudiologsBagChanged Parms{};

	Parms.SlotIndex = SlotIndex;

	UObject::ProcessEvent(Func, &Parms);
}


// Function WIDGET_MediaPanel.WIDGET_MediaPanel_C.EVENT_OnEmailsBagChanged
// (Public, HasDefaults, BlueprintCallable, BlueprintEvent)
// Parameters:
// int32                                   SlotIndex                                              (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UWIDGET_MediaPanel_C::EVENT_OnEmailsBagChanged(int32 SlotIndex)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WIDGET_MediaPanel_C", "EVENT_OnEmailsBagChanged");

	Params::WIDGET_MediaPanel_C_EVENT_OnEmailsBagChanged Parms{};

	Parms.SlotIndex = SlotIndex;

	UObject::ProcessEvent(Func, &Parms);
}


// Function WIDGET_MediaPanel.WIDGET_MediaPanel_C.EVENT_OnNotesBagChanged
// (Public, HasDefaults, BlueprintCallable, BlueprintEvent)
// Parameters:
// int32                                   SlotIndex                                              (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UWIDGET_MediaPanel_C::EVENT_OnNotesBagChanged(int32 SlotIndex)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WIDGET_MediaPanel_C", "EVENT_OnNotesBagChanged");

	Params::WIDGET_MediaPanel_C_EVENT_OnNotesBagChanged Parms{};

	Parms.SlotIndex = SlotIndex;

	UObject::ProcessEvent(Func, &Parms);
}


// Function WIDGET_MediaPanel.WIDGET_MediaPanel_C.GetAllMediaItemsByFilter
// (Public, HasOutParams, HasDefaults, BlueprintCallable, BlueprintEvent)
// Parameters:
// ENUM_MediaTabFilterType                 Filter_Type                                            (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// TArray<class UITEM_MediaBase_C*>        MediaItems                                             (Parm, OutParm)

void UWIDGET_MediaPanel_C::GetAllMediaItemsByFilter(ENUM_MediaTabFilterType Filter_Type, TArray<class UITEM_MediaBase_C*>* MediaItems)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WIDGET_MediaPanel_C", "GetAllMediaItemsByFilter");

	Params::WIDGET_MediaPanel_C_GetAllMediaItemsByFilter Parms{};

	Parms.Filter_Type = Filter_Type;

	UObject::ProcessEvent(Func, &Parms);

	if (MediaItems != nullptr)
		*MediaItems = std::move(Parms.MediaItems);
}


// Function WIDGET_MediaPanel.WIDGET_MediaPanel_C.GetDeckMediaItemsByFilter
// (Public, HasOutParams, HasDefaults, BlueprintCallable, BlueprintEvent, BlueprintPure)
// Parameters:
// ENUM_MediaTabFilterType                 FilterType                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// class FString                           Deck                                                   (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, HasGetValueTypeHash)
// TArray<class UITEM_MediaBase_C*>        MediaItems                                             (Parm, OutParm)

void UWIDGET_MediaPanel_C::GetDeckMediaItemsByFilter(ENUM_MediaTabFilterType FilterType, const class FString& Deck, TArray<class UITEM_MediaBase_C*>* MediaItems)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WIDGET_MediaPanel_C", "GetDeckMediaItemsByFilter");

	Params::WIDGET_MediaPanel_C_GetDeckMediaItemsByFilter Parms{};

	Parms.FilterType = FilterType;
	Parms.Deck = std::move(Deck);

	UObject::ProcessEvent(Func, &Parms);

	if (MediaItems != nullptr)
		*MediaItems = std::move(Parms.MediaItems);
}


// Function WIDGET_MediaPanel.WIDGET_MediaPanel_C.SetMediaPanelVisibility
// (Public, BlueprintCallable, BlueprintEvent)
// Parameters:
// bool                                    Visibility_0                                           (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor)

void UWIDGET_MediaPanel_C::SetMediaPanelVisibility(bool Visibility_0)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WIDGET_MediaPanel_C", "SetMediaPanelVisibility");

	Params::WIDGET_MediaPanel_C_SetMediaPanelVisibility Parms{};

	Parms.Visibility_0 = Visibility_0;

	UObject::ProcessEvent(Func, &Parms);
}


// Function WIDGET_MediaPanel.WIDGET_MediaPanel_C.OnMediaCategorySelected
// (Public, HasDefaults, BlueprintCallable, BlueprintEvent)
// Parameters:
// class UWIDGET_MediaCategoryListElement_C*CategoryWidget                                         (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// bool                                    AutoHighlightFirstItem                                 (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor)

void UWIDGET_MediaPanel_C::OnMediaCategorySelected(class UWIDGET_MediaCategoryListElement_C* CategoryWidget, bool AutoHighlightFirstItem)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WIDGET_MediaPanel_C", "OnMediaCategorySelected");

	Params::WIDGET_MediaPanel_C_OnMediaCategorySelected Parms{};

	Parms.CategoryWidget = CategoryWidget;
	Parms.AutoHighlightFirstItem = AutoHighlightFirstItem;

	UObject::ProcessEvent(Func, &Parms);
}


// Function WIDGET_MediaPanel.WIDGET_MediaPanel_C.GetInventoryMediaItems
// (Public, HasOutParams, HasDefaults, BlueprintCallable, BlueprintEvent)
// Parameters:
// ENUM_ItemType                           ItemType                                               (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// TArray<class UITEM_MediaBase_C*>        Result                                                 (Parm, OutParm)

void UWIDGET_MediaPanel_C::GetInventoryMediaItems(ENUM_ItemType ItemType, TArray<class UITEM_MediaBase_C*>* Result)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WIDGET_MediaPanel_C", "GetInventoryMediaItems");

	Params::WIDGET_MediaPanel_C_GetInventoryMediaItems Parms{};

	Parms.ItemType = ItemType;

	UObject::ProcessEvent(Func, &Parms);

	if (Result != nullptr)
		*Result = std::move(Parms.Result);
}


// Function WIDGET_MediaPanel.WIDGET_MediaPanel_C.CountUnviewedMedia
// (Public, HasOutParams, BlueprintCallable, BlueprintEvent, BlueprintPure)
// Parameters:
// TArray<class UITEM_MediaBase_C*>        MediaItems                                             (BlueprintVisible, BlueprintReadOnly, Parm, OutParm, ReferenceParm)
// int32                                   UnviewedItemCount                                      (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UWIDGET_MediaPanel_C::CountUnviewedMedia(TArray<class UITEM_MediaBase_C*>& MediaItems, int32* UnviewedItemCount)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WIDGET_MediaPanel_C", "CountUnviewedMedia");

	Params::WIDGET_MediaPanel_C_CountUnviewedMedia Parms{};

	Parms.MediaItems = std::move(MediaItems);

	UObject::ProcessEvent(Func, &Parms);

	MediaItems = std::move(Parms.MediaItems);

	if (UnviewedItemCount != nullptr)
		*UnviewedItemCount = Parms.UnviewedItemCount;
}


// Function WIDGET_MediaPanel.WIDGET_MediaPanel_C.RefreshAllCategoryValues
// (Public, HasDefaults, BlueprintCallable, BlueprintEvent)

void UWIDGET_MediaPanel_C::RefreshAllCategoryValues()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WIDGET_MediaPanel_C", "RefreshAllCategoryValues");

	UObject::ProcessEvent(Func, nullptr);
}


// Function WIDGET_MediaPanel.WIDGET_MediaPanel_C.RefreshCategoryValues
// (Public, HasOutParams, HasDefaults, BlueprintCallable, BlueprintEvent)
// Parameters:
// class UWIDGET_MediaCategoryListElement_C*CategoryWidget                                         (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// int32                                   UnreadMessageCount                                     (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UWIDGET_MediaPanel_C::RefreshCategoryValues(class UWIDGET_MediaCategoryListElement_C* CategoryWidget, int32* UnreadMessageCount)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WIDGET_MediaPanel_C", "RefreshCategoryValues");

	Params::WIDGET_MediaPanel_C_RefreshCategoryValues Parms{};

	Parms.CategoryWidget = CategoryWidget;

	UObject::ProcessEvent(Func, &Parms);

	if (UnreadMessageCount != nullptr)
		*UnreadMessageCount = Parms.UnreadMessageCount;
}


// Function WIDGET_MediaPanel.WIDGET_MediaPanel_C.RefreshByMediaItem
// (Public, BlueprintCallable, BlueprintEvent)
// Parameters:
// class UITEM_MediaBase_C*                MediaItem                                              (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UWIDGET_MediaPanel_C::RefreshByMediaItem(class UITEM_MediaBase_C* MediaItem)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WIDGET_MediaPanel_C", "RefreshByMediaItem");

	Params::WIDGET_MediaPanel_C_RefreshByMediaItem Parms{};

	Parms.MediaItem = MediaItem;

	UObject::ProcessEvent(Func, &Parms);
}


// Function WIDGET_MediaPanel.WIDGET_MediaPanel_C.GetDeckWidgetByDeckSymbol
// (Public, HasOutParams, BlueprintCallable, BlueprintEvent, BlueprintPure)
// Parameters:
// class FString                           DeckSymbol                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, HasGetValueTypeHash)
// class UWIDGET_MediaCategoryListElement_C*DeckWidget                                             (Parm, OutParm, ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UWIDGET_MediaPanel_C::GetDeckWidgetByDeckSymbol(const class FString& DeckSymbol, class UWIDGET_MediaCategoryListElement_C** DeckWidget)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WIDGET_MediaPanel_C", "GetDeckWidgetByDeckSymbol");

	Params::WIDGET_MediaPanel_C_GetDeckWidgetByDeckSymbol Parms{};

	Parms.DeckSymbol = std::move(DeckSymbol);

	UObject::ProcessEvent(Func, &Parms);

	if (DeckWidget != nullptr)
		*DeckWidget = Parms.DeckWidget;
}


// Function WIDGET_MediaPanel.WIDGET_MediaPanel_C.GetCurrentDeckWidget
// (Public, HasOutParams, HasDefaults, BlueprintCallable, BlueprintEvent, BlueprintPure)
// Parameters:
// class UWIDGET_MediaCategoryListElement_C*DeckWidget                                             (Parm, OutParm, ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UWIDGET_MediaPanel_C::GetCurrentDeckWidget(class UWIDGET_MediaCategoryListElement_C** DeckWidget)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WIDGET_MediaPanel_C", "GetCurrentDeckWidget");

	Params::WIDGET_MediaPanel_C_GetCurrentDeckWidget Parms{};

	UObject::ProcessEvent(Func, &Parms);

	if (DeckWidget != nullptr)
		*DeckWidget = Parms.DeckWidget;
}


// Function WIDGET_MediaPanel.WIDGET_MediaPanel_C.GetCategoryWidgets
// (Public, HasOutParams, HasDefaults, BlueprintCallable, BlueprintEvent, BlueprintPure)
// Parameters:
// TArray<class UWIDGET_MediaCategoryListElement_C*>Widgets                                                (Parm, OutParm, ContainsInstancedReference)

void UWIDGET_MediaPanel_C::GetCategoryWidgets(TArray<class UWIDGET_MediaCategoryListElement_C*>* Widgets)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WIDGET_MediaPanel_C", "GetCategoryWidgets");

	Params::WIDGET_MediaPanel_C_GetCategoryWidgets Parms{};

	UObject::ProcessEvent(Func, &Parms);

	if (Widgets != nullptr)
		*Widgets = std::move(Parms.Widgets);
}


// Function WIDGET_MediaPanel.WIDGET_MediaPanel_C.OnMediaListItemSelected
// (Public, BlueprintCallable, BlueprintEvent)
// Parameters:
// class UWIDGET_MediaListElement_C*       MediaListItem                                          (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UWIDGET_MediaPanel_C::OnMediaListItemSelected(class UWIDGET_MediaListElement_C* MediaListItem)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WIDGET_MediaPanel_C", "OnMediaListItemSelected");

	Params::WIDGET_MediaPanel_C_OnMediaListItemSelected Parms{};

	Parms.MediaListItem = MediaListItem;

	UObject::ProcessEvent(Func, &Parms);
}


// Function WIDGET_MediaPanel.WIDGET_MediaPanel_C.GetAllMediaItems
// (Public, HasOutParams, HasDefaults, BlueprintCallable, BlueprintEvent)
// Parameters:
// TArray<class UITEM_MediaBase_C*>        Result                                                 (Parm, OutParm)

void UWIDGET_MediaPanel_C::GetAllMediaItems(TArray<class UITEM_MediaBase_C*>* Result)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WIDGET_MediaPanel_C", "GetAllMediaItems");

	Params::WIDGET_MediaPanel_C_GetAllMediaItems Parms{};

	UObject::ProcessEvent(Func, &Parms);

	if (Result != nullptr)
		*Result = std::move(Parms.Result);
}


// Function WIDGET_MediaPanel.WIDGET_MediaPanel_C.GetDeckSymbolFromMediaItem
// (Public, HasOutParams, HasDefaults, BlueprintCallable, BlueprintEvent, BlueprintPure)
// Parameters:
// class UITEM_MediaBase_C*                MediaItem                                              (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// class FString                           DeckSymbol                                             (Parm, OutParm, ZeroConstructor, HasGetValueTypeHash)

void UWIDGET_MediaPanel_C::GetDeckSymbolFromMediaItem(class UITEM_MediaBase_C* MediaItem, class FString* DeckSymbol)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WIDGET_MediaPanel_C", "GetDeckSymbolFromMediaItem");

	Params::WIDGET_MediaPanel_C_GetDeckSymbolFromMediaItem Parms{};

	Parms.MediaItem = MediaItem;

	UObject::ProcessEvent(Func, &Parms);

	if (DeckSymbol != nullptr)
		*DeckSymbol = std::move(Parms.DeckSymbol);
}


// Function WIDGET_MediaPanel.WIDGET_MediaPanel_C.ToggleReaderMode
// (Public, HasDefaults, BlueprintCallable, BlueprintEvent)
// Parameters:
// bool                                    ShowMedia                                              (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor)
// class UITEM_MediaBase_C*                MediaItem                                              (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UWIDGET_MediaPanel_C::ToggleReaderMode(bool ShowMedia, class UITEM_MediaBase_C* MediaItem)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WIDGET_MediaPanel_C", "ToggleReaderMode");

	Params::WIDGET_MediaPanel_C_ToggleReaderMode Parms{};

	Parms.ShowMedia = ShowMedia;
	Parms.MediaItem = MediaItem;

	UObject::ProcessEvent(Func, &Parms);
}


// Function WIDGET_MediaPanel.WIDGET_MediaPanel_C.ReadMedia
// (Public, BlueprintCallable, BlueprintEvent)
// Parameters:
// class UITEM_MediaBase_C*                MediaItem                                              (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UWIDGET_MediaPanel_C::ReadMedia(class UITEM_MediaBase_C* MediaItem)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WIDGET_MediaPanel_C", "ReadMedia");

	Params::WIDGET_MediaPanel_C_ReadMedia Parms{};

	Parms.MediaItem = MediaItem;

	UObject::ProcessEvent(Func, &Parms);
}


// Function WIDGET_MediaPanel.WIDGET_MediaPanel_C.InvokeNavManager
// (Public, BlueprintCallable, BlueprintEvent)
// Parameters:
// bool                                    InputState                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor)
// ENUM_MenuNavigationInput                InputType                                              (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UWIDGET_MediaPanel_C::InvokeNavManager(bool InputState, ENUM_MenuNavigationInput InputType)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WIDGET_MediaPanel_C", "InvokeNavManager");

	Params::WIDGET_MediaPanel_C_InvokeNavManager Parms{};

	Parms.InputState = InputState;
	Parms.InputType = InputType;

	UObject::ProcessEvent(Func, &Parms);
}


// Function WIDGET_MediaPanel.WIDGET_MediaPanel_C.SetHighlightedListItem
// (Public, BlueprintCallable, BlueprintEvent)
// Parameters:
// class UWIDGET_MediaListElement_C*       MediaListItem                                          (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UWIDGET_MediaPanel_C::SetHighlightedListItem(class UWIDGET_MediaListElement_C* MediaListItem)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WIDGET_MediaPanel_C", "SetHighlightedListItem");

	Params::WIDGET_MediaPanel_C_SetHighlightedListItem Parms{};

	Parms.MediaListItem = MediaListItem;

	UObject::ProcessEvent(Func, &Parms);
}


// Function WIDGET_MediaPanel.WIDGET_MediaPanel_C.SetHighlightedCategory
// (Public, BlueprintCallable, BlueprintEvent)
// Parameters:
// class UWIDGET_MediaCategoryListElement_C*CategoryWidget                                         (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UWIDGET_MediaPanel_C::SetHighlightedCategory(class UWIDGET_MediaCategoryListElement_C* CategoryWidget)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WIDGET_MediaPanel_C", "SetHighlightedCategory");

	Params::WIDGET_MediaPanel_C_SetHighlightedCategory Parms{};

	Parms.CategoryWidget = CategoryWidget;

	UObject::ProcessEvent(Func, &Parms);
}


// Function WIDGET_MediaPanel.WIDGET_MediaPanel_C.SetMediaCategoryCount
// (Public, HasDefaults, BlueprintCallable, BlueprintEvent)

void UWIDGET_MediaPanel_C::SetMediaCategoryCount()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WIDGET_MediaPanel_C", "SetMediaCategoryCount");

	UObject::ProcessEvent(Func, nullptr);
}


// Function WIDGET_MediaPanel.WIDGET_MediaPanel_C.ReceiveNavTabRight
// (Public, HasOutParams, BlueprintCallable, BlueprintEvent)
// Parameters:
// bool                                    InputState                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor)
// bool                                    Result                                                 (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor)

void UWIDGET_MediaPanel_C::ReceiveNavTabRight(bool InputState, bool* Result)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WIDGET_MediaPanel_C", "ReceiveNavTabRight");

	Params::WIDGET_MediaPanel_C_ReceiveNavTabRight Parms{};

	Parms.InputState = InputState;

	UObject::ProcessEvent(Func, &Parms);

	if (Result != nullptr)
		*Result = Parms.Result;
}


// Function WIDGET_MediaPanel.WIDGET_MediaPanel_C.ReceiveNavTabLeft
// (Public, HasOutParams, BlueprintCallable, BlueprintEvent)
// Parameters:
// bool                                    InputState                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor)
// bool                                    Result                                                 (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor)

void UWIDGET_MediaPanel_C::ReceiveNavTabLeft(bool InputState, bool* Result)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WIDGET_MediaPanel_C", "ReceiveNavTabLeft");

	Params::WIDGET_MediaPanel_C_ReceiveNavTabLeft Parms{};

	Parms.InputState = InputState;

	UObject::ProcessEvent(Func, &Parms);

	if (Result != nullptr)
		*Result = Parms.Result;
}


// Function WIDGET_MediaPanel.WIDGET_MediaPanel_C.ReceiveNavAlt2
// (Public, HasOutParams, BlueprintCallable, BlueprintEvent)
// Parameters:
// bool                                    InputState                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor)
// bool                                    Result                                                 (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor)

void UWIDGET_MediaPanel_C::ReceiveNavAlt2(bool InputState, bool* Result)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WIDGET_MediaPanel_C", "ReceiveNavAlt2");

	Params::WIDGET_MediaPanel_C_ReceiveNavAlt2 Parms{};

	Parms.InputState = InputState;

	UObject::ProcessEvent(Func, &Parms);

	if (Result != nullptr)
		*Result = Parms.Result;
}


// Function WIDGET_MediaPanel.WIDGET_MediaPanel_C.ReceiveNavAlt1
// (Public, HasOutParams, BlueprintCallable, BlueprintEvent)
// Parameters:
// bool                                    InputState                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor)
// bool                                    Result                                                 (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor)

void UWIDGET_MediaPanel_C::ReceiveNavAlt1(bool InputState, bool* Result)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WIDGET_MediaPanel_C", "ReceiveNavAlt1");

	Params::WIDGET_MediaPanel_C_ReceiveNavAlt1 Parms{};

	Parms.InputState = InputState;

	UObject::ProcessEvent(Func, &Parms);

	if (Result != nullptr)
		*Result = Parms.Result;
}


// Function WIDGET_MediaPanel.WIDGET_MediaPanel_C.ReceiveNavBack
// (Public, HasOutParams, BlueprintCallable, BlueprintEvent)
// Parameters:
// bool                                    InputState                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor)
// bool                                    Result                                                 (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor)

void UWIDGET_MediaPanel_C::ReceiveNavBack(bool InputState, bool* Result)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WIDGET_MediaPanel_C", "ReceiveNavBack");

	Params::WIDGET_MediaPanel_C_ReceiveNavBack Parms{};

	Parms.InputState = InputState;

	UObject::ProcessEvent(Func, &Parms);

	if (Result != nullptr)
		*Result = Parms.Result;
}


// Function WIDGET_MediaPanel.WIDGET_MediaPanel_C.ReceiveNavAccept
// (Public, HasOutParams, BlueprintCallable, BlueprintEvent)
// Parameters:
// bool                                    InputState                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor)
// bool                                    Result                                                 (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor)

void UWIDGET_MediaPanel_C::ReceiveNavAccept(bool InputState, bool* Result)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WIDGET_MediaPanel_C", "ReceiveNavAccept");

	Params::WIDGET_MediaPanel_C_ReceiveNavAccept Parms{};

	Parms.InputState = InputState;

	UObject::ProcessEvent(Func, &Parms);

	if (Result != nullptr)
		*Result = Parms.Result;
}


// Function WIDGET_MediaPanel.WIDGET_MediaPanel_C.ReceiveNavRight
// (Public, HasOutParams, BlueprintCallable, BlueprintEvent)
// Parameters:
// bool                                    InputState                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor)
// bool                                    Result                                                 (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor)

void UWIDGET_MediaPanel_C::ReceiveNavRight(bool InputState, bool* Result)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WIDGET_MediaPanel_C", "ReceiveNavRight");

	Params::WIDGET_MediaPanel_C_ReceiveNavRight Parms{};

	Parms.InputState = InputState;

	UObject::ProcessEvent(Func, &Parms);

	if (Result != nullptr)
		*Result = Parms.Result;
}


// Function WIDGET_MediaPanel.WIDGET_MediaPanel_C.ReceiveNavLeft
// (Public, HasOutParams, BlueprintCallable, BlueprintEvent)
// Parameters:
// bool                                    InputState                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor)
// bool                                    Result                                                 (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor)

void UWIDGET_MediaPanel_C::ReceiveNavLeft(bool InputState, bool* Result)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WIDGET_MediaPanel_C", "ReceiveNavLeft");

	Params::WIDGET_MediaPanel_C_ReceiveNavLeft Parms{};

	Parms.InputState = InputState;

	UObject::ProcessEvent(Func, &Parms);

	if (Result != nullptr)
		*Result = Parms.Result;
}


// Function WIDGET_MediaPanel.WIDGET_MediaPanel_C.ReceiveNavDown
// (Public, HasOutParams, HasDefaults, BlueprintCallable, BlueprintEvent)
// Parameters:
// bool                                    InputState                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor)
// bool                                    Result                                                 (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor)

void UWIDGET_MediaPanel_C::ReceiveNavDown(bool InputState, bool* Result)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WIDGET_MediaPanel_C", "ReceiveNavDown");

	Params::WIDGET_MediaPanel_C_ReceiveNavDown Parms{};

	Parms.InputState = InputState;

	UObject::ProcessEvent(Func, &Parms);

	if (Result != nullptr)
		*Result = Parms.Result;
}


// Function WIDGET_MediaPanel.WIDGET_MediaPanel_C.ReceiveNavUp
// (Public, HasOutParams, HasDefaults, BlueprintCallable, BlueprintEvent)
// Parameters:
// bool                                    InputState                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor)
// bool                                    Result                                                 (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor)

void UWIDGET_MediaPanel_C::ReceiveNavUp(bool InputState, bool* Result)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WIDGET_MediaPanel_C", "ReceiveNavUp");

	Params::WIDGET_MediaPanel_C_ReceiveNavUp Parms{};

	Parms.InputState = InputState;

	UObject::ProcessEvent(Func, &Parms);

	if (Result != nullptr)
		*Result = Parms.Result;
}

}

