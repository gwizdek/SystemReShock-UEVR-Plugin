#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: INTERF_MouseOverToolTip

#include "Basic.hpp"

#include "CoreUObject_classes.hpp"


namespace SDK
{

// BlueprintGeneratedClass INTERF_MouseOverToolTip.INTERF_MouseOverToolTip_C
// 0x0000 (0x0028 - 0x0028)
class IINTERF_MouseOverToolTip_C final : public IInterface
{
public:
	void GetToolTipText(class FText* ToolTip);

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"INTERF_MouseOverToolTip_C">();
	}
	static class IINTERF_MouseOverToolTip_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<IINTERF_MouseOverToolTip_C>();
	}
};
static_assert(alignof(IINTERF_MouseOverToolTip_C) == 0x000008, "Wrong alignment on IINTERF_MouseOverToolTip_C");
static_assert(sizeof(IINTERF_MouseOverToolTip_C) == 0x000028, "Wrong size on IINTERF_MouseOverToolTip_C");

}

