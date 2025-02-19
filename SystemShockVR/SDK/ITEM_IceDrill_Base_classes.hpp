#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: ITEM_IceDrill_Base

#include "Basic.hpp"

#include "Engine_structs.hpp"
#include "ITEM_CyberWeapon_Base_classes.hpp"


namespace SDK
{

// BlueprintGeneratedClass ITEM_IceDrill_Base.ITEM_IceDrill_Base_C
// 0x0020 (0x0228 - 0x0208)
class UITEM_IceDrill_Base_C final : public UITEM_CyberWeapon_Base_C
{
public:
	float                                         ActivateTimestamp;                                 // 0x0204(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         RequiredLockOnDuration;                            // 0x0208(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         MaxLockOnDistance;                                 // 0x020C(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         MaxLockOnAngle;                                    // 0x0210(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_214[0x4];                                      // 0x0214(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	class AActor*                                 LockOnActor;                                       // 0x0218(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnTemplate, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FTimerHandle                           LockOnTimerHandle;                                 // 0x0220(0x0008)(Edit, BlueprintVisible, DisableEditOnInstance, NoDestructor, HasGetValueTypeHash)

public:
	void EVENT_FireProjectile();
	void GetLockOnProgress(float* Progress);
	void EVENT_LockOnTick();
	void TryFindLockOnActor(class AActor** Result);
	void IsActorInLockOnRange(class AActor* Actor, bool* Result, float* Angle);
	void Activate(class APAWN_SystemShockCharacter_C* Character, bool* Result);
	void Deactivate(bool* Result);

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"ITEM_IceDrill_Base_C">();
	}
	static class UITEM_IceDrill_Base_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<UITEM_IceDrill_Base_C>();
	}
};
static_assert(alignof(UITEM_IceDrill_Base_C) == 0x000008, "Wrong alignment on UITEM_IceDrill_Base_C");
static_assert(sizeof(UITEM_IceDrill_Base_C) == 0x000228, "Wrong size on UITEM_IceDrill_Base_C");
static_assert(offsetof(UITEM_IceDrill_Base_C, ActivateTimestamp) == 0x000204, "Member 'UITEM_IceDrill_Base_C::ActivateTimestamp' has a wrong offset!");
static_assert(offsetof(UITEM_IceDrill_Base_C, RequiredLockOnDuration) == 0x000208, "Member 'UITEM_IceDrill_Base_C::RequiredLockOnDuration' has a wrong offset!");
static_assert(offsetof(UITEM_IceDrill_Base_C, MaxLockOnDistance) == 0x00020C, "Member 'UITEM_IceDrill_Base_C::MaxLockOnDistance' has a wrong offset!");
static_assert(offsetof(UITEM_IceDrill_Base_C, MaxLockOnAngle) == 0x000210, "Member 'UITEM_IceDrill_Base_C::MaxLockOnAngle' has a wrong offset!");
static_assert(offsetof(UITEM_IceDrill_Base_C, LockOnActor) == 0x000218, "Member 'UITEM_IceDrill_Base_C::LockOnActor' has a wrong offset!");
static_assert(offsetof(UITEM_IceDrill_Base_C, LockOnTimerHandle) == 0x000220, "Member 'UITEM_IceDrill_Base_C::LockOnTimerHandle' has a wrong offset!");

}

