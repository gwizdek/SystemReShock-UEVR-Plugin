#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: PAWN_Diego_v1

#include "Basic.hpp"

#include "Engine_structs.hpp"


namespace SDK::Params
{

// Function PAWN_Diego_v1.PAWN_Diego_v1_C.ExecuteUbergraph_PAWN_Diego_v1
// 0x0070 (0x0070 - 0x0000)
struct PAWN_Diego_v1_C_ExecuteUbergraph_PAWN_Diego_v1 final
{
public:
	int32                                         EntryPoint;                                        // 0x0000(0x0004)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	TDelegate<void(float CurrValue, float LastValue)> K2Node_CreateDelegate_OutputDelegate;              // 0x0004(0x0010)(ZeroConstructor, NoDestructor)
	TDelegate<void()>                             K2Node_CreateDelegate_OutputDelegate_1;            // 0x0014(0x0010)(ZeroConstructor, NoDestructor)
	uint8                                         Pad_24[0x4];                                       // 0x0024(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	struct FTimerHandle                           CallFunc_K2_SetTimerDelegate_ReturnValue;          // 0x0028(0x0008)(NoDestructor, HasGetValueTypeHash)
	float                                         K2Node_CustomEvent_CurrValue;                      // 0x0030(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         K2Node_CustomEvent_LastValue;                      // 0x0034(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          CallFunc_Less_FloatFloat_ReturnValue;              // 0x0038(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_39[0x7];                                       // 0x0039(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	class UAnimInstance*                          CallFunc_GetAnimInstance_ReturnValue;              // 0x0040(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UANIMBP_DiegoV1_C*                      K2Node_DynamicCast_AsANIMBP_Diego_V1;              // 0x0048(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          K2Node_DynamicCast_bSuccess;                       // 0x0050(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	bool                                          CallFunc_SetUseArmProtection_Results;              // 0x0051(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_52[0x6];                                       // 0x0052(0x0006)(Fixing Size After Last Property [ Dumper-7 ])
	class UAnimInstance*                          CallFunc_GetAnimInstance_ReturnValue_1;            // 0x0058(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UANIMBP_DiegoV1_C*                      K2Node_DynamicCast_AsANIMBP_Diego_V1_1;            // 0x0060(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          K2Node_DynamicCast_bSuccess_1;                     // 0x0068(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	bool                                          CallFunc_SetUseArmProtection_Results_1;            // 0x0069(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
};
static_assert(alignof(PAWN_Diego_v1_C_ExecuteUbergraph_PAWN_Diego_v1) == 0x000008, "Wrong alignment on PAWN_Diego_v1_C_ExecuteUbergraph_PAWN_Diego_v1");
static_assert(sizeof(PAWN_Diego_v1_C_ExecuteUbergraph_PAWN_Diego_v1) == 0x000070, "Wrong size on PAWN_Diego_v1_C_ExecuteUbergraph_PAWN_Diego_v1");
static_assert(offsetof(PAWN_Diego_v1_C_ExecuteUbergraph_PAWN_Diego_v1, EntryPoint) == 0x000000, "Member 'PAWN_Diego_v1_C_ExecuteUbergraph_PAWN_Diego_v1::EntryPoint' has a wrong offset!");
static_assert(offsetof(PAWN_Diego_v1_C_ExecuteUbergraph_PAWN_Diego_v1, K2Node_CreateDelegate_OutputDelegate) == 0x000004, "Member 'PAWN_Diego_v1_C_ExecuteUbergraph_PAWN_Diego_v1::K2Node_CreateDelegate_OutputDelegate' has a wrong offset!");
static_assert(offsetof(PAWN_Diego_v1_C_ExecuteUbergraph_PAWN_Diego_v1, K2Node_CreateDelegate_OutputDelegate_1) == 0x000014, "Member 'PAWN_Diego_v1_C_ExecuteUbergraph_PAWN_Diego_v1::K2Node_CreateDelegate_OutputDelegate_1' has a wrong offset!");
static_assert(offsetof(PAWN_Diego_v1_C_ExecuteUbergraph_PAWN_Diego_v1, CallFunc_K2_SetTimerDelegate_ReturnValue) == 0x000028, "Member 'PAWN_Diego_v1_C_ExecuteUbergraph_PAWN_Diego_v1::CallFunc_K2_SetTimerDelegate_ReturnValue' has a wrong offset!");
static_assert(offsetof(PAWN_Diego_v1_C_ExecuteUbergraph_PAWN_Diego_v1, K2Node_CustomEvent_CurrValue) == 0x000030, "Member 'PAWN_Diego_v1_C_ExecuteUbergraph_PAWN_Diego_v1::K2Node_CustomEvent_CurrValue' has a wrong offset!");
static_assert(offsetof(PAWN_Diego_v1_C_ExecuteUbergraph_PAWN_Diego_v1, K2Node_CustomEvent_LastValue) == 0x000034, "Member 'PAWN_Diego_v1_C_ExecuteUbergraph_PAWN_Diego_v1::K2Node_CustomEvent_LastValue' has a wrong offset!");
static_assert(offsetof(PAWN_Diego_v1_C_ExecuteUbergraph_PAWN_Diego_v1, CallFunc_Less_FloatFloat_ReturnValue) == 0x000038, "Member 'PAWN_Diego_v1_C_ExecuteUbergraph_PAWN_Diego_v1::CallFunc_Less_FloatFloat_ReturnValue' has a wrong offset!");
static_assert(offsetof(PAWN_Diego_v1_C_ExecuteUbergraph_PAWN_Diego_v1, CallFunc_GetAnimInstance_ReturnValue) == 0x000040, "Member 'PAWN_Diego_v1_C_ExecuteUbergraph_PAWN_Diego_v1::CallFunc_GetAnimInstance_ReturnValue' has a wrong offset!");
static_assert(offsetof(PAWN_Diego_v1_C_ExecuteUbergraph_PAWN_Diego_v1, K2Node_DynamicCast_AsANIMBP_Diego_V1) == 0x000048, "Member 'PAWN_Diego_v1_C_ExecuteUbergraph_PAWN_Diego_v1::K2Node_DynamicCast_AsANIMBP_Diego_V1' has a wrong offset!");
static_assert(offsetof(PAWN_Diego_v1_C_ExecuteUbergraph_PAWN_Diego_v1, K2Node_DynamicCast_bSuccess) == 0x000050, "Member 'PAWN_Diego_v1_C_ExecuteUbergraph_PAWN_Diego_v1::K2Node_DynamicCast_bSuccess' has a wrong offset!");
static_assert(offsetof(PAWN_Diego_v1_C_ExecuteUbergraph_PAWN_Diego_v1, CallFunc_SetUseArmProtection_Results) == 0x000051, "Member 'PAWN_Diego_v1_C_ExecuteUbergraph_PAWN_Diego_v1::CallFunc_SetUseArmProtection_Results' has a wrong offset!");
static_assert(offsetof(PAWN_Diego_v1_C_ExecuteUbergraph_PAWN_Diego_v1, CallFunc_GetAnimInstance_ReturnValue_1) == 0x000058, "Member 'PAWN_Diego_v1_C_ExecuteUbergraph_PAWN_Diego_v1::CallFunc_GetAnimInstance_ReturnValue_1' has a wrong offset!");
static_assert(offsetof(PAWN_Diego_v1_C_ExecuteUbergraph_PAWN_Diego_v1, K2Node_DynamicCast_AsANIMBP_Diego_V1_1) == 0x000060, "Member 'PAWN_Diego_v1_C_ExecuteUbergraph_PAWN_Diego_v1::K2Node_DynamicCast_AsANIMBP_Diego_V1_1' has a wrong offset!");
static_assert(offsetof(PAWN_Diego_v1_C_ExecuteUbergraph_PAWN_Diego_v1, K2Node_DynamicCast_bSuccess_1) == 0x000068, "Member 'PAWN_Diego_v1_C_ExecuteUbergraph_PAWN_Diego_v1::K2Node_DynamicCast_bSuccess_1' has a wrong offset!");
static_assert(offsetof(PAWN_Diego_v1_C_ExecuteUbergraph_PAWN_Diego_v1, CallFunc_SetUseArmProtection_Results_1) == 0x000069, "Member 'PAWN_Diego_v1_C_ExecuteUbergraph_PAWN_Diego_v1::CallFunc_SetUseArmProtection_Results_1' has a wrong offset!");

// Function PAWN_Diego_v1.PAWN_Diego_v1_C.OnHealthChanged
// 0x0008 (0x0008 - 0x0000)
struct PAWN_Diego_v1_C_OnHealthChanged final
{
public:
	float                                         CurrValue;                                         // 0x0000(0x0004)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         LastValue;                                         // 0x0004(0x0004)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
};
static_assert(alignof(PAWN_Diego_v1_C_OnHealthChanged) == 0x000004, "Wrong alignment on PAWN_Diego_v1_C_OnHealthChanged");
static_assert(sizeof(PAWN_Diego_v1_C_OnHealthChanged) == 0x000008, "Wrong size on PAWN_Diego_v1_C_OnHealthChanged");
static_assert(offsetof(PAWN_Diego_v1_C_OnHealthChanged, CurrValue) == 0x000000, "Member 'PAWN_Diego_v1_C_OnHealthChanged::CurrValue' has a wrong offset!");
static_assert(offsetof(PAWN_Diego_v1_C_OnHealthChanged, LastValue) == 0x000004, "Member 'PAWN_Diego_v1_C_OnHealthChanged::LastValue' has a wrong offset!");

// Function PAWN_Diego_v1.PAWN_Diego_v1_C.GetTargetShape
// 0x0010 (0x0010 - 0x0000)
struct PAWN_Diego_v1_C_GetTargetShape final
{
public:
	class UPrimitiveComponent*                    CursorPrimitive;                                   // 0x0000(0x0008)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UShapeComponent*                        ShapeComponent;                                    // 0x0008(0x0008)(Parm, OutParm, ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
};
static_assert(alignof(PAWN_Diego_v1_C_GetTargetShape) == 0x000008, "Wrong alignment on PAWN_Diego_v1_C_GetTargetShape");
static_assert(sizeof(PAWN_Diego_v1_C_GetTargetShape) == 0x000010, "Wrong size on PAWN_Diego_v1_C_GetTargetShape");
static_assert(offsetof(PAWN_Diego_v1_C_GetTargetShape, CursorPrimitive) == 0x000000, "Member 'PAWN_Diego_v1_C_GetTargetShape::CursorPrimitive' has a wrong offset!");
static_assert(offsetof(PAWN_Diego_v1_C_GetTargetShape, ShapeComponent) == 0x000008, "Member 'PAWN_Diego_v1_C_GetTargetShape::ShapeComponent' has a wrong offset!");

// Function PAWN_Diego_v1.PAWN_Diego_v1_C.OnEnemySpawned
// 0x0038 (0x0038 - 0x0000)
struct PAWN_Diego_v1_C_OnEnemySpawned final
{
public:
	class APatrolNode_C*                          InitialPatrolNode;                                 // 0x0000(0x0008)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	TSoftClassPtr<class UClass>                   UniqueLootItem;                                    // 0x0008(0x0028)(BlueprintVisible, BlueprintReadOnly, Parm, HasGetValueTypeHash)
	bool                                          AdjustToFloor;                                     // 0x0030(0x0001)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor)
};
static_assert(alignof(PAWN_Diego_v1_C_OnEnemySpawned) == 0x000008, "Wrong alignment on PAWN_Diego_v1_C_OnEnemySpawned");
static_assert(sizeof(PAWN_Diego_v1_C_OnEnemySpawned) == 0x000038, "Wrong size on PAWN_Diego_v1_C_OnEnemySpawned");
static_assert(offsetof(PAWN_Diego_v1_C_OnEnemySpawned, InitialPatrolNode) == 0x000000, "Member 'PAWN_Diego_v1_C_OnEnemySpawned::InitialPatrolNode' has a wrong offset!");
static_assert(offsetof(PAWN_Diego_v1_C_OnEnemySpawned, UniqueLootItem) == 0x000008, "Member 'PAWN_Diego_v1_C_OnEnemySpawned::UniqueLootItem' has a wrong offset!");
static_assert(offsetof(PAWN_Diego_v1_C_OnEnemySpawned, AdjustToFloor) == 0x000030, "Member 'PAWN_Diego_v1_C_OnEnemySpawned::AdjustToFloor' has a wrong offset!");

// Function PAWN_Diego_v1.PAWN_Diego_v1_C.ToggleSwordEffect
// 0x0003 (0x0003 - 0x0000)
struct PAWN_Diego_v1_C_ToggleSwordEffect final
{
public:
	bool                                          Enabled;                                           // 0x0000(0x0001)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor)
	bool                                          CallFunc_IsActive_ReturnValue;                     // 0x0001(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	bool                                          CallFunc_NotEqual_BoolBool_ReturnValue;            // 0x0002(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
};
static_assert(alignof(PAWN_Diego_v1_C_ToggleSwordEffect) == 0x000001, "Wrong alignment on PAWN_Diego_v1_C_ToggleSwordEffect");
static_assert(sizeof(PAWN_Diego_v1_C_ToggleSwordEffect) == 0x000003, "Wrong size on PAWN_Diego_v1_C_ToggleSwordEffect");
static_assert(offsetof(PAWN_Diego_v1_C_ToggleSwordEffect, Enabled) == 0x000000, "Member 'PAWN_Diego_v1_C_ToggleSwordEffect::Enabled' has a wrong offset!");
static_assert(offsetof(PAWN_Diego_v1_C_ToggleSwordEffect, CallFunc_IsActive_ReturnValue) == 0x000001, "Member 'PAWN_Diego_v1_C_ToggleSwordEffect::CallFunc_IsActive_ReturnValue' has a wrong offset!");
static_assert(offsetof(PAWN_Diego_v1_C_ToggleSwordEffect, CallFunc_NotEqual_BoolBool_ReturnValue) == 0x000002, "Member 'PAWN_Diego_v1_C_ToggleSwordEffect::CallFunc_NotEqual_BoolBool_ReturnValue' has a wrong offset!");

}

