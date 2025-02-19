#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: TASK_Cyber_Maneuver_AttackPosition

#include "Basic.hpp"

#include "Engine_structs.hpp"
#include "TASK_Maneuver_Base_classes.hpp"
#include "CoreUObject_structs.hpp"


namespace SDK
{

// BlueprintGeneratedClass TASK_Cyber_Maneuver_AttackPosition.TASK_Cyber_Maneuver_AttackPosition_C
// 0x0020 (0x00E8 - 0x00C8)
class UTASK_Cyber_Maneuver_AttackPosition_C final : public UTASK_Maneuver_Base_C
{
public:
	struct FPointerToUberGraphFrame               UberGraphFrame_TASK_Cyber_Maneuver_AttackPosition_C; // 0x00C8(0x0008)(ZeroConstructor, Transient, DuplicateTransient)
	class APAWN_SystemShockCharacter_C*           TargetPawn;                                        // 0x00D0(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnTemplate, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FVector                                TargetLocation;                                    // 0x00D8(0x000C)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

public:
	void ExecuteUbergraph_TASK_Cyber_Maneuver_AttackPosition(int32 EntryPoint);
	void ReceiveExecuteAI(class AAIController* OwnerController, class APawn* ControlledPawn);

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"TASK_Cyber_Maneuver_AttackPosition_C">();
	}
	static class UTASK_Cyber_Maneuver_AttackPosition_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<UTASK_Cyber_Maneuver_AttackPosition_C>();
	}
};
static_assert(alignof(UTASK_Cyber_Maneuver_AttackPosition_C) == 0x000008, "Wrong alignment on UTASK_Cyber_Maneuver_AttackPosition_C");
static_assert(sizeof(UTASK_Cyber_Maneuver_AttackPosition_C) == 0x0000E8, "Wrong size on UTASK_Cyber_Maneuver_AttackPosition_C");
static_assert(offsetof(UTASK_Cyber_Maneuver_AttackPosition_C, UberGraphFrame_TASK_Cyber_Maneuver_AttackPosition_C) == 0x0000C8, "Member 'UTASK_Cyber_Maneuver_AttackPosition_C::UberGraphFrame_TASK_Cyber_Maneuver_AttackPosition_C' has a wrong offset!");
static_assert(offsetof(UTASK_Cyber_Maneuver_AttackPosition_C, TargetPawn) == 0x0000D0, "Member 'UTASK_Cyber_Maneuver_AttackPosition_C::TargetPawn' has a wrong offset!");
static_assert(offsetof(UTASK_Cyber_Maneuver_AttackPosition_C, TargetLocation) == 0x0000D8, "Member 'UTASK_Cyber_Maneuver_AttackPosition_C::TargetLocation' has a wrong offset!");

}

