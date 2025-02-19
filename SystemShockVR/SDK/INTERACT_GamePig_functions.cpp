#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: INTERACT_GamePig

#include "Basic.hpp"

#include "INTERACT_GamePig_classes.hpp"
#include "INTERACT_GamePig_parameters.hpp"


namespace SDK
{

// Function INTERACT_GamePig.INTERACT_GamePig_C.ExecuteUbergraph_INTERACT_GamePig
// (Final, UbergraphFunction)
// Parameters:
// int32                                   EntryPoint                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void AINTERACT_GamePig_C::ExecuteUbergraph_INTERACT_GamePig(int32 EntryPoint)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("INTERACT_GamePig_C", "ExecuteUbergraph_INTERACT_GamePig");

	Params::INTERACT_GamePig_C_ExecuteUbergraph_INTERACT_GamePig Parms{};

	Parms.EntryPoint = EntryPoint;

	UObject::ProcessEvent(Func, &Parms);
}


// Function INTERACT_GamePig.INTERACT_GamePig_C.ReceiveBeginPlay
// (Event, Protected, BlueprintEvent)

void AINTERACT_GamePig_C::ReceiveBeginPlay()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("INTERACT_GamePig_C", "ReceiveBeginPlay");

	UObject::ProcessEvent(Func, nullptr);
}


// Function INTERACT_GamePig.INTERACT_GamePig_C.ReceiveTick
// (Event, Public, BlueprintEvent)
// Parameters:
// float                                   DeltaSeconds                                           (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void AINTERACT_GamePig_C::ReceiveTick(float DeltaSeconds)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("INTERACT_GamePig_C", "ReceiveTick");

	Params::INTERACT_GamePig_C_ReceiveTick Parms{};

	Parms.DeltaSeconds = DeltaSeconds;

	UObject::ProcessEvent(Func, &Parms);
}


// Function INTERACT_GamePig.INTERACT_GamePig_C.InitializeGamePigMaterials
// (Protected, BlueprintCallable, BlueprintEvent)

void AINTERACT_GamePig_C::InitializeGamePigMaterials()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("INTERACT_GamePig_C", "InitializeGamePigMaterials");

	UObject::ProcessEvent(Func, nullptr);
}


// Function INTERACT_GamePig.INTERACT_GamePig_C.CreateGamepigSplashScreen
// (Protected, HasDefaults, BlueprintCallable, BlueprintEvent)

void AINTERACT_GamePig_C::CreateGamepigSplashScreen()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("INTERACT_GamePig_C", "CreateGamepigSplashScreen");

	UObject::ProcessEvent(Func, nullptr);
}


// Function INTERACT_GamePig.INTERACT_GamePig_C.CreateMinigameLevel
// (Public, HasOutParams, HasDefaults, BlueprintCallable, BlueprintEvent)
// Parameters:
// bool                                    Result                                                 (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor)

void AINTERACT_GamePig_C::CreateMinigameLevel(bool* Result)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("INTERACT_GamePig_C", "CreateMinigameLevel");

	Params::INTERACT_GamePig_C_CreateMinigameLevel Parms{};

	UObject::ProcessEvent(Func, &Parms);

	if (Result != nullptr)
		*Result = Parms.Result;
}


// Function INTERACT_GamePig.INTERACT_GamePig_C.TogglePowerLED
// (Public, BlueprintCallable, BlueprintEvent)

void AINTERACT_GamePig_C::TogglePowerLED()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("INTERACT_GamePig_C", "TogglePowerLED");

	UObject::ProcessEvent(Func, nullptr);
}


// Function INTERACT_GamePig.INTERACT_GamePig_C.PlayMinigameSound
// (Public, HasOutParams, BlueprintCallable, BlueprintEvent)
// Parameters:
// class USoundCue*                        SoundCue                                               (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// class UAudioComponent*                  AudioComponent                                         (Parm, OutParm, ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void AINTERACT_GamePig_C::PlayMinigameSound(class USoundCue* SoundCue, class UAudioComponent** AudioComponent)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("INTERACT_GamePig_C", "PlayMinigameSound");

	Params::INTERACT_GamePig_C_PlayMinigameSound Parms{};

	Parms.SoundCue = SoundCue;

	UObject::ProcessEvent(Func, &Parms);

	if (AudioComponent != nullptr)
		*AudioComponent = Parms.AudioComponent;
}


// Function INTERACT_GamePig.INTERACT_GamePig_C.UpdateMaterials
// (Protected, BlueprintCallable, BlueprintEvent)
// Parameters:
// float                                   DeltaTime                                              (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void AINTERACT_GamePig_C::UpdateMaterials(float DeltaTime)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("INTERACT_GamePig_C", "UpdateMaterials");

	Params::INTERACT_GamePig_C_UpdateMaterials Parms{};

	Parms.DeltaTime = DeltaTime;

	UObject::ProcessEvent(Func, &Parms);
}


