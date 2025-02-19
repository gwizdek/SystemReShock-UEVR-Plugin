#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: DEBUG_RevealMap

#include "Basic.hpp"

#include "DEBUG_RevealMap_classes.hpp"
#include "DEBUG_RevealMap_parameters.hpp"


namespace SDK
{

// Function DEBUG_RevealMap.DEBUG_RevealMap_C.TriggerDebugFunction
// (Public, HasOutParams, BlueprintCallable, BlueprintEvent)
// Parameters:
// bool                                    Handled                                                (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor)

void UDEBUG_RevealMap_C::TriggerDebugFunction(bool* Handled)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("DEBUG_RevealMap_C", "TriggerDebugFunction");

	Params::DEBUG_RevealMap_C_TriggerDebugFunction Parms{};

	UObject::ProcessEvent(Func, &Parms);

	if (Handled != nullptr)
		*Handled = Parms.Handled;
}

}

