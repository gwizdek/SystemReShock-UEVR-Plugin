<#
  launch-vr.ps1 - launch System Shock Remake + inject UEVR without the mod installer.

  Why this exists: the mod's installer re-verifies the deployed SystemReShockVR.dll
  against its bundled copy (InstallVerifier) and greys out Launch when they differ
  (i.e. after we build a modified plugin), and Launch is one-shot per app session.
  This script reproduces exactly what the launcher does - start the game through
  Steam, wait for the window + D3D, wait the delay, then inject the UEVR runtime
  loader followed by UEVRBackend.dll - so the deployed plugin is never overwritten.

  Usage:
    powershell -ExecutionPolicy Bypass -File .\launch-vr.ps1
    powershell -ExecutionPolicy Bypass -File .\launch-vr.ps1 -Runtime openvr -DelaySeconds 20
#>
param(
    [string]$UevrPath     = 'D:\UEVR',
    [string]$GamePath     = 'C:\Program Files (x86)\Steam\steamapps\common\System Shock Remake',
    [ValidateSet('openxr','openvr')]
    [string]$Runtime      = 'openxr',
    [int]$DelaySeconds    = 7,
    [int]$WindowTimeoutSeconds = 120
)

$ErrorActionPreference = 'Stop'
$GameExe   = 'SystemReShock-Win64-Shipping'
$SteamUri  = 'steam://rungameid/482400'
$GameExeRelative = 'SystemShock\Binaries\Win64\SystemReShock-Win64-Shipping.exe'
$RuntimeDll = if ($Runtime -eq 'openvr') { 'openvr_api.dll' } else { 'openxr_loader.dll' }
$BackendDll = 'UEVRBackend.dll'

Add-Type -Namespace Native -Name Injector -MemberDefinition @'
[DllImport("kernel32.dll", SetLastError=true)]
public static extern IntPtr OpenProcess(uint access, bool inherit, int pid);
[DllImport("kernel32.dll", SetLastError=true)]
public static extern IntPtr VirtualAllocEx(IntPtr h, IntPtr addr, UIntPtr size, uint allocType, uint protect);
[DllImport("kernel32.dll", SetLastError=true)]
public static extern bool WriteProcessMemory(IntPtr h, IntPtr addr, byte[] buf, UIntPtr size, out UIntPtr written);
[DllImport("kernel32.dll", SetLastError=true)]
public static extern IntPtr GetModuleHandle(string name);
[DllImport("kernel32.dll", SetLastError=true, CharSet=CharSet.Ansi)]
public static extern IntPtr GetProcAddress(IntPtr mod, string name);
[DllImport("kernel32.dll", SetLastError=true)]
public static extern IntPtr CreateRemoteThread(IntPtr h, IntPtr attr, UIntPtr stack, IntPtr start, IntPtr param, uint flags, out uint tid);
[DllImport("kernel32.dll", SetLastError=true)]
public static extern uint WaitForSingleObject(IntPtr handle, uint ms);
[DllImport("kernel32.dll", SetLastError=true)]
public static extern bool VirtualFreeEx(IntPtr h, IntPtr addr, UIntPtr size, uint freeType);
[DllImport("kernel32.dll", SetLastError=true)]
public static extern bool CloseHandle(IntPtr h);
'@

$PROCESS_ALL_ACCESS = 0x1F0FFF
$MEM_COMMIT = 0x1000; $MEM_RESERVE = 0x2000; $MEM_RELEASE = 0x8000
$PAGE_READWRITE = 0x04
$WAIT_OBJECT_0 = 0
$WAIT_TIMEOUT = 0x102

function Get-ReadyGameProcess {
    foreach ($p in Get-Process -Name $GameExe -ErrorAction SilentlyContinue) {
        try {
            if ($p.MainWindowHandle -ne [IntPtr]::Zero) {
                foreach ($m in $p.Modules) {
                    if ($m.ModuleName -ieq 'd3d11.dll' -or $m.ModuleName -ieq 'd3d12.dll') { return $p }
                }
            }
        } catch { }
    }
    return $null
}

