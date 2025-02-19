#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: SKILL_ShootHomingMissile

#include "Basic.hpp"

#include "CoreUObject_structs.hpp"
#include "SKILL_LaunchProjectile_classes.hpp"


namespace SDK
{

// BlueprintGeneratedClass SKILL_ShootHomingMissile.SKILL_ShootHomingMissile_C
// 0x0068 (0x0178 - 0x0110)
class USKILL_ShootHomingMissile_C : public USKILL_LaunchProjectile_C
{
public:
	TArray<struct FVector2D>                      MissilePortOffsets;                                // 0x0110(0x0010)(Edit, BlueprintVisible, DisableEditOnInstance)
	TMap<class FName, int32>                      LastBarrelPortIndexMap;                            // 0x0120(0x0050)(Edit, BlueprintVisible, DisableEditOnInstance)
	float                                         MaxSpreadRadius;                                   // 0x0170(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

public:
	void LaunchProjectile();
	void OnProjectileLaunched();
	void OnAttachProjectileToBarrel(class FName BarrelSocketName);
	void GetBarrelTransform(class FName BarrelName, struct FTransform* Transform);
	void OnCycleBarrel();
	void GetPortOffsetFromIndex(int32 PortIndex, struct FVector2D* Result);

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"SKILL_ShootHomingMissile_C">();
	}
	static class USKILL_ShootHomingMissile_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<USKILL_ShootHomingMissile_C>();
	}
};
static_assert(alignof(USKILL_ShootHomingMissile_C) == 0x000008, "Wrong alignment on USKILL_ShootHomingMissile_C");
static_assert(sizeof(USKILL_ShootHomingMissile_C) == 0x000178, "Wrong size on USKILL_ShootHomingMissile_C");
static_assert(offsetof(USKILL_ShootHomingMissile_C, MissilePortOffsets) == 0x000110, "Member 'USKILL_ShootHomingMissile_C::MissilePortOffsets' has a wrong offset!");
static_assert(offsetof(USKILL_ShootHomingMissile_C, LastBarrelPortIndexMap) == 0x000120, "Member 'USKILL_ShootHomingMissile_C::LastBarrelPortIndexMap' has a wrong offset!");
static_assert(offsetof(USKILL_ShootHomingMissile_C, MaxSpreadRadius) == 0x000170, "Member 'USKILL_ShootHomingMissile_C::MaxSpreadRadius' has a wrong offset!");

}

