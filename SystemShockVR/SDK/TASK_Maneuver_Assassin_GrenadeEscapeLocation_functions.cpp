#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: TASK_Maneuver_Assassin_GrenadeEscapeLocation

#include "Basic.hpp"

#include "TASK_Maneuver_Assassin_GrenadeEscapeLocation_classes.hpp"
#include "TASK_Maneuver_Assassin_GrenadeEscapeLocation_parameters.hpp"


namespace SDK
{

// Function TASK_Maneuver_Assassin_GrenadeEscapeLocation.TASK_Maneuver_Assassin_GrenadeEscapeLocation_C.ExecuteUbergraph_TASK_Maneuver_Assassin_GrenadeEscapeLocation
// (Final, UbergraphFunction, HasDefaults)
// Parameters:
// int32                                   EntryPoint                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UTASK_Maneuver_Assassin_GrenadeEscapeLocation_C::ExecuteUbergraph_TASK_Maneuver_Assassin_GrenadeEscapeLocation(int32 EntryPoint)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("TASK_Maneuver_Assassin_GrenadeEscapeLocation_C", "ExecuteUbergraph_TASK_Maneuver_Assassin_GrenadeEscapeLocation");

	Params::TASK_Maneuver_Assassin_GrenadeEscapeLocation_C_ExecuteUbergraph_TASK_Maneuver_Assassin_GrenadeEscapeLocation Parms{};

	Parms.EntryPoint = EntryPoint;

	UObject::ProcessEvent(Func, &Parms);
}


// Function TASK_Maneuver_Assassin_GrenadeEscapeLocation.TASK_Maneuver_Assassin_GrenadeEscapeLocation_C.ReceiveExecuteAI
// (Event, Protected, BlueprintEvent)
// Parameters:
// class AAIController*                    OwnerController                                        (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// class APawn*                            ControlledPawn                                         (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UTASK_Maneuver_Assassin_GrenadeEscapeLocation_C::ReceiveExecuteAI(class AAIController* OwnerController, class APawn* ControlledPawn)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("TASK_Maneuver_Assassin_GrenadeEscapeLocation_C", "ReceiveExecuteAI");

	Params::TASK_Maneuver_Assassin_GrenadeEscapeLocation_C_ReceiveExecuteAI Parms{};

	Parms.OwnerController = OwnerController;
	Parms.ControlledPawn = ControlledPawn;

	UObject::ProcessEvent(Func, &Parms);
}

}

