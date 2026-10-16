#pragma once

namespace SDK
{
class A_BP_VRBody_C;
class USceneComponent;
class UWorld;
}

// Makes the tutorial popups follow the head instead of the right hand.
//
// WIDGET_TutorialMessage::UpdateRenderOpacity shows a popup only while its target actor is in
// front of the view: PAWN_Hacker_Simple::IsTutorialActorVisible passes when the pitch is below
// 25 degrees and the yaw below 40 degrees, and GetHighestPriorityTutorial picks the active
// tutorial with the smallest angle. Both measure from the pawn's PlayerCamera:
// GetAngleToTutorialActor and GetPitchYawToTutorialActor read its forward vector, right vector
// and location. The mod attaches PlayerCamera to the right motion controller, so the hand
// decided which popup shows.
//
// The plugin keeps a scene component of its own, rooted so it lives for the whole session, and
// copies the world transform of _BP_VRBody.HMDComponent onto it every tick (PlayerCamera's when
// there is no VR body, which is the game's own behaviour). In the two functions it replaces
// each "Context(InstanceVariable PlayerCamera)" with "Context(ObjectConst <that component>)";
// both object expressions are 9 bytes. PlayerCamera itself stays on the hand. The component
// is not one of the VR body, because the VR body is spawned again on every level load and the
// bytecode would then point at a destroyed object. After a plugin swap by the hot loader, the
// new plugin finds the component in the patched bytecode and keeps using it.
class TutorialHeadView final
{
public:
    // Called once per engine tick, on the game thread.
    static void handle(SDK::UWorld* world, SDK::A_BP_VRBody_C* vr_body);

private:
    static void follow_view(SDK::UWorld* world, SDK::A_BP_VRBody_C* vr_body);
    static bool ensure_proxy();
    static void patch_all();
    static int patch(const wchar_t* function_name);

    static SDK::USceneComponent* s_proxy;
    static bool s_failed;
    static int s_ticks_until_check;
};
