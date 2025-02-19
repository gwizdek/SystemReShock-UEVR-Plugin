#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: SERV_BroadcastDetectedPawn

#include "Basic.hpp"

#include "SERV_BroadcastDetectedPawn_classes.hpp"
#include "SERV_BroadcastDetectedPawn_parameters.hpp"


namespace SDK
{

// Function SERV_BroadcastDetectedPawn.SERV_BroadcastDetectedPawn_C.ExecuteUbergraph_SERV_BroadcastDetectedPawn
// (Final, UbergraphFunction)
// Parameters:
// int32                                   EntryPoint                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void USERV_BroadcastDetectedPawn_C::ExecuteUbergraph_SERV_BroadcastDetectedPawn(int32 EntryPoint)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("SERV_BroadcastDetectedPawn_C", "ExecuteUbergraph_SERV_BroadcastDetectedPawn");

	Params::SERV_BroadcastDetectedPawn_C_ExecuteUbergraph_SERV_BroadcastDetectedPawn Parms{};

	Parms.EntryPoint = EntryPoint;

	UObject::ProcessEvent(Func, &Parms);
}


// Function SERV_BroadcastDetectedPawn.SERV_BroadcastDetectedPawn_C.ReceiveTickAI
// (Event, Protected, BlueprintEvent)
// Parameters:
// class AAIController*                    OwnerController                                        (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// class APawn*                            ControlledPawn                                         (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// float                                   DeltaSeconds                                           (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void USERV_BroadcastDetectedPawn_C::ReceiveTickAI(class AAIController* OwnerController, class APawn* ControlledPawn, float DeltaSeconds)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("SERV_BroadcastDetectedPawn_C", "ReceiveTickAI");

	Params::SERV_BroadcastDetectedPawn_C_ReceiveTickAI Parms{};

	Parms.OwnerController = OwnerController;
	Parms.ControlledPawn = ControlledPawn;
	Parms.DeltaSeconds = DeltaSeconds;

	UObject::ProcessEvent(Func, &Parms);
}


// Function SERV_BroadcastDetectedPawn.SERV_BroadcastDetectedPawn_C.BroadcastToNearbyEnemies
// (Public, HasDefaults, BlueprintCallable, BlueprintEvent)

void USERV_BroadcastDetectedPawn_C::BroadcastToNearbyEnemies()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("SERV_BroadcastDetectedPawn_C", "BroadcastToNearbyEnemies");

	UObject::ProcessEvent(Func, nullptr);
}

}

