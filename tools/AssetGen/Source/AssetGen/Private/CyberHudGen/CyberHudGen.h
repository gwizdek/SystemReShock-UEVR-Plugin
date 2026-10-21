#pragma once

#include "CoreMinimal.h"

struct FAssetGenContext;

// The cyberspace HUD's connection integrity widget: replacements for the four additive
// materials that UEVR's UI layer drops (the panel, the health bar, the SECURE and THREAT
// tags), at the game's own asset paths in chunk 10 so the Core pak overrides them. Their
// textures are copies of the game's in chunk 0, never shipped: the cooked materials refer to
// the paths, and in the game those resolve to the game's own textures.
// Also textures at the game's paths in chunk 10, sampled by the game's own materials: the
// flight reticle's with only the top triangle of the ring left, and the drill lock-on's arcs
// and chevrons with only a thin outline rim.
namespace CyberHudGen
{
bool Generate(const FAssetGenContext& Context);
}
