#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: TRAP_BossEncounter

#include "Basic.hpp"

#include "TRAP_BossEncounter_classes.hpp"
#include "TRAP_BossEncounter_parameters.hpp"


namespace SDK
{

// Function TRAP_BossEncounter.TRAP_BossEncounter_C.InitializeTrap
// (Protected, BlueprintCallable, BlueprintEvent)

void ATRAP_BossEncounter_C::InitializeTrap()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("TRAP_BossEncounter_C", "InitializeTrap");

	UObject::ProcessEvent(Func, nullptr);
}


// Function TRAP_BossEncounter.TRAP_BossEncounter_C.OnSpringTrap
// (Protected, HasDefaults, BlueprintCallable, BlueprintEvent)
// Parameters:
// class APAWN_Hacker_Simple_C*            Hacker                                                 (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void ATRAP_BossEncounter_C::OnSpringTrap(class APAWN_Hacker_Simple_C* Hacker)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("TRAP_BossEncounter_C", "OnSpringTrap");

	Params::TRAP_BossEncounter_C_OnSpringTrap Parms{};

	Parms.Hacker = Hacker;

	UObject::ProcessEvent(Func, &Parms);
}


// Function TRAP_BossEncounter.TRAP_BossEncounter_C.OnRemoveSpawnedEnemy
// (Protected, BlueprintCallable, BlueprintEvent)
// Parameters:
// class APAWN_Enemy_C*                    Enemy                                                  (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void ATRAP_BossEncounter_C::OnRemoveSpawnedEnemy(class APAWN_Enemy_C* Enemy)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("TRAP_BossEncounter_C", "OnRemoveSpawnedEnemy");

	Params::TRAP_BossEncounter_C_OnRemoveSpawnedEnemy Parms{};

	Parms.Enemy = Enemy;

	UObject::ProcessEvent(Func, &Parms);
}


// Function TRAP_BossEncounter.TRAP_BossEncounter_C.OnEncounterFinished
// (Protected, HasDefaults, BlueprintCallable, BlueprintEvent)

void ATRAP_BossEncounter_C::OnEncounterFinished()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("TRAP_BossEncounter_C", "OnEncounterFinished");

	UObject::ProcessEvent(Func, nullptr);
}


// Function TRAP_BossEncounter.TRAP_BossEncounter_C.EVENT_OnSpawnedEnemyDied
// (Private, BlueprintCallable, BlueprintEvent)
// Parameters:
// class APAWN_SystemShockCharacter_C*     Character                                              (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void ATRAP_BossEncounter_C::EVENT_OnSpawnedEnemyDied(class APAWN_SystemShockCharacter_C* Character)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("TRAP_BossEncounter_C", "EVENT_OnSpawnedEnemyDied");

	Params::TRAP_BossEncounter_C_EVENT_OnSpawnedEnemyDied Parms{};

	Parms.Character = Character;

	UObject::ProcessEvent(Func, &Parms);
}


// Function TRAP_BossEncounter.TRAP_BossEncounter_C.TryBindSpawnEnemyDiedEvents
// (Protected, HasOutParams, BlueprintCallable, BlueprintEvent)
// Parameters:
// bool                                    Result                                                 (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor)

void ATRAP_BossEncounter_C::TryBindSpawnEnemyDiedEvents(bool* Result)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("TRAP_BossEncounter_C", "TryBindSpawnEnemyDiedEvents");

	Params::TRAP_BossEncounter_C_TryBindSpawnEnemyDiedEvents Parms{};

	UObject::ProcessEvent(Func, &Parms);

	if (Result != nullptr)
		*Result = Parms.Result;
}


// Function TRAP_BossEncounter.TRAP_BossEncounter_C.EVENT_OnSpawnedEnemyDestroyed
// (Private, BlueprintCallable, BlueprintEvent)
// Parameters:
// class AActor*                           DestroyedActor                                         (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void ATRAP_BossEncounter_C::EVENT_OnSpawnedEnemyDestroyed(class AActor* DestroyedActor)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("TRAP_BossEncounter_C", "EVENT_OnSpawnedEnemyDestroyed");

	Params::TRAP_BossEncounter_C_EVENT_OnSpawnedEnemyDestroyed Parms{};

	Parms.DestroyedActor = DestroyedActor;

	UObject::ProcessEvent(Func, &Parms);
}


