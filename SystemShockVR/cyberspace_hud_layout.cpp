#include "cyberspace_hud_layout.hpp"

#include <vector>

#include "uevr/API.hpp"
#include "SDK/Engine_classes.hpp"
#include "SDK/UMG_classes.hpp"
#include "SDK/PAWN_Avatar_classes.hpp"
#include "SDK/WIDGET_ConnectionIntegrity_classes.hpp"
#include "SDK/WIDGET_CyberspaceHUD_classes.hpp"
#include "SDK/WIDGET_Cyberspace_SoftwareHotbar_classes.hpp"
#include "SDK/PAWN_Hacker_Simple_classes.hpp"
#include "SDK/WIDGET_PseudospaceHUD_classes.hpp"
#include "SDK/WIDGET_PseudoHealth_classes.hpp"

using namespace SDK;
using namespace uevr;

namespace {

// Connection integrity's SECURE and THREAT tags reach 3 units above the panel, so this is as
// high as it can go without cutting them.
constexpr float kIntegrityTop = 3.f;
// Connection integrity and the software hotbar are drawn at this part of their size; the UEVR
// UI is shown large in cyberspace (UI_Size 3.5).
constexpr float kPanelScale = 0.75f;
// Centre of the scan text inside PANEL_DashboardTop (which starts 5 units above the canvas),
// just below connection integrity, whose health bar ends 93 units down at full size.
constexpr float kScanTextCentre = 95.f;

struct MovedSlot
{
    UCanvasPanelSlot* slot;
    FAnchorData original;
};

struct ScaledWidget
{
    UWidget* widget;
    FWidgetTransform transform;
    FVector2D pivot;
};

std::vector<MovedSlot> s_moved{};
std::vector<ScaledWidget> s_scaled{};
// The pseudospace HUD the layout was applied to.
UUserWidget* s_pseudospace_hud{ nullptr };

bool is_alive(void* object) {
    return object != nullptr && API::UObjectHook::exists(reinterpret_cast<API::UObject*>(object));
}

// Keeps the slot's layout for restore, then lets change edit a copy and sets it.
template <class Change>
void move_slot(UWidget* widget, Change change) {
    if (!is_alive(widget) || widget->Slot == nullptr || !widget->Slot->IsA(UCanvasPanelSlot::StaticClass())) {
        return;
    }
    auto* slot = static_cast<UCanvasPanelSlot*>(widget->Slot);
    FAnchorData layout = slot->LayoutData;
    s_moved.push_back({ slot, layout });
    change(layout);
    slot->SetLayout(layout);
}

// Keeps the widget's render transform and pivot for restore, then scales it around pivot, a
// point in the widget's own size (0 to 1). Render scale leaves the layout as it is.
void scale_widget(UWidget* widget, float scale, const FVector2D& pivot) {
    if (!is_alive(widget)) {
        return;
    }
    s_scaled.push_back({ widget, widget->RenderTransform, widget->RenderTransformPivot });
    widget->SetRenderTransformPivot(pivot);
    widget->SetRenderScale(FVector2D{ scale, scale });
}

} // namespace

void CyberspaceHudLayout::apply(APAWN_Avatar_C* pawn) {
    try {
        restore();
        auto* hud = static_cast<UWIDGET_CyberspaceHUD_C*>(pawn->CyberspaceUI);
        if (!is_alive(hud)) {
            return;
        }
        // The slot sizes itself to the panel, so only anchor, alignment and position change.
        move_slot(hud->WIDGET_ConnectionIntegrity, [](FAnchorData& layout) {
            layout.Anchors = FAnchors{ { 0.5f, 0.f }, { 0.5f, 0.f } };
            layout.Alignment = FVector2D{ 0.5f, 0.f };
            layout.Offsets.Left = 0.f;
            layout.Offsets.Top = kIntegrityTop;
        });
        move_slot(hud->TEXT_ScanDescription, [](FAnchorData& layout) {
            layout.Offsets.Top = kScanTextCentre;
        });
        // Anchored to the bottom centre of PANEL_Items, which sits on the canvas bottom; the
        // game leaves a 26 unit gap below it.
        move_slot(hud->WIDGET_Cyberspace_SoftwareHotbar, [](FAnchorData& layout) {
            layout.Offsets.Top = 0.f;
        });
        // Scaled around the edge they sit on, so they stay there: connection integrity around
        // its top centre, PANEL_Items (the hotbar and the equipment boxes) around its bottom.
        scale_widget(hud->WIDGET_ConnectionIntegrity, kPanelScale, FVector2D{ 0.5f, 0.f });
        if (is_alive(hud->WIDGET_Cyberspace_SoftwareHotbar)) {
            scale_widget(hud->WIDGET_Cyberspace_SoftwareHotbar->GetParent(), kPanelScale, FVector2D{ 0.5f, 1.f });
        }
        API::get()->log_warn("[cyberspace_hud_layout][apply] Moved %d and scaled %d HUD parts for VR",
            static_cast<int>(s_moved.size()), static_cast<int>(s_scaled.size()));
    }
    catch (...) {
        API::get()->log_error("[cyberspace_hud_layout][apply] Exception");
    }
}

void CyberspaceHudLayout::restore() {
    try {
        for (const MovedSlot& moved : s_moved) {
            if (is_alive(moved.slot)) {
                moved.slot->SetLayout(moved.original);
            }
        }
        for (const ScaledWidget& scaled : s_scaled) {
            if (is_alive(scaled.widget)) {
                scaled.widget->SetRenderTransformPivot(scaled.pivot);
                scaled.widget->SetRenderTransform(scaled.transform);
            }
        }
    }
    catch (...) {
        API::get()->log_error("[cyberspace_hud_layout][restore] Exception");
    }
    s_moved.clear();
    s_scaled.clear();
    s_pseudospace_hud = nullptr;
}

void CyberspaceHudLayout::handle_pseudospace(APAWN_Hacker_Simple_C* pawn) {
    auto* hud = static_cast<UWIDGET_PseudospaceHUD_C*>(pawn->PlayerHUDWidget);
    if (hud == s_pseudospace_hud || !is_alive(hud)) {
        return;
    }
    try {
        restore();
        s_pseudospace_hud = hud;
        // The slot sizes itself to the panel, so only anchor, alignment and position change.
        move_slot(hud->WIDGET_PseudoHealth, [](FAnchorData& layout) {
            layout.Anchors = FAnchors{ { 0.5f, 0.f }, { 0.5f, 0.f } };
            layout.Alignment = FVector2D{ 0.5f, 0.f };
            layout.Offsets.Left = 0.f;
        });
        API::get()->log_warn("[cyberspace_hud_layout][handle_pseudospace] Moved %d HUD parts for VR",
            static_cast<int>(s_moved.size()));
    }
    catch (...) {
        API::get()->log_error("[cyberspace_hud_layout][handle_pseudospace] Exception");
    }
}
