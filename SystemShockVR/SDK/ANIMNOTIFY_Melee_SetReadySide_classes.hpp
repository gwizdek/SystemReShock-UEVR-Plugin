#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: ANIMNOTIFY_Melee_SetReadySide

#include "Basic.hpp"

#include "ENUM_LeftRightCenter_structs.hpp"
#include "Engine_classes.hpp"


namespace SDK
{

// BlueprintGeneratedClass ANIMNOTIFY_Melee_SetReadySide.ANIMNOTIFY_Melee_SetReadySide_C
// 0x0008 (0x0040 - 0x0038)
class UANIMNOTIFY_Melee_SetReadySide_C final : public UAnimNotify
{
public:
	ENUM_LeftRightCenter                          Side;                                              // 0x0038(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

public:
	class FString GetNotifyName() const;
	bool Received_Notify(class USkeletalMeshComponent* MeshComp, class UAnimSequenceBase* Animation) const;

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"ANIMNOTIFY_Melee_SetReadySide_C">();
	}
	static class UANIMNOTIFY_Melee_SetReadySide_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<UANIMNOTIFY_Melee_SetReadySide_C>();
	}
};
static_assert(alignof(UANIMNOTIFY_Melee_SetReadySide_C) == 0x000008, "Wrong alignment on UANIMNOTIFY_Melee_SetReadySide_C");
static_assert(sizeof(UANIMNOTIFY_Melee_SetReadySide_C) == 0x000040, "Wrong size on UANIMNOTIFY_Melee_SetReadySide_C");
static_assert(offsetof(UANIMNOTIFY_Melee_SetReadySide_C, Side) == 0x000038, "Member 'UANIMNOTIFY_Melee_SetReadySide_C::Side' has a wrong offset!");

}

