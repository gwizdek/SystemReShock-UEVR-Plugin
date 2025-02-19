#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: INTERACT_SentryTurret_HostileBase

#include "Basic.hpp"

#include "INTERACT_SentryTurret_HostileBase_classes.hpp"
#include "INTERACT_SentryTurret_HostileBase_parameters.hpp"


namespace SDK
{

// Function INTERACT_SentryTurret_HostileBase.INTERACT_SentryTurret_HostileBase_C.ExecuteUbergraph_INTERACT_SentryTurret_HostileBase
// (Final, UbergraphFunction)
// Parameters:
// int32                                   EntryPoint                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void AINTERACT_SentryTurret_HostileBase_C::ExecuteUbergraph_INTERACT_SentryTurret_HostileBase(int32 EntryPoint)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("INTERACT_SentryTurret_HostileBase_C", "ExecuteUbergraph_INTERACT_SentryTurret_HostileBase");

	Params::INTERACT_SentryTurret_HostileBase_C_ExecuteUbergraph_INTERACT_SentryTurret_HostileBase Parms{};

	Parms.EntryPoint = EntryPoint;

	UObject::ProcessEvent(Func, &Parms);
}


// Function INTERACT_SentryTurret_HostileBase.INTERACT_SentryTurret_HostileBase_C.BndEvt__INTERACT_SentryTurret_HostileBase_COMP_EnemyDetection_K2Node_ComponentBoundEvent_2_OnDetectionStateChanged__DelegateSignature
// (BlueprintEvent)
// Parameters:
// class APAWN_SystemShockCharacter_C*     Character                                              (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// struct FVector                          EventLocation                                          (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// ENUM_DetectionState                     NewState                                               (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// ENUM_DetectionState                     OldState                                               (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void AINTERACT_SentryTurret_HostileBase_C::BndEvt__INTERACT_SentryTurret_HostileBase_COMP_EnemyDetection_K2Node_ComponentBoundEvent_2_OnDetectionStateChanged__DelegateSignature(class APAWN_SystemShockCharacter_C* Character, const struct FVector& EventLocation, ENUM_DetectionState NewState, ENUM_DetectionState OldState)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("INTERACT_SentryTurret_HostileBase_C", "BndEvt__INTERACT_SentryTurret_HostileBase_COMP_EnemyDetection_K2Node_ComponentBoundEvent_2_OnDetectionStateChanged__DelegateSignature");

	Params::INTERACT_SentryTurret_HostileBase_C_BndEvt__INTERACT_SentryTurret_HostileBase_COMP_EnemyDetection_K2Node_ComponentBoundEvent_2_OnDetectionStateChanged__DelegateSignature Parms{};

	Parms.Character = Character;
	Parms.EventLocation = std::move(EventLocation);
	Parms.NewState = NewState;
	Parms.OldState = OldState;

	UObject::ProcessEvent(Func, &Parms);
}


// Function INTERACT_SentryTurret_HostileBase.INTERACT_SentryTurret_HostileBase_C.BndEvt__INTERACT_SentryTurret_HostileBase_COMP_EnemySensingComponent_K2Node_ComponentBoundEvent_1_OnHearPawn__DelegateSignature
// (BlueprintEvent)
// Parameters:
// class APAWN_SystemShockCharacter_C*     Pawn                                                   (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// struct FVector                          Location                                               (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// float                                   Loudness                                               (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void AINTERACT_SentryTurret_HostileBase_C::BndEvt__INTERACT_SentryTurret_HostileBase_COMP_EnemySensingComponent_K2Node_ComponentBoundEvent_1_OnHearPawn__DelegateSignature(class APAWN_SystemShockCharacter_C* Pawn, const struct FVector& Location, float Loudness)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("INTERACT_SentryTurret_HostileBase_C", "BndEvt__INTERACT_SentryTurret_HostileBase_COMP_EnemySensingComponent_K2Node_ComponentBoundEvent_1_OnHearPawn__DelegateSignature");

	Params::INTERACT_SentryTurret_HostileBase_C_BndEvt__INTERACT_SentryTurret_HostileBase_COMP_EnemySensingComponent_K2Node_ComponentBoundEvent_1_OnHearPawn__DelegateSignature Parms{};

	Parms.Pawn = Pawn;
	Parms.Location = std::move(Location);
	Parms.Loudness = Loudness;

	UObject::ProcessEvent(Func, &Parms);
}


