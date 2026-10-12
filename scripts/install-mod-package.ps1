<#
.SYNOPSIS
    Installs a mod package made by package-mod.ps1 on this PC.

.DESCRIPTION
    Run install.ps1 from inside the package folder. It copies:

      uevr\     -> the UEVR folder (default D:\UEVR)
      profile\  -> %AppData%\UnrealVRMod\SystemReShock-Win64-Shipping
      paks\     -> <game>\SystemShock\Content\Paks

    The game must not be running.

.PARAMETER UevrPath
    Where to put UEVR on this PC. Default D:\UEVR.

.PARAMETER GamePath
    Game folder on this PC. Default the Steam install.

.PARAMETER ProfilePath
    UEVR profile folder on this PC. Default the SystemReShock profile.
#>
[CmdletBinding()]
param(
    [string]$UevrPath = 'D:\UEVR',
    [string]$GamePath = 'C:\Program Files (x86)\Steam\steamapps\common\System Shock Remake',
    [string]$ProfilePath = (Join-Path $env:APPDATA 'UnrealVRMod\SystemReShock-Win64-Shipping')
)

$ErrorActionPreference = 'Stop'
$packageRoot = $PSScriptRoot

if (Get-Process -Name 'SystemReShock-Win64-Shipping' -ErrorAction SilentlyContinue) {
    throw 'Close the game first.'
}

function Copy-Tree([string]$Source, [string]$Target) {
    if (-not (Test-Path -LiteralPath $Source)) { return }
    New-Item -ItemType Directory -Force -Path $Target | Out-Null

    & robocopy $Source $Target /E /NFL /NDL /NJH /NJS /NP
    if ($LASTEXITCODE -ge 8) { throw "robocopy failed ($LASTEXITCODE) copying $Source" }
}

Copy-Tree (Join-Path $packageRoot 'uevr') $UevrPath
Copy-Tree (Join-Path $packageRoot 'profile') $ProfilePath

$pakSource = Join-Path $packageRoot 'paks'
$pakTarget = Join-Path $GamePath 'SystemShock\Content\Paks'
if (-not (Test-Path -LiteralPath $GamePath)) { throw "Game folder not found: $GamePath" }
New-Item -ItemType Directory -Force -Path $pakTarget | Out-Null
Get-ChildItem -LiteralPath $pakSource -Filter '*.pak' -ErrorAction SilentlyContinue | ForEach-Object {
    Copy-Item -LiteralPath $_.FullName -Destination $pakTarget -Force
}

Write-Host 'Installed.'
Write-Host "  UEVR:    $UevrPath"
Write-Host "  Profile: $ProfilePath"
Write-Host "  Paks:    $pakTarget"
