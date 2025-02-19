#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: OPTION_Audio_MasterVolume

#include "Basic.hpp"

#include "WIDGET_Settings_Slider_classes.hpp"


namespace SDK
{

// WidgetBlueprintGeneratedClass OPTION_Audio_MasterVolume.OPTION_Audio_MasterVolume_C
// 0x0000 (0x0398 - 0x0398)
class UOPTION_Audio_MasterVolume_C final : public UWIDGET_Settings_Slider_C
{
public:
	void ApplyDirtyValue();
	void OnSliderValueChanged(float NewValue);
	void ApplyCleanValue();
	void AcceptCurrentValue();
	void IsDirty(bool* Param_IsDirty_0);
	void UpdateVisuals();
	void SelectDefaultValue();
	void IsDefault(bool* Result);

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"OPTION_Audio_MasterVolume_C">();
	}
	static class UOPTION_Audio_MasterVolume_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<UOPTION_Audio_MasterVolume_C>();
	}
};
static_assert(alignof(UOPTION_Audio_MasterVolume_C) == 0x000008, "Wrong alignment on UOPTION_Audio_MasterVolume_C");
static_assert(sizeof(UOPTION_Audio_MasterVolume_C) == 0x000398, "Wrong size on UOPTION_Audio_MasterVolume_C");

}

