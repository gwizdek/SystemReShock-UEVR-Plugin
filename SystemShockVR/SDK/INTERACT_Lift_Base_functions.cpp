#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: INTERACT_Lift_Base

#include "Basic.hpp"

#include "INTERACT_Lift_Base_classes.hpp"
#include "INTERACT_Lift_Base_parameters.hpp"


namespace SDK
{

// Function INTERACT_Lift_Base.INTERACT_Lift_Base_C.ExecuteUbergraph_INTERACT_Lift_Base
// (Final, UbergraphFunction)
// Parameters:
// int32                                   EntryPoint                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void AINTERACT_Lift_Base_C::ExecuteUbergraph_INTERACT_Lift_Base(int32 EntryPoint)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("INTERACT_Lift_Base_C", "ExecuteUbergraph_INTERACT_Lift_Base");

	Params::INTERACT_Lift_Base_C_ExecuteUbergraph_INTERACT_Lift_Base Parms{};

	Parms.EntryPoint = EntryPoint;

	UObject::ProcessEvent(Func, &Parms);
}


// Function INTERACT_Lift_Base.INTERACT_Lift_Base_C.ReceiveTick
// (Event, Public, BlueprintEvent)
// Parameters:
// float                                   DeltaSeconds                                           (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void AINTERACT_Lift_Base_C::ReceiveTick(float DeltaSeconds)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("INTERACT_Lift_Base_C", "ReceiveTick");

	Params::INTERACT_Lift_Base_C_ReceiveTick Parms{};

	Parms.DeltaSeconds = DeltaSeconds;

	UObject::ProcessEvent(Func, &Parms);
}


// Function INTERACT_Lift_Base.INTERACT_Lift_Base_C.ReceiveBeginPlay
// (Event, Protected, BlueprintEvent)

void AINTERACT_Lift_Base_C::ReceiveBeginPlay()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("INTERACT_Lift_Base_C", "ReceiveBeginPlay");

	UObject::ProcessEvent(Func, nullptr);
}


// Function INTERACT_Lift_Base.INTERACT_Lift_Base_C.UserConstructionScript
// (Event, Public, BlueprintCallable, BlueprintEvent)

void AINTERACT_Lift_Base_C::UserConstructionScript()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("INTERACT_Lift_Base_C", "UserConstructionScript");

	UObject::ProcessEvent(Func, nullptr);
}


// Function INTERACT_Lift_Base.INTERACT_Lift_Base_C.GetTargetShape
// (Public, HasOutParams, BlueprintCallable, BlueprintEvent)
// Parameters:
// class UPrimitiveComponent*              CursorPrimitive                                        (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// class UShapeComponent*                  ShapeComponent                                         (Parm, OutParm, ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void AINTERACT_Lift_Base_C::GetTargetShape(class UPrimitiveComponent* CursorPrimitive, class UShapeComponent** ShapeComponent)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("INTERACT_Lift_Base_C", "GetTargetShape");

	Params::INTERACT_Lift_Base_C_GetTargetShape Parms{};

	Parms.CursorPrimitive = CursorPrimitive;

	UObject::ProcessEvent(Func, &Parms);

	if (ShapeComponent != nullptr)
		*ShapeComponent = Parms.ShapeComponent;
}


// Function INTERACT_Lift_Base.INTERACT_Lift_Base_C.TryInteract
// (Public, HasOutParams, HasDefaults, BlueprintCallable, BlueprintEvent)
// Parameters:
// class AActor*                           SourceActor                                            (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// class UPrimitiveComponent*              CursorPrimitive                                        (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// ENUM_InteractionType                    InteractionType                                        (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// struct FSTRUCT_InteractResults          InteractResults                                        (Parm, OutParm, HasGetValueTypeHash)

void AINTERACT_Lift_Base_C::TryInteract(class AActor* SourceActor, class UPrimitiveComponent* CursorPrimitive, ENUM_InteractionType InteractionType, struct FSTRUCT_InteractResults* InteractResults)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("INTERACT_Lift_Base_C", "TryInteract");

	Params::INTERACT_Lift_Base_C_TryInteract Parms{};

	Parms.SourceActor = SourceActor;
	Parms.CursorPrimitive = CursorPrimitive;
	Parms.InteractionType = InteractionType;

	UObject::ProcessEvent(Func, &Parms);

	if (InteractResults != nullptr)
		*InteractResults = std::move(Parms.InteractResults);
}


// Function INTERACT_Lift_Base.INTERACT_Lift_Base_C.InitializeLift
// (Protected, BlueprintCallable, BlueprintEvent)

