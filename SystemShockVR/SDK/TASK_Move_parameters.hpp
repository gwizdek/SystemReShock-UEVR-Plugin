#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: TASK_Move

#include "Basic.hpp"

#include "CoreUObject_structs.hpp"


namespace SDK::Params
{

// Function TASK_Move.TASK_Move_C.ExecuteUbergraph_TASK_Move
// 0x00F8 (0x00F8 - 0x0000)
struct TASK_Move_C_ExecuteUbergraph_TASK_Move final
{
public:
	int32                                         EntryPoint;                                        // 0x0000(0x0004)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          CallFunc_EqualEqual_ByteByte_ReturnValue;          // 0x0004(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	bool                                          K2Node_SwitchEnum_CmpSuccess;                      // 0x0005(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	bool                                          K2Node_SwitchEnum_CmpSuccess_1;                    // 0x0006(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	bool                                          CallFunc_SetBodyRotateSpeed_Changed;               // 0x0007(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	bool                                          CallFunc_SetMoveDirection_RotationSpeed_Changed;   // 0x0008(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	bool                                          CallFunc_NotEqual_ByteByte_ReturnValue;            // 0x0009(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	bool                                          K2Node_SwitchEnum_CmpSuccess_2;                    // 0x000A(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	bool                                          CallFunc_HasReachedDestination_Result;             // 0x000B(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	float                                         CallFunc_GetUnscaledMoveSpeedCurrent_MoveSpeedCurrent; // 0x000C(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         CallFunc_GetAngleToTarget_AngleToTarget;           // 0x0010(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          CallFunc_HasFullPathToTarget_IsValid;              // 0x0014(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_15[0x3];                                       // 0x0015(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	float                                         CallFunc_Abs_ReturnValue;                          // 0x0018(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          CallFunc_Not_PreBool_ReturnValue;                  // 0x001C(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	bool                                          CallFunc_LessEqual_FloatFloat_ReturnValue;         // 0x001D(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	bool                                          CallFunc_SetMoveDirection_RotationSpeed_Changed_1; // 0x001E(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	bool                                          K2Node_SwitchEnum_CmpSuccess_3;                    // 0x001F(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	bool                                          K2Node_SwitchEnum_CmpSuccess_4;                    // 0x0020(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_21[0x3];                                       // 0x0021(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	float                                         CallFunc_GetMoveSpeedValue_Speed;                  // 0x0024(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class AAIController*                          K2Node_Event_OwnerController_2;                    // 0x0028(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class APawn*                                  K2Node_Event_ControlledPawn_2;                     // 0x0030(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          CallFunc_NearlyEqual_FloatFloat_ReturnValue;       // 0x0038(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_39[0x7];                                       // 0x0039(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	class APAWN_Enemy_C*                          K2Node_DynamicCast_AsPAWN_Enemy;                   // 0x0040(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          K2Node_DynamicCast_bSuccess;                       // 0x0048(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_49[0x7];                                       // 0x0049(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	class AAIController*                          K2Node_Event_OwnerController_1;                    // 0x0050(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class APawn*                                  K2Node_Event_ControlledPawn_1;                     // 0x0058(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	int32                                         CallFunc_GetFirstPathObstacleActor_OutStartPathNodeIndex; // 0x0060(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	int32                                         CallFunc_GetFirstPathObstacleActor_OutEndPathNodeIndex; // 0x0064(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class AActor*                                 CallFunc_GetFirstPathObstacleActor_ReturnValue;    // 0x0068(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          CallFunc_IsValid_ReturnValue;                      // 0x0070(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	bool                                          CallFunc_Not_PreBool_ReturnValue_1;                // 0x0071(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_72[0x6];                                       // 0x0072(0x0006)(Fixing Size After Last Property [ Dumper-7 ])
	class AAIController*                          K2Node_Event_OwnerController;                      // 0x0078(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class APawn*                                  K2Node_Event_ControlledPawn;                       // 0x0080(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         K2Node_Event_DeltaSeconds;                         // 0x0088(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FVector                                CallFunc_K2_GetActorLocation_ReturnValue;          // 0x008C(0x000C)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          CallFunc_EqualExactly_VectorVector_ReturnValue;    // 0x0098(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	bool                                          CallFunc_IsValid_ReturnValue_1;                    // 0x0099(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_9A[0x6];                                       // 0x009A(0x0006)(Fixing Size After Last Property [ Dumper-7 ])
	class FString                                 CallFunc_GetDisplayName_ReturnValue;               // 0x00A0(0x0010)(ZeroConstructor, HasGetValueTypeHash)
	class FString                                 CallFunc_Concat_StrStr_ReturnValue;                // 0x00B0(0x0010)(ZeroConstructor, HasGetValueTypeHash)
	class FString                                 CallFunc_Concat_StrStr_ReturnValue_1;              // 0x00C0(0x0010)(ZeroConstructor, HasGetValueTypeHash)
	struct FVector                                CallFunc_K2_GetActorLocation_ReturnValue_1;        // 0x00D0(0x000C)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         CallFunc_GetPlayTimeInSeconds_ReturnValue;         // 0x00DC(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         CallFunc_GetPlayTimeInSeconds_ReturnValue_1;       // 0x00E0(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         CallFunc_Subtract_FloatFloat_ReturnValue;          // 0x00E4(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          CallFunc_Greater_FloatFloat_ReturnValue;           // 0x00E8(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_E9[0x3];                                       // 0x00E9(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	float                                         CallFunc_GetUnscaledMoveSpeedCurrent_MoveSpeedCurrent_1; // 0x00EC(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         CallFunc_GetMoveSpeedValue_Speed_1;                // 0x00F0(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          CallFunc_NearlyEqual_FloatFloat_ReturnValue_1;     // 0x00F4(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	bool                                          CallFunc_Not_PreBool_ReturnValue_2;                // 0x00F5(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	bool                                          CallFunc_BooleanAND_ReturnValue;                   // 0x00F6(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
};
static_assert(alignof(TASK_Move_C_ExecuteUbergraph_TASK_Move) == 0x000008, "Wrong alignment on TASK_Move_C_ExecuteUbergraph_TASK_Move");
static_assert(sizeof(TASK_Move_C_ExecuteUbergraph_TASK_Move) == 0x0000F8, "Wrong size on TASK_Move_C_ExecuteUbergraph_TASK_Move");
static_assert(offsetof(TASK_Move_C_ExecuteUbergraph_TASK_Move, EntryPoint) == 0x000000, "Member 'TASK_Move_C_ExecuteUbergraph_TASK_Move::EntryPoint' has a wrong offset!");
static_assert(offsetof(TASK_Move_C_ExecuteUbergraph_TASK_Move, CallFunc_EqualEqual_ByteByte_ReturnValue) == 0x000004, "Member 'TASK_Move_C_ExecuteUbergraph_TASK_Move::CallFunc_EqualEqual_ByteByte_ReturnValue' has a wrong offset!");
static_assert(offsetof(TASK_Move_C_ExecuteUbergraph_TASK_Move, K2Node_SwitchEnum_CmpSuccess) == 0x000005, "Member 'TASK_Move_C_ExecuteUbergraph_TASK_Move::K2Node_SwitchEnum_CmpSuccess' has a wrong offset!");
static_assert(offsetof(TASK_Move_C_ExecuteUbergraph_TASK_Move, K2Node_SwitchEnum_CmpSuccess_1) == 0x000006, "Member 'TASK_Move_C_ExecuteUbergraph_TASK_Move::K2Node_SwitchEnum_CmpSuccess_1' has a wrong offset!");
static_assert(offsetof(TASK_Move_C_ExecuteUbergraph_TASK_Move, CallFunc_SetBodyRotateSpeed_Changed) == 0x000007, "Member 'TASK_Move_C_ExecuteUbergraph_TASK_Move::CallFunc_SetBodyRotateSpeed_Changed' has a wrong offset!");
static_assert(offsetof(TASK_Move_C_ExecuteUbergraph_TASK_Move, CallFunc_SetMoveDirection_RotationSpeed_Changed) == 0x000008, "Member 'TASK_Move_C_ExecuteUbergraph_TASK_Move::CallFunc_SetMoveDirection_RotationSpeed_Changed' has a wrong offset!");
static_assert(offsetof(TASK_Move_C_ExecuteUbergraph_TASK_Move, CallFunc_NotEqual_ByteByte_ReturnValue) == 0x000009, "Member 'TASK_Move_C_ExecuteUbergraph_TASK_Move::CallFunc_NotEqual_ByteByte_ReturnValue' has a wrong offset!");
static_assert(offsetof(TASK_Move_C_ExecuteUbergraph_TASK_Move, K2Node_SwitchEnum_CmpSuccess_2) == 0x00000A, "Member 'TASK_Move_C_ExecuteUbergraph_TASK_Move::K2Node_SwitchEnum_CmpSuccess_2' has a wrong offset!");
static_assert(offsetof(TASK_Move_C_ExecuteUbergraph_TASK_Move, CallFunc_HasReachedDestination_Result) == 0x00000B, "Member 'TASK_Move_C_ExecuteUbergraph_TASK_Move::CallFunc_HasReachedDestination_Result' has a wrong offset!");
static_assert(offsetof(TASK_Move_C_ExecuteUbergraph_TASK_Move, CallFunc_GetUnscaledMoveSpeedCurrent_MoveSpeedCurrent) == 0x00000C, "Member 'TASK_Move_C_ExecuteUbergraph_TASK_Move::CallFunc_GetUnscaledMoveSpeedCurrent_MoveSpeedCurrent' has a wrong offset!");
static_assert(offsetof(TASK_Move_C_ExecuteUbergraph_TASK_Move, CallFunc_GetAngleToTarget_AngleToTarget) == 0x000010, "Member 'TASK_Move_C_ExecuteUbergraph_TASK_Move::CallFunc_GetAngleToTarget_AngleToTarget' has a wrong offset!");
static_assert(offsetof(TASK_Move_C_ExecuteUbergraph_TASK_Move, CallFunc_HasFullPathToTarget_IsValid) == 0x000014, "Member 'TASK_Move_C_ExecuteUbergraph_TASK_Move::CallFunc_HasFullPathToTarget_IsValid' has a wrong offset!");
static_assert(offsetof(TASK_Move_C_ExecuteUbergraph_TASK_Move, CallFunc_Abs_ReturnValue) == 0x000018, "Member 'TASK_Move_C_ExecuteUbergraph_TASK_Move::CallFunc_Abs_ReturnValue' has a wrong offset!");
static_assert(offsetof(TASK_Move_C_ExecuteUbergraph_TASK_Move, CallFunc_Not_PreBool_ReturnValue) == 0x00001C, "Member 'TASK_Move_C_ExecuteUbergraph_TASK_Move::CallFunc_Not_PreBool_ReturnValue' has a wrong offset!");
static_assert(offsetof(TASK_Move_C_ExecuteUbergraph_TASK_Move, CallFunc_LessEqual_FloatFloat_ReturnValue) == 0x00001D, "Member 'TASK_Move_C_ExecuteUbergraph_TASK_Move::CallFunc_LessEqual_FloatFloat_ReturnValue' has a wrong offset!");
static_assert(offsetof(TASK_Move_C_ExecuteUbergraph_TASK_Move, CallFunc_SetMoveDirection_RotationSpeed_Changed_1) == 0x00001E, "Member 'TASK_Move_C_ExecuteUbergraph_TASK_Move::CallFunc_SetMoveDirection_RotationSpeed_Changed_1' has a wrong offset!");
static_assert(offsetof(TASK_Move_C_ExecuteUbergraph_TASK_Move, K2Node_SwitchEnum_CmpSuccess_3) == 0x00001F, "Member 'TASK_Move_C_ExecuteUbergraph_TASK_Move::K2Node_SwitchEnum_CmpSuccess_3' has a wrong offset!");
static_assert(offsetof(TASK_Move_C_ExecuteUbergraph_TASK_Move, K2Node_SwitchEnum_CmpSuccess_4) == 0x000020, "Member 'TASK_Move_C_ExecuteUbergraph_TASK_Move::K2Node_SwitchEnum_CmpSuccess_4' has a wrong offset!");
static_assert(offsetof(TASK_Move_C_ExecuteUbergraph_TASK_Move, CallFunc_GetMoveSpeedValue_Speed) == 0x000024, "Member 'TASK_Move_C_ExecuteUbergraph_TASK_Move::CallFunc_GetMoveSpeedValue_Speed' has a wrong offset!");
static_assert(offsetof(TASK_Move_C_ExecuteUbergraph_TASK_Move, K2Node_Event_OwnerController_2) == 0x000028, "Member 'TASK_Move_C_ExecuteUbergraph_TASK_Move::K2Node_Event_OwnerController_2' has a wrong offset!");
static_assert(offsetof(TASK_Move_C_ExecuteUbergraph_TASK_Move, K2Node_Event_ControlledPawn_2) == 0x000030, "Member 'TASK_Move_C_ExecuteUbergraph_TASK_Move::K2Node_Event_ControlledPawn_2' has a wrong offset!");
static_assert(offsetof(TASK_Move_C_ExecuteUbergraph_TASK_Move, CallFunc_NearlyEqual_FloatFloat_ReturnValue) == 0x000038, "Member 'TASK_Move_C_ExecuteUbergraph_TASK_Move::CallFunc_NearlyEqual_FloatFloat_ReturnValue' has a wrong offset!");
static_assert(offsetof(TASK_Move_C_ExecuteUbergraph_TASK_Move, K2Node_DynamicCast_AsPAWN_Enemy) == 0x000040, "Member 'TASK_Move_C_ExecuteUbergraph_TASK_Move::K2Node_DynamicCast_AsPAWN_Enemy' has a wrong offset!");
static_assert(offsetof(TASK_Move_C_ExecuteUbergraph_TASK_Move, K2Node_DynamicCast_bSuccess) == 0x000048, "Member 'TASK_Move_C_ExecuteUbergraph_TASK_Move::K2Node_DynamicCast_bSuccess' has a wrong offset!");
static_assert(offsetof(TASK_Move_C_ExecuteUbergraph_TASK_Move, K2Node_Event_OwnerController_1) == 0x000050, "Member 'TASK_Move_C_ExecuteUbergraph_TASK_Move::K2Node_Event_OwnerController_1' has a wrong offset!");
static_assert(offsetof(TASK_Move_C_ExecuteUbergraph_TASK_Move, K2Node_Event_ControlledPawn_1) == 0x000058, "Member 'TASK_Move_C_ExecuteUbergraph_TASK_Move::K2Node_Event_ControlledPawn_1' has a wrong offset!");
static_assert(offsetof(TASK_Move_C_ExecuteUbergraph_TASK_Move, CallFunc_GetFirstPathObstacleActor_OutStartPathNodeIndex) == 0x000060, "Member 'TASK_Move_C_ExecuteUbergraph_TASK_Move::CallFunc_GetFirstPathObstacleActor_OutStartPathNodeIndex' has a wrong offset!");
static_assert(offsetof(TASK_Move_C_ExecuteUbergraph_TASK_Move, CallFunc_GetFirstPathObstacleActor_OutEndPathNodeIndex) == 0x000064, "Member 'TASK_Move_C_ExecuteUbergraph_TASK_Move::CallFunc_GetFirstPathObstacleActor_OutEndPathNodeIndex' has a wrong offset!");
static_assert(offsetof(TASK_Move_C_ExecuteUbergraph_TASK_Move, CallFunc_GetFirstPathObstacleActor_ReturnValue) == 0x000068, "Member 'TASK_Move_C_ExecuteUbergraph_TASK_Move::CallFunc_GetFirstPathObstacleActor_ReturnValue' has a wrong offset!");
static_assert(offsetof(TASK_Move_C_ExecuteUbergraph_TASK_Move, CallFunc_IsValid_ReturnValue) == 0x000070, "Member 'TASK_Move_C_ExecuteUbergraph_TASK_Move::CallFunc_IsValid_ReturnValue' has a wrong offset!");
static_assert(offsetof(TASK_Move_C_ExecuteUbergraph_TASK_Move, CallFunc_Not_PreBool_ReturnValue_1) == 0x000071, "Member 'TASK_Move_C_ExecuteUbergraph_TASK_Move::CallFunc_Not_PreBool_ReturnValue_1' has a wrong offset!");
static_assert(offsetof(TASK_Move_C_ExecuteUbergraph_TASK_Move, K2Node_Event_OwnerController) == 0x000078, "Member 'TASK_Move_C_ExecuteUbergraph_TASK_Move::K2Node_Event_OwnerController' has a wrong offset!");
static_assert(offsetof(TASK_Move_C_ExecuteUbergraph_TASK_Move, K2Node_Event_ControlledPawn) == 0x000080, "Member 'TASK_Move_C_ExecuteUbergraph_TASK_Move::K2Node_Event_ControlledPawn' has a wrong offset!");
static_assert(offsetof(TASK_Move_C_ExecuteUbergraph_TASK_Move, K2Node_Event_DeltaSeconds) == 0x000088, "Member 'TASK_Move_C_ExecuteUbergraph_TASK_Move::K2Node_Event_DeltaSeconds' has a wrong offset!");
static_assert(offsetof(TASK_Move_C_ExecuteUbergraph_TASK_Move, CallFunc_K2_GetActorLocation_ReturnValue) == 0x00008C, "Member 'TASK_Move_C_ExecuteUbergraph_TASK_Move::CallFunc_K2_GetActorLocation_ReturnValue' has a wrong offset!");
static_assert(offsetof(TASK_Move_C_ExecuteUbergraph_TASK_Move, CallFunc_EqualExactly_VectorVector_ReturnValue) == 0x000098, "Member 'TASK_Move_C_ExecuteUbergraph_TASK_Move::CallFunc_EqualExactly_VectorVector_ReturnValue' has a wrong offset!");
static_assert(offsetof(TASK_Move_C_ExecuteUbergraph_TASK_Move, CallFunc_IsValid_ReturnValue_1) == 0x000099, "Member 'TASK_Move_C_ExecuteUbergraph_TASK_Move::CallFunc_IsValid_ReturnValue_1' has a wrong offset!");
static_assert(offsetof(TASK_Move_C_ExecuteUbergraph_TASK_Move, CallFunc_GetDisplayName_ReturnValue) == 0x0000A0, "Member 'TASK_Move_C_ExecuteUbergraph_TASK_Move::CallFunc_GetDisplayName_ReturnValue' has a wrong offset!");
static_assert(offsetof(TASK_Move_C_ExecuteUbergraph_TASK_Move, CallFunc_Concat_StrStr_ReturnValue) == 0x0000B0, "Member 'TASK_Move_C_ExecuteUbergraph_TASK_Move::CallFunc_Concat_StrStr_ReturnValue' has a wrong offset!");
static_assert(offsetof(TASK_Move_C_ExecuteUbergraph_TASK_Move, CallFunc_Concat_StrStr_ReturnValue_1) == 0x0000C0, "Member 'TASK_Move_C_ExecuteUbergraph_TASK_Move::CallFunc_Concat_StrStr_ReturnValue_1' has a wrong offset!");
static_assert(offsetof(TASK_Move_C_ExecuteUbergraph_TASK_Move, CallFunc_K2_GetActorLocation_ReturnValue_1) == 0x0000D0, "Member 'TASK_Move_C_ExecuteUbergraph_TASK_Move::CallFunc_K2_GetActorLocation_ReturnValue_1' has a wrong offset!");
static_assert(offsetof(TASK_Move_C_ExecuteUbergraph_TASK_Move, CallFunc_GetPlayTimeInSeconds_ReturnValue) == 0x0000DC, "Member 'TASK_Move_C_ExecuteUbergraph_TASK_Move::CallFunc_GetPlayTimeInSeconds_ReturnValue' has a wrong offset!");
static_assert(offsetof(TASK_Move_C_ExecuteUbergraph_TASK_Move, CallFunc_GetPlayTimeInSeconds_ReturnValue_1) == 0x0000E0, "Member 'TASK_Move_C_ExecuteUbergraph_TASK_Move::CallFunc_GetPlayTimeInSeconds_ReturnValue_1' has a wrong offset!");
static_assert(offsetof(TASK_Move_C_ExecuteUbergraph_TASK_Move, CallFunc_Subtract_FloatFloat_ReturnValue) == 0x0000E4, "Member 'TASK_Move_C_ExecuteUbergraph_TASK_Move::CallFunc_Subtract_FloatFloat_ReturnValue' has a wrong offset!");
static_assert(offsetof(TASK_Move_C_ExecuteUbergraph_TASK_Move, CallFunc_Greater_FloatFloat_ReturnValue) == 0x0000E8, "Member 'TASK_Move_C_ExecuteUbergraph_TASK_Move::CallFunc_Greater_FloatFloat_ReturnValue' has a wrong offset!");
static_assert(offsetof(TASK_Move_C_ExecuteUbergraph_TASK_Move, CallFunc_GetUnscaledMoveSpeedCurrent_MoveSpeedCurrent_1) == 0x0000EC, "Member 'TASK_Move_C_ExecuteUbergraph_TASK_Move::CallFunc_GetUnscaledMoveSpeedCurrent_MoveSpeedCurrent_1' has a wrong offset!");
static_assert(offsetof(TASK_Move_C_ExecuteUbergraph_TASK_Move, CallFunc_GetMoveSpeedValue_Speed_1) == 0x0000F0, "Member 'TASK_Move_C_ExecuteUbergraph_TASK_Move::CallFunc_GetMoveSpeedValue_Speed_1' has a wrong offset!");
static_assert(offsetof(TASK_Move_C_ExecuteUbergraph_TASK_Move, CallFunc_NearlyEqual_FloatFloat_ReturnValue_1) == 0x0000F4, "Member 'TASK_Move_C_ExecuteUbergraph_TASK_Move::CallFunc_NearlyEqual_FloatFloat_ReturnValue_1' has a wrong offset!");
static_assert(offsetof(TASK_Move_C_ExecuteUbergraph_TASK_Move, CallFunc_Not_PreBool_ReturnValue_2) == 0x0000F5, "Member 'TASK_Move_C_ExecuteUbergraph_TASK_Move::CallFunc_Not_PreBool_ReturnValue_2' has a wrong offset!");
static_assert(offsetof(TASK_Move_C_ExecuteUbergraph_TASK_Move, CallFunc_BooleanAND_ReturnValue) == 0x0000F6, "Member 'TASK_Move_C_ExecuteUbergraph_TASK_Move::CallFunc_BooleanAND_ReturnValue' has a wrong offset!");

// Function TASK_Move.TASK_Move_C.ReceiveTickAI
// 0x0018 (0x0018 - 0x0000)
struct TASK_Move_C_ReceiveTickAI final
{
public:
	class AAIController*                          OwnerController;                                   // 0x0000(0x0008)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class APawn*                                  ControlledPawn;                                    // 0x0008(0x0008)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         DeltaSeconds;                                      // 0x0010(0x0004)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
};
static_assert(alignof(TASK_Move_C_ReceiveTickAI) == 0x000008, "Wrong alignment on TASK_Move_C_ReceiveTickAI");
static_assert(sizeof(TASK_Move_C_ReceiveTickAI) == 0x000018, "Wrong size on TASK_Move_C_ReceiveTickAI");
static_assert(offsetof(TASK_Move_C_ReceiveTickAI, OwnerController) == 0x000000, "Member 'TASK_Move_C_ReceiveTickAI::OwnerController' has a wrong offset!");
static_assert(offsetof(TASK_Move_C_ReceiveTickAI, ControlledPawn) == 0x000008, "Member 'TASK_Move_C_ReceiveTickAI::ControlledPawn' has a wrong offset!");
static_assert(offsetof(TASK_Move_C_ReceiveTickAI, DeltaSeconds) == 0x000010, "Member 'TASK_Move_C_ReceiveTickAI::DeltaSeconds' has a wrong offset!");

// Function TASK_Move.TASK_Move_C.ReceiveAbortAI
// 0x0010 (0x0010 - 0x0000)
struct TASK_Move_C_ReceiveAbortAI final
{
public:
	class AAIController*                          OwnerController;                                   // 0x0000(0x0008)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class APawn*                                  ControlledPawn;                                    // 0x0008(0x0008)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
};
static_assert(alignof(TASK_Move_C_ReceiveAbortAI) == 0x000008, "Wrong alignment on TASK_Move_C_ReceiveAbortAI");
static_assert(sizeof(TASK_Move_C_ReceiveAbortAI) == 0x000010, "Wrong size on TASK_Move_C_ReceiveAbortAI");
static_assert(offsetof(TASK_Move_C_ReceiveAbortAI, OwnerController) == 0x000000, "Member 'TASK_Move_C_ReceiveAbortAI::OwnerController' has a wrong offset!");
static_assert(offsetof(TASK_Move_C_ReceiveAbortAI, ControlledPawn) == 0x000008, "Member 'TASK_Move_C_ReceiveAbortAI::ControlledPawn' has a wrong offset!");

// Function TASK_Move.TASK_Move_C.ReceiveExecuteAI
// 0x0010 (0x0010 - 0x0000)
struct TASK_Move_C_ReceiveExecuteAI final
{
public:
	class AAIController*                          OwnerController;                                   // 0x0000(0x0008)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class APawn*                                  ControlledPawn;                                    // 0x0008(0x0008)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
};
static_assert(alignof(TASK_Move_C_ReceiveExecuteAI) == 0x000008, "Wrong alignment on TASK_Move_C_ReceiveExecuteAI");
static_assert(sizeof(TASK_Move_C_ReceiveExecuteAI) == 0x000010, "Wrong size on TASK_Move_C_ReceiveExecuteAI");
static_assert(offsetof(TASK_Move_C_ReceiveExecuteAI, OwnerController) == 0x000000, "Member 'TASK_Move_C_ReceiveExecuteAI::OwnerController' has a wrong offset!");
static_assert(offsetof(TASK_Move_C_ReceiveExecuteAI, ControlledPawn) == 0x000008, "Member 'TASK_Move_C_ReceiveExecuteAI::ControlledPawn' has a wrong offset!");

}

