#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: TASK_Cyber_CurveMovement

#include "Basic.hpp"

#include "CoreUObject_structs.hpp"
#include "Engine_structs.hpp"


namespace SDK::Params
{

// Function TASK_Cyber_CurveMovement.TASK_Cyber_CurveMovement_C.ExecuteUbergraph_TASK_Cyber_CurveMovement
// 0x00E0 (0x00E0 - 0x0000)
struct TASK_Cyber_CurveMovement_C_ExecuteUbergraph_TASK_Cyber_CurveMovement final
{
public:
	int32                                         EntryPoint;                                        // 0x0000(0x0004)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_4[0x4];                                        // 0x0004(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	class AActor*                                 K2Node_Event_OwnerActor;                           // 0x0008(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         K2Node_Event_DeltaSeconds;                         // 0x0010(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_14[0x4];                                       // 0x0014(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	class AAIController*                          K2Node_Event_OwnerController;                      // 0x0018(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class APawn*                                  K2Node_Event_ControlledPawn;                       // 0x0020(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class APAWN_CyberEnemy_C*                     K2Node_DynamicCast_AsPAWN_Cyber_Enemy;             // 0x0028(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          K2Node_DynamicCast_bSuccess;                       // 0x0030(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_31[0x3];                                       // 0x0031(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	float                                         CallFunc_GetPlayTimeInSeconds_ReturnValue;         // 0x0034(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         CallFunc_GetPlayTimeInSeconds_ReturnValue_1;       // 0x0038(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         CallFunc_Subtract_FloatFloat_ReturnValue;          // 0x003C(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         CallFunc_Multiply_FloatFloat_ReturnValue;          // 0x0040(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         CallFunc_Multiply_FloatFloat_ReturnValue_1;        // 0x0044(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FVector                                CallFunc_GetLocationAtDistanceAlongSpline_ReturnValue; // 0x0048(0x000C)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FHitResult                             CallFunc_K2_SetActorLocation_SweepHitResult;       // 0x0054(0x0088)(IsPlainOldData, NoDestructor, ContainsInstancedReference)
	bool                                          CallFunc_K2_SetActorLocation_ReturnValue;          // 0x00DC(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
};
static_assert(alignof(TASK_Cyber_CurveMovement_C_ExecuteUbergraph_TASK_Cyber_CurveMovement) == 0x000008, "Wrong alignment on TASK_Cyber_CurveMovement_C_ExecuteUbergraph_TASK_Cyber_CurveMovement");
static_assert(sizeof(TASK_Cyber_CurveMovement_C_ExecuteUbergraph_TASK_Cyber_CurveMovement) == 0x0000E0, "Wrong size on TASK_Cyber_CurveMovement_C_ExecuteUbergraph_TASK_Cyber_CurveMovement");
static_assert(offsetof(TASK_Cyber_CurveMovement_C_ExecuteUbergraph_TASK_Cyber_CurveMovement, EntryPoint) == 0x000000, "Member 'TASK_Cyber_CurveMovement_C_ExecuteUbergraph_TASK_Cyber_CurveMovement::EntryPoint' has a wrong offset!");
static_assert(offsetof(TASK_Cyber_CurveMovement_C_ExecuteUbergraph_TASK_Cyber_CurveMovement, K2Node_Event_OwnerActor) == 0x000008, "Member 'TASK_Cyber_CurveMovement_C_ExecuteUbergraph_TASK_Cyber_CurveMovement::K2Node_Event_OwnerActor' has a wrong offset!");
static_assert(offsetof(TASK_Cyber_CurveMovement_C_ExecuteUbergraph_TASK_Cyber_CurveMovement, K2Node_Event_DeltaSeconds) == 0x000010, "Member 'TASK_Cyber_CurveMovement_C_ExecuteUbergraph_TASK_Cyber_CurveMovement::K2Node_Event_DeltaSeconds' has a wrong offset!");
static_assert(offsetof(TASK_Cyber_CurveMovement_C_ExecuteUbergraph_TASK_Cyber_CurveMovement, K2Node_Event_OwnerController) == 0x000018, "Member 'TASK_Cyber_CurveMovement_C_ExecuteUbergraph_TASK_Cyber_CurveMovement::K2Node_Event_OwnerController' has a wrong offset!");
static_assert(offsetof(TASK_Cyber_CurveMovement_C_ExecuteUbergraph_TASK_Cyber_CurveMovement, K2Node_Event_ControlledPawn) == 0x000020, "Member 'TASK_Cyber_CurveMovement_C_ExecuteUbergraph_TASK_Cyber_CurveMovement::K2Node_Event_ControlledPawn' has a wrong offset!");
static_assert(offsetof(TASK_Cyber_CurveMovement_C_ExecuteUbergraph_TASK_Cyber_CurveMovement, K2Node_DynamicCast_AsPAWN_Cyber_Enemy) == 0x000028, "Member 'TASK_Cyber_CurveMovement_C_ExecuteUbergraph_TASK_Cyber_CurveMovement::K2Node_DynamicCast_AsPAWN_Cyber_Enemy' has a wrong offset!");
static_assert(offsetof(TASK_Cyber_CurveMovement_C_ExecuteUbergraph_TASK_Cyber_CurveMovement, K2Node_DynamicCast_bSuccess) == 0x000030, "Member 'TASK_Cyber_CurveMovement_C_ExecuteUbergraph_TASK_Cyber_CurveMovement::K2Node_DynamicCast_bSuccess' has a wrong offset!");
static_assert(offsetof(TASK_Cyber_CurveMovement_C_ExecuteUbergraph_TASK_Cyber_CurveMovement, CallFunc_GetPlayTimeInSeconds_ReturnValue) == 0x000034, "Member 'TASK_Cyber_CurveMovement_C_ExecuteUbergraph_TASK_Cyber_CurveMovement::CallFunc_GetPlayTimeInSeconds_ReturnValue' has a wrong offset!");
static_assert(offsetof(TASK_Cyber_CurveMovement_C_ExecuteUbergraph_TASK_Cyber_CurveMovement, CallFunc_GetPlayTimeInSeconds_ReturnValue_1) == 0x000038, "Member 'TASK_Cyber_CurveMovement_C_ExecuteUbergraph_TASK_Cyber_CurveMovement::CallFunc_GetPlayTimeInSeconds_ReturnValue_1' has a wrong offset!");
static_assert(offsetof(TASK_Cyber_CurveMovement_C_ExecuteUbergraph_TASK_Cyber_CurveMovement, CallFunc_Subtract_FloatFloat_ReturnValue) == 0x00003C, "Member 'TASK_Cyber_CurveMovement_C_ExecuteUbergraph_TASK_Cyber_CurveMovement::CallFunc_Subtract_FloatFloat_ReturnValue' has a wrong offset!");
static_assert(offsetof(TASK_Cyber_CurveMovement_C_ExecuteUbergraph_TASK_Cyber_CurveMovement, CallFunc_Multiply_FloatFloat_ReturnValue) == 0x000040, "Member 'TASK_Cyber_CurveMovement_C_ExecuteUbergraph_TASK_Cyber_CurveMovement::CallFunc_Multiply_FloatFloat_ReturnValue' has a wrong offset!");
static_assert(offsetof(TASK_Cyber_CurveMovement_C_ExecuteUbergraph_TASK_Cyber_CurveMovement, CallFunc_Multiply_FloatFloat_ReturnValue_1) == 0x000044, "Member 'TASK_Cyber_CurveMovement_C_ExecuteUbergraph_TASK_Cyber_CurveMovement::CallFunc_Multiply_FloatFloat_ReturnValue_1' has a wrong offset!");
static_assert(offsetof(TASK_Cyber_CurveMovement_C_ExecuteUbergraph_TASK_Cyber_CurveMovement, CallFunc_GetLocationAtDistanceAlongSpline_ReturnValue) == 0x000048, "Member 'TASK_Cyber_CurveMovement_C_ExecuteUbergraph_TASK_Cyber_CurveMovement::CallFunc_GetLocationAtDistanceAlongSpline_ReturnValue' has a wrong offset!");
static_assert(offsetof(TASK_Cyber_CurveMovement_C_ExecuteUbergraph_TASK_Cyber_CurveMovement, CallFunc_K2_SetActorLocation_SweepHitResult) == 0x000054, "Member 'TASK_Cyber_CurveMovement_C_ExecuteUbergraph_TASK_Cyber_CurveMovement::CallFunc_K2_SetActorLocation_SweepHitResult' has a wrong offset!");
static_assert(offsetof(TASK_Cyber_CurveMovement_C_ExecuteUbergraph_TASK_Cyber_CurveMovement, CallFunc_K2_SetActorLocation_ReturnValue) == 0x0000DC, "Member 'TASK_Cyber_CurveMovement_C_ExecuteUbergraph_TASK_Cyber_CurveMovement::CallFunc_K2_SetActorLocation_ReturnValue' has a wrong offset!");

// Function TASK_Cyber_CurveMovement.TASK_Cyber_CurveMovement_C.ReceiveExecuteAI
// 0x0010 (0x0010 - 0x0000)
struct TASK_Cyber_CurveMovement_C_ReceiveExecuteAI final
{
public:
	class AAIController*                          OwnerController;                                   // 0x0000(0x0008)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class APawn*                                  ControlledPawn;                                    // 0x0008(0x0008)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
};
static_assert(alignof(TASK_Cyber_CurveMovement_C_ReceiveExecuteAI) == 0x000008, "Wrong alignment on TASK_Cyber_CurveMovement_C_ReceiveExecuteAI");
static_assert(sizeof(TASK_Cyber_CurveMovement_C_ReceiveExecuteAI) == 0x000010, "Wrong size on TASK_Cyber_CurveMovement_C_ReceiveExecuteAI");
static_assert(offsetof(TASK_Cyber_CurveMovement_C_ReceiveExecuteAI, OwnerController) == 0x000000, "Member 'TASK_Cyber_CurveMovement_C_ReceiveExecuteAI::OwnerController' has a wrong offset!");
static_assert(offsetof(TASK_Cyber_CurveMovement_C_ReceiveExecuteAI, ControlledPawn) == 0x000008, "Member 'TASK_Cyber_CurveMovement_C_ReceiveExecuteAI::ControlledPawn' has a wrong offset!");

// Function TASK_Cyber_CurveMovement.TASK_Cyber_CurveMovement_C.ReceiveTick
// 0x0010 (0x0010 - 0x0000)
struct TASK_Cyber_CurveMovement_C_ReceiveTick final
{
public:
	class AActor*                                 OwnerActor;                                        // 0x0000(0x0008)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         DeltaSeconds;                                      // 0x0008(0x0004)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
};
static_assert(alignof(TASK_Cyber_CurveMovement_C_ReceiveTick) == 0x000008, "Wrong alignment on TASK_Cyber_CurveMovement_C_ReceiveTick");
static_assert(sizeof(TASK_Cyber_CurveMovement_C_ReceiveTick) == 0x000010, "Wrong size on TASK_Cyber_CurveMovement_C_ReceiveTick");
static_assert(offsetof(TASK_Cyber_CurveMovement_C_ReceiveTick, OwnerActor) == 0x000000, "Member 'TASK_Cyber_CurveMovement_C_ReceiveTick::OwnerActor' has a wrong offset!");
static_assert(offsetof(TASK_Cyber_CurveMovement_C_ReceiveTick, DeltaSeconds) == 0x000008, "Member 'TASK_Cyber_CurveMovement_C_ReceiveTick::DeltaSeconds' has a wrong offset!");

}

