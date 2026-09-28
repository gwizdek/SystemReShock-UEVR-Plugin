#pragma once

// Points the Dumper-7 SDK at the object array and the FName-to-string function that
// UEVR resolved for the running game. Without this the SDK uses the image-relative
// addresses in SDK/Basic.hpp, which only match the build the dump was taken from
// (the Steam build). The Steam and GOG builds share every class layout, so with
// this bootstrap one DLL runs on both.
namespace SDK
{
    class UWorld;
}

namespace SdkBootstrap
{
    // Returns false when UEVR did not give a usable object array; the SDK then
    // falls back to the addresses from the dump.
    bool initialize();

    // The current game world, taken from the engine object that UEVR found.
    // Use this instead of SDK::UWorld::GetWorld(), which reads the GWorld
    // constant from the dump. Returns nullptr while no world is loaded.
    SDK::UWorld* get_world();
}
