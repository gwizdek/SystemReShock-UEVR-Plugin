#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: WIDGET_MediaReaderPanel

#include "Basic.hpp"

#include "WIDGET_MediaReaderPanel_classes.hpp"
#include "WIDGET_MediaReaderPanel_parameters.hpp"


namespace SDK
{

// Function WIDGET_MediaReaderPanel.WIDGET_MediaReaderPanel_C.ExecuteUbergraph_WIDGET_MediaReaderPanel
// (Final, UbergraphFunction, HasDefaults)
// Parameters:
// int32                                   EntryPoint                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UWIDGET_MediaReaderPanel_C::ExecuteUbergraph_WIDGET_MediaReaderPanel(int32 EntryPoint)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WIDGET_MediaReaderPanel_C", "ExecuteUbergraph_WIDGET_MediaReaderPanel");

	Params::WIDGET_MediaReaderPanel_C_ExecuteUbergraph_WIDGET_MediaReaderPanel Parms{};

	Parms.EntryPoint = EntryPoint;

	UObject::ProcessEvent(Func, &Parms);
}


// Function WIDGET_MediaReaderPanel.WIDGET_MediaReaderPanel_C.BndEvt__WIDGET_MediaReaderPanel_WIDGET_ButtonLegend_Button_2_K2Node_ComponentBoundEvent_1_OnClicked__DelegateSignature
// (BlueprintEvent)
// Parameters:
// struct FGeometry                        Geometry                                               (BlueprintVisible, BlueprintReadOnly, Parm, IsPlainOldData, NoDestructor)
// struct FPointerEvent                    InputEvent                                             (BlueprintVisible, BlueprintReadOnly, Parm)

void UWIDGET_MediaReaderPanel_C::BndEvt__WIDGET_MediaReaderPanel_WIDGET_ButtonLegend_Button_2_K2Node_ComponentBoundEvent_1_OnClicked__DelegateSignature(const struct FGeometry& Geometry, const struct FPointerEvent& InputEvent)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WIDGET_MediaReaderPanel_C", "BndEvt__WIDGET_MediaReaderPanel_WIDGET_ButtonLegend_Button_2_K2Node_ComponentBoundEvent_1_OnClicked__DelegateSignature");

	Params::WIDGET_MediaReaderPanel_C_BndEvt__WIDGET_MediaReaderPanel_WIDGET_ButtonLegend_Button_2_K2Node_ComponentBoundEvent_1_OnClicked__DelegateSignature Parms{};

	Parms.Geometry = std::move(Geometry);
	Parms.InputEvent = std::move(InputEvent);

	UObject::ProcessEvent(Func, &Parms);
}


// Function WIDGET_MediaReaderPanel.WIDGET_MediaReaderPanel_C.BndEvt__WIDGET_MediaReaderPanel_WIDGET_ButtonLegend_Button_K2Node_ComponentBoundEvent_0_OnClicked__DelegateSignature
// (BlueprintEvent)
// Parameters:
// struct FGeometry                        Geometry                                               (BlueprintVisible, BlueprintReadOnly, Parm, IsPlainOldData, NoDestructor)
// struct FPointerEvent                    InputEvent                                             (BlueprintVisible, BlueprintReadOnly, Parm)

void UWIDGET_MediaReaderPanel_C::BndEvt__WIDGET_MediaReaderPanel_WIDGET_ButtonLegend_Button_K2Node_ComponentBoundEvent_0_OnClicked__DelegateSignature(const struct FGeometry& Geometry, const struct FPointerEvent& InputEvent)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WIDGET_MediaReaderPanel_C", "BndEvt__WIDGET_MediaReaderPanel_WIDGET_ButtonLegend_Button_K2Node_ComponentBoundEvent_0_OnClicked__DelegateSignature");

	Params::WIDGET_MediaReaderPanel_C_BndEvt__WIDGET_MediaReaderPanel_WIDGET_ButtonLegend_Button_K2Node_ComponentBoundEvent_0_OnClicked__DelegateSignature Parms{};

	Parms.Geometry = std::move(Geometry);
	Parms.InputEvent = std::move(InputEvent);

	UObject::ProcessEvent(Func, &Parms);
}


// Function WIDGET_MediaReaderPanel.WIDGET_MediaReaderPanel_C.Construct
// (BlueprintCosmetic, Event, Public, BlueprintEvent)

void UWIDGET_MediaReaderPanel_C::Construct()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WIDGET_MediaReaderPanel_C", "Construct");

	UObject::ProcessEvent(Func, nullptr);
}


// Function WIDGET_MediaReaderPanel.WIDGET_MediaReaderPanel_C.InitializeReaderPanel
// (Public, BlueprintCallable, BlueprintEvent)
// Parameters:
// class UWIDGET_PlayerHUD_C*              PlayerHUD_0                                            (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// class UWIDGET_MediaPanel_C*             MediaPanel_0                                           (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UWIDGET_MediaReaderPanel_C::InitializeReaderPanel(class UWIDGET_PlayerHUD_C* PlayerHUD_0, class UWIDGET_MediaPanel_C* MediaPanel_0)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WIDGET_MediaReaderPanel_C", "InitializeReaderPanel");

	Params::WIDGET_MediaReaderPanel_C_InitializeReaderPanel Parms{};

	Parms.PlayerHUD_0 = PlayerHUD_0;
	Parms.MediaPanel_0 = MediaPanel_0;

	UObject::ProcessEvent(Func, &Parms);
}


