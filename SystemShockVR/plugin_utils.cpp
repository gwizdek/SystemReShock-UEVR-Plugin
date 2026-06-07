#include "SDK/AssetRegistry_classes.hpp"
#include "SDK/UMG_classes.hpp"

#include "plugin_utils.hpp"

using namespace uevr;

void PluginUtils::reset_height(float offset_y) {
    const UEVR_VRData* vr = API::get()->param()->vr;
    UEVR_Vector3f origin{};
    vr->get_standing_origin(&origin);

    UEVR_Vector3f hmd_pos{};
    UEVR_Quaternionf hmd_rot{};
    vr->get_pose(vr->get_hmd_index(), &hmd_pos, &hmd_rot);

    origin.y = (hmd_pos.y) + offset_y;

    vr->set_standing_origin(&origin);
}

SDK::AActor* PluginUtils::spawn_actor(SDK::UWorld* world, SDK::FTransform transform, std::wstring actor_tag) {
    try {
        if (world == nullptr) {
            API::get()->log_error("[plugin_utils][spawn_actor] Invalid world pointer");
            return nullptr;
        }

        SDK::AActor* actor = SDK::UGameplayStatics::BeginDeferredActorSpawnFromClass(
            world, SDK::AActor::StaticClass(), transform, SDK::ESpawnActorCollisionHandlingMethod::AlwaysSpawn, nullptr
        );
        if (actor == nullptr) {
            API::get()->log_error("[plugin_utils][spawn_actor] Error spawning actor");
            return nullptr;
        }

        SDK::UGameplayStatics::FinishSpawningActor(actor, transform);

        SDK::TArray<SDK::FName> actor_tags{};
        actor_tags.Data = (SDK::FName*)API::FMalloc::get()->malloc(1 * sizeof(SDK::FName));
        actor_tags.NumElements = 1;
        actor_tags.MaxElements = 1;
        actor_tags.Data[0] = SDK::UKismetStringLibrary::Conv_StringToName(actor_tag.c_str());

        actor->Tags = actor_tags;

        API::get()->log_warn("[plugin_utils][spawn_actor] Spawned actor %ls", actor_tag.c_str());
        return actor;
    }
    catch (...) {
        API::get()->log_error("[plugin_utils][spawn_actor] Exception");
        return nullptr;
    }
}

// this function tries to find and destroy actors we created for attachments, even when we no longer have pointers to them
void PluginUtils::destroy_actors_by_tag(SDK::UWorld* world, SDK::FName actor_tag) {
    try {
        API::get()->log_warn("[plugin_utils][destroy_actors_by_tag] Cleaning up stale %s Actors", actor_tag.GetRawString().c_str());

        if (world == nullptr || !SDK::UKismetSystemLibrary::IsValid(world)) {
            API::get()->log_warn("[plugin_utils][destroy_actors_by_tag] Invalid World object");
            return;
        }

        SDK::TArray<SDK::AActor*> actors_to_destroy{};
        actors_to_destroy.Data = (SDK::AActor**)API::FMalloc::get()->malloc(16 * sizeof(SDK::AActor*));
        actors_to_destroy.NumElements = 0;
        actors_to_destroy.MaxElements = 16;

        SDK::UGameplayStatics::GetAllActorsOfClassWithTag(world, SDK::AActor::StaticClass(), actor_tag, &actors_to_destroy);

        API::get()->log_warn("[plugin_utils][destroy_actors_by_tag] Found %d Actors to Destroy", actors_to_destroy.Num());

        // destroying actors
        for (UC::int32 i = 0; i < actors_to_destroy.Num(); i++) {
            if (actors_to_destroy[i] != nullptr && SDK::UKismetSystemLibrary::IsValid(actors_to_destroy[i]) && actors_to_destroy[i]->IsA(SDK::AActor::StaticClass())) {
                static_cast<SDK::AActor*>(actors_to_destroy[i])->K2_DestroyActor();
                API::get()->log_warn("[plugin_utils][destroy_actors_by_tag] Destroyed Actor %s", actor_tag.GetRawString().c_str());
            }
        }

        return;
    }
    catch (...) {
        API::get()->log_error("[plugin_utils][destroy_actors_by_tag] Exception");
        return;
    }
}

