#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: AnimBP_IrisDoor

#include "Basic.hpp"

#include "AnimBP_DuctDoor_ResearchDoor_ResearchDoorDamaged_classes.hpp"


namespace SDK
{

// AnimBlueprintGeneratedClass AnimBP_IrisDoor.AnimBP_IrisDoor_C
// 0x0000 (0x0500 - 0x0500)
class UAnimBP_IrisDoor_C final : public UAnimBP_DuctDoor_ResearchDoor_ResearchDoorDamaged_C
{
public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"AnimBP_IrisDoor_C">();
	}
	static class UAnimBP_IrisDoor_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<UAnimBP_IrisDoor_C>();
	}
};
static_assert(alignof(UAnimBP_IrisDoor_C) == 0x000010, "Wrong alignment on UAnimBP_IrisDoor_C");
static_assert(sizeof(UAnimBP_IrisDoor_C) == 0x000500, "Wrong size on UAnimBP_IrisDoor_C");

}

