#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: ITEM_FirstAidKit

#include "Basic.hpp"

#include "ITEM_FirstAidKit_classes.hpp"
#include "ITEM_FirstAidKit_parameters.hpp"


namespace SDK
{

// Function ITEM_FirstAidKit.ITEM_FirstAidKit_C.UseConsumable
// (Public, HasOutParams, BlueprintCallable, BlueprintEvent)
// Parameters:
// class APAWN_SystemShockCharacter_C*     Character                                              (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// class UITEM_ConsumableBase_C*           ConsumedItem                                           (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UITEM_FirstAidKit_C::UseConsumable(class APAWN_SystemShockCharacter_C* Character, class UITEM_ConsumableBase_C** ConsumedItem)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("ITEM_FirstAidKit_C", "UseConsumable");

	Params::ITEM_FirstAidKit_C_UseConsumable Parms{};

	Parms.Character = Character;

	UObject::ProcessEvent(Func, &Parms);

	if (ConsumedItem != nullptr)
		*ConsumedItem = Parms.ConsumedItem;
}


// Function ITEM_FirstAidKit.ITEM_FirstAidKit_C.GetEffects
// (Public, HasOutParams, HasDefaults, BlueprintCallable, BlueprintEvent, BlueprintPure)
// Parameters:
// class FText                             EffectsText                                            (Parm, OutParm)

void UITEM_FirstAidKit_C::GetEffects(class FText* EffectsText)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("ITEM_FirstAidKit_C", "GetEffects");

	Params::ITEM_FirstAidKit_C_GetEffects Parms{};

	UObject::ProcessEvent(Func, &Parms);

	if (EffectsText != nullptr)
		*EffectsText = std::move(Parms.EffectsText);
}


// Function ITEM_FirstAidKit.ITEM_FirstAidKit_C.GetDuration
// (Public, HasOutParams, BlueprintCallable, BlueprintEvent, BlueprintPure)
// Parameters:
// class FText                             DurationText                                           (Parm, OutParm)

void UITEM_FirstAidKit_C::GetDuration(class FText* DurationText)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("ITEM_FirstAidKit_C", "GetDuration");

	Params::ITEM_FirstAidKit_C_GetDuration Parms{};

	UObject::ProcessEvent(Func, &Parms);

	if (DurationText != nullptr)
		*DurationText = std::move(Parms.DurationText);
}


// Function ITEM_FirstAidKit.ITEM_FirstAidKit_C.GetOwner
// (Public, HasOutParams, BlueprintCallable, BlueprintEvent)
// Parameters:
// class AActor*                           Owner                                                  (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UITEM_FirstAidKit_C::GetOwner(class AActor** Owner)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("ITEM_FirstAidKit_C", "GetOwner");

	Params::ITEM_FirstAidKit_C_GetOwner Parms{};

	UObject::ProcessEvent(Func, &Parms);

	if (Owner != nullptr)
		*Owner = Parms.Owner;
}


// Function ITEM_FirstAidKit.ITEM_FirstAidKit_C.GetEquipState
// (Public, HasOutParams, BlueprintCallable, BlueprintEvent)
// Parameters:
// bool                                    Result                                                 (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor)

void UITEM_FirstAidKit_C::GetEquipState(bool* Result)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("ITEM_FirstAidKit_C", "GetEquipState");

	Params::ITEM_FirstAidKit_C_GetEquipState Parms{};

	UObject::ProcessEvent(Func, &Parms);

	if (Result != nullptr)
		*Result = Parms.Result;
}


// Function ITEM_FirstAidKit.ITEM_FirstAidKit_C.GetHotbarDisplayName
// (Public, HasOutParams, BlueprintCallable, BlueprintEvent)
// Parameters:
// class FText                             Result                                                 (Parm, OutParm)

void UITEM_FirstAidKit_C::GetHotbarDisplayName(class FText* Result)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("ITEM_FirstAidKit_C", "GetHotbarDisplayName");

	Params::ITEM_FirstAidKit_C_GetHotbarDisplayName Parms{};

	UObject::ProcessEvent(Func, &Parms);

	if (Result != nullptr)
		*Result = std::move(Parms.Result);
}


// Function ITEM_FirstAidKit.ITEM_FirstAidKit_C.GetHotbarCount
// (Public, HasOutParams, BlueprintCallable, BlueprintEvent)
// Parameters:
// int32                                   ResultCount                                            (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UITEM_FirstAidKit_C::GetHotbarCount(int32* ResultCount)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("ITEM_FirstAidKit_C", "GetHotbarCount");

	Params::ITEM_FirstAidKit_C_GetHotbarCount Parms{};

	UObject::ProcessEvent(Func, &Parms);

	if (ResultCount != nullptr)
		*ResultCount = Parms.ResultCount;
}


// Function ITEM_FirstAidKit.ITEM_FirstAidKit_C.GetHotbarIcon
// (Public, HasOutParams, BlueprintCallable, BlueprintEvent)
// Parameters:
// class UTexture*                         ResultIcon                                             (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UITEM_FirstAidKit_C::GetHotbarIcon(class UTexture** ResultIcon)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("ITEM_FirstAidKit_C", "GetHotbarIcon");

	Params::ITEM_FirstAidKit_C_GetHotbarIcon Parms{};

	UObject::ProcessEvent(Func, &Parms);

	if (ResultIcon != nullptr)
		*ResultIcon = Parms.ResultIcon;
}


// Function ITEM_FirstAidKit.ITEM_FirstAidKit_C.DeactivateHotbarSlot
// (Public, HasOutParams, BlueprintCallable, BlueprintEvent)
// Parameters:
// bool                                    Result                                                 (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor)

void UITEM_FirstAidKit_C::DeactivateHotbarSlot(bool* Result)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("ITEM_FirstAidKit_C", "DeactivateHotbarSlot");

	Params::ITEM_FirstAidKit_C_DeactivateHotbarSlot Parms{};

	UObject::ProcessEvent(Func, &Parms);

	if (Result != nullptr)
		*Result = Parms.Result;
}


// Function ITEM_FirstAidKit.ITEM_FirstAidKit_C.ActivateHotbarSlot
// (Public, HasOutParams, BlueprintCallable, BlueprintEvent)
// Parameters:
// bool                                    Result                                                 (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor)

void UITEM_FirstAidKit_C::ActivateHotbarSlot(bool* Result)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("ITEM_FirstAidKit_C", "ActivateHotbarSlot");

	Params::ITEM_FirstAidKit_C_ActivateHotbarSlot Parms{};

	UObject::ProcessEvent(Func, &Parms);

	if (Result != nullptr)
		*Result = Parms.Result;
}


// Function ITEM_FirstAidKit.ITEM_FirstAidKit_C.TryUseConsumable
// (Public, HasOutParams, BlueprintCallable, BlueprintEvent)
// Parameters:
// bool                                    Result                                                 (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor)

void UITEM_FirstAidKit_C::TryUseConsumable(bool* Result)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("ITEM_FirstAidKit_C", "TryUseConsumable");

	Params::ITEM_FirstAidKit_C_TryUseConsumable Parms{};

	UObject::ProcessEvent(Func, &Parms);

	if (Result != nullptr)
		*Result = Parms.Result;
}

}