// this function tries to find and destroy class actors we created for attachments, even when we no longer have pointers to them
void PluginUtils::destroy_actors_by_class(SDK::UWorld* world, SDK::UClass* actor_class) {
    try {
        API::get()->log_warn("[plugin_utils][destroy_actors_by_class] Cleaning up stale %s Class Actors", actor_class->GetName().c_str());

        if (world == nullptr || !SDK::UKismetSystemLibrary::IsValid(world)) {
            API::get()->log_warn("[plugin_utils][destroy_actors_by_class] Invalid World object");
            return;
        }

        SDK::TArray<SDK::AActor*> actors_to_destroy{};
        actors_to_destroy.Data = (SDK::AActor**)API::FMalloc::get()->malloc(16 * sizeof(SDK::AActor*));
        actors_to_destroy.NumElements = 0;
        actors_to_destroy.MaxElements = 16;

        SDK::UGameplayStatics::GetAllActorsOfClass(world, actor_class, &actors_to_destroy);

        API::get()->log_warn("[plugin_utils][destroy_actors_by_class] Found %d Actors to Destroy", actors_to_destroy.Num());

        // destroying actors
        for (UC::int32 i = 0; i < actors_to_destroy.Num(); i++) {
            if (actors_to_destroy[i] != nullptr && SDK::UKismetSystemLibrary::IsValid(actors_to_destroy[i]) && actors_to_destroy[i]->IsA(SDK::AActor::StaticClass())) {
                static_cast<SDK::AActor*>(actors_to_destroy[i])->K2_DestroyActor();
                API::get()->log_warn("[plugin_utils][destroy_actors_by_class] Destroyed Class Actor %s", actor_class->GetName().c_str());
            }
        }

        return;
    }
    catch (...) {
        API::get()->log_error("[plugin_utils][destroy_actors_by_class] Exception");
        return;
    }
}

