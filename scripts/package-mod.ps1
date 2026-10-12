<#
.SYNOPSIS
    Collects the working System Shock VR mod setup into one folder so it can be
    copied to another PC and installed there with install.ps1.

.DESCRIPTION
    Gathers three things from this PC:

      uevr\     the UEVR folder, without .pdb files (large, debug only)
      profile\  %AppData%\UnrealVRMod\SystemReShock-Win64-Shipping
      paks\     SystemShockVRModCore_P.pak and SystemShockVRModAddon_P.pak

    and drops install.ps1 next to them. Copy the resulting folder to the other
    PC (for example through a shared folder), then run install.ps1 there.

.PARAMETER Destination
    Folder to write the package to. Defaults to a _mod-package folder next to
    the repository.

.PARAMETER UevrPath
    UEVR folder on this PC. Default D:\UEVR.

.PARAMETER GamePath
    Game folder on this PC. Default the Steam install.

.PARAMETER ProfilePath
    UEVR profile folder on this PC. Default the SystemReShock profile.

.PARAMETER IncludePdb
    Also copy the UEVR .pdb files (large, only useful for debugging).
#>
[CmdletBinding()]
param(
    [string]$Destination,
    [string]$UevrPath = 'D:\UEVR',
    [string]$GamePath = 'C:\Program Files (x86)\Steam\steamapps\common\System Shock Remake',
    [string]$ProfilePath = (Join-Path $env:APPDATA 'UnrealVRMod\SystemReShock-Win64-Shipping'),
    [switch]$IncludePdb
)

$ErrorActionPreference = 'Stop'
$repoRoot = Split-Path -Parent $PSScriptRoot
if (-not $Destination) { $Destination = Join-Path (Split-Path -Parent $repoRoot) '_mod-package' }

function Copy-Tree([string]$Source, [string]$Target, [string[]]$Exclude) {
    if (-not (Test-Path -LiteralPath $Source)) { throw "Missing folder: $Source" }
    New-Item -ItemType Directory -Force -Path $Target | Out-Null

    $roboArgs = @($Source, $Target, '/E', '/NFL', '/NDL', '/NJH', '/NJS', '/NP')
    if ($Exclude.Count -gt 0) { $roboArgs += (@('/XF') + $Exclude) }

    & robocopy @roboArgs
    if ($LASTEXITCODE -ge 8) { throw "robocopy failed ($LASTEXITCODE) copying $Source" }
}

$pdbExclude = @()
if (-not $IncludePdb) { $pdbExclude = @('*.pdb') }

Copy-Tree $UevrPath (Join-Path $Destination 'uevr') $pdbExclude
Copy-Tree $ProfilePath (Join-Path $Destination 'profile') @()

$pakSource = Join-Path $GamePath 'SystemShock\Content\Paks'
$pakTarget = Join-Path $Destination 'paks'
New-Item -ItemType Directory -Force -Path $pakTarget | Out-Null
foreach ($pak in 'SystemShockVRModCore_P.pak', 'SystemShockVRModAddon_P.pak') {
    $source = Join-Path $pakSource $pak
    if (-not (Test-Path -LiteralPath $source)) { throw "Missing pak: $source" }
    Copy-Item -LiteralPath $source -Destination $pakTarget -Force
}

Copy-Item -LiteralPath (Join-Path $PSScriptRoot 'install-mod-package.ps1') -Destination (Join-Path $Destination 'install.ps1') -Force

Write-Host "Package written to $Destination"
Write-Host 'Copy that folder to the other PC, then run install.ps1 there.'
