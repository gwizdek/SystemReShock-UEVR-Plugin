#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: TASK_SetSprintEnabled

#include "Basic.hpp"

#include "TASK_SetSprintEnabled_classes.hpp"
#include "TASK_SetSprintEnabled_parameters.hpp"


namespace SDK
{

// Function TASK_SetSprintEnabled.TASK_SetSprintEnabled_C.ExecuteUbergraph_TASK_SetSprintEnabled
// (Final, UbergraphFunction)
// Parameters:
// int32                                   EntryPoint                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UTASK_SetSprintEnabled_C::ExecuteUbergraph_TASK_SetSprintEnabled(int32 EntryPoint)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("TASK_SetSprintEnabled_C", "ExecuteUbergraph_TASK_SetSprintEnabled");

	Params::TASK_SetSprintEnabled_C_ExecuteUbergraph_TASK_SetSprintEnabled Parms{};

	Parms.EntryPoint = EntryPoint;

	UObject::ProcessEvent(Func, &Parms);
}


// Function TASK_SetSprintEnabled.TASK_SetSprintEnabled_C.ReceiveExecuteAI
// (Event, Protected, BlueprintEvent)
// Parameters:
// class AAIController*                    OwnerController                                        (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// class APawn*                            ControlledPawn                                         (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UTASK_SetSprintEnabled_C::ReceiveExecuteAI(class AAIController* OwnerController, class APawn* ControlledPawn)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("TASK_SetSprintEnabled_C", "ReceiveExecuteAI");

	Params::TASK_SetSprintEnabled_C_ReceiveExecuteAI Parms{};

	Parms.OwnerController = OwnerController;
	Parms.ControlledPawn = ControlledPawn;

	UObject::ProcessEvent(Func, &Parms);
}

}

