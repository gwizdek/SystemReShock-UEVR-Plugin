#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: WIDGET_SaveDifficultyIndicator

#include "Basic.hpp"

#include "WIDGET_SaveDifficultyIndicator_classes.hpp"
#include "WIDGET_SaveDifficultyIndicator_parameters.hpp"


namespace SDK
{

// Function WIDGET_SaveDifficultyIndicator.WIDGET_SaveDifficultyIndicator_C.ExecuteUbergraph_WIDGET_SaveDifficultyIndicator
// (Final, UbergraphFunction)
// Parameters:
// int32                                   EntryPoint                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UWIDGET_SaveDifficultyIndicator_C::ExecuteUbergraph_WIDGET_SaveDifficultyIndicator(int32 EntryPoint)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WIDGET_SaveDifficultyIndicator_C", "ExecuteUbergraph_WIDGET_SaveDifficultyIndicator");

	Params::WIDGET_SaveDifficultyIndicator_C_ExecuteUbergraph_WIDGET_SaveDifficultyIndicator Parms{};

	Parms.EntryPoint = EntryPoint;

	UObject::ProcessEvent(Func, &Parms);
}


// Function WIDGET_SaveDifficultyIndicator.WIDGET_SaveDifficultyIndicator_C.Construct
// (BlueprintCosmetic, Event, Public, BlueprintEvent)

void UWIDGET_SaveDifficultyIndicator_C::Construct()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WIDGET_SaveDifficultyIndicator_C", "Construct");

	UObject::ProcessEvent(Func, nullptr);
}


// Function WIDGET_SaveDifficultyIndicator.WIDGET_SaveDifficultyIndicator_C.PreConstruct
// (BlueprintCosmetic, Event, Public, BlueprintEvent)
// Parameters:
// bool                                    IsDesignTime                                           (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor)

void UWIDGET_SaveDifficultyIndicator_C::PreConstruct(bool IsDesignTime)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WIDGET_SaveDifficultyIndicator_C", "PreConstruct");

	Params::WIDGET_SaveDifficultyIndicator_C_PreConstruct Parms{};

	Parms.IsDesignTime = IsDesignTime;

	UObject::ProcessEvent(Func, &Parms);
}

}

