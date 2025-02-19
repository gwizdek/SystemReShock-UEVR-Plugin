#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: INTERACT_ForceXDoor

#include "Basic.hpp"

#include "INTERACT_ForceXDoor_classes.hpp"
#include "INTERACT_ForceXDoor_parameters.hpp"


namespace SDK
{

// Function INTERACT_ForceXDoor.INTERACT_ForceXDoor_C.ExecuteUbergraph_INTERACT_ForceXDoor
// (Final, UbergraphFunction)
// Parameters:
// int32                                   EntryPoint                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void AINTERACT_ForceXDoor_C::ExecuteUbergraph_INTERACT_ForceXDoor(int32 EntryPoint)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("INTERACT_ForceXDoor_C", "ExecuteUbergraph_INTERACT_ForceXDoor");

	Params::INTERACT_ForceXDoor_C_ExecuteUbergraph_INTERACT_ForceXDoor Parms{};

	Parms.EntryPoint = EntryPoint;

	UObject::ProcessEvent(Func, &Parms);
}


// Function INTERACT_ForceXDoor.INTERACT_ForceXDoor_C.ReceiveTick
// (Event, Public, BlueprintEvent)
// Parameters:
// float                                   DeltaSeconds                                           (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void AINTERACT_ForceXDoor_C::ReceiveTick(float DeltaSeconds)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("INTERACT_ForceXDoor_C", "ReceiveTick");

	Params::INTERACT_ForceXDoor_C_ReceiveTick Parms{};

	Parms.DeltaSeconds = DeltaSeconds;

	UObject::ProcessEvent(Func, &Parms);
}


// Function INTERACT_ForceXDoor.INTERACT_ForceXDoor_C.CloseDoor
// (Protected, BlueprintCallable, BlueprintEvent)

void AINTERACT_ForceXDoor_C::CloseDoor()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("INTERACT_ForceXDoor_C", "CloseDoor");

	UObject::ProcessEvent(Func, nullptr);
}


// Function INTERACT_ForceXDoor.INTERACT_ForceXDoor_C.OpenDoor
// (Public, BlueprintCallable, BlueprintEvent)
// Parameters:
// class AActor*                           SourceActor                                            (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void AINTERACT_ForceXDoor_C::OpenDoor(class AActor* SourceActor)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("INTERACT_ForceXDoor_C", "OpenDoor");

	Params::INTERACT_ForceXDoor_C_OpenDoor Parms{};

	Parms.SourceActor = SourceActor;

	UObject::ProcessEvent(Func, &Parms);
}


// Function INTERACT_ForceXDoor.INTERACT_ForceXDoor_C.ReceiveBeginPlay
// (Event, Protected, BlueprintEvent)

void AINTERACT_ForceXDoor_C::ReceiveBeginPlay()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("INTERACT_ForceXDoor_C", "ReceiveBeginPlay");

	UObject::ProcessEvent(Func, nullptr);
}


// Function INTERACT_ForceXDoor.INTERACT_ForceXDoor_C.IsSafeToClose
// (Public, HasOutParams, BlueprintCallable, BlueprintEvent, BlueprintPure)
// Parameters:
// bool                                    Result                                                 (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor)

void AINTERACT_ForceXDoor_C::IsSafeToClose(bool* Result)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("INTERACT_ForceXDoor_C", "IsSafeToClose");

	Params::INTERACT_ForceXDoor_C_IsSafeToClose Parms{};

	UObject::ProcessEvent(Func, &Parms);

	if (Result != nullptr)
		*Result = Parms.Result;
}


// Function INTERACT_ForceXDoor.INTERACT_ForceXDoor_C.UpdateMaterial
// (Public, BlueprintCallable, BlueprintEvent)

void AINTERACT_ForceXDoor_C::UpdateMaterial()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("INTERACT_ForceXDoor_C", "UpdateMaterial");

	UObject::ProcessEvent(Func, nullptr);
}


// Function INTERACT_ForceXDoor.INTERACT_ForceXDoor_C.UpdateAnimBP
// (Public, BlueprintCallable, BlueprintEvent)

void AINTERACT_ForceXDoor_C::UpdateAnimBP()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("INTERACT_ForceXDoor_C", "UpdateAnimBP");

	UObject::ProcessEvent(Func, nullptr);
}


// Function INTERACT_ForceXDoor.INTERACT_ForceXDoor_C.EVENT_OnStateFinished
// (Protected, BlueprintCallable, BlueprintEvent)

void AINTERACT_ForceXDoor_C::EVENT_OnStateFinished()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("INTERACT_ForceXDoor_C", "EVENT_OnStateFinished");

	UObject::ProcessEvent(Func, nullptr);
}


// Function INTERACT_ForceXDoor.INTERACT_ForceXDoor_C.GetActiveMontageDuration
// (Public, HasOutParams, BlueprintCallable, BlueprintEvent, BlueprintPure)
// Parameters:
// float                                   Duration                                               (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void AINTERACT_ForceXDoor_C::GetActiveMontageDuration(float* Duration)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("INTERACT_ForceXDoor_C", "GetActiveMontageDuration");

	Params::INTERACT_ForceXDoor_C_GetActiveMontageDuration Parms{};

	UObject::ProcessEvent(Func, &Parms);

	if (Duration != nullptr)
		*Duration = Parms.Duration;
}


// Function INTERACT_ForceXDoor.INTERACT_ForceXDoor_C.UpdateDoorEmissiveStrength
// (Public, HasOutParams, BlueprintCallable, BlueprintEvent)
// Parameters:
// float                                   Scale                                                  (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// float                                   Strength                                               (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void AINTERACT_ForceXDoor_C::UpdateDoorEmissiveStrength(float Scale, float* Strength)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("INTERACT_ForceXDoor_C", "UpdateDoorEmissiveStrength");

	Params::INTERACT_ForceXDoor_C_UpdateDoorEmissiveStrength Parms{};

	Parms.Scale = Scale;

	UObject::ProcessEvent(Func, &Parms);

	if (Strength != nullptr)
		*Strength = Parms.Strength;
}

}

