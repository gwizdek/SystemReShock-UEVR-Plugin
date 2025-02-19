#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: ITEM_Junk_Base

#include "Basic.hpp"

#include "ITEM_Junk_Base_classes.hpp"
#include "ITEM_Junk_Base_parameters.hpp"


namespace SDK
{

// Function ITEM_Junk_Base.ITEM_Junk_Base_C.CanReycleJunkItem
// (Public, HasOutParams, BlueprintCallable, BlueprintEvent, BlueprintPure)
// Parameters:
// bool                                    Result                                                 (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor)

void UITEM_Junk_Base_C::CanReycleJunkItem(bool* Result)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("ITEM_Junk_Base_C", "CanReycleJunkItem");

	Params::ITEM_Junk_Base_C_CanReycleJunkItem Parms{};

	UObject::ProcessEvent(Func, &Parms);

	if (Result != nullptr)
		*Result = Parms.Result;
}


// Function ITEM_Junk_Base.ITEM_Junk_Base_C.GetRecycleRewardItemCount
// (Public, HasOutParams, BlueprintCallable, BlueprintEvent)
// Parameters:
// class UClass*                           Class_0                                                (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// int32                                   Count_0                                                (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UITEM_Junk_Base_C::GetRecycleRewardItemCount(class UClass** Class_0, int32* Count_0)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("ITEM_Junk_Base_C", "GetRecycleRewardItemCount");

	Params::ITEM_Junk_Base_C_GetRecycleRewardItemCount Parms{};

	UObject::ProcessEvent(Func, &Parms);

	if (Class_0 != nullptr)
		*Class_0 = Parms.Class_0;

	if (Count_0 != nullptr)
		*Count_0 = Parms.Count_0;
}


// Function ITEM_Junk_Base.ITEM_Junk_Base_C.TryRecycleJunkItem
// (Public, HasOutParams, HasDefaults, BlueprintCallable, BlueprintEvent)
// Parameters:
// class UITEM_Base_C*                     SalvageRewardItem                                      (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UITEM_Junk_Base_C::TryRecycleJunkItem(class UITEM_Base_C** SalvageRewardItem)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("ITEM_Junk_Base_C", "TryRecycleJunkItem");

	Params::ITEM_Junk_Base_C_TryRecycleJunkItem Parms{};

	UObject::ProcessEvent(Func, &Parms);

	if (SalvageRewardItem != nullptr)
		*SalvageRewardItem = Parms.SalvageRewardItem;
}


// Function ITEM_Junk_Base.ITEM_Junk_Base_C.VaporizeJunkItem
// (Public, HasOutParams, HasDefaults, BlueprintCallable, BlueprintEvent)
// Parameters:
// bool                                    Result                                                 (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor)

void UITEM_Junk_Base_C::VaporizeJunkItem(bool* Result)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("ITEM_Junk_Base_C", "VaporizeJunkItem");

	Params::ITEM_Junk_Base_C_VaporizeJunkItem Parms{};

	UObject::ProcessEvent(Func, &Parms);

	if (Result != nullptr)
		*Result = Parms.Result;
}


// Function ITEM_Junk_Base.ITEM_Junk_Base_C.GetInventoryItemDetailsClass
// (Public, HasOutParams, BlueprintCallable, BlueprintEvent, BlueprintPure)
// Parameters:
// class UClass*                           InventoryItemDetailsWidget                             (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UITEM_Junk_Base_C::GetInventoryItemDetailsClass(class UClass** InventoryItemDetailsWidget)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("ITEM_Junk_Base_C", "GetInventoryItemDetailsClass");

	Params::ITEM_Junk_Base_C_GetInventoryItemDetailsClass Parms{};

	UObject::ProcessEvent(Func, &Parms);

	if (InventoryItemDetailsWidget != nullptr)
		*InventoryItemDetailsWidget = Parms.InventoryItemDetailsWidget;
}


// Function ITEM_Junk_Base.ITEM_Junk_Base_C.HasWorldInteraction
// (Public, HasOutParams, BlueprintCallable, BlueprintEvent, BlueprintPure)
// Parameters:
// bool                                    Result                                                 (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor)

void UITEM_Junk_Base_C::HasWorldInteraction(bool* Result)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("ITEM_Junk_Base_C", "HasWorldInteraction");

	Params::ITEM_Junk_Base_C_HasWorldInteraction Parms{};

	UObject::ProcessEvent(Func, &Parms);

	if (Result != nullptr)
		*Result = Parms.Result;
}

}

