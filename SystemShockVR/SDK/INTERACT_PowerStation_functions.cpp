#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: INTERACT_PowerStation

#include "Basic.hpp"

#include "INTERACT_PowerStation_classes.hpp"
#include "INTERACT_PowerStation_parameters.hpp"


namespace SDK
{

// Function INTERACT_PowerStation.INTERACT_PowerStation_C.ExecuteUbergraph_INTERACT_PowerStation
// (Final, UbergraphFunction)
// Parameters:
// int32                                   EntryPoint                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void AINTERACT_PowerStation_C::ExecuteUbergraph_INTERACT_PowerStation(int32 EntryPoint)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("INTERACT_PowerStation_C", "ExecuteUbergraph_INTERACT_PowerStation");

	Params::INTERACT_PowerStation_C_ExecuteUbergraph_INTERACT_PowerStation Parms{};

	Parms.EntryPoint = EntryPoint;

	UObject::ProcessEvent(Func, &Parms);
}


// Function INTERACT_PowerStation.INTERACT_PowerStation_C.BndEvt__INTERACT_PowerStation_COMP_VoxelCullable_K2Node_ComponentBoundEvent_1_CullableAudibilitySignature__DelegateSignature
// (BlueprintEvent)
// Parameters:
// bool                                    bAudibleState                                          (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor)

void AINTERACT_PowerStation_C::BndEvt__INTERACT_PowerStation_COMP_VoxelCullable_K2Node_ComponentBoundEvent_1_CullableAudibilitySignature__DelegateSignature(bool bAudibleState)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("INTERACT_PowerStation_C", "BndEvt__INTERACT_PowerStation_COMP_VoxelCullable_K2Node_ComponentBoundEvent_1_CullableAudibilitySignature__DelegateSignature");

	Params::INTERACT_PowerStation_C_BndEvt__INTERACT_PowerStation_COMP_VoxelCullable_K2Node_ComponentBoundEvent_1_CullableAudibilitySignature__DelegateSignature Parms{};

	Parms.bAudibleState = bAudibleState;

	UObject::ProcessEvent(Func, &Parms);
}


// Function INTERACT_PowerStation.INTERACT_PowerStation_C.BndEvt__INTERACT_PowerStation_COMP_VoxelCullable_K2Node_ComponentBoundEvent_0_CullableVisibilitySignature__DelegateSignature
// (BlueprintEvent)
// Parameters:
// bool                                    bVisibleState                                          (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor)

void AINTERACT_PowerStation_C::BndEvt__INTERACT_PowerStation_COMP_VoxelCullable_K2Node_ComponentBoundEvent_0_CullableVisibilitySignature__DelegateSignature(bool bVisibleState)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("INTERACT_PowerStation_C", "BndEvt__INTERACT_PowerStation_COMP_VoxelCullable_K2Node_ComponentBoundEvent_0_CullableVisibilitySignature__DelegateSignature");

	Params::INTERACT_PowerStation_C_BndEvt__INTERACT_PowerStation_COMP_VoxelCullable_K2Node_ComponentBoundEvent_0_CullableVisibilitySignature__DelegateSignature Parms{};

	Parms.bVisibleState = bVisibleState;

	UObject::ProcessEvent(Func, &Parms);
}


// Function INTERACT_PowerStation.INTERACT_PowerStation_C.ReceiveBeginPlay
// (Event, Protected, BlueprintEvent)

void AINTERACT_PowerStation_C::ReceiveBeginPlay()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("INTERACT_PowerStation_C", "ReceiveBeginPlay");

	UObject::ProcessEvent(Func, nullptr);
}


// Function INTERACT_PowerStation.INTERACT_PowerStation_C.UserConstructionScript
// (Event, Public, BlueprintCallable, BlueprintEvent)

void AINTERACT_PowerStation_C::UserConstructionScript()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("INTERACT_PowerStation_C", "UserConstructionScript");

	UObject::ProcessEvent(Func, nullptr);
}


