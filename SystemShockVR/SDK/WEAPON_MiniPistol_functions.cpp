#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: WEAPON_MiniPistol

#include "Basic.hpp"

#include "WEAPON_MiniPistol_classes.hpp"
#include "WEAPON_MiniPistol_parameters.hpp"


namespace SDK
{

// Function WEAPON_MiniPistol.WEAPON_MiniPistol_C.ExecuteUbergraph_WEAPON_MiniPistol
// (Final, UbergraphFunction)
// Parameters:
// int32                                   EntryPoint                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UWEAPON_MiniPistol_C::ExecuteUbergraph_WEAPON_MiniPistol(int32 EntryPoint)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WEAPON_MiniPistol_C", "ExecuteUbergraph_WEAPON_MiniPistol");

	Params::WEAPON_MiniPistol_C_ExecuteUbergraph_WEAPON_MiniPistol Parms{};

	Parms.EntryPoint = EntryPoint;

	UObject::ProcessEvent(Func, &Parms);
}


// Function WEAPON_MiniPistol.WEAPON_MiniPistol_C.AsyncPlayCooldownSFX
// (BlueprintCallable, BlueprintEvent)

void UWEAPON_MiniPistol_C::AsyncPlayCooldownSFX()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WEAPON_MiniPistol_C", "AsyncPlayCooldownSFX");

	UObject::ProcessEvent(Func, nullptr);
}


// Function WEAPON_MiniPistol.WEAPON_MiniPistol_C.OnLoaded_2CC67EA24D4297D5895AF4B7131E9430
// (BlueprintCallable, BlueprintEvent)
// Parameters:
// class UObject*                          Loaded                                                 (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UWEAPON_MiniPistol_C::OnLoaded_2CC67EA24D4297D5895AF4B7131E9430(class UObject* Loaded)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WEAPON_MiniPistol_C", "OnLoaded_2CC67EA24D4297D5895AF4B7131E9430");

	Params::WEAPON_MiniPistol_C_OnLoaded_2CC67EA24D4297D5895AF4B7131E9430 Parms{};

	Parms.Loaded = Loaded;

	UObject::ProcessEvent(Func, &Parms);
}


// Function WEAPON_MiniPistol.WEAPON_MiniPistol_C.ConsumeAmmo
// (Public, BlueprintCallable, BlueprintEvent)

void UWEAPON_MiniPistol_C::ConsumeAmmo()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WEAPON_MiniPistol_C", "ConsumeAmmo");

	UObject::ProcessEvent(Func, nullptr);
}


// Function WEAPON_MiniPistol.WEAPON_MiniPistol_C.RefillMagazine
// (Public, BlueprintCallable, BlueprintEvent)

void UWEAPON_MiniPistol_C::RefillMagazine()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WEAPON_MiniPistol_C", "RefillMagazine");

	UObject::ProcessEvent(Func, nullptr);
}


// Function WEAPON_MiniPistol.WEAPON_MiniPistol_C.OnWeaponBecameActivatable
// (Public, BlueprintCallable, BlueprintEvent)
// Parameters:
// class APAWN_SystemShockCharacter_C*     Character                                              (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// bool                                    ShowImmediately                                        (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor)

void UWEAPON_MiniPistol_C::OnWeaponBecameActivatable(class APAWN_SystemShockCharacter_C* Character, bool ShowImmediately)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WEAPON_MiniPistol_C", "OnWeaponBecameActivatable");

	Params::WEAPON_MiniPistol_C_OnWeaponBecameActivatable Parms{};

	Parms.Character = Character;
	Parms.ShowImmediately = ShowImmediately;

	UObject::ProcessEvent(Func, &Parms);
}


// Function WEAPON_MiniPistol.WEAPON_MiniPistol_C.SetHasBarrelExtension
// (Public, BlueprintCallable, BlueprintEvent)
// Parameters:
// bool                                    State                                                  (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor)

void UWEAPON_MiniPistol_C::SetHasBarrelExtension(bool State)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WEAPON_MiniPistol_C", "SetHasBarrelExtension");

	Params::WEAPON_MiniPistol_C_SetHasBarrelExtension Parms{};

	Parms.State = State;

	UObject::ProcessEvent(Func, &Parms);
}


// Function WEAPON_MiniPistol.WEAPON_MiniPistol_C.UpdateDryIdleSequence
// (Protected, BlueprintCallable, BlueprintEvent)

void UWEAPON_MiniPistol_C::UpdateDryIdleSequence()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WEAPON_MiniPistol_C", "UpdateDryIdleSequence");

	UObject::ProcessEvent(Func, nullptr);
}


