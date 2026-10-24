---
name: release-plugin
description: Build a release of the mod as a UEVR profile zip (SystemReShock-Win64-Shipping.zip) for the current version. Builds the plugin, stages the profile, plugin and paks like the installer, and writes the zip under releases\. It does not change the version. Use when the user says "release the plugin", "make a release" or "/release-plugin".
disable-model-invocation: true
allowed-tools: PowerShell, Bash, Read
argument-hint: [--pak-dir <folder>]
---

# Release the plugin as a UEVR profile zip

Runs `scripts\release-plugin.py`, which makes `SystemReShock-Win64-Shipping.zip`: the UEVR profile
of the mod with the plugin DLL and both paks, the same files the installer embeds.

The release uses the version that is already set. Bumping the version is a separate step (see
"Bumping the version" in `.claude/rules/build.md`), done before the release when needed. This
skill never changes the version.

## Steps

1. From the repository root, run:

   ```powershell
   python scripts\release-plugin.py
   ```

   Pass `--pak-dir <folder>` only when the user names another folder for
   `pakchunk10-WindowsNoEditor.pak`. The default is the Unreal project's packaged paks.

   The script:
   - checks that the profile, the Addon pak and the Core chunk exist;
   - reads the version from `InformationalVersion` in the installer project, and stops when
     `remarks` in `profile\ProfileMeta.json` is not the same version;
   - builds the plugin (Release x64), which reads the same version;
   - stages the profile without `imgui.ini`, the DLL in `plugins\`, and the Core chunk in `paks\`
     as `SystemShockVRModCore_P.pak`;
   - writes `releases\<version>_<timestamp>\SystemReShock-Win64-Shipping.zip`.

2. If the script fails, show its error and stop. When the two versions do not match, do not
   fix them; tell the user to finish the version bump.

3. On success, report the version, the zip path and size, the plugin build index, and the Core
   pak's date from the script's output. The script does not package the Unreal project: if the
   Core pak is older than the latest content change, say so.

## Rules

- This does not change the version, build the installer, commit or publish anything.
  `releases\` is gitignored.
- Follow `.claude/rules/build.md`.