// Function INTERACT_PowerStation.INTERACT_PowerStation_C.GetTargetShape
// (Public, HasOutParams, BlueprintCallable, BlueprintEvent)
// Parameters:
// class UPrimitiveComponent*              CursorPrimitive                                        (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// class UShapeComponent*                  ShapeComponent                                         (Parm, OutParm, ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void AINTERACT_PowerStation_C::GetTargetShape(class UPrimitiveComponent* CursorPrimitive, class UShapeComponent** ShapeComponent)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("INTERACT_PowerStation_C", "GetTargetShape");

	Params::INTERACT_PowerStation_C_GetTargetShape Parms{};

	Parms.CursorPrimitive = CursorPrimitive;

	UObject::ProcessEvent(Func, &Parms);

	if (ShapeComponent != nullptr)
		*ShapeComponent = Parms.ShapeComponent;
}


// Function INTERACT_PowerStation.INTERACT_PowerStation_C.TryInteract
// (Public, HasOutParams, HasDefaults, BlueprintCallable, BlueprintEvent)
// Parameters:
// class AActor*                           SourceActor                                            (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// class UPrimitiveComponent*              CursorPrimitive                                        (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// ENUM_InteractionType                    InteractionType                                        (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// struct FSTRUCT_InteractResults          InteractResults                                        (Parm, OutParm, HasGetValueTypeHash)

void AINTERACT_PowerStation_C::TryInteract(class AActor* SourceActor, class UPrimitiveComponent* CursorPrimitive, ENUM_InteractionType InteractionType, struct FSTRUCT_InteractResults* InteractResults)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("INTERACT_PowerStation_C", "TryInteract");

	Params::INTERACT_PowerStation_C_TryInteract Parms{};

	Parms.SourceActor = SourceActor;
	Parms.CursorPrimitive = CursorPrimitive;
	Parms.InteractionType = InteractionType;

	UObject::ProcessEvent(Func, &Parms);

	if (InteractResults != nullptr)
		*InteractResults = std::move(Parms.InteractResults);
}


// Function INTERACT_PowerStation.INTERACT_PowerStation_C.EVENT_PowerDownTick
// (Private, BlueprintCallable, BlueprintEvent)

void AINTERACT_PowerStation_C::EVENT_PowerDownTick()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("INTERACT_PowerStation_C", "EVENT_PowerDownTick");

	UObject::ProcessEvent(Func, nullptr);
}


// Function INTERACT_PowerStation.INTERACT_PowerStation_C.EVENT_OnRechargeStageFinished
// (Protected, HasDefaults, BlueprintCallable, BlueprintEvent)

void AINTERACT_PowerStation_C::EVENT_OnRechargeStageFinished()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("INTERACT_PowerStation_C", "EVENT_OnRechargeStageFinished");

	UObject::ProcessEvent(Func, nullptr);
}


// Function INTERACT_PowerStation.INTERACT_PowerStation_C.EVENT_SecurityLevelChanged
// (Protected, BlueprintCallable, BlueprintEvent)
// Parameters:
// int32                                   NewSecurityLevel                                       (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void AINTERACT_PowerStation_C::EVENT_SecurityLevelChanged(int32 NewSecurityLevel)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("INTERACT_PowerStation_C", "EVENT_SecurityLevelChanged");

	Params::INTERACT_PowerStation_C_EVENT_SecurityLevelChanged Parms{};

	Parms.NewSecurityLevel = NewSecurityLevel;

	UObject::ProcessEvent(Func, &Parms);
}


// Function INTERACT_PowerStation.INTERACT_PowerStation_C.InitializePowerStation
// (Protected, HasDefaults, BlueprintCallable, BlueprintEvent)

void AINTERACT_PowerStation_C::InitializePowerStation()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("INTERACT_PowerStation_C", "InitializePowerStation");

	UObject::ProcessEvent(Func, nullptr);
}


// Function INTERACT_PowerStation.INTERACT_PowerStation_C.EVENT_OnBeginDischarging
// (Protected, HasDefaults, BlueprintCallable, BlueprintEvent)

void AINTERACT_PowerStation_C::EVENT_OnBeginDischarging()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("INTERACT_PowerStation_C", "EVENT_OnBeginDischarging");

	UObject::ProcessEvent(Func, nullptr);
}


// Function INTERACT_PowerStation.INTERACT_PowerStation_C.InitializeAttributes
// (Protected, BlueprintCallable, BlueprintEvent)

void AINTERACT_PowerStation_C::InitializeAttributes()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("INTERACT_PowerStation_C", "InitializeAttributes");

	UObject::ProcessEvent(Func, nullptr);
}


