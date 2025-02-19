#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: INTERACT_Screen_Terminal

#include "Basic.hpp"

#include "INTERACT_Screen_Terminal_classes.hpp"
#include "INTERACT_Screen_Terminal_parameters.hpp"


namespace SDK
{

// Function INTERACT_Screen_Terminal.INTERACT_Screen_Terminal_C.GetInteractBusy
// (Public, HasOutParams, BlueprintCallable, BlueprintEvent)
// Parameters:
// bool                                    Result                                                 (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor)
// class FText                             BusyMessage                                            (Parm, OutParm)

void AINTERACT_Screen_Terminal_C::GetInteractBusy(bool* Result, class FText* BusyMessage)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("INTERACT_Screen_Terminal_C", "GetInteractBusy");

	Params::INTERACT_Screen_Terminal_C_GetInteractBusy Parms{};

	UObject::ProcessEvent(Func, &Parms);

	if (Result != nullptr)
		*Result = Parms.Result;

	if (BusyMessage != nullptr)
		*BusyMessage = std::move(Parms.BusyMessage);
}

}