// Function INTERACT_SentryTurret_HostileBase.INTERACT_SentryTurret_HostileBase_C.BndEvt__INTERACT_SentryTurret_HostileBase_COMP_EnemySensingComponent_K2Node_ComponentBoundEvent_0_OnSeePawn__DelegateSignature
// (BlueprintEvent)
// Parameters:
// class APAWN_SystemShockCharacter_C*     Pawn                                                   (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// struct FVector                          Location                                               (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void AINTERACT_SentryTurret_HostileBase_C::BndEvt__INTERACT_SentryTurret_HostileBase_COMP_EnemySensingComponent_K2Node_ComponentBoundEvent_0_OnSeePawn__DelegateSignature(class APAWN_SystemShockCharacter_C* Pawn, const struct FVector& Location)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("INTERACT_SentryTurret_HostileBase_C", "BndEvt__INTERACT_SentryTurret_HostileBase_COMP_EnemySensingComponent_K2Node_ComponentBoundEvent_0_OnSeePawn__DelegateSignature");

	Params::INTERACT_SentryTurret_HostileBase_C_BndEvt__INTERACT_SentryTurret_HostileBase_COMP_EnemySensingComponent_K2Node_ComponentBoundEvent_0_OnSeePawn__DelegateSignature Parms{};

	Parms.Pawn = Pawn;
	Parms.Location = std::move(Location);

	UObject::ProcessEvent(Func, &Parms);
}


// Function INTERACT_SentryTurret_HostileBase.INTERACT_SentryTurret_HostileBase_C.TickSentryTurret
// (Protected, HasDefaults, BlueprintCallable, BlueprintEvent)
// Parameters:
// float                                   DeltaSeconds                                           (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void AINTERACT_SentryTurret_HostileBase_C::TickSentryTurret(float DeltaSeconds)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("INTERACT_SentryTurret_HostileBase_C", "TickSentryTurret");

	Params::INTERACT_SentryTurret_HostileBase_C_TickSentryTurret Parms{};

	Parms.DeltaSeconds = DeltaSeconds;

	UObject::ProcessEvent(Func, &Parms);
}


// Function INTERACT_SentryTurret_HostileBase.INTERACT_SentryTurret_HostileBase_C.UpdateSentryTurretTransition
// (Protected, BlueprintCallable, BlueprintEvent)
// Parameters:
// float                                   StateProgress                                          (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void AINTERACT_SentryTurret_HostileBase_C::UpdateSentryTurretTransition(float StateProgress)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("INTERACT_SentryTurret_HostileBase_C", "UpdateSentryTurretTransition");

	Params::INTERACT_SentryTurret_HostileBase_C_UpdateSentryTurretTransition Parms{};

	Parms.StateProgress = StateProgress;

	UObject::ProcessEvent(Func, &Parms);
}


// Function INTERACT_SentryTurret_HostileBase.INTERACT_SentryTurret_HostileBase_C.InitializeSentryTurretRotation
// (Protected, BlueprintCallable, BlueprintEvent)

void AINTERACT_SentryTurret_HostileBase_C::InitializeSentryTurretRotation()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("INTERACT_SentryTurret_HostileBase_C", "InitializeSentryTurretRotation");

	UObject::ProcessEvent(Func, nullptr);
}


// Function INTERACT_SentryTurret_HostileBase.INTERACT_SentryTurret_HostileBase_C.UpdateBodyMeshLocation
// (Protected, HasDefaults, BlueprintCallable, BlueprintEvent)
// Parameters:
// float                                   DeployProgress                                         (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void AINTERACT_SentryTurret_HostileBase_C::UpdateBodyMeshLocation(float DeployProgress)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("INTERACT_SentryTurret_HostileBase_C", "UpdateBodyMeshLocation");

	Params::INTERACT_SentryTurret_HostileBase_C_UpdateBodyMeshLocation Parms{};

	Parms.DeployProgress = DeployProgress;

	UObject::ProcessEvent(Func, &Parms);
}


// Function INTERACT_SentryTurret_HostileBase.INTERACT_SentryTurret_HostileBase_C.TrySetSentryTurretIsAware
// (Protected, HasOutParams, BlueprintCallable, BlueprintEvent)
// Parameters:
// bool                                    State                                                  (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor)
// bool                                    Result                                                 (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor)

