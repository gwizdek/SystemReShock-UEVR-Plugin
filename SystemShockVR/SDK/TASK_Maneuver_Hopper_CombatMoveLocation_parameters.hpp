#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: TASK_Maneuver_Hopper_CombatMoveLocation

#include "Basic.hpp"

#include "ENUM_PreferredCombatStyle_structs.hpp"
#include "CoreUObject_structs.hpp"
#include "LevelVoxelization_structs.hpp"


namespace SDK::Params
{

// Function TASK_Maneuver_Hopper_CombatMoveLocation.TASK_Maneuver_Hopper_CombatMoveLocation_C.ExecuteUbergraph_TASK_Maneuver_Hopper_CombatMoveLocation
// 0x0018 (0x0018 - 0x0000)
struct TASK_Maneuver_Hopper_CombatMoveLocation_C_ExecuteUbergraph_TASK_Maneuver_Hopper_CombatMoveLocation final
{
public:
	int32                                         EntryPoint;                                        // 0x0000(0x0004)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_4[0x4];                                        // 0x0004(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	class AAIController*                          K2Node_Event_OwnerController;                      // 0x0008(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class APawn*                                  K2Node_Event_ControlledPawn;                       // 0x0010(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
};
static_assert(alignof(TASK_Maneuver_Hopper_CombatMoveLocation_C_ExecuteUbergraph_TASK_Maneuver_Hopper_CombatMoveLocation) == 0x000008, "Wrong alignment on TASK_Maneuver_Hopper_CombatMoveLocation_C_ExecuteUbergraph_TASK_Maneuver_Hopper_CombatMoveLocation");
static_assert(sizeof(TASK_Maneuver_Hopper_CombatMoveLocation_C_ExecuteUbergraph_TASK_Maneuver_Hopper_CombatMoveLocation) == 0x000018, "Wrong size on TASK_Maneuver_Hopper_CombatMoveLocation_C_ExecuteUbergraph_TASK_Maneuver_Hopper_CombatMoveLocation");
static_assert(offsetof(TASK_Maneuver_Hopper_CombatMoveLocation_C_ExecuteUbergraph_TASK_Maneuver_Hopper_CombatMoveLocation, EntryPoint) == 0x000000, "Member 'TASK_Maneuver_Hopper_CombatMoveLocation_C_ExecuteUbergraph_TASK_Maneuver_Hopper_CombatMoveLocation::EntryPoint' has a wrong offset!");
static_assert(offsetof(TASK_Maneuver_Hopper_CombatMoveLocation_C_ExecuteUbergraph_TASK_Maneuver_Hopper_CombatMoveLocation, K2Node_Event_OwnerController) == 0x000008, "Member 'TASK_Maneuver_Hopper_CombatMoveLocation_C_ExecuteUbergraph_TASK_Maneuver_Hopper_CombatMoveLocation::K2Node_Event_OwnerController' has a wrong offset!");
static_assert(offsetof(TASK_Maneuver_Hopper_CombatMoveLocation_C_ExecuteUbergraph_TASK_Maneuver_Hopper_CombatMoveLocation, K2Node_Event_ControlledPawn) == 0x000010, "Member 'TASK_Maneuver_Hopper_CombatMoveLocation_C_ExecuteUbergraph_TASK_Maneuver_Hopper_CombatMoveLocation::K2Node_Event_ControlledPawn' has a wrong offset!");

// Function TASK_Maneuver_Hopper_CombatMoveLocation.TASK_Maneuver_Hopper_CombatMoveLocation_C.ReceiveExecuteAI
// 0x0010 (0x0010 - 0x0000)
struct TASK_Maneuver_Hopper_CombatMoveLocation_C_ReceiveExecuteAI final
{
public:
	class AAIController*                          OwnerController;                                   // 0x0000(0x0008)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class APawn*                                  ControlledPawn;                                    // 0x0008(0x0008)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
};
static_assert(alignof(TASK_Maneuver_Hopper_CombatMoveLocation_C_ReceiveExecuteAI) == 0x000008, "Wrong alignment on TASK_Maneuver_Hopper_CombatMoveLocation_C_ReceiveExecuteAI");
static_assert(sizeof(TASK_Maneuver_Hopper_CombatMoveLocation_C_ReceiveExecuteAI) == 0x000010, "Wrong size on TASK_Maneuver_Hopper_CombatMoveLocation_C_ReceiveExecuteAI");
static_assert(offsetof(TASK_Maneuver_Hopper_CombatMoveLocation_C_ReceiveExecuteAI, OwnerController) == 0x000000, "Member 'TASK_Maneuver_Hopper_CombatMoveLocation_C_ReceiveExecuteAI::OwnerController' has a wrong offset!");
static_assert(offsetof(TASK_Maneuver_Hopper_CombatMoveLocation_C_ReceiveExecuteAI, ControlledPawn) == 0x000008, "Member 'TASK_Maneuver_Hopper_CombatMoveLocation_C_ReceiveExecuteAI::ControlledPawn' has a wrong offset!");

// Function TASK_Maneuver_Hopper_CombatMoveLocation.TASK_Maneuver_Hopper_CombatMoveLocation_C.LookForLocation
// 0x00E8 (0x00E8 - 0x0000)
struct TASK_Maneuver_Hopper_CombatMoveLocation_C_LookForLocation final
{
public:
	int32                                         PreferredMaxDistance;                              // 0x0000(0x0004)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	int32                                         PreferredMinDistance;                              // 0x0004(0x0004)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FVector                                TargetLocation;                                    // 0x0008(0x000C)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_14[0x4];                                       // 0x0014(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	class APAWN_SystemShockCharacter_C*           TargetPawn;                                        // 0x0018(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnTemplate, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	EVoxelSpatialQueryFuncType                    Temp_byte_Variable;                                // 0x0020(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	EVoxelSpatialQueryFuncType                    Temp_byte_Variable_1;                              // 0x0021(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	EVoxelSpatialQueryFuncType                    Temp_byte_Variable_2;                              // 0x0022(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_23[0x5];                                       // 0x0023(0x0005)(Fixing Size After Last Property [ Dumper-7 ])
	class UOBJ_EnemyTarget_C*                     CallFunc_GetTarget_Target;                         // 0x0028(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FVector                                CallFunc_K2_GetActorLocation_ReturnValue;          // 0x0030(0x000C)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          CallFunc_IsValid_ReturnValue;                      // 0x003C(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	bool                                          CallFunc_IsValid_ReturnValue_1;                    // 0x003D(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_3E[0x2];                                       // 0x003E(0x0002)(Fixing Size After Last Property [ Dumper-7 ])
	class APAWN_SystemShockCharacter_C*           CallFunc_GetDetectedPawn_Pawn;                     // 0x0040(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          CallFunc_WeightByDistanceFromObstacles_ReturnValue; // 0x0048(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_49[0x3];                                       // 0x0049(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	struct FVector2D                              CallFunc_GetPreferredDistanceMinMax_PreferredDistance; // 0x004C(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_54[0x4];                                       // 0x0054(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	class UOBJ_EnemyTarget_C*                     CallFunc_GetTarget_Target_1;                       // 0x0058(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         CallFunc_BreakVector2D_X;                          // 0x0060(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         CallFunc_BreakVector2D_Y;                          // 0x0064(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FVector                                CallFunc_GetPredictedTargetLocation_PredictedLocation; // 0x0068(0x000C)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	int32                                         CallFunc_FFloor_ReturnValue;                       // 0x0074(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	int32                                         CallFunc_FCeil_ReturnValue;                        // 0x0078(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	ENUM_PreferredCombatStyle                     Temp_byte_Variable_3;                              // 0x007C(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_7D[0x3];                                       // 0x007D(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	float                                         CallFunc_GetPreferredRangeBias_Bias;               // 0x0080(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_84[0x4];                                       // 0x0084(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	TArray<class AActor*>                         K2Node_MakeArray_Array;                            // 0x0088(0x0010)(ConstParm, ReferenceParm)
	bool                                          CallFunc_IsValid_ReturnValue_2;                    // 0x0098(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	bool                                          CallFunc_AddPathableVoxelsInBox_ReturnValue;       // 0x0099(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	EVoxelSpatialQueryFuncType                    K2Node_Select_Default;                             // 0x009A(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          CallFunc_WeightByDistanceFromPoint_ReturnValue;    // 0x009B(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	bool                                          CallFunc_ExecuteQueryInBackground_ReturnValue;     // 0x009C(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	bool                                          CallFunc_Not_PreBool_ReturnValue;                  // 0x009D(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_9E[0x2];                                       // 0x009E(0x0002)(Fixing Size After Last Property [ Dumper-7 ])
	struct FVector                                CallFunc_K2_GetActorLocation_ReturnValue_1;        // 0x00A0(0x000C)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FVector                                CallFunc_Subtract_VectorVector_ReturnValue;        // 0x00AC(0x000C)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FVector                                CallFunc_Normal_ReturnValue;                       // 0x00B8(0x000C)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          CallFunc_WeightByAngleFromViewpoint_ReturnValue;   // 0x00C4(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_C5[0x3];                                       // 0x00C5(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	class UVoxelSpatialNavigationQuery*           CallFunc_CreateSpatialNavigationQuery_ReturnValue; // 0x00C8(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	TDelegate<void(bool bResult, TArray<struct FVector4>& WeightedWorldLocations)> K2Node_CreateDelegate_OutputDelegate;              // 0x00D0(0x0010)(ZeroConstructor, NoDestructor)
	bool                                          CallFunc_FilterByVisibilityToPoint_ReturnValue;    // 0x00E0(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
};
static_assert(alignof(TASK_Maneuver_Hopper_CombatMoveLocation_C_LookForLocation) == 0x000008, "Wrong alignment on TASK_Maneuver_Hopper_CombatMoveLocation_C_LookForLocation");
static_assert(sizeof(TASK_Maneuver_Hopper_CombatMoveLocation_C_LookForLocation) == 0x0000E8, "Wrong size on TASK_Maneuver_Hopper_CombatMoveLocation_C_LookForLocation");
static_assert(offsetof(TASK_Maneuver_Hopper_CombatMoveLocation_C_LookForLocation, PreferredMaxDistance) == 0x000000, "Member 'TASK_Maneuver_Hopper_CombatMoveLocation_C_LookForLocation::PreferredMaxDistance' has a wrong offset!");
static_assert(offsetof(TASK_Maneuver_Hopper_CombatMoveLocation_C_LookForLocation, PreferredMinDistance) == 0x000004, "Member 'TASK_Maneuver_Hopper_CombatMoveLocation_C_LookForLocation::PreferredMinDistance' has a wrong offset!");
static_assert(offsetof(TASK_Maneuver_Hopper_CombatMoveLocation_C_LookForLocation, TargetLocation) == 0x000008, "Member 'TASK_Maneuver_Hopper_CombatMoveLocation_C_LookForLocation::TargetLocation' has a wrong offset!");
static_assert(offsetof(TASK_Maneuver_Hopper_CombatMoveLocation_C_LookForLocation, TargetPawn) == 0x000018, "Member 'TASK_Maneuver_Hopper_CombatMoveLocation_C_LookForLocation::TargetPawn' has a wrong offset!");
static_assert(offsetof(TASK_Maneuver_Hopper_CombatMoveLocation_C_LookForLocation, Temp_byte_Variable) == 0x000020, "Member 'TASK_Maneuver_Hopper_CombatMoveLocation_C_LookForLocation::Temp_byte_Variable' has a wrong offset!");
static_assert(offsetof(TASK_Maneuver_Hopper_CombatMoveLocation_C_LookForLocation, Temp_byte_Variable_1) == 0x000021, "Member 'TASK_Maneuver_Hopper_CombatMoveLocation_C_LookForLocation::Temp_byte_Variable_1' has a wrong offset!");
static_assert(offsetof(TASK_Maneuver_Hopper_CombatMoveLocation_C_LookForLocation, Temp_byte_Variable_2) == 0x000022, "Member 'TASK_Maneuver_Hopper_CombatMoveLocation_C_LookForLocation::Temp_byte_Variable_2' has a wrong offset!");
static_assert(offsetof(TASK_Maneuver_Hopper_CombatMoveLocation_C_LookForLocation, CallFunc_GetTarget_Target) == 0x000028, "Member 'TASK_Maneuver_Hopper_CombatMoveLocation_C_LookForLocation::CallFunc_GetTarget_Target' has a wrong offset!");
static_assert(offsetof(TASK_Maneuver_Hopper_CombatMoveLocation_C_LookForLocation, CallFunc_K2_GetActorLocation_ReturnValue) == 0x000030, "Member 'TASK_Maneuver_Hopper_CombatMoveLocation_C_LookForLocation::CallFunc_K2_GetActorLocation_ReturnValue' has a wrong offset!");
static_assert(offsetof(TASK_Maneuver_Hopper_CombatMoveLocation_C_LookForLocation, CallFunc_IsValid_ReturnValue) == 0x00003C, "Member 'TASK_Maneuver_Hopper_CombatMoveLocation_C_LookForLocation::CallFunc_IsValid_ReturnValue' has a wrong offset!");
static_assert(offsetof(TASK_Maneuver_Hopper_CombatMoveLocation_C_LookForLocation, CallFunc_IsValid_ReturnValue_1) == 0x00003D, "Member 'TASK_Maneuver_Hopper_CombatMoveLocation_C_LookForLocation::CallFunc_IsValid_ReturnValue_1' has a wrong offset!");
static_assert(offsetof(TASK_Maneuver_Hopper_CombatMoveLocation_C_LookForLocation, CallFunc_GetDetectedPawn_Pawn) == 0x000040, "Member 'TASK_Maneuver_Hopper_CombatMoveLocation_C_LookForLocation::CallFunc_GetDetectedPawn_Pawn' has a wrong offset!");
static_assert(offsetof(TASK_Maneuver_Hopper_CombatMoveLocation_C_LookForLocation, CallFunc_WeightByDistanceFromObstacles_ReturnValue) == 0x000048, "Member 'TASK_Maneuver_Hopper_CombatMoveLocation_C_LookForLocation::CallFunc_WeightByDistanceFromObstacles_ReturnValue' has a wrong offset!");
static_assert(offsetof(TASK_Maneuver_Hopper_CombatMoveLocation_C_LookForLocation, CallFunc_GetPreferredDistanceMinMax_PreferredDistance) == 0x00004C, "Member 'TASK_Maneuver_Hopper_CombatMoveLocation_C_LookForLocation::CallFunc_GetPreferredDistanceMinMax_PreferredDistance' has a wrong offset!");
static_assert(offsetof(TASK_Maneuver_Hopper_CombatMoveLocation_C_LookForLocation, CallFunc_GetTarget_Target_1) == 0x000058, "Member 'TASK_Maneuver_Hopper_CombatMoveLocation_C_LookForLocation::CallFunc_GetTarget_Target_1' has a wrong offset!");
static_assert(offsetof(TASK_Maneuver_Hopper_CombatMoveLocation_C_LookForLocation, CallFunc_BreakVector2D_X) == 0x000060, "Member 'TASK_Maneuver_Hopper_CombatMoveLocation_C_LookForLocation::CallFunc_BreakVector2D_X' has a wrong offset!");
static_assert(offsetof(TASK_Maneuver_Hopper_CombatMoveLocation_C_LookForLocation, CallFunc_BreakVector2D_Y) == 0x000064, "Member 'TASK_Maneuver_Hopper_CombatMoveLocation_C_LookForLocation::CallFunc_BreakVector2D_Y' has a wrong offset!");
static_assert(offsetof(TASK_Maneuver_Hopper_CombatMoveLocation_C_LookForLocation, CallFunc_GetPredictedTargetLocation_PredictedLocation) == 0x000068, "Member 'TASK_Maneuver_Hopper_CombatMoveLocation_C_LookForLocation::CallFunc_GetPredictedTargetLocation_PredictedLocation' has a wrong offset!");
static_assert(offsetof(TASK_Maneuver_Hopper_CombatMoveLocation_C_LookForLocation, CallFunc_FFloor_ReturnValue) == 0x000074, "Member 'TASK_Maneuver_Hopper_CombatMoveLocation_C_LookForLocation::CallFunc_FFloor_ReturnValue' has a wrong offset!");
static_assert(offsetof(TASK_Maneuver_Hopper_CombatMoveLocation_C_LookForLocation, CallFunc_FCeil_ReturnValue) == 0x000078, "Member 'TASK_Maneuver_Hopper_CombatMoveLocation_C_LookForLocation::CallFunc_FCeil_ReturnValue' has a wrong offset!");
static_assert(offsetof(TASK_Maneuver_Hopper_CombatMoveLocation_C_LookForLocation, Temp_byte_Variable_3) == 0x00007C, "Member 'TASK_Maneuver_Hopper_CombatMoveLocation_C_LookForLocation::Temp_byte_Variable_3' has a wrong offset!");
static_assert(offsetof(TASK_Maneuver_Hopper_CombatMoveLocation_C_LookForLocation, CallFunc_GetPreferredRangeBias_Bias) == 0x000080, "Member 'TASK_Maneuver_Hopper_CombatMoveLocation_C_LookForLocation::CallFunc_GetPreferredRangeBias_Bias' has a wrong offset!");
static_assert(offsetof(TASK_Maneuver_Hopper_CombatMoveLocation_C_LookForLocation, K2Node_MakeArray_Array) == 0x000088, "Member 'TASK_Maneuver_Hopper_CombatMoveLocation_C_LookForLocation::K2Node_MakeArray_Array' has a wrong offset!");
static_assert(offsetof(TASK_Maneuver_Hopper_CombatMoveLocation_C_LookForLocation, CallFunc_IsValid_ReturnValue_2) == 0x000098, "Member 'TASK_Maneuver_Hopper_CombatMoveLocation_C_LookForLocation::CallFunc_IsValid_ReturnValue_2' has a wrong offset!");
static_assert(offsetof(TASK_Maneuver_Hopper_CombatMoveLocation_C_LookForLocation, CallFunc_AddPathableVoxelsInBox_ReturnValue) == 0x000099, "Member 'TASK_Maneuver_Hopper_CombatMoveLocation_C_LookForLocation::CallFunc_AddPathableVoxelsInBox_ReturnValue' has a wrong offset!");
static_assert(offsetof(TASK_Maneuver_Hopper_CombatMoveLocation_C_LookForLocation, K2Node_Select_Default) == 0x00009A, "Member 'TASK_Maneuver_Hopper_CombatMoveLocation_C_LookForLocation::K2Node_Select_Default' has a wrong offset!");
static_assert(offsetof(TASK_Maneuver_Hopper_CombatMoveLocation_C_LookForLocation, CallFunc_WeightByDistanceFromPoint_ReturnValue) == 0x00009B, "Member 'TASK_Maneuver_Hopper_CombatMoveLocation_C_LookForLocation::CallFunc_WeightByDistanceFromPoint_ReturnValue' has a wrong offset!");
static_assert(offsetof(TASK_Maneuver_Hopper_CombatMoveLocation_C_LookForLocation, CallFunc_ExecuteQueryInBackground_ReturnValue) == 0x00009C, "Member 'TASK_Maneuver_Hopper_CombatMoveLocation_C_LookForLocation::CallFunc_ExecuteQueryInBackground_ReturnValue' has a wrong offset!");
static_assert(offsetof(TASK_Maneuver_Hopper_CombatMoveLocation_C_LookForLocation, CallFunc_Not_PreBool_ReturnValue) == 0x00009D, "Member 'TASK_Maneuver_Hopper_CombatMoveLocation_C_LookForLocation::CallFunc_Not_PreBool_ReturnValue' has a wrong offset!");
static_assert(offsetof(TASK_Maneuver_Hopper_CombatMoveLocation_C_LookForLocation, CallFunc_K2_GetActorLocation_ReturnValue_1) == 0x0000A0, "Member 'TASK_Maneuver_Hopper_CombatMoveLocation_C_LookForLocation::CallFunc_K2_GetActorLocation_ReturnValue_1' has a wrong offset!");
static_assert(offsetof(TASK_Maneuver_Hopper_CombatMoveLocation_C_LookForLocation, CallFunc_Subtract_VectorVector_ReturnValue) == 0x0000AC, "Member 'TASK_Maneuver_Hopper_CombatMoveLocation_C_LookForLocation::CallFunc_Subtract_VectorVector_ReturnValue' has a wrong offset!");
static_assert(offsetof(TASK_Maneuver_Hopper_CombatMoveLocation_C_LookForLocation, CallFunc_Normal_ReturnValue) == 0x0000B8, "Member 'TASK_Maneuver_Hopper_CombatMoveLocation_C_LookForLocation::CallFunc_Normal_ReturnValue' has a wrong offset!");
static_assert(offsetof(TASK_Maneuver_Hopper_CombatMoveLocation_C_LookForLocation, CallFunc_WeightByAngleFromViewpoint_ReturnValue) == 0x0000C4, "Member 'TASK_Maneuver_Hopper_CombatMoveLocation_C_LookForLocation::CallFunc_WeightByAngleFromViewpoint_ReturnValue' has a wrong offset!");
static_assert(offsetof(TASK_Maneuver_Hopper_CombatMoveLocation_C_LookForLocation, CallFunc_CreateSpatialNavigationQuery_ReturnValue) == 0x0000C8, "Member 'TASK_Maneuver_Hopper_CombatMoveLocation_C_LookForLocation::CallFunc_CreateSpatialNavigationQuery_ReturnValue' has a wrong offset!");
static_assert(offsetof(TASK_Maneuver_Hopper_CombatMoveLocation_C_LookForLocation, K2Node_CreateDelegate_OutputDelegate) == 0x0000D0, "Member 'TASK_Maneuver_Hopper_CombatMoveLocation_C_LookForLocation::K2Node_CreateDelegate_OutputDelegate' has a wrong offset!");
static_assert(offsetof(TASK_Maneuver_Hopper_CombatMoveLocation_C_LookForLocation, CallFunc_FilterByVisibilityToPoint_ReturnValue) == 0x0000E0, "Member 'TASK_Maneuver_Hopper_CombatMoveLocation_C_LookForLocation::CallFunc_FilterByVisibilityToPoint_ReturnValue' has a wrong offset!");

}