void AINTERACT_Lift_Base_C::InitializeLift()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("INTERACT_Lift_Base_C", "InitializeLift");

	UObject::ProcessEvent(Func, nullptr);
}


// Function INTERACT_Lift_Base.INTERACT_Lift_Base_C.InitializeAttributes
// (Protected, BlueprintCallable, BlueprintEvent)

void AINTERACT_Lift_Base_C::InitializeAttributes()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("INTERACT_Lift_Base_C", "InitializeAttributes");

	UObject::ProcessEvent(Func, nullptr);
}


// Function INTERACT_Lift_Base.INTERACT_Lift_Base_C.UpdateEmissiveStrength
// (Protected, BlueprintCallable, BlueprintEvent)
// Parameters:
// float                                   Scale                                                  (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void AINTERACT_Lift_Base_C::UpdateEmissiveStrength(float Scale)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("INTERACT_Lift_Base_C", "UpdateEmissiveStrength");

	Params::INTERACT_Lift_Base_C_UpdateEmissiveStrength Parms{};

	Parms.Scale = Scale;

	UObject::ProcessEvent(Func, &Parms);
}


// Function INTERACT_Lift_Base.INTERACT_Lift_Base_C.ComputeLiftMoveParameters
// (Protected, BlueprintCallable, BlueprintEvent)

void AINTERACT_Lift_Base_C::ComputeLiftMoveParameters()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("INTERACT_Lift_Base_C", "ComputeLiftMoveParameters");

	UObject::ProcessEvent(Func, nullptr);
}


// Function INTERACT_Lift_Base.INTERACT_Lift_Base_C.BeginLiftMovement
// (Protected, BlueprintCallable, BlueprintEvent)

void AINTERACT_Lift_Base_C::BeginLiftMovement()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("INTERACT_Lift_Base_C", "BeginLiftMovement");

	UObject::ProcessEvent(Func, nullptr);
}


// Function INTERACT_Lift_Base.INTERACT_Lift_Base_C.TryUpdateLiftMovement
// (Protected, HasOutParams, BlueprintCallable, BlueprintEvent)
// Parameters:
// float                                   Elapsed_Time                                           (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// bool                                    Result                                                 (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor)

void AINTERACT_Lift_Base_C::TryUpdateLiftMovement(float Elapsed_Time, bool* Result)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("INTERACT_Lift_Base_C", "TryUpdateLiftMovement");

	Params::INTERACT_Lift_Base_C_TryUpdateLiftMovement Parms{};

	Parms.Elapsed_Time = Elapsed_Time;

	UObject::ProcessEvent(Func, &Parms);

	if (Result != nullptr)
		*Result = Parms.Result;
}


// Function INTERACT_Lift_Base.INTERACT_Lift_Base_C.UpdateLiftMovement
// (Protected, BlueprintCallable, BlueprintEvent)
// Parameters:
// float                                   Elapsed_Time                                           (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void AINTERACT_Lift_Base_C::UpdateLiftMovement(float Elapsed_Time)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("INTERACT_Lift_Base_C", "UpdateLiftMovement");

	Params::INTERACT_Lift_Base_C_UpdateLiftMovement Parms{};

	Parms.Elapsed_Time = Elapsed_Time;

	UObject::ProcessEvent(Func, &Parms);
}


// Function INTERACT_Lift_Base.INTERACT_Lift_Base_C.UpdateLiftLocation
// (Protected, HasDefaults, BlueprintCallable, BlueprintEvent)
// Parameters:
// float                                   Displacement                                           (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void AINTERACT_Lift_Base_C::UpdateLiftLocation(float Displacement)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("INTERACT_Lift_Base_C", "UpdateLiftLocation");

	Params::INTERACT_Lift_Base_C_UpdateLiftLocation Parms{};

	Parms.Displacement = Displacement;

	UObject::ProcessEvent(Func, &Parms);
}


// Function INTERACT_Lift_Base.INTERACT_Lift_Base_C.FinishLiftMovement
// (Protected, HasDefaults, BlueprintCallable, BlueprintEvent)

void AINTERACT_Lift_Base_C::FinishLiftMovement()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("INTERACT_Lift_Base_C", "FinishLiftMovement");

	UObject::ProcessEvent(Func, nullptr);
}


// Function INTERACT_Lift_Base.INTERACT_Lift_Base_C.PlayStartFX
// (Protected, BlueprintCallable, BlueprintEvent)

void AINTERACT_Lift_Base_C::PlayStartFX()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("INTERACT_Lift_Base_C", "PlayStartFX");

	UObject::ProcessEvent(Func, nullptr);
}


