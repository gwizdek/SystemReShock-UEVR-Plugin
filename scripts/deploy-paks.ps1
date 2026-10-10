<#
.SYNOPSIS
    Copies the Core pak built by the Unreal project into the game's pak folder.

.DESCRIPTION
    Removes every old copy of the Core pak from the game's pak folder, then copies
    pakchunk10-WindowsNoEditor.pak from the Unreal project's packaged output into that folder
    under the name the installer ships it with, SystemShockVRModCore_P.pak.

    The defaults point at the Steam install, which is the development install
    (see .claude\rules\game-installs.md). Nothing is built; package the Unreal project first.

.PARAMETER PakSourceDir
    The Unreal project's packaged pak folder. Only pakchunk10-WindowsNoEditor.pak is taken from it.

.PARAMETER GamePaksDir
    The game's pak folder. Defaults to the Steam install.
#>
[CmdletBinding()]
param(
    [string]$PakSourceDir = 'D:\Unreal Engine\Projects\SystemReShock-UE4-Project\WindowsNoEditor\SystemShock\Content\Paks',
    [string]$GamePaksDir = 'D:\Steam\steamapps\common\System Shock Remake\SystemShock\Content\Paks'
)

$ErrorActionPreference = 'Stop'

$sourceName = 'pakchunk10-WindowsNoEditor.pak'
$targetName = 'SystemShockVRModCore_P.pak'
# Names the Core pak has been deployed under. All of them are removed so only one copy is mounted.
$oldNames = @('pakchunk10-WindowsNoEditor.pak', 'pakchunk10-WindowsNoEditor_P.pak', $targetName)

$sourcePak = Join-Path $PakSourceDir $sourceName
if (-not (Test-Path $sourcePak)) { throw "Source pak not found: $sourcePak. Package the Unreal project first." }
if (-not (Test-Path $GamePaksDir)) { throw "Game pak folder not found: $GamePaksDir" }

# The game keeps a mounted pak locked, so a failed removal means the game is running with it.
function Remove-OldPak([string]$Path) {
    if (-not (Test-Path $Path)) { return }
    try {
        Remove-Item $Path -Force -ErrorAction Stop
        Write-Host "Removed $Path"
    }
    catch {
        throw "Cannot remove $Path because the game has it mounted. Close the game and run again."
    }
}

foreach ($name in $oldNames) {
    Remove-OldPak (Join-Path $GamePaksDir $name)
}

$destination = Join-Path $GamePaksDir $targetName
Copy-Item $sourcePak -Destination $destination -Force
$deployed = Get-Item $destination
Write-Host "Deployed $($deployed.FullName) ($($deployed.Length) bytes, $($deployed.LastWriteTime))"
