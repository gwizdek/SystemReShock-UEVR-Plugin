#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: DEC_IsAtSpawn

#include "Basic.hpp"

#include "CoreUObject_structs.hpp"


namespace SDK::Params
{

// Function DEC_IsAtSpawn.DEC_IsAtSpawn_C.PerformConditionCheckAI
// 0x0088 (0x0088 - 0x0000)
struct DEC_IsAtSpawn_C_PerformConditionCheckAI final
{
public:
	class AAIController*                          OwnerController;                                   // 0x0000(0x0008)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class APawn*                                  ControlledPawn;                                    // 0x0008(0x0008)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          ReturnValue;                                       // 0x0010(0x0001)(Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData, NoDestructor)
	uint8                                         Pad_11[0x7];                                       // 0x0011(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	class APAWN_Enemy_C*                          EnemyPawn;                                         // 0x0018(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnTemplate, IsPlainOldData, NoDestructor, UObjectWrapper, HasGetValueTypeHash)
	class APAWN_Enemy_C*                          K2Node_DynamicCast_AsPAWN_Enemy;                   // 0x0020(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          K2Node_DynamicCast_bSuccess;                       // 0x0028(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_29[0x3];                                       // 0x0029(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	struct FVector                                CallFunc_GetActorForwardVector_ReturnValue;        // 0x002C(0x000C)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         CallFunc_SignedAngleBetweenNormals_ReturnValue;    // 0x0038(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          CallFunc_LessEqual_FloatFloat_ReturnValue;         // 0x003C(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_3D[0x3];                                       // 0x003D(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	struct FVector                                CallFunc_MakeVector_ReturnValue;                   // 0x0040(0x000C)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FVector                                CallFunc_GetActorForwardVector_ReturnValue_1;      // 0x004C(0x000C)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          CallFunc_EqualEqual_ByteByte_ReturnValue;          // 0x0058(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_59[0x3];                                       // 0x0059(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	float                                         CallFunc_SignedAngleBetweenOnPlane_ReturnValue;    // 0x005C(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         CallFunc_Abs_ReturnValue;                          // 0x0060(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          CallFunc_LessEqual_FloatFloat_ReturnValue_1;       // 0x0064(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	bool                                          CallFunc_Not_PreBool_ReturnValue;                  // 0x0065(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	bool                                          CallFunc_Not_PreBool_ReturnValue_1;                // 0x0066(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	bool                                          CallFunc_BooleanOR_ReturnValue;                    // 0x0067(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	bool                                          CallFunc_BooleanOR_ReturnValue_1;                  // 0x0068(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	bool                                          CallFunc_BooleanAND_ReturnValue;                   // 0x0069(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_6A[0x2];                                       // 0x006A(0x0002)(Fixing Size After Last Property [ Dumper-7 ])
	float                                         CallFunc_Square_ReturnValue;                       // 0x006C(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FVector                                CallFunc_GetShockAgentLocation_Location;           // 0x0070(0x000C)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         CallFunc_Vector_DistanceSquared_ReturnValue;       // 0x007C(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          CallFunc_LessEqual_FloatFloat_ReturnValue_2;       // 0x0080(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
};
static_assert(alignof(DEC_IsAtSpawn_C_PerformConditionCheckAI) == 0x000008, "Wrong alignment on DEC_IsAtSpawn_C_PerformConditionCheckAI");
static_assert(sizeof(DEC_IsAtSpawn_C_PerformConditionCheckAI) == 0x000088, "Wrong size on DEC_IsAtSpawn_C_PerformConditionCheckAI");
static_assert(offsetof(DEC_IsAtSpawn_C_PerformConditionCheckAI, OwnerController) == 0x000000, "Member 'DEC_IsAtSpawn_C_PerformConditionCheckAI::OwnerController' has a wrong offset!");
static_assert(offsetof(DEC_IsAtSpawn_C_PerformConditionCheckAI, ControlledPawn) == 0x000008, "Member 'DEC_IsAtSpawn_C_PerformConditionCheckAI::ControlledPawn' has a wrong offset!");
static_assert(offsetof(DEC_IsAtSpawn_C_PerformConditionCheckAI, ReturnValue) == 0x000010, "Member 'DEC_IsAtSpawn_C_PerformConditionCheckAI::ReturnValue' has a wrong offset!");
static_assert(offsetof(DEC_IsAtSpawn_C_PerformConditionCheckAI, EnemyPawn) == 0x000018, "Member 'DEC_IsAtSpawn_C_PerformConditionCheckAI::EnemyPawn' has a wrong offset!");
static_assert(offsetof(DEC_IsAtSpawn_C_PerformConditionCheckAI, K2Node_DynamicCast_AsPAWN_Enemy) == 0x000020, "Member 'DEC_IsAtSpawn_C_PerformConditionCheckAI::K2Node_DynamicCast_AsPAWN_Enemy' has a wrong offset!");
static_assert(offsetof(DEC_IsAtSpawn_C_PerformConditionCheckAI, K2Node_DynamicCast_bSuccess) == 0x000028, "Member 'DEC_IsAtSpawn_C_PerformConditionCheckAI::K2Node_DynamicCast_bSuccess' has a wrong offset!");
static_assert(offsetof(DEC_IsAtSpawn_C_PerformConditionCheckAI, CallFunc_GetActorForwardVector_ReturnValue) == 0x00002C, "Member 'DEC_IsAtSpawn_C_PerformConditionCheckAI::CallFunc_GetActorForwardVector_ReturnValue' has a wrong offset!");
static_assert(offsetof(DEC_IsAtSpawn_C_PerformConditionCheckAI, CallFunc_SignedAngleBetweenNormals_ReturnValue) == 0x000038, "Member 'DEC_IsAtSpawn_C_PerformConditionCheckAI::CallFunc_SignedAngleBetweenNormals_ReturnValue' has a wrong offset!");
static_assert(offsetof(DEC_IsAtSpawn_C_PerformConditionCheckAI, CallFunc_LessEqual_FloatFloat_ReturnValue) == 0x00003C, "Member 'DEC_IsAtSpawn_C_PerformConditionCheckAI::CallFunc_LessEqual_FloatFloat_ReturnValue' has a wrong offset!");
static_assert(offsetof(DEC_IsAtSpawn_C_PerformConditionCheckAI, CallFunc_MakeVector_ReturnValue) == 0x000040, "Member 'DEC_IsAtSpawn_C_PerformConditionCheckAI::CallFunc_MakeVector_ReturnValue' has a wrong offset!");
static_assert(offsetof(DEC_IsAtSpawn_C_PerformConditionCheckAI, CallFunc_GetActorForwardVector_ReturnValue_1) == 0x00004C, "Member 'DEC_IsAtSpawn_C_PerformConditionCheckAI::CallFunc_GetActorForwardVector_ReturnValue_1' has a wrong offset!");
static_assert(offsetof(DEC_IsAtSpawn_C_PerformConditionCheckAI, CallFunc_EqualEqual_ByteByte_ReturnValue) == 0x000058, "Member 'DEC_IsAtSpawn_C_PerformConditionCheckAI::CallFunc_EqualEqual_ByteByte_ReturnValue' has a wrong offset!");
static_assert(offsetof(DEC_IsAtSpawn_C_PerformConditionCheckAI, CallFunc_SignedAngleBetweenOnPlane_ReturnValue) == 0x00005C, "Member 'DEC_IsAtSpawn_C_PerformConditionCheckAI::CallFunc_SignedAngleBetweenOnPlane_ReturnValue' has a wrong offset!");
static_assert(offsetof(DEC_IsAtSpawn_C_PerformConditionCheckAI, CallFunc_Abs_ReturnValue) == 0x000060, "Member 'DEC_IsAtSpawn_C_PerformConditionCheckAI::CallFunc_Abs_ReturnValue' has a wrong offset!");
static_assert(offsetof(DEC_IsAtSpawn_C_PerformConditionCheckAI, CallFunc_LessEqual_FloatFloat_ReturnValue_1) == 0x000064, "Member 'DEC_IsAtSpawn_C_PerformConditionCheckAI::CallFunc_LessEqual_FloatFloat_ReturnValue_1' has a wrong offset!");
static_assert(offsetof(DEC_IsAtSpawn_C_PerformConditionCheckAI, CallFunc_Not_PreBool_ReturnValue) == 0x000065, "Member 'DEC_IsAtSpawn_C_PerformConditionCheckAI::CallFunc_Not_PreBool_ReturnValue' has a wrong offset!");
static_assert(offsetof(DEC_IsAtSpawn_C_PerformConditionCheckAI, CallFunc_Not_PreBool_ReturnValue_1) == 0x000066, "Member 'DEC_IsAtSpawn_C_PerformConditionCheckAI::CallFunc_Not_PreBool_ReturnValue_1' has a wrong offset!");
static_assert(offsetof(DEC_IsAtSpawn_C_PerformConditionCheckAI, CallFunc_BooleanOR_ReturnValue) == 0x000067, "Member 'DEC_IsAtSpawn_C_PerformConditionCheckAI::CallFunc_BooleanOR_ReturnValue' has a wrong offset!");
static_assert(offsetof(DEC_IsAtSpawn_C_PerformConditionCheckAI, CallFunc_BooleanOR_ReturnValue_1) == 0x000068, "Member 'DEC_IsAtSpawn_C_PerformConditionCheckAI::CallFunc_BooleanOR_ReturnValue_1' has a wrong offset!");
static_assert(offsetof(DEC_IsAtSpawn_C_PerformConditionCheckAI, CallFunc_BooleanAND_ReturnValue) == 0x000069, "Member 'DEC_IsAtSpawn_C_PerformConditionCheckAI::CallFunc_BooleanAND_ReturnValue' has a wrong offset!");
static_assert(offsetof(DEC_IsAtSpawn_C_PerformConditionCheckAI, CallFunc_Square_ReturnValue) == 0x00006C, "Member 'DEC_IsAtSpawn_C_PerformConditionCheckAI::CallFunc_Square_ReturnValue' has a wrong offset!");
static_assert(offsetof(DEC_IsAtSpawn_C_PerformConditionCheckAI, CallFunc_GetShockAgentLocation_Location) == 0x000070, "Member 'DEC_IsAtSpawn_C_PerformConditionCheckAI::CallFunc_GetShockAgentLocation_Location' has a wrong offset!");
static_assert(offsetof(DEC_IsAtSpawn_C_PerformConditionCheckAI, CallFunc_Vector_DistanceSquared_ReturnValue) == 0x00007C, "Member 'DEC_IsAtSpawn_C_PerformConditionCheckAI::CallFunc_Vector_DistanceSquared_ReturnValue' has a wrong offset!");
static_assert(offsetof(DEC_IsAtSpawn_C_PerformConditionCheckAI, CallFunc_LessEqual_FloatFloat_ReturnValue_2) == 0x000080, "Member 'DEC_IsAtSpawn_C_PerformConditionCheckAI::CallFunc_LessEqual_FloatFloat_ReturnValue_2' has a wrong offset!");

}