// Function WIDGET_MediaReaderPanel.WIDGET_MediaReaderPanel_C.SetMediaReaderData
// (Public, HasDefaults, BlueprintCallable, BlueprintEvent)
// Parameters:
// class UITEM_MediaBase_C*                MediaItem_0                                            (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UWIDGET_MediaReaderPanel_C::SetMediaReaderData(class UITEM_MediaBase_C* MediaItem_0)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WIDGET_MediaReaderPanel_C", "SetMediaReaderData");

	Params::WIDGET_MediaReaderPanel_C_SetMediaReaderData Parms{};

	Parms.MediaItem_0 = MediaItem_0;

	UObject::ProcessEvent(Func, &Parms);
}


// Function WIDGET_MediaReaderPanel.WIDGET_MediaReaderPanel_C.SetMediaTypeIcon
// (Public, BlueprintCallable, BlueprintEvent)

void UWIDGET_MediaReaderPanel_C::SetMediaTypeIcon()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WIDGET_MediaReaderPanel_C", "SetMediaTypeIcon");

	UObject::ProcessEvent(Func, nullptr);
}


// Function WIDGET_MediaReaderPanel.WIDGET_MediaReaderPanel_C.SetMediaPortrait
// (Public, BlueprintCallable, BlueprintEvent)
// Parameters:
// TSoftObjectPtr<class UTexture2D>        PortraitTexture                                        (BlueprintVisible, BlueprintReadOnly, Parm, HasGetValueTypeHash)
// int32                                   PortraitRowCount                                       (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// int32                                   PortraitColumnCount                                    (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// int32                                   PortraitFrameRate                                      (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UWIDGET_MediaReaderPanel_C::SetMediaPortrait(TSoftObjectPtr<class UTexture2D> PortraitTexture, int32 PortraitRowCount, int32 PortraitColumnCount, int32 PortraitFrameRate)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WIDGET_MediaReaderPanel_C", "SetMediaPortrait");

	Params::WIDGET_MediaReaderPanel_C_SetMediaPortrait Parms{};

	Parms.PortraitTexture = PortraitTexture;
	Parms.PortraitRowCount = PortraitRowCount;
	Parms.PortraitColumnCount = PortraitColumnCount;
	Parms.PortraitFrameRate = PortraitFrameRate;

	UObject::ProcessEvent(Func, &Parms);
}


// Function WIDGET_MediaReaderPanel.WIDGET_MediaReaderPanel_C.ToggleInteractivity
// (Public, BlueprintCallable, BlueprintEvent)
// Parameters:
// bool                                    IsInteractive                                          (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor)

void UWIDGET_MediaReaderPanel_C::ToggleInteractivity(bool IsInteractive)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WIDGET_MediaReaderPanel_C", "ToggleInteractivity");

	Params::WIDGET_MediaReaderPanel_C_ToggleInteractivity Parms{};

	Parms.IsInteractive = IsInteractive;

	UObject::ProcessEvent(Func, &Parms);
}


// Function WIDGET_MediaReaderPanel.WIDGET_MediaReaderPanel_C.GetFormattedNoteText
// (Protected, HasOutParams, HasDefaults, BlueprintCallable, BlueprintEvent, BlueprintPure)
// Parameters:
// class FText                             InputText                                              (BlueprintVisible, BlueprintReadOnly, Parm)
// class FText                             ResultText                                             (Parm, OutParm)

void UWIDGET_MediaReaderPanel_C::GetFormattedNoteText(const class FText& InputText, class FText* ResultText)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WIDGET_MediaReaderPanel_C", "GetFormattedNoteText");

	Params::WIDGET_MediaReaderPanel_C_GetFormattedNoteText Parms{};

	Parms.InputText = std::move(InputText);

	UObject::ProcessEvent(Func, &Parms);

	if (ResultText != nullptr)
		*ResultText = std::move(Parms.ResultText);
}


// Function WIDGET_MediaReaderPanel.WIDGET_MediaReaderPanel_C.GetFormattedLogText
// (Public, HasOutParams, HasDefaults, BlueprintCallable, BlueprintEvent, BlueprintPure)
// Parameters:
// class FText                             InputText                                              (BlueprintVisible, BlueprintReadOnly, Parm)
// class FText                             ResultText                                             (Parm, OutParm)

void UWIDGET_MediaReaderPanel_C::GetFormattedLogText(const class FText& InputText, class FText* ResultText)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WIDGET_MediaReaderPanel_C", "GetFormattedLogText");

	Params::WIDGET_MediaReaderPanel_C_GetFormattedLogText Parms{};

	Parms.InputText = std::move(InputText);

	UObject::ProcessEvent(Func, &Parms);

	if (ResultText != nullptr)
		*ResultText = std::move(Parms.ResultText);
}


// Function WIDGET_MediaReaderPanel.WIDGET_MediaReaderPanel_C.UpdateMediaReaderPortrait
// (Public, BlueprintCallable, BlueprintEvent)

void UWIDGET_MediaReaderPanel_C::UpdateMediaReaderPortrait()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WIDGET_MediaReaderPanel_C", "UpdateMediaReaderPortrait");

	UObject::ProcessEvent(Func, nullptr);
}


// Function WIDGET_MediaReaderPanel.WIDGET_MediaReaderPanel_C.PlayPreviewedMedia
// (Public, BlueprintCallable, BlueprintEvent)

void UWIDGET_MediaReaderPanel_C::PlayPreviewedMedia()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WIDGET_MediaReaderPanel_C", "PlayPreviewedMedia");

	UObject::ProcessEvent(Func, nullptr);
}


// Function WIDGET_MediaReaderPanel.WIDGET_MediaReaderPanel_C.UpdateMediaPlayIcon
// (Public, BlueprintCallable, BlueprintEvent)

void UWIDGET_MediaReaderPanel_C::UpdateMediaPlayIcon()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WIDGET_MediaReaderPanel_C", "UpdateMediaPlayIcon");

	UObject::ProcessEvent(Func, nullptr);
}

}

