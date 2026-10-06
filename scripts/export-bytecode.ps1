<#
.SYNOPSIS
    Runs BytecodeExporter on one asset, found by name or given as a path.

.DESCRIPTION
    Resolves the asset, builds tools\BytecodeExporter when its EXE is missing,
    and runs it. The exporter writes a folder named like the asset next to the
    asset with one .bytecode file per function plus variables.json,
    components.json and class.json.

.PARAMETER Asset
    An asset name such as PAWN_Hopper (with or without .uasset), or a full path
    to a .uasset file. A name is searched under -AssetsRoot.

.PARAMETER AssetsRoot
    Folder to search when -Asset is a name. Defaults to <repo>\dumps\assets.

.PARAMETER OutDir
    Output folder. Defaults to a folder named like the asset, next to the asset.

.PARAMETER Rebuild
    Build the exporter even when its EXE already exists.

.EXAMPLE
    powershell -ExecutionPolicy Bypass -File scripts\export-bytecode.ps1 PAWN_Hopper
#>
[CmdletBinding()]
param(
    [Parameter(Mandatory = $true, Position = 0)]
    [string]$Asset,
    [string]$AssetsRoot,
    [string]$OutDir,
    [switch]$Rebuild
)

$ErrorActionPreference = 'Stop'
$repoRoot = Split-Path -Parent $PSScriptRoot
if (-not $AssetsRoot) { $AssetsRoot = Join-Path $repoRoot 'dumps\assets' }

function Resolve-Asset([string]$asset, [string]$root) {
    if (Test-Path -LiteralPath $asset -PathType Leaf) { return (Resolve-Path -LiteralPath $asset).Path }
    if (-not (Test-Path -LiteralPath $root)) { throw "Assets folder not found: $root" }

    $name = [System.IO.Path]::GetFileNameWithoutExtension($asset)
    $matches = @(Get-ChildItem -LiteralPath $root -Recurse -File -Filter "$name.uasset")
    if ($matches.Count -eq 0) { throw "No asset named '$name.uasset' under $root" }
    if ($matches.Count -gt 1) {
        $list = ($matches | ForEach-Object { "  " + $_.FullName }) -join "`n"
        throw "Several assets are named '$name.uasset'. Pass the full path of one of them:`n$list"
    }
    return $matches[0].FullName
}

function Get-Exporter([string]$root, [bool]$rebuild) {
    $project = Join-Path $root 'tools\BytecodeExporter\BytecodeExporter.csproj'
    $exe = Join-Path $root 'tools\BytecodeExporter\bin\Release\net8.0\BytecodeExporter.exe'
    if ($rebuild -or -not (Test-Path -LiteralPath $exe)) {
        Write-Host "Building BytecodeExporter (Release)"
        & dotnet build $project -c Release --nologo -v quiet
        if ($LASTEXITCODE -ne 0) { throw "BytecodeExporter build failed with exit code $LASTEXITCODE" }
    }
    return $exe
}

$assetPath = Resolve-Asset $Asset $AssetsRoot
$exe = Get-Exporter $repoRoot $Rebuild.IsPresent

$arguments = @($assetPath)
if ($OutDir) { $arguments += @('--out', $OutDir) }

& $exe @arguments
if ($LASTEXITCODE -ne 0) { throw "BytecodeExporter failed with exit code $LASTEXITCODE" }
