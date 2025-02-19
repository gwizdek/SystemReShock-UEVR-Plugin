#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: INTERACT_RobotRechargeStation

#include "Basic.hpp"

#include "INTERACT_RobotRechargeStation_classes.hpp"
#include "INTERACT_RobotRechargeStation_parameters.hpp"


namespace SDK
{

// Function INTERACT_RobotRechargeStation.INTERACT_RobotRechargeStation_C.ExecuteUbergraph_INTERACT_RobotRechargeStation
// (Final, UbergraphFunction)
// Parameters:
// int32                                   EntryPoint                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void AINTERACT_RobotRechargeStation_C::ExecuteUbergraph_INTERACT_RobotRechargeStation(int32 EntryPoint)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("INTERACT_RobotRechargeStation_C", "ExecuteUbergraph_INTERACT_RobotRechargeStation");

	Params::INTERACT_RobotRechargeStation_C_ExecuteUbergraph_INTERACT_RobotRechargeStation Parms{};

	Parms.EntryPoint = EntryPoint;

	UObject::ProcessEvent(Func, &Parms);
}


// Function INTERACT_RobotRechargeStation.INTERACT_RobotRechargeStation_C.BndEvt__INTERACT_RobotRechargeStation_COMP_VoxelCullable_K2Node_ComponentBoundEvent_1_CullableAudibilitySignature__DelegateSignature
// (BlueprintEvent)
// Parameters:
// bool                                    bAudibleState                                          (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor)

void AINTERACT_RobotRechargeStation_C::BndEvt__INTERACT_RobotRechargeStation_COMP_VoxelCullable_K2Node_ComponentBoundEvent_1_CullableAudibilitySignature__DelegateSignature(bool bAudibleState)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("INTERACT_RobotRechargeStation_C", "BndEvt__INTERACT_RobotRechargeStation_COMP_VoxelCullable_K2Node_ComponentBoundEvent_1_CullableAudibilitySignature__DelegateSignature");

	Params::INTERACT_RobotRechargeStation_C_BndEvt__INTERACT_RobotRechargeStation_COMP_VoxelCullable_K2Node_ComponentBoundEvent_1_CullableAudibilitySignature__DelegateSignature Parms{};

	Parms.bAudibleState = bAudibleState;

	UObject::ProcessEvent(Func, &Parms);
}


// Function INTERACT_RobotRechargeStation.INTERACT_RobotRechargeStation_C.BndEvt__COMP_VoxelCullable_K2Node_ComponentBoundEvent_0_CullableVisibilitySignature__DelegateSignature
// (BlueprintEvent)
// Parameters:
// bool                                    bVisibleState                                          (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor)

void AINTERACT_RobotRechargeStation_C::BndEvt__COMP_VoxelCullable_K2Node_ComponentBoundEvent_0_CullableVisibilitySignature__DelegateSignature(bool bVisibleState)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("INTERACT_RobotRechargeStation_C", "BndEvt__COMP_VoxelCullable_K2Node_ComponentBoundEvent_0_CullableVisibilitySignature__DelegateSignature");

	Params::INTERACT_RobotRechargeStation_C_BndEvt__COMP_VoxelCullable_K2Node_ComponentBoundEvent_0_CullableVisibilitySignature__DelegateSignature Parms{};

	Parms.bVisibleState = bVisibleState;

	UObject::ProcessEvent(Func, &Parms);
}


// Function INTERACT_RobotRechargeStation.INTERACT_RobotRechargeStation_C.ReceiveBeginPlay
// (Event, Protected, BlueprintEvent)

void AINTERACT_RobotRechargeStation_C::ReceiveBeginPlay()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("INTERACT_RobotRechargeStation_C", "ReceiveBeginPlay");

	UObject::ProcessEvent(Func, nullptr);
}


// Function INTERACT_RobotRechargeStation.INTERACT_RobotRechargeStation_C.UserConstructionScript
// (Event, Public, BlueprintCallable, BlueprintEvent)

void AINTERACT_RobotRechargeStation_C::UserConstructionScript()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("INTERACT_RobotRechargeStation_C", "UserConstructionScript");

	UObject::ProcessEvent(Func, nullptr);
}


// Function INTERACT_RobotRechargeStation.INTERACT_RobotRechargeStation_C.TryInteract
// (Public, HasOutParams, HasDefaults, BlueprintCallable, BlueprintEvent)
// Parameters:
// class AActor*                           SourceActor                                            (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// class UPrimitiveComponent*              CursorPrimitive                                        (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// ENUM_InteractionType                    InteractionType                                        (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// struct FSTRUCT_InteractResults          InteractResults                                        (Parm, OutParm, HasGetValueTypeHash)

