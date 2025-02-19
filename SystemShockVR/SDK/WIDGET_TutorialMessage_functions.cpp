#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: WIDGET_TutorialMessage

#include "Basic.hpp"

#include "WIDGET_TutorialMessage_classes.hpp"
#include "WIDGET_TutorialMessage_parameters.hpp"


namespace SDK
{

// Function WIDGET_TutorialMessage.WIDGET_TutorialMessage_C.ExecuteUbergraph_WIDGET_TutorialMessage
// (Final, UbergraphFunction, HasDefaults)
// Parameters:
// int32                                   EntryPoint                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UWIDGET_TutorialMessage_C::ExecuteUbergraph_WIDGET_TutorialMessage(int32 EntryPoint)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WIDGET_TutorialMessage_C", "ExecuteUbergraph_WIDGET_TutorialMessage");

	Params::WIDGET_TutorialMessage_C_ExecuteUbergraph_WIDGET_TutorialMessage Parms{};

	Parms.EntryPoint = EntryPoint;

	UObject::ProcessEvent(Func, &Parms);
}


// Function WIDGET_TutorialMessage.WIDGET_TutorialMessage_C.Tick
// (BlueprintCosmetic, Event, Public, BlueprintEvent)
// Parameters:
// struct FGeometry                        MyGeometry                                             (BlueprintVisible, BlueprintReadOnly, Parm, IsPlainOldData, NoDestructor)
// float                                   InDeltaTime                                            (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UWIDGET_TutorialMessage_C::Tick(const struct FGeometry& MyGeometry, float InDeltaTime)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WIDGET_TutorialMessage_C", "Tick");

	Params::WIDGET_TutorialMessage_C_Tick Parms{};

	Parms.MyGeometry = std::move(MyGeometry);
	Parms.InDeltaTime = InDeltaTime;

	UObject::ProcessEvent(Func, &Parms);
}


// Function WIDGET_TutorialMessage.WIDGET_TutorialMessage_C.InitializeTutorialMessage
// (Public, BlueprintCallable, BlueprintEvent)

void UWIDGET_TutorialMessage_C::InitializeTutorialMessage()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WIDGET_TutorialMessage_C", "InitializeTutorialMessage");

	UObject::ProcessEvent(Func, nullptr);
}


// Function WIDGET_TutorialMessage.WIDGET_TutorialMessage_C.SetCurrentTutorial
// (Private, HasDefaults, BlueprintCallable, BlueprintEvent)
// Parameters:
// struct FSTRUCT_TutorialInstance         Tutorial                                               (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UWIDGET_TutorialMessage_C::SetCurrentTutorial(const struct FSTRUCT_TutorialInstance& Tutorial)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WIDGET_TutorialMessage_C", "SetCurrentTutorial");

	Params::WIDGET_TutorialMessage_C_SetCurrentTutorial Parms{};

	Parms.Tutorial = std::move(Tutorial);

	UObject::ProcessEvent(Func, &Parms);
}


// Function WIDGET_TutorialMessage.WIDGET_TutorialMessage_C.SetTutorialsEnabled
// (Public, BlueprintCallable, BlueprintEvent)
// Parameters:
// bool                                    TutorialsEnabled                                       (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor)

void UWIDGET_TutorialMessage_C::SetTutorialsEnabled(bool TutorialsEnabled)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WIDGET_TutorialMessage_C", "SetTutorialsEnabled");

	Params::WIDGET_TutorialMessage_C_SetTutorialsEnabled Parms{};

	Parms.TutorialsEnabled = TutorialsEnabled;

	UObject::ProcessEvent(Func, &Parms);
}


// Function WIDGET_TutorialMessage.WIDGET_TutorialMessage_C.SetTutorialsOverridden
// (Public, BlueprintCallable, BlueprintEvent)
// Parameters:
// bool                                    TutorialsOverridden_0                                  (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor)

void UWIDGET_TutorialMessage_C::SetTutorialsOverridden(bool TutorialsOverridden_0)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WIDGET_TutorialMessage_C", "SetTutorialsOverridden");

	Params::WIDGET_TutorialMessage_C_SetTutorialsOverridden Parms{};

	Parms.TutorialsOverridden_0 = TutorialsOverridden_0;

	UObject::ProcessEvent(Func, &Parms);
}


// Function WIDGET_TutorialMessage.WIDGET_TutorialMessage_C.TryShowTutorialMessage
// (Public, BlueprintCallable, BlueprintEvent)

void UWIDGET_TutorialMessage_C::TryShowTutorialMessage()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WIDGET_TutorialMessage_C", "TryShowTutorialMessage");

	UObject::ProcessEvent(Func, nullptr);
}


// Function WIDGET_TutorialMessage.WIDGET_TutorialMessage_C.TryHideTutorialMessage
// (Public, BlueprintCallable, BlueprintEvent)

void UWIDGET_TutorialMessage_C::TryHideTutorialMessage()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WIDGET_TutorialMessage_C", "TryHideTutorialMessage");

	UObject::ProcessEvent(Func, nullptr);
}


// Function WIDGET_TutorialMessage.WIDGET_TutorialMessage_C.UpdateCurrentMessageToTarget
// (Public, HasDefaults, BlueprintCallable, BlueprintEvent)

void UWIDGET_TutorialMessage_C::UpdateCurrentMessageToTarget()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WIDGET_TutorialMessage_C", "UpdateCurrentMessageToTarget");

	UObject::ProcessEvent(Func, nullptr);
}


// Function WIDGET_TutorialMessage.WIDGET_TutorialMessage_C.UpdateRenderOpacity
// (Public, BlueprintCallable, BlueprintEvent)
// Parameters:
// float                                   DeltaTime                                              (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UWIDGET_TutorialMessage_C::UpdateRenderOpacity(float DeltaTime)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WIDGET_TutorialMessage_C", "UpdateRenderOpacity");

	Params::WIDGET_TutorialMessage_C_UpdateRenderOpacity Parms{};

	Parms.DeltaTime = DeltaTime;

	UObject::ProcessEvent(Func, &Parms);
}


// Function WIDGET_TutorialMessage.WIDGET_TutorialMessage_C.UpdateTargetLine
// (Public, HasDefaults, BlueprintCallable, BlueprintEvent)

void UWIDGET_TutorialMessage_C::UpdateTargetLine()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WIDGET_TutorialMessage_C", "UpdateTargetLine");

	UObject::ProcessEvent(Func, nullptr);
}

}

