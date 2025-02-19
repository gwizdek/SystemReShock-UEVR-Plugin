#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: TASK_MobileLaser_Beam_LongRange

#include "Basic.hpp"

#include "CoreUObject_structs.hpp"
#include "Engine_structs.hpp"
#include "ENUM_MobileLaser_BeamState_structs.hpp"


namespace SDK::Params
{

// Function TASK_MobileLaser_Beam_LongRange.TASK_MobileLaser_Beam_LongRange_C.ExecuteUbergraph_TASK_MobileLaser_Beam_LongRange
// 0x0018 (0x0018 - 0x0000)
struct TASK_MobileLaser_Beam_LongRange_C_ExecuteUbergraph_TASK_MobileLaser_Beam_LongRange final
{
public:
	int32                                         EntryPoint;                                        // 0x0000(0x0004)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_4[0x4];                                        // 0x0004(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	class AAIController*                          K2Node_Event_OwnerController;                      // 0x0008(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class APawn*                                  K2Node_Event_ControlledPawn;                       // 0x0010(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
};
static_assert(alignof(TASK_MobileLaser_Beam_LongRange_C_ExecuteUbergraph_TASK_MobileLaser_Beam_LongRange) == 0x000008, "Wrong alignment on TASK_MobileLaser_Beam_LongRange_C_ExecuteUbergraph_TASK_MobileLaser_Beam_LongRange");
static_assert(sizeof(TASK_MobileLaser_Beam_LongRange_C_ExecuteUbergraph_TASK_MobileLaser_Beam_LongRange) == 0x000018, "Wrong size on TASK_MobileLaser_Beam_LongRange_C_ExecuteUbergraph_TASK_MobileLaser_Beam_LongRange");
static_assert(offsetof(TASK_MobileLaser_Beam_LongRange_C_ExecuteUbergraph_TASK_MobileLaser_Beam_LongRange, EntryPoint) == 0x000000, "Member 'TASK_MobileLaser_Beam_LongRange_C_ExecuteUbergraph_TASK_MobileLaser_Beam_LongRange::EntryPoint' has a wrong offset!");
static_assert(offsetof(TASK_MobileLaser_Beam_LongRange_C_ExecuteUbergraph_TASK_MobileLaser_Beam_LongRange, K2Node_Event_OwnerController) == 0x000008, "Member 'TASK_MobileLaser_Beam_LongRange_C_ExecuteUbergraph_TASK_MobileLaser_Beam_LongRange::K2Node_Event_OwnerController' has a wrong offset!");
static_assert(offsetof(TASK_MobileLaser_Beam_LongRange_C_ExecuteUbergraph_TASK_MobileLaser_Beam_LongRange, K2Node_Event_ControlledPawn) == 0x000010, "Member 'TASK_MobileLaser_Beam_LongRange_C_ExecuteUbergraph_TASK_MobileLaser_Beam_LongRange::K2Node_Event_ControlledPawn' has a wrong offset!");

// Function TASK_MobileLaser_Beam_LongRange.TASK_MobileLaser_Beam_LongRange_C.ReceiveExecuteAI
// 0x0010 (0x0010 - 0x0000)
struct TASK_MobileLaser_Beam_LongRange_C_ReceiveExecuteAI final
{
public:
	class AAIController*                          OwnerController;                                   // 0x0000(0x0008)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class APawn*                                  ControlledPawn;                                    // 0x0008(0x0008)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
};
static_assert(alignof(TASK_MobileLaser_Beam_LongRange_C_ReceiveExecuteAI) == 0x000008, "Wrong alignment on TASK_MobileLaser_Beam_LongRange_C_ReceiveExecuteAI");
static_assert(sizeof(TASK_MobileLaser_Beam_LongRange_C_ReceiveExecuteAI) == 0x000010, "Wrong size on TASK_MobileLaser_Beam_LongRange_C_ReceiveExecuteAI");
static_assert(offsetof(TASK_MobileLaser_Beam_LongRange_C_ReceiveExecuteAI, OwnerController) == 0x000000, "Member 'TASK_MobileLaser_Beam_LongRange_C_ReceiveExecuteAI::OwnerController' has a wrong offset!");
static_assert(offsetof(TASK_MobileLaser_Beam_LongRange_C_ReceiveExecuteAI, ControlledPawn) == 0x000008, "Member 'TASK_MobileLaser_Beam_LongRange_C_ReceiveExecuteAI::ControlledPawn' has a wrong offset!");

// Function TASK_MobileLaser_Beam_LongRange.TASK_MobileLaser_Beam_LongRange_C.UpdateBeamOn
// 0x001C (0x001C - 0x0000)
struct TASK_MobileLaser_Beam_LongRange_C_UpdateBeamOn final
{
public:
	float                                         DeltaSeconds;                                      // 0x0000(0x0004)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         Progress;                                          // 0x0004(0x0004)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         CallFunc_GetPlayTimeInSeconds_ReturnValue;         // 0x0008(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          CallFunc_GreaterEqual_FloatFloat_ReturnValue;      // 0x000C(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_D[0x3];                                        // 0x000D(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	float                                         CallFunc_Subtract_FloatFloat_ReturnValue;          // 0x0010(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         CallFunc_Divide_FloatFloat_ReturnValue;            // 0x0014(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         CallFunc_FClamp_ReturnValue;                       // 0x0018(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
};
static_assert(alignof(TASK_MobileLaser_Beam_LongRange_C_UpdateBeamOn) == 0x000004, "Wrong alignment on TASK_MobileLaser_Beam_LongRange_C_UpdateBeamOn");
static_assert(sizeof(TASK_MobileLaser_Beam_LongRange_C_UpdateBeamOn) == 0x00001C, "Wrong size on TASK_MobileLaser_Beam_LongRange_C_UpdateBeamOn");
static_assert(offsetof(TASK_MobileLaser_Beam_LongRange_C_UpdateBeamOn, DeltaSeconds) == 0x000000, "Member 'TASK_MobileLaser_Beam_LongRange_C_UpdateBeamOn::DeltaSeconds' has a wrong offset!");
static_assert(offsetof(TASK_MobileLaser_Beam_LongRange_C_UpdateBeamOn, Progress) == 0x000004, "Member 'TASK_MobileLaser_Beam_LongRange_C_UpdateBeamOn::Progress' has a wrong offset!");
static_assert(offsetof(TASK_MobileLaser_Beam_LongRange_C_UpdateBeamOn, CallFunc_GetPlayTimeInSeconds_ReturnValue) == 0x000008, "Member 'TASK_MobileLaser_Beam_LongRange_C_UpdateBeamOn::CallFunc_GetPlayTimeInSeconds_ReturnValue' has a wrong offset!");
static_assert(offsetof(TASK_MobileLaser_Beam_LongRange_C_UpdateBeamOn, CallFunc_GreaterEqual_FloatFloat_ReturnValue) == 0x00000C, "Member 'TASK_MobileLaser_Beam_LongRange_C_UpdateBeamOn::CallFunc_GreaterEqual_FloatFloat_ReturnValue' has a wrong offset!");
static_assert(offsetof(TASK_MobileLaser_Beam_LongRange_C_UpdateBeamOn, CallFunc_Subtract_FloatFloat_ReturnValue) == 0x000010, "Member 'TASK_MobileLaser_Beam_LongRange_C_UpdateBeamOn::CallFunc_Subtract_FloatFloat_ReturnValue' has a wrong offset!");
static_assert(offsetof(TASK_MobileLaser_Beam_LongRange_C_UpdateBeamOn, CallFunc_Divide_FloatFloat_ReturnValue) == 0x000014, "Member 'TASK_MobileLaser_Beam_LongRange_C_UpdateBeamOn::CallFunc_Divide_FloatFloat_ReturnValue' has a wrong offset!");
static_assert(offsetof(TASK_MobileLaser_Beam_LongRange_C_UpdateBeamOn, CallFunc_FClamp_ReturnValue) == 0x000018, "Member 'TASK_MobileLaser_Beam_LongRange_C_UpdateBeamOn::CallFunc_FClamp_ReturnValue' has a wrong offset!");

// Function TASK_MobileLaser_Beam_LongRange.TASK_MobileLaser_Beam_LongRange_C.UpdateBeamTurningOn
// 0x0014 (0x0014 - 0x0000)
struct TASK_MobileLaser_Beam_LongRange_C_UpdateBeamTurningOn final
{
public:
	float                                         DeltaSeconds;                                      // 0x0000(0x0004)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         Progress;                                          // 0x0004(0x0004)(Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         CurrentProgress;                                   // 0x0008(0x0004)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         CallFunc_UpdateBeamTurningOn_Progress;             // 0x000C(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          CallFunc_GreaterEqual_FloatFloat_ReturnValue;      // 0x0010(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
};
static_assert(alignof(TASK_MobileLaser_Beam_LongRange_C_UpdateBeamTurningOn) == 0x000004, "Wrong alignment on TASK_MobileLaser_Beam_LongRange_C_UpdateBeamTurningOn");
static_assert(sizeof(TASK_MobileLaser_Beam_LongRange_C_UpdateBeamTurningOn) == 0x000014, "Wrong size on TASK_MobileLaser_Beam_LongRange_C_UpdateBeamTurningOn");
static_assert(offsetof(TASK_MobileLaser_Beam_LongRange_C_UpdateBeamTurningOn, DeltaSeconds) == 0x000000, "Member 'TASK_MobileLaser_Beam_LongRange_C_UpdateBeamTurningOn::DeltaSeconds' has a wrong offset!");
static_assert(offsetof(TASK_MobileLaser_Beam_LongRange_C_UpdateBeamTurningOn, Progress) == 0x000004, "Member 'TASK_MobileLaser_Beam_LongRange_C_UpdateBeamTurningOn::Progress' has a wrong offset!");
static_assert(offsetof(TASK_MobileLaser_Beam_LongRange_C_UpdateBeamTurningOn, CurrentProgress) == 0x000008, "Member 'TASK_MobileLaser_Beam_LongRange_C_UpdateBeamTurningOn::CurrentProgress' has a wrong offset!");
static_assert(offsetof(TASK_MobileLaser_Beam_LongRange_C_UpdateBeamTurningOn, CallFunc_UpdateBeamTurningOn_Progress) == 0x00000C, "Member 'TASK_MobileLaser_Beam_LongRange_C_UpdateBeamTurningOn::CallFunc_UpdateBeamTurningOn_Progress' has a wrong offset!");
static_assert(offsetof(TASK_MobileLaser_Beam_LongRange_C_UpdateBeamTurningOn, CallFunc_GreaterEqual_FloatFloat_ReturnValue) == 0x000010, "Member 'TASK_MobileLaser_Beam_LongRange_C_UpdateBeamTurningOn::CallFunc_GreaterEqual_FloatFloat_ReturnValue' has a wrong offset!");

// Function TASK_MobileLaser_Beam_LongRange.TASK_MobileLaser_Beam_LongRange_C.SetBeamState
// 0x01A0 (0x01A0 - 0x0000)
struct TASK_MobileLaser_Beam_LongRange_C_SetBeamState final
{
public:
	ENUM_MobileLaser_BeamState                    State;                                             // 0x0000(0x0001)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          K2Node_SwitchEnum_CmpSuccess;                      // 0x0001(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_2[0x2];                                        // 0x0002(0x0002)(Fixing Size After Last Property [ Dumper-7 ])
	class FName                                   CallFunc_Array_Get_Item;                           // 0x0004(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_C[0x4];                                        // 0x000C(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	class UNiagaraComponent*                      CallFunc_Array_Get_Item_1;                         // 0x0010(0x0008)(ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_18[0x8];                                       // 0x0018(0x0008)(Fixing Size After Last Property [ Dumper-7 ])
	struct FTransform                             CallFunc_GetSocketTransform_ReturnValue;           // 0x0020(0x0030)(IsPlainOldData, NoDestructor)
	struct FVector                                CallFunc_BreakTransform_Location;                  // 0x0050(0x000C)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FRotator                               CallFunc_BreakTransform_Rotation;                  // 0x005C(0x000C)(ZeroConstructor, IsPlainOldData, NoDestructor)
	struct FVector                                CallFunc_BreakTransform_Scale;                     // 0x0068(0x000C)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_74[0x4];                                       // 0x0074(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	class UNiagaraComponent*                      CallFunc_SpawnSystemAtLocation_ReturnValue;        // 0x0078(0x0008)(ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class FName                                   CallFunc_Array_Get_Item_2;                         // 0x0080(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FHitResult                             CallFunc_BeamDamageTraceSingle_Result;             // 0x0088(0x0088)(IsPlainOldData, NoDestructor, ContainsInstancedReference)
	bool                                          CallFunc_BreakHitResult_bBlockingHit;              // 0x0110(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	bool                                          CallFunc_BreakHitResult_bInitialOverlap;           // 0x0111(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_112[0x2];                                      // 0x0112(0x0002)(Fixing Size After Last Property [ Dumper-7 ])
	float                                         CallFunc_BreakHitResult_Time;                      // 0x0114(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         CallFunc_BreakHitResult_Distance;                  // 0x0118(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FVector                                CallFunc_BreakHitResult_Location;                  // 0x011C(0x000C)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FVector                                CallFunc_BreakHitResult_ImpactPoint;               // 0x0128(0x000C)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FVector                                CallFunc_BreakHitResult_Normal;                    // 0x0134(0x000C)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FVector                                CallFunc_BreakHitResult_ImpactNormal;              // 0x0140(0x000C)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_14C[0x4];                                      // 0x014C(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	class UPhysicalMaterial*                      CallFunc_BreakHitResult_PhysMat;                   // 0x0150(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class AActor*                                 CallFunc_BreakHitResult_HitActor;                  // 0x0158(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UPrimitiveComponent*                    CallFunc_BreakHitResult_HitComponent;              // 0x0160(0x0008)(ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class FName                                   CallFunc_BreakHitResult_HitBoneName;               // 0x0168(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	int32                                         CallFunc_BreakHitResult_HitItem;                   // 0x0170(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	int32                                         CallFunc_BreakHitResult_ElementIndex;              // 0x0174(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	int32                                         CallFunc_BreakHitResult_FaceIndex;                 // 0x0178(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FVector                                CallFunc_BreakHitResult_TraceStart;                // 0x017C(0x000C)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FVector                                CallFunc_BreakHitResult_TraceEnd;                  // 0x0188(0x000C)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FVector                                CallFunc_SelectVector_ReturnValue;                 // 0x0194(0x000C)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
};
static_assert(alignof(TASK_MobileLaser_Beam_LongRange_C_SetBeamState) == 0x000010, "Wrong alignment on TASK_MobileLaser_Beam_LongRange_C_SetBeamState");
static_assert(sizeof(TASK_MobileLaser_Beam_LongRange_C_SetBeamState) == 0x0001A0, "Wrong size on TASK_MobileLaser_Beam_LongRange_C_SetBeamState");
static_assert(offsetof(TASK_MobileLaser_Beam_LongRange_C_SetBeamState, State) == 0x000000, "Member 'TASK_MobileLaser_Beam_LongRange_C_SetBeamState::State' has a wrong offset!");
static_assert(offsetof(TASK_MobileLaser_Beam_LongRange_C_SetBeamState, K2Node_SwitchEnum_CmpSuccess) == 0x000001, "Member 'TASK_MobileLaser_Beam_LongRange_C_SetBeamState::K2Node_SwitchEnum_CmpSuccess' has a wrong offset!");
static_assert(offsetof(TASK_MobileLaser_Beam_LongRange_C_SetBeamState, CallFunc_Array_Get_Item) == 0x000004, "Member 'TASK_MobileLaser_Beam_LongRange_C_SetBeamState::CallFunc_Array_Get_Item' has a wrong offset!");
static_assert(offsetof(TASK_MobileLaser_Beam_LongRange_C_SetBeamState, CallFunc_Array_Get_Item_1) == 0x000010, "Member 'TASK_MobileLaser_Beam_LongRange_C_SetBeamState::CallFunc_Array_Get_Item_1' has a wrong offset!");
static_assert(offsetof(TASK_MobileLaser_Beam_LongRange_C_SetBeamState, CallFunc_GetSocketTransform_ReturnValue) == 0x000020, "Member 'TASK_MobileLaser_Beam_LongRange_C_SetBeamState::CallFunc_GetSocketTransform_ReturnValue' has a wrong offset!");
static_assert(offsetof(TASK_MobileLaser_Beam_LongRange_C_SetBeamState, CallFunc_BreakTransform_Location) == 0x000050, "Member 'TASK_MobileLaser_Beam_LongRange_C_SetBeamState::CallFunc_BreakTransform_Location' has a wrong offset!");
static_assert(offsetof(TASK_MobileLaser_Beam_LongRange_C_SetBeamState, CallFunc_BreakTransform_Rotation) == 0x00005C, "Member 'TASK_MobileLaser_Beam_LongRange_C_SetBeamState::CallFunc_BreakTransform_Rotation' has a wrong offset!");
static_assert(offsetof(TASK_MobileLaser_Beam_LongRange_C_SetBeamState, CallFunc_BreakTransform_Scale) == 0x000068, "Member 'TASK_MobileLaser_Beam_LongRange_C_SetBeamState::CallFunc_BreakTransform_Scale' has a wrong offset!");
static_assert(offsetof(TASK_MobileLaser_Beam_LongRange_C_SetBeamState, CallFunc_SpawnSystemAtLocation_ReturnValue) == 0x000078, "Member 'TASK_MobileLaser_Beam_LongRange_C_SetBeamState::CallFunc_SpawnSystemAtLocation_ReturnValue' has a wrong offset!");
static_assert(offsetof(TASK_MobileLaser_Beam_LongRange_C_SetBeamState, CallFunc_Array_Get_Item_2) == 0x000080, "Member 'TASK_MobileLaser_Beam_LongRange_C_SetBeamState::CallFunc_Array_Get_Item_2' has a wrong offset!");
static_assert(offsetof(TASK_MobileLaser_Beam_LongRange_C_SetBeamState, CallFunc_BeamDamageTraceSingle_Result) == 0x000088, "Member 'TASK_MobileLaser_Beam_LongRange_C_SetBeamState::CallFunc_BeamDamageTraceSingle_Result' has a wrong offset!");
static_assert(offsetof(TASK_MobileLaser_Beam_LongRange_C_SetBeamState, CallFunc_BreakHitResult_bBlockingHit) == 0x000110, "Member 'TASK_MobileLaser_Beam_LongRange_C_SetBeamState::CallFunc_BreakHitResult_bBlockingHit' has a wrong offset!");
static_assert(offsetof(TASK_MobileLaser_Beam_LongRange_C_SetBeamState, CallFunc_BreakHitResult_bInitialOverlap) == 0x000111, "Member 'TASK_MobileLaser_Beam_LongRange_C_SetBeamState::CallFunc_BreakHitResult_bInitialOverlap' has a wrong offset!");
static_assert(offsetof(TASK_MobileLaser_Beam_LongRange_C_SetBeamState, CallFunc_BreakHitResult_Time) == 0x000114, "Member 'TASK_MobileLaser_Beam_LongRange_C_SetBeamState::CallFunc_BreakHitResult_Time' has a wrong offset!");
static_assert(offsetof(TASK_MobileLaser_Beam_LongRange_C_SetBeamState, CallFunc_BreakHitResult_Distance) == 0x000118, "Member 'TASK_MobileLaser_Beam_LongRange_C_SetBeamState::CallFunc_BreakHitResult_Distance' has a wrong offset!");
static_assert(offsetof(TASK_MobileLaser_Beam_LongRange_C_SetBeamState, CallFunc_BreakHitResult_Location) == 0x00011C, "Member 'TASK_MobileLaser_Beam_LongRange_C_SetBeamState::CallFunc_BreakHitResult_Location' has a wrong offset!");
static_assert(offsetof(TASK_MobileLaser_Beam_LongRange_C_SetBeamState, CallFunc_BreakHitResult_ImpactPoint) == 0x000128, "Member 'TASK_MobileLaser_Beam_LongRange_C_SetBeamState::CallFunc_BreakHitResult_ImpactPoint' has a wrong offset!");
static_assert(offsetof(TASK_MobileLaser_Beam_LongRange_C_SetBeamState, CallFunc_BreakHitResult_Normal) == 0x000134, "Member 'TASK_MobileLaser_Beam_LongRange_C_SetBeamState::CallFunc_BreakHitResult_Normal' has a wrong offset!");
static_assert(offsetof(TASK_MobileLaser_Beam_LongRange_C_SetBeamState, CallFunc_BreakHitResult_ImpactNormal) == 0x000140, "Member 'TASK_MobileLaser_Beam_LongRange_C_SetBeamState::CallFunc_BreakHitResult_ImpactNormal' has a wrong offset!");
static_assert(offsetof(TASK_MobileLaser_Beam_LongRange_C_SetBeamState, CallFunc_BreakHitResult_PhysMat) == 0x000150, "Member 'TASK_MobileLaser_Beam_LongRange_C_SetBeamState::CallFunc_BreakHitResult_PhysMat' has a wrong offset!");
static_assert(offsetof(TASK_MobileLaser_Beam_LongRange_C_SetBeamState, CallFunc_BreakHitResult_HitActor) == 0x000158, "Member 'TASK_MobileLaser_Beam_LongRange_C_SetBeamState::CallFunc_BreakHitResult_HitActor' has a wrong offset!");
static_assert(offsetof(TASK_MobileLaser_Beam_LongRange_C_SetBeamState, CallFunc_BreakHitResult_HitComponent) == 0x000160, "Member 'TASK_MobileLaser_Beam_LongRange_C_SetBeamState::CallFunc_BreakHitResult_HitComponent' has a wrong offset!");
static_assert(offsetof(TASK_MobileLaser_Beam_LongRange_C_SetBeamState, CallFunc_BreakHitResult_HitBoneName) == 0x000168, "Member 'TASK_MobileLaser_Beam_LongRange_C_SetBeamState::CallFunc_BreakHitResult_HitBoneName' has a wrong offset!");
static_assert(offsetof(TASK_MobileLaser_Beam_LongRange_C_SetBeamState, CallFunc_BreakHitResult_HitItem) == 0x000170, "Member 'TASK_MobileLaser_Beam_LongRange_C_SetBeamState::CallFunc_BreakHitResult_HitItem' has a wrong offset!");
static_assert(offsetof(TASK_MobileLaser_Beam_LongRange_C_SetBeamState, CallFunc_BreakHitResult_ElementIndex) == 0x000174, "Member 'TASK_MobileLaser_Beam_LongRange_C_SetBeamState::CallFunc_BreakHitResult_ElementIndex' has a wrong offset!");
static_assert(offsetof(TASK_MobileLaser_Beam_LongRange_C_SetBeamState, CallFunc_BreakHitResult_FaceIndex) == 0x000178, "Member 'TASK_MobileLaser_Beam_LongRange_C_SetBeamState::CallFunc_BreakHitResult_FaceIndex' has a wrong offset!");
static_assert(offsetof(TASK_MobileLaser_Beam_LongRange_C_SetBeamState, CallFunc_BreakHitResult_TraceStart) == 0x00017C, "Member 'TASK_MobileLaser_Beam_LongRange_C_SetBeamState::CallFunc_BreakHitResult_TraceStart' has a wrong offset!");
static_assert(offsetof(TASK_MobileLaser_Beam_LongRange_C_SetBeamState, CallFunc_BreakHitResult_TraceEnd) == 0x000188, "Member 'TASK_MobileLaser_Beam_LongRange_C_SetBeamState::CallFunc_BreakHitResult_TraceEnd' has a wrong offset!");
static_assert(offsetof(TASK_MobileLaser_Beam_LongRange_C_SetBeamState, CallFunc_SelectVector_ReturnValue) == 0x000194, "Member 'TASK_MobileLaser_Beam_LongRange_C_SetBeamState::CallFunc_SelectVector_ReturnValue' has a wrong offset!");

// Function TASK_MobileLaser_Beam_LongRange.TASK_MobileLaser_Beam_LongRange_C.GetBeamAimDirection
// 0x00C0 (0x00C0 - 0x0000)
struct TASK_MobileLaser_Beam_LongRange_C_GetBeamAimDirection final
{
public:
	class FName                                   BeamSocket;                                        // 0x0000(0x0008)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FVector                                BeamAimDirection;                                  // 0x0008(0x000C)(Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FVector                                AimLocation;                                       // 0x0014(0x000C)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FVector                                SocketLocation;                                    // 0x0020(0x000C)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FVector                                CallFunc_GetLocalForwardDirection_ForwardDirection; // 0x002C(0x000C)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_38[0x8];                                       // 0x0038(0x0008)(Fixing Size After Last Property [ Dumper-7 ])
	struct FTransform                             CallFunc_GetSocketTransform_ReturnValue;           // 0x0040(0x0030)(IsPlainOldData, NoDestructor)
	struct FVector                                CallFunc_TransformDirection_ReturnValue;           // 0x0070(0x000C)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FVector                                CallFunc_GetSocketLocation_ReturnValue;            // 0x007C(0x000C)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FVector                                CallFunc_Subtract_VectorVector_ReturnValue;        // 0x0088(0x000C)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FVector                                CallFunc_Normal_ReturnValue;                       // 0x0094(0x000C)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FVector                                CallFunc_ClampDirectionInCone_ClampedDirection;    // 0x00A0(0x000C)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FVector                                CallFunc_GetBestAimTargetLocation_BestTargetLocation; // 0x00AC(0x000C)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
};
static_assert(alignof(TASK_MobileLaser_Beam_LongRange_C_GetBeamAimDirection) == 0x000010, "Wrong alignment on TASK_MobileLaser_Beam_LongRange_C_GetBeamAimDirection");
static_assert(sizeof(TASK_MobileLaser_Beam_LongRange_C_GetBeamAimDirection) == 0x0000C0, "Wrong size on TASK_MobileLaser_Beam_LongRange_C_GetBeamAimDirection");
static_assert(offsetof(TASK_MobileLaser_Beam_LongRange_C_GetBeamAimDirection, BeamSocket) == 0x000000, "Member 'TASK_MobileLaser_Beam_LongRange_C_GetBeamAimDirection::BeamSocket' has a wrong offset!");
static_assert(offsetof(TASK_MobileLaser_Beam_LongRange_C_GetBeamAimDirection, BeamAimDirection) == 0x000008, "Member 'TASK_MobileLaser_Beam_LongRange_C_GetBeamAimDirection::BeamAimDirection' has a wrong offset!");
static_assert(offsetof(TASK_MobileLaser_Beam_LongRange_C_GetBeamAimDirection, AimLocation) == 0x000014, "Member 'TASK_MobileLaser_Beam_LongRange_C_GetBeamAimDirection::AimLocation' has a wrong offset!");
static_assert(offsetof(TASK_MobileLaser_Beam_LongRange_C_GetBeamAimDirection, SocketLocation) == 0x000020, "Member 'TASK_MobileLaser_Beam_LongRange_C_GetBeamAimDirection::SocketLocation' has a wrong offset!");
static_assert(offsetof(TASK_MobileLaser_Beam_LongRange_C_GetBeamAimDirection, CallFunc_GetLocalForwardDirection_ForwardDirection) == 0x00002C, "Member 'TASK_MobileLaser_Beam_LongRange_C_GetBeamAimDirection::CallFunc_GetLocalForwardDirection_ForwardDirection' has a wrong offset!");
static_assert(offsetof(TASK_MobileLaser_Beam_LongRange_C_GetBeamAimDirection, CallFunc_GetSocketTransform_ReturnValue) == 0x000040, "Member 'TASK_MobileLaser_Beam_LongRange_C_GetBeamAimDirection::CallFunc_GetSocketTransform_ReturnValue' has a wrong offset!");
static_assert(offsetof(TASK_MobileLaser_Beam_LongRange_C_GetBeamAimDirection, CallFunc_TransformDirection_ReturnValue) == 0x000070, "Member 'TASK_MobileLaser_Beam_LongRange_C_GetBeamAimDirection::CallFunc_TransformDirection_ReturnValue' has a wrong offset!");
static_assert(offsetof(TASK_MobileLaser_Beam_LongRange_C_GetBeamAimDirection, CallFunc_GetSocketLocation_ReturnValue) == 0x00007C, "Member 'TASK_MobileLaser_Beam_LongRange_C_GetBeamAimDirection::CallFunc_GetSocketLocation_ReturnValue' has a wrong offset!");
static_assert(offsetof(TASK_MobileLaser_Beam_LongRange_C_GetBeamAimDirection, CallFunc_Subtract_VectorVector_ReturnValue) == 0x000088, "Member 'TASK_MobileLaser_Beam_LongRange_C_GetBeamAimDirection::CallFunc_Subtract_VectorVector_ReturnValue' has a wrong offset!");
static_assert(offsetof(TASK_MobileLaser_Beam_LongRange_C_GetBeamAimDirection, CallFunc_Normal_ReturnValue) == 0x000094, "Member 'TASK_MobileLaser_Beam_LongRange_C_GetBeamAimDirection::CallFunc_Normal_ReturnValue' has a wrong offset!");
static_assert(offsetof(TASK_MobileLaser_Beam_LongRange_C_GetBeamAimDirection, CallFunc_ClampDirectionInCone_ClampedDirection) == 0x0000A0, "Member 'TASK_MobileLaser_Beam_LongRange_C_GetBeamAimDirection::CallFunc_ClampDirectionInCone_ClampedDirection' has a wrong offset!");
static_assert(offsetof(TASK_MobileLaser_Beam_LongRange_C_GetBeamAimDirection, CallFunc_GetBestAimTargetLocation_BestTargetLocation) == 0x0000AC, "Member 'TASK_MobileLaser_Beam_LongRange_C_GetBeamAimDirection::CallFunc_GetBestAimTargetLocation_BestTargetLocation' has a wrong offset!");

}

