#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: TRAP_BossEncounter

#include "Basic.hpp"

#include "Engine_structs.hpp"
#include "ENUM_EncounterLockType_structs.hpp"
#include "CoreUObject_structs.hpp"
#include "TRAP_Trigger_classes.hpp"
#include "AttributeSystem_structs.hpp"


namespace SDK
{

// BlueprintGeneratedClass TRAP_BossEncounter.TRAP_BossEncounter_C
// 0x00D0 (0x0440 - 0x0370)
class ATRAP_BossEncounter_C final : public ATRAP_Trigger_C
{
public:
	ENUM_EncounterLockType                        LockTypeAfterEncounter;                            // 0x0370(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_371[0x7];                                      // 0x0371(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	TArray<class AINTERACT_Base_C*>               LockInteractsDuringEncounter;                      // 0x0378(0x0010)(Edit, BlueprintVisible, DisableEditOnTemplate)
	TArray<class AEnemySpawnPoint_C*>             EnemySpawnPoints;                                  // 0x0388(0x0010)(Edit, BlueprintVisible, DisableEditOnTemplate)
	TArray<class APAWN_Enemy_C*>                  SpawnedEnemies;                                    // 0x0398(0x0010)(Edit, BlueprintVisible, DisableEditOnTemplate, DisableEditOnInstance, SaveGame)
	TArray<struct FAttribModApplyData>            EnemyApplyMods;                                    // 0x03A8(0x0010)(Edit, BlueprintVisible)
	TArray<struct FDataTableRowHandle>            EncounterFinishedGameEvents;                       // 0x03B8(0x0010)(Edit, BlueprintVisible)
	TSet<class AINTERACT_Base_C*>                 LockedInteracts;                                   // 0x03C8(0x0050)(Edit, BlueprintVisible, DisableEditOnTemplate, DisableEditOnInstance, SaveGame)
	class UMOVECONTROL_BossCutscene_C*            CutsceneMoveControl;                               // 0x0418(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FVector                                CutsceneFocusOffset;                               // 0x0420(0x000C)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_42C[0x4];                                      // 0x042C(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	TArray<class ATriggerVolume*>                 BehaviorPatternVolumes;                            // 0x0430(0x0010)(Edit, BlueprintVisible, DisableEditOnTemplate)

public:
	void InitializeTrap();
	void OnSpringTrap(class APAWN_Hacker_Simple_C* Hacker);
	void OnRemoveSpawnedEnemy(class APAWN_Enemy_C* Enemy);
	void OnEncounterFinished();
	void EVENT_OnSpawnedEnemyDied(class APAWN_SystemShockCharacter_C* Character);
	void TryBindSpawnEnemyDiedEvents(bool* Result);
	void EVENT_OnSpawnedEnemyDestroyed(class AActor* DestroyedActor);
	void TryLockInteractBeforeEncounter(class AINTERACT_Base_C* Interact);
	void TryUnlockInteractAfterEncounter(class AINTERACT_Base_C* Interact);
	void UpdateCutsceneArmorMod(bool State);
	void StartCutsceneCamera();
	void StopCutsceneCamera(class UMOVECONTROL_Base_C* MoveControl);
	void HasSpawnedEnemy(class APAWN_Enemy_C* EnemyPawn, bool* Result);
	void GetBossVolumesWithTag(class FName Tag, TArray<class ATriggerVolume*>* Results);

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"TRAP_BossEncounter_C">();
	}
	static class ATRAP_BossEncounter_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<ATRAP_BossEncounter_C>();
	}
};
static_assert(alignof(ATRAP_BossEncounter_C) == 0x000008, "Wrong alignment on ATRAP_BossEncounter_C");
static_assert(sizeof(ATRAP_BossEncounter_C) == 0x000440, "Wrong size on ATRAP_BossEncounter_C");
static_assert(offsetof(ATRAP_BossEncounter_C, LockTypeAfterEncounter) == 0x000370, "Member 'ATRAP_BossEncounter_C::LockTypeAfterEncounter' has a wrong offset!");
static_assert(offsetof(ATRAP_BossEncounter_C, LockInteractsDuringEncounter) == 0x000378, "Member 'ATRAP_BossEncounter_C::LockInteractsDuringEncounter' has a wrong offset!");
static_assert(offsetof(ATRAP_BossEncounter_C, EnemySpawnPoints) == 0x000388, "Member 'ATRAP_BossEncounter_C::EnemySpawnPoints' has a wrong offset!");
static_assert(offsetof(ATRAP_BossEncounter_C, SpawnedEnemies) == 0x000398, "Member 'ATRAP_BossEncounter_C::SpawnedEnemies' has a wrong offset!");
static_assert(offsetof(ATRAP_BossEncounter_C, EnemyApplyMods) == 0x0003A8, "Member 'ATRAP_BossEncounter_C::EnemyApplyMods' has a wrong offset!");
static_assert(offsetof(ATRAP_BossEncounter_C, EncounterFinishedGameEvents) == 0x0003B8, "Member 'ATRAP_BossEncounter_C::EncounterFinishedGameEvents' has a wrong offset!");
static_assert(offsetof(ATRAP_BossEncounter_C, LockedInteracts) == 0x0003C8, "Member 'ATRAP_BossEncounter_C::LockedInteracts' has a wrong offset!");
static_assert(offsetof(ATRAP_BossEncounter_C, CutsceneMoveControl) == 0x000418, "Member 'ATRAP_BossEncounter_C::CutsceneMoveControl' has a wrong offset!");
static_assert(offsetof(ATRAP_BossEncounter_C, CutsceneFocusOffset) == 0x000420, "Member 'ATRAP_BossEncounter_C::CutsceneFocusOffset' has a wrong offset!");
static_assert(offsetof(ATRAP_BossEncounter_C, BehaviorPatternVolumes) == 0x000430, "Member 'ATRAP_BossEncounter_C::BehaviorPatternVolumes' has a wrong offset!");

}