// Function INTERACT_PowerStation.INTERACT_PowerStation_C.UpdateMeshEmissiveStrength
// (Protected, BlueprintCallable, BlueprintEvent)
// Parameters:
// float                                   Value                                                  (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void AINTERACT_PowerStation_C::UpdateMeshEmissiveStrength(float Value)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("INTERACT_PowerStation_C", "UpdateMeshEmissiveStrength");

	Params::INTERACT_PowerStation_C_UpdateMeshEmissiveStrength Parms{};

	Parms.Value = Value;

	UObject::ProcessEvent(Func, &Parms);
}


// Function INTERACT_PowerStation.INTERACT_PowerStation_C.TryCompleteGameEvents
// (Protected, HasDefaults, BlueprintCallable, BlueprintEvent)

void AINTERACT_PowerStation_C::TryCompleteGameEvents()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("INTERACT_PowerStation_C", "TryCompleteGameEvents");

	UObject::ProcessEvent(Func, nullptr);
}


// Function INTERACT_PowerStation.INTERACT_PowerStation_C.TryBeginActivatingPowerStation
// (Protected, HasDefaults, BlueprintCallable, BlueprintEvent)

void AINTERACT_PowerStation_C::TryBeginActivatingPowerStation()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("INTERACT_PowerStation_C", "TryBeginActivatingPowerStation");

	UObject::ProcessEvent(Func, nullptr);
}


// Function INTERACT_PowerStation.INTERACT_PowerStation_C.ApplyPowerStationActivationMods
// (Private, BlueprintCallable, BlueprintEvent)

void AINTERACT_PowerStation_C::ApplyPowerStationActivationMods()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("INTERACT_PowerStation_C", "ApplyPowerStationActivationMods");

	UObject::ProcessEvent(Func, nullptr);
}


// Function INTERACT_PowerStation.INTERACT_PowerStation_C.UpdateRechargeAnimationState
// (Protected, BlueprintCallable, BlueprintEvent)

void AINTERACT_PowerStation_C::UpdateRechargeAnimationState()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("INTERACT_PowerStation_C", "UpdateRechargeAnimationState");

	UObject::ProcessEvent(Func, nullptr);
}


// Function INTERACT_PowerStation.INTERACT_PowerStation_C.UpdateLightIntensity
// (Public, BlueprintCallable, BlueprintEvent)
// Parameters:
// float                                   Scale                                                  (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void AINTERACT_PowerStation_C::UpdateLightIntensity(float Scale)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("INTERACT_PowerStation_C", "UpdateLightIntensity");

	Params::INTERACT_PowerStation_C_UpdateLightIntensity Parms{};

	Parms.Scale = Scale;

	UObject::ProcessEvent(Func, &Parms);
}


// Function INTERACT_PowerStation.INTERACT_PowerStation_C.UpdatePowerStationVisibility
// (Protected, BlueprintCallable, BlueprintEvent)
// Parameters:
// bool                                    VisibilityState                                        (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor)

void AINTERACT_PowerStation_C::UpdatePowerStationVisibility(bool VisibilityState)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("INTERACT_PowerStation_C", "UpdatePowerStationVisibility");

	Params::INTERACT_PowerStation_C_UpdatePowerStationVisibility Parms{};

	Parms.VisibilityState = VisibilityState;

	UObject::ProcessEvent(Func, &Parms);
}


// Function INTERACT_PowerStation.INTERACT_PowerStation_C.UpdatePowerStationAudibility
// (Protected, BlueprintCallable, BlueprintEvent)
// Parameters:
// bool                                    AudibilityState                                        (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor)

void AINTERACT_PowerStation_C::UpdatePowerStationAudibility(bool AudibilityState)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("INTERACT_PowerStation_C", "UpdatePowerStationAudibility");

	Params::INTERACT_PowerStation_C_UpdatePowerStationAudibility Parms{};

	Parms.AudibilityState = AudibilityState;

	UObject::ProcessEvent(Func, &Parms);
}


// Function INTERACT_PowerStation.INTERACT_PowerStation_C.TryDisablePowerStationLight
// (Protected, HasDefaults, BlueprintCallable, BlueprintEvent)

void AINTERACT_PowerStation_C::TryDisablePowerStationLight()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("INTERACT_PowerStation_C", "TryDisablePowerStationLight");

	UObject::ProcessEvent(Func, nullptr);
}


// Function INTERACT_PowerStation.INTERACT_PowerStation_C.PlayPowerStationIdleEffects
// (Private, BlueprintCallable, BlueprintEvent)

