#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: PointOfInterestComponent

#include "Basic.hpp"

#include "StreamingSaveGameSystem_structs.hpp"
#include "STRUCT_LocalBehaviorAnimations_structs.hpp"


namespace SDK::Params
{

// Function PointOfInterestComponent.PointOfInterestComponent_C.ExecuteUbergraph_PointOfInterestComponent
// 0x0020 (0x0020 - 0x0000)
struct PointOfInterestComponent_C_ExecuteUbergraph_PointOfInterestComponent final
{
public:
	int32                                         EntryPoint;                                        // 0x0000(0x0004)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_4[0x4];                                        // 0x0004(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	class UGameInstance*                          CallFunc_GetGameInstance_ReturnValue;              // 0x0008(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UGI_SinglePlayer_C*                     K2Node_DynamicCast_AsGI_Single_Player;             // 0x0010(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          K2Node_DynamicCast_bSuccess;                       // 0x0018(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	bool                                          CallFunc_IsValid_ReturnValue;                      // 0x0019(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
};
static_assert(alignof(PointOfInterestComponent_C_ExecuteUbergraph_PointOfInterestComponent) == 0x000008, "Wrong alignment on PointOfInterestComponent_C_ExecuteUbergraph_PointOfInterestComponent");
static_assert(sizeof(PointOfInterestComponent_C_ExecuteUbergraph_PointOfInterestComponent) == 0x000020, "Wrong size on PointOfInterestComponent_C_ExecuteUbergraph_PointOfInterestComponent");
static_assert(offsetof(PointOfInterestComponent_C_ExecuteUbergraph_PointOfInterestComponent, EntryPoint) == 0x000000, "Member 'PointOfInterestComponent_C_ExecuteUbergraph_PointOfInterestComponent::EntryPoint' has a wrong offset!");
static_assert(offsetof(PointOfInterestComponent_C_ExecuteUbergraph_PointOfInterestComponent, CallFunc_GetGameInstance_ReturnValue) == 0x000008, "Member 'PointOfInterestComponent_C_ExecuteUbergraph_PointOfInterestComponent::CallFunc_GetGameInstance_ReturnValue' has a wrong offset!");
static_assert(offsetof(PointOfInterestComponent_C_ExecuteUbergraph_PointOfInterestComponent, K2Node_DynamicCast_AsGI_Single_Player) == 0x000010, "Member 'PointOfInterestComponent_C_ExecuteUbergraph_PointOfInterestComponent::K2Node_DynamicCast_AsGI_Single_Player' has a wrong offset!");
static_assert(offsetof(PointOfInterestComponent_C_ExecuteUbergraph_PointOfInterestComponent, K2Node_DynamicCast_bSuccess) == 0x000018, "Member 'PointOfInterestComponent_C_ExecuteUbergraph_PointOfInterestComponent::K2Node_DynamicCast_bSuccess' has a wrong offset!");
static_assert(offsetof(PointOfInterestComponent_C_ExecuteUbergraph_PointOfInterestComponent, CallFunc_IsValid_ReturnValue) == 0x000019, "Member 'PointOfInterestComponent_C_ExecuteUbergraph_PointOfInterestComponent::CallFunc_IsValid_ReturnValue' has a wrong offset!");

// Function PointOfInterestComponent.PointOfInterestComponent_C.IsCooldownFinished
// 0x0010 (0x0010 - 0x0000)
struct PointOfInterestComponent_C_IsCooldownFinished final
{
public:
	bool                                          Result;                                            // 0x0000(0x0001)(Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_1[0x3];                                        // 0x0001(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	float                                         CallFunc_GetPlayTimeInSeconds_ReturnValue;         // 0x0004(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         CallFunc_Add_FloatFloat_ReturnValue;               // 0x0008(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          CallFunc_GreaterEqual_FloatFloat_ReturnValue;      // 0x000C(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	bool                                          CallFunc_Greater_FloatFloat_ReturnValue;           // 0x000D(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
};
static_assert(alignof(PointOfInterestComponent_C_IsCooldownFinished) == 0x000004, "Wrong alignment on PointOfInterestComponent_C_IsCooldownFinished");
static_assert(sizeof(PointOfInterestComponent_C_IsCooldownFinished) == 0x000010, "Wrong size on PointOfInterestComponent_C_IsCooldownFinished");
static_assert(offsetof(PointOfInterestComponent_C_IsCooldownFinished, Result) == 0x000000, "Member 'PointOfInterestComponent_C_IsCooldownFinished::Result' has a wrong offset!");
static_assert(offsetof(PointOfInterestComponent_C_IsCooldownFinished, CallFunc_GetPlayTimeInSeconds_ReturnValue) == 0x000004, "Member 'PointOfInterestComponent_C_IsCooldownFinished::CallFunc_GetPlayTimeInSeconds_ReturnValue' has a wrong offset!");
static_assert(offsetof(PointOfInterestComponent_C_IsCooldownFinished, CallFunc_Add_FloatFloat_ReturnValue) == 0x000008, "Member 'PointOfInterestComponent_C_IsCooldownFinished::CallFunc_Add_FloatFloat_ReturnValue' has a wrong offset!");
static_assert(offsetof(PointOfInterestComponent_C_IsCooldownFinished, CallFunc_GreaterEqual_FloatFloat_ReturnValue) == 0x00000C, "Member 'PointOfInterestComponent_C_IsCooldownFinished::CallFunc_GreaterEqual_FloatFloat_ReturnValue' has a wrong offset!");
static_assert(offsetof(PointOfInterestComponent_C_IsCooldownFinished, CallFunc_Greater_FloatFloat_ReturnValue) == 0x00000D, "Member 'PointOfInterestComponent_C_IsCooldownFinished::CallFunc_Greater_FloatFloat_ReturnValue' has a wrong offset!");

// Function PointOfInterestComponent.PointOfInterestComponent_C.GetPointOfInterestWeight
// 0x0004 (0x0004 - 0x0000)
struct PointOfInterestComponent_C_GetPointOfInterestWeight final
{
public:
	float                                         Weight;                                            // 0x0000(0x0004)(Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
};
static_assert(alignof(PointOfInterestComponent_C_GetPointOfInterestWeight) == 0x000004, "Wrong alignment on PointOfInterestComponent_C_GetPointOfInterestWeight");
static_assert(sizeof(PointOfInterestComponent_C_GetPointOfInterestWeight) == 0x000004, "Wrong size on PointOfInterestComponent_C_GetPointOfInterestWeight");
static_assert(offsetof(PointOfInterestComponent_C_GetPointOfInterestWeight, Weight) == 0x000000, "Member 'PointOfInterestComponent_C_GetPointOfInterestWeight::Weight' has a wrong offset!");

// Function PointOfInterestComponent.PointOfInterestComponent_C.CanEnemyUsePointOfInterest
// 0x00B0 (0x00B0 - 0x0000)
struct PointOfInterestComponent_C_CanEnemyUsePointOfInterest final
{
public:
	class APAWN_Enemy_C*                          Enemy;                                             // 0x0000(0x0008)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          Result;                                            // 0x0008(0x0001)(Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor)
	bool                                          CallFunc_IsCooldownFinished_Result;                // 0x0009(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	bool                                          CallFunc_GetLocalBehaviorAnimationDataByType_Found; // 0x000A(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_B[0x5];                                        // 0x000B(0x0005)(Fixing Size After Last Property [ Dumper-7 ])
	struct FSTRUCT_LocalBehaviorAnimations        CallFunc_GetLocalBehaviorAnimationDataByType_Result; // 0x0010(0x00A0)(HasGetValueTypeHash)
};
static_assert(alignof(PointOfInterestComponent_C_CanEnemyUsePointOfInterest) == 0x000008, "Wrong alignment on PointOfInterestComponent_C_CanEnemyUsePointOfInterest");
static_assert(sizeof(PointOfInterestComponent_C_CanEnemyUsePointOfInterest) == 0x0000B0, "Wrong size on PointOfInterestComponent_C_CanEnemyUsePointOfInterest");
static_assert(offsetof(PointOfInterestComponent_C_CanEnemyUsePointOfInterest, Enemy) == 0x000000, "Member 'PointOfInterestComponent_C_CanEnemyUsePointOfInterest::Enemy' has a wrong offset!");
static_assert(offsetof(PointOfInterestComponent_C_CanEnemyUsePointOfInterest, Result) == 0x000008, "Member 'PointOfInterestComponent_C_CanEnemyUsePointOfInterest::Result' has a wrong offset!");
static_assert(offsetof(PointOfInterestComponent_C_CanEnemyUsePointOfInterest, CallFunc_IsCooldownFinished_Result) == 0x000009, "Member 'PointOfInterestComponent_C_CanEnemyUsePointOfInterest::CallFunc_IsCooldownFinished_Result' has a wrong offset!");
static_assert(offsetof(PointOfInterestComponent_C_CanEnemyUsePointOfInterest, CallFunc_GetLocalBehaviorAnimationDataByType_Found) == 0x00000A, "Member 'PointOfInterestComponent_C_CanEnemyUsePointOfInterest::CallFunc_GetLocalBehaviorAnimationDataByType_Found' has a wrong offset!");
static_assert(offsetof(PointOfInterestComponent_C_CanEnemyUsePointOfInterest, CallFunc_GetLocalBehaviorAnimationDataByType_Result) == 0x000010, "Member 'PointOfInterestComponent_C_CanEnemyUsePointOfInterest::CallFunc_GetLocalBehaviorAnimationDataByType_Result' has a wrong offset!");

// Function PointOfInterestComponent.PointOfInterestComponent_C.ShouldSaveComponent
// 0x0014 (0x0014 - 0x0000)
struct PointOfInterestComponent_C_ShouldSaveComponent final
{
public:
	struct FStreamingSaveGameComponentParams      Params_0;                                          // 0x0000(0x0004)(Parm, OutParm, NoDestructor)
	bool                                          ReturnValue;                                       // 0x0004(0x0001)(Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData, NoDestructor)
	uint8                                         Pad_5[0x3];                                        // 0x0005(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	struct FStreamingSaveGameComponentParams      K2Node_MakeStruct_StreamingSaveGameComponentParams; // 0x0008(0x0004)(NoDestructor)
	struct FStreamingSaveGameComponentParams      CallFunc_ShouldSaveComponent_Params;               // 0x000C(0x0004)(NoDestructor)
	bool                                          CallFunc_ShouldSaveComponent_ReturnValue;          // 0x0010(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	bool                                          CallFunc_Greater_FloatFloat_ReturnValue;           // 0x0011(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	bool                                          CallFunc_BooleanOR_ReturnValue;                    // 0x0012(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
};
static_assert(alignof(PointOfInterestComponent_C_ShouldSaveComponent) == 0x000004, "Wrong alignment on PointOfInterestComponent_C_ShouldSaveComponent");
static_assert(sizeof(PointOfInterestComponent_C_ShouldSaveComponent) == 0x000014, "Wrong size on PointOfInterestComponent_C_ShouldSaveComponent");
static_assert(offsetof(PointOfInterestComponent_C_ShouldSaveComponent, Params_0) == 0x000000, "Member 'PointOfInterestComponent_C_ShouldSaveComponent::Params_0' has a wrong offset!");
static_assert(offsetof(PointOfInterestComponent_C_ShouldSaveComponent, ReturnValue) == 0x000004, "Member 'PointOfInterestComponent_C_ShouldSaveComponent::ReturnValue' has a wrong offset!");
static_assert(offsetof(PointOfInterestComponent_C_ShouldSaveComponent, K2Node_MakeStruct_StreamingSaveGameComponentParams) == 0x000008, "Member 'PointOfInterestComponent_C_ShouldSaveComponent::K2Node_MakeStruct_StreamingSaveGameComponentParams' has a wrong offset!");
static_assert(offsetof(PointOfInterestComponent_C_ShouldSaveComponent, CallFunc_ShouldSaveComponent_Params) == 0x00000C, "Member 'PointOfInterestComponent_C_ShouldSaveComponent::CallFunc_ShouldSaveComponent_Params' has a wrong offset!");
static_assert(offsetof(PointOfInterestComponent_C_ShouldSaveComponent, CallFunc_ShouldSaveComponent_ReturnValue) == 0x000010, "Member 'PointOfInterestComponent_C_ShouldSaveComponent::CallFunc_ShouldSaveComponent_ReturnValue' has a wrong offset!");
static_assert(offsetof(PointOfInterestComponent_C_ShouldSaveComponent, CallFunc_Greater_FloatFloat_ReturnValue) == 0x000011, "Member 'PointOfInterestComponent_C_ShouldSaveComponent::CallFunc_Greater_FloatFloat_ReturnValue' has a wrong offset!");
static_assert(offsetof(PointOfInterestComponent_C_ShouldSaveComponent, CallFunc_BooleanOR_ReturnValue) == 0x000012, "Member 'PointOfInterestComponent_C_ShouldSaveComponent::CallFunc_BooleanOR_ReturnValue' has a wrong offset!");

// Function PointOfInterestComponent.PointOfInterestComponent_C.UpdateArrivedTimestamp
// 0x0008 (0x0008 - 0x0000)
struct PointOfInterestComponent_C_UpdateArrivedTimestamp final
{
public:
	bool                                          Reset;                                             // 0x0000(0x0001)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_1[0x3];                                        // 0x0001(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	float                                         CallFunc_GetPlayTimeInSeconds_ReturnValue;         // 0x0004(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
};
static_assert(alignof(PointOfInterestComponent_C_UpdateArrivedTimestamp) == 0x000004, "Wrong alignment on PointOfInterestComponent_C_UpdateArrivedTimestamp");
static_assert(sizeof(PointOfInterestComponent_C_UpdateArrivedTimestamp) == 0x000008, "Wrong size on PointOfInterestComponent_C_UpdateArrivedTimestamp");
static_assert(offsetof(PointOfInterestComponent_C_UpdateArrivedTimestamp, Reset) == 0x000000, "Member 'PointOfInterestComponent_C_UpdateArrivedTimestamp::Reset' has a wrong offset!");
static_assert(offsetof(PointOfInterestComponent_C_UpdateArrivedTimestamp, CallFunc_GetPlayTimeInSeconds_ReturnValue) == 0x000004, "Member 'PointOfInterestComponent_C_UpdateArrivedTimestamp::CallFunc_GetPlayTimeInSeconds_ReturnValue' has a wrong offset!");

}

