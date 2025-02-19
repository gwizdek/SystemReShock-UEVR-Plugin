#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: COMP_LimbManager

#include "Basic.hpp"

#include "COMP_LimbManager_classes.hpp"
#include "COMP_LimbManager_parameters.hpp"


namespace SDK
{

// Function COMP_LimbManager.COMP_LimbManager_C.ExecuteUbergraph_COMP_LimbManager
// (Final, UbergraphFunction)
// Parameters:
// int32                                   EntryPoint                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UCOMP_LimbManager_C::ExecuteUbergraph_COMP_LimbManager(int32 EntryPoint)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("COMP_LimbManager_C", "ExecuteUbergraph_COMP_LimbManager");

	Params::COMP_LimbManager_C_ExecuteUbergraph_COMP_LimbManager Parms{};

	Parms.EntryPoint = EntryPoint;

	UObject::ProcessEvent(Func, &Parms);
}


// Function COMP_LimbManager.COMP_LimbManager_C.ReceiveTick
// (Event, Public, BlueprintEvent)
// Parameters:
// float                                   DeltaSeconds                                           (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UCOMP_LimbManager_C::ReceiveTick(float DeltaSeconds)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("COMP_LimbManager_C", "ReceiveTick");

	Params::COMP_LimbManager_C_ReceiveTick Parms{};

	Parms.DeltaSeconds = DeltaSeconds;

	UObject::ProcessEvent(Func, &Parms);
}


// Function COMP_LimbManager.COMP_LimbManager_C.IsLimbImpactedInFront
// (Public, HasOutParams, HasDefaults, BlueprintCallable, BlueprintEvent, BlueprintPure)
// Parameters:
// struct FSTRUCT_AnimatedLimb             LimbSettings                                           (BlueprintVisible, BlueprintReadOnly, Parm, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// struct FVector                          ImpactLocation                                         (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// bool                                    Result                                                 (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor)

void UCOMP_LimbManager_C::IsLimbImpactedInFront(const struct FSTRUCT_AnimatedLimb& LimbSettings, const struct FVector& ImpactLocation, bool* Result)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("COMP_LimbManager_C", "IsLimbImpactedInFront");

	Params::COMP_LimbManager_C_IsLimbImpactedInFront Parms{};

	Parms.LimbSettings = std::move(LimbSettings);
	Parms.ImpactLocation = std::move(ImpactLocation);

	UObject::ProcessEvent(Func, &Parms);

	if (Result != nullptr)
		*Result = Parms.Result;
}


// Function COMP_LimbManager.COMP_LimbManager_C.SearchForLimbNameFromBoneName
// (Public, HasOutParams, HasDefaults, BlueprintCallable, BlueprintEvent, BlueprintPure)
// Parameters:
// class FName                             BoneName                                               (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// class FName                             Result                                                 (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UCOMP_LimbManager_C::SearchForLimbNameFromBoneName(class FName BoneName, class FName* Result)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("COMP_LimbManager_C", "SearchForLimbNameFromBoneName");

	Params::COMP_LimbManager_C_SearchForLimbNameFromBoneName Parms{};

	Parms.BoneName = BoneName;

	UObject::ProcessEvent(Func, &Parms);

	if (Result != nullptr)
		*Result = Parms.Result;
}


// Function COMP_LimbManager.COMP_LimbManager_C.GetLimbFromBoneName
// (Public, HasOutParams, HasDefaults, BlueprintCallable, BlueprintEvent, BlueprintPure)
// Parameters:
// class FName                             BoneName                                               (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// struct FSTRUCT_AnimatedLimb             Limb                                                   (Parm, OutParm, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UCOMP_LimbManager_C::GetLimbFromBoneName(class FName BoneName, struct FSTRUCT_AnimatedLimb* Limb)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("COMP_LimbManager_C", "GetLimbFromBoneName");

	Params::COMP_LimbManager_C_GetLimbFromBoneName Parms{};

	Parms.BoneName = BoneName;

	UObject::ProcessEvent(Func, &Parms);

	if (Limb != nullptr)
		*Limb = std::move(Parms.Limb);
}


// Function COMP_LimbManager.COMP_LimbManager_C.GetLimbDamageBonusFromBoneName
// (Public, HasOutParams, HasDefaults, BlueprintCallable, BlueprintEvent, BlueprintPure)
// Parameters:
// class FName                             BoneName                                               (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// struct FVector                          ImpactLocation                                         (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// float                                   BonusPercent                                           (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UCOMP_LimbManager_C::GetLimbDamageBonusFromBoneName(class FName BoneName, const struct FVector& ImpactLocation, float* BonusPercent)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("COMP_LimbManager_C", "GetLimbDamageBonusFromBoneName");

	Params::COMP_LimbManager_C_GetLimbDamageBonusFromBoneName Parms{};

	Parms.BoneName = BoneName;
	Parms.ImpactLocation = std::move(ImpactLocation);

	UObject::ProcessEvent(Func, &Parms);

	if (BonusPercent != nullptr)
		*BonusPercent = Parms.BonusPercent;
}


