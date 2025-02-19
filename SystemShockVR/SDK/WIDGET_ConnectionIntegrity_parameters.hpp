#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: WIDGET_ConnectionIntegrity

#include "Basic.hpp"


namespace SDK::Params
{

// Function WIDGET_ConnectionIntegrity.WIDGET_ConnectionIntegrity_C.Set Integrity Value
// 0x0040 (0x0040 - 0x0000)
struct WIDGET_ConnectionIntegrity_C_Set_Integrity_Value final
{
public:
	float                                         CurrentHealth;                                     // 0x0000(0x0004)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         MaxHealth;                                         // 0x0004(0x0004)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UMaterialInstanceDynamic*               CallFunc_ConvertToDynamicMaterialInstance_ReturnValue; // 0x0008(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         CallFunc_Divide_FloatFloat_ReturnValue;            // 0x0010(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          CallFunc_Greater_FloatFloat_ReturnValue;           // 0x0014(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_15[0x3];                                       // 0x0015(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	float                                         CallFunc_Divide_FloatFloat_ReturnValue_1;          // 0x0018(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         CallFunc_Conv_BoolToFloat_ReturnValue;             // 0x001C(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          CallFunc_LessEqual_FloatFloat_ReturnValue;         // 0x0020(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_21[0x3];                                       // 0x0021(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	float                                         CallFunc_Conv_BoolToFloat_ReturnValue_1;           // 0x0024(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UMaterialInstanceDynamic*               CallFunc_ConvertToDynamicMaterialInstance_ReturnValue_1; // 0x0028(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         CallFunc_Divide_FloatFloat_ReturnValue_2;          // 0x0030(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_34[0x4];                                       // 0x0034(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	class UMaterialInstanceDynamic*               CallFunc_ConvertToDynamicMaterialInstance_ReturnValue_2; // 0x0038(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
};
static_assert(alignof(WIDGET_ConnectionIntegrity_C_Set_Integrity_Value) == 0x000008, "Wrong alignment on WIDGET_ConnectionIntegrity_C_Set_Integrity_Value");
static_assert(sizeof(WIDGET_ConnectionIntegrity_C_Set_Integrity_Value) == 0x000040, "Wrong size on WIDGET_ConnectionIntegrity_C_Set_Integrity_Value");
static_assert(offsetof(WIDGET_ConnectionIntegrity_C_Set_Integrity_Value, CurrentHealth) == 0x000000, "Member 'WIDGET_ConnectionIntegrity_C_Set_Integrity_Value::CurrentHealth' has a wrong offset!");
static_assert(offsetof(WIDGET_ConnectionIntegrity_C_Set_Integrity_Value, MaxHealth) == 0x000004, "Member 'WIDGET_ConnectionIntegrity_C_Set_Integrity_Value::MaxHealth' has a wrong offset!");
static_assert(offsetof(WIDGET_ConnectionIntegrity_C_Set_Integrity_Value, CallFunc_ConvertToDynamicMaterialInstance_ReturnValue) == 0x000008, "Member 'WIDGET_ConnectionIntegrity_C_Set_Integrity_Value::CallFunc_ConvertToDynamicMaterialInstance_ReturnValue' has a wrong offset!");
static_assert(offsetof(WIDGET_ConnectionIntegrity_C_Set_Integrity_Value, CallFunc_Divide_FloatFloat_ReturnValue) == 0x000010, "Member 'WIDGET_ConnectionIntegrity_C_Set_Integrity_Value::CallFunc_Divide_FloatFloat_ReturnValue' has a wrong offset!");
static_assert(offsetof(WIDGET_ConnectionIntegrity_C_Set_Integrity_Value, CallFunc_Greater_FloatFloat_ReturnValue) == 0x000014, "Member 'WIDGET_ConnectionIntegrity_C_Set_Integrity_Value::CallFunc_Greater_FloatFloat_ReturnValue' has a wrong offset!");
static_assert(offsetof(WIDGET_ConnectionIntegrity_C_Set_Integrity_Value, CallFunc_Divide_FloatFloat_ReturnValue_1) == 0x000018, "Member 'WIDGET_ConnectionIntegrity_C_Set_Integrity_Value::CallFunc_Divide_FloatFloat_ReturnValue_1' has a wrong offset!");
static_assert(offsetof(WIDGET_ConnectionIntegrity_C_Set_Integrity_Value, CallFunc_Conv_BoolToFloat_ReturnValue) == 0x00001C, "Member 'WIDGET_ConnectionIntegrity_C_Set_Integrity_Value::CallFunc_Conv_BoolToFloat_ReturnValue' has a wrong offset!");
static_assert(offsetof(WIDGET_ConnectionIntegrity_C_Set_Integrity_Value, CallFunc_LessEqual_FloatFloat_ReturnValue) == 0x000020, "Member 'WIDGET_ConnectionIntegrity_C_Set_Integrity_Value::CallFunc_LessEqual_FloatFloat_ReturnValue' has a wrong offset!");
static_assert(offsetof(WIDGET_ConnectionIntegrity_C_Set_Integrity_Value, CallFunc_Conv_BoolToFloat_ReturnValue_1) == 0x000024, "Member 'WIDGET_ConnectionIntegrity_C_Set_Integrity_Value::CallFunc_Conv_BoolToFloat_ReturnValue_1' has a wrong offset!");
static_assert(offsetof(WIDGET_ConnectionIntegrity_C_Set_Integrity_Value, CallFunc_ConvertToDynamicMaterialInstance_ReturnValue_1) == 0x000028, "Member 'WIDGET_ConnectionIntegrity_C_Set_Integrity_Value::CallFunc_ConvertToDynamicMaterialInstance_ReturnValue_1' has a wrong offset!");
static_assert(offsetof(WIDGET_ConnectionIntegrity_C_Set_Integrity_Value, CallFunc_Divide_FloatFloat_ReturnValue_2) == 0x000030, "Member 'WIDGET_ConnectionIntegrity_C_Set_Integrity_Value::CallFunc_Divide_FloatFloat_ReturnValue_2' has a wrong offset!");
static_assert(offsetof(WIDGET_ConnectionIntegrity_C_Set_Integrity_Value, CallFunc_ConvertToDynamicMaterialInstance_ReturnValue_2) == 0x000038, "Member 'WIDGET_ConnectionIntegrity_C_Set_Integrity_Value::CallFunc_ConvertToDynamicMaterialInstance_ReturnValue_2' has a wrong offset!");

// Function WIDGET_ConnectionIntegrity.WIDGET_ConnectionIntegrity_C.SetConnectionStatus
// 0x0002 (0x0002 - 0x0000)
struct WIDGET_ConnectionIntegrity_C_SetConnectionStatus final
{
public:
	bool                                          HealthCritical;                                    // 0x0000(0x0001)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor)
	bool                                          TimeCritical;                                      // 0x0001(0x0001)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor)
};
static_assert(alignof(WIDGET_ConnectionIntegrity_C_SetConnectionStatus) == 0x000001, "Wrong alignment on WIDGET_ConnectionIntegrity_C_SetConnectionStatus");
static_assert(sizeof(WIDGET_ConnectionIntegrity_C_SetConnectionStatus) == 0x000002, "Wrong size on WIDGET_ConnectionIntegrity_C_SetConnectionStatus");
static_assert(offsetof(WIDGET_ConnectionIntegrity_C_SetConnectionStatus, HealthCritical) == 0x000000, "Member 'WIDGET_ConnectionIntegrity_C_SetConnectionStatus::HealthCritical' has a wrong offset!");
static_assert(offsetof(WIDGET_ConnectionIntegrity_C_SetConnectionStatus, TimeCritical) == 0x000001, "Member 'WIDGET_ConnectionIntegrity_C_SetConnectionStatus::TimeCritical' has a wrong offset!");

}

