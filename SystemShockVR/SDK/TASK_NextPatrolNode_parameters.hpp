#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: TASK_NextPatrolNode

#include "Basic.hpp"


namespace SDK::Params
{

// Function TASK_NextPatrolNode.TASK_NextPatrolNode_C.ExecuteUbergraph_TASK_NextPatrolNode
// 0x0028 (0x0028 - 0x0000)
struct TASK_NextPatrolNode_C_ExecuteUbergraph_TASK_NextPatrolNode final
{
public:
	int32                                         EntryPoint;                                        // 0x0000(0x0004)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_4[0x4];                                        // 0x0004(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	class AAIController*                          K2Node_Event_OwnerController;                      // 0x0008(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class APawn*                                  K2Node_Event_ControlledPawn;                       // 0x0010(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class APAWN_Enemy_C*                          K2Node_DynamicCast_AsPAWN_Enemy;                   // 0x0018(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          K2Node_DynamicCast_bSuccess;                       // 0x0020(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
};
static_assert(alignof(TASK_NextPatrolNode_C_ExecuteUbergraph_TASK_NextPatrolNode) == 0x000008, "Wrong alignment on TASK_NextPatrolNode_C_ExecuteUbergraph_TASK_NextPatrolNode");
static_assert(sizeof(TASK_NextPatrolNode_C_ExecuteUbergraph_TASK_NextPatrolNode) == 0x000028, "Wrong size on TASK_NextPatrolNode_C_ExecuteUbergraph_TASK_NextPatrolNode");
static_assert(offsetof(TASK_NextPatrolNode_C_ExecuteUbergraph_TASK_NextPatrolNode, EntryPoint) == 0x000000, "Member 'TASK_NextPatrolNode_C_ExecuteUbergraph_TASK_NextPatrolNode::EntryPoint' has a wrong offset!");
static_assert(offsetof(TASK_NextPatrolNode_C_ExecuteUbergraph_TASK_NextPatrolNode, K2Node_Event_OwnerController) == 0x000008, "Member 'TASK_NextPatrolNode_C_ExecuteUbergraph_TASK_NextPatrolNode::K2Node_Event_OwnerController' has a wrong offset!");
static_assert(offsetof(TASK_NextPatrolNode_C_ExecuteUbergraph_TASK_NextPatrolNode, K2Node_Event_ControlledPawn) == 0x000010, "Member 'TASK_NextPatrolNode_C_ExecuteUbergraph_TASK_NextPatrolNode::K2Node_Event_ControlledPawn' has a wrong offset!");
static_assert(offsetof(TASK_NextPatrolNode_C_ExecuteUbergraph_TASK_NextPatrolNode, K2Node_DynamicCast_AsPAWN_Enemy) == 0x000018, "Member 'TASK_NextPatrolNode_C_ExecuteUbergraph_TASK_NextPatrolNode::K2Node_DynamicCast_AsPAWN_Enemy' has a wrong offset!");
static_assert(offsetof(TASK_NextPatrolNode_C_ExecuteUbergraph_TASK_NextPatrolNode, K2Node_DynamicCast_bSuccess) == 0x000020, "Member 'TASK_NextPatrolNode_C_ExecuteUbergraph_TASK_NextPatrolNode::K2Node_DynamicCast_bSuccess' has a wrong offset!");

// Function TASK_NextPatrolNode.TASK_NextPatrolNode_C.ReceiveExecuteAI
// 0x0010 (0x0010 - 0x0000)
struct TASK_NextPatrolNode_C_ReceiveExecuteAI final
{
public:
	class AAIController*                          OwnerController;                                   // 0x0000(0x0008)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class APawn*                                  ControlledPawn;                                    // 0x0008(0x0008)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
};
static_assert(alignof(TASK_NextPatrolNode_C_ReceiveExecuteAI) == 0x000008, "Wrong alignment on TASK_NextPatrolNode_C_ReceiveExecuteAI");
static_assert(sizeof(TASK_NextPatrolNode_C_ReceiveExecuteAI) == 0x000010, "Wrong size on TASK_NextPatrolNode_C_ReceiveExecuteAI");
static_assert(offsetof(TASK_NextPatrolNode_C_ReceiveExecuteAI, OwnerController) == 0x000000, "Member 'TASK_NextPatrolNode_C_ReceiveExecuteAI::OwnerController' has a wrong offset!");
static_assert(offsetof(TASK_NextPatrolNode_C_ReceiveExecuteAI, ControlledPawn) == 0x000008, "Member 'TASK_NextPatrolNode_C_ReceiveExecuteAI::ControlledPawn' has a wrong offset!");

}