// finds every actor in the world, then forces all UPrimitiveComponents whose world location is within
// 'range' (unreal units) of 'origin' to be rendered (Visibility = true, HiddenInGame = false).
// useful for debugging hidden/invisible geometry near a point of interest (e.g. the player's hand).
// the player's character pawn is skipped unless include_pawn is true.
void PluginUtils::show_all_primitive_components(SDK::UWorld* world, SDK::USceneComponent* origin, float range, bool include_pawn) {
    try {
        if (world == nullptr || !SDK::UKismetSystemLibrary::IsValid(world)) {
            API::get()->log_warn("[plugin_utils][show_all_primitive_components] Invalid World object");
            return;
        }

        if (origin == nullptr || !SDK::UKismetSystemLibrary::IsValid(origin)) {
            API::get()->log_warn("[plugin_utils][show_all_primitive_components] Invalid origin component");
            return;
        }

        const SDK::FVector origin_loc = origin->K2_GetComponentLocation();
        const float range_sq = range * range;

        // unless the caller opts in, skip the player's character pawn so we don't reveal its body components
        SDK::APawn* player_pawn = include_pawn ? nullptr : SDK::UGameplayStatics::GetPlayerPawn(world, 0);

        SDK::TArray<SDK::AActor*> actors{};
        actors.Data = (SDK::AActor**)API::FMalloc::get()->malloc(8196 * sizeof(SDK::AActor*));
        actors.NumElements = 0;
        actors.MaxElements = 8196;

        SDK::UGameplayStatics::GetAllActorsOfClass(world, SDK::AActor::StaticClass(), &actors);

        API::get()->log_warn("[plugin_utils][show_all_primitive_components] Found %d Actors", actors.Num());

        int32_t shown = 0;
        for (UC::int32 i = 0; i < actors.Num(); i++) {
            SDK::AActor* actor = actors[i];
            if (actor == nullptr || !SDK::UKismetSystemLibrary::IsValid(actor)) {
                continue;
            }

            // skip the player's character pawn and anything attached to / owned by it (its components
            // are children of the pawn hierarchy) unless the caller opts in. walk up the attachment
            // chain first, then fall back to child-actor parent and ownership; depth-capped against cycles.
            if (player_pawn != nullptr) {
                bool belongs_to_pawn = false;
                SDK::AActor* ancestor = actor;
                for (int depth = 0; ancestor != nullptr && depth < 32; depth++) {
                    if (ancestor == player_pawn) {
                        belongs_to_pawn = true;
                        break;
                    }
                    SDK::AActor* next = ancestor->GetAttachParentActor();
                    if (next == nullptr) {
                        next = ancestor->GetParentActor();
                    }
                    if (next == nullptr) {
                        next = ancestor->GetOwner();
                    }
                    ancestor = next;
                }
                if (belongs_to_pawn) {
                    continue;
                }
            }

            // returns every UActorComponent on the actor that is (or derives from) UPrimitiveComponent
            SDK::TArray<SDK::UActorComponent*> components =
                actor->K2_GetComponentsByClass(SDK::UPrimitiveComponent::StaticClass());

            for (UC::int32 j = 0; j < components.Num(); j++) {
                SDK::UActorComponent* component = components[j];
                if (component == nullptr || !SDK::UKismetSystemLibrary::IsValid(component)) {
                    continue;
                }

                // ArrowComponents are editor-only direction gizmos - don't reveal them
                if (component->IsA(SDK::UArrowComponent::StaticClass())) {
                    continue;
                }

                // SetVisibility / SetHiddenInGame / K2_GetComponentLocation are USceneComponent members
                SDK::UPrimitiveComponent* primitive = static_cast<SDK::UPrimitiveComponent*>(component);

                // skip anything outside the range sphere (compare squared distances to avoid a sqrt)
                const SDK::FVector loc = primitive->K2_GetComponentLocation();
                if (SDK::UKismetMathLibrary::Vector_DistanceSquared(origin_loc, loc) > range_sq) {
                    continue;
                }

                primitive->SetVisibility(true, false);
                primitive->SetHiddenInGame(false, false);
                shown++;
            }
        }

        API::get()->log_warn("[plugin_utils][show_all_primitive_components] Shown %d PrimitiveComponents within %.1f units", shown, range);
        return;
    }
    catch (...) {
        API::get()->log_error("[plugin_utils][show_all_primitive_components] Exception");
        return;
    }
}

