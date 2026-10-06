# BytecodeExporter

A command line tool that reads one `.uasset` and writes its Blueprint bytecode, variables and
components as pretty JSON. It has no window. It uses the `UAssetAPI` NuGet package (the same
library that UAssetGUI is built on), so the output format of the bytecode is the same as
UAssetGUI's "pretty bytecode" view.

## Build

From PowerShell at the repository root:

```powershell
dotnet build tools\BytecodeExporter\BytecodeExporter.csproj -c Release
```

The EXE lands in `tools\BytecodeExporter\bin\Release\net8.0\BytecodeExporter.exe`. The first build
downloads `UAssetAPI` from NuGet; nothing has to be copied by hand.

## Run

```powershell
tools\BytecodeExporter\bin\Release\net8.0\BytecodeExporter.exe <asset.uasset> [--out <dir>] [--engine 4.27] [--mappings <file.usmap>]
```

- The `.uexp` file must sit next to the `.uasset`. Cooked assets always have one.
- `--out` picks another output folder. Without it, the tool creates a folder named like the asset,
  next to the asset. For `...\Hacker\PAWN_Hacker_Simple.uasset` that is `...\Hacker\PAWN_Hacker_Simple\`.
- `--engine` defaults to `4.27`, the version System Shock uses. Any `UAssetAPI` version name works,
  written as `4.27` or `5.3`.
- `--mappings` loads a `.usmap` file. The System Shock pak does not need one.

Exit code 0 means success, 1 means the asset could not be read, 2 means bad arguments.

`scripts\export-bytecode.ps1 <name>` finds an asset by name under `dumps\assets\`, builds the
exporter when the EXE is missing, and runs it. The `/bytecode-exporter <name>` skill calls that
script.

## Output

| File | Content |
|---|---|
| `<FunctionName>.bytecode` | One file per function (and per any other struct export that carries script, such as the class itself). Holds the function flags, its parameters and locals with their pin types, and the `Script` array from `KismetSerializer`. The `Script` array is the same JSON that UAssetGUI shows under `ScriptBytecode`. |
| `variables.json` | Every variable of the `BlueprintGeneratedClass`: name, property type, pin type, property flags, replication settings, and the default value taken from the class default object. |
| `components.json` | The `SimpleConstructionScript` tree: each `SCS_Node` with its variable name, component class, parent attachment, the component template with all its properties, and its child nodes. `OtherComponents` lists component templates that are not in the tree: components inherited from the native parent class (outer is the default object), `NODE_Add*` templates added by the construction script, and anything whose class name ends in `Component`. |
| `class.json` | The class header (super class, flags, interfaces, function map) and an index of every export in the package with its class, outer and `UAssetAPI` export kind. Use it to see what else the package holds, such as timelines, curves and delegate bindings. |

A function whose bytecode `KismetSerializer` cannot read still gets a file. Its `Script` value is
then an object with an `Error` key, and the error is printed to stderr.

Assets that are not Blueprints (textures, data tables, materials) produce only `class.json` and an
empty `components.json`. The tool does not fail on them.

## Where the data comes from

- Functions are `FunctionExport` objects whose outer is the `BlueprintGeneratedClass` export (the
  `..._C` class). The cooked pak holds only that class; the editor-side `Blueprint` object is not
  cooked.
- Variables are the `LoadedProperties` of the class export. Default values are the matching entries
  in the `Default__..._C` export.
- Components are `SCS_Node` exports owned by the `SimpleConstructionScript` export. Each node points
  to a `..._GEN_VARIABLE` template export that holds the component's edited properties.
