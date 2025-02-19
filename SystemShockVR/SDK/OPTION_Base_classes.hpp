#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: OPTION_Base

#include "Basic.hpp"

#include "WIDGET_MenuListItemBase_classes.hpp"


namespace SDK
{

// WidgetBlueprintGeneratedClass OPTION_Base.OPTION_Base_C
// 0x0028 (0x0338 - 0x0310)
class UOPTION_Base_C : public UWIDGET_MenuListItemBase_C
{
public:
	bool                                          IsMutator;                                         // 0x0310(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor)
	bool                                          ShowExampleImage;                                  // 0x0311(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_312[0x6];                                      // 0x0312(0x0006)(Fixing Size After Last Property [ Dumper-7 ])
	TArray<TSoftObjectPtr<class UTexture2D>>      ExampleImagesArray;                                // 0x0318(0x0010)(Edit, BlueprintVisible)
	FMulticastInlineDelegateProperty_             OnOptionChanged;                                   // 0x0328(0x0010)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, BlueprintAssignable, BlueprintCallable)

public:
	void OnOptionChanged__DelegateSignature();
	void ApplyDirtyValue();
	void ApplyCleanValue();
	void IsDirty(bool* IsDirty_0);
	void SaveNewValue();
	void AcceptCurrentValue();
	void UpdateVisuals();
	void SelectDefaultValue();
	void SetOptionEnabled(bool IsOptionEnabled, bool* Result);
	void GetPreviousSavedValue();
	void ShowDirtyIcon();
	void GetSaveSettings(class USAVE_Settings_C** ShockSettings);
	void InitializeMenuListItem(class UWIDGET_MenuListBase_C* ParentList, int32 Index_0);
	void IsDefault(bool* Result);

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"OPTION_Base_C">();
	}
	static class UOPTION_Base_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<UOPTION_Base_C>();
	}
};
static_assert(alignof(UOPTION_Base_C) == 0x000008, "Wrong alignment on UOPTION_Base_C");
static_assert(sizeof(UOPTION_Base_C) == 0x000338, "Wrong size on UOPTION_Base_C");
static_assert(offsetof(UOPTION_Base_C, IsMutator) == 0x000310, "Member 'UOPTION_Base_C::IsMutator' has a wrong offset!");
static_assert(offsetof(UOPTION_Base_C, ShowExampleImage) == 0x000311, "Member 'UOPTION_Base_C::ShowExampleImage' has a wrong offset!");
static_assert(offsetof(UOPTION_Base_C, ExampleImagesArray) == 0x000318, "Member 'UOPTION_Base_C::ExampleImagesArray' has a wrong offset!");
static_assert(offsetof(UOPTION_Base_C, OnOptionChanged) == 0x000328, "Member 'UOPTION_Base_C::OnOptionChanged' has a wrong offset!");

}

