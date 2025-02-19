#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: WIDGET_MediaPrompt

#include "Basic.hpp"

#include "WIDGET_MediaPrompt_classes.hpp"
#include "WIDGET_MediaPrompt_parameters.hpp"


namespace SDK
{

// Function WIDGET_MediaPrompt.WIDGET_MediaPrompt_C.ExecuteUbergraph_WIDGET_MediaPrompt
// (Final, UbergraphFunction, HasDefaults)
// Parameters:
// int32                                   EntryPoint                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UWIDGET_MediaPrompt_C::ExecuteUbergraph_WIDGET_MediaPrompt(int32 EntryPoint)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WIDGET_MediaPrompt_C", "ExecuteUbergraph_WIDGET_MediaPrompt");

	Params::WIDGET_MediaPrompt_C_ExecuteUbergraph_WIDGET_MediaPrompt Parms{};

	Parms.EntryPoint = EntryPoint;

	UObject::ProcessEvent(Func, &Parms);
}


// Function WIDGET_MediaPrompt.WIDGET_MediaPrompt_C.Tick
// (BlueprintCosmetic, Event, Public, BlueprintEvent)
// Parameters:
// struct FGeometry                        MyGeometry                                             (BlueprintVisible, BlueprintReadOnly, Parm, IsPlainOldData, NoDestructor)
// float                                   InDeltaTime                                            (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UWIDGET_MediaPrompt_C::Tick(const struct FGeometry& MyGeometry, float InDeltaTime)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WIDGET_MediaPrompt_C", "Tick");

	Params::WIDGET_MediaPrompt_C_Tick Parms{};

	Parms.MyGeometry = std::move(MyGeometry);
	Parms.InDeltaTime = InDeltaTime;

	UObject::ProcessEvent(Func, &Parms);
}


// Function WIDGET_MediaPrompt.WIDGET_MediaPrompt_C.PreConstruct
// (BlueprintCosmetic, Event, Public, BlueprintEvent)
// Parameters:
// bool                                    IsDesignTime                                           (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor)

void UWIDGET_MediaPrompt_C::PreConstruct(bool IsDesignTime)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WIDGET_MediaPrompt_C", "PreConstruct");

	Params::WIDGET_MediaPrompt_C_PreConstruct Parms{};

	Parms.IsDesignTime = IsDesignTime;

	UObject::ProcessEvent(Func, &Parms);
}


// Function WIDGET_MediaPrompt.WIDGET_MediaPrompt_C.InitializeMediaPrompt
// (Public, BlueprintCallable, BlueprintEvent)
// Parameters:
// class UWIDGET_PlayerHUD_C*              PlayerHUD_0                                            (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UWIDGET_MediaPrompt_C::InitializeMediaPrompt(class UWIDGET_PlayerHUD_C* PlayerHUD_0)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WIDGET_MediaPrompt_C", "InitializeMediaPrompt");

	Params::WIDGET_MediaPrompt_C_InitializeMediaPrompt Parms{};

	Parms.PlayerHUD_0 = PlayerHUD_0;

	UObject::ProcessEvent(Func, &Parms);
}


// Function WIDGET_MediaPrompt.WIDGET_MediaPrompt_C.EnableMediaPrompt
// (Public, HasDefaults, BlueprintCallable, BlueprintEvent)
// Parameters:
// class UITEM_MediaBase_C*                MediaItem                                              (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UWIDGET_MediaPrompt_C::EnableMediaPrompt(class UITEM_MediaBase_C* MediaItem)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WIDGET_MediaPrompt_C", "EnableMediaPrompt");

	Params::WIDGET_MediaPrompt_C_EnableMediaPrompt Parms{};

	Parms.MediaItem = MediaItem;

	UObject::ProcessEvent(Func, &Parms);
}


// Function WIDGET_MediaPrompt.WIDGET_MediaPrompt_C.ResumeMediaPrompt
// (Public, HasOutParams, HasDefaults, BlueprintCallable, BlueprintEvent)
// Parameters:
// class UITEM_MediaBase_C*                MediaItem                                              (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// float                                   Timestamp                                              (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// bool                                    Success                                                (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor)

void UWIDGET_MediaPrompt_C::ResumeMediaPrompt(class UITEM_MediaBase_C* MediaItem, float Timestamp, bool* Success)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WIDGET_MediaPrompt_C", "ResumeMediaPrompt");

	Params::WIDGET_MediaPrompt_C_ResumeMediaPrompt Parms{};

	Parms.MediaItem = MediaItem;
	Parms.Timestamp = Timestamp;

	UObject::ProcessEvent(Func, &Parms);

	if (Success != nullptr)
		*Success = Parms.Success;
}


