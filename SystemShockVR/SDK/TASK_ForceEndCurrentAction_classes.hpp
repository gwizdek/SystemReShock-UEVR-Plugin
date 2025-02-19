#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: TASK_ForceEndCurrentAction

#include "Basic.hpp"

#include "ENUM_ActionPriority_structs.hpp"
#include "Engine_structs.hpp"
#include "AIModule_classes.hpp"


namespace SDK
{

// BlueprintGeneratedClass TASK_ForceEndCurrentAction.TASK_ForceEndCurrentAction_C
// 0x0028 (0x00D0 - 0x00A8)
class UTASK_ForceEndCurrentAction_C final : public UBTTask_BlueprintBase
{
public:
	struct FPointerToUberGraphFrame               UberGraphFrame;                                    // 0x00A8(0x0008)(ZeroConstructor, Transient, DuplicateTransient)
	ENUM_ActionPriority                           MaximumPriority;                                   // 0x00B0(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_B1[0x7];                                       // 0x00B1(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	class APAWN_Enemy_C*                          EnemyPawn;                                         // 0x00B8(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnTemplate, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UCharacterAction_C*                     CurrentAction;                                     // 0x00C0(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         BlendTime;                                         // 0x00C8(0x0004)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

public:
	void ExecuteUbergraph_TASK_ForceEndCurrentAction(int32 EntryPoint);
	void ReceiveExecuteAI(class AAIController* OwnerController, class APawn* ControlledPawn);

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"TASK_ForceEndCurrentAction_C">();
	}
	static class UTASK_ForceEndCurrentAction_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<UTASK_ForceEndCurrentAction_C>();
	}
};
static_assert(alignof(UTASK_ForceEndCurrentAction_C) == 0x000008, "Wrong alignment on UTASK_ForceEndCurrentAction_C");
static_assert(sizeof(UTASK_ForceEndCurrentAction_C) == 0x0000D0, "Wrong size on UTASK_ForceEndCurrentAction_C");
static_assert(offsetof(UTASK_ForceEndCurrentAction_C, UberGraphFrame) == 0x0000A8, "Member 'UTASK_ForceEndCurrentAction_C::UberGraphFrame' has a wrong offset!");
static_assert(offsetof(UTASK_ForceEndCurrentAction_C, MaximumPriority) == 0x0000B0, "Member 'UTASK_ForceEndCurrentAction_C::MaximumPriority' has a wrong offset!");
static_assert(offsetof(UTASK_ForceEndCurrentAction_C, EnemyPawn) == 0x0000B8, "Member 'UTASK_ForceEndCurrentAction_C::EnemyPawn' has a wrong offset!");
static_assert(offsetof(UTASK_ForceEndCurrentAction_C, CurrentAction) == 0x0000C0, "Member 'UTASK_ForceEndCurrentAction_C::CurrentAction' has a wrong offset!");
static_assert(offsetof(UTASK_ForceEndCurrentAction_C, BlendTime) == 0x0000C8, "Member 'UTASK_ForceEndCurrentAction_C::BlendTime' has a wrong offset!");

}

