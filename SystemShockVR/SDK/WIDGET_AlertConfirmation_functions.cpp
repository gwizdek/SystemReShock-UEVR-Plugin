#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: WIDGET_AlertConfirmation

#include "Basic.hpp"

#include "WIDGET_AlertConfirmation_classes.hpp"
#include "WIDGET_AlertConfirmation_parameters.hpp"


namespace SDK
{

// Function WIDGET_AlertConfirmation.WIDGET_AlertConfirmation_C.OnClickAccept__DelegateSignature
// (Public, Delegate, BlueprintCallable, BlueprintEvent)

void UWIDGET_AlertConfirmation_C::OnClickAccept__DelegateSignature()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WIDGET_AlertConfirmation_C", "OnClickAccept__DelegateSignature");

	UObject::ProcessEvent(Func, nullptr);
}


// Function WIDGET_AlertConfirmation.WIDGET_AlertConfirmation_C.OnClickBack__DelegateSignature
// (Public, Delegate, BlueprintCallable, BlueprintEvent)

void UWIDGET_AlertConfirmation_C::OnClickBack__DelegateSignature()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WIDGET_AlertConfirmation_C", "OnClickBack__DelegateSignature");

	UObject::ProcessEvent(Func, nullptr);
}


// Function WIDGET_AlertConfirmation.WIDGET_AlertConfirmation_C.ExecuteUbergraph_WIDGET_AlertConfirmation
// (Final, UbergraphFunction, HasDefaults)
// Parameters:
// int32                                   EntryPoint                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UWIDGET_AlertConfirmation_C::ExecuteUbergraph_WIDGET_AlertConfirmation(int32 EntryPoint)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WIDGET_AlertConfirmation_C", "ExecuteUbergraph_WIDGET_AlertConfirmation");

	Params::WIDGET_AlertConfirmation_C_ExecuteUbergraph_WIDGET_AlertConfirmation Parms{};

	Parms.EntryPoint = EntryPoint;

	UObject::ProcessEvent(Func, &Parms);
}


// Function WIDGET_AlertConfirmation.WIDGET_AlertConfirmation_C.BndEvt__WIDGET_AlertConfirmation_WIDGET_ButtonLegend_Confirm_K2Node_ComponentBoundEvent_1_OnClicked__DelegateSignature
// (BlueprintEvent)
// Parameters:
// struct FGeometry                        Geometry                                               (BlueprintVisible, BlueprintReadOnly, Parm, IsPlainOldData, NoDestructor)
// struct FPointerEvent                    InputEvent                                             (BlueprintVisible, BlueprintReadOnly, Parm)

void UWIDGET_AlertConfirmation_C::BndEvt__WIDGET_AlertConfirmation_WIDGET_ButtonLegend_Confirm_K2Node_ComponentBoundEvent_1_OnClicked__DelegateSignature(const struct FGeometry& Geometry, const struct FPointerEvent& InputEvent)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WIDGET_AlertConfirmation_C", "BndEvt__WIDGET_AlertConfirmation_WIDGET_ButtonLegend_Confirm_K2Node_ComponentBoundEvent_1_OnClicked__DelegateSignature");

	Params::WIDGET_AlertConfirmation_C_BndEvt__WIDGET_AlertConfirmation_WIDGET_ButtonLegend_Confirm_K2Node_ComponentBoundEvent_1_OnClicked__DelegateSignature Parms{};

	Parms.Geometry = std::move(Geometry);
	Parms.InputEvent = std::move(InputEvent);

	UObject::ProcessEvent(Func, &Parms);
}


// Function WIDGET_AlertConfirmation.WIDGET_AlertConfirmation_C.BndEvt__WIDGET_AlertConfirmation_WIDGET_ButtonLegend_Back_K2Node_ComponentBoundEvent_0_OnClicked__DelegateSignature
// (BlueprintEvent)
// Parameters:
// struct FGeometry                        Geometry                                               (BlueprintVisible, BlueprintReadOnly, Parm, IsPlainOldData, NoDestructor)
// struct FPointerEvent                    InputEvent                                             (BlueprintVisible, BlueprintReadOnly, Parm)

void UWIDGET_AlertConfirmation_C::BndEvt__WIDGET_AlertConfirmation_WIDGET_ButtonLegend_Back_K2Node_ComponentBoundEvent_0_OnClicked__DelegateSignature(const struct FGeometry& Geometry, const struct FPointerEvent& InputEvent)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WIDGET_AlertConfirmation_C", "BndEvt__WIDGET_AlertConfirmation_WIDGET_ButtonLegend_Back_K2Node_ComponentBoundEvent_0_OnClicked__DelegateSignature");

	Params::WIDGET_AlertConfirmation_C_BndEvt__WIDGET_AlertConfirmation_WIDGET_ButtonLegend_Back_K2Node_ComponentBoundEvent_0_OnClicked__DelegateSignature Parms{};

	Parms.Geometry = std::move(Geometry);
	Parms.InputEvent = std::move(InputEvent);

	UObject::ProcessEvent(Func, &Parms);
}


// Function WIDGET_AlertConfirmation.WIDGET_AlertConfirmation_C.PreConstruct
// (BlueprintCosmetic, Event, Public, BlueprintEvent)
// Parameters:
// bool                                    IsDesignTime                                           (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor)

void UWIDGET_AlertConfirmation_C::PreConstruct(bool IsDesignTime)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WIDGET_AlertConfirmation_C", "PreConstruct");

	Params::WIDGET_AlertConfirmation_C_PreConstruct Parms{};

	Parms.IsDesignTime = IsDesignTime;

	UObject::ProcessEvent(Func, &Parms);
}


// Function WIDGET_AlertConfirmation.WIDGET_AlertConfirmation_C.TriggerAcceptInput
// (Public, BlueprintCallable, BlueprintEvent)

void UWIDGET_AlertConfirmation_C::TriggerAcceptInput()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WIDGET_AlertConfirmation_C", "TriggerAcceptInput");

	UObject::ProcessEvent(Func, nullptr);
}


// Function WIDGET_AlertConfirmation.WIDGET_AlertConfirmation_C.TriggerBackInput
// (Public, BlueprintCallable, BlueprintEvent)

void UWIDGET_AlertConfirmation_C::TriggerBackInput()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WIDGET_AlertConfirmation_C", "TriggerBackInput");

	UObject::ProcessEvent(Func, nullptr);
}

}