// Function WIDGET_MediaPrompt.WIDGET_MediaPrompt_C.DisableMediaPrompt
// (Public, BlueprintCallable, BlueprintEvent)
// Parameters:
// bool                                    Immediate                                              (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor)

void UWIDGET_MediaPrompt_C::DisableMediaPrompt(bool Immediate)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WIDGET_MediaPrompt_C", "DisableMediaPrompt");

	Params::WIDGET_MediaPrompt_C_DisableMediaPrompt Parms{};

	Parms.Immediate = Immediate;

	UObject::ProcessEvent(Func, &Parms);
}


// Function WIDGET_MediaPrompt.WIDGET_MediaPrompt_C.ReceiveMediaKey
// (Public, HasDefaults, BlueprintCallable, BlueprintEvent)
// Parameters:
// bool                                    Down                                                   (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor)

void UWIDGET_MediaPrompt_C::ReceiveMediaKey(bool Down)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WIDGET_MediaPrompt_C", "ReceiveMediaKey");

	Params::WIDGET_MediaPrompt_C_ReceiveMediaKey Parms{};

	Parms.Down = Down;

	UObject::ProcessEvent(Func, &Parms);
}


// Function WIDGET_MediaPrompt.WIDGET_MediaPrompt_C.EVENT_AutoCloseAudioLogPrompt
// (Private, BlueprintCallable, BlueprintEvent)

void UWIDGET_MediaPrompt_C::EVENT_AutoCloseAudioLogPrompt()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WIDGET_MediaPrompt_C", "EVENT_AutoCloseAudioLogPrompt");

	UObject::ProcessEvent(Func, nullptr);
}


// Function WIDGET_MediaPrompt.WIDGET_MediaPrompt_C.EVENT_TryPromptQueuedMedia
// (Private, BlueprintCallable, BlueprintEvent)

void UWIDGET_MediaPrompt_C::EVENT_TryPromptQueuedMedia()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WIDGET_MediaPrompt_C", "EVENT_TryPromptQueuedMedia");

	UObject::ProcessEvent(Func, nullptr);
}


// Function WIDGET_MediaPrompt.WIDGET_MediaPrompt_C.UpdateMediaPromptVisibility
// (Public, BlueprintCallable, BlueprintEvent)

void UWIDGET_MediaPrompt_C::UpdateMediaPromptVisibility()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WIDGET_MediaPrompt_C", "UpdateMediaPromptVisibility");

	UObject::ProcessEvent(Func, nullptr);
}


// Function WIDGET_MediaPrompt.WIDGET_MediaPrompt_C.EVENT_CloseAndPlayMedia
// (Private, BlueprintCallable, BlueprintEvent)

void UWIDGET_MediaPrompt_C::EVENT_CloseAndPlayMedia()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WIDGET_MediaPrompt_C", "EVENT_CloseAndPlayMedia");

	UObject::ProcessEvent(Func, nullptr);
}


// Function WIDGET_MediaPrompt.WIDGET_MediaPrompt_C.ForceQueueMediaItem
// (Private, BlueprintCallable, BlueprintEvent)
// Parameters:
// class UITEM_MediaBase_C*                MediaItem                                              (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UWIDGET_MediaPrompt_C::ForceQueueMediaItem(class UITEM_MediaBase_C* MediaItem)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WIDGET_MediaPrompt_C", "ForceQueueMediaItem");

	Params::WIDGET_MediaPrompt_C_ForceQueueMediaItem Parms{};

	Parms.MediaItem = MediaItem;

	UObject::ProcessEvent(Func, &Parms);
}


// Function WIDGET_MediaPrompt.WIDGET_MediaPrompt_C.TryQueueMediaItem
// (Private, BlueprintCallable, BlueprintEvent)
// Parameters:
// class UITEM_MediaBase_C*                MediaItem                                              (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UWIDGET_MediaPrompt_C::TryQueueMediaItem(class UITEM_MediaBase_C* MediaItem)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WIDGET_MediaPrompt_C", "TryQueueMediaItem");

	Params::WIDGET_MediaPrompt_C_TryQueueMediaItem Parms{};

	Parms.MediaItem = MediaItem;

	UObject::ProcessEvent(Func, &Parms);
}


// Function WIDGET_MediaPrompt.WIDGET_MediaPrompt_C.TryCancelQueuedMediaItem
// (Public, BlueprintCallable, BlueprintEvent)

void UWIDGET_MediaPrompt_C::TryCancelQueuedMediaItem()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WIDGET_MediaPrompt_C", "TryCancelQueuedMediaItem");

	UObject::ProcessEvent(Func, nullptr);
}


