#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: CIRCUITPUZZLE_Simple

#include "Basic.hpp"

#include "Engine_structs.hpp"
#include "CIRCUITPUZZLE_Base_classes.hpp"


namespace SDK
{

// BlueprintGeneratedClass CIRCUITPUZZLE_Simple.CIRCUITPUZZLE_Simple_C
// 0x0008 (0x08A8 - 0x08A0)
class ACIRCUITPUZZLE_Simple_C final : public ACIRCUITPUZZLE_Base_C
{
public:
	struct FPointerToUberGraphFrame               UberGraphFrame_CIRCUITPUZZLE_Simple_C;             // 0x08A0(0x0008)(ZeroConstructor, Transient, DuplicateTransient)

public:
	void ExecuteUbergraph_CIRCUITPUZZLE_Simple(int32 EntryPoint);
	void ReceiveBeginPlay();

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"CIRCUITPUZZLE_Simple_C">();
	}
	static class ACIRCUITPUZZLE_Simple_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<ACIRCUITPUZZLE_Simple_C>();
	}
};
static_assert(alignof(ACIRCUITPUZZLE_Simple_C) == 0x000008, "Wrong alignment on ACIRCUITPUZZLE_Simple_C");
static_assert(sizeof(ACIRCUITPUZZLE_Simple_C) == 0x0008A8, "Wrong size on ACIRCUITPUZZLE_Simple_C");
static_assert(offsetof(ACIRCUITPUZZLE_Simple_C, UberGraphFrame_CIRCUITPUZZLE_Simple_C) == 0x0008A0, "Member 'ACIRCUITPUZZLE_Simple_C::UberGraphFrame_CIRCUITPUZZLE_Simple_C' has a wrong offset!");

}

