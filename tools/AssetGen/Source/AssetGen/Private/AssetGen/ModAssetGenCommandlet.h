#pragma once

#include "Commandlets/Commandlet.h"
#include "CoreMinimal.h"

#include "ModAssetGenCommandlet.generated.h"

// Creates the mod's generated assets in the Unreal project. Each generator owns one set:
// Menu (the VR options page, MenuGen/), HudIcon (the HUD email icon, HudIconGen/),
// ButtonAtlas (the VR controller button atlas, ButtonAtlasGen/) and CyberHud (the cyberspace
// HUD, CyberHudGen/). All of them run in one editor start, unless -Only names some.
//
// Run with:
//   UE4Editor-Cmd.exe <Project>.uproject -run=ModAssetGen [-Only=Menu,CyberHud] [-ModRoot=/Game/Mods/UI/Options] [-Overwrite]
UCLASS()
class UModAssetGenCommandlet : public UCommandlet
{
    GENERATED_BODY()

public:
    UModAssetGenCommandlet();

    virtual int32 Main(const FString& Params) override;
};
