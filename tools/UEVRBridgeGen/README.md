# UEVRBridgeGen

An Unreal Engine 4.27 editor plugin. It runs as a commandlet and writes C++ wrapper
headers for the project's Blueprint classes, User Defined Enums and User Defined
Structs. The wrappers are compiled into the UEVR plugin (`SystemShockVR`) next to the
Dumper-7 SDK and replace the dumped headers of the mod's own Blueprints (the assets
whose names start with `_`).

## Why

Dumper-7 headers hard-code memory offsets. For the game's own classes that is fine,
because the game binary does not change. For the mod's Blueprints it is not: every
edit to a Blueprint variable shifts offsets, and the plugin then reads wrong memory
until the game is run again and dumped again.

The generated wrappers resolve every variable and function by name through the UEVR
API on first use and cache the result. The headers are produced from the editor
project, so they are always in step with the paks you build, and no game run is
needed.

## Where the plugin lives

The plugin source is kept here, in the UEVR plugin repository, because its output
contract (Dumper-7 naming, the `SDK::` namespace, the UEVR API) belongs to the
consumer. Each Unreal project that holds mod Blueprints gets a directory junction
to this folder:

```cmd
mklink /J "C:\path\to\UnrealProject\Plugins\UEVRBridgeGen" "C:\_Dev\mods\SystemReShock-UEVR-Plugin\tools\UEVRBridgeGen"
```

Adding a code plugin turns a Blueprint-only project into one that needs compiling.
The first time, build the editor target for the project:

```cmd
"C:\Program Files\Epic Games\UE_4.27\Engine\Build\BatchFiles\Build.bat" ^
    <ProjectName>Editor Win64 Development -Project="C:\path\to\UnrealProject\<ProjectName>.uproject" -WaitMutex
```

Opening the project in the editor and accepting the rebuild prompt does the same.

## Running it

```cmd
"C:\Program Files\Epic Games\UE_4.27\Engine\Binaries\Win64\UE4Editor-Cmd.exe" ^
    "C:\path\to\UnrealProject\<ProjectName>.uproject" ^
    -run=UEVRBridgeGen ^
    -OutDir="C:\_Dev\mods\SystemReShock-UEVR-Plugin\SystemShockVR\BridgeSDK" ^
    -Prefix=_ ^
    -unattended -nopause -nosplash
```

| Option | Default | Meaning |
|---|---|---|
| `-OutDir=` | required | Folder that receives the generated headers. |
| `-Paths=` | `/Game` | Comma-separated content paths to scan, recursively. |
| `-Prefix=` | none | Only assets whose name starts with this prefix. Use `_` for the mod's Blueprints. |
| `-SdkInclude=` | `../SDK` | Include path from `OutDir` to the Dumper-7 SDK folder. |
| `-UevrInclude=` | `../uevr/API.hpp` | Include path from `OutDir` to the UEVR API header. |
| `-Aggregate=` | `BridgeSDK.hpp` | Name of the header that includes every generated header. |

Files are only rewritten when their content changes, so MSBuild's incremental build
is not disturbed. Files for Blueprints that no longer exist are not deleted; remove
them by hand.

## What gets generated

For each Blueprint class, `<AssetName>_classes.hpp`:

```cpp
class A_BP_VRBody_C final : public AActor
{
public:
    static class UClass* StaticClass();               // for IsA, spawning, GetAllActorsOfClass
    static A_BP_VRBody_C* GetDefaultObj();

    class UWidgetComponent*& Subtitles();              // Blueprint variable, by reference
    bool& IsInADSZone();
    E_ENUM_VRHand& MainHand();
    TArray<class AActor*>& IgnoredActors();

    bool IsWeaponHolstered();                          // Blueprint function
    void SetADSZoneOffset(float ForwardOffset, float UpOffset, float HalfSize);
    void GetNearestWeaponInteractionSource(class UMotionControllerComponent* MotionController,
        class U_BP_InteractionSourceComponent_C** OutInteractionSource, float* Distance);
};
```

