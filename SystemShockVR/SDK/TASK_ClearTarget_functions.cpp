#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: TASK_ClearTarget

#include "Basic.hpp"

#include "TASK_ClearTarget_classes.hpp"
#include "TASK_ClearTarget_parameters.hpp"


namespace SDK
{

// Function TASK_ClearTarget.TASK_ClearTarget_C.ExecuteUbergraph_TASK_ClearTarget
// (Final, UbergraphFunction)
// Parameters:
// int32                                   EntryPoint                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UTASK_ClearTarget_C::ExecuteUbergraph_TASK_ClearTarget(int32 EntryPoint)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("TASK_ClearTarget_C", "ExecuteUbergraph_TASK_ClearTarget");

	Params::TASK_ClearTarget_C_ExecuteUbergraph_TASK_ClearTarget Parms{};

	Parms.EntryPoint = EntryPoint;

	UObject::ProcessEvent(Func, &Parms);
}


// Function TASK_ClearTarget.TASK_ClearTarget_C.ReceiveExecuteAI
// (Event, Protected, BlueprintEvent)
// Parameters:
// class AAIController*                    OwnerController                                        (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// class APawn*                            ControlledPawn                                         (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UTASK_ClearTarget_C::ReceiveExecuteAI(class AAIController* OwnerController, class APawn* ControlledPawn)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("TASK_ClearTarget_C", "ReceiveExecuteAI");

	Params::TASK_ClearTarget_C_ReceiveExecuteAI Parms{};

	Parms.OwnerController = OwnerController;
	Parms.ControlledPawn = ControlledPawn;

	UObject::ProcessEvent(Func, &Parms);
}

}

