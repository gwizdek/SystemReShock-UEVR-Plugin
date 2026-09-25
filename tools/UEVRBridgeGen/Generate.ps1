<#
.SYNOPSIS
Regenerates the BridgeSDK headers from the Unreal project.

.DESCRIPTION
Reads bridgegen.config.json next to this script for the engine folder, the Unreal
project and the generator options, then runs the UEVRBridgeGen commandlet. The
normal case is that only Blueprints changed, so the editor plugin is not rebuilt
unless -RebuildGen is given. Logs go to Intermediate\Generate\ next to this script.

See documentation\bridge-sdk-generator.md for what the generator does.

.PARAMETER RebuildGen
Rebuild the editor plugin first. Needed after a change under Source\ or Resources\.

.PARAMETER Config
Path to the config file. Defaults to bridgegen.config.json next to this script.

.EXAMPLE
.\Generate.ps1
.\Generate.ps1 -RebuildGen
#>
[CmdletBinding()]
param(
    [switch]$RebuildGen,
    [string]$Config = (Join-Path $PSScriptRoot "bridgegen.config.json")
)

$ErrorActionPreference = "Stop"

function Resolve-OutDir([string]$RepoRoot, [string]$OutDir) {
    if ([System.IO.Path]::IsPathRooted($OutDir)) { return $OutDir }
    return [System.IO.Path]::GetFullPath((Join-Path $RepoRoot $OutDir))
}

function Assert-Exists([string]$Path, [string]$What) {
    if (-not (Test-Path -LiteralPath $Path)) {
        throw "$What not found: $Path (check $Config)"
    }
}

function Show-Errors([string]$LogPath) {
    Get-Content -LiteralPath $LogPath | Select-String -Pattern "error" -CaseSensitive:$false | Select-Object -First 15 | ForEach-Object { Write-Host $_.Line }
}

$cfg = Get-Content -LiteralPath $Config -Raw | ConvertFrom-Json
$repoRoot = [System.IO.Path]::GetFullPath((Join-Path $PSScriptRoot "..\.."))
$buildBat = Join-Path $cfg.engineDir "Engine\Build\BatchFiles\Build.bat"
$editorCmd = Join-Path $cfg.engineDir "Engine\Binaries\Win64\UE4Editor-Cmd.exe"
$outDir = Resolve-OutDir $repoRoot $cfg.outDir
$logDir = Join-Path $PSScriptRoot "Intermediate\Generate"

Assert-Exists $cfg.project "Unreal project"
Assert-Exists $buildBat "Build.bat"
Assert-Exists $editorCmd "UE4Editor-Cmd.exe"
New-Item -ItemType Directory -Force -Path $logDir | Out-Null

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

$genLog = Join-Path $logDir "generate.log"
Write-Host "Generating into $outDir ..."
& $editorCmd $cfg.project -run=UEVRBridgeGen "-OutDir=$outDir" "-Paths=$($cfg.paths)" "-Prefix=$($cfg.prefix)" `
    "-SdkInclude=$($cfg.sdkInclude)" "-UevrInclude=$($cfg.uevrInclude)" "-Aggregate=$($cfg.aggregate)" `
    -unattended -nopause -nosplash -stdout -FullStdOutLogOutput *> $genLog
if ($LASTEXITCODE -ne 0) {
    Show-Errors $genLog
    throw "Generation failed (exit $LASTEXITCODE). Full log: $genLog"
}

# The commandlet's own lines are the useful part of the editor log.
Get-Content -LiteralPath $genLog | Select-String -Pattern "LogUEVRBridgeGen: " | ForEach-Object {
    Write-Host ($_.Line -replace '^.*LogUEVRBridgeGen: ', '')
}
Write-Host "Done. Rebuild SystemShockVR to compile the new headers."
