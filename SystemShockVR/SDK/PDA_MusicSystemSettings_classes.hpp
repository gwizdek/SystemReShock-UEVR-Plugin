#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: PDA_MusicSystemSettings

#include "Basic.hpp"

#include "Engine_classes.hpp"


namespace SDK
{

// BlueprintGeneratedClass PDA_MusicSystemSettings.PDA_MusicSystemSettings_C
// 0x0010 (0x0040 - 0x0030)
class UPDA_MusicSystemSettings_C final : public UPrimaryDataAsset
{
public:
	float                                         ExplorationIntensityRegionDiscoverGain;            // 0x0030(0x0004)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         ExplorationIntensityDecayAmount;                   // 0x0034(0x0004)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         ExplorationIntensityDecayTime;                     // 0x0038(0x0004)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"PDA_MusicSystemSettings_C">();
	}
	static class UPDA_MusicSystemSettings_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<UPDA_MusicSystemSettings_C>();
	}
};
static_assert(alignof(UPDA_MusicSystemSettings_C) == 0x000008, "Wrong alignment on UPDA_MusicSystemSettings_C");
static_assert(sizeof(UPDA_MusicSystemSettings_C) == 0x000040, "Wrong size on UPDA_MusicSystemSettings_C");
static_assert(offsetof(UPDA_MusicSystemSettings_C, ExplorationIntensityRegionDiscoverGain) == 0x000030, "Member 'UPDA_MusicSystemSettings_C::ExplorationIntensityRegionDiscoverGain' has a wrong offset!");
static_assert(offsetof(UPDA_MusicSystemSettings_C, ExplorationIntensityDecayAmount) == 0x000034, "Member 'UPDA_MusicSystemSettings_C::ExplorationIntensityDecayAmount' has a wrong offset!");
static_assert(offsetof(UPDA_MusicSystemSettings_C, ExplorationIntensityDecayTime) == 0x000038, "Member 'UPDA_MusicSystemSettings_C::ExplorationIntensityDecayTime' has a wrong offset!");

}