void AINTERACT_SentryTurret_HostileBase_C::TrySetSentryTurretIsAware(bool State, bool* Result)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("INTERACT_SentryTurret_HostileBase_C", "TrySetSentryTurretIsAware");

	Params::INTERACT_SentryTurret_HostileBase_C_TrySetSentryTurretIsAware Parms{};

	Parms.State = State;

	UObject::ProcessEvent(Func, &Parms);

	if (Result != nullptr)
		*Result = Parms.Result;
}


// Function INTERACT_SentryTurret_HostileBase.INTERACT_SentryTurret_HostileBase_C.EVENT_OnTryMakeUnawareTick
// (Private, HasDefaults, BlueprintCallable, BlueprintEvent)

void AINTERACT_SentryTurret_HostileBase_C::EVENT_OnTryMakeUnawareTick()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("INTERACT_SentryTurret_HostileBase_C", "EVENT_OnTryMakeUnawareTick");

	UObject::ProcessEvent(Func, nullptr);
}


// Function INTERACT_SentryTurret_HostileBase.INTERACT_SentryTurret_HostileBase_C.CanDeploySentryTurret
// (Public, HasOutParams, BlueprintCallable, BlueprintEvent, BlueprintPure)
// Parameters:
// bool                                    Result                                                 (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor)

void AINTERACT_SentryTurret_HostileBase_C::CanDeploySentryTurret(bool* Result)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("INTERACT_SentryTurret_HostileBase_C", "CanDeploySentryTurret");

	Params::INTERACT_SentryTurret_HostileBase_C_CanDeploySentryTurret Parms{};

	UObject::ProcessEvent(Func, &Parms);

	if (Result != nullptr)
		*Result = Parms.Result;
}


// Function INTERACT_SentryTurret_HostileBase.INTERACT_SentryTurret_HostileBase_C.HasTickBehaviorWhilePerceptible
// (Protected, HasOutParams, BlueprintCallable, BlueprintEvent)
// Parameters:
// bool                                    Result                                                 (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor)

void AINTERACT_SentryTurret_HostileBase_C::HasTickBehaviorWhilePerceptible(bool* Result)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("INTERACT_SentryTurret_HostileBase_C", "HasTickBehaviorWhilePerceptible");

	Params::INTERACT_SentryTurret_HostileBase_C_HasTickBehaviorWhilePerceptible Parms{};

	UObject::ProcessEvent(Func, &Parms);

	if (Result != nullptr)
		*Result = Parms.Result;
}


// Function INTERACT_SentryTurret_HostileBase.INTERACT_SentryTurret_HostileBase_C.OnTickStateChanged
// (Protected, HasDefaults, BlueprintCallable, BlueprintEvent)
// Parameters:
// bool                                    State                                                  (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor)

void AINTERACT_SentryTurret_HostileBase_C::OnTickStateChanged(bool State)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("INTERACT_SentryTurret_HostileBase_C", "OnTickStateChanged");

	Params::INTERACT_SentryTurret_HostileBase_C_OnTickStateChanged Parms{};

	Parms.State = State;

	UObject::ProcessEvent(Func, &Parms);
}


// Function INTERACT_SentryTurret_HostileBase.INTERACT_SentryTurret_HostileBase_C.HasCriticalTickBehavior
// (Protected, HasOutParams, BlueprintCallable, BlueprintEvent)
// Parameters:
// bool                                    Result                                                 (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor)

void AINTERACT_SentryTurret_HostileBase_C::HasCriticalTickBehavior(bool* Result)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("INTERACT_SentryTurret_HostileBase_C", "HasCriticalTickBehavior");

	Params::INTERACT_SentryTurret_HostileBase_C_HasCriticalTickBehavior Parms{};

	UObject::ProcessEvent(Func, &Parms);

	if (Result != nullptr)
		*Result = Parms.Result;
}


// Function INTERACT_SentryTurret_HostileBase.INTERACT_SentryTurret_HostileBase_C.OnSentryTurretAwarenessChanged
// (Protected, BlueprintCallable, BlueprintEvent)

