#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: INTERACT_Focusable_Base

#include "Basic.hpp"

#include "INTERACT_Channeling_Base_classes.hpp"
#include "ENUM_InteractionType_structs.hpp"


namespace SDK
{

// BlueprintGeneratedClass INTERACT_Focusable_Base.INTERACT_Focusable_Base_C
// 0x0038 (0x0388 - 0x0350)
class AINTERACT_Focusable_Base_C : public AINTERACT_Channeling_Base_C
{
public:
	class UMOVECONTROL_FocusableInteract_C*       FocusableMoveControl;                              // 0x0350(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class FText                                   CantFocusWhileFallingMessage;                      // 0x0358(0x0018)(Edit, BlueprintVisible, DisableEditOnInstance)
	class FText                                   CantFocusFromLocationMessage;                      // 0x0370(0x0018)(Edit, BlueprintVisible, DisableEditOnInstance)

public:
	void ShouldFocusOnInteract(class AController* Controller, bool* Result);
	void GetFocusWorldTransform(struct FTransform* Transform);
	void BeginFocusSequence(class APAWN_Hacker_Simple_C* HackerPawn);
	void TryBeginFocusInteraction(class APAWN_Hacker_Simple_C* HackerPawn, class UPrimitiveComponent* CursorPrimitive, bool* Result);
	void TryFinishFocusInteraction(class APAWN_Hacker_Simple_C* HackerPawn);
	void ResumeChannelingInteraction(class APAWN_Hacker_Simple_C* HackerPawn);
	void CycleFocusedPrimitiveComponent(class UPrimitiveComponent* CursorPrimitive, bool Vertical, bool Previous);
	void FocusOnPrimitiveComponent(class UPrimitiveComponent* PrimitiveComponent);
	void StopFocusingInternal(class APAWN_Hacker_Simple_C* HackerPawn);
	void OnFinishedFocusing();
	void StopChanneling(class AActor* NewChannelingInteract, bool* Result);
	void TryInteract(class AActor* SourceActor, class UPrimitiveComponent* CursorPrimitive, ENUM_InteractionType InteractionType, struct FSTRUCT_InteractResults* InteractResults);

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"INTERACT_Focusable_Base_C">();
	}
	static class AINTERACT_Focusable_Base_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<AINTERACT_Focusable_Base_C>();
	}
};
static_assert(alignof(AINTERACT_Focusable_Base_C) == 0x000008, "Wrong alignment on AINTERACT_Focusable_Base_C");
static_assert(sizeof(AINTERACT_Focusable_Base_C) == 0x000388, "Wrong size on AINTERACT_Focusable_Base_C");
static_assert(offsetof(AINTERACT_Focusable_Base_C, FocusableMoveControl) == 0x000350, "Member 'AINTERACT_Focusable_Base_C::FocusableMoveControl' has a wrong offset!");
static_assert(offsetof(AINTERACT_Focusable_Base_C, CantFocusWhileFallingMessage) == 0x000358, "Member 'AINTERACT_Focusable_Base_C::CantFocusWhileFallingMessage' has a wrong offset!");
static_assert(offsetof(AINTERACT_Focusable_Base_C, CantFocusFromLocationMessage) == 0x000370, "Member 'AINTERACT_Focusable_Base_C::CantFocusFromLocationMessage' has a wrong offset!");

}

