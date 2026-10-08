---
name: bytecode-exporter
description: Export the Blueprint bytecode, variables, components, widget tree and enums of one game asset as JSON with tools\BytecodeExporter. Use when the user says "/bytecode-exporter <AssetName>", "export the bytecode of X", "decompile X" or wants to read what a Blueprint function does.
disable-model-invocation: true
allowed-tools: PowerShell, Bash, Read, Glob, Grep
---

# Export the bytecode of one asset

Runs `tools\BytecodeExporter` on the asset named in the arguments. The asset is looked up by
name under `dumps\assets\` (the unpacked game pak). The output lands in a folder named like
the asset, next to the asset, for example
`dumps\assets\SystemShock\Content\Blueprints\Characters\Hopper\PAWN_Hopper\`.

Arguments: `$ARGUMENTS`

## Steps

1. From the repository root, run:

   ```powershell
   powershell -ExecutionPolicy Bypass -File scripts\export-bytecode.ps1 <asset>
   ```

   `<asset>` is the first argument: a name such as `PAWN_Hopper`, with or without `.uasset`,
   or a full path to a `.uasset` file. The script builds the exporter first when its EXE is
   missing. Pass `-Rebuild` when the user changed the exporter's source.
   Pass `-OutDir <folder>` only when the user asks for another output folder.

2. If the script reports several assets with that name, show the list and ask the user which
   one they mean. Then run the script again with that full path.

3. If the script reports that no asset was found, say so and stop. Do not unpack the pak.
   `dumps\assets\` must already hold the asset; see `tools\BytecodeExporter\README.md`.

4. If the build or the export fails, show the error output and stop.

5. On success, report in two or three lines: the output folder, the counts the exporter
   printed (bytecode files, variables, components, widgets, enums), and the file names a reader
   usually starts with: `ExecuteUbergraph_<Asset>.bytecode`, `variables.json`, `components.json`,
   `widgets.json` for a widget Blueprint, `enums.json` for an enum.

## Rules

- Run the exporter only. Do not read or summarize the output unless the user asks.
- The output folder is under `dumps\`, which is gitignored. Never commit it.
- Follow `.claude/rules/build.md` for the build; the EXE is in
  `tools\BytecodeExporter\bin\Release\net8.0\`.
