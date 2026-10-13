<#
.SYNOPSIS
Writes a cooked BGRA8 texture of the game as a PNG.

.DESCRIPTION
Reads the .uexp of a cooked Texture2D from the repository's asset dump and writes its
pixels as a PNG. Only textures with one mip in PF_B8G8R8A8 are supported; that is what the
game's HUD textures use. The pixel data starts 44 bytes after the "PF_B8G8R8A8" format
string, and the width and height are the two ints 16 and 12 bytes before it.

.PARAMETER Uexp
The cooked texture's .uexp file.

.PARAMETER Png
The PNG to write. Defaults to the same name next to this script, under CyberHud\.

.EXAMPLE
.\export-cooked-texture.ps1 ..\..\..\..\dumps\assets\SystemShock\Content\Art\Cyberspace\GUI\T_ConnectionIntegrityWindow.uexp
#>
[CmdletBinding()]
param(
    [Parameter(Mandatory = $true)][string]$Uexp,
    [string]$Png
)

$ErrorActionPreference = "Stop"
Add-Type -AssemblyName System.Drawing

$scriptDir = Split-Path -Parent $MyInvocation.MyCommand.Path
if (-not $Png) {
    $Png = Join-Path (Join-Path $scriptDir "CyberHud") ([IO.Path]::GetFileNameWithoutExtension($Uexp) + ".png")
}
New-Item -ItemType Directory -Force (Split-Path -Parent $Png) | Out-Null

$bytes = [IO.File]::ReadAllBytes($Uexp)
$pattern = [Text.Encoding]::ASCII.GetBytes("PF_B8G8R8A8")
$at = -1
for ($k = 0; $k -lt $bytes.Length - $pattern.Length; $k++) {
    $match = $true
    for ($j = 0; $j -lt $pattern.Length; $j++) { if ($bytes[$k + $j] -ne $pattern[$j]) { $match = $false; break } }
    if ($match) { $at = $k; break }
}
if ($at -lt 0) { throw "$Uexp is not a PF_B8G8R8A8 texture" }

$width = [BitConverter]::ToInt32($bytes, $at - 16)
$height = [BitConverter]::ToInt32($bytes, $at - 12)
$offset = $at + 44
if ($bytes.Length -lt $offset + $width * $height * 4) { throw "$Uexp is smaller than ${width}x${height} BGRA8 needs" }

$bmp = New-Object System.Drawing.Bitmap $width, $height, ([System.Drawing.Imaging.PixelFormat]::Format32bppArgb)
$rect = New-Object System.Drawing.Rectangle 0, 0, $width, $height
$data = $bmp.LockBits($rect, [System.Drawing.Imaging.ImageLockMode]::WriteOnly, $bmp.PixelFormat)
[System.Runtime.InteropServices.Marshal]::Copy($bytes, $offset, $data.Scan0, $width * $height * 4)
$bmp.UnlockBits($data)
$bmp.Save($Png, [System.Drawing.Imaging.ImageFormat]::Png)
Write-Host "Wrote $Png (${width}x${height})"
