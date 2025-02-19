#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: MODKIT_IonPulseRifle_Energy

#include "Basic.hpp"

#include "MODKIT_IonPulseRifle_Energy_classes.hpp"
#include "MODKIT_IonPulseRifle_Energy_parameters.hpp"


namespace SDK
{

// Function MODKIT_IonPulseRifle_Energy.MODKIT_IonPulseRifle_Energy_C.TryApplyWeaponModifications
// (Public, HasOutParams, BlueprintCallable, BlueprintEvent)
// Parameters:
// class UITEM_WeaponBase_C*               Weapon                                                 (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// bool                                    DuringInitialization                                   (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor)
// bool                                    Result                                                 (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor)

void UMODKIT_IonPulseRifle_Energy_C::TryApplyWeaponModifications(class UITEM_WeaponBase_C* Weapon, bool DuringInitialization, bool* Result)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("MODKIT_IonPulseRifle_Energy_C", "TryApplyWeaponModifications");

	Params::MODKIT_IonPulseRifle_Energy_C_TryApplyWeaponModifications Parms{};

	Parms.Weapon = Weapon;
	Parms.DuringInitialization = DuringInitialization;

	UObject::ProcessEvent(Func, &Parms);

	if (Result != nullptr)
		*Result = Parms.Result;
}


// Function MODKIT_IonPulseRifle_Energy.MODKIT_IonPulseRifle_Energy_C.GetModifiedWeaponMode
// (Public, HasOutParams, HasDefaults, BlueprintCallable, BlueprintEvent)
// Parameters:
// struct FSTRUCT_WeaponMode               WeaponMode                                             (BlueprintVisible, BlueprintReadOnly, Parm, HasGetValueTypeHash)
// struct FSTRUCT_WeaponMode               ResultMode                                             (Parm, OutParm, HasGetValueTypeHash)

void UMODKIT_IonPulseRifle_Energy_C::GetModifiedWeaponMode(const struct FSTRUCT_WeaponMode& WeaponMode, struct FSTRUCT_WeaponMode* ResultMode)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("MODKIT_IonPulseRifle_Energy_C", "GetModifiedWeaponMode");

	Params::MODKIT_IonPulseRifle_Energy_C_GetModifiedWeaponMode Parms{};

	Parms.WeaponMode = std::move(WeaponMode);

	UObject::ProcessEvent(Func, &Parms);

	if (ResultMode != nullptr)
		*ResultMode = std::move(Parms.ResultMode);
}

}

