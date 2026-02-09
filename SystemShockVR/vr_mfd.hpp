#pragma once
#include "SDK/Engine_classes.hpp"
#include "SDK/UMG_classes.hpp"
#include "SDK/COMP_HackerInventory_classes.hpp"
#include "SDK/WIDGET_PlayerHUD_classes.hpp"

#include "SDK/_BP_VRBody_classes.hpp"

#include "memo_structs.hpp"

using namespace uevr;
using namespace SDK;

class VRMFD
{
private:

public:
    VRMFD() = default;
    virtual ~VRMFD() {};

    static inline float m_mfd_depth{ 150.f };

    static void initialize(A_BP_VRBody_C* vr_body);

    static void align_mfd_panel(UWIDGET_PlayerHUD_C* neural_hud);

    //static void send_mouse(WORD key, bool key_up);
    static void handle_mfd_interactions(XINPUT_STATE* state, const UEVR_VRData* vr);
    static void handle_mfd_changes(const UEVR_VRData* vr);
    static void show(A_BP_VRBody_C* vr_body);
    static void hide(A_BP_VRBody_C* vr_body);
    static void set_crosshair_cursor_scale(UWIDGET_PlayerHUD_C* neural_hud, float* scale);
};
