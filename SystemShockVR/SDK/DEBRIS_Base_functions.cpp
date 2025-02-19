#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: DEBRIS_Base

#include "Basic.hpp"

#include "DEBRIS_Base_classes.hpp"
#include "DEBRIS_Base_parameters.hpp"


namespace SDK
{

// Function DEBRIS_Base.DEBRIS_Base_C.ExecuteUbergraph_DEBRIS_Base
// (Final, UbergraphFunction)
// Parameters:
// int32                                   EntryPoint                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void ADEBRIS_Base_C::ExecuteUbergraph_DEBRIS_Base(int32 EntryPoint)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("DEBRIS_Base_C", "ExecuteUbergraph_DEBRIS_Base");

	Params::DEBRIS_Base_C_ExecuteUbergraph_DEBRIS_Base Parms{};

	Parms.EntryPoint = EntryPoint;

	UObject::ProcessEvent(Func, &Parms);
}


// Function DEBRIS_Base.DEBRIS_Base_C.BndEvt__DEBRIS_Base_COMP_CullableNavModifier_K2Node_ComponentBoundEvent_1_CullableVisibilitySignature__DelegateSignature
// (BlueprintEvent)
// Parameters:
// bool                                    bVisibleState                                          (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor)

void ADEBRIS_Base_C::BndEvt__DEBRIS_Base_COMP_CullableNavModifier_K2Node_ComponentBoundEvent_1_CullableVisibilitySignature__DelegateSignature(bool bVisibleState)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("DEBRIS_Base_C", "BndEvt__DEBRIS_Base_COMP_CullableNavModifier_K2Node_ComponentBoundEvent_1_CullableVisibilitySignature__DelegateSignature");

	Params::DEBRIS_Base_C_BndEvt__DEBRIS_Base_COMP_CullableNavModifier_K2Node_ComponentBoundEvent_1_CullableVisibilitySignature__DelegateSignature Parms{};

	Parms.bVisibleState = bVisibleState;

	UObject::ProcessEvent(Func, &Parms);
}


// Function DEBRIS_Base.DEBRIS_Base_C.ReceiveBeginPlay
// (Event, Protected, BlueprintEvent)

void ADEBRIS_Base_C::ReceiveBeginPlay()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("DEBRIS_Base_C", "ReceiveBeginPlay");

	UObject::ProcessEvent(Func, nullptr);
}


// Function DEBRIS_Base.DEBRIS_Base_C.IsTeleporting
// (Public, HasOutParams, BlueprintCallable, BlueprintEvent, BlueprintPure)
// Parameters:
// bool                                    Result                                                 (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor)

void ADEBRIS_Base_C::IsTeleporting(bool* Result)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("DEBRIS_Base_C", "IsTeleporting");

	Params::DEBRIS_Base_C_IsTeleporting Parms{};

	UObject::ProcessEvent(Func, &Parms);

	if (Result != nullptr)
		*Result = Parms.Result;
}


// Function DEBRIS_Base.DEBRIS_Base_C.CanTeleportDebris
// (Public, HasOutParams, BlueprintCallable, BlueprintEvent, BlueprintPure)
// Parameters:
// bool                                    Result                                                 (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor)

void ADEBRIS_Base_C::CanTeleportDebris(bool* Result)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("DEBRIS_Base_C", "CanTeleportDebris");

	Params::DEBRIS_Base_C_CanTeleportDebris Parms{};

	UObject::ProcessEvent(Func, &Parms);

	if (Result != nullptr)
		*Result = Parms.Result;
}


// Function DEBRIS_Base.DEBRIS_Base_C.UpdateDebrisVisibility
// (Public, BlueprintCallable, BlueprintEvent)
// Parameters:
// bool                                    VisibilityState                                        (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor)

void ADEBRIS_Base_C::UpdateDebrisVisibility(bool VisibilityState)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("DEBRIS_Base_C", "UpdateDebrisVisibility");

	Params::DEBRIS_Base_C_UpdateDebrisVisibility Parms{};

	Parms.VisibilityState = VisibilityState;

	UObject::ProcessEvent(Func, &Parms);
}


// Function DEBRIS_Base.DEBRIS_Base_C.TryTeleportDebris
// (Public, HasOutParams, HasDefaults, BlueprintCallable, BlueprintEvent)
// Parameters:
// struct FVector                          Location                                               (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// struct FRotator                         Rotation                                               (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor)
// float                                   MaterializeDuration                                    (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// class USoundCue*                        SoundCue                                               (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// class UNiagaraSystem*                   TeleportFX                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// bool                                    Result                                                 (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor)

void ADEBRIS_Base_C::TryTeleportDebris(const struct FVector& Location, const struct FRotator& Rotation, float MaterializeDuration, class USoundCue* SoundCue, class UNiagaraSystem* TeleportFX, bool* Result)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("DEBRIS_Base_C", "TryTeleportDebris");

	Params::DEBRIS_Base_C_TryTeleportDebris Parms{};

	Parms.Location = std::move(Location);
	Parms.Rotation = std::move(Rotation);
	Parms.MaterializeDuration = MaterializeDuration;
	Parms.SoundCue = SoundCue;
	Parms.TeleportFX = TeleportFX;

	UObject::ProcessEvent(Func, &Parms);

	if (Result != nullptr)
		*Result = Parms.Result;
}