// Function COMP_LimbManager.COMP_LimbManager_C.GetOwnerPawn
// (Private, HasOutParams, BlueprintCallable, BlueprintEvent, BlueprintPure)
// Parameters:
// class APAWN_Enemy_C*                    Pawn                                                   (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UCOMP_LimbManager_C::GetOwnerPawn(class APAWN_Enemy_C** Pawn)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("COMP_LimbManager_C", "GetOwnerPawn");

	Params::COMP_LimbManager_C_GetOwnerPawn Parms{};

	UObject::ProcessEvent(Func, &Parms);

	if (Pawn != nullptr)
		*Pawn = Parms.Pawn;
}


// Function COMP_LimbManager.COMP_LimbManager_C.ReceiveDamage
// (Public, HasDefaults, BlueprintCallable, BlueprintEvent)
// Parameters:
// class UOBJ_ImpactData_C*                ImpactData                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// struct FAttribDamageInstance            DamageInstance                                         (BlueprintVisible, BlueprintReadOnly, Parm)

void UCOMP_LimbManager_C::ReceiveDamage(class UOBJ_ImpactData_C* ImpactData, const struct FAttribDamageInstance& DamageInstance)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("COMP_LimbManager_C", "ReceiveDamage");

	Params::COMP_LimbManager_C_ReceiveDamage Parms{};

	Parms.ImpactData = ImpactData;
	Parms.DamageInstance = std::move(DamageInstance);

	UObject::ProcessEvent(Func, &Parms);
}


// Function COMP_LimbManager.COMP_LimbManager_C.ReceiveImpulseWhileAlive
// (Private, HasDefaults, BlueprintCallable, BlueprintEvent)
// Parameters:
// class UOBJ_ImpactData_C*                ImpactData                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// struct FAttribDamageInstance            DamageInstance                                         (BlueprintVisible, BlueprintReadOnly, Parm)

void UCOMP_LimbManager_C::ReceiveImpulseWhileAlive(class UOBJ_ImpactData_C* ImpactData, const struct FAttribDamageInstance& DamageInstance)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("COMP_LimbManager_C", "ReceiveImpulseWhileAlive");

	Params::COMP_LimbManager_C_ReceiveImpulseWhileAlive Parms{};

	Parms.ImpactData = ImpactData;
	Parms.DamageInstance = std::move(DamageInstance);

	UObject::ProcessEvent(Func, &Parms);
}


// Function COMP_LimbManager.COMP_LimbManager_C.ReceiveImpulseWhileDead
// (Private, BlueprintCallable, BlueprintEvent)
// Parameters:
// class UOBJ_ImpactData_C*                ImpactData                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// struct FAttribDamageInstance            DamageInstance                                         (BlueprintVisible, BlueprintReadOnly, Parm)

void UCOMP_LimbManager_C::ReceiveImpulseWhileDead(class UOBJ_ImpactData_C* ImpactData, const struct FAttribDamageInstance& DamageInstance)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("COMP_LimbManager_C", "ReceiveImpulseWhileDead");

	Params::COMP_LimbManager_C_ReceiveImpulseWhileDead Parms{};

	Parms.ImpactData = ImpactData;
	Parms.DamageInstance = std::move(DamageInstance);

	UObject::ProcessEvent(Func, &Parms);
}


// Function COMP_LimbManager.COMP_LimbManager_C.ReceiveImpulseWhileDying
// (Private, BlueprintCallable, BlueprintEvent)
// Parameters:
// class UOBJ_ImpactData_C*                ImpactData                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// struct FAttribDamageInstance            DamageIntance                                          (BlueprintVisible, BlueprintReadOnly, Parm)

void UCOMP_LimbManager_C::ReceiveImpulseWhileDying(class UOBJ_ImpactData_C* ImpactData, const struct FAttribDamageInstance& DamageIntance)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("COMP_LimbManager_C", "ReceiveImpulseWhileDying");

	Params::COMP_LimbManager_C_ReceiveImpulseWhileDying Parms{};

	Parms.ImpactData = ImpactData;
	Parms.DamageIntance = std::move(DamageIntance);

	UObject::ProcessEvent(Func, &Parms);
}


