#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: TRIGGER_TauntVolume

#include "Basic.hpp"

#include "Engine_structs.hpp"
#include "INTERACT_Base_classes.hpp"
#include "ENUM_TriggerCondition_structs.hpp"
#include "ENUM_InteractionType_structs.hpp"


namespace SDK
{

// BlueprintGeneratedClass TRIGGER_TauntVolume.TRIGGER_TauntVolume_C
// 0x0050 (0x0358 - 0x0308)
class ATRIGGER_TauntVolume_C final : public AINTERACT_Base_C
{
public:
	struct FPointerToUberGraphFrame               UberGraphFrame_TRIGGER_TauntVolume_C;              // 0x0308(0x0008)(ZeroConstructor, Transient, DuplicateTransient)
	class UBillboardComponent*                    Billboard;                                         // 0x0310(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NonTransactional, NoDestructor, HasGetValueTypeHash)
	class UBoxComponent*                          OverlapBox;                                        // 0x0318(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NonTransactional, NoDestructor, HasGetValueTypeHash)
	struct FDataTableRowHandle                    TauntDataHandle;                                   // 0x0320(0x0010)(Edit, BlueprintVisible, NoDestructor)
	float                                         TauntDelayTime;                                    // 0x0330(0x0004)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         TriggerTimestamp;                                  // 0x0334(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, SaveGame, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	ENUM_TriggerCondition                         TriggerCondition;                                  // 0x0338(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_339[0x7];                                      // 0x0339(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	struct FTimerHandle                           TauntTimerHandle;                                  // 0x0340(0x0008)(Edit, BlueprintVisible, DisableEditOnInstance, NoDestructor, HasGetValueTypeHash)
	struct FDataTableRowHandle                    RequiredQuest;                                     // 0x0348(0x0010)(Edit, BlueprintVisible, NoDestructor)

public:
	void ExecuteUbergraph_TRIGGER_TauntVolume(int32 EntryPoint);
	void BndEvt__TRIGGER_TauntVolume_OverlapBox_K2Node_ComponentBoundEvent_1_ComponentEndOverlapSignature__DelegateSignature(class UPrimitiveComponent* OverlappedComponent, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
	void ReceiveBeginPlay();
	void BndEvt__TRIGGER_TauntVolume_OverlapBox_K2Node_ComponentBoundEvent_0_ComponentBeginOverlapSignature__DelegateSignature(class UPrimitiveComponent* OverlappedComponent, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const struct FHitResult& SweepResult);
	void UserConstructionScript();
	void TryInteract(class AActor* SourceActor, class UPrimitiveComponent* CursorPrimitive, ENUM_InteractionType InteractionType, struct FSTRUCT_InteractResults* InteractResults);
	void HasBeenTriggered(bool* Result);
	void InitializeTauntTrigger();
	void PlayTauntOnPublicAddressSystem();
	void TryTriggerFromOverlapEvent(class AActor* Actor, bool BeginOverlap, bool* Result);
	void TryResumeDelayedTaunt(bool* Result);
	void IsInteractActivated(bool* Result);
	void GetInteractLocked(class AActor* SourceActor, bool* Result, class FText* LockMessage);
	void SetInteractLocked(bool Locked, bool* Result);
	void HasCompletedRequiredQuest(bool* Result);

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"TRIGGER_TauntVolume_C">();
	}
	static class ATRIGGER_TauntVolume_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<ATRIGGER_TauntVolume_C>();
	}
};
static_assert(alignof(ATRIGGER_TauntVolume_C) == 0x000008, "Wrong alignment on ATRIGGER_TauntVolume_C");
static_assert(sizeof(ATRIGGER_TauntVolume_C) == 0x000358, "Wrong size on ATRIGGER_TauntVolume_C");
static_assert(offsetof(ATRIGGER_TauntVolume_C, UberGraphFrame_TRIGGER_TauntVolume_C) == 0x000308, "Member 'ATRIGGER_TauntVolume_C::UberGraphFrame_TRIGGER_TauntVolume_C' has a wrong offset!");
static_assert(offsetof(ATRIGGER_TauntVolume_C, Billboard) == 0x000310, "Member 'ATRIGGER_TauntVolume_C::Billboard' has a wrong offset!");
static_assert(offsetof(ATRIGGER_TauntVolume_C, OverlapBox) == 0x000318, "Member 'ATRIGGER_TauntVolume_C::OverlapBox' has a wrong offset!");
static_assert(offsetof(ATRIGGER_TauntVolume_C, TauntDataHandle) == 0x000320, "Member 'ATRIGGER_TauntVolume_C::TauntDataHandle' has a wrong offset!");
static_assert(offsetof(ATRIGGER_TauntVolume_C, TauntDelayTime) == 0x000330, "Member 'ATRIGGER_TauntVolume_C::TauntDelayTime' has a wrong offset!");
static_assert(offsetof(ATRIGGER_TauntVolume_C, TriggerTimestamp) == 0x000334, "Member 'ATRIGGER_TauntVolume_C::TriggerTimestamp' has a wrong offset!");
static_assert(offsetof(ATRIGGER_TauntVolume_C, TriggerCondition) == 0x000338, "Member 'ATRIGGER_TauntVolume_C::TriggerCondition' has a wrong offset!");
static_assert(offsetof(ATRIGGER_TauntVolume_C, TauntTimerHandle) == 0x000340, "Member 'ATRIGGER_TauntVolume_C::TauntTimerHandle' has a wrong offset!");
static_assert(offsetof(ATRIGGER_TauntVolume_C, RequiredQuest) == 0x000348, "Member 'ATRIGGER_TauntVolume_C::RequiredQuest' has a wrong offset!");

}

