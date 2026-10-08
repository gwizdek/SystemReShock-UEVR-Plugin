#pragma once

#include "BridgeSDK/BridgeSDK.hpp"

namespace SDK
{
// Warms up only the BridgeSDK classes the plugin uses. This list is kept by hand.
//
// Finding a class scans the whole Unreal object array, so every entry costs tens of
// milliseconds at level setup. BridgeWarmupAll() in BridgeSDK.hpp warms every generated
// class; most of them are never touched by the plugin.
//
// When plugin code starts using a class that is not listed here, its first use logs
//   [bridge] resolved on first use, not pre-warmed: <class path>
// Add the class to this list when that line shows up for a class used during gameplay.
// A_BP_VRBody_C and A_BP_VRAvatar_C are loaded and resolved before the first warm-up by
// design, when their actor is spawned (VRBody::initialize_vr_body and
// VRAvatar::initialize_vr_avatar), so that line is expected for them once per level.
inline bool BridgeWarmupUsed()
{
	bool Ok = true;
	Ok &= A_BP_HackerHardware_C::BridgeWarmup();
	Ok &= A_BP_ItemSelector_C::BridgeWarmup();
	Ok &= A_BP_LaserDot_C::BridgeWarmup();
	Ok &= A_BP_MeleeWeaponHandler_C::BridgeWarmup();
	Ok &= A_BP_VRAvatar_C::BridgeWarmup();
	Ok &= A_BP_VRBody_C::BridgeWarmup();
	Ok &= U_BP_HandInteractionComponent_C::BridgeWarmup();
	Ok &= U_BP_MFDMaskComponent_C::BridgeWarmup();
	Ok &= U_BP_VRMenu_C::BridgeWarmup();
	Ok &= U_BP_VRMovementComponent_C::BridgeWarmup();
	return Ok;
}
}
