#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: SKILL_CyborgAssassin_ThrowGrenade

#include "Basic.hpp"

#include "SKILL_CyborgAssassin_ThrowGrenade_classes.hpp"
#include "SKILL_CyborgAssassin_ThrowGrenade_parameters.hpp"


namespace SDK
{

// Function SKILL_CyborgAssassin_ThrowGrenade.SKILL_CyborgAssassin_ThrowGrenade_C.GetPredictedLocationToShoot
// (Public, HasOutParams, HasDefaults, BlueprintCallable, BlueprintEvent, BlueprintPure)
// Parameters:
// struct FVector                          SourceLocation                                         (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// struct FVector                          PredictedLocation                                      (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void USKILL_CyborgAssassin_ThrowGrenade_C::GetPredictedLocationToShoot(const struct FVector& SourceLocation, struct FVector* PredictedLocation)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("SKILL_CyborgAssassin_ThrowGrenade_C", "GetPredictedLocationToShoot");

	Params::SKILL_CyborgAssassin_ThrowGrenade_C_GetPredictedLocationToShoot Parms{};

	Parms.SourceLocation = std::move(SourceLocation);

	UObject::ProcessEvent(Func, &Parms);

	if (PredictedLocation != nullptr)
		*PredictedLocation = std::move(Parms.PredictedLocation);
}


// Function SKILL_CyborgAssassin_ThrowGrenade.SKILL_CyborgAssassin_ThrowGrenade_C.SpawnProjectile
// (Protected, HasDefaults, BlueprintCallable, BlueprintEvent)

void USKILL_CyborgAssassin_ThrowGrenade_C::SpawnProjectile()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("SKILL_CyborgAssassin_ThrowGrenade_C", "SpawnProjectile");

	UObject::ProcessEvent(Func, nullptr);
}


// Function SKILL_CyborgAssassin_ThrowGrenade.SKILL_CyborgAssassin_ThrowGrenade_C.OnProjectileLaunched
// (Protected, BlueprintCallable, BlueprintEvent)

void USKILL_CyborgAssassin_ThrowGrenade_C::OnProjectileLaunched()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("SKILL_CyborgAssassin_ThrowGrenade_C", "OnProjectileLaunched");

	UObject::ProcessEvent(Func, nullptr);
}


// Function SKILL_CyborgAssassin_ThrowGrenade.SKILL_CyborgAssassin_ThrowGrenade_C.DropProjectile
// (Protected, BlueprintCallable, BlueprintEvent)

void USKILL_CyborgAssassin_ThrowGrenade_C::DropProjectile()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("SKILL_CyborgAssassin_ThrowGrenade_C", "DropProjectile");

	UObject::ProcessEvent(Func, nullptr);
}

}

