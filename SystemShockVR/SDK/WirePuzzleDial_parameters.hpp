#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: WirePuzzleDial

#include "Basic.hpp"

#include "CoreUObject_structs.hpp"
#include "Engine_structs.hpp"


namespace SDK::Params
{

// Function WirePuzzleDial.WirePuzzleDial_C.ExecuteUbergraph_WirePuzzleDial
// 0x0008 (0x0008 - 0x0000)
struct WirePuzzleDial_C_ExecuteUbergraph_WirePuzzleDial final
{
public:
	int32                                         EntryPoint;                                        // 0x0000(0x0004)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         K2Node_Event_DeltaSeconds;                         // 0x0004(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
};
static_assert(alignof(WirePuzzleDial_C_ExecuteUbergraph_WirePuzzleDial) == 0x000004, "Wrong alignment on WirePuzzleDial_C_ExecuteUbergraph_WirePuzzleDial");
static_assert(sizeof(WirePuzzleDial_C_ExecuteUbergraph_WirePuzzleDial) == 0x000008, "Wrong size on WirePuzzleDial_C_ExecuteUbergraph_WirePuzzleDial");
static_assert(offsetof(WirePuzzleDial_C_ExecuteUbergraph_WirePuzzleDial, EntryPoint) == 0x000000, "Member 'WirePuzzleDial_C_ExecuteUbergraph_WirePuzzleDial::EntryPoint' has a wrong offset!");
static_assert(offsetof(WirePuzzleDial_C_ExecuteUbergraph_WirePuzzleDial, K2Node_Event_DeltaSeconds) == 0x000004, "Member 'WirePuzzleDial_C_ExecuteUbergraph_WirePuzzleDial::K2Node_Event_DeltaSeconds' has a wrong offset!");

// Function WirePuzzleDial.WirePuzzleDial_C.ReceiveTick
// 0x0004 (0x0004 - 0x0000)
struct WirePuzzleDial_C_ReceiveTick final
{
public:
	float                                         DeltaSeconds;                                      // 0x0000(0x0004)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
};
static_assert(alignof(WirePuzzleDial_C_ReceiveTick) == 0x000004, "Wrong alignment on WirePuzzleDial_C_ReceiveTick");
static_assert(sizeof(WirePuzzleDial_C_ReceiveTick) == 0x000004, "Wrong size on WirePuzzleDial_C_ReceiveTick");
static_assert(offsetof(WirePuzzleDial_C_ReceiveTick, DeltaSeconds) == 0x000000, "Member 'WirePuzzleDial_C_ReceiveTick::DeltaSeconds' has a wrong offset!");

// Function WirePuzzleDial.WirePuzzleDial_C.InitializeWireDial
// 0x0094 (0x0094 - 0x0000)
struct WirePuzzleDial_C_InitializeWireDial final
{
public:
	struct FRotator                               CallFunc_GetTargetRotation_TargetRotation;         // 0x0000(0x000C)(ZeroConstructor, IsPlainOldData, NoDestructor)
	struct FHitResult                             CallFunc_K2_SetRelativeRotation_SweepHitResult;    // 0x000C(0x0088)(IsPlainOldData, NoDestructor, ContainsInstancedReference)
};
static_assert(alignof(WirePuzzleDial_C_InitializeWireDial) == 0x000004, "Wrong alignment on WirePuzzleDial_C_InitializeWireDial");
static_assert(sizeof(WirePuzzleDial_C_InitializeWireDial) == 0x000094, "Wrong size on WirePuzzleDial_C_InitializeWireDial");
static_assert(offsetof(WirePuzzleDial_C_InitializeWireDial, CallFunc_GetTargetRotation_TargetRotation) == 0x000000, "Member 'WirePuzzleDial_C_InitializeWireDial::CallFunc_GetTargetRotation_TargetRotation' has a wrong offset!");
static_assert(offsetof(WirePuzzleDial_C_InitializeWireDial, CallFunc_K2_SetRelativeRotation_SweepHitResult) == 0x00000C, "Member 'WirePuzzleDial_C_InitializeWireDial::CallFunc_K2_SetRelativeRotation_SweepHitResult' has a wrong offset!");

// Function WirePuzzleDial.WirePuzzleDial_C.UpdateRotation
// 0x00C0 (0x00C0 - 0x0000)
struct WirePuzzleDial_C_UpdateRotation final
{
public:
	float                                         DeltaSeconds;                                      // 0x0000(0x0004)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FRotator                               TargetRotation;                                    // 0x0004(0x000C)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor)
	struct FRotator                               CallFunc_GetTargetRotation_TargetRotation;         // 0x0010(0x000C)(ZeroConstructor, IsPlainOldData, NoDestructor)
	struct FVector                                CallFunc_K2_GetComponentLocation_ReturnValue;      // 0x001C(0x000C)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FRotator                               CallFunc_RInterpTo_Constant_ReturnValue;           // 0x0028(0x000C)(ZeroConstructor, IsPlainOldData, NoDestructor)
	bool                                          CallFunc_EqualEqual_RotatorRotator_ReturnValue;    // 0x0034(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_35[0x3];                                       // 0x0035(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	struct FHitResult                             CallFunc_K2_SetRelativeRotation_SweepHitResult;    // 0x0038(0x0088)(IsPlainOldData, NoDestructor, ContainsInstancedReference)
};
static_assert(alignof(WirePuzzleDial_C_UpdateRotation) == 0x000004, "Wrong alignment on WirePuzzleDial_C_UpdateRotation");
static_assert(sizeof(WirePuzzleDial_C_UpdateRotation) == 0x0000C0, "Wrong size on WirePuzzleDial_C_UpdateRotation");
static_assert(offsetof(WirePuzzleDial_C_UpdateRotation, DeltaSeconds) == 0x000000, "Member 'WirePuzzleDial_C_UpdateRotation::DeltaSeconds' has a wrong offset!");
static_assert(offsetof(WirePuzzleDial_C_UpdateRotation, TargetRotation) == 0x000004, "Member 'WirePuzzleDial_C_UpdateRotation::TargetRotation' has a wrong offset!");
static_assert(offsetof(WirePuzzleDial_C_UpdateRotation, CallFunc_GetTargetRotation_TargetRotation) == 0x000010, "Member 'WirePuzzleDial_C_UpdateRotation::CallFunc_GetTargetRotation_TargetRotation' has a wrong offset!");
static_assert(offsetof(WirePuzzleDial_C_UpdateRotation, CallFunc_K2_GetComponentLocation_ReturnValue) == 0x00001C, "Member 'WirePuzzleDial_C_UpdateRotation::CallFunc_K2_GetComponentLocation_ReturnValue' has a wrong offset!");
static_assert(offsetof(WirePuzzleDial_C_UpdateRotation, CallFunc_RInterpTo_Constant_ReturnValue) == 0x000028, "Member 'WirePuzzleDial_C_UpdateRotation::CallFunc_RInterpTo_Constant_ReturnValue' has a wrong offset!");
static_assert(offsetof(WirePuzzleDial_C_UpdateRotation, CallFunc_EqualEqual_RotatorRotator_ReturnValue) == 0x000034, "Member 'WirePuzzleDial_C_UpdateRotation::CallFunc_EqualEqual_RotatorRotator_ReturnValue' has a wrong offset!");
static_assert(offsetof(WirePuzzleDial_C_UpdateRotation, CallFunc_K2_SetRelativeRotation_SweepHitResult) == 0x000038, "Member 'WirePuzzleDial_C_UpdateRotation::CallFunc_K2_SetRelativeRotation_SweepHitResult' has a wrong offset!");

// Function WirePuzzleDial.WirePuzzleDial_C.GetTargetRotation
// 0x003C (0x003C - 0x0000)
struct WirePuzzleDial_C_GetTargetRotation final
{
public:
	struct FRotator                               TargetRotation;                                    // 0x0000(0x000C)(Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor)
	float                                         DialRotation;                                      // 0x000C(0x0004)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         CellRotation;                                      // 0x0010(0x0004)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          CallFunc_BooleanXOR_ReturnValue;                   // 0x0014(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_15[0x3];                                       // 0x0015(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	float                                         CallFunc_SelectFloat_ReturnValue;                  // 0x0018(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         CallFunc_Add_FloatFloat_ReturnValue;               // 0x001C(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FRotator                               CallFunc_MakeRotator_ReturnValue;                  // 0x0020(0x000C)(ZeroConstructor, IsPlainOldData, NoDestructor)
	float                                         CallFunc_Multiply_IntFloat_ReturnValue;            // 0x002C(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          CallFunc_IsTJunction_Result;                       // 0x0030(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_31[0x3];                                       // 0x0031(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	float                                         CallFunc_SelectFloat_ReturnValue_1;                // 0x0034(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         CallFunc_SelectFloat_ReturnValue_2;                // 0x0038(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
};
static_assert(alignof(WirePuzzleDial_C_GetTargetRotation) == 0x000004, "Wrong alignment on WirePuzzleDial_C_GetTargetRotation");
static_assert(sizeof(WirePuzzleDial_C_GetTargetRotation) == 0x00003C, "Wrong size on WirePuzzleDial_C_GetTargetRotation");
static_assert(offsetof(WirePuzzleDial_C_GetTargetRotation, TargetRotation) == 0x000000, "Member 'WirePuzzleDial_C_GetTargetRotation::TargetRotation' has a wrong offset!");
static_assert(offsetof(WirePuzzleDial_C_GetTargetRotation, DialRotation) == 0x00000C, "Member 'WirePuzzleDial_C_GetTargetRotation::DialRotation' has a wrong offset!");
static_assert(offsetof(WirePuzzleDial_C_GetTargetRotation, CellRotation) == 0x000010, "Member 'WirePuzzleDial_C_GetTargetRotation::CellRotation' has a wrong offset!");
static_assert(offsetof(WirePuzzleDial_C_GetTargetRotation, CallFunc_BooleanXOR_ReturnValue) == 0x000014, "Member 'WirePuzzleDial_C_GetTargetRotation::CallFunc_BooleanXOR_ReturnValue' has a wrong offset!");
static_assert(offsetof(WirePuzzleDial_C_GetTargetRotation, CallFunc_SelectFloat_ReturnValue) == 0x000018, "Member 'WirePuzzleDial_C_GetTargetRotation::CallFunc_SelectFloat_ReturnValue' has a wrong offset!");
static_assert(offsetof(WirePuzzleDial_C_GetTargetRotation, CallFunc_Add_FloatFloat_ReturnValue) == 0x00001C, "Member 'WirePuzzleDial_C_GetTargetRotation::CallFunc_Add_FloatFloat_ReturnValue' has a wrong offset!");
static_assert(offsetof(WirePuzzleDial_C_GetTargetRotation, CallFunc_MakeRotator_ReturnValue) == 0x000020, "Member 'WirePuzzleDial_C_GetTargetRotation::CallFunc_MakeRotator_ReturnValue' has a wrong offset!");
static_assert(offsetof(WirePuzzleDial_C_GetTargetRotation, CallFunc_Multiply_IntFloat_ReturnValue) == 0x00002C, "Member 'WirePuzzleDial_C_GetTargetRotation::CallFunc_Multiply_IntFloat_ReturnValue' has a wrong offset!");
static_assert(offsetof(WirePuzzleDial_C_GetTargetRotation, CallFunc_IsTJunction_Result) == 0x000030, "Member 'WirePuzzleDial_C_GetTargetRotation::CallFunc_IsTJunction_Result' has a wrong offset!");
static_assert(offsetof(WirePuzzleDial_C_GetTargetRotation, CallFunc_SelectFloat_ReturnValue_1) == 0x000034, "Member 'WirePuzzleDial_C_GetTargetRotation::CallFunc_SelectFloat_ReturnValue_1' has a wrong offset!");
static_assert(offsetof(WirePuzzleDial_C_GetTargetRotation, CallFunc_SelectFloat_ReturnValue_2) == 0x000038, "Member 'WirePuzzleDial_C_GetTargetRotation::CallFunc_SelectFloat_ReturnValue_2' has a wrong offset!");

// Function WirePuzzleDial.WirePuzzleDial_C.IsTJunction
// 0x0030 (0x0030 - 0x0000)
struct WirePuzzleDial_C_IsTJunction final
{
public:
	bool                                          Result;                                            // 0x0000(0x0001)(Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_1[0x3];                                        // 0x0001(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	int32                                         CallFunc_Array_Length_ReturnValue;                 // 0x0004(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	int32                                         CallFunc_Array_Get_Item;                           // 0x0008(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          CallFunc_GreaterEqual_IntInt_ReturnValue;          // 0x000C(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_D[0x3];                                        // 0x000D(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	float                                         CallFunc_Multiply_IntFloat_ReturnValue;            // 0x0010(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         CallFunc_NormalizeAxis_ReturnValue;                // 0x0014(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	int32                                         CallFunc_Array_Get_Item_1;                         // 0x0018(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         CallFunc_Multiply_IntFloat_ReturnValue_1;          // 0x001C(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         CallFunc_NormalizeAxis_ReturnValue_1;              // 0x0020(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         CallFunc_Subtract_FloatFloat_ReturnValue;          // 0x0024(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         CallFunc_ClampAxis_ReturnValue;                    // 0x0028(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          CallFunc_NearlyEqual_FloatFloat_ReturnValue;       // 0x002C(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
};
static_assert(alignof(WirePuzzleDial_C_IsTJunction) == 0x000004, "Wrong alignment on WirePuzzleDial_C_IsTJunction");
static_assert(sizeof(WirePuzzleDial_C_IsTJunction) == 0x000030, "Wrong size on WirePuzzleDial_C_IsTJunction");
static_assert(offsetof(WirePuzzleDial_C_IsTJunction, Result) == 0x000000, "Member 'WirePuzzleDial_C_IsTJunction::Result' has a wrong offset!");
static_assert(offsetof(WirePuzzleDial_C_IsTJunction, CallFunc_Array_Length_ReturnValue) == 0x000004, "Member 'WirePuzzleDial_C_IsTJunction::CallFunc_Array_Length_ReturnValue' has a wrong offset!");
static_assert(offsetof(WirePuzzleDial_C_IsTJunction, CallFunc_Array_Get_Item) == 0x000008, "Member 'WirePuzzleDial_C_IsTJunction::CallFunc_Array_Get_Item' has a wrong offset!");
static_assert(offsetof(WirePuzzleDial_C_IsTJunction, CallFunc_GreaterEqual_IntInt_ReturnValue) == 0x00000C, "Member 'WirePuzzleDial_C_IsTJunction::CallFunc_GreaterEqual_IntInt_ReturnValue' has a wrong offset!");
static_assert(offsetof(WirePuzzleDial_C_IsTJunction, CallFunc_Multiply_IntFloat_ReturnValue) == 0x000010, "Member 'WirePuzzleDial_C_IsTJunction::CallFunc_Multiply_IntFloat_ReturnValue' has a wrong offset!");
static_assert(offsetof(WirePuzzleDial_C_IsTJunction, CallFunc_NormalizeAxis_ReturnValue) == 0x000014, "Member 'WirePuzzleDial_C_IsTJunction::CallFunc_NormalizeAxis_ReturnValue' has a wrong offset!");
static_assert(offsetof(WirePuzzleDial_C_IsTJunction, CallFunc_Array_Get_Item_1) == 0x000018, "Member 'WirePuzzleDial_C_IsTJunction::CallFunc_Array_Get_Item_1' has a wrong offset!");
static_assert(offsetof(WirePuzzleDial_C_IsTJunction, CallFunc_Multiply_IntFloat_ReturnValue_1) == 0x00001C, "Member 'WirePuzzleDial_C_IsTJunction::CallFunc_Multiply_IntFloat_ReturnValue_1' has a wrong offset!");
static_assert(offsetof(WirePuzzleDial_C_IsTJunction, CallFunc_NormalizeAxis_ReturnValue_1) == 0x000020, "Member 'WirePuzzleDial_C_IsTJunction::CallFunc_NormalizeAxis_ReturnValue_1' has a wrong offset!");
static_assert(offsetof(WirePuzzleDial_C_IsTJunction, CallFunc_Subtract_FloatFloat_ReturnValue) == 0x000024, "Member 'WirePuzzleDial_C_IsTJunction::CallFunc_Subtract_FloatFloat_ReturnValue' has a wrong offset!");
static_assert(offsetof(WirePuzzleDial_C_IsTJunction, CallFunc_ClampAxis_ReturnValue) == 0x000028, "Member 'WirePuzzleDial_C_IsTJunction::CallFunc_ClampAxis_ReturnValue' has a wrong offset!");
static_assert(offsetof(WirePuzzleDial_C_IsTJunction, CallFunc_NearlyEqual_FloatFloat_ReturnValue) == 0x00002C, "Member 'WirePuzzleDial_C_IsTJunction::CallFunc_NearlyEqual_FloatFloat_ReturnValue' has a wrong offset!");

}

