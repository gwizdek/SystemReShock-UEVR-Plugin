#pragma once

#include "CoreMinimal.h"

class FMenuGenBlueprint;
struct FMenuGenStore;

// The functions of the VR options page: InitializeMenu, Install and the three event handlers.
// documentation/vr-options-menu.md describes what each one does and why.
namespace MenuGenPageLogic
{
bool Build(FMenuGenBlueprint& Page, const FMenuGenStore& Store);
}
