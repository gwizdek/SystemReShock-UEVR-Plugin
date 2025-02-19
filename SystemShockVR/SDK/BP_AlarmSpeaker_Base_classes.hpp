#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: BP_AlarmSpeaker_Base

#include "Basic.hpp"

#include "Engine_structs.hpp"
#include "Engine_classes.hpp"


namespace SDK
{

// BlueprintGeneratedClass BP_AlarmSpeaker_Base.BP_AlarmSpeaker_Base_C
// 0x0068 (0x0288 - 0x0220)
class ABP_AlarmSpeaker_Base_C : public AActor
{
public:
	struct FPointerToUberGraphFrame               UberGraphFrame;                                    // 0x0220(0x0008)(ZeroConstructor, Transient, DuplicateTransient)
	class UCOMP_VoxelCullable_C*                  COMP_VoxelCullable;                                // 0x0228(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NonTransactional, NoDestructor, HasGetValueTypeHash)
	class UStaticMeshComponent*                   StaticMesh;                                        // 0x0230(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NonTransactional, NoDestructor, HasGetValueTypeHash)
	bool                                          IsAlarmAudible;                                    // 0x0238(0x0001)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor)
	bool                                          IsAlarmActivated;                                  // 0x0239(0x0001)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor)
	uint8                                         Pad_23A[0x6];                                      // 0x023A(0x0006)(Fixing Size After Last Property [ Dumper-7 ])
	TSoftObjectPtr<class USoundCue>               EmergencySoundCue;                                 // 0x0240(0x0028)(Edit, BlueprintVisible, DisableEditOnInstance, HasGetValueTypeHash)
	struct FDataTableRowHandle                    RequiredStoryQuest;                                // 0x0268(0x0010)(Edit, BlueprintVisible, NoDestructor)
	struct FDataTableRowHandle                    DisableStoryQuest;                                 // 0x0278(0x0010)(Edit, BlueprintVisible, NoDestructor)

public:
	void ExecuteUbergraph_BP_AlarmSpeaker_Base(int32 EntryPoint);
	void ReceiveBeginPlay();
	void BndEvt__BP_AlarmLight_COMP_VoxelCullable_K2Node_ComponentBoundEvent_1_CullableAudibilitySignature__DelegateSignature(bool bAudibleState);
	void IsAlarmFunctional(bool* Result);
	void InitializeAlarmSpeaker();
	void OnAlarmActivated();
	void TryUpdateAudibleBehavior();
	void UpdateAlarmSpeakerAudibility(bool AudibilityState);
	void PlayEmergencySound();
	void EVENT_OnStoryQuestChanged(class FName StoryQuestName, bool Value);
	void IsAlarmActive(bool* Result);
	void GetAlarmSpeakerPosition(struct FVector* Result);

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"BP_AlarmSpeaker_Base_C">();
	}
	static class ABP_AlarmSpeaker_Base_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<ABP_AlarmSpeaker_Base_C>();
	}
};
static_assert(alignof(ABP_AlarmSpeaker_Base_C) == 0x000008, "Wrong alignment on ABP_AlarmSpeaker_Base_C");
static_assert(sizeof(ABP_AlarmSpeaker_Base_C) == 0x000288, "Wrong size on ABP_AlarmSpeaker_Base_C");
static_assert(offsetof(ABP_AlarmSpeaker_Base_C, UberGraphFrame) == 0x000220, "Member 'ABP_AlarmSpeaker_Base_C::UberGraphFrame' has a wrong offset!");
static_assert(offsetof(ABP_AlarmSpeaker_Base_C, COMP_VoxelCullable) == 0x000228, "Member 'ABP_AlarmSpeaker_Base_C::COMP_VoxelCullable' has a wrong offset!");
static_assert(offsetof(ABP_AlarmSpeaker_Base_C, StaticMesh) == 0x000230, "Member 'ABP_AlarmSpeaker_Base_C::StaticMesh' has a wrong offset!");
static_assert(offsetof(ABP_AlarmSpeaker_Base_C, IsAlarmAudible) == 0x000238, "Member 'ABP_AlarmSpeaker_Base_C::IsAlarmAudible' has a wrong offset!");
static_assert(offsetof(ABP_AlarmSpeaker_Base_C, IsAlarmActivated) == 0x000239, "Member 'ABP_AlarmSpeaker_Base_C::IsAlarmActivated' has a wrong offset!");
static_assert(offsetof(ABP_AlarmSpeaker_Base_C, EmergencySoundCue) == 0x000240, "Member 'ABP_AlarmSpeaker_Base_C::EmergencySoundCue' has a wrong offset!");
static_assert(offsetof(ABP_AlarmSpeaker_Base_C, RequiredStoryQuest) == 0x000268, "Member 'ABP_AlarmSpeaker_Base_C::RequiredStoryQuest' has a wrong offset!");
static_assert(offsetof(ABP_AlarmSpeaker_Base_C, DisableStoryQuest) == 0x000278, "Member 'ABP_AlarmSpeaker_Base_C::DisableStoryQuest' has a wrong offset!");

}