function Inject-Dll([int]$procId, [string]$dllPath) {
    $full = (Resolve-Path -LiteralPath $dllPath).Path
    $h = [Native.Injector]::OpenProcess($PROCESS_ALL_ACCESS, $false, $procId)
    if ($h -eq [IntPtr]::Zero) { throw "OpenProcess failed for process $procId (run as admin?): $([Runtime.InteropServices.Marshal]::GetLastWin32Error())" }
    try {
        $bytes = [Text.Encoding]::Unicode.GetBytes($full + [char]0)
        $remote = [Native.Injector]::VirtualAllocEx($h, [IntPtr]::Zero, [UIntPtr][uint64]$bytes.Length, ($MEM_COMMIT -bor $MEM_RESERVE), $PAGE_READWRITE)
        if ($remote -eq [IntPtr]::Zero) { throw "VirtualAllocEx failed: $([Runtime.InteropServices.Marshal]::GetLastWin32Error())" }
        try {
            $written = [UIntPtr]::Zero
            if (-not [Native.Injector]::WriteProcessMemory($h, $remote, $bytes, [UIntPtr][uint64]$bytes.Length, [ref]$written)) { throw "WriteProcessMemory failed: $([Runtime.InteropServices.Marshal]::GetLastWin32Error())" }
            $loadLibrary = [Native.Injector]::GetProcAddress([Native.Injector]::GetModuleHandle('kernel32.dll'), 'LoadLibraryW')
            if ($loadLibrary -eq [IntPtr]::Zero) { throw 'LoadLibraryW not found' }
            $tid = 0
            $thread = [Native.Injector]::CreateRemoteThread($h, [IntPtr]::Zero, [UIntPtr]::Zero, $loadLibrary, $remote, 0, [ref]$tid)
            if ($thread -eq [IntPtr]::Zero) { throw "CreateRemoteThread failed: $([Runtime.InteropServices.Marshal]::GetLastWin32Error())" }
            try {
                $r = [Native.Injector]::WaitForSingleObject($thread, 10000)
                if ($r -eq $WAIT_TIMEOUT) { throw "Timed out loading $([IO.Path]::GetFileName($full))" }
            } finally { [void][Native.Injector]::CloseHandle($thread) }
        } finally { [void][Native.Injector]::VirtualFreeEx($h, $remote, [UIntPtr]::Zero, $MEM_RELEASE) }
    } finally { [void][Native.Injector]::CloseHandle($h) }
    Write-Host ("  injected " + [IO.Path]::GetFileName($full))
}

# sanity: UEVR files
foreach ($f in @($RuntimeDll, $BackendDll)) {
    $p = Join-Path $UevrPath $f
    if (-not (Test-Path -LiteralPath $p)) { throw "Missing $p" }
}

$game = Get-ReadyGameProcess
if ($game) {
    Write-Host "Game already running (pid $($game.Id))."
} else {
    Write-Host "Starting System Shock Remake via Steam..."
    Start-Process $SteamUri
    $deadline = (Get-Date).AddSeconds($WindowTimeoutSeconds)
    while ((Get-Date) -lt $deadline) {
        Start-Sleep -Milliseconds 500
        $game = Get-ReadyGameProcess
        if ($game) { break }
    }
    if (-not $game) {
        # fall back to launching the exe directly
        $exe = Join-Path $GamePath $GameExeRelative
        if (Test-Path -LiteralPath $exe) {
            Write-Host "Steam launch did not surface a window; starting the exe directly..."
            $proc = Start-Process -FilePath $exe -WorkingDirectory (Split-Path $exe) -PassThru
            $deadline = (Get-Date).AddSeconds($WindowTimeoutSeconds)
            while ((Get-Date) -lt $deadline) {
                Start-Sleep -Milliseconds 500
                $game = Get-ReadyGameProcess
                if ($game) { break }
            }
        }
    }
    if (-not $game) { throw "Game window did not appear in time." }
    Write-Host "Game window is up (pid $($game.Id))."
}

for ($r = $DelaySeconds; $r -gt 0; $r--) { Write-Host "Injecting UEVR ($Runtime) in $r s..."; Start-Sleep -Seconds 1 }

Write-Host "Injecting $RuntimeDll + $BackendDll..."
Inject-Dll $game.Id (Join-Path $UevrPath $RuntimeDll)
Inject-Dll $game.Id (Join-Path $UevrPath $BackendDll)

Write-Host ""
Write-Host "UEVR injected. Put on your headset and play. Leave this window open or close it - the game is already injected."
