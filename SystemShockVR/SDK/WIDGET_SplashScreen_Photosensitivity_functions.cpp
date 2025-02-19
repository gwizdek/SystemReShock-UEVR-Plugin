#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: WIDGET_SplashScreen_Photosensitivity

#include "Basic.hpp"

#include "WIDGET_SplashScreen_Photosensitivity_classes.hpp"
#include "WIDGET_SplashScreen_Photosensitivity_parameters.hpp"


namespace SDK
{

// Function WIDGET_SplashScreen_Photosensitivity.WIDGET_SplashScreen_Photosensitivity_C.ExecuteUbergraph_WIDGET_SplashScreen_Photosensitivity
// (Final, UbergraphFunction)
// Parameters:
// int32                                   EntryPoint                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UWIDGET_SplashScreen_Photosensitivity_C::ExecuteUbergraph_WIDGET_SplashScreen_Photosensitivity(int32 EntryPoint)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WIDGET_SplashScreen_Photosensitivity_C", "ExecuteUbergraph_WIDGET_SplashScreen_Photosensitivity");

	Params::WIDGET_SplashScreen_Photosensitivity_C_ExecuteUbergraph_WIDGET_SplashScreen_Photosensitivity Parms{};

	Parms.EntryPoint = EntryPoint;

	UObject::ProcessEvent(Func, &Parms);
}


// Function WIDGET_SplashScreen_Photosensitivity.WIDGET_SplashScreen_Photosensitivity_C.Construct
// (BlueprintCosmetic, Event, Public, BlueprintEvent)

void UWIDGET_SplashScreen_Photosensitivity_C::Construct()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WIDGET_SplashScreen_Photosensitivity_C", "Construct");

	UObject::ProcessEvent(Func, nullptr);
}


// Function WIDGET_SplashScreen_Photosensitivity.WIDGET_SplashScreen_Photosensitivity_C.GetFadeOutDuration
// (Public, HasOutParams, BlueprintCallable, BlueprintEvent)
// Parameters:
// float                                   Duration                                               (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UWIDGET_SplashScreen_Photosensitivity_C::GetFadeOutDuration(float* Duration)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WIDGET_SplashScreen_Photosensitivity_C", "GetFadeOutDuration");

	Params::WIDGET_SplashScreen_Photosensitivity_C_GetFadeOutDuration Parms{};

	UObject::ProcessEvent(Func, &Parms);

	if (Duration != nullptr)
		*Duration = Parms.Duration;
}


// Function WIDGET_SplashScreen_Photosensitivity.WIDGET_SplashScreen_Photosensitivity_C.GetSplashDuration
// (Public, HasOutParams, BlueprintCallable, BlueprintEvent)
// Parameters:
// float                                   Duration                                               (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UWIDGET_SplashScreen_Photosensitivity_C::GetSplashDuration(float* Duration)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WIDGET_SplashScreen_Photosensitivity_C", "GetSplashDuration");

	Params::WIDGET_SplashScreen_Photosensitivity_C_GetSplashDuration Parms{};

	UObject::ProcessEvent(Func, &Parms);

	if (Duration != nullptr)
		*Duration = Parms.Duration;
}


// Function WIDGET_SplashScreen_Photosensitivity.WIDGET_SplashScreen_Photosensitivity_C.GetFadeInDuration
// (Public, HasOutParams, BlueprintCallable, BlueprintEvent)
// Parameters:
// float                                   Duration                                               (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UWIDGET_SplashScreen_Photosensitivity_C::GetFadeInDuration(float* Duration)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WIDGET_SplashScreen_Photosensitivity_C", "GetFadeInDuration");

	Params::WIDGET_SplashScreen_Photosensitivity_C_GetFadeInDuration Parms{};

	UObject::ProcessEvent(Func, &Parms);

	if (Duration != nullptr)
		*Duration = Parms.Duration;
}


// Function WIDGET_SplashScreen_Photosensitivity.WIDGET_SplashScreen_Photosensitivity_C.CanSkipSplash
// (Public, HasOutParams, BlueprintCallable, BlueprintEvent)
// Parameters:
// bool                                    Result                                                 (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor)

void UWIDGET_SplashScreen_Photosensitivity_C::CanSkipSplash(bool* Result)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WIDGET_SplashScreen_Photosensitivity_C", "CanSkipSplash");

	Params::WIDGET_SplashScreen_Photosensitivity_C_CanSkipSplash Parms{};

	UObject::ProcessEvent(Func, &Parms);

	if (Result != nullptr)
		*Result = Parms.Result;
}


// Function WIDGET_SplashScreen_Photosensitivity.WIDGET_SplashScreen_Photosensitivity_C.CanSkipFadeIn
// (Public, HasOutParams, BlueprintCallable, BlueprintEvent)
// Parameters:
// bool                                    Result                                                 (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor)