void AINTERACT_RobotRechargeStation_C::TryInteract(class AActor* SourceActor, class UPrimitiveComponent* CursorPrimitive, ENUM_InteractionType InteractionType, struct FSTRUCT_InteractResults* InteractResults)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("INTERACT_RobotRechargeStation_C", "TryInteract");

	Params::INTERACT_RobotRechargeStation_C_TryInteract Parms{};

	Parms.SourceActor = SourceActor;
	Parms.CursorPrimitive = CursorPrimitive;
	Parms.InteractionType = InteractionType;

	UObject::ProcessEvent(Func, &Parms);

	if (InteractResults != nullptr)
		*InteractResults = std::move(Parms.InteractResults);
}


// Function INTERACT_RobotRechargeStation.INTERACT_RobotRechargeStation_C.InitializeRechargeStation
// (Protected, BlueprintCallable, BlueprintEvent)

void AINTERACT_RobotRechargeStation_C::InitializeRechargeStation()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("INTERACT_RobotRechargeStation_C", "InitializeRechargeStation");

	UObject::ProcessEvent(Func, nullptr);
}


// Function INTERACT_RobotRechargeStation.INTERACT_RobotRechargeStation_C.InitializeAttributes
// (Protected, BlueprintCallable, BlueprintEvent)

void AINTERACT_RobotRechargeStation_C::InitializeAttributes()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("INTERACT_RobotRechargeStation_C", "InitializeAttributes");

	UObject::ProcessEvent(Func, nullptr);
}


// Function INTERACT_RobotRechargeStation.INTERACT_RobotRechargeStation_C.UpdateMeshEmissive
// (Protected, BlueprintCallable, BlueprintEvent)
// Parameters:
// float                                   Value                                                  (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void AINTERACT_RobotRechargeStation_C::UpdateMeshEmissive(float Value)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("INTERACT_RobotRechargeStation_C", "UpdateMeshEmissive");

	Params::INTERACT_RobotRechargeStation_C_UpdateMeshEmissive Parms{};

	Parms.Value = Value;

	UObject::ProcessEvent(Func, &Parms);
}


// Function INTERACT_RobotRechargeStation.INTERACT_RobotRechargeStation_C.OnEnemyStartedRecharging
// (Protected, BlueprintCallable, BlueprintEvent)

void AINTERACT_RobotRechargeStation_C::OnEnemyStartedRecharging()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("INTERACT_RobotRechargeStation_C", "OnEnemyStartedRecharging");

	UObject::ProcessEvent(Func, nullptr);
}


// Function INTERACT_RobotRechargeStation.INTERACT_RobotRechargeStation_C.TryDeactivateRechargeStation
// (Protected, HasOutParams, BlueprintCallable, BlueprintEvent)
// Parameters:
// bool                                    Result                                                 (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor)

void AINTERACT_RobotRechargeStation_C::TryDeactivateRechargeStation(bool* Result)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("INTERACT_RobotRechargeStation_C", "TryDeactivateRechargeStation");

	Params::INTERACT_RobotRechargeStation_C_TryDeactivateRechargeStation Parms{};

	UObject::ProcessEvent(Func, &Parms);

	if (Result != nullptr)
		*Result = Parms.Result;
}


// Function INTERACT_RobotRechargeStation.INTERACT_RobotRechargeStation_C.EVENT_OnRechargingEnemyDied
// (Private, BlueprintCallable, BlueprintEvent)
// Parameters:
// class APAWN_SystemShockCharacter_C*     Character                                              (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void AINTERACT_RobotRechargeStation_C::EVENT_OnRechargingEnemyDied(class APAWN_SystemShockCharacter_C* Character)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("INTERACT_RobotRechargeStation_C", "EVENT_OnRechargingEnemyDied");

	Params::INTERACT_RobotRechargeStation_C_EVENT_OnRechargingEnemyDied Parms{};

	Parms.Character = Character;

	UObject::ProcessEvent(Func, &Parms);
}


// Function INTERACT_RobotRechargeStation.INTERACT_RobotRechargeStation_C.AlertNearbyRechargeStations
// (Protected, HasDefaults, BlueprintCallable, BlueprintEvent)

void AINTERACT_RobotRechargeStation_C::AlertNearbyRechargeStations()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("INTERACT_RobotRechargeStation_C", "AlertNearbyRechargeStations");

	UObject::ProcessEvent(Func, nullptr);
}


// Function INTERACT_RobotRechargeStation.INTERACT_RobotRechargeStation_C.EVENT_OnRechargingEnemyDamaged
// (Private, BlueprintCallable, BlueprintEvent)
// Parameters:
// class AActor*                           OtherActor                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// struct FAttribDamageInstance            DamageInstance                                         (BlueprintVisible, BlueprintReadOnly, Parm)
// class UObject*                          UserParams                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void AINTERACT_RobotRechargeStation_C::EVENT_OnRechargingEnemyDamaged(class AActor* OtherActor, const struct FAttribDamageInstance& DamageInstance, class UObject* UserParams)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("INTERACT_RobotRechargeStation_C", "EVENT_OnRechargingEnemyDamaged");

	Params::INTERACT_RobotRechargeStation_C_EVENT_OnRechargingEnemyDamaged Parms{};

	Parms.OtherActor = OtherActor;
	Parms.DamageInstance = std::move(DamageInstance);
	Parms.UserParams = UserParams;

	UObject::ProcessEvent(Func, &Parms);
}