// Function TRAP_BossEncounter.TRAP_BossEncounter_C.TryLockInteractBeforeEncounter
// (Private, HasDefaults, BlueprintCallable, BlueprintEvent)
// Parameters:
// class AINTERACT_Base_C*                 Interact                                               (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void ATRAP_BossEncounter_C::TryLockInteractBeforeEncounter(class AINTERACT_Base_C* Interact)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("TRAP_BossEncounter_C", "TryLockInteractBeforeEncounter");

	Params::TRAP_BossEncounter_C_TryLockInteractBeforeEncounter Parms{};

	Parms.Interact = Interact;

	UObject::ProcessEvent(Func, &Parms);
}


// Function TRAP_BossEncounter.TRAP_BossEncounter_C.TryUnlockInteractAfterEncounter
// (Private, HasDefaults, BlueprintCallable, BlueprintEvent)
// Parameters:
// class AINTERACT_Base_C*                 Interact                                               (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void ATRAP_BossEncounter_C::TryUnlockInteractAfterEncounter(class AINTERACT_Base_C* Interact)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("TRAP_BossEncounter_C", "TryUnlockInteractAfterEncounter");

	Params::TRAP_BossEncounter_C_TryUnlockInteractAfterEncounter Parms{};

	Parms.Interact = Interact;

	UObject::ProcessEvent(Func, &Parms);
}


// Function TRAP_BossEncounter.TRAP_BossEncounter_C.UpdateCutsceneArmorMod
// (Public, HasDefaults, BlueprintCallable, BlueprintEvent)
// Parameters:
// bool                                    State                                                  (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor)

void ATRAP_BossEncounter_C::UpdateCutsceneArmorMod(bool State)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("TRAP_BossEncounter_C", "UpdateCutsceneArmorMod");

	Params::TRAP_BossEncounter_C_UpdateCutsceneArmorMod Parms{};

	Parms.State = State;

	UObject::ProcessEvent(Func, &Parms);
}


// Function TRAP_BossEncounter.TRAP_BossEncounter_C.StartCutsceneCamera
// (Protected, BlueprintCallable, BlueprintEvent)

void ATRAP_BossEncounter_C::StartCutsceneCamera()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("TRAP_BossEncounter_C", "StartCutsceneCamera");

	UObject::ProcessEvent(Func, nullptr);
}


// Function TRAP_BossEncounter.TRAP_BossEncounter_C.StopCutsceneCamera
// (Protected, BlueprintCallable, BlueprintEvent)
// Parameters:
// class UMOVECONTROL_Base_C*              MoveControl                                            (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void ATRAP_BossEncounter_C::StopCutsceneCamera(class UMOVECONTROL_Base_C* MoveControl)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("TRAP_BossEncounter_C", "StopCutsceneCamera");

	Params::TRAP_BossEncounter_C_StopCutsceneCamera Parms{};

	Parms.MoveControl = MoveControl;

	UObject::ProcessEvent(Func, &Parms);
}


// Function TRAP_BossEncounter.TRAP_BossEncounter_C.HasSpawnedEnemy
// (Public, HasOutParams, BlueprintCallable, BlueprintEvent, BlueprintPure)
// Parameters:
// class APAWN_Enemy_C*                    EnemyPawn                                              (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// bool                                    Result                                                 (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor)

void ATRAP_BossEncounter_C::HasSpawnedEnemy(class APAWN_Enemy_C* EnemyPawn, bool* Result)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("TRAP_BossEncounter_C", "HasSpawnedEnemy");

	Params::TRAP_BossEncounter_C_HasSpawnedEnemy Parms{};

	Parms.EnemyPawn = EnemyPawn;

	UObject::ProcessEvent(Func, &Parms);

	if (Result != nullptr)
		*Result = Parms.Result;
}


// Function TRAP_BossEncounter.TRAP_BossEncounter_C.GetBossVolumesWithTag
// (Public, HasOutParams, HasDefaults, BlueprintCallable, BlueprintEvent)
// Parameters:
// class FName                             Tag                                                    (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// TArray<class ATriggerVolume*>           Results                                                (Parm, OutParm)

void ATRAP_BossEncounter_C::GetBossVolumesWithTag(class FName Tag, TArray<class ATriggerVolume*>* Results)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("TRAP_BossEncounter_C", "GetBossVolumesWithTag");

	Params::TRAP_BossEncounter_C_GetBossVolumesWithTag Parms{};

	Parms.Tag = Tag;

	UObject::ProcessEvent(Func, &Parms);

	if (Results != nullptr)
		*Results = std::move(Parms.Results);
}

}

