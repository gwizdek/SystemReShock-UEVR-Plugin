# BridgeSDK generator (UEVRBridgeGen)

UEVRBridgeGen is an Unreal Engine 4.27 editor plugin that lives in
`tools/UEVRBridgeGen/`. It runs as a commandlet inside the mod's Unreal project
and writes the C++ headers in `SystemShockVR/BridgeSDK/`. Those headers wrap the
mod's own Blueprint classes, enums and structs so the UEVR plugin can use them
without hard-coded memory offsets.

## Why it exists

Dumper-7 headers hard-code the memory offset of every variable. That works for
the game's own classes, because the game binary does not change. It does not
work for the mod's Blueprints. Every time a variable is added or removed in a
Blueprint, the offsets shift, and the plugin reads wrong memory until the game
is dumped again.

The generated headers find each variable and function by name through the UEVR
API instead, and cache the result. They are produced from the Unreal project,
so they match the paks you build, and no game run is needed.

## How to use it

### Regenerate after a Blueprint change

Run the script from the repository root:

```powershell
.\tools\UEVRBridgeGen\Generate.ps1
```

It reads `tools/UEVRBridgeGen/bridgegen.config.json`, runs the commandlet, and
prints what was written. Then rebuild `SystemShockVR` so the new headers
compile. The compiler reports every call site that a renamed or removed
Blueprint member breaks. Generation takes about a minute, most of it editor
start-up.

### Regenerate after a generator change

Pass `-RebuildGen` when something under `tools/UEVRBridgeGen/Source/` or
`Resources/` changed:

```powershell
.\tools\UEVRBridgeGen\Generate.ps1 -RebuildGen
```

The script then builds the editor target before generating, so the commandlet
runs with the new code. The build takes about half a minute when little
changed.

### The config file

`tools/UEVRBridgeGen/bridgegen.config.json` holds the machine-specific paths and
the generator options. It is the one place an agent or a script needs to read.

| Key | Meaning |
|---|---|
| `engineDir` | Root of the UE 4.27 install. `Build.bat` and `UE4Editor-Cmd.exe` are found under it. |
| `project` | Full path to the `.uproject` that holds the mod's Blueprints. |
| `buildTarget` | Editor target that `-RebuildGen` builds. `UE4Editor` for a Blueprint-only project. |
| `outDir` | Where the headers go, relative to the repository root. |
| `paths` | Comma-separated content paths to scan, recursively. |
| `prefix` | Only assets whose name starts with this prefix. `_` selects the mod's Blueprints. |
| `sdkInclude` | Include path from `outDir` to the Dumper-7 SDK folder. |
| `uevrInclude` | Include path from `outDir` to the UEVR API header. |
| `aggregate` | Name of the header that includes every generated header. |

The script passes each option to the commandlet as `-Key=Value`. Running the
commandlet by hand works too; `tools/UEVRBridgeGen/README.md` shows the command.

### First-time setup on a new machine

1. Make `Plugins/UEVRBridgeGen` in the Unreal project a directory junction to
   `tools/UEVRBridgeGen` in this repository. The README shows the `mklink`
   command.
2. Set `engineDir` and `project` in the config file.
3. Run `Generate.ps1 -RebuildGen`. The first build compiles the plugin from
   scratch and takes a few minutes.

A Blueprint-only project needs to be compiled once it contains a code plugin.
Opening the project in the editor and accepting the rebuild prompt does the
same as the script's build step.

### What to do with the output

- Include the header for the class you need, for example
  `BridgeSDK/_BP_VRBody_classes.hpp`. `BridgeSDK.hpp` includes everything.
- Variables are methods that return a reference: `body->ADSAngle() = 1.0f;`.
- Functions are inline methods with the same signature style as Dumper-7. Out
  parameters are pointers. Struct, string and container inputs are `const&`.
- Call `SDK::BridgeWarmupAll()` once the mod's classes are loaded. See
  `bridge-sdk-warmup.md`.
- Do not edit the generated files. The generator overwrites them.

Generated files for Blueprints that no longer exist are not deleted. Remove them
by hand.

## How it works

### The commandlet

`UUEVRBridgeGenCommandlet::Main` runs these steps in order:

1. **Parse options** from the command line into `FBridgeGenOptions`.
2. **Collect targets.** It asks the Asset Registry for every `UBlueprint`,
   `UUserDefinedEnum` and `UUserDefinedStruct` under the configured paths,
   keeps the ones whose name starts with the prefix, and loads them. A
   Blueprint contributes its generated class.
3. **Fill the context.** `FBridgeContext` records the set of generated types.
   The writers use it to decide whether a type comes from a generated header or
   from the Dumper-7 SDK.
4. **Write one header per target.** Classes go to `<Package>_classes.hpp`,
   enums and structs to `<Package>_structs.hpp`. A file is only written when
   its content changed, so an unchanged header does not trigger a recompile.
5. **Copy `Bridge.hpp`** from `tools/UEVRBridgeGen/Resources/` into the output
   folder, replacing the `@UEVR_API_INCLUDE@` marker with `uevrInclude`.
