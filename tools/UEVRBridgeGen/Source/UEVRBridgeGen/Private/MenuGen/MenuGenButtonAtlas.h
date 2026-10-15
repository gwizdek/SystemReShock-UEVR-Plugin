#pragma once

#include "CoreMinimal.h"

struct FMenuGenOptions;
struct FMenuGenStore;

// The VR controller button atlas for the game's tutorial popups and button legends: the atlas
// texture, a stand-in for the game's MAT_PlatformButton (chunk 0, never shipped) and a material
// instance of it that sets the atlas and its row count (chunk 10). The plugin gives the
// instance and the texture to WIDGET_ButtonLegend_Key (SystemShockVR\vr_button_atlas.cpp);
// in the game the instance's parent resolves to the game's own material.
namespace MenuGenButtonAtlas
{
bool Generate(FMenuGenStore& Store, const FMenuGenOptions& Options);
}
