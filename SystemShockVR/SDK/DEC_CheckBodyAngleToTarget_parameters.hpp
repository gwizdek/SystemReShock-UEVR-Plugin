#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: DEC_CheckBodyAngleToTarget

#include "Basic.hpp"

#include "CoreUObject_structs.hpp"


namespace SDK::Params
{

// Function DEC_CheckBodyAngleToTarget.DEC_CheckBodyAngleToTarget_C.PerformConditionCheckAI
// 0x0140 (0x0140 - 0x0000)
struct DEC_CheckBodyAngleToTarget_C_PerformConditionCheckAI final
{
public:
	class AAIController*                          OwnerController;                                   // 0x0000(0x0008)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class APawn*                                  ControlledPawn;                                    // 0x0008(0x0008)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          ReturnValue;                                       // 0x0010(0x0001)(Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData, NoDestructor)
	uint8                                         Pad_11[0x3];                                       // 0x0011(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	struct FVector                                TargetDirection;                                   // 0x0014(0x000C)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FVector                                CurrentDirection;                                  // 0x0020(0x000C)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         AngleToTarget;                                     // 0x002C(0x0004)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class APAWN_Enemy_C*                          Enemy;                                             // 0x0030(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnTemplate, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class APAWN_Enemy_C*                          K2Node_DynamicCast_AsPAWN_Enemy;                   // 0x0038(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          K2Node_DynamicCast_bSuccess;                       // 0x0040(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_41[0x3];                                       // 0x0041(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	struct FVector                                CallFunc_GetActorForwardVector_ReturnValue;        // 0x0044(0x000C)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         CallFunc_BreakVector_X;                            // 0x0050(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         CallFunc_BreakVector_Y;                            // 0x0054(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         CallFunc_BreakVector_Z;                            // 0x0058(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         CallFunc_BreakVector_X_1;                          // 0x005C(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         CallFunc_BreakVector_Y_1;                          // 0x0060(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         CallFunc_BreakVector_Z_1;                          // 0x0064(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FVector                                CallFunc_MakeVector_ReturnValue;                   // 0x0068(0x000C)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FVector                                CallFunc_MakeVector_ReturnValue_1;                 // 0x0074(0x000C)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FVector                                CallFunc_Normal_ReturnValue;                       // 0x0080(0x000C)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FVector                                CallFunc_Normal_ReturnValue_1;                     // 0x008C(0x000C)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         CallFunc_SignedAngleBetweenNormals_ReturnValue;    // 0x0098(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          CallFunc_Not_PreBool_ReturnValue;                  // 0x009C(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_9D[0x3];                                       // 0x009D(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	float                                         CallFunc_Abs_ReturnValue;                          // 0x00A0(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         CallFunc_BreakVector_X_2;                          // 0x00A4(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         CallFunc_BreakVector_Y_2;                          // 0x00A8(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         CallFunc_BreakVector_Z_2;                          // 0x00AC(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FVector                                CallFunc_MakeVector_ReturnValue_2;                 // 0x00B0(0x000C)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FVector                                CallFunc_Normal_ReturnValue_2;                     // 0x00BC(0x000C)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         CallFunc_BreakVector_X_3;                          // 0x00C8(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         CallFunc_BreakVector_Y_3;                          // 0x00CC(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         CallFunc_BreakVector_Z_3;                          // 0x00D0(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FVector                                CallFunc_MakeVector_ReturnValue_3;                 // 0x00D4(0x000C)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FVector                                CallFunc_Normal_ReturnValue_3;                     // 0x00E0(0x000C)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FVector                                CallFunc_Normal_ReturnValue_4;                     // 0x00EC(0x000C)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         CallFunc_SignedAngleBetweenNormals_ReturnValue_1;  // 0x00F8(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         CallFunc_SignedAngleBetweenNormals_ReturnValue_2;  // 0x00FC(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UOBJ_EnemyTarget_C*                     CallFunc_GetTarget_Target;                         // 0x0100(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FVector                                CallFunc_Get_Target_Direction_Direction;           // 0x0108(0x000C)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FVector                                CallFunc_GetBodyDirectionCurrent_BodyDirectionCurrent; // 0x0114(0x000C)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FVector                                CallFunc_SelectVector_ReturnValue;                 // 0x0120(0x000C)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          CallFunc_NearlyEqual_FloatFloat_ReturnValue;       // 0x012C(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_12D[0x3];                                      // 0x012D(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	class UOBJ_EnemyTarget_C*                     CallFunc_GetTarget_Target_1;                       // 0x0130(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          CallFunc_IsValid_ReturnValue;                      // 0x0138(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	bool                                          CallFunc_LessEqual_FloatFloat_ReturnValue;         // 0x0139(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	bool                                          K2Node_SwitchEnum_CmpSuccess;                      // 0x013A(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	bool                                          CallFunc_GreaterEqual_FloatFloat_ReturnValue;      // 0x013B(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	bool                                          K2Node_SwitchEnum_CmpSuccess_1;                    // 0x013C(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
};
static_assert(alignof(DEC_CheckBodyAngleToTarget_C_PerformConditionCheckAI) == 0x000008, "Wrong alignment on DEC_CheckBodyAngleToTarget_C_PerformConditionCheckAI");
static_assert(sizeof(DEC_CheckBodyAngleToTarget_C_PerformConditionCheckAI) == 0x000140, "Wrong size on DEC_CheckBodyAngleToTarget_C_PerformConditionCheckAI");
static_assert(offsetof(DEC_CheckBodyAngleToTarget_C_PerformConditionCheckAI, OwnerController) == 0x000000, "Member 'DEC_CheckBodyAngleToTarget_C_PerformConditionCheckAI::OwnerController' has a wrong offset!");
static_assert(offsetof(DEC_CheckBodyAngleToTarget_C_PerformConditionCheckAI, ControlledPawn) == 0x000008, "Member 'DEC_CheckBodyAngleToTarget_C_PerformConditionCheckAI::ControlledPawn' has a wrong offset!");
static_assert(offsetof(DEC_CheckBodyAngleToTarget_C_PerformConditionCheckAI, ReturnValue) == 0x000010, "Member 'DEC_CheckBodyAngleToTarget_C_PerformConditionCheckAI::ReturnValue' has a wrong offset!");
static_assert(offsetof(DEC_CheckBodyAngleToTarget_C_PerformConditionCheckAI, TargetDirection) == 0x000014, "Member 'DEC_CheckBodyAngleToTarget_C_PerformConditionCheckAI::TargetDirection' has a wrong offset!");
static_assert(offsetof(DEC_CheckBodyAngleToTarget_C_PerformConditionCheckAI, CurrentDirection) == 0x000020, "Member 'DEC_CheckBodyAngleToTarget_C_PerformConditionCheckAI::CurrentDirection' has a wrong offset!");
static_assert(offsetof(DEC_CheckBodyAngleToTarget_C_PerformConditionCheckAI, AngleToTarget) == 0x00002C, "Member 'DEC_CheckBodyAngleToTarget_C_PerformConditionCheckAI::AngleToTarget' has a wrong offset!");
static_assert(offsetof(DEC_CheckBodyAngleToTarget_C_PerformConditionCheckAI, Enemy) == 0x000030, "Member 'DEC_CheckBodyAngleToTarget_C_PerformConditionCheckAI::Enemy' has a wrong offset!");
static_assert(offsetof(DEC_CheckBodyAngleToTarget_C_PerformConditionCheckAI, K2Node_DynamicCast_AsPAWN_Enemy) == 0x000038, "Member 'DEC_CheckBodyAngleToTarget_C_PerformConditionCheckAI::K2Node_DynamicCast_AsPAWN_Enemy' has a wrong offset!");
static_assert(offsetof(DEC_CheckBodyAngleToTarget_C_PerformConditionCheckAI, K2Node_DynamicCast_bSuccess) == 0x000040, "Member 'DEC_CheckBodyAngleToTarget_C_PerformConditionCheckAI::K2Node_DynamicCast_bSuccess' has a wrong offset!");
static_assert(offsetof(DEC_CheckBodyAngleToTarget_C_PerformConditionCheckAI, CallFunc_GetActorForwardVector_ReturnValue) == 0x000044, "Member 'DEC_CheckBodyAngleToTarget_C_PerformConditionCheckAI::CallFunc_GetActorForwardVector_ReturnValue' has a wrong offset!");
static_assert(offsetof(DEC_CheckBodyAngleToTarget_C_PerformConditionCheckAI, CallFunc_BreakVector_X) == 0x000050, "Member 'DEC_CheckBodyAngleToTarget_C_PerformConditionCheckAI::CallFunc_BreakVector_X' has a wrong offset!");
static_assert(offsetof(DEC_CheckBodyAngleToTarget_C_PerformConditionCheckAI, CallFunc_BreakVector_Y) == 0x000054, "Member 'DEC_CheckBodyAngleToTarget_C_PerformConditionCheckAI::CallFunc_BreakVector_Y' has a wrong offset!");
static_assert(offsetof(DEC_CheckBodyAngleToTarget_C_PerformConditionCheckAI, CallFunc_BreakVector_Z) == 0x000058, "Member 'DEC_CheckBodyAngleToTarget_C_PerformConditionCheckAI::CallFunc_BreakVector_Z' has a wrong offset!");
static_assert(offsetof(DEC_CheckBodyAngleToTarget_C_PerformConditionCheckAI, CallFunc_BreakVector_X_1) == 0x00005C, "Member 'DEC_CheckBodyAngleToTarget_C_PerformConditionCheckAI::CallFunc_BreakVector_X_1' has a wrong offset!");
static_assert(offsetof(DEC_CheckBodyAngleToTarget_C_PerformConditionCheckAI, CallFunc_BreakVector_Y_1) == 0x000060, "Member 'DEC_CheckBodyAngleToTarget_C_PerformConditionCheckAI::CallFunc_BreakVector_Y_1' has a wrong offset!");
static_assert(offsetof(DEC_CheckBodyAngleToTarget_C_PerformConditionCheckAI, CallFunc_BreakVector_Z_1) == 0x000064, "Member 'DEC_CheckBodyAngleToTarget_C_PerformConditionCheckAI::CallFunc_BreakVector_Z_1' has a wrong offset!");
static_assert(offsetof(DEC_CheckBodyAngleToTarget_C_PerformConditionCheckAI, CallFunc_MakeVector_ReturnValue) == 0x000068, "Member 'DEC_CheckBodyAngleToTarget_C_PerformConditionCheckAI::CallFunc_MakeVector_ReturnValue' has a wrong offset!");
static_assert(offsetof(DEC_CheckBodyAngleToTarget_C_PerformConditionCheckAI, CallFunc_MakeVector_ReturnValue_1) == 0x000074, "Member 'DEC_CheckBodyAngleToTarget_C_PerformConditionCheckAI::CallFunc_MakeVector_ReturnValue_1' has a wrong offset!");
static_assert(offsetof(DEC_CheckBodyAngleToTarget_C_PerformConditionCheckAI, CallFunc_Normal_ReturnValue) == 0x000080, "Member 'DEC_CheckBodyAngleToTarget_C_PerformConditionCheckAI::CallFunc_Normal_ReturnValue' has a wrong offset!");
static_assert(offsetof(DEC_CheckBodyAngleToTarget_C_PerformConditionCheckAI, CallFunc_Normal_ReturnValue_1) == 0x00008C, "Member 'DEC_CheckBodyAngleToTarget_C_PerformConditionCheckAI::CallFunc_Normal_ReturnValue_1' has a wrong offset!");
static_assert(offsetof(DEC_CheckBodyAngleToTarget_C_PerformConditionCheckAI, CallFunc_SignedAngleBetweenNormals_ReturnValue) == 0x000098, "Member 'DEC_CheckBodyAngleToTarget_C_PerformConditionCheckAI::CallFunc_SignedAngleBetweenNormals_ReturnValue' has a wrong offset!");
static_assert(offsetof(DEC_CheckBodyAngleToTarget_C_PerformConditionCheckAI, CallFunc_Not_PreBool_ReturnValue) == 0x00009C, "Member 'DEC_CheckBodyAngleToTarget_C_PerformConditionCheckAI::CallFunc_Not_PreBool_ReturnValue' has a wrong offset!");
static_assert(offsetof(DEC_CheckBodyAngleToTarget_C_PerformConditionCheckAI, CallFunc_Abs_ReturnValue) == 0x0000A0, "Member 'DEC_CheckBodyAngleToTarget_C_PerformConditionCheckAI::CallFunc_Abs_ReturnValue' has a wrong offset!");
static_assert(offsetof(DEC_CheckBodyAngleToTarget_C_PerformConditionCheckAI, CallFunc_BreakVector_X_2) == 0x0000A4, "Member 'DEC_CheckBodyAngleToTarget_C_PerformConditionCheckAI::CallFunc_BreakVector_X_2' has a wrong offset!");
static_assert(offsetof(DEC_CheckBodyAngleToTarget_C_PerformConditionCheckAI, CallFunc_BreakVector_Y_2) == 0x0000A8, "Member 'DEC_CheckBodyAngleToTarget_C_PerformConditionCheckAI::CallFunc_BreakVector_Y_2' has a wrong offset!");
static_assert(offsetof(DEC_CheckBodyAngleToTarget_C_PerformConditionCheckAI, CallFunc_BreakVector_Z_2) == 0x0000AC, "Member 'DEC_CheckBodyAngleToTarget_C_PerformConditionCheckAI::CallFunc_BreakVector_Z_2' has a wrong offset!");
static_assert(offsetof(DEC_CheckBodyAngleToTarget_C_PerformConditionCheckAI, CallFunc_MakeVector_ReturnValue_2) == 0x0000B0, "Member 'DEC_CheckBodyAngleToTarget_C_PerformConditionCheckAI::CallFunc_MakeVector_ReturnValue_2' has a wrong offset!");
static_assert(offsetof(DEC_CheckBodyAngleToTarget_C_PerformConditionCheckAI, CallFunc_Normal_ReturnValue_2) == 0x0000BC, "Member 'DEC_CheckBodyAngleToTarget_C_PerformConditionCheckAI::CallFunc_Normal_ReturnValue_2' has a wrong offset!");
static_assert(offsetof(DEC_CheckBodyAngleToTarget_C_PerformConditionCheckAI, CallFunc_BreakVector_X_3) == 0x0000C8, "Member 'DEC_CheckBodyAngleToTarget_C_PerformConditionCheckAI::CallFunc_BreakVector_X_3' has a wrong offset!");
static_assert(offsetof(DEC_CheckBodyAngleToTarget_C_PerformConditionCheckAI, CallFunc_BreakVector_Y_3) == 0x0000CC, "Member 'DEC_CheckBodyAngleToTarget_C_PerformConditionCheckAI::CallFunc_BreakVector_Y_3' has a wrong offset!");
static_assert(offsetof(DEC_CheckBodyAngleToTarget_C_PerformConditionCheckAI, CallFunc_BreakVector_Z_3) == 0x0000D0, "Member 'DEC_CheckBodyAngleToTarget_C_PerformConditionCheckAI::CallFunc_BreakVector_Z_3' has a wrong offset!");
static_assert(offsetof(DEC_CheckBodyAngleToTarget_C_PerformConditionCheckAI, CallFunc_MakeVector_ReturnValue_3) == 0x0000D4, "Member 'DEC_CheckBodyAngleToTarget_C_PerformConditionCheckAI::CallFunc_MakeVector_ReturnValue_3' has a wrong offset!");
static_assert(offsetof(DEC_CheckBodyAngleToTarget_C_PerformConditionCheckAI, CallFunc_Normal_ReturnValue_3) == 0x0000E0, "Member 'DEC_CheckBodyAngleToTarget_C_PerformConditionCheckAI::CallFunc_Normal_ReturnValue_3' has a wrong offset!");
static_assert(offsetof(DEC_CheckBodyAngleToTarget_C_PerformConditionCheckAI, CallFunc_Normal_ReturnValue_4) == 0x0000EC, "Member 'DEC_CheckBodyAngleToTarget_C_PerformConditionCheckAI::CallFunc_Normal_ReturnValue_4' has a wrong offset!");
static_assert(offsetof(DEC_CheckBodyAngleToTarget_C_PerformConditionCheckAI, CallFunc_SignedAngleBetweenNormals_ReturnValue_1) == 0x0000F8, "Member 'DEC_CheckBodyAngleToTarget_C_PerformConditionCheckAI::CallFunc_SignedAngleBetweenNormals_ReturnValue_1' has a wrong offset!");
static_assert(offsetof(DEC_CheckBodyAngleToTarget_C_PerformConditionCheckAI, CallFunc_SignedAngleBetweenNormals_ReturnValue_2) == 0x0000FC, "Member 'DEC_CheckBodyAngleToTarget_C_PerformConditionCheckAI::CallFunc_SignedAngleBetweenNormals_ReturnValue_2' has a wrong offset!");
static_assert(offsetof(DEC_CheckBodyAngleToTarget_C_PerformConditionCheckAI, CallFunc_GetTarget_Target) == 0x000100, "Member 'DEC_CheckBodyAngleToTarget_C_PerformConditionCheckAI::CallFunc_GetTarget_Target' has a wrong offset!");
static_assert(offsetof(DEC_CheckBodyAngleToTarget_C_PerformConditionCheckAI, CallFunc_Get_Target_Direction_Direction) == 0x000108, "Member 'DEC_CheckBodyAngleToTarget_C_PerformConditionCheckAI::CallFunc_Get_Target_Direction_Direction' has a wrong offset!");
static_assert(offsetof(DEC_CheckBodyAngleToTarget_C_PerformConditionCheckAI, CallFunc_GetBodyDirectionCurrent_BodyDirectionCurrent) == 0x000114, "Member 'DEC_CheckBodyAngleToTarget_C_PerformConditionCheckAI::CallFunc_GetBodyDirectionCurrent_BodyDirectionCurrent' has a wrong offset!");
static_assert(offsetof(DEC_CheckBodyAngleToTarget_C_PerformConditionCheckAI, CallFunc_SelectVector_ReturnValue) == 0x000120, "Member 'DEC_CheckBodyAngleToTarget_C_PerformConditionCheckAI::CallFunc_SelectVector_ReturnValue' has a wrong offset!");
static_assert(offsetof(DEC_CheckBodyAngleToTarget_C_PerformConditionCheckAI, CallFunc_NearlyEqual_FloatFloat_ReturnValue) == 0x00012C, "Member 'DEC_CheckBodyAngleToTarget_C_PerformConditionCheckAI::CallFunc_NearlyEqual_FloatFloat_ReturnValue' has a wrong offset!");
static_assert(offsetof(DEC_CheckBodyAngleToTarget_C_PerformConditionCheckAI, CallFunc_GetTarget_Target_1) == 0x000130, "Member 'DEC_CheckBodyAngleToTarget_C_PerformConditionCheckAI::CallFunc_GetTarget_Target_1' has a wrong offset!");
static_assert(offsetof(DEC_CheckBodyAngleToTarget_C_PerformConditionCheckAI, CallFunc_IsValid_ReturnValue) == 0x000138, "Member 'DEC_CheckBodyAngleToTarget_C_PerformConditionCheckAI::CallFunc_IsValid_ReturnValue' has a wrong offset!");
static_assert(offsetof(DEC_CheckBodyAngleToTarget_C_PerformConditionCheckAI, CallFunc_LessEqual_FloatFloat_ReturnValue) == 0x000139, "Member 'DEC_CheckBodyAngleToTarget_C_PerformConditionCheckAI::CallFunc_LessEqual_FloatFloat_ReturnValue' has a wrong offset!");
static_assert(offsetof(DEC_CheckBodyAngleToTarget_C_PerformConditionCheckAI, K2Node_SwitchEnum_CmpSuccess) == 0x00013A, "Member 'DEC_CheckBodyAngleToTarget_C_PerformConditionCheckAI::K2Node_SwitchEnum_CmpSuccess' has a wrong offset!");
static_assert(offsetof(DEC_CheckBodyAngleToTarget_C_PerformConditionCheckAI, CallFunc_GreaterEqual_FloatFloat_ReturnValue) == 0x00013B, "Member 'DEC_CheckBodyAngleToTarget_C_PerformConditionCheckAI::CallFunc_GreaterEqual_FloatFloat_ReturnValue' has a wrong offset!");
static_assert(offsetof(DEC_CheckBodyAngleToTarget_C_PerformConditionCheckAI, K2Node_SwitchEnum_CmpSuccess_1) == 0x00013C, "Member 'DEC_CheckBodyAngleToTarget_C_PerformConditionCheckAI::K2Node_SwitchEnum_CmpSuccess_1' has a wrong offset!");

}

