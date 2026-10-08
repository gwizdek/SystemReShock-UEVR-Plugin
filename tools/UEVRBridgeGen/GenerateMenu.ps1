<#
.SYNOPSIS
Creates the assets of the VR options page in the Unreal project.

.DESCRIPTION
Reads bridgegen.config.json next to this script for the engine folder and the Unreal
project, then runs the VROptionsMenuGen commandlet. It creates the dummy copies of the
game's menu classes and the mod's page, list and rows. Assets that already exist are
kept unless -Overwrite is given. Close the Unreal editor before running this.
Logs go to Intermediate\Generate\ next to this script.

See documentation\vr-options-menu.md for what the assets are.

.PARAMETER RebuildGen
Rebuild the editor plugin first. Needed after a change under Source\.

.PARAMETER Overwrite
Create every asset again, even when its package exists.

.PARAMETER ModRoot
Content path that receives the mod's widgets. Defaults to /Game/Mods/UI/Options.

.PARAMETER Config
Path to the config file. Defaults to bridgegen.config.json next to this script.

.EXAMPLE
.\GenerateMenu.ps1
.\GenerateMenu.ps1 -RebuildGen -Overwrite
#>
[CmdletBinding()]
param(
    [switch]$RebuildGen,
    [switch]$Overwrite,
    [string]$ModRoot = "/Game/Mods/UI/Options",
    [string]$Config
)

$ErrorActionPreference = "Stop"
$scriptDir = Split-Path -Parent $MyInvocation.MyCommand.Path
if (-not $Config) { $Config = Join-Path $scriptDir "bridgegen.config.json" }

function Assert-Exists([string]$Path, [string]$What) {
    if (-not (Test-Path -LiteralPath $Path)) {
        throw "$What not found: $Path (check $Config)"
    }
}

function Show-Errors([string]$LogPath) {
    Get-Content -LiteralPath $LogPath | Select-String -Pattern "error" -CaseSensitive:$false | Select-Object -First 20 | ForEach-Object { Write-Host $_.Line }
}

$cfg = Get-Content -LiteralPath $Config -Raw | ConvertFrom-Json
$buildBat = Join-Path $cfg.engineDir "Engine\Build\BatchFiles\Build.bat"
$editorCmd = Join-Path $cfg.engineDir "Engine\Binaries\Win64\UE4Editor-Cmd.exe"
$logDir = Join-Path $scriptDir "Intermediate\Generate"

Assert-Exists $cfg.project "Unreal project"
Assert-Exists $buildBat "Build.bat"
Assert-Exists $editorCmd "UE4Editor-Cmd.exe"
New-Item -ItemType Directory -Force -Path $logDir | Out-Null

if (Get-Process -Name "UE4Editor" -ErrorAction SilentlyContinue) {
    throw "The Unreal editor is running. Close it first: it locks the plugin DLL and the asset files."
}

if ($RebuildGen) {
    $buildLog = Join-Path $logDir "build.log"
    Write-Host "Building $($cfg.buildTarget) for $($cfg.project) ..."
    & $buildBat $cfg.buildTarget Win64 Development "-Project=$($cfg.project)" -WaitMutex *> $buildLog
    if ($LASTEXITCODE -ne 0) {
        Show-Errors $buildLog
        throw "Build failed (exit $LASTEXITCODE). Full log: $buildLog"
    }
    Write-Host "Build OK."
}

$genLog = Join-Path $logDir "generate-menu.log"
$arguments = @($cfg.project, "-run=VROptionsMenuGen", "-ModRoot=$ModRoot")
if ($Overwrite) { $arguments += "-Overwrite" }
$arguments += @("-unattended", "-nopause", "-nosplash", "-stdout", "-FullStdOutLogOutput")

Write-Host "Generating the VR options menu assets ..."
& $editorCmd @arguments *> $genLog
$exit = $LASTEXITCODE

# The commandlet's own lines are the useful part of the editor log.
Get-Content -LiteralPath $genLog | Select-String -Pattern "LogUEVRBridgeGen: " | ForEach-Object {
    Write-Host ($_.Line -replace '^.*LogUEVRBridgeGen: ', '')
}
if ($exit -ne 0) {
    Show-Errors $genLog
    throw "Generation failed (exit $exit). Full log: $genLog"
}
Write-Host "Done. Open the project in the editor to check the Blueprints, then cook."
