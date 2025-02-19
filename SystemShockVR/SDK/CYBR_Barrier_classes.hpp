#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: CYBR_Barrier

#include "Basic.hpp"

#include "Engine_structs.hpp"
#include "CoreUObject_structs.hpp"
#include "LevelVoxelization_structs.hpp"
#include "ENUM_DoorState_structs.hpp"
#include "ENUM_InteractionType_structs.hpp"
#include "CYBR_InteractBase_classes.hpp"


namespace SDK
{

// BlueprintGeneratedClass CYBR_Barrier.CYBR_Barrier_C
// 0x0088 (0x02C0 - 0x0238)
class ACYBR_Barrier_C final : public ACYBR_InteractBase_C
{
public:
	struct FPointerToUberGraphFrame               UberGraphFrame_CYBR_Barrier_C;                     // 0x0238(0x0008)(ZeroConstructor, Transient, DuplicateTransient)
	class UAudioComponent*                        CyberBarrier_Loop;                                 // 0x0240(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NonTransactional, NoDestructor, HasGetValueTypeHash)
	class UCOMP_CullableNavModifier_C*            COMP_CullableNavModifier;                          // 0x0248(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NonTransactional, NoDestructor, HasGetValueTypeHash)
	class UNiagaraComponent*                      Niagara;                                           // 0x0250(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NonTransactional, NoDestructor, HasGetValueTypeHash)
	class UBoxComponent*                          CollisionBox;                                      // 0x0258(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NonTransactional, NoDestructor, HasGetValueTypeHash)
	class UMaterialInstanceDynamic*               ForceXMaterialInstance;                            // 0x0260(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UMaterialInstanceDynamic*               ForceMaterialInstance;                             // 0x0268(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FIntPoint                              BarrierDimensions;                                 // 0x0270(0x0008)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          StartsActive;                                      // 0x0278(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor)
	bool                                          IsManuallyLocked;                                  // 0x0279(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_27A[0x2];                                      // 0x027A(0x0002)(Fixing Size After Last Property [ Dumper-7 ])
	float                                         TransitionTimestamp;                               // 0x027C(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         TransitionDuration;                                // 0x0280(0x0004)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         AutoCloseTime;                                     // 0x0284(0x0004)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FTimerHandle                           AutoCloseTimerHandle;                              // 0x0288(0x0008)(Edit, BlueprintVisible, DisableEditOnInstance, NoDestructor, HasGetValueTypeHash)
	ENUM_DoorState                                BarrierState;                                      // 0x0290(0x0001)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_291[0x7];                                      // 0x0291(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	TArray<class APAWN_CyberEnemy_C*>             EnemiesRequiredToKill;                             // 0x0298(0x0010)(Edit, BlueprintVisible, DisableEditOnTemplate)
	int32                                         EnemiesRemaining;                                  // 0x02A8(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_2AC[0x4];                                      // 0x02AC(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	struct FDataTableRowHandle                    QuestRequiredToComplete;                           // 0x02B0(0x0010)(Edit, BlueprintVisible, NoDestructor)

public:
	void ExecuteUbergraph_CYBR_Barrier(int32 EntryPoint);
	void ReceiveTick(float DeltaSeconds);
	void ReceiveBeginPlay();
	void UserConstructionScript();
	void EVENT_OnEnemyDied(class APAWN_SystemShockCharacter_C* Character);
	void TryInteract(class AActor* SourceActor, class UPrimitiveComponent* CursorPrimitive, ENUM_InteractionType InteractionType, struct FSTRUCT_InteractResults* InteractResults);
	void InitializeCyberBarrier();
	void TryOpenBarrier();
	void TryCloseBarrier();
	void OnBarrierStateChanged();
	void UpdateBarrierState(float DeltaSeconds);
	void UpdateBarrierEffectsDimensions();
	void EVENT_OnQuestStateChanged(class FName StoryQuestName, bool Value);

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"CYBR_Barrier_C">();
	}
	static class ACYBR_Barrier_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<ACYBR_Barrier_C>();
	}
};
static_assert(alignof(ACYBR_Barrier_C) == 0x000008, "Wrong alignment on ACYBR_Barrier_C");
static_assert(sizeof(ACYBR_Barrier_C) == 0x0002C0, "Wrong size on ACYBR_Barrier_C");
static_assert(offsetof(ACYBR_Barrier_C, UberGraphFrame_CYBR_Barrier_C) == 0x000238, "Member 'ACYBR_Barrier_C::UberGraphFrame_CYBR_Barrier_C' has a wrong offset!");
static_assert(offsetof(ACYBR_Barrier_C, CyberBarrier_Loop) == 0x000240, "Member 'ACYBR_Barrier_C::CyberBarrier_Loop' has a wrong offset!");
static_assert(offsetof(ACYBR_Barrier_C, COMP_CullableNavModifier) == 0x000248, "Member 'ACYBR_Barrier_C::COMP_CullableNavModifier' has a wrong offset!");
static_assert(offsetof(ACYBR_Barrier_C, Niagara) == 0x000250, "Member 'ACYBR_Barrier_C::Niagara' has a wrong offset!");
static_assert(offsetof(ACYBR_Barrier_C, CollisionBox) == 0x000258, "Member 'ACYBR_Barrier_C::CollisionBox' has a wrong offset!");
static_assert(offsetof(ACYBR_Barrier_C, ForceXMaterialInstance) == 0x000260, "Member 'ACYBR_Barrier_C::ForceXMaterialInstance' has a wrong offset!");
static_assert(offsetof(ACYBR_Barrier_C, ForceMaterialInstance) == 0x000268, "Member 'ACYBR_Barrier_C::ForceMaterialInstance' has a wrong offset!");
static_assert(offsetof(ACYBR_Barrier_C, BarrierDimensions) == 0x000270, "Member 'ACYBR_Barrier_C::BarrierDimensions' has a wrong offset!");
static_assert(offsetof(ACYBR_Barrier_C, StartsActive) == 0x000278, "Member 'ACYBR_Barrier_C::StartsActive' has a wrong offset!");
static_assert(offsetof(ACYBR_Barrier_C, IsManuallyLocked) == 0x000279, "Member 'ACYBR_Barrier_C::IsManuallyLocked' has a wrong offset!");
static_assert(offsetof(ACYBR_Barrier_C, TransitionTimestamp) == 0x00027C, "Member 'ACYBR_Barrier_C::TransitionTimestamp' has a wrong offset!");
static_assert(offsetof(ACYBR_Barrier_C, TransitionDuration) == 0x000280, "Member 'ACYBR_Barrier_C::TransitionDuration' has a wrong offset!");
static_assert(offsetof(ACYBR_Barrier_C, AutoCloseTime) == 0x000284, "Member 'ACYBR_Barrier_C::AutoCloseTime' has a wrong offset!");
static_assert(offsetof(ACYBR_Barrier_C, AutoCloseTimerHandle) == 0x000288, "Member 'ACYBR_Barrier_C::AutoCloseTimerHandle' has a wrong offset!");
static_assert(offsetof(ACYBR_Barrier_C, BarrierState) == 0x000290, "Member 'ACYBR_Barrier_C::BarrierState' has a wrong offset!");
static_assert(offsetof(ACYBR_Barrier_C, EnemiesRequiredToKill) == 0x000298, "Member 'ACYBR_Barrier_C::EnemiesRequiredToKill' has a wrong offset!");
static_assert(offsetof(ACYBR_Barrier_C, EnemiesRemaining) == 0x0002A8, "Member 'ACYBR_Barrier_C::EnemiesRemaining' has a wrong offset!");
static_assert(offsetof(ACYBR_Barrier_C, QuestRequiredToComplete) == 0x0002B0, "Member 'ACYBR_Barrier_C::QuestRequiredToComplete' has a wrong offset!");

}

