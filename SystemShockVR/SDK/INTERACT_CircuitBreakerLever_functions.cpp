#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: INTERACT_CircuitBreakerLever

#include "Basic.hpp"

#include "INTERACT_CircuitBreakerLever_classes.hpp"
#include "INTERACT_CircuitBreakerLever_parameters.hpp"


namespace SDK
{

// Function INTERACT_CircuitBreakerLever.INTERACT_CircuitBreakerLever_C.IsButtonFunctional
// (Public, HasOutParams, BlueprintCallable, BlueprintEvent, BlueprintPure)
// Parameters:
// bool                                    CheckPower                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor)
// bool                                    Result                                                 (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor)

void AINTERACT_CircuitBreakerLever_C::IsButtonFunctional(bool CheckPower, bool* Result)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("INTERACT_CircuitBreakerLever_C", "IsButtonFunctional");

	Params::INTERACT_CircuitBreakerLever_C_IsButtonFunctional Parms{};

	Parms.CheckPower = CheckPower;

	UObject::ProcessEvent(Func, &Parms);

	if (Result != nullptr)
		*Result = Parms.Result;
}


// Function INTERACT_CircuitBreakerLever.INTERACT_CircuitBreakerLever_C.OnInteractSuccess
// (Protected, BlueprintCallable, BlueprintEvent)
// Parameters:
// class AActor*                           SourceActor                                            (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void AINTERACT_CircuitBreakerLever_C::OnInteractSuccess(class AActor* SourceActor)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("INTERACT_CircuitBreakerLever_C", "OnInteractSuccess");

	Params::INTERACT_CircuitBreakerLever_C_OnInteractSuccess Parms{};

	Parms.SourceActor = SourceActor;

	UObject::ProcessEvent(Func, &Parms);
}


// Function INTERACT_CircuitBreakerLever.INTERACT_CircuitBreakerLever_C.UpdatePoweredStates
// (Protected, HasDefaults, BlueprintCallable, BlueprintEvent)

void AINTERACT_CircuitBreakerLever_C::UpdatePoweredStates()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("INTERACT_CircuitBreakerLever_C", "UpdatePoweredStates");

	UObject::ProcessEvent(Func, nullptr);
}


// Function INTERACT_CircuitBreakerLever.INTERACT_CircuitBreakerLever_C.InitializeButtonState
// (Protected, BlueprintCallable, BlueprintEvent)

void AINTERACT_CircuitBreakerLever_C::InitializeButtonState()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("INTERACT_CircuitBreakerLever_C", "InitializeButtonState");

	UObject::ProcessEvent(Func, nullptr);
}


// Function INTERACT_CircuitBreakerLever.INTERACT_CircuitBreakerLever_C.EVENT_OnFinishedLoadingLevelCollection
// (Private, BlueprintCallable, BlueprintEvent)

void AINTERACT_CircuitBreakerLever_C::EVENT_OnFinishedLoadingLevelCollection()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("INTERACT_CircuitBreakerLever_C", "EVENT_OnFinishedLoadingLevelCollection");

	UObject::ProcessEvent(Func, nullptr);
}


// Function INTERACT_CircuitBreakerLever.INTERACT_CircuitBreakerLever_C.CanModifyAnyTargetState
// (Protected, HasOutParams, BlueprintCallable, BlueprintEvent)
// Parameters:
// bool                                    Result                                                 (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor)

void AINTERACT_CircuitBreakerLever_C::CanModifyAnyTargetState(bool* Result)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("INTERACT_CircuitBreakerLever_C", "CanModifyAnyTargetState");

	Params::INTERACT_CircuitBreakerLever_C_CanModifyAnyTargetState Parms{};

	UObject::ProcessEvent(Func, &Parms);

	if (Result != nullptr)
		*Result = Parms.Result;
}


// Function INTERACT_CircuitBreakerLever.INTERACT_CircuitBreakerLever_C.SetInteractPowered
// (Public, HasOutParams, BlueprintCallable, BlueprintEvent)
// Parameters:
// bool                                    State_0                                                (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor)
// bool                                    Result                                                 (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor)

void AINTERACT_CircuitBreakerLever_C::SetInteractPowered(bool State_0, bool* Result)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("INTERACT_CircuitBreakerLever_C", "SetInteractPowered");

	Params::INTERACT_CircuitBreakerLever_C_SetInteractPowered Parms{};

	Parms.State_0 = State_0;

	UObject::ProcessEvent(Func, &Parms);

	if (Result != nullptr)
		*Result = Parms.Result;
}


// Function INTERACT_CircuitBreakerLever.INTERACT_CircuitBreakerLever_C.CanModifyInteractPower
// (Public, HasOutParams, BlueprintCallable, BlueprintEvent)
// Parameters:
// bool                                    Result                                                 (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor)

void AINTERACT_CircuitBreakerLever_C::CanModifyInteractPower(bool* Result)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("INTERACT_CircuitBreakerLever_C", "CanModifyInteractPower");

	Params::INTERACT_CircuitBreakerLever_C_CanModifyInteractPower Parms{};

	UObject::ProcessEvent(Func, &Parms);

	if (Result != nullptr)
		*Result = Parms.Result;
}

}