void AINTERACT_PowerStation_C::PlayPowerStationIdleEffects()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("INTERACT_PowerStation_C", "PlayPowerStationIdleEffects");

	UObject::ProcessEvent(Func, nullptr);
}


// Function INTERACT_PowerStation.INTERACT_PowerStation_C.PlayPowerStationMontage
// (Protected, HasDefaults, BlueprintCallable, BlueprintEvent)

void AINTERACT_PowerStation_C::PlayPowerStationMontage()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("INTERACT_PowerStation_C", "PlayPowerStationMontage");

	UObject::ProcessEvent(Func, nullptr);
}


// Function INTERACT_PowerStation.INTERACT_PowerStation_C.ReceiveAnimationMessage
// (Public, HasOutParams, BlueprintCallable, BlueprintEvent)
// Parameters:
// class FString                           Message                                                (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, HasGetValueTypeHash)
// bool                                    Result                                                 (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor)

void AINTERACT_PowerStation_C::ReceiveAnimationMessage(const class FString& Message, bool* Result)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("INTERACT_PowerStation_C", "ReceiveAnimationMessage");

	Params::INTERACT_PowerStation_C_ReceiveAnimationMessage Parms{};

	Parms.Message = std::move(Message);

	UObject::ProcessEvent(Func, &Parms);

	if (Result != nullptr)
		*Result = Parms.Result;
}


// Function INTERACT_PowerStation.INTERACT_PowerStation_C.GetRechargeStateDuration
// (Public, HasOutParams, BlueprintCallable, BlueprintEvent, BlueprintPure)
// Parameters:
// float                                   Result                                                 (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void AINTERACT_PowerStation_C::GetRechargeStateDuration(float* Result)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("INTERACT_PowerStation_C", "GetRechargeStateDuration");

	Params::INTERACT_PowerStation_C_GetRechargeStateDuration Parms{};

	UObject::ProcessEvent(Func, &Parms);

	if (Result != nullptr)
		*Result = Parms.Result;
}


// Function INTERACT_PowerStation.INTERACT_PowerStation_C.GetRechargeStateCount
// (Public, HasOutParams, BlueprintCallable, BlueprintEvent, BlueprintPure)
// Parameters:
// int32                                   Count                                                  (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void AINTERACT_PowerStation_C::GetRechargeStateCount(int32* Count)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("INTERACT_PowerStation_C", "GetRechargeStateCount");

	Params::INTERACT_PowerStation_C_GetRechargeStateCount Parms{};

	UObject::ProcessEvent(Func, &Parms);

	if (Count != nullptr)
		*Count = Parms.Count;
}


// Function INTERACT_PowerStation.INTERACT_PowerStation_C.EVENT_OnSpawnedActivateFX
// (Private, BlueprintCallable, BlueprintEvent)
// Parameters:
// class UObject*                          Object                                                 (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void AINTERACT_PowerStation_C::EVENT_OnSpawnedActivateFX(class UObject* Object)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("INTERACT_PowerStation_C", "EVENT_OnSpawnedActivateFX");

	Params::INTERACT_PowerStation_C_EVENT_OnSpawnedActivateFX Parms{};

	Parms.Object = Object;

	UObject::ProcessEvent(Func, &Parms);
}


// Function INTERACT_PowerStation.INTERACT_PowerStation_C.CreateChannelingMoveControl
// (Protected, HasOutParams, BlueprintCallable, BlueprintEvent)
// Parameters:
// class APAWN_Hacker_Simple_C*            HackerPawn                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// class UMOVECONTROL_Base_C*              Result                                                 (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void AINTERACT_PowerStation_C::CreateChannelingMoveControl(class APAWN_Hacker_Simple_C* HackerPawn, class UMOVECONTROL_Base_C** Result)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("INTERACT_PowerStation_C", "CreateChannelingMoveControl");

	Params::INTERACT_PowerStation_C_CreateChannelingMoveControl Parms{};

	Parms.HackerPawn = HackerPawn;

	UObject::ProcessEvent(Func, &Parms);

	if (Result != nullptr)
		*Result = Parms.Result;
}


