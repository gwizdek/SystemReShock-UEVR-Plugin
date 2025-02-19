#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: PROJECTILE_IceDrill

#include "Basic.hpp"

#include "PROJECTILE_IceDrill_classes.hpp"
#include "PROJECTILE_IceDrill_parameters.hpp"


namespace SDK
{

// Function PROJECTILE_IceDrill.PROJECTILE_IceDrill_C.SetLockOnActor
// (Public, BlueprintCallable, BlueprintEvent)
// Parameters:
// class AActor*                           Actor                                                  (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void APROJECTILE_IceDrill_C::SetLockOnActor(class AActor* Actor)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("PROJECTILE_IceDrill_C", "SetLockOnActor");

	Params::PROJECTILE_IceDrill_C_SetLockOnActor Parms{};

	Parms.Actor = Actor;

	UObject::ProcessEvent(Func, &Parms);
}


// Function PROJECTILE_IceDrill.PROJECTILE_IceDrill_C.UpdateDrillRotation
// (Protected, BlueprintCallable, BlueprintEvent)
// Parameters:
// float                                   DeltaSeconds                                           (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void APROJECTILE_IceDrill_C::UpdateDrillRotation(float DeltaSeconds)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("PROJECTILE_IceDrill_C", "UpdateDrillRotation");

	Params::PROJECTILE_IceDrill_C_UpdateDrillRotation Parms{};

	Parms.DeltaSeconds = DeltaSeconds;

	UObject::ProcessEvent(Func, &Parms);
}


// Function PROJECTILE_IceDrill.PROJECTILE_IceDrill_C.IncrementalPositionUpdate
// (Protected, HasOutParams, BlueprintCallable, BlueprintEvent)
// Parameters:
// float                                   DeltaTime                                              (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// bool                                    Result                                                 (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor)

void APROJECTILE_IceDrill_C::IncrementalPositionUpdate(float DeltaTime, bool* Result)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("PROJECTILE_IceDrill_C", "IncrementalPositionUpdate");

	Params::PROJECTILE_IceDrill_C_IncrementalPositionUpdate Parms{};

	Parms.DeltaTime = DeltaTime;

	UObject::ProcessEvent(Func, &Parms);

	if (Result != nullptr)
		*Result = Parms.Result;
}


// Function PROJECTILE_IceDrill.PROJECTILE_IceDrill_C.ApplyDamageMod
// (Protected, HasOutParams, HasDefaults, BlueprintCallable, BlueprintEvent)
// Parameters:
// class UAttribManagerComponent*          AttribManager                                          (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// class UOBJ_ImpactData_C*                ImpactData                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// float                                   FrameHitDeltaTime                                      (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// struct FAttribDamageInstance            DamageInstance                                         (Parm, OutParm)
// class UAttribMod*                       DamageMod                                              (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void APROJECTILE_IceDrill_C::ApplyDamageMod(class UAttribManagerComponent* AttribManager, class UOBJ_ImpactData_C* ImpactData, float FrameHitDeltaTime, struct FAttribDamageInstance* DamageInstance, class UAttribMod** DamageMod)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("PROJECTILE_IceDrill_C", "ApplyDamageMod");

	Params::PROJECTILE_IceDrill_C_ApplyDamageMod Parms{};

	Parms.AttribManager = AttribManager;
	Parms.ImpactData = ImpactData;
	Parms.FrameHitDeltaTime = FrameHitDeltaTime;

	UObject::ProcessEvent(Func, &Parms);

	if (DamageInstance != nullptr)
		*DamageInstance = std::move(Parms.DamageInstance);

	if (DamageMod != nullptr)
		*DamageMod = Parms.DamageMod;
}


// Function PROJECTILE_IceDrill.PROJECTILE_IceDrill_C.DestroyProjectile
// (Public, HasDefaults, BlueprintCallable, BlueprintEvent)
// Parameters:
// struct FVector                          ImpactNormal                                           (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void APROJECTILE_IceDrill_C::DestroyProjectile(const struct FVector& ImpactNormal)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("PROJECTILE_IceDrill_C", "DestroyProjectile");

	Params::PROJECTILE_IceDrill_C_DestroyProjectile Parms{};

	Parms.ImpactNormal = std::move(ImpactNormal);

	UObject::ProcessEvent(Func, &Parms);
}

}

