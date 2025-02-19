#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: TASK_ExpireModsOfCategory

#include "Basic.hpp"

#include "Engine_structs.hpp"
#include "AIModule_classes.hpp"


namespace SDK
{

// BlueprintGeneratedClass TASK_ExpireModsOfCategory.TASK_ExpireModsOfCategory_C
// 0x0020 (0x00C8 - 0x00A8)
class UTASK_ExpireModsOfCategory_C final : public UBTTask_BlueprintBase
{
public:
	struct FPointerToUberGraphFrame               UberGraphFrame;                                    // 0x00A8(0x0008)(ZeroConstructor, Transient, DuplicateTransient)
	TArray<class FName>                           ModCategories;                                     // 0x00B0(0x0010)(Edit, BlueprintVisible)
	class APAWN_Enemy_C*                          EnemyPawn;                                         // 0x00C0(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnTemplate, DisableEditOnInstance, IsPlainOldData, NoDestructor, UObjectWrapper, HasGetValueTypeHash)

public:
	void ExecuteUbergraph_TASK_ExpireModsOfCategory(int32 EntryPoint);
	void ReceiveExecuteAI(class AAIController* OwnerController, class APawn* ControlledPawn);

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"TASK_ExpireModsOfCategory_C">();
	}
	static class UTASK_ExpireModsOfCategory_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<UTASK_ExpireModsOfCategory_C>();
	}
};
static_assert(alignof(UTASK_ExpireModsOfCategory_C) == 0x000008, "Wrong alignment on UTASK_ExpireModsOfCategory_C");
static_assert(sizeof(UTASK_ExpireModsOfCategory_C) == 0x0000C8, "Wrong size on UTASK_ExpireModsOfCategory_C");
static_assert(offsetof(UTASK_ExpireModsOfCategory_C, UberGraphFrame) == 0x0000A8, "Member 'UTASK_ExpireModsOfCategory_C::UberGraphFrame' has a wrong offset!");
static_assert(offsetof(UTASK_ExpireModsOfCategory_C, ModCategories) == 0x0000B0, "Member 'UTASK_ExpireModsOfCategory_C::ModCategories' has a wrong offset!");
static_assert(offsetof(UTASK_ExpireModsOfCategory_C, EnemyPawn) == 0x0000C0, "Member 'UTASK_ExpireModsOfCategory_C::EnemyPawn' has a wrong offset!");

}

