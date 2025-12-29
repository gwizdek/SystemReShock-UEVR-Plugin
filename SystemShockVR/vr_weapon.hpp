#pragma once
#include "main.hpp"
#include "SDK/ITEM_WeaponBase_classes.hpp"
#include "SDK/Niagara_classes.hpp"

typedef enum HackerWeapon : int32_t
{
    WEAPON_NONE                 = 0,
    WEAPON_LEAD_PIPE            = 1,
    WEAPON_WRENCH               = 2,
    WEAPON_SHOTGUN              = 3,
    WEAPON_SKORPION             = 4,
    WEAPON_MAGNUM               = 5,
    WEAPON_ION                  = 6,
    WEAPON_RAIL                 = 7,
    WEAPON_PLASMA_RIFLE         = 8,
    WEAPON_MAG_PULSE            = 9,
    WEAPON_SPARQ_BEAM           = 10,
    WEAPON_MINI_PISTOL          = 11,
    WEAPON_GRENADE_LAUNCHER     = 12,
    WEAPON_ASSAULT_RIFLE        = 13,
    WEAPON_LASER_RAPIER         = 14,
    WEAPON_PSEUDOPULSER         = 15,
    WEAPON_PSEUDODISCLAUNCHER   = 16,
    WEAPON_PSEUDONOVA           = 17,
    WEAPON_CYBERGUN             = 18,
    GRENADE_MANAGER             = 19,
    MEDIPATCH_MANAGER           = 20,
    STAMINUP_MANAGER            = 21,
    BERSERK_PATCH_MANAGER       = 22,
    VISION_PATCH_MANAGER        = 23,
    DETOX_PATCH_MANAGER         = 24,
    FIRST_AID_KIT_MANAGER       = 25,
    BATTERY_PACK_MANAGER        = 26,
    PROXIMITY_MINE_MANAGER      = 27
} HackerWeapon;

typedef std::tuple<std::string, SDK::FVector, float> WeaponMeta;

//  HackerWeapon enum           Search string               Weapon offset               Selector distance offset
const std::map<HackerWeapon, WeaponMeta> weapons_map{
    { WEAPON_NONE,              { "None",                   { 0.0f, 0.0f, 0.0f },       0.0f    } },
    { WEAPON_LEAD_PIPE,         { "LeadPipe",               { 0.0f, 4.0f, -8.0f },      0.0f    } },    // ok
    { WEAPON_WRENCH,            { "Wrench",                 { 0.0f, 4.0f, -8.0f },      0.0f    } },    // ok
    { WEAPON_SHOTGUN,           { "Shotgun",                { -2.6f, -2.0f, -1.1f },    10.0f   } },    // ok
    { WEAPON_SKORPION,          { "Skorpion",               { 0.0f, -5.0f, -0.5f },     10.0f   } },    // ok
    { WEAPON_MAGNUM,            { "Magnum",                 { 0.0f, -0.4f, -1.43f },    0.0f    } },    // ok
    { WEAPON_ION,               { "Ion",                    { 2.5f, -4.0f, -1.5f },     10.0f   } },    // ok
    { WEAPON_RAIL,              { "Rail",                   { 3.5f, -6.4f, -4.4f },     10.0f   } },    // ok
    { WEAPON_PLASMA_RIFLE,      { "PlasmaRifle",            { 10.0f, -2.3f, -7.6f },    10.0f   } },    // ok
    { WEAPON_MAG_PULSE,         { "MagPulse",               { -2.5f, -3.5f, -2.0f },    0.0f    } },    // ok
    { WEAPON_SPARQ_BEAM,        { "SparqBeam",              { 2.75f, -3.0f, -7.25f },   0.0f    } },    // ok
    { WEAPON_MINI_PISTOL,       { "MiniPistol",             { 0.0f, -0.8f, -0.5f },     0.0f    } },    // ok
    { WEAPON_GRENADE_LAUNCHER,  { "GrenadeLauncher",        { 6.0f, -6.0f, -1.15f },    10.0f   } },    // ok
    { WEAPON_ASSAULT_RIFLE,     { "AssaultRifle",           { 6.5f, -5.0f, -1.1f },     10.0f   } },    // ok
    { WEAPON_LASER_RAPIER,      { "LaserRapier",            { -2.0f, -15.0f, 0.0f },    0.0f    } },    // ok
    { WEAPON_PSEUDOPULSER,      { "PseudoPulser",           { 8.0f, -2.0f, -3.0f },     0.0f    } },    // ok
    { WEAPON_PSEUDODISCLAUNCHER,{ "PseudoDiscLauncher",     { 8.0f, -2.0f, -3.0f },     0.0f    } },    // ok
    { WEAPON_PSEUDONOVA,        { "PseudoNova",             { 8.0f, -2.0f, -3.0f },     0.0f    } },    // ok
    { WEAPON_CYBERGUN,          { "Cybergun",               { 6.0f, -2.0f, -3.0f },     0.0f    } },    // ok
    { GRENADE_MANAGER,          { "GrenadeManager",         { 0.0f, -3.5f, -2.0f },     0.0f    } },    // ok
    { MEDIPATCH_MANAGER,        { "MedipatchManager",       { 0.0f, -1.5f, -3.5f },     0.0f    } },    // ok
    { STAMINUP_MANAGER,         { "StaminupManager",        { 0.0f, -1.5f, -3.5f },     0.0f    } },    // ok
    { BERSERK_PATCH_MANAGER,    { "BerserkPatchManager",    { 0.0f, -1.5f, -3.5f },     0.0f    } },    // ok
    { VISION_PATCH_MANAGER,     { "VisionPatchManager",     { 0.0f, -1.5f, -3.5f },     0.0f    } },    // ok
    { DETOX_PATCH_MANAGER,      { "DetoxPatchManager",      { 0.0f, -1.5f, -3.5f },     0.0f    } },    // ok
    { FIRST_AID_KIT_MANAGER,    { "FirstAidKitManager",     { 4.0f, -18.0f, -8.0f },    10.0f   } },    // ok
    { BATTERY_PACK_MANAGER,     { "BatteryPackManager",     { 9.0f, -17.0f, -13.0f },   0.0f    } },    // ok
    { PROXIMITY_MINE_MANAGER,   { "ProximityMineManager",   { 0.0f, -6.0f, -7.0f },     0.0f    } },    // ok
};

