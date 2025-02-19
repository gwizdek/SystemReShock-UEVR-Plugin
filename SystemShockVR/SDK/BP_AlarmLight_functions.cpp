#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: BP_AlarmLight

#include "Basic.hpp"

#include "BP_AlarmLight_classes.hpp"
#include "BP_AlarmLight_parameters.hpp"


namespace SDK
{

// Function BP_AlarmLight.BP_AlarmLight_C.ExecuteUbergraph_BP_AlarmLight
// (Final, UbergraphFunction)
// Parameters:
// int32                                   EntryPoint                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void ABP_AlarmLight_C::ExecuteUbergraph_BP_AlarmLight(int32 EntryPoint)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("BP_AlarmLight_C", "ExecuteUbergraph_BP_AlarmLight");

	Params::BP_AlarmLight_C_ExecuteUbergraph_BP_AlarmLight Parms{};

	Parms.EntryPoint = EntryPoint;

	UObject::ProcessEvent(Func, &Parms);
}


// Function BP_AlarmLight.BP_AlarmLight_C.BndEvt__BP_AlarmLight_COMP_VoxelCullable_K2Node_ComponentBoundEvent_2_CullableVisibilitySignature__DelegateSignature
// (BlueprintEvent)
// Parameters:
// bool                                    bVisibleState                                          (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor)

void ABP_AlarmLight_C::BndEvt__BP_AlarmLight_COMP_VoxelCullable_K2Node_ComponentBoundEvent_2_CullableVisibilitySignature__DelegateSignature(bool bVisibleState)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("BP_AlarmLight_C", "BndEvt__BP_AlarmLight_COMP_VoxelCullable_K2Node_ComponentBoundEvent_2_CullableVisibilitySignature__DelegateSignature");

	Params::BP_AlarmLight_C_BndEvt__BP_AlarmLight_COMP_VoxelCullable_K2Node_ComponentBoundEvent_2_CullableVisibilitySignature__DelegateSignature Parms{};

	Parms.bVisibleState = bVisibleState;

	UObject::ProcessEvent(Func, &Parms);
}


// Function BP_AlarmLight.BP_AlarmLight_C.ReceiveBeginPlay
// (Event, Protected, BlueprintEvent)

void ABP_AlarmLight_C::ReceiveBeginPlay()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("BP_AlarmLight_C", "ReceiveBeginPlay");

	UObject::ProcessEvent(Func, nullptr);
}


// Function BP_AlarmLight.BP_AlarmLight_C.UserConstructionScript
// (Event, Public, BlueprintCallable, BlueprintEvent)

void ABP_AlarmLight_C::UserConstructionScript()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("BP_AlarmLight_C", "UserConstructionScript");

	UObject::ProcessEvent(Func, nullptr);
}


// Function BP_AlarmLight.BP_AlarmLight_C.InitializeAttributes
// (Protected, BlueprintCallable, BlueprintEvent)

void ABP_AlarmLight_C::InitializeAttributes()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("BP_AlarmLight_C", "InitializeAttributes");

	UObject::ProcessEvent(Func, nullptr);
}


// Function BP_AlarmLight.BP_AlarmLight_C.UpdateEmissiveStrength
// (Protected, BlueprintCallable, BlueprintEvent)
// Parameters:
// float                                   Scale                                                  (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void ABP_AlarmLight_C::UpdateEmissiveStrength(float Scale)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("BP_AlarmLight_C", "UpdateEmissiveStrength");

	Params::BP_AlarmLight_C_UpdateEmissiveStrength Parms{};

	Parms.Scale = Scale;

	UObject::ProcessEvent(Func, &Parms);
}


// Function BP_AlarmLight.BP_AlarmLight_C.UpdateAlarmLightVisibility
// (Protected, BlueprintCallable, BlueprintEvent)
// Parameters:
// bool                                    VisibilityState                                        (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor)

void ABP_AlarmLight_C::UpdateAlarmLightVisibility(bool VisibilityState)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("BP_AlarmLight_C", "UpdateAlarmLightVisibility");

	Params::BP_AlarmLight_C_UpdateAlarmLightVisibility Parms{};

	Parms.VisibilityState = VisibilityState;

	UObject::ProcessEvent(Func, &Parms);
}


// Function BP_AlarmLight.BP_AlarmLight_C.EVENT_OnDisableAttribChanged
// (Private, BlueprintCallable, BlueprintEvent)
// Parameters:
// float                                   CurrValue                                              (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// float                                   LastValue                                              (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void ABP_AlarmLight_C::EVENT_OnDisableAttribChanged(float CurrValue, float LastValue)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("BP_AlarmLight_C", "EVENT_OnDisableAttribChanged");

	Params::BP_AlarmLight_C_EVENT_OnDisableAttribChanged Parms{};

	Parms.CurrValue = CurrValue;
	Parms.LastValue = LastValue;

	UObject::ProcessEvent(Func, &Parms);
}


// Function BP_AlarmLight.BP_AlarmLight_C.IsAlarmFunctional
// (Public, HasOutParams, BlueprintCallable, BlueprintEvent, BlueprintPure)
// Parameters:
// bool                                    Result                                                 (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor)

void ABP_AlarmLight_C::IsAlarmFunctional(bool* Result)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("BP_AlarmLight_C", "IsAlarmFunctional");

	Params::BP_AlarmLight_C_IsAlarmFunctional Parms{};

	UObject::ProcessEvent(Func, &Parms);

	if (Result != nullptr)
		*Result = Parms.Result;
}


// Function BP_AlarmLight.BP_AlarmLight_C.InitializeAlarmSpeaker
// (Protected, BlueprintCallable, BlueprintEvent)

void ABP_AlarmLight_C::InitializeAlarmSpeaker()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("BP_AlarmLight_C", "InitializeAlarmSpeaker");

	UObject::ProcessEvent(Func, nullptr);
}


// Function BP_AlarmLight.BP_AlarmLight_C.OnAlarmActivated
// (Protected, BlueprintCallable, BlueprintEvent)

void ABP_AlarmLight_C::OnAlarmActivated()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("BP_AlarmLight_C", "OnAlarmActivated");

	UObject::ProcessEvent(Func, nullptr);
}


// Function BP_AlarmLight.BP_AlarmLight_C.GetAlarmSpeakerPosition
// (Public, HasOutParams, BlueprintCallable, BlueprintEvent, BlueprintPure)
// Parameters:
// struct FVector                          Result                                                 (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void ABP_AlarmLight_C::GetAlarmSpeakerPosition(struct FVector* Result)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("BP_AlarmLight_C", "GetAlarmSpeakerPosition");

	Params::BP_AlarmLight_C_GetAlarmSpeakerPosition Parms{};

	UObject::ProcessEvent(Func, &Parms);

	if (Result != nullptr)
		*Result = std::move(Parms.Result);
}

}

