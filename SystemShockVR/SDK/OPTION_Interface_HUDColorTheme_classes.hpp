#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: OPTION_Interface_HUDColorTheme

#include "Basic.hpp"

#include "WIDGET_Settings_MultiSelector_classes.hpp"


namespace SDK
{

// WidgetBlueprintGeneratedClass OPTION_Interface_HUDColorTheme.OPTION_Interface_HUDColorTheme_C
// 0x0018 (0x03C8 - 0x03B0)
class UOPTION_Interface_HUDColorTheme_C final : public UWIDGET_Settings_MultiSelector_C
{
public:
	class UDataTable*                             UserTintOptionsDataTable;                          // 0x03B0(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	TArray<class FName>                           UserTintNames;                                     // 0x03B8(0x0010)(Edit, BlueprintVisible, DisableEditOnInstance)

public:
	void PopulateUniqueSettings();
	void AcceptCurrentValue();
	void ApplyDirtyValue();
	void IsDirty(bool* Param_IsDirty_0);
	void UpdateVisuals();
	void ApplyCleanValue();
	void SelectDefaultValue();
	void IsDefault(bool* Result);
	void OnMultiSelectorValueModifiedByUser();

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"OPTION_Interface_HUDColorTheme_C">();
	}
	static class UOPTION_Interface_HUDColorTheme_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<UOPTION_Interface_HUDColorTheme_C>();
	}
};
static_assert(alignof(UOPTION_Interface_HUDColorTheme_C) == 0x000008, "Wrong alignment on UOPTION_Interface_HUDColorTheme_C");
static_assert(sizeof(UOPTION_Interface_HUDColorTheme_C) == 0x0003C8, "Wrong size on UOPTION_Interface_HUDColorTheme_C");
static_assert(offsetof(UOPTION_Interface_HUDColorTheme_C, UserTintOptionsDataTable) == 0x0003B0, "Member 'UOPTION_Interface_HUDColorTheme_C::UserTintOptionsDataTable' has a wrong offset!");
static_assert(offsetof(UOPTION_Interface_HUDColorTheme_C, UserTintNames) == 0x0003B8, "Member 'UOPTION_Interface_HUDColorTheme_C::UserTintNames' has a wrong offset!");

}

