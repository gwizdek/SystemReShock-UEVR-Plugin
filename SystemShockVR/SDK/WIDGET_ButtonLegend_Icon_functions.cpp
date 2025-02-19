#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: WIDGET_ButtonLegend_Icon

#include "Basic.hpp"

#include "WIDGET_ButtonLegend_Icon_classes.hpp"
#include "WIDGET_ButtonLegend_Icon_parameters.hpp"


namespace SDK
{

// Function WIDGET_ButtonLegend_Icon.WIDGET_ButtonLegend_Icon_C.ExecuteUbergraph_WIDGET_ButtonLegend_Icon
// (Final, UbergraphFunction)
// Parameters:
// int32                                   EntryPoint                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UWIDGET_ButtonLegend_Icon_C::ExecuteUbergraph_WIDGET_ButtonLegend_Icon(int32 EntryPoint)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WIDGET_ButtonLegend_Icon_C", "ExecuteUbergraph_WIDGET_ButtonLegend_Icon");

	Params::WIDGET_ButtonLegend_Icon_C_ExecuteUbergraph_WIDGET_ButtonLegend_Icon Parms{};

	Parms.EntryPoint = EntryPoint;

	UObject::ProcessEvent(Func, &Parms);
}


// Function WIDGET_ButtonLegend_Icon.WIDGET_ButtonLegend_Icon_C.Construct
// (BlueprintCosmetic, Event, Public, BlueprintEvent)

void UWIDGET_ButtonLegend_Icon_C::Construct()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WIDGET_ButtonLegend_Icon_C", "Construct");

	UObject::ProcessEvent(Func, nullptr);
}


// Function WIDGET_ButtonLegend_Icon.WIDGET_ButtonLegend_Icon_C.PreConstruct
// (BlueprintCosmetic, Event, Public, BlueprintEvent)
// Parameters:
// bool                                    IsDesignTime                                           (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor)

void UWIDGET_ButtonLegend_Icon_C::PreConstruct(bool IsDesignTime)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WIDGET_ButtonLegend_Icon_C", "PreConstruct");

	Params::WIDGET_ButtonLegend_Icon_C_PreConstruct Parms{};

	Parms.IsDesignTime = IsDesignTime;

	UObject::ProcessEvent(Func, &Parms);
}


// Function WIDGET_ButtonLegend_Icon.WIDGET_ButtonLegend_Icon_C.UpdateActionButtonIconTextures
// (Public, BlueprintCallable, BlueprintEvent)

void UWIDGET_ButtonLegend_Icon_C::UpdateActionButtonIconTextures()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WIDGET_ButtonLegend_Icon_C", "UpdateActionButtonIconTextures");

	UObject::ProcessEvent(Func, nullptr);
}


// Function WIDGET_ButtonLegend_Icon.WIDGET_ButtonLegend_Icon_C.SetDisabled
// (Public, BlueprintCallable, BlueprintEvent)
// Parameters:
// bool                                    IsDisabled_0                                           (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor)

void UWIDGET_ButtonLegend_Icon_C::SetDisabled(bool IsDisabled_0)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WIDGET_ButtonLegend_Icon_C", "SetDisabled");

	Params::WIDGET_ButtonLegend_Icon_C_SetDisabled Parms{};

	Parms.IsDisabled_0 = IsDisabled_0;

	UObject::ProcessEvent(Func, &Parms);
}


// Function WIDGET_ButtonLegend_Icon.WIDGET_ButtonLegend_Icon_C.SetActionButtonIcon
// (Public, BlueprintCallable, BlueprintEvent)
// Parameters:
// int32                                   ButtonIconIndex                                        (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UWIDGET_ButtonLegend_Icon_C::SetActionButtonIcon(int32 ButtonIconIndex)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WIDGET_ButtonLegend_Icon_C", "SetActionButtonIcon");

	Params::WIDGET_ButtonLegend_Icon_C_SetActionButtonIcon Parms{};

	Parms.ButtonIconIndex = ButtonIconIndex;

	UObject::ProcessEvent(Func, &Parms);
}

}

