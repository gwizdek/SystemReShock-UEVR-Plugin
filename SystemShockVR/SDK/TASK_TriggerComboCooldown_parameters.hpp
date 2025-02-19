#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: TASK_TriggerComboCooldown

#include "Basic.hpp"

#include "STRUCT_DefaultSkillComboParams_structs.hpp"


namespace SDK::Params
{

// Function TASK_TriggerComboCooldown.TASK_TriggerComboCooldown_C.ExecuteUbergraph_TASK_TriggerComboCooldown
// 0x0068 (0x0068 - 0x0000)
struct TASK_TriggerComboCooldown_C_ExecuteUbergraph_TASK_TriggerComboCooldown final
{
public:
	int32                                         EntryPoint;                                        // 0x0000(0x0004)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	int32                                         Temp_int_Array_Index_Variable;                     // 0x0004(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	int32                                         Temp_int_Loop_Counter_Variable;                    // 0x0008(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	int32                                         CallFunc_Add_IntInt_ReturnValue;                   // 0x000C(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class AAIController*                          K2Node_Event_OwnerController;                      // 0x0010(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class APawn*                                  K2Node_Event_ControlledPawn;                       // 0x0018(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class APAWN_Enemy_C*                          K2Node_DynamicCast_AsPAWN_Enemy;                   // 0x0020(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          K2Node_DynamicCast_bSuccess;                       // 0x0028(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_29[0x7];                                       // 0x0029(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	struct FSTRUCT_DefaultSkillComboParams        CallFunc_Array_Get_Item;                           // 0x0030(0x0030)(IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	int32                                         CallFunc_Array_Length_ReturnValue;                 // 0x0060(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          CallFunc_Less_IntInt_ReturnValue;                  // 0x0064(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	bool                                          CallFunc_EqualEqual_ObjectObject_ReturnValue;      // 0x0065(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
};
static_assert(alignof(TASK_TriggerComboCooldown_C_ExecuteUbergraph_TASK_TriggerComboCooldown) == 0x000008, "Wrong alignment on TASK_TriggerComboCooldown_C_ExecuteUbergraph_TASK_TriggerComboCooldown");
static_assert(sizeof(TASK_TriggerComboCooldown_C_ExecuteUbergraph_TASK_TriggerComboCooldown) == 0x000068, "Wrong size on TASK_TriggerComboCooldown_C_ExecuteUbergraph_TASK_TriggerComboCooldown");
static_assert(offsetof(TASK_TriggerComboCooldown_C_ExecuteUbergraph_TASK_TriggerComboCooldown, EntryPoint) == 0x000000, "Member 'TASK_TriggerComboCooldown_C_ExecuteUbergraph_TASK_TriggerComboCooldown::EntryPoint' has a wrong offset!");
static_assert(offsetof(TASK_TriggerComboCooldown_C_ExecuteUbergraph_TASK_TriggerComboCooldown, Temp_int_Array_Index_Variable) == 0x000004, "Member 'TASK_TriggerComboCooldown_C_ExecuteUbergraph_TASK_TriggerComboCooldown::Temp_int_Array_Index_Variable' has a wrong offset!");
static_assert(offsetof(TASK_TriggerComboCooldown_C_ExecuteUbergraph_TASK_TriggerComboCooldown, Temp_int_Loop_Counter_Variable) == 0x000008, "Member 'TASK_TriggerComboCooldown_C_ExecuteUbergraph_TASK_TriggerComboCooldown::Temp_int_Loop_Counter_Variable' has a wrong offset!");
static_assert(offsetof(TASK_TriggerComboCooldown_C_ExecuteUbergraph_TASK_TriggerComboCooldown, CallFunc_Add_IntInt_ReturnValue) == 0x00000C, "Member 'TASK_TriggerComboCooldown_C_ExecuteUbergraph_TASK_TriggerComboCooldown::CallFunc_Add_IntInt_ReturnValue' has a wrong offset!");
static_assert(offsetof(TASK_TriggerComboCooldown_C_ExecuteUbergraph_TASK_TriggerComboCooldown, K2Node_Event_OwnerController) == 0x000010, "Member 'TASK_TriggerComboCooldown_C_ExecuteUbergraph_TASK_TriggerComboCooldown::K2Node_Event_OwnerController' has a wrong offset!");
static_assert(offsetof(TASK_TriggerComboCooldown_C_ExecuteUbergraph_TASK_TriggerComboCooldown, K2Node_Event_ControlledPawn) == 0x000018, "Member 'TASK_TriggerComboCooldown_C_ExecuteUbergraph_TASK_TriggerComboCooldown::K2Node_Event_ControlledPawn' has a wrong offset!");
static_assert(offsetof(TASK_TriggerComboCooldown_C_ExecuteUbergraph_TASK_TriggerComboCooldown, K2Node_DynamicCast_AsPAWN_Enemy) == 0x000020, "Member 'TASK_TriggerComboCooldown_C_ExecuteUbergraph_TASK_TriggerComboCooldown::K2Node_DynamicCast_AsPAWN_Enemy' has a wrong offset!");
static_assert(offsetof(TASK_TriggerComboCooldown_C_ExecuteUbergraph_TASK_TriggerComboCooldown, K2Node_DynamicCast_bSuccess) == 0x000028, "Member 'TASK_TriggerComboCooldown_C_ExecuteUbergraph_TASK_TriggerComboCooldown::K2Node_DynamicCast_bSuccess' has a wrong offset!");
static_assert(offsetof(TASK_TriggerComboCooldown_C_ExecuteUbergraph_TASK_TriggerComboCooldown, CallFunc_Array_Get_Item) == 0x000030, "Member 'TASK_TriggerComboCooldown_C_ExecuteUbergraph_TASK_TriggerComboCooldown::CallFunc_Array_Get_Item' has a wrong offset!");
static_assert(offsetof(TASK_TriggerComboCooldown_C_ExecuteUbergraph_TASK_TriggerComboCooldown, CallFunc_Array_Length_ReturnValue) == 0x000060, "Member 'TASK_TriggerComboCooldown_C_ExecuteUbergraph_TASK_TriggerComboCooldown::CallFunc_Array_Length_ReturnValue' has a wrong offset!");
static_assert(offsetof(TASK_TriggerComboCooldown_C_ExecuteUbergraph_TASK_TriggerComboCooldown, CallFunc_Less_IntInt_ReturnValue) == 0x000064, "Member 'TASK_TriggerComboCooldown_C_ExecuteUbergraph_TASK_TriggerComboCooldown::CallFunc_Less_IntInt_ReturnValue' has a wrong offset!");
static_assert(offsetof(TASK_TriggerComboCooldown_C_ExecuteUbergraph_TASK_TriggerComboCooldown, CallFunc_EqualEqual_ObjectObject_ReturnValue) == 0x000065, "Member 'TASK_TriggerComboCooldown_C_ExecuteUbergraph_TASK_TriggerComboCooldown::CallFunc_EqualEqual_ObjectObject_ReturnValue' has a wrong offset!");

// Function TASK_TriggerComboCooldown.TASK_TriggerComboCooldown_C.ReceiveExecuteAI
// 0x0010 (0x0010 - 0x0000)
struct TASK_TriggerComboCooldown_C_ReceiveExecuteAI final
{
public:
	class AAIController*                          OwnerController;                                   // 0x0000(0x0008)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class APawn*                                  ControlledPawn;                                    // 0x0008(0x0008)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
};
static_assert(alignof(TASK_TriggerComboCooldown_C_ReceiveExecuteAI) == 0x000008, "Wrong alignment on TASK_TriggerComboCooldown_C_ReceiveExecuteAI");
static_assert(sizeof(TASK_TriggerComboCooldown_C_ReceiveExecuteAI) == 0x000010, "Wrong size on TASK_TriggerComboCooldown_C_ReceiveExecuteAI");
static_assert(offsetof(TASK_TriggerComboCooldown_C_ReceiveExecuteAI, OwnerController) == 0x000000, "Member 'TASK_TriggerComboCooldown_C_ReceiveExecuteAI::OwnerController' has a wrong offset!");
static_assert(offsetof(TASK_TriggerComboCooldown_C_ReceiveExecuteAI, ControlledPawn) == 0x000008, "Member 'TASK_TriggerComboCooldown_C_ReceiveExecuteAI::ControlledPawn' has a wrong offset!");

}

