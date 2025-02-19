#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: WIDGET_SoftwarePanel

#include "Basic.hpp"

#include "WIDGET_SoftwarePanel_classes.hpp"
#include "WIDGET_SoftwarePanel_parameters.hpp"


namespace SDK
{

// Function WIDGET_SoftwarePanel.WIDGET_SoftwarePanel_C.InitializeSoftwarePanel
// (Public, HasDefaults, BlueprintCallable, BlueprintEvent)
// Parameters:
// class UWIDGET_PlayerHUD_C*              HUD                                                    (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UWIDGET_SoftwarePanel_C::InitializeSoftwarePanel(class UWIDGET_PlayerHUD_C* HUD)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WIDGET_SoftwarePanel_C", "InitializeSoftwarePanel");

	Params::WIDGET_SoftwarePanel_C_InitializeSoftwarePanel Parms{};

	Parms.HUD = HUD;

	UObject::ProcessEvent(Func, &Parms);
}


// Function WIDGET_SoftwarePanel.WIDGET_SoftwarePanel_C.SetSoftwarePanelVisibility
// (Public, BlueprintCallable, BlueprintEvent)
// Parameters:
// bool                                    Visible                                                (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor)

void UWIDGET_SoftwarePanel_C::SetSoftwarePanelVisibility(bool Visible)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WIDGET_SoftwarePanel_C", "SetSoftwarePanelVisibility");

	Params::WIDGET_SoftwarePanel_C_SetSoftwarePanelVisibility Parms{};

	Parms.Visible = Visible;

	UObject::ProcessEvent(Func, &Parms);
}


// Function WIDGET_SoftwarePanel.WIDGET_SoftwarePanel_C.EVENT_OnMouseMove
// (Public, HasOutParams, HasDefaults, BlueprintCallable, BlueprintEvent)
// Parameters:
// struct FGeometry                        MyGeometry                                             (BlueprintVisible, BlueprintReadOnly, Parm, IsPlainOldData, NoDestructor)
// struct FPointerEvent                    MouseEvent                                             (ConstParm, BlueprintVisible, BlueprintReadOnly, Parm, OutParm, ReferenceParm)
// struct FEventReply                      ReturnValue                                            (Parm, OutParm, ReturnParm)

struct FEventReply UWIDGET_SoftwarePanel_C::EVENT_OnMouseMove(const struct FGeometry& MyGeometry, const struct FPointerEvent& MouseEvent)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WIDGET_SoftwarePanel_C", "EVENT_OnMouseMove");

	Params::WIDGET_SoftwarePanel_C_EVENT_OnMouseMove Parms{};

	Parms.MyGeometry = std::move(MyGeometry);
	Parms.MouseEvent = std::move(MouseEvent);

	UObject::ProcessEvent(Func, &Parms);

	return Parms.ReturnValue;
}

}

