#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: TASK_DestroySelf

#include "Basic.hpp"


namespace SDK::Params
{

// Function TASK_DestroySelf.TASK_DestroySelf_C.ExecuteUbergraph_TASK_DestroySelf
// 0x0018 (0x0018 - 0x0000)
struct TASK_DestroySelf_C_ExecuteUbergraph_TASK_DestroySelf final
{
public:
	int32                                         EntryPoint;                                        // 0x0000(0x0004)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_4[0x4];                                        // 0x0004(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	class AAIController*                          K2Node_Event_OwnerController;                      // 0x0008(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class APawn*                                  K2Node_Event_ControlledPawn;                       // 0x0010(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
};
static_assert(alignof(TASK_DestroySelf_C_ExecuteUbergraph_TASK_DestroySelf) == 0x000008, "Wrong alignment on TASK_DestroySelf_C_ExecuteUbergraph_TASK_DestroySelf");
static_assert(sizeof(TASK_DestroySelf_C_ExecuteUbergraph_TASK_DestroySelf) == 0x000018, "Wrong size on TASK_DestroySelf_C_ExecuteUbergraph_TASK_DestroySelf");
static_assert(offsetof(TASK_DestroySelf_C_ExecuteUbergraph_TASK_DestroySelf, EntryPoint) == 0x000000, "Member 'TASK_DestroySelf_C_ExecuteUbergraph_TASK_DestroySelf::EntryPoint' has a wrong offset!");
static_assert(offsetof(TASK_DestroySelf_C_ExecuteUbergraph_TASK_DestroySelf, K2Node_Event_OwnerController) == 0x000008, "Member 'TASK_DestroySelf_C_ExecuteUbergraph_TASK_DestroySelf::K2Node_Event_OwnerController' has a wrong offset!");
static_assert(offsetof(TASK_DestroySelf_C_ExecuteUbergraph_TASK_DestroySelf, K2Node_Event_ControlledPawn) == 0x000010, "Member 'TASK_DestroySelf_C_ExecuteUbergraph_TASK_DestroySelf::K2Node_Event_ControlledPawn' has a wrong offset!");

// Function TASK_DestroySelf.TASK_DestroySelf_C.ReceiveExecuteAI
// 0x0010 (0x0010 - 0x0000)
struct TASK_DestroySelf_C_ReceiveExecuteAI final
{
public:
	class AAIController*                          OwnerController;                                   // 0x0000(0x0008)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class APawn*                                  ControlledPawn;                                    // 0x0008(0x0008)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
};
static_assert(alignof(TASK_DestroySelf_C_ReceiveExecuteAI) == 0x000008, "Wrong alignment on TASK_DestroySelf_C_ReceiveExecuteAI");
static_assert(sizeof(TASK_DestroySelf_C_ReceiveExecuteAI) == 0x000010, "Wrong size on TASK_DestroySelf_C_ReceiveExecuteAI");
static_assert(offsetof(TASK_DestroySelf_C_ReceiveExecuteAI, OwnerController) == 0x000000, "Member 'TASK_DestroySelf_C_ReceiveExecuteAI::OwnerController' has a wrong offset!");
static_assert(offsetof(TASK_DestroySelf_C_ReceiveExecuteAI, ControlledPawn) == 0x000008, "Member 'TASK_DestroySelf_C_ReceiveExecuteAI::ControlledPawn' has a wrong offset!");

}

