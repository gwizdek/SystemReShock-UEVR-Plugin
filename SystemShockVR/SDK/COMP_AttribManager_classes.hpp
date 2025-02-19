#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: COMP_AttribManager

#include "Basic.hpp"

#include "AttributeSystem_classes.hpp"


namespace SDK
{

// BlueprintGeneratedClass COMP_AttribManager.COMP_AttribManager_C
// 0x0008 (0x01A8 - 0x01A0)
class UCOMP_AttribManager_C final : public UAttribManagerComponent
{
public:
	bool                                          ShouldSaveAttributes;                              // 0x01A0(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor)

public:
	void K2_OnGetElapsedPlayTime(float* PlayTime);
	float GetExploitDamage(class AActor* SourceActor, class UAttribDamageType* DamageType, class UObject* UserParams);
	float GetArmorAugmentation(class AActor* SourceActor, class UAttribDamageType* DamageType, class UObject* UserParams);
	bool ShouldSaveComponent(struct FStreamingSaveGameComponentParams* Params_0);

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"COMP_AttribManager_C">();
	}
	static class UCOMP_AttribManager_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<UCOMP_AttribManager_C>();
	}
};
static_assert(alignof(UCOMP_AttribManager_C) == 0x000008, "Wrong alignment on UCOMP_AttribManager_C");
static_assert(sizeof(UCOMP_AttribManager_C) == 0x0001A8, "Wrong size on UCOMP_AttribManager_C");
static_assert(offsetof(UCOMP_AttribManager_C, ShouldSaveAttributes) == 0x0001A0, "Member 'UCOMP_AttribManager_C::ShouldSaveAttributes' has a wrong offset!");

}

