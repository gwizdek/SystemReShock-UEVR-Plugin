#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: MOVECONTROL_MenuMove

#include "Basic.hpp"

#include "STRUCT_MoveControlParams_structs.hpp"
#include "CoreUObject_structs.hpp"


namespace SDK::Params
{

// Function MOVECONTROL_MenuMove.MOVECONTROL_MenuMove_C.UpdateMoveControl
// 0x0058 (0x0058 - 0x0000)
struct MOVECONTROL_MenuMove_C_UpdateMoveControl final
{
public:
	struct FVector2D                              MoveInput;                                         // 0x0000(0x0008)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FVector2D                              LookInput;                                         // 0x0008(0x0008)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FSTRUCT_MoveControlParams              ControlParams;                                     // 0x0010(0x0028)(BlueprintVisible, BlueprintReadOnly, Parm, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	TArray<float>                                 ActionInputValues;                                 // 0x0038(0x0010)(BlueprintVisible, BlueprintReadOnly, Parm, OutParm, ReferenceParm)
	float                                         MoveInputScale;                                    // 0x0048(0x0004)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         Delta_Time;                                        // 0x004C(0x0004)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          ShouldExpire;                                      // 0x0050(0x0001)(Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor)
};
static_assert(alignof(MOVECONTROL_MenuMove_C_UpdateMoveControl) == 0x000008, "Wrong alignment on MOVECONTROL_MenuMove_C_UpdateMoveControl");
static_assert(sizeof(MOVECONTROL_MenuMove_C_UpdateMoveControl) == 0x000058, "Wrong size on MOVECONTROL_MenuMove_C_UpdateMoveControl");
static_assert(offsetof(MOVECONTROL_MenuMove_C_UpdateMoveControl, MoveInput) == 0x000000, "Member 'MOVECONTROL_MenuMove_C_UpdateMoveControl::MoveInput' has a wrong offset!");
static_assert(offsetof(MOVECONTROL_MenuMove_C_UpdateMoveControl, LookInput) == 0x000008, "Member 'MOVECONTROL_MenuMove_C_UpdateMoveControl::LookInput' has a wrong offset!");
static_assert(offsetof(MOVECONTROL_MenuMove_C_UpdateMoveControl, ControlParams) == 0x000010, "Member 'MOVECONTROL_MenuMove_C_UpdateMoveControl::ControlParams' has a wrong offset!");
static_assert(offsetof(MOVECONTROL_MenuMove_C_UpdateMoveControl, ActionInputValues) == 0x000038, "Member 'MOVECONTROL_MenuMove_C_UpdateMoveControl::ActionInputValues' has a wrong offset!");
static_assert(offsetof(MOVECONTROL_MenuMove_C_UpdateMoveControl, MoveInputScale) == 0x000048, "Member 'MOVECONTROL_MenuMove_C_UpdateMoveControl::MoveInputScale' has a wrong offset!");
static_assert(offsetof(MOVECONTROL_MenuMove_C_UpdateMoveControl, Delta_Time) == 0x00004C, "Member 'MOVECONTROL_MenuMove_C_UpdateMoveControl::Delta_Time' has a wrong offset!");
static_assert(offsetof(MOVECONTROL_MenuMove_C_UpdateMoveControl, ShouldExpire) == 0x000050, "Member 'MOVECONTROL_MenuMove_C_UpdateMoveControl::ShouldExpire' has a wrong offset!");

// Function MOVECONTROL_MenuMove.MOVECONTROL_MenuMove_C.InitializeMoveControl
// 0x0038 (0x0038 - 0x0000)
struct MOVECONTROL_MenuMove_C_InitializeMoveControl final
{
public:
	class APAWN_Hacker_Simple_C*                  Player_0;                                          // 0x0000(0x0008)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         GameTime;                                          // 0x0008(0x0004)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FSTRUCT_MoveControlParams              InitialControlParams;                              // 0x000C(0x0028)(BlueprintVisible, BlueprintReadOnly, Parm, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          Result;                                            // 0x0034(0x0001)(Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor)
	bool                                          CallFunc_InitializeMoveControl_Result;             // 0x0035(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
};
static_assert(alignof(MOVECONTROL_MenuMove_C_InitializeMoveControl) == 0x000008, "Wrong alignment on MOVECONTROL_MenuMove_C_InitializeMoveControl");
static_assert(sizeof(MOVECONTROL_MenuMove_C_InitializeMoveControl) == 0x000038, "Wrong size on MOVECONTROL_MenuMove_C_InitializeMoveControl");
static_assert(offsetof(MOVECONTROL_MenuMove_C_InitializeMoveControl, Player_0) == 0x000000, "Member 'MOVECONTROL_MenuMove_C_InitializeMoveControl::Player_0' has a wrong offset!");
static_assert(offsetof(MOVECONTROL_MenuMove_C_InitializeMoveControl, GameTime) == 0x000008, "Member 'MOVECONTROL_MenuMove_C_InitializeMoveControl::GameTime' has a wrong offset!");
static_assert(offsetof(MOVECONTROL_MenuMove_C_InitializeMoveControl, InitialControlParams) == 0x00000C, "Member 'MOVECONTROL_MenuMove_C_InitializeMoveControl::InitialControlParams' has a wrong offset!");
static_assert(offsetof(MOVECONTROL_MenuMove_C_InitializeMoveControl, Result) == 0x000034, "Member 'MOVECONTROL_MenuMove_C_InitializeMoveControl::Result' has a wrong offset!");
static_assert(offsetof(MOVECONTROL_MenuMove_C_InitializeMoveControl, CallFunc_InitializeMoveControl_Result) == 0x000035, "Member 'MOVECONTROL_MenuMove_C_InitializeMoveControl::CallFunc_InitializeMoveControl_Result' has a wrong offset!");

}

