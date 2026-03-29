#pragma once

#include "SDK/Engine_structs.hpp"
#include "SDK/COMP_HackerInventory_classes.hpp"
#include "SDK/WIDGET_PlayerHUD_classes.hpp"
#include "SDK/_BP_VRAvatar_classes.hpp"
#include "SDK/PAWN_Avatar_classes.hpp"

class VRAvatar final
{
private:

public:
    static SDK::A_BP_VRAvatar_C* initialize_vr_avatar(SDK::APAWN_Avatar_C* pawn);

};