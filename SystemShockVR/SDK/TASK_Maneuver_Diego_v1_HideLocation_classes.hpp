#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: TASK_Maneuver_Diego_v1_HideLocation

#include "Basic.hpp"

#include "Engine_structs.hpp"
#include "TASK_Maneuver_Base_classes.hpp"
#include "CoreUObject_structs.hpp"


namespace SDK
{

// BlueprintGeneratedClass TASK_Maneuver_Diego_v1_HideLocation.TASK_Maneuver_Diego_v1_HideLocation_C
// 0x0020 (0x00E8 - 0x00C8)
class UTASK_Maneuver_Diego_v1_HideLocation_C final : public UTASK_Maneuver_Base_C
{
public:
	struct FPointerToUberGraphFrame               UberGraphFrame_TASK_Maneuver_Diego_v1_HideLocation_C; // 0x00C8(0x0008)(ZeroConstructor, Transient, DuplicateTransient)
	struct FVector                                PlayerLocation;                                    // 0x00D0(0x000C)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FVector                                EnemyLocation;                                     // 0x00DC(0x000C)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

public:
	void ExecuteUbergraph_TASK_Maneuver_Diego_v1_HideLocation(int32 EntryPoint);
	void ReceiveExecuteAI(class AAIController* OwnerController, class APawn* ControlledPawn);

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"TASK_Maneuver_Diego_v1_HideLocation_C">();
	}
	static class UTASK_Maneuver_Diego_v1_HideLocation_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<UTASK_Maneuver_Diego_v1_HideLocation_C>();
	}
};
static_assert(alignof(UTASK_Maneuver_Diego_v1_HideLocation_C) == 0x000008, "Wrong alignment on UTASK_Maneuver_Diego_v1_HideLocation_C");
static_assert(sizeof(UTASK_Maneuver_Diego_v1_HideLocation_C) == 0x0000E8, "Wrong size on UTASK_Maneuver_Diego_v1_HideLocation_C");
static_assert(offsetof(UTASK_Maneuver_Diego_v1_HideLocation_C, UberGraphFrame_TASK_Maneuver_Diego_v1_HideLocation_C) == 0x0000C8, "Member 'UTASK_Maneuver_Diego_v1_HideLocation_C::UberGraphFrame_TASK_Maneuver_Diego_v1_HideLocation_C' has a wrong offset!");
static_assert(offsetof(UTASK_Maneuver_Diego_v1_HideLocation_C, PlayerLocation) == 0x0000D0, "Member 'UTASK_Maneuver_Diego_v1_HideLocation_C::PlayerLocation' has a wrong offset!");
static_assert(offsetof(UTASK_Maneuver_Diego_v1_HideLocation_C, EnemyLocation) == 0x0000DC, "Member 'UTASK_Maneuver_Diego_v1_HideLocation_C::EnemyLocation' has a wrong offset!");

}

