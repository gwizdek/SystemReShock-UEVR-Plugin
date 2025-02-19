#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: PAWN_CyberBully

#include "Basic.hpp"

#include "PAWN_CyberBully_classes.hpp"
#include "PAWN_CyberBully_parameters.hpp"


namespace SDK
{

// Function PAWN_CyberBully.PAWN_CyberBully_C.OnBullorangReceived__DelegateSignature
// (Public, Delegate, BlueprintCallable, BlueprintEvent)

void APAWN_CyberBully_C::OnBullorangReceived__DelegateSignature()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("PAWN_CyberBully_C", "OnBullorangReceived__DelegateSignature");

	UObject::ProcessEvent(Func, nullptr);
}


// Function PAWN_CyberBully.PAWN_CyberBully_C.ExecuteUbergraph_PAWN_CyberBully
// (Final, UbergraphFunction)
// Parameters:
// int32                                   EntryPoint                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void APAWN_CyberBully_C::ExecuteUbergraph_PAWN_CyberBully(int32 EntryPoint)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("PAWN_CyberBully_C", "ExecuteUbergraph_PAWN_CyberBully");

	Params::PAWN_CyberBully_C_ExecuteUbergraph_PAWN_CyberBully Parms{};

	Parms.EntryPoint = EntryPoint;

	UObject::ProcessEvent(Func, &Parms);
}


// Function PAWN_CyberBully.PAWN_CyberBully_C.ReceiveTick
// (Event, Public, BlueprintEvent)
// Parameters:
// float                                   DeltaSeconds                                           (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void APAWN_CyberBully_C::ReceiveTick(float DeltaSeconds)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("PAWN_CyberBully_C", "ReceiveTick");

	Params::PAWN_CyberBully_C_ReceiveTick Parms{};

	Parms.DeltaSeconds = DeltaSeconds;

	UObject::ProcessEvent(Func, &Parms);
}


// Function PAWN_CyberBully.PAWN_CyberBully_C.DeployBullorang
// (Public, HasDefaults, BlueprintCallable, BlueprintEvent)
// Parameters:
// class UClass*                           BullorangClass                                         (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void APAWN_CyberBully_C::DeployBullorang(class UClass* BullorangClass)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("PAWN_CyberBully_C", "DeployBullorang");

	Params::PAWN_CyberBully_C_DeployBullorang Parms{};

	Parms.BullorangClass = BullorangClass;

	UObject::ProcessEvent(Func, &Parms);
}


// Function PAWN_CyberBully.PAWN_CyberBully_C.DisplayMeshBullorang
// (Public, BlueprintCallable, BlueprintEvent)
// Parameters:
// bool                                    Display                                                (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor)

void APAWN_CyberBully_C::DisplayMeshBullorang(bool Display)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("PAWN_CyberBully_C", "DisplayMeshBullorang");

	Params::PAWN_CyberBully_C_DisplayMeshBullorang Parms{};

	Parms.Display = Display;

	UObject::ProcessEvent(Func, &Parms);
}


// Function PAWN_CyberBully.PAWN_CyberBully_C.ReceiveBullorang
// (Public, BlueprintCallable, BlueprintEvent)

void APAWN_CyberBully_C::ReceiveBullorang()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("PAWN_CyberBully_C", "ReceiveBullorang");

	UObject::ProcessEvent(Func, nullptr);
}


// Function PAWN_CyberBully.PAWN_CyberBully_C.GetIceShieldSize
// (Public, HasOutParams, BlueprintCallable, BlueprintEvent, BlueprintPure)
// Parameters:
// float                                   Result                                                 (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void APAWN_CyberBully_C::GetIceShieldSize(float* Result)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("PAWN_CyberBully_C", "GetIceShieldSize");

	Params::PAWN_CyberBully_C_GetIceShieldSize Parms{};

	UObject::ProcessEvent(Func, &Parms);

	if (Result != nullptr)
		*Result = Parms.Result;
}


// Function PAWN_CyberBully.PAWN_CyberBully_C.OnCharacterDied
// (Public, HasOutParams, HasDefaults, BlueprintCallable, BlueprintEvent)
// Parameters:
// class UOBJ_ImpactData_C*                ImpactData                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// struct FAttribDamageInstance            DamageInstance                                         (BlueprintVisible, BlueprintReadOnly, Parm)
// class AActor*                           OtherActor                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// bool                                    Result                                                 (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor)

void APAWN_CyberBully_C::OnCharacterDied(class UOBJ_ImpactData_C* ImpactData, const struct FAttribDamageInstance& DamageInstance, class AActor* OtherActor, bool* Result)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("PAWN_CyberBully_C", "OnCharacterDied");

	Params::PAWN_CyberBully_C_OnCharacterDied Parms{};

	Parms.ImpactData = ImpactData;
	Parms.DamageInstance = std::move(DamageInstance);
	Parms.OtherActor = OtherActor;

	UObject::ProcessEvent(Func, &Parms);

	if (Result != nullptr)
		*Result = Parms.Result;
}

}