void AINTERACT_SentryTurret_HostileBase_C::OnSentryTurretAwarenessChanged()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("INTERACT_SentryTurret_HostileBase_C", "OnSentryTurretAwarenessChanged");

	UObject::ProcessEvent(Func, nullptr);
}


// Function INTERACT_SentryTurret_HostileBase.INTERACT_SentryTurret_HostileBase_C.OnDetectionStateChanged
// (Protected, BlueprintCallable, BlueprintEvent)
// Parameters:
// class APAWN_SystemShockCharacter_C*     Character                                              (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// struct FVector                          EventLocation                                          (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// ENUM_DetectionState                     DetectionState                                         (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void AINTERACT_SentryTurret_HostileBase_C::OnDetectionStateChanged(class APAWN_SystemShockCharacter_C* Character, const struct FVector& EventLocation, ENUM_DetectionState DetectionState)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("INTERACT_SentryTurret_HostileBase_C", "OnDetectionStateChanged");

	Params::INTERACT_SentryTurret_HostileBase_C_OnDetectionStateChanged Parms{};

	Parms.Character = Character;
	Parms.EventLocation = std::move(EventLocation);
	Parms.DetectionState = DetectionState;

	UObject::ProcessEvent(Func, &Parms);
}


// Function INTERACT_SentryTurret_HostileBase.INTERACT_SentryTurret_HostileBase_C.SetSentryAlertState
// (Protected, HasDefaults, BlueprintCallable, BlueprintEvent)
// Parameters:
// bool                                    State                                                  (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor)
// bool                                    IsDuringBeginPlay                                      (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor)

void AINTERACT_SentryTurret_HostileBase_C::SetSentryAlertState(bool State, bool IsDuringBeginPlay)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("INTERACT_SentryTurret_HostileBase_C", "SetSentryAlertState");

	Params::INTERACT_SentryTurret_HostileBase_C_SetSentryAlertState Parms{};

	Parms.State = State;
	Parms.IsDuringBeginPlay = IsDuringBeginPlay;

	UObject::ProcessEvent(Func, &Parms);
}


// Function INTERACT_SentryTurret_HostileBase.INTERACT_SentryTurret_HostileBase_C.SetSentryHostileState
// (Protected, BlueprintCallable, BlueprintEvent)
// Parameters:
// bool                                    State                                                  (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor)

void AINTERACT_SentryTurret_HostileBase_C::SetSentryHostileState(bool State)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("INTERACT_SentryTurret_HostileBase_C", "SetSentryHostileState");

	Params::INTERACT_SentryTurret_HostileBase_C_SetSentryHostileState Parms{};

	Parms.State = State;

	UObject::ProcessEvent(Func, &Parms);
}


// Function INTERACT_SentryTurret_HostileBase.INTERACT_SentryTurret_HostileBase_C.RotateTurretToTargetYaw
// (Protected, HasOutParams, HasDefaults, BlueprintCallable, BlueprintEvent)
// Parameters:
// float                                   DesiredYaw                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// float                                   DeltaSeconds                                           (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// bool                                    Changed                                                (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor)

void AINTERACT_SentryTurret_HostileBase_C::RotateTurretToTargetYaw(float DesiredYaw, float DeltaSeconds, bool* Changed)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("INTERACT_SentryTurret_HostileBase_C", "RotateTurretToTargetYaw");

	Params::INTERACT_SentryTurret_HostileBase_C_RotateTurretToTargetYaw Parms{};

	Parms.DesiredYaw = DesiredYaw;
	Parms.DeltaSeconds = DeltaSeconds;

	UObject::ProcessEvent(Func, &Parms);

	if (Changed != nullptr)
		*Changed = Parms.Changed;
}


// Function INTERACT_SentryTurret_HostileBase.INTERACT_SentryTurret_HostileBase_C.RotateTurretToTargetPitch
// (Protected, HasOutParams, HasDefaults, BlueprintCallable, BlueprintEvent)
// Parameters:
// float                                   DesiredPitch                                           (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// float                                   DeltaSeconds                                           (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// bool                                    Changed                                                (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor)

void AINTERACT_SentryTurret_HostileBase_C::RotateTurretToTargetPitch(float DesiredPitch, float DeltaSeconds, bool* Changed)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("INTERACT_SentryTurret_HostileBase_C", "RotateTurretToTargetPitch");

	Params::INTERACT_SentryTurret_HostileBase_C_RotateTurretToTargetPitch Parms{};

	Parms.DesiredPitch = DesiredPitch;
	Parms.DeltaSeconds = DeltaSeconds;

	UObject::ProcessEvent(Func, &Parms);

	if (Changed != nullptr)
		*Changed = Parms.Changed;
}


