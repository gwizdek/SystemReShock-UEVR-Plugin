#pragma once
#include <windows.h>
#include <Xinput.h>
#include <unordered_set>
#include <map>

#include "mINI/ini.h"

#include "SDK/Engine_classes.hpp"
#include "SDK/UMG_classes.hpp"
#include "SDK/COMP_HackerInventory_classes.hpp"

#include "memo_structs.hpp"
#include "vr_controllers.hpp"
#include "SDK/_BP_VRBody_classes.hpp"
#include "SDK/WIDGET_PlayerHUD_classes.hpp"

using namespace uevr;

class VRBody;

class VRMFD
{
private:
    const char* MOD_VERSION = "v2.0.0-alpha";

    VRBody* m_vr_body{ nullptr };

    // convenience pointers
    SDK::UWorld* m_world{ nullptr };
    SDK::UWIDGET_PlayerHUD_C* m_neural_hud{ nullptr };

    // utils
    std::unordered_set<ModEvent> m_mod_events{};
    SDK::FHitResult m_hit_result{};

public:
    VRMFD();
    virtual ~VRMFD();

    void on_tick(float delta);
    void send_mouse(WORD key, bool key_up);
    void handle_mfd_interactions(XINPUT_STATE* state, const UEVR_VRData* vr);
    void handle_mfd_changes(const UEVR_VRData* vr);

};
