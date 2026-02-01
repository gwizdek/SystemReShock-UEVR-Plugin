#include "uevr/API.hpp"
#include "imgui/imgui.h"

#include "SDK/Niagara_classes.hpp"
#include "SDK/PAWN_Hacker_Implant_classes.hpp"
#include "SDK/WIDGET_PlayerHUD_classes.hpp"
#include "SDK/WIDGET_HotbarSlot_classes.hpp"
#include "SDK/COMP_MoveControlManager_classes.hpp"
#include "SDK/CH_Hacker_AnimBP_classes.hpp"

#include "SDK/_BI_VRWeapon_classes.hpp"
#include "SDK/_CH_Hacker_Rig_Skeleton_AnimBlueprint_classes.hpp"
#include "SDK/_BP_LaserDot_classes.hpp"
#include "SDK/_BP_ItemSelector_classes.hpp"

#include "vr_body.hpp"
#include "plugin_utils.hpp"

using namespace uevr;
using namespace SDK;

VRBody::VRBody(SystemShockMain* main) {
    m_main = main;
}

bool VRBody::is_valid() {
    return m_main != nullptr && UKismetSystemLibrary::IsValid(m_bp_actor);
}

void VRBody::on_tick() {
    try {
        if (!is_valid()) {
            API::get()->log_warn("[vr_body][on_tick] Invalid VRBody");
            return;
        }

        if (m_main->get_pawn() == nullptr || !m_main->get_pawn()->IsA(APAWN_Hacker_Implant_C::StaticClass())) {
            API::get()->log_warn("[vr_body][on_tick] Invalid Pawn");
            return;
        }
    }
    catch (...) {
        API::get()->log_error("[vrbody][on_tick] Exception");
    }
}

// disables / enables collisions on close to body meshes to prevent unwanted collisions with the widget interation component trace
void VRBody::set_player_response_to_collision_channel(ECollisionChannel channel, ECollisionResponse response) {
    try {
        if (m_main == nullptr) {
            return;
        }
        auto pawn = static_cast<APAWN_Hacker_Implant_C*>(m_main->get_pawn());
        if (pawn != nullptr) {
            pawn->CapsuleComponent->SetCollisionResponseToChannel(channel, response);
            pawn->Mesh->SetCollisionResponseToChannel(channel, response);
            pawn->ArmsMesh->SetCollisionResponseToChannel(channel, response);
            pawn->WeaponMesh->SetCollisionResponseToChannel(channel, response);
            //API::get()->log_warn("[vrbody][set_player_response_to_collision_channel] Hacker collision changed");
        }

        if (m_bp_actor != nullptr) {
            //API::get()->log_warn("[vrbody][set_player_response_to_collision_channel] VRBody collision changed");
            m_bp_actor->VRBodyMesh->SetCollisionResponseToChannel(channel, response);
        }
    }
    catch (...) {
        API::get()->log_error("[vrbody][set_player_response_to_collision_channel] Exception");
    }
}

void VRBody::set_player_response_to_all_collision_channels(ECollisionResponse response) {
    try {
        if (m_main == nullptr) {
            return;
        }
        auto pawn = static_cast<APAWN_Hacker_Implant_C*>(m_main->get_pawn());
        if (pawn != nullptr) {
            pawn->CapsuleComponent->SetCollisionResponseToAllChannels(response);
            pawn->Mesh->SetCollisionResponseToAllChannels(response);
            pawn->ArmsMesh->SetCollisionResponseToAllChannels(response);
            pawn->WeaponMesh->SetCollisionResponseToAllChannels(response);
            API::get()->log_warn("[vrbody][set_player_response_to_all_collision_channels] Hacker collision changed");
        }

        if (m_bp_actor != nullptr) {
            API::get()->log_warn("[vrbody][set_player_response_to_all_collision_channels] VRBody collision changed");
            m_bp_actor->VRBodyMesh->SetCollisionResponseToAllChannels(response);
        }
    }
    catch (...) {
        API::get()->log_error("[vrbody][set_player_response_to_all_collision_channels] Exception");
    }
}

