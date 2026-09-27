<#
.SYNOPSIS
    Builds the UEVR plugin and copies it into the UEVR profile plugins folder.

.DESCRIPTION
    Runs MSBuild on SystemShockVR\SystemShockVR.vcxproj (x64) and copies the
    resulting SystemReShockVR.dll and .pdb into the UEVR plugins folder.
    The plugin must be unloaded in the UEVR overlay before deploying, and
    reloaded there afterwards. Both are manual steps.

.PARAMETER Configuration
    Release (default) or Debug.

.PARAMETER PluginsDir
    Target folder. Defaults to the UEVR profile for SystemReShock.

.PARAMETER SkipBuild
    Copy the already built DLL without building.
#>
[CmdletBinding()]
param(
    [ValidateSet('Release', 'Debug')]
    [string]$Configuration = 'Release',
    [string]$PluginsDir = (Join-Path $env:APPDATA 'UnrealVRMod\SystemReShock-Win64-Shipping\plugins'),
    [switch]$SkipBuild
)

$ErrorActionPreference = 'Stop'
$repoRoot = Split-Path -Parent $PSScriptRoot
$project = Join-Path $repoRoot 'SystemShockVR\SystemShockVR.vcxproj'
$outDir = Join-Path $repoRoot "SystemShockVR\x64\$Configuration"

function Find-MSBuild {
    $vswhere = "${env:ProgramFiles(x86)}\Microsoft Visual Studio\Installer\vswhere.exe"
    if (Test-Path $vswhere) {
        $found = & $vswhere -latest -products * -requires Microsoft.Component.MSBuild -find 'MSBuild\**\Bin\MSBuild.exe' | Select-Object -First 1
        if ($found) { return $found }
    }
    $onPath = Get-Command msbuild -ErrorAction SilentlyContinue
    if ($onPath) { return $onPath.Source }
    throw 'MSBuild not found. Install Visual Studio with the C++ workload.'
}

if (-not $SkipBuild) {
    $msbuild = Find-MSBuild
    Write-Host "Building plugin ($Configuration) with $msbuild"
    & $msbuild $project /p:Configuration=$Configuration /p:Platform=x64 /m /v:m /nologo
    if ($LASTEXITCODE -ne 0) { throw "Plugin build failed with exit code $LASTEXITCODE" }
}

$dll = Join-Path $outDir 'SystemReShockVR.dll'
if (-not (Test-Path $dll)) { throw "Built DLL not found: $dll" }

New-Item -ItemType Directory -Force -Path $PluginsDir | Out-Null

# Copies one file into the plugins folder. The running game keeps the loaded DLL locked,
# so the plugin must be unloaded in the UEVR overlay before deploying.
function Deploy-File([string]$Source) {
    $target = Join-Path $PluginsDir (Split-Path -Leaf $Source)
    try {
        Copy-Item $Source -Destination $target -Force -ErrorAction Stop
    }
    catch [System.IO.IOException] {
        throw "Cannot overwrite $target because the game has it loaded. Unload the plugin in the UEVR overlay, then run this script again."
    }
}

Deploy-File $dll
$pdb = Join-Path $outDir 'SystemReShockVR.pdb'
if (Test-Path $pdb) { Deploy-File $pdb }

$deployed = Get-Item (Join-Path $PluginsDir 'SystemReShockVR.dll')
Write-Host "Deployed $($deployed.FullName) ($($deployed.Length) bytes, $($deployed.LastWriteTime))"
Write-Host 'Reload the plugin from the UEVR overlay to pick it up.'