// Function WEAPON_MiniPistol.WEAPON_MiniPistol_C.FireProjectile
// (Public, HasOutParams, HasDefaults, BlueprintCallable, BlueprintEvent)
// Parameters:
// class AActor*                           FiredProjectile                                        (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// struct FVector                          Direction                                              (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UWEAPON_MiniPistol_C::FireProjectile(class AActor** FiredProjectile, struct FVector* Direction)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WEAPON_MiniPistol_C", "FireProjectile");

	Params::WEAPON_MiniPistol_C_FireProjectile Parms{};

	UObject::ProcessEvent(Func, &Parms);

	if (FiredProjectile != nullptr)
		*FiredProjectile = Parms.FiredProjectile;

	if (Direction != nullptr)
		*Direction = std::move(Parms.Direction);
}


// Function WEAPON_MiniPistol.WEAPON_MiniPistol_C.GetProjectileClass
// (Public, HasOutParams, BlueprintCallable, BlueprintEvent, BlueprintPure)
// Parameters:
// class UClass*                           Result                                                 (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UWEAPON_MiniPistol_C::GetProjectileClass(class UClass** Result)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WEAPON_MiniPistol_C", "GetProjectileClass");

	Params::WEAPON_MiniPistol_C_GetProjectileClass Parms{};

	UObject::ProcessEvent(Func, &Parms);

	if (Result != nullptr)
		*Result = Parms.Result;
}


// Function WEAPON_MiniPistol.WEAPON_MiniPistol_C.OnBecomeUnactivatable
// (Public, HasOutParams, BlueprintCallable, BlueprintEvent)
// Parameters:
// bool                                    Result                                                 (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor)

void UWEAPON_MiniPistol_C::OnBecomeUnactivatable(bool* Result)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WEAPON_MiniPistol_C", "OnBecomeUnactivatable");

	Params::WEAPON_MiniPistol_C_OnBecomeUnactivatable Parms{};

	UObject::ProcessEvent(Func, &Parms);

	if (Result != nullptr)
		*Result = Parms.Result;
}


// Function WEAPON_MiniPistol.WEAPON_MiniPistol_C.HasBurstFireOption
// (Public, HasOutParams, BlueprintCallable, BlueprintEvent, BlueprintPure)
// Parameters:
// bool                                    Result                                                 (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor)

void UWEAPON_MiniPistol_C::HasBurstFireOption(bool* Result)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WEAPON_MiniPistol_C", "HasBurstFireOption");

	Params::WEAPON_MiniPistol_C_HasBurstFireOption Parms{};

	UObject::ProcessEvent(Func, &Parms);

	if (Result != nullptr)
		*Result = Parms.Result;
}


// Function WEAPON_MiniPistol.WEAPON_MiniPistol_C.IsUsingBurstFire
// (Public, HasOutParams, BlueprintCallable, BlueprintEvent, BlueprintPure)
// Parameters:
// bool                                    Result                                                 (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor)

void UWEAPON_MiniPistol_C::IsUsingBurstFire(bool* Result)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WEAPON_MiniPistol_C", "IsUsingBurstFire");

	Params::WEAPON_MiniPistol_C_IsUsingBurstFire Parms{};

	UObject::ProcessEvent(Func, &Parms);

	if (Result != nullptr)
		*Result = Parms.Result;
}


// Function WEAPON_MiniPistol.WEAPON_MiniPistol_C.GetWeaponModeDefaults
// (Public, HasOutParams, HasDefaults, BlueprintCallable, BlueprintEvent, BlueprintPure)
// Parameters:
// int32                                   Index_0                                                (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// struct FSTRUCT_WeaponMode               Mode                                                   (Parm, OutParm, HasGetValueTypeHash)

void UWEAPON_MiniPistol_C::GetWeaponModeDefaults(int32 Index_0, struct FSTRUCT_WeaponMode* Mode)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WEAPON_MiniPistol_C", "GetWeaponModeDefaults");

	Params::WEAPON_MiniPistol_C_GetWeaponModeDefaults Parms{};

	Parms.Index_0 = Index_0;

	UObject::ProcessEvent(Func, &Parms);

	if (Mode != nullptr)
		*Mode = std::move(Parms.Mode);
}


// Function WEAPON_MiniPistol.WEAPON_MiniPistol_C.SetUsingBurstFire
// (Public, BlueprintCallable, BlueprintEvent)
// Parameters:
// bool                                    State                                                  (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor)

void UWEAPON_MiniPistol_C::SetUsingBurstFire(bool State)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WEAPON_MiniPistol_C", "SetUsingBurstFire");

	Params::WEAPON_MiniPistol_C_SetUsingBurstFire Parms{};

	Parms.State = State;

	UObject::ProcessEvent(Func, &Parms);
}

}

