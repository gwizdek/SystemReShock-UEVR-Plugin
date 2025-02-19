#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: WIDGET_EndDemoScreen

#include "Basic.hpp"

#include "Engine_structs.hpp"
#include "UMG_classes.hpp"


namespace SDK
{

// WidgetBlueprintGeneratedClass WIDGET_EndDemoScreen.WIDGET_EndGameScreen_C
// 0x0050 (0x02B0 - 0x0260)
class UWIDGET_EndGameScreen_C final : public UUserWidget
{
public:
	struct FPointerToUberGraphFrame               UberGraphFrame;                                    // 0x0260(0x0008)(ZeroConstructor, Transient, DuplicateTransient)
	class UWidgetAnimation*                       FadeOutBlack;                                      // 0x0268(0x0008)(BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Transient, IsPlainOldData, RepSkip, NoDestructor, HasGetValueTypeHash)
	class UImage*                                 BlackFadeImage;                                    // 0x0270(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UImage*                                 CitadelMovie;                                      // 0x0278(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UImage*                                 NightDive;                                         // 0x0280(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UImage*                                 SystemShock;                                       // 0x0288(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UTextBlock*                             TEXT_PressAnyKey;                                  // 0x0290(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UTextBlock*                             TEXT_ThanksForPlaying;                             // 0x0298(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UCanvasPanel*                           TextCanvas;                                        // 0x02A0(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UMediaPlayer*                           CitadelMediaPlayer;                                // 0x02A8(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

public:
	void ExecuteUbergraph_WIDGET_EndGameScreen(int32 EntryPoint);
	void Tick(const struct FGeometry& MyGeometry, float InDeltaTime);
	void Construct();
	void OpenEndCard();
	void EVENT_QuitGame();
	void PlayEndCard();
	struct FEventReply OnKeyDown(const struct FGeometry& MyGeometry, const struct FKeyEvent& InKeyEvent);

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"WIDGET_EndGameScreen_C">();
	}
	static class UWIDGET_EndGameScreen_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<UWIDGET_EndGameScreen_C>();
	}
};
static_assert(alignof(UWIDGET_EndGameScreen_C) == 0x000008, "Wrong alignment on UWIDGET_EndGameScreen_C");
static_assert(sizeof(UWIDGET_EndGameScreen_C) == 0x0002B0, "Wrong size on UWIDGET_EndGameScreen_C");
static_assert(offsetof(UWIDGET_EndGameScreen_C, UberGraphFrame) == 0x000260, "Member 'UWIDGET_EndGameScreen_C::UberGraphFrame' has a wrong offset!");
static_assert(offsetof(UWIDGET_EndGameScreen_C, FadeOutBlack) == 0x000268, "Member 'UWIDGET_EndGameScreen_C::FadeOutBlack' has a wrong offset!");
static_assert(offsetof(UWIDGET_EndGameScreen_C, BlackFadeImage) == 0x000270, "Member 'UWIDGET_EndGameScreen_C::BlackFadeImage' has a wrong offset!");
static_assert(offsetof(UWIDGET_EndGameScreen_C, CitadelMovie) == 0x000278, "Member 'UWIDGET_EndGameScreen_C::CitadelMovie' has a wrong offset!");
static_assert(offsetof(UWIDGET_EndGameScreen_C, NightDive) == 0x000280, "Member 'UWIDGET_EndGameScreen_C::NightDive' has a wrong offset!");
static_assert(offsetof(UWIDGET_EndGameScreen_C, SystemShock) == 0x000288, "Member 'UWIDGET_EndGameScreen_C::SystemShock' has a wrong offset!");
static_assert(offsetof(UWIDGET_EndGameScreen_C, TEXT_PressAnyKey) == 0x000290, "Member 'UWIDGET_EndGameScreen_C::TEXT_PressAnyKey' has a wrong offset!");
static_assert(offsetof(UWIDGET_EndGameScreen_C, TEXT_ThanksForPlaying) == 0x000298, "Member 'UWIDGET_EndGameScreen_C::TEXT_ThanksForPlaying' has a wrong offset!");
static_assert(offsetof(UWIDGET_EndGameScreen_C, TextCanvas) == 0x0002A0, "Member 'UWIDGET_EndGameScreen_C::TextCanvas' has a wrong offset!");
static_assert(offsetof(UWIDGET_EndGameScreen_C, CitadelMediaPlayer) == 0x0002A8, "Member 'UWIDGET_EndGameScreen_C::CitadelMediaPlayer' has a wrong offset!");

}