// Function COMP_LimbManager.COMP_LimbManager_C.GetLimbMesh
// (Private, HasOutParams, BlueprintCallable, BlueprintEvent, BlueprintPure)
// Parameters:
// class USkeletalMeshComponent*           Mesh                                                   (Parm, OutParm, ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UCOMP_LimbManager_C::GetLimbMesh(class USkeletalMeshComponent** Mesh)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("COMP_LimbManager_C", "GetLimbMesh");

	Params::COMP_LimbManager_C_GetLimbMesh Parms{};

	UObject::ProcessEvent(Func, &Parms);

	if (Mesh != nullptr)
		*Mesh = Parms.Mesh;
}


// Function COMP_LimbManager.COMP_LimbManager_C.StartDeathRattleTransition
// (Public, HasDefaults, BlueprintCallable, BlueprintEvent)
// Parameters:
// class UOBJ_ImpactData_C*                ImpactData                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UCOMP_LimbManager_C::StartDeathRattleTransition(class UOBJ_ImpactData_C* ImpactData)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("COMP_LimbManager_C", "StartDeathRattleTransition");

	Params::COMP_LimbManager_C_StartDeathRattleTransition Parms{};

	Parms.ImpactData = ImpactData;

	UObject::ProcessEvent(Func, &Parms);
}


// Function COMP_LimbManager.COMP_LimbManager_C.SetRagdollEnabled
// (Public, BlueprintCallable, BlueprintEvent)

void UCOMP_LimbManager_C::SetRagdollEnabled()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("COMP_LimbManager_C", "SetRagdollEnabled");

	UObject::ProcessEvent(Func, nullptr);
}


// Function COMP_LimbManager.COMP_LimbManager_C.OnEndDeathRattleTransition
// (Public, BlueprintCallable, BlueprintEvent)

void UCOMP_LimbManager_C::OnEndDeathRattleTransition()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("COMP_LimbManager_C", "OnEndDeathRattleTransition");

	UObject::ProcessEvent(Func, nullptr);
}


// Function COMP_LimbManager.COMP_LimbManager_C.UpdateDeathRattle
// (Private, BlueprintCallable, BlueprintEvent)

void UCOMP_LimbManager_C::UpdateDeathRattle()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("COMP_LimbManager_C", "UpdateDeathRattle");

	UObject::ProcessEvent(Func, nullptr);
}


// Function COMP_LimbManager.COMP_LimbManager_C.ApplyDeathBlow
// (Public, BlueprintCallable, BlueprintEvent)
// Parameters:
// class UOBJ_ImpactData_C*                ImpactData                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// struct FSTRUCT_DeathBlowData            DeathBlow                                              (BlueprintVisible, BlueprintReadOnly, Parm, HasGetValueTypeHash)

void UCOMP_LimbManager_C::ApplyDeathBlow(class UOBJ_ImpactData_C* ImpactData, const struct FSTRUCT_DeathBlowData& DeathBlow)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("COMP_LimbManager_C", "ApplyDeathBlow");

	Params::COMP_LimbManager_C_ApplyDeathBlow Parms{};

	Parms.ImpactData = ImpactData;
	Parms.DeathBlow = std::move(DeathBlow);

	UObject::ProcessEvent(Func, &Parms);
}


// Function COMP_LimbManager.COMP_LimbManager_C.EVENT_OnDeathBlowFinished
// (Public, BlueprintCallable, BlueprintEvent)

void UCOMP_LimbManager_C::EVENT_OnDeathBlowFinished()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("COMP_LimbManager_C", "EVENT_OnDeathBlowFinished");

	UObject::ProcessEvent(Func, nullptr);
}


// Function COMP_LimbManager.COMP_LimbManager_C.CanBecomeLowFi
// (Public, HasOutParams, BlueprintCallable, BlueprintEvent, BlueprintPure)
// Parameters:
// bool                                    Result                                                 (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor)

void UCOMP_LimbManager_C::CanBecomeLowFi(bool* Result)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("COMP_LimbManager_C", "CanBecomeLowFi");

	Params::COMP_LimbManager_C_CanBecomeLowFi Parms{};

	UObject::ProcessEvent(Func, &Parms);

	if (Result != nullptr)
		*Result = Parms.Result;
}


// Function COMP_LimbManager.COMP_LimbManager_C.UpdateRagdollSettle
// (Public, BlueprintCallable, BlueprintEvent)

void UCOMP_LimbManager_C::UpdateRagdollSettle()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("COMP_LimbManager_C", "UpdateRagdollSettle");

	UObject::ProcessEvent(Func, nullptr);
}