// Function WIDGET_MediaPrompt.WIDGET_MediaPrompt_C.CanHoldKeyToPlayLog
// (Public, HasOutParams, BlueprintCallable, BlueprintEvent, BlueprintPure)
// Parameters:
// bool                                    Result                                                 (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor)

void UWIDGET_MediaPrompt_C::CanHoldKeyToPlayLog(bool* Result)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WIDGET_MediaPrompt_C", "CanHoldKeyToPlayLog");

	Params::WIDGET_MediaPrompt_C_CanHoldKeyToPlayLog Parms{};

	UObject::ProcessEvent(Func, &Parms);

	if (Result != nullptr)
		*Result = Parms.Result;
}


// Function WIDGET_MediaPrompt.WIDGET_MediaPrompt_C.GetPulsingColorValue
// (Public, HasOutParams, BlueprintCallable, BlueprintEvent, BlueprintPure)
// Parameters:
// struct FColor                           Color                                                  (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UWIDGET_MediaPrompt_C::GetPulsingColorValue(struct FColor* Color)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WIDGET_MediaPrompt_C", "GetPulsingColorValue");

	Params::WIDGET_MediaPrompt_C_GetPulsingColorValue Parms{};

	UObject::ProcessEvent(Func, &Parms);

	if (Color != nullptr)
		*Color = std::move(Parms.Color);
}


// Function WIDGET_MediaPrompt.WIDGET_MediaPrompt_C.GetHoldingButtonColorValue
// (Public, HasOutParams, BlueprintCallable, BlueprintEvent, BlueprintPure)
// Parameters:
// struct FColor                           Color                                                  (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UWIDGET_MediaPrompt_C::GetHoldingButtonColorValue(struct FColor* Color)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WIDGET_MediaPrompt_C", "GetHoldingButtonColorValue");

	Params::WIDGET_MediaPrompt_C_GetHoldingButtonColorValue Parms{};

	UObject::ProcessEvent(Func, &Parms);

	if (Color != nullptr)
		*Color = std::move(Parms.Color);
}


// Function WIDGET_MediaPrompt.WIDGET_MediaPrompt_C.MultiplyColorAlpha
// (Public, HasOutParams, BlueprintCallable, BlueprintEvent, BlueprintPure)
// Parameters:
// struct FColor                           InitialColor                                           (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// float                                   AlphaMultiplier                                        (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// struct FColor                           ModifiedColor                                          (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UWIDGET_MediaPrompt_C::MultiplyColorAlpha(const struct FColor& InitialColor, float AlphaMultiplier, struct FColor* ModifiedColor)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WIDGET_MediaPrompt_C", "MultiplyColorAlpha");

	Params::WIDGET_MediaPrompt_C_MultiplyColorAlpha Parms{};

	Parms.InitialColor = std::move(InitialColor);
	Parms.AlphaMultiplier = AlphaMultiplier;

	UObject::ProcessEvent(Func, &Parms);

	if (ModifiedColor != nullptr)
		*ModifiedColor = std::move(Parms.ModifiedColor);
}


// Function WIDGET_MediaPrompt.WIDGET_MediaPrompt_C.CanShowPromptForNewMedia
// (Public, HasOutParams, BlueprintCallable, BlueprintEvent, BlueprintPure)
// Parameters:
// class UITEM_MediaBase_C*                MediaItem                                              (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// bool                                    Result                                                 (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor)

void UWIDGET_MediaPrompt_C::CanShowPromptForNewMedia(class UITEM_MediaBase_C* MediaItem, bool* Result)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WIDGET_MediaPrompt_C", "CanShowPromptForNewMedia");

	Params::WIDGET_MediaPrompt_C_CanShowPromptForNewMedia Parms{};

	Parms.MediaItem = MediaItem;

	UObject::ProcessEvent(Func, &Parms);

	if (Result != nullptr)
		*Result = Parms.Result;
}


// Function WIDGET_MediaPrompt.WIDGET_MediaPrompt_C.GetMediaPriority
// (Public, HasOutParams, BlueprintCallable, BlueprintEvent, BlueprintPure)
// Parameters:
// class UITEM_MediaBase_C*                MediaItem                                              (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// int32                                   Priority_0                                             (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UWIDGET_MediaPrompt_C::GetMediaPriority(class UITEM_MediaBase_C* MediaItem, int32* Priority_0)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WIDGET_MediaPrompt_C", "GetMediaPriority");

	Params::WIDGET_MediaPrompt_C_GetMediaPriority Parms{};

	Parms.MediaItem = MediaItem;

	UObject::ProcessEvent(Func, &Parms);

	if (Priority_0 != nullptr)
		*Priority_0 = Parms.Priority_0;
}

}

