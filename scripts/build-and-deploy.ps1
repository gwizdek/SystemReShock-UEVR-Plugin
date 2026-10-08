<#
.SYNOPSIS
    Builds a UEVR plugin from this repository and deploys it for the running game.

.DESCRIPTION
    Runs MSBuild on the chosen project (x64) and copies the result where UEVR, or the
    plugin hot loader, picks it up.

    The plugin (default target) goes to the hot loader's watched folder. The hot loader
    plugin, PluginHotLoader.dll, loads a copy of it and swaps to a new build by itself a
    second or so after the copy, while the game runs. No overlay step is needed. See
    documentation\plugin-hot-reload.md.

    PluginHotLoader and PakHotReloader go to the UEVR plugins folder. The game keeps those
    DLLs locked, so they must be unloaded in the UEVR overlay before they can be replaced.

.PARAMETER Target
    Plugin (default) builds SystemShockVR\SystemShockVR.vcxproj -> SystemReShockVR.dll.
    PluginHotLoader builds tools\PluginHotLoader\PluginHotLoader.vcxproj -> PluginHotLoader.dll.
    PakHotReloader builds tools\PakHotReloader\PakHotReloader.vcxproj -> PakHotReloader.dll.

.PARAMETER Configuration
    Release (default) or Debug.

.PARAMETER ProfileDir
    The UEVR profile folder. Defaults to the profile for SystemReShock.

.PARAMETER Direct
    Plugin target only: copy SystemReShockVR.dll straight into the UEVR plugins folder, without
    the hot loader. The plugin must then be unloaded in the UEVR overlay before deploying and
    reloaded there afterwards.

.PARAMETER SkipBuild
    Copy the already built DLL without building.
#>
[CmdletBinding()]
param(
    [ValidateSet('Plugin', 'PluginHotLoader', 'PakHotReloader')]
    [string]$Target = 'Plugin',
    [ValidateSet('Release', 'Debug')]
    [string]$Configuration = 'Release',
    [string]$ProfileDir = (Join-Path $env:APPDATA 'UnrealVRMod\SystemReShock-Win64-Shipping'),
    [switch]$Direct,
    [switch]$SkipBuild
)

$ErrorActionPreference = 'Stop'
$repoRoot = Split-Path -Parent $PSScriptRoot
$pluginsDir = Join-Path $ProfileDir 'plugins'
$hotPluginsDir = Join-Path $ProfileDir 'hot_plugins'

$targets = @{
    Plugin          = @{ Project = 'SystemShockVR\SystemShockVR.vcxproj';            OutDir = 'SystemShockVR\x64';            Dll = 'SystemReShockVR.dll' }
    PluginHotLoader = @{ Project = 'tools\PluginHotLoader\PluginHotLoader.vcxproj'; OutDir = 'tools\PluginHotLoader\x64'; Dll = 'PluginHotLoader.dll' }
    PakHotReloader  = @{ Project = 'tools\PakHotReloader\PakHotReloader.vcxproj';   OutDir = 'tools\PakHotReloader\x64';   Dll = 'PakHotReloader.dll' }
}
$selected = $targets[$Target]
$project = Join-Path $repoRoot $selected.Project
$outDir = Join-Path $repoRoot "$($selected.OutDir)\$Configuration"

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

function Build-Target {
    $msbuild = Find-MSBuild
    Write-Host "Building $Target ($Configuration) with $msbuild"
    & $msbuild $project /p:Configuration=$Configuration /p:Platform=x64 /m /v:m /nologo
    if ($LASTEXITCODE -ne 0) { throw "$Target build failed with exit code $LASTEXITCODE" }
}

# Copies one file into a folder that UEVR loads from directly. The running game keeps such a
# DLL locked, so it must be unloaded in the UEVR overlay first.
function Deploy-Locked([string]$Source, [string]$Folder) {
    $destination = Join-Path $Folder (Split-Path -Leaf $Source)
    try {
        Copy-Item $Source -Destination $destination -Force -ErrorAction Stop
    }
    catch [System.IO.IOException] {
        throw "Cannot overwrite $destination because the game has it loaded. Unload the plugin in the UEVR overlay, then run this script again."
    }
    return $destination
}

# Copies one file into the hot loader's watched folder. The file is written under a temporary
# name and renamed into place, so the loader never sees a half-written DLL.
function Deploy-Watched([string]$Source, [string]$Folder) {
    $destination = Join-Path $Folder (Split-Path -Leaf $Source)
    $temporary = "$destination.tmp"
    Copy-Item $Source -Destination $temporary -Force
    Move-Item $temporary -Destination $destination -Force
    return $destination
}

function Assert-HotLoaderSetup {
    $direct = Join-Path $pluginsDir 'SystemReShockVR.dll'
    if (Test-Path $direct) {
        throw "$direct exists. UEVR would load it directly and the hot loader would load a second copy. Unload the plugin in the UEVR overlay, delete that file and run again. Pass -Direct to deploy without the hot loader."
    }
    if (-not (Test-Path (Join-Path $pluginsDir 'PluginHotLoader.dll'))) {
        Write-Warning "PluginHotLoader.dll is not in $pluginsDir. Deploy it once with -Target PluginHotLoader, otherwise nothing loads the plugin."
    }
}

if (-not $SkipBuild) { Build-Target }

$dll = Join-Path $outDir $selected.Dll
if (-not (Test-Path $dll)) { throw "Built DLL not found: $dll" }
$pdb = [System.IO.Path]::ChangeExtension($dll, '.pdb')

if ($Target -eq 'Plugin' -and -not $Direct) {
    Assert-HotLoaderSetup
    New-Item -ItemType Directory -Force -Path $hotPluginsDir | Out-Null
    $deployedPath = Deploy-Watched $dll $hotPluginsDir
    # No .pdb: the loader runs a renamed copy, and the debugger finds the symbols through the
    # build path stored in the DLL.
    $deployed = Get-Item $deployedPath
    Write-Host "Deployed $($deployed.FullName) ($($deployed.Length) bytes, $($deployed.LastWriteTime))"
    Write-Host 'The hot loader swaps to it within a few seconds. Watch log.txt for [inner_plugin][load].'
}
else {
    New-Item -ItemType Directory -Force -Path $pluginsDir | Out-Null
    $deployedPath = Deploy-Locked $dll $pluginsDir
    if (Test-Path $pdb) { Deploy-Locked $pdb $pluginsDir | Out-Null }
    $deployed = Get-Item $deployedPath
    Write-Host "Deployed $($deployed.FullName) ($($deployed.Length) bytes, $($deployed.LastWriteTime))"
    Write-Host 'Reload the plugin from the UEVR overlay to pick it up.'
}
