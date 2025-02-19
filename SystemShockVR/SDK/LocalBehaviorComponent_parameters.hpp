#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: LocalBehaviorComponent

#include "Basic.hpp"

#include "StreamingSaveGameSystem_structs.hpp"


namespace SDK::Params
{

// Function LocalBehaviorComponent.LocalBehaviorComponent_C.HasValidBehavior
// 0x0008 (0x0008 - 0x0000)
struct LocalBehaviorComponent_C_HasValidBehavior final
{
public:
	bool                                          Result;                                            // 0x0000(0x0001)(Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor)
	bool                                          CallFunc_IsValidSoftObjectReference_ReturnValue;   // 0x0001(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	bool                                          CallFunc_NotEqual_ByteByte_ReturnValue;            // 0x0002(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	bool                                          CallFunc_BooleanOR_ReturnValue;                    // 0x0003(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	bool                                          CallFunc_Greater_FloatFloat_ReturnValue;           // 0x0004(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	bool                                          CallFunc_NotEqual_ByteByte_ReturnValue_1;          // 0x0005(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	bool                                          CallFunc_BooleanOR_ReturnValue_1;                  // 0x0006(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	bool                                          CallFunc_BooleanOR_ReturnValue_2;                  // 0x0007(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
};
static_assert(alignof(LocalBehaviorComponent_C_HasValidBehavior) == 0x000001, "Wrong alignment on LocalBehaviorComponent_C_HasValidBehavior");
static_assert(sizeof(LocalBehaviorComponent_C_HasValidBehavior) == 0x000008, "Wrong size on LocalBehaviorComponent_C_HasValidBehavior");
static_assert(offsetof(LocalBehaviorComponent_C_HasValidBehavior, Result) == 0x000000, "Member 'LocalBehaviorComponent_C_HasValidBehavior::Result' has a wrong offset!");
static_assert(offsetof(LocalBehaviorComponent_C_HasValidBehavior, CallFunc_IsValidSoftObjectReference_ReturnValue) == 0x000001, "Member 'LocalBehaviorComponent_C_HasValidBehavior::CallFunc_IsValidSoftObjectReference_ReturnValue' has a wrong offset!");
static_assert(offsetof(LocalBehaviorComponent_C_HasValidBehavior, CallFunc_NotEqual_ByteByte_ReturnValue) == 0x000002, "Member 'LocalBehaviorComponent_C_HasValidBehavior::CallFunc_NotEqual_ByteByte_ReturnValue' has a wrong offset!");
static_assert(offsetof(LocalBehaviorComponent_C_HasValidBehavior, CallFunc_BooleanOR_ReturnValue) == 0x000003, "Member 'LocalBehaviorComponent_C_HasValidBehavior::CallFunc_BooleanOR_ReturnValue' has a wrong offset!");
static_assert(offsetof(LocalBehaviorComponent_C_HasValidBehavior, CallFunc_Greater_FloatFloat_ReturnValue) == 0x000004, "Member 'LocalBehaviorComponent_C_HasValidBehavior::CallFunc_Greater_FloatFloat_ReturnValue' has a wrong offset!");
static_assert(offsetof(LocalBehaviorComponent_C_HasValidBehavior, CallFunc_NotEqual_ByteByte_ReturnValue_1) == 0x000005, "Member 'LocalBehaviorComponent_C_HasValidBehavior::CallFunc_NotEqual_ByteByte_ReturnValue_1' has a wrong offset!");
static_assert(offsetof(LocalBehaviorComponent_C_HasValidBehavior, CallFunc_BooleanOR_ReturnValue_1) == 0x000006, "Member 'LocalBehaviorComponent_C_HasValidBehavior::CallFunc_BooleanOR_ReturnValue_1' has a wrong offset!");
static_assert(offsetof(LocalBehaviorComponent_C_HasValidBehavior, CallFunc_BooleanOR_ReturnValue_2) == 0x000007, "Member 'LocalBehaviorComponent_C_HasValidBehavior::CallFunc_BooleanOR_ReturnValue_2' has a wrong offset!");

// Function LocalBehaviorComponent.LocalBehaviorComponent_C.HasFinishedWaiting
// 0x0010 (0x0010 - 0x0000)
struct LocalBehaviorComponent_C_HasFinishedWaiting final
{
public:
	bool                                          Result;                                            // 0x0000(0x0001)(Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor)
	bool                                          CallFunc_Greater_FloatFloat_ReturnValue;           // 0x0001(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_2[0x2];                                        // 0x0002(0x0002)(Fixing Size After Last Property [ Dumper-7 ])
	float                                         CallFunc_Add_FloatFloat_ReturnValue;               // 0x0004(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         CallFunc_GetPlayTimeInSeconds_ReturnValue;         // 0x0008(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          CallFunc_GreaterEqual_FloatFloat_ReturnValue;      // 0x000C(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
};
static_assert(alignof(LocalBehaviorComponent_C_HasFinishedWaiting) == 0x000004, "Wrong alignment on LocalBehaviorComponent_C_HasFinishedWaiting");
static_assert(sizeof(LocalBehaviorComponent_C_HasFinishedWaiting) == 0x000010, "Wrong size on LocalBehaviorComponent_C_HasFinishedWaiting");
static_assert(offsetof(LocalBehaviorComponent_C_HasFinishedWaiting, Result) == 0x000000, "Member 'LocalBehaviorComponent_C_HasFinishedWaiting::Result' has a wrong offset!");
static_assert(offsetof(LocalBehaviorComponent_C_HasFinishedWaiting, CallFunc_Greater_FloatFloat_ReturnValue) == 0x000001, "Member 'LocalBehaviorComponent_C_HasFinishedWaiting::CallFunc_Greater_FloatFloat_ReturnValue' has a wrong offset!");
static_assert(offsetof(LocalBehaviorComponent_C_HasFinishedWaiting, CallFunc_Add_FloatFloat_ReturnValue) == 0x000004, "Member 'LocalBehaviorComponent_C_HasFinishedWaiting::CallFunc_Add_FloatFloat_ReturnValue' has a wrong offset!");
static_assert(offsetof(LocalBehaviorComponent_C_HasFinishedWaiting, CallFunc_GetPlayTimeInSeconds_ReturnValue) == 0x000008, "Member 'LocalBehaviorComponent_C_HasFinishedWaiting::CallFunc_GetPlayTimeInSeconds_ReturnValue' has a wrong offset!");
static_assert(offsetof(LocalBehaviorComponent_C_HasFinishedWaiting, CallFunc_GreaterEqual_FloatFloat_ReturnValue) == 0x00000C, "Member 'LocalBehaviorComponent_C_HasFinishedWaiting::CallFunc_GreaterEqual_FloatFloat_ReturnValue' has a wrong offset!");

// Function LocalBehaviorComponent.LocalBehaviorComponent_C.UpdateArrivedTimestamp
// 0x0008 (0x0008 - 0x0000)
struct LocalBehaviorComponent_C_UpdateArrivedTimestamp final
{
public:
	bool                                          Reset;                                             // 0x0000(0x0001)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_1[0x3];                                        // 0x0001(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	float                                         CallFunc_GetPlayTimeInSeconds_ReturnValue;         // 0x0004(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
};
static_assert(alignof(LocalBehaviorComponent_C_UpdateArrivedTimestamp) == 0x000004, "Wrong alignment on LocalBehaviorComponent_C_UpdateArrivedTimestamp");
static_assert(sizeof(LocalBehaviorComponent_C_UpdateArrivedTimestamp) == 0x000008, "Wrong size on LocalBehaviorComponent_C_UpdateArrivedTimestamp");
static_assert(offsetof(LocalBehaviorComponent_C_UpdateArrivedTimestamp, Reset) == 0x000000, "Member 'LocalBehaviorComponent_C_UpdateArrivedTimestamp::Reset' has a wrong offset!");
static_assert(offsetof(LocalBehaviorComponent_C_UpdateArrivedTimestamp, CallFunc_GetPlayTimeInSeconds_ReturnValue) == 0x000004, "Member 'LocalBehaviorComponent_C_UpdateArrivedTimestamp::CallFunc_GetPlayTimeInSeconds_ReturnValue' has a wrong offset!");

// Function LocalBehaviorComponent.LocalBehaviorComponent_C.ShouldSaveComponent
// 0x0010 (0x0010 - 0x0000)
struct LocalBehaviorComponent_C_ShouldSaveComponent final
{
public:
	struct FStreamingSaveGameComponentParams      Params_0;                                          // 0x0000(0x0004)(Parm, OutParm, NoDestructor)
	bool                                          ReturnValue;                                       // 0x0004(0x0001)(Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData, NoDestructor)
	uint8                                         Pad_5[0x3];                                        // 0x0005(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	struct FStreamingSaveGameComponentParams      K2Node_MakeStruct_StreamingSaveGameComponentParams; // 0x0008(0x0004)(NoDestructor)
	bool                                          CallFunc_Greater_FloatFloat_ReturnValue;           // 0x000C(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
};
static_assert(alignof(LocalBehaviorComponent_C_ShouldSaveComponent) == 0x000004, "Wrong alignment on LocalBehaviorComponent_C_ShouldSaveComponent");
static_assert(sizeof(LocalBehaviorComponent_C_ShouldSaveComponent) == 0x000010, "Wrong size on LocalBehaviorComponent_C_ShouldSaveComponent");
static_assert(offsetof(LocalBehaviorComponent_C_ShouldSaveComponent, Params_0) == 0x000000, "Member 'LocalBehaviorComponent_C_ShouldSaveComponent::Params_0' has a wrong offset!");
static_assert(offsetof(LocalBehaviorComponent_C_ShouldSaveComponent, ReturnValue) == 0x000004, "Member 'LocalBehaviorComponent_C_ShouldSaveComponent::ReturnValue' has a wrong offset!");
static_assert(offsetof(LocalBehaviorComponent_C_ShouldSaveComponent, K2Node_MakeStruct_StreamingSaveGameComponentParams) == 0x000008, "Member 'LocalBehaviorComponent_C_ShouldSaveComponent::K2Node_MakeStruct_StreamingSaveGameComponentParams' has a wrong offset!");
static_assert(offsetof(LocalBehaviorComponent_C_ShouldSaveComponent, CallFunc_Greater_FloatFloat_ReturnValue) == 0x00000C, "Member 'LocalBehaviorComponent_C_ShouldSaveComponent::CallFunc_Greater_FloatFloat_ReturnValue' has a wrong offset!");

}