// A_BP_VRBody_C class is loaded into memory by hard-referencing it in the modified ArmsMesh AnimBP
void VRBody::initialize() {
    try {
        API::get()->log_warn("[vrbody][initialize] Begin");

        cleanup_pointers();

        auto world = UWorld::GetWorld();

        if (!SDK::UKismetSystemLibrary::IsValid(m_main->get_pawn()) || !m_main->get_pawn()->IsA(APAWN_Hacker_Implant_C::StaticClass())) {
            API::get()->log_error("[vrbody][initialize] Invalid Pawn");
            return;
        }

        APAWN_Hacker_Implant_C* pawn = static_cast<APAWN_Hacker_Implant_C*>(m_main->get_pawn());

        const FVector pawn_location = pawn->K2_GetActorLocation();
        FTransform pawn_transform{};
        pawn_transform.Rotation = { 0.f, 0.f, 0.f, 1.f };
        pawn_transform.Translation = { pawn_location.X, pawn_location.Y, pawn_location.Z };
        pawn_transform.Scale3D = { 1.f, 1.f, 1.f };

        if (m_bp_actor != nullptr) {
            API::get()->log_error("[vrbody][initialize] Expected m_bp_actor to be cleaned up before spawning new actor");
            return;
        }

        API::get()->log_warn("[vrbody][initialize] Spawning VRBody BP actor");
        m_bp_actor = (A_BP_VRBody_C*)UGameplayStatics::BeginDeferredActorSpawnFromClass(
            world, A_BP_VRBody_C::StaticClass(), pawn_transform, ESpawnActorCollisionHandlingMethod::AlwaysSpawn, nullptr
        );
        if (m_bp_actor == nullptr) {
            API::get()->log_error("[vrbody][initialize] Error spawning VRBody BP Actor");
            return;
        }

        UGameplayStatics::FinishSpawningActor(m_bp_actor, pawn_transform);
        API::get()->log_warn("[vrbody][initialize] Finishied spawning VRBody BP Actor");

        TArray<FName> actor_tags{};
        actor_tags.Data = (FName*)API::FMalloc::get()->malloc(1 * sizeof(FName));
        actor_tags.NumElements = 1;
        actor_tags.MaxElements = 1;
        actor_tags.Data[0] = UKismetStringLibrary::Conv_StringToName(L"VRBodyActor");

        m_bp_actor->Tags = actor_tags;
        API::get()->log_warn("[vrbody][initialize] Added 'VRBodyActor' Tag");

        m_bp_actor->K2_AttachRootComponentTo(
            pawn->K2_GetRootComponent(),
            UKismetStringLibrary::Conv_StringToName(L"None"),
            EAttachLocation::SnapToTarget,
            true
        );

        FHitResult SweepHitResult{};
        // move vr actor down to the bottom of the collision capsule
        m_bp_actor->K2_GetRootComponent()->K2_SetRelativeLocation({ 0.0f, 0.0f, -80.0f }, false, &SweepHitResult, false);
        API::get()->log_warn("[vrbody][initialize] Attached to Hacker's root component");


        // HMDComponent tracks UEVR Camera offset to RootComponent (our VROrigin)
        auto hmd_state = API::UObjectHook::get_or_add_motion_controller_state((API::UObject*)m_bp_actor->HMDComponent);
        if (hmd_state == nullptr) {
            API::get()->log_error("[vrbody][initialize] Failed to hook HMD motion controller component");
            return;
        }
        hmd_state->set_hand(2);
        hmd_state->set_permanent(true);
        API::get()->log_warn("[vrbody][initialize] Hooked HMD motion controller component");


        // Re-Attach Hacker Hardware
        static_cast<APAWN_Hacker_Implant_C*>(pawn)->MediaReaderMesh->K2_AttachToComponent(
            m_bp_actor->VRBodyMesh,
            UKismetStringLibrary::Conv_StringToName(L"LeftForeArmRoll1"),
            EAttachmentRule::SnapToTarget,
            EAttachmentRule::KeepRelative,
            EAttachmentRule::KeepWorld,
            true
        );
        static_cast<APAWN_Hacker_Implant_C*>(pawn)->MediaReaderMesh->K2_SetRelativeLocationAndRotation(
            { 7.f, 3.f, 0.5f }, { 0.f, 3.f, 77.f }, false, &SweepHitResult, false
        );
        API::get()->log_warn("[vrbody][initialize] Attached Media Reader");

        initialize_main_item_selector();
        initialize_laser_dot();
        overwrite_hacker_crouch_animations();
    }
    catch (...) {
        API::get()->log_error("[vrbody][initialize] Exception");
    }
}