// detaches 'panel' from whatever panel currently owns it and re-adds it as a child of 'user_widget's
// root panel. RemoveChild only unparents (it does not destroy), so the same widget instance survives
// the move. AddChild always appends and returns a brand-new UPanelSlot with default layout, so when
// the destination root is a CanvasPanel we re-apply a full-fill layout - otherwise the freshly added
// child would sit at the top-left with zero size and render invisibly. returns the new slot (so the
// caller can further tweak layout) or nullptr on failure.
// NOTE: UMG mutation is game-thread only - call this from a tick/pre-engine-tick callback.
SDK::UPanelSlot* PluginUtils::reparent_panel_to_user_widget(SDK::UPanelWidget* panel, SDK::UUserWidget* user_widget) {
    try {
        if (panel == nullptr || !SDK::UKismetSystemLibrary::IsValid(panel)) {
            API::get()->log_error("[plugin_utils][reparent_panel_to_user_widget] Invalid panel pointer");
            return nullptr;
        }

        if (user_widget == nullptr || !SDK::UKismetSystemLibrary::IsValid(user_widget)) {
            API::get()->log_error("[plugin_utils][reparent_panel_to_user_widget] Invalid user widget pointer");
            return nullptr;
        }

        // the UserWidget is not itself a panel - its contents live under WidgetTree->RootWidget,
        // which must be a panel for us to add children to it
        SDK::UWidgetTree* widget_tree = user_widget->WidgetTree;
        if (widget_tree == nullptr || !SDK::UKismetSystemLibrary::IsValid(widget_tree)) {
            API::get()->log_error("[plugin_utils][reparent_panel_to_user_widget] User widget has no WidgetTree");
            return nullptr;
        }

        SDK::UWidget* root_widget = widget_tree->RootWidget;
        if (root_widget == nullptr || !root_widget->IsA(SDK::UPanelWidget::StaticClass())) {
            API::get()->log_error("[plugin_utils][reparent_panel_to_user_widget] User widget root is not a UPanelWidget");
            return nullptr;
        }
        SDK::UPanelWidget* target_panel = static_cast<SDK::UPanelWidget*>(root_widget);

        // detach from the current parent (no-op if it has none); this does not destroy the widget
        SDK::UPanelWidget* old_parent = panel->GetParent();
        if (old_parent != nullptr && SDK::UKismetSystemLibrary::IsValid(old_parent)) {
            old_parent->RemoveChild(panel);
        }

        SDK::UPanelSlot* new_slot = target_panel->AddChild(panel);
        if (new_slot == nullptr) {
            API::get()->log_error("[plugin_utils][reparent_panel_to_user_widget] AddChild returned null slot");
            return nullptr;
        }

        // a fresh CanvasPanel slot defaults to zero-size at the top-left - stretch it to fill the
        // parent so the reparented panel is actually visible. caller can override afterwards.
        if (new_slot->IsA(SDK::UCanvasPanelSlot::StaticClass())) {
            SDK::UCanvasPanelSlot* canvas_slot = static_cast<SDK::UCanvasPanelSlot*>(new_slot);
            SDK::FAnchors full_anchors{};
            full_anchors.Minimum = SDK::FVector2D{ 0.0f, 0.0f };
            full_anchors.Maximum = SDK::FVector2D{ 1.0f, 1.0f };
            canvas_slot->SetAnchors(full_anchors);
            canvas_slot->SetOffsets(SDK::FMargin{ 0.0f, 0.0f, 0.0f, 0.0f });
        }

        API::get()->log_warn("[plugin_utils][reparent_panel_to_user_widget] Reparented %s into %s",
            panel->GetName().c_str(), user_widget->GetName().c_str());
        return new_slot;
    }
    catch (...) {
        API::get()->log_error("[plugin_utils][reparent_panel_to_user_widget] Exception");
        return nullptr;
    }
}

SDK::UObject* PluginUtils::load_asset(SDK::FAssetData asset_data) {
    try {
        API::get()->log_warn("[plugin_utils][load_asset] Loading Asset %s", asset_data.ObjectPath.GetRawString().c_str());
        SDK::FSoftObjectPath path = SDK::UAssetRegistryHelpers::ToSoftObjectPath(asset_data);
        auto obj_ref = SDK::UKismetSystemLibrary::Conv_SoftObjPathToSoftObjRef(path);
        SDK::UObject* asset = SDK::UKismetSystemLibrary::LoadAsset_Blocking(obj_ref);
        API::get()->log_warn("[plugin_utils][load_asset] Successfully Loaded Asset");
        return asset;
    }
    catch (...) {
        API::get()->log_error("[plugin_utils][load_asset] Exception");
        return nullptr;
    }
}