// Function INTERACT_Lift_Base.INTERACT_Lift_Base_C.PlayStopFX
// (Protected, BlueprintCallable, BlueprintEvent)

void AINTERACT_Lift_Base_C::PlayStopFX()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("INTERACT_Lift_Base_C", "PlayStopFX");

	UObject::ProcessEvent(Func, nullptr);
}


// Function INTERACT_Lift_Base.INTERACT_Lift_Base_C.IsLiftFunctional
// (Public, HasOutParams, BlueprintCallable, BlueprintEvent, BlueprintPure)
// Parameters:
// bool                                    Result                                                 (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor)

void AINTERACT_Lift_Base_C::IsLiftFunctional(bool* Result)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("INTERACT_Lift_Base_C", "IsLiftFunctional");

	Params::INTERACT_Lift_Base_C_IsLiftFunctional Parms{};

	UObject::ProcessEvent(Func, &Parms);

	if (Result != nullptr)
		*Result = Parms.Result;
}


// Function INTERACT_Lift_Base.INTERACT_Lift_Base_C.IsSafeToMove
// (Public, HasOutParams, HasDefaults, BlueprintCallable, BlueprintEvent, BlueprintPure)
// Parameters:
// bool                                    Result                                                 (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor)

void AINTERACT_Lift_Base_C::IsSafeToMove(bool* Result)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("INTERACT_Lift_Base_C", "IsSafeToMove");

	Params::INTERACT_Lift_Base_C_IsSafeToMove Parms{};

	UObject::ProcessEvent(Func, &Parms);

	if (Result != nullptr)
		*Result = Parms.Result;
}


// Function INTERACT_Lift_Base.INTERACT_Lift_Base_C.SetInteractLocked
// (Public, HasOutParams, BlueprintCallable, BlueprintEvent)
// Parameters:
// bool                                    Locked                                                 (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor)
// bool                                    Result                                                 (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor)

void AINTERACT_Lift_Base_C::SetInteractLocked(bool Locked, bool* Result)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("INTERACT_Lift_Base_C", "SetInteractLocked");

	Params::INTERACT_Lift_Base_C_SetInteractLocked Parms{};

	Parms.Locked = Locked;

	UObject::ProcessEvent(Func, &Parms);

	if (Result != nullptr)
		*Result = Parms.Result;
}


// Function INTERACT_Lift_Base.INTERACT_Lift_Base_C.GetInteractLocked
// (Public, HasOutParams, BlueprintCallable, BlueprintEvent)
// Parameters:
// class AActor*                           SourceActor                                            (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// bool                                    Result                                                 (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor)
// class FText                             LockMessage                                            (Parm, OutParm)

void AINTERACT_Lift_Base_C::GetInteractLocked(class AActor* SourceActor, bool* Result, class FText* LockMessage)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("INTERACT_Lift_Base_C", "GetInteractLocked");

	Params::INTERACT_Lift_Base_C_GetInteractLocked Parms{};

	Parms.SourceActor = SourceActor;

	UObject::ProcessEvent(Func, &Parms);

	if (Result != nullptr)
		*Result = Parms.Result;

	if (LockMessage != nullptr)
		*LockMessage = std::move(Parms.LockMessage);
}


// Function INTERACT_Lift_Base.INTERACT_Lift_Base_C.IsLiftEnabled
// (Public, HasOutParams, BlueprintCallable, BlueprintEvent, BlueprintPure)
// Parameters:
// bool                                    Result                                                 (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor)

void AINTERACT_Lift_Base_C::IsLiftEnabled(bool* Result)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("INTERACT_Lift_Base_C", "IsLiftEnabled");

	Params::INTERACT_Lift_Base_C_IsLiftEnabled Parms{};

	UObject::ProcessEvent(Func, &Parms);

	if (Result != nullptr)
		*Result = Parms.Result;
}


// Function INTERACT_Lift_Base.INTERACT_Lift_Base_C.GetInteractBusy
// (Public, HasOutParams, BlueprintCallable, BlueprintEvent)
// Parameters:
// bool                                    Result                                                 (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor)
// class FText                             BusyMessage_0                                          (Parm, OutParm)

void AINTERACT_Lift_Base_C::GetInteractBusy(bool* Result, class FText* BusyMessage_0)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("INTERACT_Lift_Base_C", "GetInteractBusy");

	Params::INTERACT_Lift_Base_C_GetInteractBusy Parms{};

	UObject::ProcessEvent(Func, &Parms);

	if (Result != nullptr)
		*Result = Parms.Result;

	if (BusyMessage_0 != nullptr)
		*BusyMessage_0 = std::move(Parms.BusyMessage_0);
}


