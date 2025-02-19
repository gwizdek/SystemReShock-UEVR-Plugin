#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: PAWN_CyborgAssassin

#include "Basic.hpp"

#include "PAWN_CyborgAssassin_classes.hpp"
#include "PAWN_CyborgAssassin_parameters.hpp"


namespace SDK
{

// Function PAWN_CyborgAssassin.PAWN_CyborgAssassin_C.ExecuteUbergraph_PAWN_CyborgAssassin
// (Final, UbergraphFunction)
// Parameters:
// int32                                   EntryPoint                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void APAWN_CyborgAssassin_C::ExecuteUbergraph_PAWN_CyborgAssassin(int32 EntryPoint)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("PAWN_CyborgAssassin_C", "ExecuteUbergraph_PAWN_CyborgAssassin");

	Params::PAWN_CyborgAssassin_C_ExecuteUbergraph_PAWN_CyborgAssassin Parms{};

	Parms.EntryPoint = EntryPoint;

	UObject::ProcessEvent(Func, &Parms);
}


// Function PAWN_CyborgAssassin.PAWN_CyborgAssassin_C.ReceiveTick
// (Event, Public, BlueprintEvent)
// Parameters:
// float                                   DeltaSeconds                                           (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void APAWN_CyborgAssassin_C::ReceiveTick(float DeltaSeconds)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("PAWN_CyborgAssassin_C", "ReceiveTick");

	Params::PAWN_CyborgAssassin_C_ReceiveTick Parms{};

	Parms.DeltaSeconds = DeltaSeconds;

	UObject::ProcessEvent(Func, &Parms);
}


// Function PAWN_CyborgAssassin.PAWN_CyborgAssassin_C.SetLaserEnabled
// (Public, BlueprintCallable, BlueprintEvent)
// Parameters:
// bool                                    IsEnabled                                              (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor)

void APAWN_CyborgAssassin_C::SetLaserEnabled(bool IsEnabled)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("PAWN_CyborgAssassin_C", "SetLaserEnabled");

	Params::PAWN_CyborgAssassin_C_SetLaserEnabled Parms{};

	Parms.IsEnabled = IsEnabled;

	UObject::ProcessEvent(Func, &Parms);
}


// Function PAWN_CyborgAssassin.PAWN_CyborgAssassin_C.UpdateLaser
// (Public, HasDefaults, BlueprintCallable, BlueprintEvent)

void APAWN_CyborgAssassin_C::UpdateLaser()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("PAWN_CyborgAssassin_C", "UpdateLaser");

	UObject::ProcessEvent(Func, nullptr);
}


// Function PAWN_CyborgAssassin.PAWN_CyborgAssassin_C.DestroyRifle
// (Public, HasDefaults, BlueprintCallable, BlueprintEvent)
// Parameters:
// bool                                    DuringBeginPlay                                        (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor)

void APAWN_CyborgAssassin_C::DestroyRifle(bool DuringBeginPlay)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("PAWN_CyborgAssassin_C", "DestroyRifle");

	Params::PAWN_CyborgAssassin_C_DestroyRifle Parms{};

	Parms.DuringBeginPlay = DuringBeginPlay;

	UObject::ProcessEvent(Func, &Parms);
}


// Function PAWN_CyborgAssassin.PAWN_CyborgAssassin_C.InitializeCharacterAsDead
// (Public, HasOutParams, BlueprintCallable, BlueprintEvent)
// Parameters:
// bool                                    Result                                                 (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor)

void APAWN_CyborgAssassin_C::InitializeCharacterAsDead(bool* Result)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("PAWN_CyborgAssassin_C", "InitializeCharacterAsDead");

	Params::PAWN_CyborgAssassin_C_InitializeCharacterAsDead Parms{};

	UObject::ProcessEvent(Func, &Parms);

	if (Result != nullptr)
		*Result = Parms.Result;
}


// Function PAWN_CyborgAssassin.PAWN_CyborgAssassin_C.OnCharacterDied
// (Public, HasOutParams, HasDefaults, BlueprintCallable, BlueprintEvent)
// Parameters:
// class UOBJ_ImpactData_C*                ImpactData                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// struct FAttribDamageInstance            DamageInstance                                         (BlueprintVisible, BlueprintReadOnly, Parm)
// class AActor*                           OtherActor                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// bool                                    Result                                                 (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor)

void APAWN_CyborgAssassin_C::OnCharacterDied(class UOBJ_ImpactData_C* ImpactData, const struct FAttribDamageInstance& DamageInstance, class AActor* OtherActor, bool* Result)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("PAWN_CyborgAssassin_C", "OnCharacterDied");

	Params::PAWN_CyborgAssassin_C_OnCharacterDied Parms{};

	Parms.ImpactData = ImpactData;
	Parms.DamageInstance = std::move(DamageInstance);
	Parms.OtherActor = OtherActor;

	UObject::ProcessEvent(Func, &Parms);

	if (Result != nullptr)
		*Result = Parms.Result;
}


// Function PAWN_CyborgAssassin.PAWN_CyborgAssassin_C.OnUpdateLaserVisibility
// (Protected, BlueprintCallable, BlueprintEvent)

void APAWN_CyborgAssassin_C::OnUpdateLaserVisibility()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("PAWN_CyborgAssassin_C", "OnUpdateLaserVisibility");

	UObject::ProcessEvent(Func, nullptr);
}


// Function PAWN_CyborgAssassin.PAWN_CyborgAssassin_C.OnMagneticDisableStateChanged
// (Protected, BlueprintCallable, BlueprintEvent)
// Parameters:
// bool                                    DisableState                                           (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor)

void APAWN_CyborgAssassin_C::OnMagneticDisableStateChanged(bool DisableState)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("PAWN_CyborgAssassin_C", "OnMagneticDisableStateChanged");

	Params::PAWN_CyborgAssassin_C_OnMagneticDisableStateChanged Parms{};

	Parms.DisableState = DisableState;

	UObject::ProcessEvent(Func, &Parms);
}


// Function PAWN_CyborgAssassin.PAWN_CyborgAssassin_C.OnCharacterVisibilityChanged
// (Protected, BlueprintCallable, BlueprintEvent)
// Parameters:
// bool                                    VisibilityState                                        (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor)

void APAWN_CyborgAssassin_C::OnCharacterVisibilityChanged(bool VisibilityState)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("PAWN_CyborgAssassin_C", "OnCharacterVisibilityChanged");

	Params::PAWN_CyborgAssassin_C_OnCharacterVisibilityChanged Parms{};

	Parms.VisibilityState = VisibilityState;

	UObject::ProcessEvent(Func, &Parms);
}

}