- The class derives from the Dumper-7 parent and adds no data members. Every native
  member and method of the parent keeps working unchanged.
- Variables are methods returning a reference: `body->ADSAngle() = 1.0f;`.
- Bit-packed bools (rare in Blueprints) get a getter and a setter overload instead.
- Out parameters are pointers, as in Dumper-7. Struct, string and container inputs
  are passed by const reference.
- Blueprint function libraries produce `static` methods. Interfaces produce `static`
  methods whose first parameter is the target `uevr::API::UObject*`.
- Functions are inline. There is no `_functions.cpp` to add to the project file.

For each User Defined Enum, `<AssetName>_structs.hpp`. Both the display names and the
internal `NewEnumeratorN` names are emitted, so existing code keeps compiling.

For each User Defined Struct, `<AssetName>_structs.hpp` holds a view type: a single
`uint8_t* Data` plus name-resolved accessors. Accessor names are the names shown in
the editor, not the GUID-suffixed internal names. `TArray` of such a struct is exposed
as `bridge::StructArray<View>`, and a struct returned from a function as
`bridge::Boxed<View>`.

`Bridge.hpp` is copied from `Resources/` into the output folder. `BridgeSDK.hpp`
includes everything.

## Switching the UEVR plugin over

1. Run the commandlet with `-OutDir` pointing at `SystemShockVR/BridgeSDK`.
2. Delete `SystemShockVR/SDK/_*` and remove the `SDK\_*_functions.cpp` entries from
   `SystemShockVR.vcxproj`.
3. Change `#include "SDK/_X_classes.hpp"` to `#include "BridgeSDK/_X_classes.hpp"`.
4. Change field access to calls: `g_vr_body->HandInteractionRight->IsHoldingWeapon`
   becomes `g_vr_body->HandInteractionRight()->IsHoldingWeapon()`. The compiler
   reports every site that still needs the change.
5. Replace `E_ENUM_VRHandPose::NewEnumerator3` with the display name if wanted. The
   old spelling still compiles.

## Naming rules

Identifiers follow Dumper-7 so that a generated header is a drop-in replacement:

- Classes: `A` for actors, `U` otherwise, `I` for interfaces, plus the class name
  (`A_BP_VRBody_C`).
- Structs: `F` plus the struct name (`F_STRUCT_MontageMeta`).
- Enums: unchanged if the name starts with `E`, otherwise `E` is prefixed
  (`E_ENUM_VRHand`, `ENUM_InteractResultType`).
- Characters that are not letters, digits or `_` become `_`. A leading digit gets a
  `_` in front. C++ keywords get a `_` appended.
- Header names are `<Package>_classes.hpp` and `<Package>_structs.hpp`, where
  `<Package>` is the last segment of the asset's package path.

If a Blueprint variable has the same name as a function in its class, or as
`StaticClass`, `GetDefaultObj`, `BridgeClass` or `BridgeClassPath`, the accessor gets
a `_` suffix.

## Not supported

These produce a `// skipped ...` comment instead of an accessor or method:

- `TMap` or `TSet` whose key or value is a User Defined Struct.
- A User Defined Struct that is outside the scanned set (different prefix or path).
- Property types not listed in `BridgeTypeMapper.cpp` (for example `FFieldPath`,
  sparse multicast delegates).

Delegates are exposed as references to Dumper-7's `TDelegate` and
`TMulticastInlineDelegate` types. Binding them from C++ is no more supported than it
was with Dumper-7.

## Runtime behaviour

- The first access to a class, property or function resolves it through the UEVR
  API. Later accesses reuse the cached class pointer, property offset or function
  pointer.
- Function pointers and parameter offsets are cached per target class. Calling the
  same wrapper on an object of a Blueprint subclass re-resolves once, so the subclass
  override is used.
- A class that is not loaded yet is looked up again on the next access. A name that
  does not exist logs `[bridge] ... not found` through the UEVR log and throws
  `std::runtime_error`.
- Everything is meant for the game thread, matching how UEVR calls into the plugin.