void UWIDGET_SplashScreen_Photosensitivity_C::CanSkipFadeIn(bool* Result)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WIDGET_SplashScreen_Photosensitivity_C", "CanSkipFadeIn");

	Params::WIDGET_SplashScreen_Photosensitivity_C_CanSkipFadeIn Parms{};

	UObject::ProcessEvent(Func, &Parms);

	if (Result != nullptr)
		*Result = Parms.Result;
}


// Function WIDGET_SplashScreen_Photosensitivity.WIDGET_SplashScreen_Photosensitivity_C.UpdateFadeIn
// (Public, HasOutParams, BlueprintCallable, BlueprintEvent)
// Parameters:
// float                                   Progress                                               (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// bool                                    Result                                                 (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor)

void UWIDGET_SplashScreen_Photosensitivity_C::UpdateFadeIn(float Progress, bool* Result)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WIDGET_SplashScreen_Photosensitivity_C", "UpdateFadeIn");

	Params::WIDGET_SplashScreen_Photosensitivity_C_UpdateFadeIn Parms{};

	Parms.Progress = Progress;

	UObject::ProcessEvent(Func, &Parms);

	if (Result != nullptr)
		*Result = Parms.Result;
}


// Function WIDGET_SplashScreen_Photosensitivity.WIDGET_SplashScreen_Photosensitivity_C.UpdateSplash
// (Public, HasOutParams, BlueprintCallable, BlueprintEvent)
// Parameters:
// float                                   Progress                                               (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// bool                                    Result                                                 (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor)

void UWIDGET_SplashScreen_Photosensitivity_C::UpdateSplash(float Progress, bool* Result)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WIDGET_SplashScreen_Photosensitivity_C", "UpdateSplash");

	Params::WIDGET_SplashScreen_Photosensitivity_C_UpdateSplash Parms{};

	Parms.Progress = Progress;

	UObject::ProcessEvent(Func, &Parms);

	if (Result != nullptr)
		*Result = Parms.Result;
}


// Function WIDGET_SplashScreen_Photosensitivity.WIDGET_SplashScreen_Photosensitivity_C.UpdateFadeOut
// (Public, HasOutParams, BlueprintCallable, BlueprintEvent)
// Parameters:
// float                                   Progress                                               (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// bool                                    Result                                                 (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor)

void UWIDGET_SplashScreen_Photosensitivity_C::UpdateFadeOut(float Progress, bool* Result)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WIDGET_SplashScreen_Photosensitivity_C", "UpdateFadeOut");

	Params::WIDGET_SplashScreen_Photosensitivity_C_UpdateFadeOut Parms{};

	Parms.Progress = Progress;

	UObject::ProcessEvent(Func, &Parms);

	if (Result != nullptr)
		*Result = Parms.Result;
}


// Function WIDGET_SplashScreen_Photosensitivity.WIDGET_SplashScreen_Photosensitivity_C.SetPreGameScreen
// (Public, HasOutParams, BlueprintCallable, BlueprintEvent)
// Parameters:
// class UWIDGET_PreGameScreen_C*          PreGameScreen                                          (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// bool                                    Result                                                 (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor)

void UWIDGET_SplashScreen_Photosensitivity_C::SetPreGameScreen(class UWIDGET_PreGameScreen_C* PreGameScreen, bool* Result)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WIDGET_SplashScreen_Photosensitivity_C", "SetPreGameScreen");

	Params::WIDGET_SplashScreen_Photosensitivity_C_SetPreGameScreen Parms{};

	Parms.PreGameScreen = PreGameScreen;

	UObject::ProcessEvent(Func, &Parms);

	if (Result != nullptr)
		*Result = Parms.Result;
}


// Function WIDGET_SplashScreen_Photosensitivity.WIDGET_SplashScreen_Photosensitivity_C.OnSplashVisible
// (Public, HasOutParams, BlueprintCallable, BlueprintEvent)
// Parameters:
// bool                                    Result                                                 (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor)

void UWIDGET_SplashScreen_Photosensitivity_C::OnSplashVisible(bool* Result)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WIDGET_SplashScreen_Photosensitivity_C", "OnSplashVisible");

	Params::WIDGET_SplashScreen_Photosensitivity_C_OnSplashVisible Parms{};

	UObject::ProcessEvent(Func, &Parms);

	if (Result != nullptr)
		*Result = Parms.Result;
}


// Function WIDGET_SplashScreen_Photosensitivity.WIDGET_SplashScreen_Photosensitivity_C.OnSplashHidden
// (Public, HasOutParams, BlueprintCallable, BlueprintEvent)
// Parameters:
// bool                                    Result                                                 (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor)

void UWIDGET_SplashScreen_Photosensitivity_C::OnSplashHidden(bool* Result)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WIDGET_SplashScreen_Photosensitivity_C", "OnSplashHidden");

	Params::WIDGET_SplashScreen_Photosensitivity_C_OnSplashHidden Parms{};

	UObject::ProcessEvent(Func, &Parms);

	if (Result != nullptr)
		*Result = Parms.Result;
}

}

