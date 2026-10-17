#pragma once
#include "SDK/WIDGET_PlayerHUD_classes.hpp"

class VRMFD final
{
public:
    static inline float m_mfd_depth{ 150.f };
    static inline bool m_had_equipped_weapon{ false };
    // Final view rotation of the last rendered view, HMD included. Set by save_view_rotation.
    static inline SDK::FRotator m_view_rotation{};
    static inline bool m_has_view_rotation{ false };

    static void save_view_rotation(const UEVR_Rotatorf* rotation);
    static void face_head(SDK::APawn* pawn, const UEVR_VRData* vr);
    static void align_mfd_panel(SDK::UWIDGET_PlayerHUD_C* neural_hud);
    static void show_mfd();
    static void hide_mfd(SDK::ACON_Hacker_C* ctrl);
    static void set_crosshair_cursor_scale(SDK::UWIDGET_PlayerHUD_C* neural_hud, float* scale);
    static bool calculate_uevr_ui_params(const UEVR_VRData* vr, SDK::UWorld* world, char* ui_distance, char* ui_size);

    VRMFD() = delete;
};