void VRBody::initialize_laser_dot() {
    API::get()->log_warn("[vrbody][initialize_laser_dot] Begin");
    if (m_bp_actor == nullptr) {
        API::get()->log_error("[vrbody][initialize_laser_dot] Invalid BP Actor");
        return;
    }

    FHitResult hit_result{};
    m_bp_actor->LaserDot->DrawDebugSphere = false;
    m_bp_actor->LaserDot->TraceChannel = ETraceTypeQuery::TraceTypeQuery3;
    m_bp_actor->LaserDot->RootComponent->K2_SetRelativeLocationAndRotation({ 0.f, 0.f, 0.f }, { 0.f, 0.f, 0.f }, false, &hit_result, false);


    //m_bp_actor->LaserDotComponent->K2_SetWorldLocation({ -63.f, 1850.f, 300.f }, false, &hit_result, false);
    ////m_bp_actor->LaserDotComponent->SetNiagaraVariableFloat(L"Power", 0.2f);

    //m_bp_actor->LaserDot->LaserDotComponent->Activate(true);
    m_bp_actor->LaserDot->LaserDotComponent->SetFloatParameter(UKismetStringLibrary::Conv_StringToName(L"Power"), 0.5f);
    m_bp_actor->LaserDot->LaserDotComponent->SetFloatParameter(UKismetStringLibrary::Conv_StringToName(L"Size"), 3.f);
    m_bp_actor->LaserDot->EnableTrace();

    m_bp_actor->LaserDot->LaserPointerComponent->SetFloatParameter(UKismetStringLibrary::Conv_StringToName(L"Power"), 0.1f);
    m_bp_actor->LaserDot->LaserPointerComponent->SetColorParameter(UKismetStringLibrary::Conv_StringToName(L"LaserColour"), { 0.3f, 0.f, 0.f, 1.f });
    m_bp_actor->LaserDot->LaserPointerComponent->SetColorParameter(UKismetStringLibrary::Conv_StringToName(L"PrimaryColor"), { 0.3f, 0.f, 0.f, 1.f });

    //PluginUtils::bytes_to_float("Power", 0, 0, 128, 63);
    //PluginUtils::bytes_to_float("Size", 0, 0, 192, 64);
}