typedef enum VRWeaponType {
    WEAPON_TYPE_UNARMED,
    WEAPON_TYPE_RANGED,
    WEAPON_TYPE_MELEE,
    WEAPON_TYPE_UNKNOWN
} VRWeaponType;

static std::map<VRWeaponType, const char*> VRWeaponTypeName = {
    { WEAPON_TYPE_UNARMED, "Unarmed" },
    { WEAPON_TYPE_RANGED, "Ranged" },
    { WEAPON_TYPE_MELEE, "Melee" },
    { WEAPON_TYPE_UNKNOWN, "Unknown" }
};

class VRWeapon
{
private:
    VRBody* m_vr_body{ nullptr };
    SDK::UITEM_WeaponBase_C* m_equipped_weapon{ nullptr };
    //SDK::USkeletalMesh* m_equipped_weapon_mesh{ nullptr };
    MemoProperty<HackerWeapon> m_weapon_state{ WEAPON_NONE, WEAPON_NONE };

    // interaction components
    SDK::UNiagaraComponent* m_laser_dot_component{ nullptr };
    SDK::UNiagaraComponent* m_laser_sight_component{ nullptr };
    SDK::UStaticMeshComponent* m_scope_component{ nullptr };

    VRWeaponType m_weapon_type{ WEAPON_TYPE_UNKNOWN };

public:
    VRWeapon(VRBody* vr_body);
    virtual ~VRWeapon() {};

    MemoProperty<std::string> m_equipped_weapon_mesh_name{ "", "" };
    // getters
    SDK::UITEM_WeaponBase_C* get_equipped_weapon() { return m_equipped_weapon; };
    //SDK::USkeletalMeshComponent* get_equipped_weapon_mesh_component() { return m_equipped_weapon_mesh_component; };


    // setters
    //void set_equipped_weapon_mesh_component(SDK::USkeletalMeshComponent* mesh) { m_equipped_weapon_mesh_component = mesh; };
     
    void set_weapon(SDK::UITEM_WeaponBase_C* weapon);
    void set_laser_pointer_visibility(bool visible);

    //void set_weapon_state(SDK::UITEM_WeaponBase_C* weapon);
    void change_equipped_weapon(SDK::UITEM_WeaponBase_C* weapon);
    void attach_camera(SDK::UCameraComponent* camera);
    void attach_laser();
    void initialize();
    void cleanup_pointers();
    bool is_valid();
    void on_tick();
    void on_draw_imgui();
    void spawn_laser_pointer();
    void attach_laser_pointer();
    void update_laser_pointer();
    //void set_weapon_state();
    void fire_weapon();
    void handle_weapon_change();

    void empty_magazine();
    void reload();
};