// Function COMP_LimbManager.COMP_LimbManager_C.GetLimbArmorBonusFromBoneName
// (Public, HasOutParams, HasDefaults, BlueprintCallable, BlueprintEvent, BlueprintPure)
// Parameters:
// class FName                             BoneName                                               (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// struct FVector                          ImpactLocation                                         (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// float                                   BonusPercent                                           (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UCOMP_LimbManager_C::GetLimbArmorBonusFromBoneName(class FName BoneName, const struct FVector& ImpactLocation, float* BonusPercent)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("COMP_LimbManager_C", "GetLimbArmorBonusFromBoneName");

	Params::COMP_LimbManager_C_GetLimbArmorBonusFromBoneName Parms{};

	Parms.BoneName = BoneName;
	Parms.ImpactLocation = std::move(ImpactLocation);

	UObject::ProcessEvent(Func, &Parms);

	if (BonusPercent != nullptr)
		*BonusPercent = Parms.BonusPercent;
}


// Function COMP_LimbManager.COMP_LimbManager_C.UpdateDamageImpulse
// (Public, BlueprintCallable, BlueprintEvent)

void UCOMP_LimbManager_C::UpdateDamageImpulse()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("COMP_LimbManager_C", "UpdateDamageImpulse");

	UObject::ProcessEvent(Func, nullptr);
}


// Function COMP_LimbManager.COMP_LimbManager_C.InitHitReactPhysicsAsset
// (Public, BlueprintCallable, BlueprintEvent)

void UCOMP_LimbManager_C::InitHitReactPhysicsAsset()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("COMP_LimbManager_C", "InitHitReactPhysicsAsset");

	UObject::ProcessEvent(Func, nullptr);
}


// Function COMP_LimbManager.COMP_LimbManager_C.GetLimbDamageBonusFromEpicenter
// (Public, HasOutParams, HasDefaults, BlueprintCallable, BlueprintEvent, BlueprintPure)
// Parameters:
// struct FVector                          Location                                               (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// float                                   Radius                                                 (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// float                                   Result                                                 (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UCOMP_LimbManager_C::GetLimbDamageBonusFromEpicenter(const struct FVector& Location, float Radius, float* Result)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("COMP_LimbManager_C", "GetLimbDamageBonusFromEpicenter");

	Params::COMP_LimbManager_C_GetLimbDamageBonusFromEpicenter Parms{};

	Parms.Location = std::move(Location);
	Parms.Radius = Radius;

	UObject::ProcessEvent(Func, &Parms);

	if (Result != nullptr)
		*Result = Parms.Result;
}


// Function COMP_LimbManager.COMP_LimbManager_C.GetLimbDamageAndArmorBonusFromBoneName
// (Public, HasOutParams, HasDefaults, BlueprintCallable, BlueprintEvent)
// Parameters:
// class FName                             BoneName                                               (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// struct FVector                          ImpactLocation                                         (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// float                                   DamageBonusPercent                                     (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// float                                   ArmorBonusPercent                                      (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UCOMP_LimbManager_C::GetLimbDamageAndArmorBonusFromBoneName(class FName BoneName, const struct FVector& ImpactLocation, float* DamageBonusPercent, float* ArmorBonusPercent)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("COMP_LimbManager_C", "GetLimbDamageAndArmorBonusFromBoneName");

	Params::COMP_LimbManager_C_GetLimbDamageAndArmorBonusFromBoneName Parms{};

	Parms.BoneName = BoneName;
	Parms.ImpactLocation = std::move(ImpactLocation);

	UObject::ProcessEvent(Func, &Parms);

	if (DamageBonusPercent != nullptr)
		*DamageBonusPercent = Parms.DamageBonusPercent;

	if (ArmorBonusPercent != nullptr)
		*ArmorBonusPercent = Parms.ArmorBonusPercent;
}


// Function COMP_LimbManager.COMP_LimbManager_C.EVENT_StartDeferredDeathRattleTransition
// (Private, BlueprintCallable, BlueprintEvent)

void UCOMP_LimbManager_C::EVENT_StartDeferredDeathRattleTransition()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("COMP_LimbManager_C", "EVENT_StartDeferredDeathRattleTransition");

	UObject::ProcessEvent(Func, nullptr);
}


// Function COMP_LimbManager.COMP_LimbManager_C.ShouldSaveComponent
// (Event, Public, HasOutParams, HasDefaults, BlueprintCallable, BlueprintEvent)
// Parameters:
// struct FStreamingSaveGameComponentParamsParams_0                                               (Parm, OutParm, NoDestructor)
// bool                                    ReturnValue                                            (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData, NoDestructor)

bool UCOMP_LimbManager_C::ShouldSaveComponent(struct FStreamingSaveGameComponentParams* Params_0)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("COMP_LimbManager_C", "ShouldSaveComponent");

	Params::COMP_LimbManager_C_ShouldSaveComponent Parms{};

	UObject::ProcessEvent(Func, &Parms);

	if (Params_0 != nullptr)
		*Params_0 = std::move(Parms.Params_0);

	return Parms.ReturnValue;
}

}

