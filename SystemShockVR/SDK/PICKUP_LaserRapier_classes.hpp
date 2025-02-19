#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: PICKUP_LaserRapier

#include "Basic.hpp"

#include "ENUM_LaserRapierColor_structs.hpp"
#include "PICKUP_Base_classes.hpp"


namespace SDK
{

// BlueprintGeneratedClass PICKUP_LaserRapier.PICKUP_LaserRapier_C
// 0x0000 (0x0478 - 0x0478)
class APICKUP_LaserRapier_C final : public APICKUP_Base_C
{
public:
	ENUM_LaserRapierColor                         LaserColorType;                                    // 0x0474(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

public:
	void OnPrePickup();
	void GetItemDisplayName(class FText* Result);

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"PICKUP_LaserRapier_C">();
	}
	static class APICKUP_LaserRapier_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<APICKUP_LaserRapier_C>();
	}
};
static_assert(alignof(APICKUP_LaserRapier_C) == 0x000008, "Wrong alignment on APICKUP_LaserRapier_C");
static_assert(sizeof(APICKUP_LaserRapier_C) == 0x000478, "Wrong size on APICKUP_LaserRapier_C");
static_assert(offsetof(APICKUP_LaserRapier_C, LaserColorType) == 0x000474, "Member 'APICKUP_LaserRapier_C::LaserColorType' has a wrong offset!");

}