// Function INTERACT_PowerStation.INTERACT_PowerStation_C.EVENT_OnDisableAttribChanged
// (Private, BlueprintCallable, BlueprintEvent)
// Parameters:
// float                                   CurrValue                                              (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// float                                   LastValue                                              (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void AINTERACT_PowerStation_C::EVENT_OnDisableAttribChanged(float CurrValue, float LastValue)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("INTERACT_PowerStation_C", "EVENT_OnDisableAttribChanged");

	Params::INTERACT_PowerStation_C_EVENT_OnDisableAttribChanged Parms{};

	Parms.CurrValue = CurrValue;
	Parms.LastValue = LastValue;

	UObject::ProcessEvent(Func, &Parms);
}


// Function INTERACT_PowerStation.INTERACT_PowerStation_C.IsPowerStationFunctional
// (Public, HasOutParams, BlueprintCallable, BlueprintEvent, BlueprintPure)
// Parameters:
// bool                                    Result                                                 (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor)

void AINTERACT_PowerStation_C::IsPowerStationFunctional(bool* Result)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("INTERACT_PowerStation_C", "IsPowerStationFunctional");

	Params::INTERACT_PowerStation_C_IsPowerStationFunctional Parms{};

	UObject::ProcessEvent(Func, &Parms);

	if (Result != nullptr)
		*Result = Parms.Result;
}


// Function INTERACT_PowerStation.INTERACT_PowerStation_C.IsHiddenInteractablePrimitive
// (Public, HasOutParams, BlueprintCallable, BlueprintEvent)
// Parameters:
// class APAWN_SystemShockCharacter_C*     Character                                              (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// class UPrimitiveComponent*              CursorPrimitive                                        (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// bool                                    Result                                                 (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor)

void AINTERACT_PowerStation_C::IsHiddenInteractablePrimitive(class APAWN_SystemShockCharacter_C* Character, class UPrimitiveComponent* CursorPrimitive, bool* Result)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("INTERACT_PowerStation_C", "IsHiddenInteractablePrimitive");

	Params::INTERACT_PowerStation_C_IsHiddenInteractablePrimitive Parms{};

	Parms.Character = Character;
	Parms.CursorPrimitive = CursorPrimitive;

	UObject::ProcessEvent(Func, &Parms);

	if (Result != nullptr)
		*Result = Parms.Result;
}


// Function INTERACT_PowerStation.INTERACT_PowerStation_C.CanModifyInteractPower
// (Public, HasOutParams, BlueprintCallable, BlueprintEvent)
// Parameters:
// bool                                    Result                                                 (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor)

void AINTERACT_PowerStation_C::CanModifyInteractPower(bool* Result)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("INTERACT_PowerStation_C", "CanModifyInteractPower");

	Params::INTERACT_PowerStation_C_CanModifyInteractPower Parms{};

	UObject::ProcessEvent(Func, &Parms);

	if (Result != nullptr)
		*Result = Parms.Result;
}


// Function INTERACT_PowerStation.INTERACT_PowerStation_C.SetInteractPowered
// (Public, HasOutParams, BlueprintCallable, BlueprintEvent)
// Parameters:
// bool                                    State                                                  (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor)
// bool                                    Result                                                 (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor)

void AINTERACT_PowerStation_C::SetInteractPowered(bool State, bool* Result)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("INTERACT_PowerStation_C", "SetInteractPowered");

	Params::INTERACT_PowerStation_C_SetInteractPowered Parms{};

	Parms.State = State;

	UObject::ProcessEvent(Func, &Parms);

	if (Result != nullptr)
		*Result = Parms.Result;
}


// Function INTERACT_PowerStation.INTERACT_PowerStation_C.OnPowerStateEnabled
// (Protected, BlueprintCallable, BlueprintEvent)

void AINTERACT_PowerStation_C::OnPowerStateEnabled()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("INTERACT_PowerStation_C", "OnPowerStateEnabled");

	UObject::ProcessEvent(Func, nullptr);
}


// Function INTERACT_PowerStation.INTERACT_PowerStation_C.OnPowerStateDisabled
// (Protected, HasDefaults, BlueprintCallable, BlueprintEvent)
// Parameters:
// bool                                    HandleTimerChanges                                     (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor)

void AINTERACT_PowerStation_C::OnPowerStateDisabled(bool HandleTimerChanges)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("INTERACT_PowerStation_C", "OnPowerStateDisabled");

	Params::INTERACT_PowerStation_C_OnPowerStateDisabled Parms{};

	Parms.HandleTimerChanges = HandleTimerChanges;

	UObject::ProcessEvent(Func, &Parms);
}

}

