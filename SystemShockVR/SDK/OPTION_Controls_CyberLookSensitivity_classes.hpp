#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: OPTION_Controls_CyberLookSensitivity

#include "Basic.hpp"

#include "WIDGET_Settings_Slider_classes.hpp"


namespace SDK
{

// WidgetBlueprintGeneratedClass OPTION_Controls_CyberLookSensitivity.OPTION_Controls_CyberLookSensitivity_C
// 0x0000 (0x0398 - 0x0398)
class UOPTION_Controls_CyberLookSensitivity_C final : public UWIDGET_Settings_Slider_C
{
public:
	void AcceptCurrentValue();
	void ApplyDirtyValue();
	void ApplyCleanValue();
	void UpdateVisuals();
	void IsDirty(bool* Param_IsDirty_0);
	void OnSliderValueChanged(float NewValue);
	void SelectDefaultValue();
	void IsDefault(bool* Result);

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"OPTION_Controls_CyberLookSensitivity_C">();
	}
	static class UOPTION_Controls_CyberLookSensitivity_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<UOPTION_Controls_CyberLookSensitivity_C>();
	}
};
static_assert(alignof(UOPTION_Controls_CyberLookSensitivity_C) == 0x000008, "Wrong alignment on UOPTION_Controls_CyberLookSensitivity_C");
static_assert(sizeof(UOPTION_Controls_CyberLookSensitivity_C) == 0x000398, "Wrong size on UOPTION_Controls_CyberLookSensitivity_C");

}

