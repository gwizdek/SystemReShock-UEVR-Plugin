#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: TASK_SetPredictedTargetLocation

#include "Basic.hpp"

#include "TASK_SetPredictedTargetLocation_classes.hpp"
#include "TASK_SetPredictedTargetLocation_parameters.hpp"


namespace SDK
{

// Function TASK_SetPredictedTargetLocation.TASK_SetPredictedTargetLocation_C.ExecuteUbergraph_TASK_SetPredictedTargetLocation
// (Final, UbergraphFunction)
// Parameters:
// int32                                   EntryPoint                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UTASK_SetPredictedTargetLocation_C::ExecuteUbergraph_TASK_SetPredictedTargetLocation(int32 EntryPoint)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("TASK_SetPredictedTargetLocation_C", "ExecuteUbergraph_TASK_SetPredictedTargetLocation");

	Params::TASK_SetPredictedTargetLocation_C_ExecuteUbergraph_TASK_SetPredictedTargetLocation Parms{};

	Parms.EntryPoint = EntryPoint;

	UObject::ProcessEvent(Func, &Parms);
}


// Function TASK_SetPredictedTargetLocation.TASK_SetPredictedTargetLocation_C.ReceiveExecuteAI
// (Event, Protected, BlueprintEvent)
// Parameters:
// class AAIController*                    OwnerController                                        (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// class APawn*                            ControlledPawn                                         (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UTASK_SetPredictedTargetLocation_C::ReceiveExecuteAI(class AAIController* OwnerController, class APawn* ControlledPawn)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("TASK_SetPredictedTargetLocation_C", "ReceiveExecuteAI");

	Params::TASK_SetPredictedTargetLocation_C_ReceiveExecuteAI Parms{};

	Parms.OwnerController = OwnerController;
	Parms.ControlledPawn = ControlledPawn;

	UObject::ProcessEvent(Func, &Parms);
}


// Function TASK_SetPredictedTargetLocation.TASK_SetPredictedTargetLocation_C.SetPredictedTargetLocation
// (Public, BlueprintCallable, BlueprintEvent)

void UTASK_SetPredictedTargetLocation_C::SetPredictedTargetLocation()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("TASK_SetPredictedTargetLocation_C", "SetPredictedTargetLocation");

	UObject::ProcessEvent(Func, nullptr);
}

}