// Function INTERACT_SentryTurret_HostileBase.INTERACT_SentryTurret_HostileBase_C.IsSentryTurretAware
// (Public, HasOutParams, BlueprintCallable, BlueprintEvent, BlueprintPure)
// Parameters:
// bool                                    Result                                                 (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor)

void AINTERACT_SentryTurret_HostileBase_C::IsSentryTurretAware(bool* Result)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("INTERACT_SentryTurret_HostileBase_C", "IsSentryTurretAware");

	Params::INTERACT_SentryTurret_HostileBase_C_IsSentryTurretAware Parms{};

	UObject::ProcessEvent(Func, &Parms);

	if (Result != nullptr)
		*Result = Parms.Result;
}


// Function INTERACT_SentryTurret_HostileBase.INTERACT_SentryTurret_HostileBase_C.IsLocationInTurretRange
// (Public, HasOutParams, BlueprintCallable, BlueprintEvent, BlueprintPure)
// Parameters:
// struct FVector                          Location                                               (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// bool                                    Result                                                 (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor)

void AINTERACT_SentryTurret_HostileBase_C::IsLocationInTurretRange(const struct FVector& Location, bool* Result)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("INTERACT_SentryTurret_HostileBase_C", "IsLocationInTurretRange");

	Params::INTERACT_SentryTurret_HostileBase_C_IsLocationInTurretRange Parms{};

	Parms.Location = std::move(Location);

	UObject::ProcessEvent(Func, &Parms);

	if (Result != nullptr)
		*Result = Parms.Result;
}


// Function INTERACT_SentryTurret_HostileBase.INTERACT_SentryTurret_HostileBase_C.IsAttackCooldownFinished
// (Public, HasOutParams, BlueprintCallable, BlueprintEvent, BlueprintPure)
// Parameters:
// bool                                    Result                                                 (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor)

void AINTERACT_SentryTurret_HostileBase_C::IsAttackCooldownFinished(bool* Result)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("INTERACT_SentryTurret_HostileBase_C", "IsAttackCooldownFinished");

	Params::INTERACT_SentryTurret_HostileBase_C_IsAttackCooldownFinished Parms{};

	UObject::ProcessEvent(Func, &Parms);

	if (Result != nullptr)
		*Result = Parms.Result;
}


// Function INTERACT_SentryTurret_HostileBase.INTERACT_SentryTurret_HostileBase_C.StartSentryTurretAttack
// (Protected, BlueprintCallable, BlueprintEvent)

void AINTERACT_SentryTurret_HostileBase_C::StartSentryTurretAttack()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("INTERACT_SentryTurret_HostileBase_C", "StartSentryTurretAttack");

	UObject::ProcessEvent(Func, nullptr);
}


// Function INTERACT_SentryTurret_HostileBase.INTERACT_SentryTurret_HostileBase_C.CanAttackTarget
// (Public, HasOutParams, BlueprintCallable, BlueprintEvent, BlueprintPure)
// Parameters:
// bool                                    IsTargetVisible                                        (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor)
// bool                                    Result                                                 (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor)

void AINTERACT_SentryTurret_HostileBase_C::CanAttackTarget(bool IsTargetVisible, bool* Result)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("INTERACT_SentryTurret_HostileBase_C", "CanAttackTarget");

	Params::INTERACT_SentryTurret_HostileBase_C_CanAttackTarget Parms{};

	Parms.IsTargetVisible = IsTargetVisible;

	UObject::ProcessEvent(Func, &Parms);

	if (Result != nullptr)
		*Result = Parms.Result;
}


// Function INTERACT_SentryTurret_HostileBase.INTERACT_SentryTurret_HostileBase_C.GetAttackCooldownDuration
// (Public, HasOutParams, BlueprintCallable, BlueprintEvent, BlueprintPure)
// Parameters:
// float                                   Result                                                 (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void AINTERACT_SentryTurret_HostileBase_C::GetAttackCooldownDuration(float* Result)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("INTERACT_SentryTurret_HostileBase_C", "GetAttackCooldownDuration");

	Params::INTERACT_SentryTurret_HostileBase_C_GetAttackCooldownDuration Parms{};

	UObject::ProcessEvent(Func, &Parms);

	if (Result != nullptr)
		*Result = Parms.Result;
}


