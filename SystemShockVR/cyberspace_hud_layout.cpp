#include "cyberspace_hud_layout.hpp"

#include <vector>

#include "uevr/API.hpp"
#include "SDK/Engine_classes.hpp"
#include "SDK/UMG_classes.hpp"
#include "SDK/PAWN_Avatar_classes.hpp"
#include "SDK/WIDGET_ConnectionIntegrity_classes.hpp"
#include "SDK/WIDGET_CyberspaceHUD_classes.hpp"
#include "SDK/WIDGET_Cyberspace_SoftwareHotbar_classes.hpp"

using namespace SDK;
using namespace uevr;

namespace {

// Connection integrity's SECURE and THREAT tags reach 3 units above the panel, so this is as
// high as it can go without cutting them.
constexpr float kIntegrityTop = 3.f;
// Centre of the scan text inside PANEL_DashboardTop (which starts 5 units above the canvas),
// just below connection integrity, whose health bar ends about 93 units down.
constexpr float kScanTextCentre = 118.f;

struct MovedSlot
{
    UCanvasPanelSlot* slot;
    FAnchorData original;
};

std::vector<MovedSlot> s_moved{};

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
        API::get()->log_warn("[cyberspace_hud_layout][apply] Moved %d HUD parts for VR", static_cast<int>(s_moved.size()));
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
    }
    catch (...) {
        API::get()->log_error("[cyberspace_hud_layout][restore] Exception");
    }
    s_moved.clear();
}
