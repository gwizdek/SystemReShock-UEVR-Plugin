---
name: release-plugin
description: Build a release of the mod as a UEVR profile zip (SystemReShock-Win64-Shipping.zip) for a given version, for example 2.0-beta.4. Sets the version, builds the plugin, stages the profile, plugin and paks like the installer, and writes the zip under releases\. Use when the user says "release the plugin", "make a release" or "/release-plugin <version>".
disable-model-invocation: true
allowed-tools: PowerShell, Bash, Read
argument-hint: <version, for example 2.0-beta.4>
---

# Release the plugin as a UEVR profile zip

Runs `scripts\release-plugin.py`, which makes `SystemReShock-Win64-Shipping.zip`: the UEVR profile
of the mod with the plugin DLL and both paks, the same files the installer embeds.

## Steps

1. **The version is required.** Take it from the arguments: `$ARGUMENTS`. If it is empty, stop
   and ask the user for the version. Do not guess it and do not reuse the current one. The script
   itself also stops without a version, and when the version is not like `2.0-beta.4`.

2. From the repository root, run:

   ```powershell
   python scripts\release-plugin.py <version>
   ```

   Pass `--pak-dir <folder>` only when the user names another folder for
   `pakchunk10-WindowsNoEditor.pak`. The default is the Unreal project's packaged paks.

   The script:
   - checks that the profile, the Addon pak and the Core chunk exist, before it changes anything;
   - sets `InformationalVersion` in the installer project and `remarks` and `modifiedDate` in
     `profile\ProfileMeta.json`;
   - builds the plugin (Release x64), which reads the new version;
   - stages the profile without `imgui.ini`, the DLL in `plugins\`, and the Core chunk in `paks\`
     as `SystemShockVRModCore_P.pak`;
   - writes `releases\<version>_<timestamp>\SystemReShock-Win64-Shipping.zip`.

3. If the script fails, show its error and stop. If it failed after setting the version, say
   that the version files are changed.

4. On success, report the zip path and size, the plugin build index, and the Core pak's date
   from the script's output. The script does not package the Unreal project: if the Core pak is
   older than the latest content change, say so.

5. Say that the version change in `SystemReShockInstaller.csproj` and `profile\ProfileMeta.json`
   is not committed. Commit it only when the user asks.

## Rules

- This does not build the installer and does not publish anything. `releases\` is gitignored.
- Follow `.claude/rules/build.md`.