void VRBody::initialize_main_item_selector() {
    try {
        API::get()->log_warn("[vrbody][initialize_main_item_selector] Initialize HotbarSlots");
        auto neural_hud = m_main->get_neural_hud();

        // get prepared in UE Editor hotbar slot array 
        auto hotbar_slots = m_bp_actor->ItemSelectorRight->HotbarSlots;

        // canvas panel slots 
        std::array<SDK::UCanvasPanelSlot*, 4> canvas_panel_slots{};

        API::get()->log_warn("[vrbody][initialize_main_item_selector] #0");
        for (int i = 0; i < 10; i++) {
            canvas_panel_slots[i] = (SDK::UCanvasPanelSlot*)neural_hud->HotbarSlots[i]->Slot;
            canvas_panel_slots[i]->SetAlignment({ 0.5f, 0.5f });
            canvas_panel_slots[i]->SetAnchors(SDK::FAnchors{ {0.5f, 0.5f}, {0.5f, 0.5f} });
            API::get()->log_warn("[vrbody][initialize_main_item_selector] #1 %d", i);

            hotbar_slots[i]->SetWidget(neural_hud->HotbarSlots[i]);
    
            API::get()->log_warn("[vrbody][initialize_main_item_selector] #2");
            // 150.f seems to be the correct size
            hotbar_slots[i]->SetDrawSize({ 100.0f, 104.0f });
            hotbar_slots[i]->SetVisibility(false, false);
            hotbar_slots[i]->SetHiddenInGame(true, true);

            API::get()->log_warn("[vrbody][initialize_main_item_selector] #3");
            // set properties for collision detection
            hotbar_slots[i]->SetWidgetSpace(SDK::EWidgetSpace::World);
            hotbar_slots[i]->SetCollisionEnabled(SDK::ECollisionEnabled::QueryOnly);
            hotbar_slots[i]->SetCollisionObjectType(item_selector_collision_channel);
            hotbar_slots[i]->SetCollisionResponseToAllChannels(SDK::ECollisionResponse::ECR_Ignore);
            //hotbar_slots[i]->SetCollisionResponseToChannel(
            //    item_selector_collision_channel, SDK::ECollisionResponse::ECR_Block
            //);
            API::get()->log_warn("[vrbody][initialize_main_item_selector] #4");
            canvas_panel_slots[i]->SetAlignment({ 0.5f, 1.f });
            canvas_panel_slots[i]->SetAnchors(SDK::FAnchors{ {0.5f, 1.f}, {0.5f, 1.f} });

            auto material = API::get()->find_uobject<SDK::UMaterialInstanceConstant>(
                L"MaterialInstanceConstant /Engine/EngineMaterials/Widget3DPassThrough_Translucent.Widget3DPassThrough_Translucent"
                //L"MaterialInstanceConstant /Engine/EngineMaterials/Widget3DPassThrough_Opaque.Widget3DPassThrough_Opaque"
            );
            SDK::FLinearColor color{ 0.1f, 0.1f, 0.1f, 1.0f };
            hotbar_slots[i]->SetMaterial(0, material);
            hotbar_slots[i]->SetTintColorAndOpacity(color);

            neural_hud->HotbarSlots[i]->UpdateHotbarSlot();

            set_primary_item_selector_visibility(false);
            API::get()->log_warn("[vrbody][initialize_main_item_selector] #5");
        }

        API::get()->log_warn("[vrbody][initialize_main_item_selector] Initialized HotbarSlots");


        m_bp_actor->WidgetInteractionRight->VirtualUserIndex = 99;
        m_bp_actor->WidgetInteractionRight->PointerIndex = 99;
        m_bp_actor->WidgetInteractionRight->TraceChannel = item_selector_collision_channel;
        m_bp_actor->WidgetInteractionRight->InteractionDistance = 300.0f;
        m_bp_actor->WidgetInteractionRight->InteractionSource = SDK::EWidgetInteractionSource::World;
        m_bp_actor->WidgetInteractionRight->bEnableHitTesting = true;
        //m_bp_actor->WidgetInteractionRight->SetVisibility(false, false);
        //m_bp_actor->WidgetInteractionRight->SetHiddenInGame(true, true);


    }
    catch (...) {
        API::get()->log_error("[vrbody][initialize] Exception");
    }
}

void VRBody::set_hotbar_slot_visibility(int slot, bool visible) {
    //m_hotbar_slots[slot]->SetVisibility(visible ? SDK::ESlateVisibility::Visible : SDK::ESlateVisibility::Hidden);
    m_bp_actor->ItemSelectorRight->HotbarSlots[slot]->SetVisibility(visible, true);
    m_bp_actor->ItemSelectorRight->HotbarSlots[slot]->SetHiddenInGame(!visible, true);
}

