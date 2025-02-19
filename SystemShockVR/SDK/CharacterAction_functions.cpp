#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: CharacterAction

#include "Basic.hpp"

#include "CharacterAction_classes.hpp"
#include "CharacterAction_parameters.hpp"


namespace SDK
{

// Function CharacterAction.CharacterAction_C.OnActionInterruptible__DelegateSignature
// (Public, Delegate, BlueprintCallable, BlueprintEvent)

void UCharacterAction_C::OnActionInterruptible__DelegateSignature()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("CharacterAction_C", "OnActionInterruptible__DelegateSignature");

	UObject::ProcessEvent(Func, nullptr);
}


// Function CharacterAction.CharacterAction_C.OnActionInterrupted__DelegateSignature
// (Public, Delegate, BlueprintCallable, BlueprintEvent)

void UCharacterAction_C::OnActionInterrupted__DelegateSignature()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("CharacterAction_C", "OnActionInterrupted__DelegateSignature");

	UObject::ProcessEvent(Func, nullptr);
}


// Function CharacterAction.CharacterAction_C.OnActionEnded__DelegateSignature
// (Public, Delegate, BlueprintCallable, BlueprintEvent)

void UCharacterAction_C::OnActionEnded__DelegateSignature()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("CharacterAction_C", "OnActionEnded__DelegateSignature");

	UObject::ProcessEvent(Func, nullptr);
}


// Function CharacterAction.CharacterAction_C.InitializeAction
// (Public, BlueprintCallable, BlueprintEvent)
// Parameters:
// class UCOMP_ActionManager_C*            Manager                                                (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// class APAWN_SystemShockCharacter_C*     Owner                                                  (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UCharacterAction_C::InitializeAction(class UCOMP_ActionManager_C* Manager, class APAWN_SystemShockCharacter_C* Owner)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("CharacterAction_C", "InitializeAction");

	Params::CharacterAction_C_InitializeAction Parms{};

	Parms.Manager = Manager;
	Parms.Owner = Owner;

	UObject::ProcessEvent(Func, &Parms);
}


// Function CharacterAction.CharacterAction_C.IsInterruptibleAtPriority
// (Public, HasOutParams, BlueprintCallable, BlueprintEvent, BlueprintPure)
// Parameters:
// ENUM_ActionPriority                     InterruptPriority                                      (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// bool                                    Result                                                 (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor)

void UCharacterAction_C::IsInterruptibleAtPriority(ENUM_ActionPriority InterruptPriority, bool* Result)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("CharacterAction_C", "IsInterruptibleAtPriority");

	Params::CharacterAction_C_IsInterruptibleAtPriority Parms{};

	Parms.InterruptPriority = InterruptPriority;

	UObject::ProcessEvent(Func, &Parms);

	if (Result != nullptr)
		*Result = Parms.Result;
}


// Function CharacterAction.CharacterAction_C.PlayMontage
// (Public, HasOutParams, BlueprintCallable, BlueprintEvent)
// Parameters:
// float                                   PlayRate                                               (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// float                                   MontageDuration_0                                      (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UCharacterAction_C::PlayMontage(float PlayRate, float* MontageDuration_0)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("CharacterAction_C", "PlayMontage");

	Params::CharacterAction_C_PlayMontage Parms{};

	Parms.PlayRate = PlayRate;

	UObject::ProcessEvent(Func, &Parms);

	if (MontageDuration_0 != nullptr)
		*MontageDuration_0 = Parms.MontageDuration_0;
}


// Function CharacterAction.CharacterAction_C.ResumeMontage
// (Public, HasOutParams, BlueprintCallable, BlueprintEvent)
// Parameters:
// float                                   PlayRate                                               (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// float                                   MontageDuration_0                                      (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UCharacterAction_C::ResumeMontage(float PlayRate, float* MontageDuration_0)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("CharacterAction_C", "ResumeMontage");

	Params::CharacterAction_C_ResumeMontage Parms{};

	Parms.PlayRate = PlayRate;

	UObject::ProcessEvent(Func, &Parms);

	if (MontageDuration_0 != nullptr)
		*MontageDuration_0 = Parms.MontageDuration_0;
}


// Function CharacterAction.CharacterAction_C.StopMontage
// (Public, BlueprintCallable, BlueprintEvent)
// Parameters:
// float                                   BlendOutTime                                           (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UCharacterAction_C::StopMontage(float BlendOutTime)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("CharacterAction_C", "StopMontage");

	Params::CharacterAction_C_StopMontage Parms{};

	Parms.BlendOutTime = BlendOutTime;

	UObject::ProcessEvent(Func, &Parms);
}


