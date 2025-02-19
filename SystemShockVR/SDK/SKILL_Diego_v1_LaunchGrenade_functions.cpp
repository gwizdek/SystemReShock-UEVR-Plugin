#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: SKILL_Diego_v1_LaunchGrenade

#include "Basic.hpp"

#include "SKILL_Diego_v1_LaunchGrenade_classes.hpp"
#include "SKILL_Diego_v1_LaunchGrenade_parameters.hpp"


namespace SDK
{

// Function SKILL_Diego_v1_LaunchGrenade.SKILL_Diego_v1_LaunchGrenade_C.GetDesiredGrenadeDelay
// (Public, HasOutParams, BlueprintCallable, BlueprintEvent, BlueprintPure)
// Parameters:
// float                                   ArmTime                                                (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void USKILL_Diego_v1_LaunchGrenade_C::GetDesiredGrenadeDelay(float* ArmTime)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("SKILL_Diego_v1_LaunchGrenade_C", "GetDesiredGrenadeDelay");

	Params::SKILL_Diego_v1_LaunchGrenade_C_GetDesiredGrenadeDelay Parms{};

	UObject::ProcessEvent(Func, &Parms);

	if (ArmTime != nullptr)
		*ArmTime = Parms.ArmTime;
}


// Function SKILL_Diego_v1_LaunchGrenade.SKILL_Diego_v1_LaunchGrenade_C.OnProjectileLaunched
// (Protected, BlueprintCallable, BlueprintEvent)

void USKILL_Diego_v1_LaunchGrenade_C::OnProjectileLaunched()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("SKILL_Diego_v1_LaunchGrenade_C", "OnProjectileLaunched");

	UObject::ProcessEvent(Func, nullptr);
}


// Function SKILL_Diego_v1_LaunchGrenade.SKILL_Diego_v1_LaunchGrenade_C.ArmGrenade
// (Protected, BlueprintCallable, BlueprintEvent)
// Parameters:
// float                                   DelayTime                                              (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void USKILL_Diego_v1_LaunchGrenade_C::ArmGrenade(float DelayTime)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("SKILL_Diego_v1_LaunchGrenade_C", "ArmGrenade");

	Params::SKILL_Diego_v1_LaunchGrenade_C_ArmGrenade Parms{};

	Parms.DelayTime = DelayTime;

	UObject::ProcessEvent(Func, &Parms);
}


// Function SKILL_Diego_v1_LaunchGrenade.SKILL_Diego_v1_LaunchGrenade_C.DropProjectile
// (Protected, BlueprintCallable, BlueprintEvent)

void USKILL_Diego_v1_LaunchGrenade_C::DropProjectile()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("SKILL_Diego_v1_LaunchGrenade_C", "DropProjectile");

	UObject::ProcessEvent(Func, nullptr);
}

}

