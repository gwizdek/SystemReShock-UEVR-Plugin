#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: ANIMBP_Keypad

#include "Basic.hpp"

#include "Engine_structs.hpp"
#include "Engine_classes.hpp"
#include "AnimGraphRuntime_structs.hpp"


namespace SDK
{

// AnimBlueprintGeneratedClass ANIMBP_Keypad.AnimBP_Keypad_C
// 0x0100 (0x03C0 - 0x02C0)
class UAnimBP_Keypad_C final : public UAnimInstance
{
public:
	uint8                                         Pad_2B8[0x8];                                      // 0x02B8(0x0008)(Fixing Size After Last Property [ Dumper-7 ])
	struct FPointerToUberGraphFrame               UberGraphFrame;                                    // 0x02C0(0x0008)(ZeroConstructor, Transient, DuplicateTransient)
	struct FAnimNode_Root                         AnimGraphNode_Root;                                // 0x02C8(0x0030)()
	struct FAnimNode_SequencePlayer               AnimGraphNode_SequencePlayer;                      // 0x02F8(0x0080)()
	struct FAnimNode_Slot                         AnimGraphNode_Slot;                                // 0x0378(0x0048)()

public:
	void ExecuteUbergraph_AnimBP_Keypad(int32 EntryPoint);
	void AnimGraph(struct FPoseLink* AnimGraph_0);

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"AnimBP_Keypad_C">();
	}
	static class UAnimBP_Keypad_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<UAnimBP_Keypad_C>();
	}
};
static_assert(alignof(UAnimBP_Keypad_C) == 0x000010, "Wrong alignment on UAnimBP_Keypad_C");
static_assert(sizeof(UAnimBP_Keypad_C) == 0x0003C0, "Wrong size on UAnimBP_Keypad_C");
static_assert(offsetof(UAnimBP_Keypad_C, UberGraphFrame) == 0x0002C0, "Member 'UAnimBP_Keypad_C::UberGraphFrame' has a wrong offset!");
static_assert(offsetof(UAnimBP_Keypad_C, AnimGraphNode_Root) == 0x0002C8, "Member 'UAnimBP_Keypad_C::AnimGraphNode_Root' has a wrong offset!");
static_assert(offsetof(UAnimBP_Keypad_C, AnimGraphNode_SequencePlayer) == 0x0002F8, "Member 'UAnimBP_Keypad_C::AnimGraphNode_SequencePlayer' has a wrong offset!");
static_assert(offsetof(UAnimBP_Keypad_C, AnimGraphNode_Slot) == 0x000378, "Member 'UAnimBP_Keypad_C::AnimGraphNode_Slot' has a wrong offset!");

}