// Function INTERACT_RobotRechargeStation.INTERACT_RobotRechargeStation_C.UpdateRechargeAnimationState
// (Protected, BlueprintCallable, BlueprintEvent)
// Parameters:
// bool                                    State                                                  (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor)

void AINTERACT_RobotRechargeStation_C::UpdateRechargeAnimationState(bool State)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("INTERACT_RobotRechargeStation_C", "UpdateRechargeAnimationState");

	Params::INTERACT_RobotRechargeStation_C_UpdateRechargeAnimationState Parms{};

	Parms.State = State;

	UObject::ProcessEvent(Func, &Parms);
}


// Function INTERACT_RobotRechargeStation.INTERACT_RobotRechargeStation_C.UpdateRechargeEffects
// (Protected, HasDefaults, BlueprintCallable, BlueprintEvent)
// Parameters:
// bool                                    State                                                  (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor)

void AINTERACT_RobotRechargeStation_C::UpdateRechargeEffects(bool State)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("INTERACT_RobotRechargeStation_C", "UpdateRechargeEffects");

	Params::INTERACT_RobotRechargeStation_C_UpdateRechargeEffects Parms{};

	Parms.State = State;

	UObject::ProcessEvent(Func, &Parms);
}


// Function INTERACT_RobotRechargeStation.INTERACT_RobotRechargeStation_C.UpdateRechargeStationVisibility
// (Protected, BlueprintCallable, BlueprintEvent)
// Parameters:
// bool                                    VisibilityState                                        (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor)

void AINTERACT_RobotRechargeStation_C::UpdateRechargeStationVisibility(bool VisibilityState)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("INTERACT_RobotRechargeStation_C", "UpdateRechargeStationVisibility");

	Params::INTERACT_RobotRechargeStation_C_UpdateRechargeStationVisibility Parms{};

	Parms.VisibilityState = VisibilityState;

	UObject::ProcessEvent(Func, &Parms);
}


// Function INTERACT_RobotRechargeStation.INTERACT_RobotRechargeStation_C.UpdateRechargeStationAudibility
// (Protected, HasDefaults, BlueprintCallable, BlueprintEvent)
// Parameters:
// bool                                    AudibilityState                                        (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor)

void AINTERACT_RobotRechargeStation_C::UpdateRechargeStationAudibility(bool AudibilityState)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("INTERACT_RobotRechargeStation_C", "UpdateRechargeStationAudibility");

	Params::INTERACT_RobotRechargeStation_C_UpdateRechargeStationAudibility Parms{};

	Parms.AudibilityState = AudibilityState;

	UObject::ProcessEvent(Func, &Parms);
}


// Function INTERACT_RobotRechargeStation.INTERACT_RobotRechargeStation_C.BindRechargingEnemyEvents
// (Private, BlueprintCallable, BlueprintEvent)

void AINTERACT_RobotRechargeStation_C::BindRechargingEnemyEvents()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("INTERACT_RobotRechargeStation_C", "BindRechargingEnemyEvents");

	UObject::ProcessEvent(Func, nullptr);
}


// Function INTERACT_RobotRechargeStation.INTERACT_RobotRechargeStation_C.UnbindRechargingEnemyEvents
// (Private, BlueprintCallable, BlueprintEvent)

void AINTERACT_RobotRechargeStation_C::UnbindRechargingEnemyEvents()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("INTERACT_RobotRechargeStation_C", "UnbindRechargingEnemyEvents");

	UObject::ProcessEvent(Func, nullptr);
}


// Function INTERACT_RobotRechargeStation.INTERACT_RobotRechargeStation_C.EVENT_OnRechargeEffectSpawned
// (Private, BlueprintCallable, BlueprintEvent)
// Parameters:
// class UObject*                          Object                                                 (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void AINTERACT_RobotRechargeStation_C::EVENT_OnRechargeEffectSpawned(class UObject* Object)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("INTERACT_RobotRechargeStation_C", "EVENT_OnRechargeEffectSpawned");

	Params::INTERACT_RobotRechargeStation_C_EVENT_OnRechargeEffectSpawned Parms{};

	Parms.Object = Object;

	UObject::ProcessEvent(Func, &Parms);
}


// Function INTERACT_RobotRechargeStation.INTERACT_RobotRechargeStation_C.EVENT_OnDisableAttribChanged
// (Private, BlueprintCallable, BlueprintEvent)
// Parameters:
// float                                   CurrValue                                              (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// float                                   LastValue                                              (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void AINTERACT_RobotRechargeStation_C::EVENT_OnDisableAttribChanged(float CurrValue, float LastValue)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("INTERACT_RobotRechargeStation_C", "EVENT_OnDisableAttribChanged");

	Params::INTERACT_RobotRechargeStation_C_EVENT_OnDisableAttribChanged Parms{};

	Parms.CurrValue = CurrValue;
	Parms.LastValue = LastValue;

	UObject::ProcessEvent(Func, &Parms);
}

}

