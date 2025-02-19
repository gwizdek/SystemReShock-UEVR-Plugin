#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: COMP_SkinnedDecalSampler

#include "Basic.hpp"

#include "SkinnedDecalComponent_classes.hpp"


namespace SDK
{

// BlueprintGeneratedClass COMP_SkinnedDecalSampler.COMP_SkinnedDecalSampler_C
// 0x0000 (0x0188 - 0x0188)
class UCOMP_SkinnedDecalSampler_C final : public USkinnedDecalSampler
{
public:
	bool ShouldSaveComponent(struct FStreamingSaveGameComponentParams* Params_0);

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"COMP_SkinnedDecalSampler_C">();
	}
	static class UCOMP_SkinnedDecalSampler_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<UCOMP_SkinnedDecalSampler_C>();
	}
};
static_assert(alignof(UCOMP_SkinnedDecalSampler_C) == 0x000008, "Wrong alignment on UCOMP_SkinnedDecalSampler_C");
static_assert(sizeof(UCOMP_SkinnedDecalSampler_C) == 0x000188, "Wrong size on UCOMP_SkinnedDecalSampler_C");

}