//Find vtable real function and hook it
int32_t PluginUtils::hook_vtable_fn(std::wstring_view class_name, std::wstring_view fn_name, void* destination, void** original) {
    //auto obj = (API::UClass*)API::get()->find_uobject(class_name);

    //if (obj == nullptr) {
    //    PLUGIN_LOG_ONCE_ERROR("Failed to find %ls", class_name.data());
    //    return -1;
    //}

    //auto fn = obj->find_function(fn_name);

    //if (fn == nullptr) {
    //    PLUGIN_LOG_ONCE_ERROR("Failed to find %ls", fn_name.data());
    //    return -1;
    //}

    //auto native = fn->get_native_function();

    //if (native == nullptr) {
    //    PLUGIN_LOG_ONCE_ERROR("Failed to get native function");
    //    return -1;
    //}

    //PLUGIN_LOG_ONCE("%ls native: 0x%p", fn_name.data(), native);

    //auto default_object = obj->get_class_default_object();

    //if (default_object == nullptr) {
    //    PLUGIN_LOG_ONCE_ERROR("Failed to get default object");
    //    return -1;
    //}

    //auto insn = utility::scan_disasm((uintptr_t)native, 0x1000, "FF 90 ? ? ? ?");

    //if (!insn) {
    //    PLUGIN_LOG_ONCE_ERROR("Failed to find the instruction");
    //    return -1;
    //}

    //auto offset = *(int32_t*)(*insn + 2);

    //auto vtable = *(uintptr_t**)default_object;
    //auto real_fn = vtable[offset / sizeof(void*)];

    //PLUGIN_LOG_ONCE("Real %ls: 0x%p (index: %d, offset 0x%X)", fn_name.data(), real_fn, offset / sizeof(void*), offset);

    //return API::get()->param()->functions->register_inline_hook((void*)real_fn, (void*)destination, original);
    
    // remove me
    return 0;
}

float PluginUtils::bytes_to_float(std::string name, uint8_t b0, uint8_t b1, uint8_t b2, uint8_t b3)
{
    uint8_t bytes[4] = { b0, b1, b2, b3 };
    static_assert(sizeof(float) == 4, "float size is expected to be 4 bytes");
    float f;
    memcpy(&f, bytes, 4);
    return f;
}

void PluginUtils::print_niagara_parameter_float(std::string name, uint8_t offset, SDK::TArray<uint8_t> data) {
    float value = bytes_to_float(name, data[offset], data[offset + 1], data[offset + 2], data[offset + 3]);
    API::get()->log_warn("[plugin_utils][bytes_to_float] Name: %s | Value %f", name.c_str(), value);
}

float PluginUtils::get_niagara_parameter_float(std::string name, uint8_t offset, SDK::TArray<uint8_t> data) {
    return bytes_to_float(name, data[offset], data[offset + 1], data[offset + 2], data[offset + 3]);
}

float PluginUtils::uevr_param_to_float(const UEVR_VRData* vr, const char* key) {
    try {
        // get uevr param
        char uevr_param[16] = {};
        vr->get_mod_value(key, uevr_param, sizeof(uevr_param));
        float value{ 1.f };
        size_t read = 0;
        value = std::stof(uevr_param, &read);
        return value;
    }
    catch (std::invalid_argument) {
        API::get()->log_error("[plugin_utils][uevr_param_to_float] Error converting UEVR param value to float");
    }
    return 0;
}

void PluginUtils::handle_native_stereo_fix_cycler(const UEVR_VRData* vr) {
    if (PluginUtils::m_native_fix_tick_counter >= 0) {
        PluginUtils::m_native_fix_tick_counter--;
        if (PluginUtils::m_native_fix_tick_counter == 0) {
            API::get()->log_warn("[plugin_utils][handle_native_stereo_fix_cycler] Native Stereo Fix: ON");
            vr->set_mod_value("VR_NativeStereoFix", "true");
        }
    }
}

void PluginUtils::cycle_native_stereo_fix() {
    const UEVR_VRData* vr = API::get()->param()->vr;

    char vr_native_stereo_fix_str[16] = { 0 };
    vr->get_mod_value("VR_NativeStereoFix", vr_native_stereo_fix_str, sizeof(vr_native_stereo_fix_str));

    // cycle only if the setting is enabled
    if (std::string(vr_native_stereo_fix_str, strnlen(vr_native_stereo_fix_str, sizeof(vr_native_stereo_fix_str))) == "true") {
        PluginUtils::m_native_fix_tick_counter = 200;
        vr->set_mod_value("VR_NativeStereoFix", "false");
        API::get()->log_warn("[plugin_utils][handle_native_stereo_fix_cycler] Native Stereo Fix: OFF");
    }
}
