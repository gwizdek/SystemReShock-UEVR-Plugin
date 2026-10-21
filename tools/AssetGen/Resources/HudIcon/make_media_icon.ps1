<#
.SYNOPSIS
Writes T_MediaIcon_UnreadMessages_VR.png, the texture of the HUD email icon for VR.

.DESCRIPTION
Reads the game's cooked T_MediaIcon_UnreadMessages (104 x 86 BGRA8 pixels, starting at
byte 326 of its .uexp) from the repository's asset dump and writes it as a PNG next to
this script. The texture's R channel is the crisp outline of the envelope and G a soft
fill with a glow around it. The glow outside the envelope is reduced to a fraction of its
value (G and alpha), so the icon does not show as a box. Inside the envelope nothing changes.

.PARAMETER Uexp
The cooked texture. Defaults to the copy under dumps\ in the repository.

.PARAMETER OutsideFactor
What is left of the glow outside the envelope. 0 removes it, 1 keeps it. Default 0.1.
#>
[CmdletBinding()]
param(
    [string]$Uexp,
    [double]$OutsideFactor = 0.1
)

$ErrorActionPreference = "Stop"
Add-Type -AssemblyName System.Drawing

$scriptDir = Split-Path -Parent $MyInvocation.MyCommand.Path
if (-not $Uexp) {
    $repo = (Resolve-Path (Join-Path $scriptDir "..\..\..\..")).Path
    $Uexp = Join-Path $repo "dumps\assets\SystemShock\Content\Art\UI\HUD\Media\T_MediaIcon_UnreadMessages.uexp"
}
$outFile = Join-Path $scriptDir "T_MediaIcon_UnreadMessages_VR.png"

$width = 104; $height = 86; $offset = 326
$bytes = [IO.File]::ReadAllBytes($Uexp)
if ($bytes.Length -lt $offset + $width * $height * 4) { throw "$Uexp is smaller than expected" }

$bmp = New-Object System.Drawing.Bitmap $width, $height, ([System.Drawing.Imaging.PixelFormat]::Format32bppArgb)
$rect = New-Object System.Drawing.Rectangle 0, 0, $width, $height
$data = $bmp.LockBits($rect, [System.Drawing.Imaging.ImageLockMode]::WriteOnly, $bmp.PixelFormat)
[System.Runtime.InteropServices.Marshal]::Copy($bytes, $offset, $data.Scan0, $width * $height * 4)
$bmp.UnlockBits($data)

# The envelope is the box around every outline pixel (R channel).
$left = $width; $top = $height; $right = -1; $bottom = -1
for ($y = 0; $y -lt $height; $y++) {
    for ($x = 0; $x -lt $width; $x++) {
        if ($bmp.GetPixel($x, $y).R -gt 128) {
            if ($x -lt $left) { $left = $x }; if ($x -gt $right) { $right = $x }
            if ($y -lt $top) { $top = $y }; if ($y -gt $bottom) { $bottom = $y }
        }
    }
}
if ($right -lt 0) { throw "No outline pixels found" }

for ($y = 0; $y -lt $height; $y++) {
    for ($x = 0; $x -lt $width; $x++) {
        $outside = ($x -lt $left) -or ($x -gt $right) -or ($y -lt $top) -or ($y -gt $bottom)
        if (-not $outside) { continue }
        $p = $bmp.GetPixel($x, $y)
        $g = [int][Math]::Round($p.G * $OutsideFactor)
        $a = [int][Math]::Round($p.A * $OutsideFactor)
        $bmp.SetPixel($x, $y, [System.Drawing.Color]::FromArgb($a, $p.R, $g, $p.B))
    }
}

$bmp.Save($outFile, [System.Drawing.Imaging.ImageFormat]::Png)
Write-Host "Envelope box: x $left..$right, y $top..$bottom. Wrote $outFile"
