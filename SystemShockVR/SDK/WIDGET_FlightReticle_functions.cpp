#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: WIDGET_FlightReticle

#include "Basic.hpp"

#include "WIDGET_FlightReticle_classes.hpp"
#include "WIDGET_FlightReticle_parameters.hpp"


namespace SDK
{

// Function WIDGET_FlightReticle.WIDGET_FlightReticle_C.RotateUpward
// (Public, BlueprintCallable, BlueprintEvent)

void UWIDGET_FlightReticle_C::RotateUpward()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WIDGET_FlightReticle_C", "RotateUpward");

	UObject::ProcessEvent(Func, nullptr);
}

}

