#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: ITEM_HandheldDevice_Base

#include "Basic.hpp"

#include "Engine_structs.hpp"
#include "ITEM_HandheldConsumable_Base_classes.hpp"


namespace SDK
{

// BlueprintGeneratedClass ITEM_HandheldDevice_Base.ITEM_HandheldDevice_Base_C
// 0x0040 (0x0410 - 0x03D0)
class UITEM_HandheldDevice_Base_C : public UITEM_HandheldConsumable_Base_C
{
public:
	struct FPointerToUberGraphFrame               UberGraphFrame_ITEM_HandheldDevice_Base_C;         // 0x03D0(0x0008)(ZeroConstructor, Transient, DuplicateTransient)
	TSoftObjectPtr<class UAnimMontage>            UseMontage;                                        // 0x03D8(0x0028)(Edit, BlueprintVisible, DisableEditOnInstance, HasGetValueTypeHash)
	class UAnimMontage*                           CachedUseMontage;                                  // 0x0400(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          HasConsumedDevice;                                 // 0x0408(0x0001)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, SaveGame, IsPlainOldData, NoDestructor)

public:
	void ExecuteUbergraph_ITEM_HandheldDevice_Base(int32 EntryPoint);
	void StreamWeaponMontages();
	void OnLoaded_C7864A054553FC5E3414D4B3DBBBFB08(class UObject* Loaded);
	void IsUsingDevice(bool* Result);
	void EVENT_OnStartedUsingDevice();
	void TryResumeHandheldDeviceAction();
	void ConsumeDevice();
	void EVENT_OnFinishingUsingDevice();
	void ReceiveAnimationMessage(const class FString& Message, bool* Result);
	void SetupMaterial();
	void TryBecomeActivatableImmediately(bool ShowImmediately, bool* Result);
	void ResumeWaitingToHolster(class UCOMP_Inventory_C* FromInventory);
	void OnBecomeUnactivatable(bool* Result);
	void Activate(class APAWN_SystemShockCharacter_C* Character, bool* Result);
	void Deactivate(bool* Result);

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"ITEM_HandheldDevice_Base_C">();
	}
	static class UITEM_HandheldDevice_Base_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<UITEM_HandheldDevice_Base_C>();
	}
};
static_assert(alignof(UITEM_HandheldDevice_Base_C) == 0x000008, "Wrong alignment on UITEM_HandheldDevice_Base_C");
static_assert(sizeof(UITEM_HandheldDevice_Base_C) == 0x000410, "Wrong size on UITEM_HandheldDevice_Base_C");
static_assert(offsetof(UITEM_HandheldDevice_Base_C, UberGraphFrame_ITEM_HandheldDevice_Base_C) == 0x0003D0, "Member 'UITEM_HandheldDevice_Base_C::UberGraphFrame_ITEM_HandheldDevice_Base_C' has a wrong offset!");
static_assert(offsetof(UITEM_HandheldDevice_Base_C, UseMontage) == 0x0003D8, "Member 'UITEM_HandheldDevice_Base_C::UseMontage' has a wrong offset!");
static_assert(offsetof(UITEM_HandheldDevice_Base_C, CachedUseMontage) == 0x000400, "Member 'UITEM_HandheldDevice_Base_C::CachedUseMontage' has a wrong offset!");
static_assert(offsetof(UITEM_HandheldDevice_Base_C, HasConsumedDevice) == 0x000408, "Member 'UITEM_HandheldDevice_Base_C::HasConsumedDevice' has a wrong offset!");

}

