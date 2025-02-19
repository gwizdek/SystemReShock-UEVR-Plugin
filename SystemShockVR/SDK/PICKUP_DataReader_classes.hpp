#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: PICKUP_DataReader

#include "Basic.hpp"

#include "PICKUP_Hardware_Base_classes.hpp"


namespace SDK
{

// BlueprintGeneratedClass PICKUP_DataReader.PICKUP_DataReader_C
// 0x0000 (0x0480 - 0x0480)
class APICKUP_DataReader_C final : public APICKUP_Hardware_Base_C
{
public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"PICKUP_DataReader_C">();
	}
	static class APICKUP_DataReader_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<APICKUP_DataReader_C>();
	}
};
static_assert(alignof(APICKUP_DataReader_C) == 0x000008, "Wrong alignment on APICKUP_DataReader_C");
static_assert(sizeof(APICKUP_DataReader_C) == 0x000480, "Wrong size on APICKUP_DataReader_C");

}