// Function INTERACT_SentryTurret_HostileBase.INTERACT_SentryTurret_HostileBase_C.CancelSentryTurretAttack
// (Protected, BlueprintCallable, BlueprintEvent)

void AINTERACT_SentryTurret_HostileBase_C::CancelSentryTurretAttack()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("INTERACT_SentryTurret_HostileBase_C", "CancelSentryTurretAttack");

	UObject::ProcessEvent(Func, nullptr);
}


// Function INTERACT_SentryTurret_HostileBase.INTERACT_SentryTurret_HostileBase_C.GetElapsedTimeSinceLastAttack
// (Public, HasOutParams, BlueprintCallable, BlueprintEvent, BlueprintPure)
// Parameters:
// float                                   Result                                                 (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void AINTERACT_SentryTurret_HostileBase_C::GetElapsedTimeSinceLastAttack(float* Result)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("INTERACT_SentryTurret_HostileBase_C", "GetElapsedTimeSinceLastAttack");

	Params::INTERACT_SentryTurret_HostileBase_C_GetElapsedTimeSinceLastAttack Parms{};

	UObject::ProcessEvent(Func, &Parms);

	if (Result != nullptr)
		*Result = Parms.Result;
}


// Function INTERACT_SentryTurret_HostileBase.INTERACT_SentryTurret_HostileBase_C.OnMagneticDisableStateChanged
// (Protected, BlueprintCallable, BlueprintEvent)
// Parameters:
// bool                                    DisableState                                           (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor)

void AINTERACT_SentryTurret_HostileBase_C::OnMagneticDisableStateChanged(bool DisableState)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("INTERACT_SentryTurret_HostileBase_C", "OnMagneticDisableStateChanged");

	Params::INTERACT_SentryTurret_HostileBase_C_OnMagneticDisableStateChanged Parms{};

	Parms.DisableState = DisableState;

	UObject::ProcessEvent(Func, &Parms);
}


// Function INTERACT_SentryTurret_HostileBase.INTERACT_SentryTurret_HostileBase_C.TryDeploySentryTurret
// (Public, HasOutParams, BlueprintCallable, BlueprintEvent)
// Parameters:
// class AActor*                           SourceActor                                            (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// bool                                    Result                                                 (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor)

void AINTERACT_SentryTurret_HostileBase_C::TryDeploySentryTurret(class AActor* SourceActor, bool* Result)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("INTERACT_SentryTurret_HostileBase_C", "TryDeploySentryTurret");

	Params::INTERACT_SentryTurret_HostileBase_C_TryDeploySentryTurret Parms{};

	Parms.SourceActor = SourceActor;

	UObject::ProcessEvent(Func, &Parms);

	if (Result != nullptr)
		*Result = Parms.Result;
}


// Function INTERACT_SentryTurret_HostileBase.INTERACT_SentryTurret_HostileBase_C.InitializeDestructible
// (Protected, BlueprintCallable, BlueprintEvent)

void AINTERACT_SentryTurret_HostileBase_C::InitializeDestructible()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("INTERACT_SentryTurret_HostileBase_C", "InitializeDestructible");

	UObject::ProcessEvent(Func, nullptr);
}


// Function INTERACT_SentryTurret_HostileBase.INTERACT_SentryTurret_HostileBase_C.OnTakeDamage
// (Protected, HasOutParams, BlueprintCallable, BlueprintEvent)
// Parameters:
// class AActor*                           OtherActor                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// struct FAttribDamageInstance            DamageInstance                                         (BlueprintVisible, BlueprintReadOnly, Parm)
// class UObject*                          UserParams                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// bool                                    Result                                                 (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor)

void AINTERACT_SentryTurret_HostileBase_C::OnTakeDamage(class AActor* OtherActor, const struct FAttribDamageInstance& DamageInstance, class UObject* UserParams, bool* Result)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("INTERACT_SentryTurret_HostileBase_C", "OnTakeDamage");

	Params::INTERACT_SentryTurret_HostileBase_C_OnTakeDamage Parms{};

	Parms.OtherActor = OtherActor;
	Parms.DamageInstance = std::move(DamageInstance);
	Parms.UserParams = UserParams;

	UObject::ProcessEvent(Func, &Parms);

	if (Result != nullptr)
		*Result = Parms.Result;
}