// Function INTERACT_GamePig.INTERACT_GamePig_C.UpdateTransition
// (Protected, HasDefaults, BlueprintCallable, BlueprintEvent)

void AINTERACT_GamePig_C::UpdateTransition()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("INTERACT_GamePig_C", "UpdateTransition");

	UObject::ProcessEvent(Func, nullptr);
}


// Function INTERACT_GamePig.INTERACT_GamePig_C.StopPlayingGamePig
// (Public, HasDefaults, BlueprintCallable, BlueprintEvent)

void AINTERACT_GamePig_C::StopPlayingGamePig()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("INTERACT_GamePig_C", "StopPlayingGamePig");

	UObject::ProcessEvent(Func, nullptr);
}


// Function INTERACT_GamePig.INTERACT_GamePig_C.GetHolsteredTransform
// (Public, HasOutParams, HasDefaults, BlueprintCallable, BlueprintEvent, BlueprintPure)
// Parameters:
// struct FTransform                       Transform                                              (Parm, OutParm, IsPlainOldData, NoDestructor)

void AINTERACT_GamePig_C::GetHolsteredTransform(struct FTransform* Transform)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("INTERACT_GamePig_C", "GetHolsteredTransform");

	Params::INTERACT_GamePig_C_GetHolsteredTransform Parms{};

	UObject::ProcessEvent(Func, &Parms);

	if (Transform != nullptr)
		*Transform = std::move(Parms.Transform);
}


// Function INTERACT_GamePig.INTERACT_GamePig_C.CanResumeChannelingInteraction
// (Public, HasOutParams, BlueprintCallable, BlueprintEvent, BlueprintPure)
// Parameters:
// bool                                    Result                                                 (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor)

void AINTERACT_GamePig_C::CanResumeChannelingInteraction(bool* Result)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("INTERACT_GamePig_C", "CanResumeChannelingInteraction");

	Params::INTERACT_GamePig_C_CanResumeChannelingInteraction Parms{};

	UObject::ProcessEvent(Func, &Parms);

	if (Result != nullptr)
		*Result = Parms.Result;
}


// Function INTERACT_GamePig.INTERACT_GamePig_C.GetTargetShape
// (Public, HasOutParams, BlueprintCallable, BlueprintEvent)
// Parameters:
// class UPrimitiveComponent*              CursorPrimitive                                        (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// class UShapeComponent*                  ShapeComponent                                         (Parm, OutParm, ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void AINTERACT_GamePig_C::GetTargetShape(class UPrimitiveComponent* CursorPrimitive, class UShapeComponent** ShapeComponent)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("INTERACT_GamePig_C", "GetTargetShape");

	Params::INTERACT_GamePig_C_GetTargetShape Parms{};

	Parms.CursorPrimitive = CursorPrimitive;

	UObject::ProcessEvent(Func, &Parms);

	if (ShapeComponent != nullptr)
		*ShapeComponent = Parms.ShapeComponent;
}


// Function INTERACT_GamePig.INTERACT_GamePig_C.StopChanneling
// (Public, HasOutParams, BlueprintCallable, BlueprintEvent)
// Parameters:
// class AActor*                           NewChannelingInteract                                  (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// bool                                    Result                                                 (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor)

void AINTERACT_GamePig_C::StopChanneling(class AActor* NewChannelingInteract, bool* Result)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("INTERACT_GamePig_C", "StopChanneling");

	Params::INTERACT_GamePig_C_StopChanneling Parms{};

	Parms.NewChannelingInteract = NewChannelingInteract;

	UObject::ProcessEvent(Func, &Parms);

	if (Result != nullptr)
		*Result = Parms.Result;
}


// Function INTERACT_GamePig.INTERACT_GamePig_C.TryInteract
// (Public, HasOutParams, HasDefaults, BlueprintCallable, BlueprintEvent)
// Parameters:
// class AActor*                           SourceActor                                            (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// class UPrimitiveComponent*              CursorPrimitive                                        (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// ENUM_InteractionType                    InteractionType                                        (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// struct FSTRUCT_InteractResults          InteractResults                                        (Parm, OutParm, HasGetValueTypeHash)

void AINTERACT_GamePig_C::TryInteract(class AActor* SourceActor, class UPrimitiveComponent* CursorPrimitive, ENUM_InteractionType InteractionType, struct FSTRUCT_InteractResults* InteractResults)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("INTERACT_GamePig_C", "TryInteract");

	Params::INTERACT_GamePig_C_TryInteract Parms{};

	Parms.SourceActor = SourceActor;
	Parms.CursorPrimitive = CursorPrimitive;
	Parms.InteractionType = InteractionType;

	UObject::ProcessEvent(Func, &Parms);

	if (InteractResults != nullptr)
		*InteractResults = std::move(Parms.InteractResults);
}

}

