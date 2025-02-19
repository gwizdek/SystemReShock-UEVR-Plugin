#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: SAVE_DeveloperSettings

#include "Basic.hpp"

#include "Engine_classes.hpp"


namespace SDK
{

// BlueprintGeneratedClass SAVE_DeveloperSettings.SAVE_DeveloperSettings_C
// 0x0008 (0x0030 - 0x0028)
class USAVE_DeveloperSettings_C final : public USaveGame
{
public:
	bool                                          ShowIntroSequence;                                 // 0x0028(0x0001)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor)

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"SAVE_DeveloperSettings_C">();
	}
	static class USAVE_DeveloperSettings_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<USAVE_DeveloperSettings_C>();
	}
};
static_assert(alignof(USAVE_DeveloperSettings_C) == 0x000008, "Wrong alignment on USAVE_DeveloperSettings_C");
static_assert(sizeof(USAVE_DeveloperSettings_C) == 0x000030, "Wrong size on USAVE_DeveloperSettings_C");
static_assert(offsetof(USAVE_DeveloperSettings_C, ShowIntroSequence) == 0x000028, "Member 'USAVE_DeveloperSettings_C::ShowIntroSequence' has a wrong offset!");

}

