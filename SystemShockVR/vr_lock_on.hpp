#pragma once

namespace SDK
{
    class A_BP_VRAvatar_C;
    class APAWN_Avatar_C;
    class UUserWidget;
    class UWIDGET_CyberspaceHUD_C;
    class UWidgetComponent;
    struct FRotator;
    struct FVector;
}

// Shows the I.C.E. drill lock-on (WIDGET_IceDrillLockOn) in the world, on the aim line, instead
// of at the centre of the HUD. See "Drill lock-on" in documentation/cyberspace-controls.md.
//
// The HUD keeps the lock-on at the screen centre, which in VR is where the head looks, while
// the drill aims with the right controller. The plugin adds a widget component to the VR
// avatar and moves the HUD's own lock-on widget into it, so the game's code keeps driving the
// same widget: its states, animations and sounds. VRAvatar places the component with the aim
// reticle every tick, at a fixed part of the reticle's world units per pixel, so it grows and
// shrinks with the reticle. Back in the HUD it goes when the VR avatar is removed.
class VRLockOn final
{
public:
    // Adds the component to the VR avatar and moves the HUD's lock-on widget into it.
    static void attach(SDK::A_BP_VRAvatar_C* vr_avatar, SDK::APAWN_Avatar_C* pawn);
    // Every tick, from VRAvatar::place_reticle: where the reticle is and its scale.
    static void place(const SDK::FVector& location, const SDK::FRotator& rotation, float scale);
    // Moves the lock-on widget back into the HUD, at the screen centre.
    static void restore();

private:
    static SDK::UWidgetComponent* create_component(SDK::A_BP_VRAvatar_C* vr_avatar);

    static SDK::UWidgetComponent* s_component;
    static SDK::UUserWidget* s_widget;
    static SDK::UWIDGET_CyberspaceHUD_C* s_hud;
};