// Function CharacterAction.CharacterAction_C.SetMontageWithPriority
// (Public, BlueprintCallable, BlueprintEvent)
// Parameters:
// class UAnimMontage*                     Montage_0                                              (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// ENUM_ActionPriority                     Priority_0                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UCharacterAction_C::SetMontageWithPriority(class UAnimMontage* Montage_0, ENUM_ActionPriority Priority_0)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("CharacterAction_C", "SetMontageWithPriority");

	Params::CharacterAction_C_SetMontageWithPriority Parms{};

	Parms.Montage_0 = Montage_0;
	Parms.Priority_0 = Priority_0;

	UObject::ProcessEvent(Func, &Parms);
}


// Function CharacterAction.CharacterAction_C.SetElapsedTime
// (Public, HasOutParams, BlueprintCallable, BlueprintEvent)
// Parameters:
// float                                   NewElapsedTime                                         (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// bool                                    IsFinished                                             (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor)

void UCharacterAction_C::SetElapsedTime(float NewElapsedTime, bool* IsFinished)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("CharacterAction_C", "SetElapsedTime");

	Params::CharacterAction_C_SetElapsedTime Parms{};

	Parms.NewElapsedTime = NewElapsedTime;

	UObject::ProcessEvent(Func, &Parms);

	if (IsFinished != nullptr)
		*IsFinished = Parms.IsFinished;
}


// Function CharacterAction.CharacterAction_C.GetElapsedPlayTime
// (Public, HasOutParams, BlueprintCallable, BlueprintEvent, BlueprintPure)
// Parameters:
// float                                   Result                                                 (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UCharacterAction_C::GetElapsedPlayTime(float* Result)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("CharacterAction_C", "GetElapsedPlayTime");

	Params::CharacterAction_C_GetElapsedPlayTime Parms{};

	UObject::ProcessEvent(Func, &Parms);

	if (Result != nullptr)
		*Result = Parms.Result;
}


// Function CharacterAction.CharacterAction_C.GetProgress
// (Public, HasOutParams, BlueprintCallable, BlueprintEvent, BlueprintPure)
// Parameters:
// float                                   Progress                                               (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UCharacterAction_C::GetProgress(float* Progress)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("CharacterAction_C", "GetProgress");

	Params::CharacterAction_C_GetProgress Parms{};

	UObject::ProcessEvent(Func, &Parms);

	if (Progress != nullptr)
		*Progress = Parms.Progress;
}


// Function CharacterAction.CharacterAction_C.IsActive
// (Public, HasOutParams, BlueprintCallable, BlueprintEvent, BlueprintPure)
// Parameters:
// bool                                    Result                                                 (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor)

void UCharacterAction_C::IsActive(bool* Result)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("CharacterAction_C", "IsActive");

	Params::CharacterAction_C_IsActive Parms{};

	UObject::ProcessEvent(Func, &Parms);

	if (Result != nullptr)
		*Result = Parms.Result;
}


// Function CharacterAction.CharacterAction_C.GetMontage
// (Public, HasOutParams, BlueprintCallable, BlueprintEvent, BlueprintPure)
// Parameters:
// class UAnimMontage*                     Result                                                 (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UCharacterAction_C::GetMontage(class UAnimMontage** Result)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("CharacterAction_C", "GetMontage");

	Params::CharacterAction_C_GetMontage Parms{};

	UObject::ProcessEvent(Func, &Parms);

	if (Result != nullptr)
		*Result = Parms.Result;
}


// Function CharacterAction.CharacterAction_C.GetPriority
// (Public, HasOutParams, BlueprintCallable, BlueprintEvent, BlueprintPure)
// Parameters:
// ENUM_ActionPriority                     Result                                                 (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UCharacterAction_C::GetPriority(ENUM_ActionPriority* Result)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("CharacterAction_C", "GetPriority");

	Params::CharacterAction_C_GetPriority Parms{};

	UObject::ProcessEvent(Func, &Parms);

	if (Result != nullptr)
		*Result = Parms.Result;
}


// Function CharacterAction.CharacterAction_C.SetPriority
// (Public, BlueprintCallable, BlueprintEvent)
// Parameters:
// ENUM_ActionPriority                     NewPriority                                            (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UCharacterAction_C::SetPriority(ENUM_ActionPriority NewPriority)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("CharacterAction_C", "SetPriority");

	Params::CharacterAction_C_SetPriority Parms{};

	Parms.NewPriority = NewPriority;

	UObject::ProcessEvent(Func, &Parms);
}

}