6. **Write the aggregate header** with an include for every generated file and
   the `SDK::BridgeWarmupAll()` function.

### The writers

Each writer turns one reflected type into text.

- **`FBridgeClassWriter`** writes a class that derives from the Dumper-7 parent
  and adds no data members. Every parent member keeps working. It emits one
  accessor per Blueprint variable, one method per Blueprint function, and the
  `BridgeWarmup()` function. The ubergraph frame pointer, delegate signatures
  and the `ExecuteUbergraph` entry point are skipped, because they are compiler
  bookkeeping, not part of the Blueprint's interface.
- **`FBridgeFunctionWriter`** writes one function. It maps each parameter,
  builds the signature, and emits the body: create a `bridge::Call`, copy the
  inputs into the parameter buffer, invoke, copy the outputs back. Static
  functions of a function library are dispatched on the class default object.
  Interface functions take the target `uevr::API::UObject*` as their first
  parameter.
- **`FBridgeEnumStructWriter`** writes enums as a plain `enum class`, with both
  the display names and the internal `NewEnumeratorN` names. It writes a User
  Defined Struct as a view: a single `uint8_t* Data` plus name-resolved
  accessors. The layout of such a struct is not fixed, so the view never
  assumes one.
- **`FBridgeHeaderBuilder`** collects the includes and forward declarations a
  header needs, and assembles the file. A type that is only used through a
  pointer gets a forward declaration. A type that is used by value, as a parent
  or as an enum gets an include.
- **`FBridgeTypeMapper`** turns an `FProperty` into a Dumper-7 compatible C++
  type string. It handles numbers, bools, enums, structs, object pointers and
  the soft, weak, lazy and interface pointer templates, `TArray`, `TMap`,
  `TSet`, delegates, `FName`, `FString` and `FText`. Anything else becomes a
  `// skipped` comment with the reason.
- **`BridgeNaming`** produces the same identifiers as Dumper-7: `A` for actors,
  `I` for interfaces, `U` for other classes, `F` for structs, and `E` in front
  of an enum name that does not start with one. Characters that are not valid
  in an identifier become `_`, and C++ keywords get a `_` suffix. This is what
  makes a generated header a drop-in replacement for the dumped one.

### The runtime, `Bridge.hpp`

The generated headers contain no lookup code themselves. They hold names, and
`Bridge.hpp` resolves them.

- `ObjectRef` finds a class or struct by its full path through
  `find_uobject` on first use and keeps the pointer. A miss is not cached, so a
  class that loads later is still found.
- `Prop` holds one property. On first use it walks the class and its parents
  with `find_property`, and caches the property and its offset. After that an
  access is the object address plus the cached offset. Bit-packed bools go
  through `FBoolProperty` instead, because a bit has no address.
- `Func` holds one function and the names of its parameters. On first use it
  finds the `UFunction` in the target's class hierarchy, then each parameter's
  offset inside the parameter block. It caches per target class, so calling the
  same wrapper on a Blueprint subclass resolves once more and uses the override.
- `Call` is a zeroed parameter buffer for one invocation. It lives on the stack
  up to 512 bytes and on the heap above that. `invoke()` calls
  `process_event` on the target.
- `StructArray<View>` is a `TArray` whose element is a User Defined Struct.
  `Boxed<View>` owns the bytes of a struct returned from a function.
- `warm()` resolves a list of `Prop` or `Func` entries ahead of time.

Name lookups match Unreal's rules: exact match first, then case-insensitive,
because the cooked game may store a different casing than the editor.

A name that cannot be resolved logs `[bridge] ... not found` through the UEVR
log and throws `std::runtime_error`. The plugin's frame callbacks catch it.

## Limits

These produce a `// skipped` comment instead of an accessor or method:

- `TMap` or `TSet` whose key or value is a User Defined Struct.
- A User Defined Struct outside the scanned set, for example one under a path
  or prefix that was not generated.
- Property types the mapper does not know, such as `FFieldPath` or sparse
  multicast delegates.

Delegates are exposed as references to Dumper-7's `TDelegate` and
`TMulticastInlineDelegate` types. Binding them from C++ is not supported, the
same as with Dumper-7.

Everything is meant for the game thread, which is how UEVR calls into the
plugin.

## Files

| What | Where |
|---|---|
| Config read by the script | `tools/UEVRBridgeGen/bridgegen.config.json` |
| Build and generate script | `tools/UEVRBridgeGen/Generate.ps1` |
| Plugin descriptor and module | `tools/UEVRBridgeGen/UEVRBridgeGen.uplugin`, `Source/UEVRBridgeGen/` |
| Commandlet | `Source/UEVRBridgeGen/Private/UEVRBridgeGenCommandlet.cpp` |
| Writers, naming, type mapper | `Source/UEVRBridgeGen/Private/Bridge*.cpp` |
| Runtime header source | `tools/UEVRBridgeGen/Resources/Bridge.hpp` |
| Generated output | `SystemShockVR/BridgeSDK/` |
| Command-line reference | `tools/UEVRBridgeGen/README.md` |
| Build output, ignored by git | `tools/UEVRBridgeGen/Binaries/`, `Intermediate/` |
