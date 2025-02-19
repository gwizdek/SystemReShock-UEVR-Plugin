#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: WIDGET_SplashScreen_NightDive

#include "Basic.hpp"

#include "UMG_classes.hpp"


namespace SDK
{

// WidgetBlueprintGeneratedClass WIDGET_SplashScreen_NightDive.WIDGET_SplashScreen_NightDive_C
// 0x0028 (0x0288 - 0x0260)
class UWIDGET_SplashScreen_NightDive_C final : public UUserWidget
{
public:
	class UWidgetAnimation*                       NightDiveDistortion;                               // 0x0260(0x0008)(BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Transient, IsPlainOldData, RepSkip, NoDestructor, HasGetValueTypeHash)
	class UImage*                                 Black;                                             // 0x0268(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UImage*                                 IMAGE_NDSBumper;                                   // 0x0270(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UMediaPlayer*                           MediaPlayer;                                       // 0x0278(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UMediaSoundComponent*                   MediaSound;                                        // 0x0280(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

public:
	void GetFadeOutDuration(float* Duration);
	void GetSplashDuration(float* Duration);
	void GetFadeInDuration(float* Duration);
	void CanSkipSplash(bool* Result);
	void CanSkipFadeIn(bool* Result);
	void UpdateFadeIn(float Progress, bool* Result);
	void UpdateSplash(float Progress, bool* Result);
	void UpdateFadeOut(float Progress, bool* Result);
	void SetPreGameScreen(class UWIDGET_PreGameScreen_C* PreGameScreen, bool* Result);
	void OnSplashVisible(bool* Result);
	void OnSplashHidden(bool* Result);

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"WIDGET_SplashScreen_NightDive_C">();
	}
	static class UWIDGET_SplashScreen_NightDive_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<UWIDGET_SplashScreen_NightDive_C>();
	}
};
static_assert(alignof(UWIDGET_SplashScreen_NightDive_C) == 0x000008, "Wrong alignment on UWIDGET_SplashScreen_NightDive_C");
static_assert(sizeof(UWIDGET_SplashScreen_NightDive_C) == 0x000288, "Wrong size on UWIDGET_SplashScreen_NightDive_C");
static_assert(offsetof(UWIDGET_SplashScreen_NightDive_C, NightDiveDistortion) == 0x000260, "Member 'UWIDGET_SplashScreen_NightDive_C::NightDiveDistortion' has a wrong offset!");
static_assert(offsetof(UWIDGET_SplashScreen_NightDive_C, Black) == 0x000268, "Member 'UWIDGET_SplashScreen_NightDive_C::Black' has a wrong offset!");
static_assert(offsetof(UWIDGET_SplashScreen_NightDive_C, IMAGE_NDSBumper) == 0x000270, "Member 'UWIDGET_SplashScreen_NightDive_C::IMAGE_NDSBumper' has a wrong offset!");
static_assert(offsetof(UWIDGET_SplashScreen_NightDive_C, MediaPlayer) == 0x000278, "Member 'UWIDGET_SplashScreen_NightDive_C::MediaPlayer' has a wrong offset!");
static_assert(offsetof(UWIDGET_SplashScreen_NightDive_C, MediaSound) == 0x000280, "Member 'UWIDGET_SplashScreen_NightDive_C::MediaSound' has a wrong offset!");

}