// Function INTERACT_Lift_Base.INTERACT_Lift_Base_C.IsLiftMoving
// (Public, HasOutParams, BlueprintCallable, BlueprintEvent, BlueprintPure)
// Parameters:
// bool                                    Result                                                 (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor)

void AINTERACT_Lift_Base_C::IsLiftMoving(bool* Result)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("INTERACT_Lift_Base_C", "IsLiftMoving");

	Params::INTERACT_Lift_Base_C_IsLiftMoving Parms{};

	UObject::ProcessEvent(Func, &Parms);

	if (Result != nullptr)
		*Result = Parms.Result;
}


// Function INTERACT_Lift_Base.INTERACT_Lift_Base_C.GetMoveDirection
// (Public, HasOutParams, BlueprintCallable, BlueprintEvent, BlueprintPure)
// Parameters:
// struct FVector                          Result                                                 (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void AINTERACT_Lift_Base_C::GetMoveDirection(struct FVector* Result)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("INTERACT_Lift_Base_C", "GetMoveDirection");

	Params::INTERACT_Lift_Base_C_GetMoveDirection Parms{};

	UObject::ProcessEvent(Func, &Parms);

	if (Result != nullptr)
		*Result = std::move(Parms.Result);
}


// Function INTERACT_Lift_Base.INTERACT_Lift_Base_C.GetTargetLocation
// (Public, HasOutParams, BlueprintCallable, BlueprintEvent, BlueprintPure)
// Parameters:
// struct FVector                          Location                                               (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void AINTERACT_Lift_Base_C::GetTargetLocation(struct FVector* Location)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("INTERACT_Lift_Base_C", "GetTargetLocation");

	Params::INTERACT_Lift_Base_C_GetTargetLocation Parms{};

	UObject::ProcessEvent(Func, &Parms);

	if (Location != nullptr)
		*Location = std::move(Parms.Location);
}


// Function INTERACT_Lift_Base.INTERACT_Lift_Base_C.GetTargetRotation
// (Public, HasOutParams, BlueprintCallable, BlueprintEvent, BlueprintPure)
// Parameters:
// struct FRotator                         Rotation                                               (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor)

void AINTERACT_Lift_Base_C::GetTargetRotation(struct FRotator* Rotation)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("INTERACT_Lift_Base_C", "GetTargetRotation");

	Params::INTERACT_Lift_Base_C_GetTargetRotation Parms{};

	UObject::ProcessEvent(Func, &Parms);

	if (Rotation != nullptr)
		*Rotation = std::move(Parms.Rotation);
}


// Function INTERACT_Lift_Base.INTERACT_Lift_Base_C.IsInteractActivated
// (Public, HasOutParams, BlueprintCallable, BlueprintEvent)
// Parameters:
// bool                                    Result                                                 (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor)

void AINTERACT_Lift_Base_C::IsInteractActivated(bool* Result)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("INTERACT_Lift_Base_C", "IsInteractActivated");

	Params::INTERACT_Lift_Base_C_IsInteractActivated Parms{};

	UObject::ProcessEvent(Func, &Parms);

	if (Result != nullptr)
		*Result = Parms.Result;
}


// Function INTERACT_Lift_Base.INTERACT_Lift_Base_C.EVENT_OnDisableAttribChanged
// (Private, HasDefaults, BlueprintCallable, BlueprintEvent)
// Parameters:
// float                                   CurrValue                                              (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// float                                   LastValue                                              (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void AINTERACT_Lift_Base_C::EVENT_OnDisableAttribChanged(float CurrValue, float LastValue)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("INTERACT_Lift_Base_C", "EVENT_OnDisableAttribChanged");

	Params::INTERACT_Lift_Base_C_EVENT_OnDisableAttribChanged Parms{};

	Parms.CurrValue = CurrValue;
	Parms.LastValue = LastValue;

	UObject::ProcessEvent(Func, &Parms);
}


// Function INTERACT_Lift_Base.INTERACT_Lift_Base_C.GetCurrentMovementTime
// (Public, HasOutParams, BlueprintCallable, BlueprintEvent, BlueprintPure)
// Parameters:
// float                                   Result                                                 (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void AINTERACT_Lift_Base_C::GetCurrentMovementTime(float* Result)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("INTERACT_Lift_Base_C", "GetCurrentMovementTime");

	Params::INTERACT_Lift_Base_C_GetCurrentMovementTime Parms{};

	UObject::ProcessEvent(Func, &Parms);

	if (Result != nullptr)
		*Result = Parms.Result;
}

}