// highlights selected item
void VRBody::highlight_quick_slot() {
    //API::get()->log_warn("[vrbody][highlight_quick_slot] Begin");
    m_highlighted_widget_component.set_value(m_bp_actor->WidgetInteractionRight->GetHoveredWidgetComponent());

    if (m_highlighted_widget_component.has_changed()) {
        // highlight current selected slot
        if (m_highlighted_widget_component.value != nullptr) {
            auto widget = m_highlighted_widget_component.value->GetWidget();
            if (widget != nullptr && widget->IsA(SDK::UWIDGET_HotbarSlot_C::StaticClass())) {
                static_cast<SDK::UWIDGET_HotbarSlot_C*>(widget)->SetIsCurrentQuickSlot(true);
            }
        }

        // remove highlight from previous slot
        if (m_highlighted_widget_component.prev_value != nullptr) {
            auto prev_widget = m_highlighted_widget_component.prev_value->GetWidget();
            if (prev_widget != nullptr && prev_widget->IsA(SDK::UWIDGET_HotbarSlot_C::StaticClass())) {
                static_cast<SDK::UWIDGET_HotbarSlot_C*>(prev_widget)->SetIsCurrentQuickSlot(false);
            }
        }
    }
    //API::get()->log_warn("[vrbody][highlight_quick_slot] End");
}

// change active hotbar slot
void VRBody::change_quick_slot() {
    if (!m_main->get_pawn()->IsA(SDK::APAWN_Hacker_Implant_C::StaticClass())) {
        return;
    }

    if (m_highlighted_widget_component.value != nullptr) {
        auto widget = m_highlighted_widget_component.value->GetWidget();
        if (widget != nullptr && widget->IsA(SDK::UWIDGET_HotbarSlot_C::StaticClass())) {
            SDK::int32 slot_index;
            static_cast<SDK::UWIDGET_HotbarSlot_C*>(widget)->GetSlotIndex(&slot_index);

            static_cast<SDK::APAWN_Hacker_Implant_C*>(m_main->get_pawn())->ReceiveInputForHotbarSlotByIndex(
                slot_index + 1, true
            );
        }
    }
    else {
        auto pawn = static_cast<APAWN_Hacker_Implant_C*>(m_main->get_pawn());
        SDK::FKey h_key_name{
            .KeyName = SDK::UKismetStringLibrary::Conv_StringToName(L"H")
        };

        // holster weapon
        pawn->InpActEvt_Real_ToggleEquip_K2Node_InputActionEvent_24(h_key_name);
    }
}

void VRBody::set_primary_item_selector_visibility(bool visible) {
    APAWN_Hacker_Implant_C* hacker_implant_pawn = static_cast<APAWN_Hacker_Implant_C*>(m_main->get_pawn());

    hacker_implant_pawn->WeaponMesh->SetVisibility(!visible, true);

    for (int i = 0; i < 10; i++) {
        if (m_bp_actor->ItemSelectorRight->HotbarSlots[i] != nullptr) {
            m_bp_actor->ItemSelectorRight->HotbarSlots[i]->SetVisibility(visible, true);
            m_bp_actor->ItemSelectorRight->HotbarSlots[i]->SetHiddenInGame(!visible, true);

            m_bp_actor->ItemSelectorRight->HotbarSlots[i]->SetCollisionResponseToChannel(
                item_selector_collision_channel, visible ? SDK::ECollisionResponse::ECR_Block : SDK::ECollisionResponse::ECR_Ignore
            );

            //m_bp_actor->ItemSelectorRight->HotbarSlots[i]->SetCollisionResponseToAllChannels(
            //    visible ? SDK::ECollisionResponse::ECR_Block : SDK::ECollisionResponse::ECR_Ignore
            //);
        }
    }
}

