#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: INTERACT_IrisDoor

#include "Basic.hpp"


namespace SDK::Params
{

// Function INTERACT_IrisDoor.INTERACT_IrisDoor_C.GetTargetShape
// 0x0048 (0x0048 - 0x0000)
struct INTERACT_IrisDoor_C_GetTargetShape final
{
public:
	class UPrimitiveComponent*                    CursorPrimitive;                                   // 0x0000(0x0008)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UShapeComponent*                        ShapeComponent;                                    // 0x0008(0x0008)(Parm, OutParm, ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          Temp_bool_Variable;                                // 0x0010(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_11[0x7];                                       // 0x0011(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	class UBoxComponent*                          Temp_object_Variable;                              // 0x0018(0x0008)(ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          Temp_bool_Variable_1;                              // 0x0020(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_21[0x7];                                       // 0x0021(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	class UShapeComponent*                        Temp_object_Variable_1;                            // 0x0028(0x0008)(ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UBoxComponent*                          K2Node_Select_Default;                             // 0x0030(0x0008)(ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UShapeComponent*                        K2Node_Select_Default_1;                           // 0x0038(0x0008)(ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          CallFunc_EqualEqual_ObjectObject_ReturnValue;      // 0x0040(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	bool                                          CallFunc_EqualEqual_ObjectObject_ReturnValue_1;    // 0x0041(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
};
static_assert(alignof(INTERACT_IrisDoor_C_GetTargetShape) == 0x000008, "Wrong alignment on INTERACT_IrisDoor_C_GetTargetShape");
static_assert(sizeof(INTERACT_IrisDoor_C_GetTargetShape) == 0x000048, "Wrong size on INTERACT_IrisDoor_C_GetTargetShape");
static_assert(offsetof(INTERACT_IrisDoor_C_GetTargetShape, CursorPrimitive) == 0x000000, "Member 'INTERACT_IrisDoor_C_GetTargetShape::CursorPrimitive' has a wrong offset!");
static_assert(offsetof(INTERACT_IrisDoor_C_GetTargetShape, ShapeComponent) == 0x000008, "Member 'INTERACT_IrisDoor_C_GetTargetShape::ShapeComponent' has a wrong offset!");
static_assert(offsetof(INTERACT_IrisDoor_C_GetTargetShape, Temp_bool_Variable) == 0x000010, "Member 'INTERACT_IrisDoor_C_GetTargetShape::Temp_bool_Variable' has a wrong offset!");
static_assert(offsetof(INTERACT_IrisDoor_C_GetTargetShape, Temp_object_Variable) == 0x000018, "Member 'INTERACT_IrisDoor_C_GetTargetShape::Temp_object_Variable' has a wrong offset!");
static_assert(offsetof(INTERACT_IrisDoor_C_GetTargetShape, Temp_bool_Variable_1) == 0x000020, "Member 'INTERACT_IrisDoor_C_GetTargetShape::Temp_bool_Variable_1' has a wrong offset!");
static_assert(offsetof(INTERACT_IrisDoor_C_GetTargetShape, Temp_object_Variable_1) == 0x000028, "Member 'INTERACT_IrisDoor_C_GetTargetShape::Temp_object_Variable_1' has a wrong offset!");
static_assert(offsetof(INTERACT_IrisDoor_C_GetTargetShape, K2Node_Select_Default) == 0x000030, "Member 'INTERACT_IrisDoor_C_GetTargetShape::K2Node_Select_Default' has a wrong offset!");
static_assert(offsetof(INTERACT_IrisDoor_C_GetTargetShape, K2Node_Select_Default_1) == 0x000038, "Member 'INTERACT_IrisDoor_C_GetTargetShape::K2Node_Select_Default_1' has a wrong offset!");
static_assert(offsetof(INTERACT_IrisDoor_C_GetTargetShape, CallFunc_EqualEqual_ObjectObject_ReturnValue) == 0x000040, "Member 'INTERACT_IrisDoor_C_GetTargetShape::CallFunc_EqualEqual_ObjectObject_ReturnValue' has a wrong offset!");
static_assert(offsetof(INTERACT_IrisDoor_C_GetTargetShape, CallFunc_EqualEqual_ObjectObject_ReturnValue_1) == 0x000041, "Member 'INTERACT_IrisDoor_C_GetTargetShape::CallFunc_EqualEqual_ObjectObject_ReturnValue_1' has a wrong offset!");

}

