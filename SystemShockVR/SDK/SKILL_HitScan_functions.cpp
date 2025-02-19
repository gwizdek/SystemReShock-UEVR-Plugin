#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: SKILL_HitScan

#include "Basic.hpp"

#include "SKILL_HitScan_classes.hpp"
#include "SKILL_HitScan_parameters.hpp"


namespace SDK
{

// Function SKILL_HitScan.SKILL_HitScan_C.TryUseSkill
// (Public, HasOutParams, BlueprintCallable, BlueprintEvent)
// Parameters:
// class UCharacterAction_C*               Result                                                 (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void USKILL_HitScan_C::TryUseSkill(class UCharacterAction_C** Result)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("SKILL_HitScan_C", "TryUseSkill");

	Params::SKILL_HitScan_C_TryUseSkill Parms{};

	UObject::ProcessEvent(Func, &Parms);

	if (Result != nullptr)
		*Result = Parms.Result;
}


// Function SKILL_HitScan.SKILL_HitScan_C.PerformDamageLineTrace
// (Protected, HasDefaults, BlueprintCallable, BlueprintEvent)

void USKILL_HitScan_C::PerformDamageLineTrace()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("SKILL_HitScan_C", "PerformDamageLineTrace");

	UObject::ProcessEvent(Func, nullptr);
}


// Function SKILL_HitScan.SKILL_HitScan_C.CreateBeamEffects
// (Private, BlueprintCallable, BlueprintEvent)
// Parameters:
// struct FVector                          SourceLocation                                         (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// struct FVector                          TargetLocation                                         (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void USKILL_HitScan_C::CreateBeamEffects(const struct FVector& SourceLocation, const struct FVector& TargetLocation)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("SKILL_HitScan_C", "CreateBeamEffects");

	Params::SKILL_HitScan_C_CreateBeamEffects Parms{};

	Parms.SourceLocation = std::move(SourceLocation);
	Parms.TargetLocation = std::move(TargetLocation);

	UObject::ProcessEvent(Func, &Parms);
}


// Function SKILL_HitScan.SKILL_HitScan_C.OnActivateSkill
// (Protected, HasOutParams, BlueprintCallable, BlueprintEvent)
// Parameters:
// bool                                    Result                                                 (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor)

void USKILL_HitScan_C::OnActivateSkill(bool* Result)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("SKILL_HitScan_C", "OnActivateSkill");

	Params::SKILL_HitScan_C_OnActivateSkill Parms{};

	UObject::ProcessEvent(Func, &Parms);

	if (Result != nullptr)
		*Result = Parms.Result;
}


// Function SKILL_HitScan.SKILL_HitScan_C.CanUseSkill
// (Public, HasOutParams, BlueprintCallable, BlueprintEvent, BlueprintPure)
// Parameters:
// bool                                    Result                                                 (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor)

void USKILL_HitScan_C::CanUseSkill(bool* Result)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("SKILL_HitScan_C", "CanUseSkill");

	Params::SKILL_HitScan_C_CanUseSkill Parms{};

	UObject::ProcessEvent(Func, &Parms);

	if (Result != nullptr)
		*Result = Parms.Result;
}


// Function SKILL_HitScan.SKILL_HitScan_C.GetBarrelLocation
// (Public, HasOutParams, BlueprintCallable, BlueprintEvent, BlueprintPure)
// Parameters:
// struct FVector                          StartLocation                                          (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void USKILL_HitScan_C::GetBarrelLocation(struct FVector* StartLocation)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("SKILL_HitScan_C", "GetBarrelLocation");

	Params::SKILL_HitScan_C_GetBarrelLocation Parms{};

	UObject::ProcessEvent(Func, &Parms);

	if (StartLocation != nullptr)
		*StartLocation = std::move(Parms.StartLocation);
}

}

