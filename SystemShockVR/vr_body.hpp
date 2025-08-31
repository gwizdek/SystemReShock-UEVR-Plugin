#pragma once
#include "main.hpp"
#include "SDK/Niagara_classes.hpp"


class VRBody
{
private:
    SystemShockMain* m_main{ nullptr };
    SDK::ABP_VRBody_C* m_bp_actor{ nullptr };

public:
    VRBody(SystemShockMain* main);
    virtual ~VRBody() {};

    SDK::ABP_VRBody_C* get_bp_actor() { return m_bp_actor; };

    void initialize();
    bool is_valid();
    void on_tick();
    void on_draw_imgui();
    void cleanup_pointers();
    static void cleanup_actors();
};
