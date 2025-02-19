#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: INTERF_ANIM_Door

#include "Basic.hpp"


namespace SDK::Params
{

// Function INTERF_ANIM_Door.INTERF_ANIM_Door_C.OpenDoor
// 0x0001 (0x0001 - 0x0000)
struct INTERF_ANIM_Door_C_OpenDoor final
{
public:
	bool                                          Result;                                            // 0x0000(0x0001)(Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor)
};
static_assert(alignof(INTERF_ANIM_Door_C_OpenDoor) == 0x000001, "Wrong alignment on INTERF_ANIM_Door_C_OpenDoor");
static_assert(sizeof(INTERF_ANIM_Door_C_OpenDoor) == 0x000001, "Wrong size on INTERF_ANIM_Door_C_OpenDoor");
static_assert(offsetof(INTERF_ANIM_Door_C_OpenDoor, Result) == 0x000000, "Member 'INTERF_ANIM_Door_C_OpenDoor::Result' has a wrong offset!");

// Function INTERF_ANIM_Door.INTERF_ANIM_Door_C.CloseDoor
// 0x0001 (0x0001 - 0x0000)
struct INTERF_ANIM_Door_C_CloseDoor final
{
public:
	bool                                          Result;                                            // 0x0000(0x0001)(Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor)
};
static_assert(alignof(INTERF_ANIM_Door_C_CloseDoor) == 0x000001, "Wrong alignment on INTERF_ANIM_Door_C_CloseDoor");
static_assert(sizeof(INTERF_ANIM_Door_C_CloseDoor) == 0x000001, "Wrong size on INTERF_ANIM_Door_C_CloseDoor");
static_assert(offsetof(INTERF_ANIM_Door_C_CloseDoor, Result) == 0x000000, "Member 'INTERF_ANIM_Door_C_CloseDoor::Result' has a wrong offset!");

// Function INTERF_ANIM_Door.INTERF_ANIM_Door_C.IsLocked
// 0x0001 (0x0001 - 0x0000)
struct INTERF_ANIM_Door_C_IsLocked final
{
public:
	bool                                          Result;                                            // 0x0000(0x0001)(Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor)
};
static_assert(alignof(INTERF_ANIM_Door_C_IsLocked) == 0x000001, "Wrong alignment on INTERF_ANIM_Door_C_IsLocked");
static_assert(sizeof(INTERF_ANIM_Door_C_IsLocked) == 0x000001, "Wrong size on INTERF_ANIM_Door_C_IsLocked");
static_assert(offsetof(INTERF_ANIM_Door_C_IsLocked, Result) == 0x000000, "Member 'INTERF_ANIM_Door_C_IsLocked::Result' has a wrong offset!");

// Function INTERF_ANIM_Door.INTERF_ANIM_Door_C.SetLocked
// 0x0002 (0x0002 - 0x0000)
struct INTERF_ANIM_Door_C_SetLocked final
{
public:
	bool                                          LockedState;                                       // 0x0000(0x0001)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor)
	bool                                          Result;                                            // 0x0001(0x0001)(Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor)
};
static_assert(alignof(INTERF_ANIM_Door_C_SetLocked) == 0x000001, "Wrong alignment on INTERF_ANIM_Door_C_SetLocked");
static_assert(sizeof(INTERF_ANIM_Door_C_SetLocked) == 0x000002, "Wrong size on INTERF_ANIM_Door_C_SetLocked");
static_assert(offsetof(INTERF_ANIM_Door_C_SetLocked, LockedState) == 0x000000, "Member 'INTERF_ANIM_Door_C_SetLocked::LockedState' has a wrong offset!");
static_assert(offsetof(INTERF_ANIM_Door_C_SetLocked, Result) == 0x000001, "Member 'INTERF_ANIM_Door_C_SetLocked::Result' has a wrong offset!");

// Function INTERF_ANIM_Door.INTERF_ANIM_Door_C.HideFrontButton
// 0x0002 (0x0002 - 0x0000)
struct INTERF_ANIM_Door_C_HideFrontButton final
{
public:
	bool                                          HideState;                                         // 0x0000(0x0001)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor)
	bool                                          Result;                                            // 0x0001(0x0001)(Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor)
};
static_assert(alignof(INTERF_ANIM_Door_C_HideFrontButton) == 0x000001, "Wrong alignment on INTERF_ANIM_Door_C_HideFrontButton");
static_assert(sizeof(INTERF_ANIM_Door_C_HideFrontButton) == 0x000002, "Wrong size on INTERF_ANIM_Door_C_HideFrontButton");
static_assert(offsetof(INTERF_ANIM_Door_C_HideFrontButton, HideState) == 0x000000, "Member 'INTERF_ANIM_Door_C_HideFrontButton::HideState' has a wrong offset!");
static_assert(offsetof(INTERF_ANIM_Door_C_HideFrontButton, Result) == 0x000001, "Member 'INTERF_ANIM_Door_C_HideFrontButton::Result' has a wrong offset!");

// Function INTERF_ANIM_Door.INTERF_ANIM_Door_C.HideBackButton
// 0x0002 (0x0002 - 0x0000)
struct INTERF_ANIM_Door_C_HideBackButton final
{
public:
	bool                                          HideState;                                         // 0x0000(0x0001)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor)
	bool                                          Result;                                            // 0x0001(0x0001)(Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor)
};
static_assert(alignof(INTERF_ANIM_Door_C_HideBackButton) == 0x000001, "Wrong alignment on INTERF_ANIM_Door_C_HideBackButton");
static_assert(sizeof(INTERF_ANIM_Door_C_HideBackButton) == 0x000002, "Wrong size on INTERF_ANIM_Door_C_HideBackButton");
static_assert(offsetof(INTERF_ANIM_Door_C_HideBackButton, HideState) == 0x000000, "Member 'INTERF_ANIM_Door_C_HideBackButton::HideState' has a wrong offset!");
static_assert(offsetof(INTERF_ANIM_Door_C_HideBackButton, Result) == 0x000001, "Member 'INTERF_ANIM_Door_C_HideBackButton::Result' has a wrong offset!");

// Function INTERF_ANIM_Door.INTERF_ANIM_Door_C.UnlockDoor
// 0x0001 (0x0001 - 0x0000)
struct INTERF_ANIM_Door_C_UnlockDoor final
{
public:
	bool                                          Result;                                            // 0x0000(0x0001)(Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor)
};
static_assert(alignof(INTERF_ANIM_Door_C_UnlockDoor) == 0x000001, "Wrong alignment on INTERF_ANIM_Door_C_UnlockDoor");
static_assert(sizeof(INTERF_ANIM_Door_C_UnlockDoor) == 0x000001, "Wrong size on INTERF_ANIM_Door_C_UnlockDoor");
static_assert(offsetof(INTERF_ANIM_Door_C_UnlockDoor, Result) == 0x000000, "Member 'INTERF_ANIM_Door_C_UnlockDoor::Result' has a wrong offset!");

}

