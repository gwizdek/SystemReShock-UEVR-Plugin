#pragma once
#include "SDK/WIDGET_PlayerHUD_classes.hpp"

class VRMFD final
{
public:
    static inline float m_mfd_depth{ 150.f };

    static void align_mfd_panel(SDK::UWIDGET_PlayerHUD_C* neural_hud);
    static void show_mfd();
    static void hide_mfd();
    static void set_crosshair_cursor_scale(SDK::UWIDGET_PlayerHUD_C* neural_hud, float* scale);
    static bool calculate_uevr_ui_params(const UEVR_VRData* vr, SDK::UWorld* world, char* ui_distance, char* ui_size);

    VRMFD() = delete;
};
