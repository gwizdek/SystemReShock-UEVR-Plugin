#pragma once

#include "Commandlets/Commandlet.h"
#include "CoreMinimal.h"

#include "VROptionsMenuGenCommandlet.generated.h"

// Creates the assets of the VR options page: dummy copies of the game's menu classes and the
// mod's own page, list and rows. See documentation/vr-options-menu.md.
//
// Run with:
//   UE4Editor-Cmd.exe <Project>.uproject -run=VROptionsMenuGen [-ModRoot=/Game/Mods/UI/Options] [-Overwrite]
UCLASS()
class UVROptionsMenuGenCommandlet : public UCommandlet
{
    GENERATED_BODY()

public:
    UVROptionsMenuGenCommandlet();

    virtual int32 Main(const FString& Params) override;
};