// Function INTERACT_SentryTurret_HostileBase.INTERACT_SentryTurret_HostileBase_C.OnDeath
// (Protected, HasOutParams, BlueprintCallable, BlueprintEvent)
// Parameters:
// class AActor*                           SourceActor                                            (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// bool                                    Result                                                 (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor)

void AINTERACT_SentryTurret_HostileBase_C::OnDeath(class AActor* SourceActor, bool* Result)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("INTERACT_SentryTurret_HostileBase_C", "OnDeath");

	Params::INTERACT_SentryTurret_HostileBase_C_OnDeath Parms{};

	Parms.SourceActor = SourceActor;

	UObject::ProcessEvent(Func, &Parms);

	if (Result != nullptr)
		*Result = Parms.Result;
}


// Function INTERACT_SentryTurret_HostileBase.INTERACT_SentryTurret_HostileBase_C.UpdateDeathSettings
// (Protected, HasOutParams, BlueprintCallable, BlueprintEvent)
// Parameters:
// bool                                    DuringBeginPlay                                        (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor)
// bool                                    Result                                                 (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor)

void AINTERACT_SentryTurret_HostileBase_C::UpdateDeathSettings(bool DuringBeginPlay, bool* Result)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("INTERACT_SentryTurret_HostileBase_C", "UpdateDeathSettings");

	Params::INTERACT_SentryTurret_HostileBase_C_UpdateDeathSettings Parms{};

	Parms.DuringBeginPlay = DuringBeginPlay;

	UObject::ProcessEvent(Func, &Parms);

	if (Result != nullptr)
		*Result = Parms.Result;
}


// Function INTERACT_SentryTurret_HostileBase.INTERACT_SentryTurret_HostileBase_C.GetThreatLevel
// (Public, HasOutParams, BlueprintCallable, BlueprintEvent, BlueprintPure)
// Parameters:
// int32                                   ThreatLevel                                            (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void AINTERACT_SentryTurret_HostileBase_C::GetThreatLevel(int32* ThreatLevel)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("INTERACT_SentryTurret_HostileBase_C", "GetThreatLevel");

	Params::INTERACT_SentryTurret_HostileBase_C_GetThreatLevel Parms{};

	UObject::ProcessEvent(Func, &Parms);

	if (ThreatLevel != nullptr)
		*ThreatLevel = Parms.ThreatLevel;
}


// Function INTERACT_SentryTurret_HostileBase.INTERACT_SentryTurret_HostileBase_C.CanHackDestructible
// (Public, HasOutParams, BlueprintCallable, BlueprintEvent, BlueprintPure)
// Parameters:
// class APAWN_SystemShockCharacter_C*     SourceCharacter                                        (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// bool                                    Result                                                 (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor)

void AINTERACT_SentryTurret_HostileBase_C::CanHackDestructible(class APAWN_SystemShockCharacter_C* SourceCharacter, bool* Result)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("INTERACT_SentryTurret_HostileBase_C", "CanHackDestructible");

	Params::INTERACT_SentryTurret_HostileBase_C_CanHackDestructible Parms{};

	Parms.SourceCharacter = SourceCharacter;

	UObject::ProcessEvent(Func, &Parms);

	if (Result != nullptr)
		*Result = Parms.Result;
}


// Function INTERACT_SentryTurret_HostileBase.INTERACT_SentryTurret_HostileBase_C.GetDetectionComponent
// (Public, HasOutParams, BlueprintCallable, BlueprintEvent, BlueprintPure)
// Parameters:
// class UCOMP_EnemyDetection_C*           Result                                                 (Parm, OutParm, ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void AINTERACT_SentryTurret_HostileBase_C::GetDetectionComponent(class UCOMP_EnemyDetection_C** Result)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("INTERACT_SentryTurret_HostileBase_C", "GetDetectionComponent");

	Params::INTERACT_SentryTurret_HostileBase_C_GetDetectionComponent Parms{};

	UObject::ProcessEvent(Func, &Parms);

	if (Result != nullptr)
		*Result = Parms.Result;
}

}

