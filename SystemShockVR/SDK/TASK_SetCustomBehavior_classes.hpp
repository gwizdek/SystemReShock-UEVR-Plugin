#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: TASK_SetCustomBehavior

#include "Basic.hpp"

#include "Engine_structs.hpp"
#include "GameplayTags_structs.hpp"
#include "AIModule_classes.hpp"


namespace SDK
{

// BlueprintGeneratedClass TASK_SetCustomBehavior.TASK_SetCustomBehavior_C
// 0x0028 (0x00D0 - 0x00A8)
class UTASK_SetCustomBehavior_C final : public UBTTask_BlueprintBase
{
public:
	struct FPointerToUberGraphFrame               UberGraphFrame;                                    // 0x00A8(0x0008)(ZeroConstructor, Transient, DuplicateTransient)
	struct FGameplayTag                           InjectTag;                                         // 0x00B0(0x0008)(Edit, BlueprintVisible, NoDestructor, HasGetValueTypeHash)
	class UBehaviorTree*                          DynamicBehavior;                                   // 0x00B8(0x0008)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class APAWN_Enemy_C*                          EnemyPawn;                                         // 0x00C0(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnTemplate, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          ReplaceInitialCustomBehavior;                      // 0x00C8(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor)

public:
	void ExecuteUbergraph_TASK_SetCustomBehavior(int32 EntryPoint);
	void ReceiveExecuteAI(class AAIController* OwnerController, class APawn* ControlledPawn);

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"TASK_SetCustomBehavior_C">();
	}
	static class UTASK_SetCustomBehavior_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<UTASK_SetCustomBehavior_C>();
	}
};
static_assert(alignof(UTASK_SetCustomBehavior_C) == 0x000008, "Wrong alignment on UTASK_SetCustomBehavior_C");
static_assert(sizeof(UTASK_SetCustomBehavior_C) == 0x0000D0, "Wrong size on UTASK_SetCustomBehavior_C");
static_assert(offsetof(UTASK_SetCustomBehavior_C, UberGraphFrame) == 0x0000A8, "Member 'UTASK_SetCustomBehavior_C::UberGraphFrame' has a wrong offset!");
static_assert(offsetof(UTASK_SetCustomBehavior_C, InjectTag) == 0x0000B0, "Member 'UTASK_SetCustomBehavior_C::InjectTag' has a wrong offset!");
static_assert(offsetof(UTASK_SetCustomBehavior_C, DynamicBehavior) == 0x0000B8, "Member 'UTASK_SetCustomBehavior_C::DynamicBehavior' has a wrong offset!");
static_assert(offsetof(UTASK_SetCustomBehavior_C, EnemyPawn) == 0x0000C0, "Member 'UTASK_SetCustomBehavior_C::EnemyPawn' has a wrong offset!");
static_assert(offsetof(UTASK_SetCustomBehavior_C, ReplaceInitialCustomBehavior) == 0x0000C8, "Member 'UTASK_SetCustomBehavior_C::ReplaceInitialCustomBehavior' has a wrong offset!");

}

