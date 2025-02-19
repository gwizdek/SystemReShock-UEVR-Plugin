#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: TASK_Maneuver_Assassin_GrenadeEscapeLocation

#include "Basic.hpp"

#include "CoreUObject_structs.hpp"


namespace SDK::Params
{

// Function TASK_Maneuver_Assassin_GrenadeEscapeLocation.TASK_Maneuver_Assassin_GrenadeEscapeLocation_C.ExecuteUbergraph_TASK_Maneuver_Assassin_GrenadeEscapeLocation
// 0x0078 (0x0078 - 0x0000)
struct TASK_Maneuver_Assassin_GrenadeEscapeLocation_C_ExecuteUbergraph_TASK_Maneuver_Assassin_GrenadeEscapeLocation final
{
public:
	int32                                         EntryPoint;                                        // 0x0000(0x0004)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	TDelegate<void(bool bResult, TArray<struct FVector4>& WeightedWorldLocations)> K2Node_CreateDelegate_OutputDelegate;              // 0x0004(0x0010)(ZeroConstructor, NoDestructor)
	uint8                                         Pad_14[0x4];                                       // 0x0014(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	class UVoxelSpatialNavigationQuery*           CallFunc_CreateSpatialNavigationQuery_ReturnValue; // 0x0018(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          CallFunc_ExecuteQueryInBackground_ReturnValue;     // 0x0020(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	bool                                          CallFunc_Not_PreBool_ReturnValue;                  // 0x0021(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_22[0x6];                                       // 0x0022(0x0006)(Fixing Size After Last Property [ Dumper-7 ])
	class AAIController*                          K2Node_Event_OwnerController;                      // 0x0028(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class APawn*                                  K2Node_Event_ControlledPawn;                       // 0x0030(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          CallFunc_WeightByDistanceFromPoint_ReturnValue;    // 0x0038(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	bool                                          CallFunc_AddPathableVoxelsInBox_ReturnValue;       // 0x0039(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_3A[0x2];                                       // 0x003A(0x0002)(Fixing Size After Last Property [ Dumper-7 ])
	struct FVector                                CallFunc_K2_GetActorLocation_ReturnValue;          // 0x003C(0x000C)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UOBJ_EnemyTarget_C*                     CallFunc_GetTarget_Target;                         // 0x0048(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FVector                                CallFunc_Get_Target_Location_Location;             // 0x0050(0x000C)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_5C[0x4];                                       // 0x005C(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	TArray<struct FVector>                        K2Node_MakeArray_Array;                            // 0x0060(0x0010)(ConstParm, ReferenceParm)
	bool                                          CallFunc_FilterOutWorldLocations_ReturnValue;      // 0x0070(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
};
static_assert(alignof(TASK_Maneuver_Assassin_GrenadeEscapeLocation_C_ExecuteUbergraph_TASK_Maneuver_Assassin_GrenadeEscapeLocation) == 0x000008, "Wrong alignment on TASK_Maneuver_Assassin_GrenadeEscapeLocation_C_ExecuteUbergraph_TASK_Maneuver_Assassin_GrenadeEscapeLocation");
static_assert(sizeof(TASK_Maneuver_Assassin_GrenadeEscapeLocation_C_ExecuteUbergraph_TASK_Maneuver_Assassin_GrenadeEscapeLocation) == 0x000078, "Wrong size on TASK_Maneuver_Assassin_GrenadeEscapeLocation_C_ExecuteUbergraph_TASK_Maneuver_Assassin_GrenadeEscapeLocation");
static_assert(offsetof(TASK_Maneuver_Assassin_GrenadeEscapeLocation_C_ExecuteUbergraph_TASK_Maneuver_Assassin_GrenadeEscapeLocation, EntryPoint) == 0x000000, "Member 'TASK_Maneuver_Assassin_GrenadeEscapeLocation_C_ExecuteUbergraph_TASK_Maneuver_Assassin_GrenadeEscapeLocation::EntryPoint' has a wrong offset!");
static_assert(offsetof(TASK_Maneuver_Assassin_GrenadeEscapeLocation_C_ExecuteUbergraph_TASK_Maneuver_Assassin_GrenadeEscapeLocation, K2Node_CreateDelegate_OutputDelegate) == 0x000004, "Member 'TASK_Maneuver_Assassin_GrenadeEscapeLocation_C_ExecuteUbergraph_TASK_Maneuver_Assassin_GrenadeEscapeLocation::K2Node_CreateDelegate_OutputDelegate' has a wrong offset!");
static_assert(offsetof(TASK_Maneuver_Assassin_GrenadeEscapeLocation_C_ExecuteUbergraph_TASK_Maneuver_Assassin_GrenadeEscapeLocation, CallFunc_CreateSpatialNavigationQuery_ReturnValue) == 0x000018, "Member 'TASK_Maneuver_Assassin_GrenadeEscapeLocation_C_ExecuteUbergraph_TASK_Maneuver_Assassin_GrenadeEscapeLocation::CallFunc_CreateSpatialNavigationQuery_ReturnValue' has a wrong offset!");
static_assert(offsetof(TASK_Maneuver_Assassin_GrenadeEscapeLocation_C_ExecuteUbergraph_TASK_Maneuver_Assassin_GrenadeEscapeLocation, CallFunc_ExecuteQueryInBackground_ReturnValue) == 0x000020, "Member 'TASK_Maneuver_Assassin_GrenadeEscapeLocation_C_ExecuteUbergraph_TASK_Maneuver_Assassin_GrenadeEscapeLocation::CallFunc_ExecuteQueryInBackground_ReturnValue' has a wrong offset!");
static_assert(offsetof(TASK_Maneuver_Assassin_GrenadeEscapeLocation_C_ExecuteUbergraph_TASK_Maneuver_Assassin_GrenadeEscapeLocation, CallFunc_Not_PreBool_ReturnValue) == 0x000021, "Member 'TASK_Maneuver_Assassin_GrenadeEscapeLocation_C_ExecuteUbergraph_TASK_Maneuver_Assassin_GrenadeEscapeLocation::CallFunc_Not_PreBool_ReturnValue' has a wrong offset!");
static_assert(offsetof(TASK_Maneuver_Assassin_GrenadeEscapeLocation_C_ExecuteUbergraph_TASK_Maneuver_Assassin_GrenadeEscapeLocation, K2Node_Event_OwnerController) == 0x000028, "Member 'TASK_Maneuver_Assassin_GrenadeEscapeLocation_C_ExecuteUbergraph_TASK_Maneuver_Assassin_GrenadeEscapeLocation::K2Node_Event_OwnerController' has a wrong offset!");
static_assert(offsetof(TASK_Maneuver_Assassin_GrenadeEscapeLocation_C_ExecuteUbergraph_TASK_Maneuver_Assassin_GrenadeEscapeLocation, K2Node_Event_ControlledPawn) == 0x000030, "Member 'TASK_Maneuver_Assassin_GrenadeEscapeLocation_C_ExecuteUbergraph_TASK_Maneuver_Assassin_GrenadeEscapeLocation::K2Node_Event_ControlledPawn' has a wrong offset!");
static_assert(offsetof(TASK_Maneuver_Assassin_GrenadeEscapeLocation_C_ExecuteUbergraph_TASK_Maneuver_Assassin_GrenadeEscapeLocation, CallFunc_WeightByDistanceFromPoint_ReturnValue) == 0x000038, "Member 'TASK_Maneuver_Assassin_GrenadeEscapeLocation_C_ExecuteUbergraph_TASK_Maneuver_Assassin_GrenadeEscapeLocation::CallFunc_WeightByDistanceFromPoint_ReturnValue' has a wrong offset!");
static_assert(offsetof(TASK_Maneuver_Assassin_GrenadeEscapeLocation_C_ExecuteUbergraph_TASK_Maneuver_Assassin_GrenadeEscapeLocation, CallFunc_AddPathableVoxelsInBox_ReturnValue) == 0x000039, "Member 'TASK_Maneuver_Assassin_GrenadeEscapeLocation_C_ExecuteUbergraph_TASK_Maneuver_Assassin_GrenadeEscapeLocation::CallFunc_AddPathableVoxelsInBox_ReturnValue' has a wrong offset!");
static_assert(offsetof(TASK_Maneuver_Assassin_GrenadeEscapeLocation_C_ExecuteUbergraph_TASK_Maneuver_Assassin_GrenadeEscapeLocation, CallFunc_K2_GetActorLocation_ReturnValue) == 0x00003C, "Member 'TASK_Maneuver_Assassin_GrenadeEscapeLocation_C_ExecuteUbergraph_TASK_Maneuver_Assassin_GrenadeEscapeLocation::CallFunc_K2_GetActorLocation_ReturnValue' has a wrong offset!");
static_assert(offsetof(TASK_Maneuver_Assassin_GrenadeEscapeLocation_C_ExecuteUbergraph_TASK_Maneuver_Assassin_GrenadeEscapeLocation, CallFunc_GetTarget_Target) == 0x000048, "Member 'TASK_Maneuver_Assassin_GrenadeEscapeLocation_C_ExecuteUbergraph_TASK_Maneuver_Assassin_GrenadeEscapeLocation::CallFunc_GetTarget_Target' has a wrong offset!");
static_assert(offsetof(TASK_Maneuver_Assassin_GrenadeEscapeLocation_C_ExecuteUbergraph_TASK_Maneuver_Assassin_GrenadeEscapeLocation, CallFunc_Get_Target_Location_Location) == 0x000050, "Member 'TASK_Maneuver_Assassin_GrenadeEscapeLocation_C_ExecuteUbergraph_TASK_Maneuver_Assassin_GrenadeEscapeLocation::CallFunc_Get_Target_Location_Location' has a wrong offset!");
static_assert(offsetof(TASK_Maneuver_Assassin_GrenadeEscapeLocation_C_ExecuteUbergraph_TASK_Maneuver_Assassin_GrenadeEscapeLocation, K2Node_MakeArray_Array) == 0x000060, "Member 'TASK_Maneuver_Assassin_GrenadeEscapeLocation_C_ExecuteUbergraph_TASK_Maneuver_Assassin_GrenadeEscapeLocation::K2Node_MakeArray_Array' has a wrong offset!");
static_assert(offsetof(TASK_Maneuver_Assassin_GrenadeEscapeLocation_C_ExecuteUbergraph_TASK_Maneuver_Assassin_GrenadeEscapeLocation, CallFunc_FilterOutWorldLocations_ReturnValue) == 0x000070, "Member 'TASK_Maneuver_Assassin_GrenadeEscapeLocation_C_ExecuteUbergraph_TASK_Maneuver_Assassin_GrenadeEscapeLocation::CallFunc_FilterOutWorldLocations_ReturnValue' has a wrong offset!");

// Function TASK_Maneuver_Assassin_GrenadeEscapeLocation.TASK_Maneuver_Assassin_GrenadeEscapeLocation_C.ReceiveExecuteAI
// 0x0010 (0x0010 - 0x0000)
struct TASK_Maneuver_Assassin_GrenadeEscapeLocation_C_ReceiveExecuteAI final
{
public:
	class AAIController*                          OwnerController;                                   // 0x0000(0x0008)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class APawn*                                  ControlledPawn;                                    // 0x0008(0x0008)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
};
static_assert(alignof(TASK_Maneuver_Assassin_GrenadeEscapeLocation_C_ReceiveExecuteAI) == 0x000008, "Wrong alignment on TASK_Maneuver_Assassin_GrenadeEscapeLocation_C_ReceiveExecuteAI");
static_assert(sizeof(TASK_Maneuver_Assassin_GrenadeEscapeLocation_C_ReceiveExecuteAI) == 0x000010, "Wrong size on TASK_Maneuver_Assassin_GrenadeEscapeLocation_C_ReceiveExecuteAI");
static_assert(offsetof(TASK_Maneuver_Assassin_GrenadeEscapeLocation_C_ReceiveExecuteAI, OwnerController) == 0x000000, "Member 'TASK_Maneuver_Assassin_GrenadeEscapeLocation_C_ReceiveExecuteAI::OwnerController' has a wrong offset!");
static_assert(offsetof(TASK_Maneuver_Assassin_GrenadeEscapeLocation_C_ReceiveExecuteAI, ControlledPawn) == 0x000008, "Member 'TASK_Maneuver_Assassin_GrenadeEscapeLocation_C_ReceiveExecuteAI::ControlledPawn' has a wrong offset!");

}