// Function DEBRIS_Base.DEBRIS_Base_C.EVENT_OnFinishedMaterializingFromTeleport
// (Private, BlueprintCallable, BlueprintEvent)

void ADEBRIS_Base_C::EVENT_OnFinishedMaterializingFromTeleport()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("DEBRIS_Base_C", "EVENT_OnFinishedMaterializingFromTeleport");

	UObject::ProcessEvent(Func, nullptr);
}


// Function DEBRIS_Base.DEBRIS_Base_C.IgnorePhysicsBodyCollisionTemporarily
// (Public, HasDefaults, BlueprintCallable, BlueprintEvent)
// Parameters:
// float                                   Duration                                               (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void ADEBRIS_Base_C::IgnorePhysicsBodyCollisionTemporarily(float Duration)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("DEBRIS_Base_C", "IgnorePhysicsBodyCollisionTemporarily");

	Params::DEBRIS_Base_C_IgnorePhysicsBodyCollisionTemporarily Parms{};

	Parms.Duration = Duration;

	UObject::ProcessEvent(Func, &Parms);
}


// Function DEBRIS_Base.DEBRIS_Base_C.GetDebrisMeshComponent
// (Public, HasOutParams, BlueprintCallable, BlueprintEvent, BlueprintPure)
// Parameters:
// class UStaticMeshComponent*             Result                                                 (Parm, OutParm, ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void ADEBRIS_Base_C::GetDebrisMeshComponent(class UStaticMeshComponent** Result)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("DEBRIS_Base_C", "GetDebrisMeshComponent");

	Params::DEBRIS_Base_C_GetDebrisMeshComponent Parms{};

	UObject::ProcessEvent(Func, &Parms);

	if (Result != nullptr)
		*Result = Parms.Result;
}


// Function DEBRIS_Base.DEBRIS_Base_C.EVENT_EndIgnoreCollision
// (Private, BlueprintCallable, BlueprintEvent)

void ADEBRIS_Base_C::EVENT_EndIgnoreCollision()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("DEBRIS_Base_C", "EVENT_EndIgnoreCollision");

	UObject::ProcessEvent(Func, nullptr);
}


// Function DEBRIS_Base.DEBRIS_Base_C.ShouldSaveActor
// (Event, Public, HasOutParams, HasDefaults, BlueprintCallable, BlueprintEvent)
// Parameters:
// struct FStreamingSaveGameActorParams    Params_0                                               (Parm, OutParm)
// bool                                    ReturnValue                                            (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData, NoDestructor)

bool ADEBRIS_Base_C::ShouldSaveActor(struct FStreamingSaveGameActorParams* Params_0)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("DEBRIS_Base_C", "ShouldSaveActor");

	Params::DEBRIS_Base_C_ShouldSaveActor Parms{};

	UObject::ProcessEvent(Func, &Parms);

	if (Params_0 != nullptr)
		*Params_0 = std::move(Parms.Params_0);

	return Parms.ReturnValue;
}


// Function DEBRIS_Base.DEBRIS_Base_C.ReceivePendingBodyTransforms
// (Event, Public, HasOutParams, BlueprintCallable, BlueprintEvent)
// Parameters:
// class USkeletalMeshComponent*           SkeletalMeshComponent                                  (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// TArray<struct FTransform>               BodyTransforms                                         (ConstParm, BlueprintVisible, BlueprintReadOnly, Parm, OutParm, ReferenceParm)
// bool                                    ReturnValue                                            (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData, NoDestructor)

bool ADEBRIS_Base_C::ReceivePendingBodyTransforms(class USkeletalMeshComponent* SkeletalMeshComponent, const TArray<struct FTransform>& BodyTransforms)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("DEBRIS_Base_C", "ReceivePendingBodyTransforms");

	Params::DEBRIS_Base_C_ReceivePendingBodyTransforms Parms{};

	Parms.SkeletalMeshComponent = SkeletalMeshComponent;
	Parms.BodyTransforms = std::move(BodyTransforms);

	UObject::ProcessEvent(Func, &Parms);

	return Parms.ReturnValue;
}


// Function DEBRIS_Base.DEBRIS_Base_C.ReceivePendingCharacterVelocity
// (Event, Public, HasOutParams, BlueprintCallable, BlueprintEvent)
// Parameters:
// struct FVector                          Velocity                                               (ConstParm, BlueprintVisible, BlueprintReadOnly, Parm, OutParm, ZeroConstructor, ReferenceParm, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// bool                                    ReturnValue                                            (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData, NoDestructor)

bool ADEBRIS_Base_C::ReceivePendingCharacterVelocity(const struct FVector& Velocity)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("DEBRIS_Base_C", "ReceivePendingCharacterVelocity");

	Params::DEBRIS_Base_C_ReceivePendingCharacterVelocity Parms{};

	Parms.Velocity = std::move(Velocity);

	UObject::ProcessEvent(Func, &Parms);

	return Parms.ReturnValue;
}

}

