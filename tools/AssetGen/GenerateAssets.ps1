<#
.SYNOPSIS
Creates the mod's generated assets in the Unreal project.

.DESCRIPTION
Reads assetgen.config.json next to this script for the engine folder and the Unreal
project, then runs the ModAssetGen commandlet. It runs these generators, in this order:

  Menu         the VR options page (documentation\vr-options-menu.md)
  HudIcon      the HUD email icon (documentation\hud-materials-in-vr.md)
  ButtonAtlas  the VR controller button atlas (documentation\menu-icons.md)
  CyberHud     the cyberspace HUD (documentation\hud-materials-in-vr.md)

Assets that already exist are kept unless -Overwrite is given. Close the Unreal editor
before running this. Logs go to Intermediate\Generate\ next to this script.

.PARAMETER RebuildGen
Rebuild the editor plugin first. Needed after a change under Source\.

.PARAMETER Only
Run only these generators. Defaults to all of them.

.PARAMETER Overwrite
Create every asset of the selected generators again, even when its package exists.

.PARAMETER ModRoot
Content path that receives the mod's widgets. Defaults to /Game/Mods/UI/Options.

.PARAMETER Config
Path to the config file. Defaults to assetgen.config.json next to this script.

.EXAMPLE
.\GenerateAssets.ps1
.\GenerateAssets.ps1 -RebuildGen -Overwrite
.\GenerateAssets.ps1 -Only CyberHud -Overwrite
#>
[CmdletBinding()]
param(
    [switch]$RebuildGen,
    [ValidateSet("Menu", "HudIcon", "ButtonAtlas", "CyberHud")]
    [string[]]$Only,
    [switch]$Overwrite,
    [string]$ModRoot = "/Game/Mods/UI/Options",
    [string]$Config
)

$ErrorActionPreference = "Stop"
$scriptDir = Split-Path -Parent $MyInvocation.MyCommand.Path
if (-not $Config) { $Config = Join-Path $scriptDir "assetgen.config.json" }

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

$genLog = Join-Path $logDir "generate-assets.log"
$arguments = @($cfg.project, "-run=ModAssetGen", "-ModRoot=$ModRoot")
if ($Only) { $arguments += "-Only=$($Only -join ',')" }
if ($Overwrite) { $arguments += "-Overwrite" }
$arguments += @("-unattended", "-nopause", "-nosplash", "-stdout", "-FullStdOutLogOutput")

Write-Host "Generating the mod assets ..."
& $editorCmd @arguments *> $genLog
$exit = $LASTEXITCODE

# The commandlet's own lines are the useful part of the editor log.
Get-Content -LiteralPath $genLog | Select-String -Pattern "LogAssetGen: " | ForEach-Object {
    Write-Host ($_.Line -replace '^.*LogAssetGen: ', '')
}
if ($exit -ne 0) {
    Show-Errors $genLog
    throw "Generation failed (exit $exit). Full log: $genLog"
}
Write-Host "Done. Open the project in the editor to check the Blueprints, then cook."
