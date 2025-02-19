#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: TASK_PerformActionBase

#include "Basic.hpp"

#include "Engine_structs.hpp"
#include "AIModule_classes.hpp"


namespace SDK
{

// BlueprintGeneratedClass TASK_PerformActionBase.TASK_PerformActionBase_C
// 0x0038 (0x00E0 - 0x00A8)
class UTASK_PerformActionBase_C : public UBTTask_BlueprintBase
{
public:
	struct FPointerToUberGraphFrame               UberGraphFrame;                                    // 0x00A8(0x0008)(ZeroConstructor, Transient, DuplicateTransient)
	bool                                          ForceBegin;                                        // 0x00B0(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor)
	bool                                          EndOnLowPriority;                                  // 0x00B1(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_B2[0x6];                                       // 0x00B2(0x0006)(Fixing Size After Last Property [ Dumper-7 ])
	class APAWN_Enemy_C*                          EnemyPawn;                                         // 0x00B8(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnTemplate, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UCharacterAction_C*                     Action;                                            // 0x00C0(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          SetIdleOverride;                                   // 0x00C8(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_C9[0x7];                                       // 0x00C9(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	class UAnimSequenceBase*                      IdleOverride;                                      // 0x00D0(0x0008)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          HasSetIdleOverride;                                // 0x00D8(0x0001)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor)

public:
	void ExecuteUbergraph_TASK_PerformActionBase(int32 EntryPoint);
	void EVENT_OnActionEnded();
	void TrySetIdleOverride();
	void ReceiveTick(class AActor* OwnerActor, float DeltaSeconds);
	void CleanUpEvents();
	void ReceiveExecuteAI(class AAIController* OwnerController, class APawn* ControlledPawn);
	void ChooseActionMontage(class UAnimMontage** Montage);
	void StartAction(bool* Success, class UCharacterAction_C** Result);

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"TASK_PerformActionBase_C">();
	}
	static class UTASK_PerformActionBase_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<UTASK_PerformActionBase_C>();
	}
};
static_assert(alignof(UTASK_PerformActionBase_C) == 0x000008, "Wrong alignment on UTASK_PerformActionBase_C");
static_assert(sizeof(UTASK_PerformActionBase_C) == 0x0000E0, "Wrong size on UTASK_PerformActionBase_C");
static_assert(offsetof(UTASK_PerformActionBase_C, UberGraphFrame) == 0x0000A8, "Member 'UTASK_PerformActionBase_C::UberGraphFrame' has a wrong offset!");
static_assert(offsetof(UTASK_PerformActionBase_C, ForceBegin) == 0x0000B0, "Member 'UTASK_PerformActionBase_C::ForceBegin' has a wrong offset!");
static_assert(offsetof(UTASK_PerformActionBase_C, EndOnLowPriority) == 0x0000B1, "Member 'UTASK_PerformActionBase_C::EndOnLowPriority' has a wrong offset!");
static_assert(offsetof(UTASK_PerformActionBase_C, EnemyPawn) == 0x0000B8, "Member 'UTASK_PerformActionBase_C::EnemyPawn' has a wrong offset!");
static_assert(offsetof(UTASK_PerformActionBase_C, Action) == 0x0000C0, "Member 'UTASK_PerformActionBase_C::Action' has a wrong offset!");
static_assert(offsetof(UTASK_PerformActionBase_C, SetIdleOverride) == 0x0000C8, "Member 'UTASK_PerformActionBase_C::SetIdleOverride' has a wrong offset!");
static_assert(offsetof(UTASK_PerformActionBase_C, IdleOverride) == 0x0000D0, "Member 'UTASK_PerformActionBase_C::IdleOverride' has a wrong offset!");
static_assert(offsetof(UTASK_PerformActionBase_C, HasSetIdleOverride) == 0x0000D8, "Member 'UTASK_PerformActionBase_C::HasSetIdleOverride' has a wrong offset!");

}

