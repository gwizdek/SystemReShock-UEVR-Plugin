#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: INTERF_Interactable

#include "Basic.hpp"

#include "CoreUObject_classes.hpp"
#include "ENUM_InteractionType_structs.hpp"


namespace SDK
{

// BlueprintGeneratedClass INTERF_Interactable.INTERF_Interactable_C
// 0x0000 (0x0028 - 0x0028)
class IINTERF_Interactable_C final : public IInterface
{
public:
	void TryInteract(class AActor* SourceActor, class UPrimitiveComponent* CursorPrimitive, ENUM_InteractionType InteractionType, struct FSTRUCT_InteractResults* InteractResults);
	void TryReceiveItem(class UITEM_Base_C* Item, bool* Result);
	void TryDetachInteract(bool SimulatePhysics, bool* Result);
	void OnCursorEnter(class UPrimitiveComponent* Cursor_Primitive);
	void OnCursorLeave(class UPrimitiveComponent* Cursor_Primitive);
	void GetTargetShape(class UPrimitiveComponent* CursorPrimitive, class UShapeComponent** ShapeComponent);
	void StopChanneling(class AActor* NewChannelingInteract, bool* Result);
	void SetInteractLocked(bool Locked, bool* Result);
	void SetInteractPowered(bool State, bool* Result);
	void GetInteractBusy(bool* Result, class FText* BusyMessage);
	void GetInteractLocked(class AActor* SourceActor, bool* Result, class FText* LockMessage);
	void GetInteractBroken(bool* Result, class FText* BrokenMessage);
	void GetInteractDestroyed(bool* Result);
	void CanInteractBeDestroyed(bool* Result);
	void CanModifyInteractPower(bool* Result);
	void IsInteractActivated(bool* Result);
	void IsHiddenInteractablePrimitive(class APAWN_SystemShockCharacter_C* Character, class UPrimitiveComponent* CursorPrimitive, bool* Result);
	void ShouldIgnoreInteractRange(bool* Result);
	void CanReceiveItem(class UITEM_Base_C* Item, bool* Result);
	void GetChannelingHoldDuration(float* Result);
	void FinishedChannelingHoldInteraction(class APAWN_SystemShockCharacter_C* Character, bool* Result);

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"INTERF_Interactable_C">();
	}
	static class IINTERF_Interactable_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<IINTERF_Interactable_C>();
	}
};
static_assert(alignof(IINTERF_Interactable_C) == 0x000008, "Wrong alignment on IINTERF_Interactable_C");
static_assert(sizeof(IINTERF_Interactable_C) == 0x000028, "Wrong size on IINTERF_Interactable_C");

}