void VRBody::unselect_all_hotbar_slots() {
    try {
        //API::get()->log_warn("[vrbody][unselect_all_hotbar_slots] Begin");
        if (m_main == nullptr || m_main->get_neural_hud() == nullptr)
            return;

        for (int i = 0; i < 10; i++) {
            m_main->get_neural_hud()->HotbarSlots[i]->SetIsCurrentQuickSlot(false);
        }
        //API::get()->log_warn("[vrbody][unselect_all_hotbar_slots] End");
    }
    catch (...) {
        API::get()->log_error("[vrbody][unselect_all_hotbar_slots] Exception");
    }
}

void VRBody::overwrite_hacker_crouch_animations() {
    API::get()->log_warn("[vrbody][override_hacker_walk_animations] Start");

    if (!SDK::UKismetSystemLibrary::IsValid(m_main->get_pawn()) || !m_main->get_pawn()->IsA(APAWN_Hacker_Implant_C::StaticClass())) {
        API::get()->log_error("[vrbody][overwrite_hacker_crouch_animations] Invalid Pawn");
        return;
    }
    APAWN_Hacker_Implant_C* hacker_implant_pawn = static_cast<APAWN_Hacker_Implant_C*>(m_main->get_pawn());
 
    SDK::UCH_Hacker_AnimBP_C* hacker_anim = (SDK::UCH_Hacker_AnimBP_C*) hacker_implant_pawn->Mesh->AnimScriptInstance;
    if (hacker_anim != nullptr) {
        // make crouch animations use walk animations
        hacker_anim->AnimGraphNode_SequencePlayer_8.Sequence = hacker_anim->AnimGraphNode_SequencePlayer_7.Sequence;
        hacker_anim->AnimGraphNode_SequenceEvaluator_5.Sequence = hacker_anim->AnimGraphNode_SequenceEvaluator_2.Sequence;
        hacker_anim->AnimGraphNode_SequenceEvaluator_6.Sequence = hacker_anim->AnimGraphNode_SequenceEvaluator_1.Sequence;
        hacker_anim->AnimGraphNode_SequenceEvaluator_11.Sequence = hacker_anim->AnimGraphNode_SequenceEvaluator_8.Sequence;
        hacker_anim->AnimGraphNode_SequenceEvaluator_12.Sequence = hacker_anim->AnimGraphNode_SequenceEvaluator_7.Sequence;
    }
}

void VRBody::cleanup_pointers() {
    API::get()->log_warn("[vrbody][cleanup_pointers] Cleanup");
    m_bp_actor = nullptr;
    m_highlighted_widget_component.reset(nullptr);
}

void VRBody::cleanup_actors() {
    try {
        auto world = UWorld::GetWorld();
        if (!UKismetSystemLibrary::IsValid(world)) {
            API::get()->log_error("[vrbody][cleanup_actors] World invalid");
            return;
        }

        PluginUtils::destroy_actors_by_tag(world, UKismetStringLibrary::Conv_StringToName(L"VRBodyActor"));
    }
    catch (...) {
        API::get()->log_error("[vrbody][cleanup_actors] Exception");
    }
}

void VRBody::on_draw_imgui() {
    try {
        if (is_valid()) {
            ImGui::SeparatorText("VR Body");
            // game state section

            ImGui::BeginGroup();
            ImGui::BeginDisabled();

            //ImGui::InputFloat3("TraceStartOffset", m_trace_start_offset);
            //ImGui::InputFloat("LaserPower", &m_laser_power);
            //ImGui::InputFloat("Occlusion", &m_occlusion_sample_diameter);
            //ImGui::InputFloat("Alpha", &m_alpha);

            //float m_laser_power{ -1.f };
            //float m_occlusion_sample_diameter{ -1.f };
            //float m_alpha{ -1.f };

            ImGui::EndDisabled();
            ImGui::EndGroup();

            //if (m_vr_weapon->is_valid()) {
            //    m_vr_weapon->on_draw_imgui();
            //}
        }
    }
    catch (...) {
        API::get()->log_error("[vrbody][on_draw_imgui] Exception");
    }
}
