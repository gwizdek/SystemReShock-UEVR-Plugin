<#
.SYNOPSIS
    Starts the game if it is not running and injects UEVR into it.

.DESCRIPTION
    Does the same as the installer's launcher (GameLaunchService in SystemShockInstaller):

    - Game not running: starts it, waits for its window, waits the inject delay, injects UEVR.
      A Steam install is started through Steam, any other install from its exe.
    - Game running without UEVR: waits for its window, injects UEVR.
    - Game running with UEVR: does nothing.

    UEVR counts as injected when the game has UEVRBackend.dll loaded. Injection loads the
    runtime loader DLL first, then UEVRBackend.dll, the same way the UEVR frontend does.

    The defaults point at the Steam install, which is the development install
    (see .claude\rules\game-installs.md).

.PARAMETER GamePath
    The game's install folder. Used to start the exe when Steam cannot start the game.

.PARAMETER UevrPath
    The folder with UEVRBackend.dll and the runtime loader DLLs.

.PARAMETER Runtime
    OpenXR (default) or OpenVR. Picks the loader DLL injected before the backend.

.PARAMETER DelaySeconds
    Seconds between the game window appearing and the injection, when this script started
    the game.
#>
[CmdletBinding()]
param(
    [string]$GamePath = 'D:\Steam\steamapps\common\System Shock Remake',
    [string]$UevrPath = 'D:\Modding\UEVR',
    [ValidateSet('OpenXR', 'OpenVR')]
    [string]$Runtime = 'OpenXR',
    [int]$DelaySeconds = 5
)

$ErrorActionPreference = 'Stop'

$gameExeName = 'SystemReShock-Win64-Shipping'
$gameExeRelative = "SystemShock\Binaries\Win64\$gameExeName.exe"
$steamLaunchUri = 'steam://rungameid/482400'
$backendDllName = 'UEVRBackend.dll'
$runtimeDllNames = @{ OpenXR = 'openxr_loader.dll'; OpenVR = 'openvr_api.dll' }
$windowTimeoutSeconds = 120

# Remote-thread LoadLibraryW injection, ported from DllInjector.cs in the installer.
# Windows PowerShell compiles only old C#, so the installer source cannot be used as it is.
Add-Type -TypeDefinition @'
using System;
using System.ComponentModel;
using System.Runtime.InteropServices;
using System.Text;

public static class UevrDllInjector
{
    const uint InjectAccess = 0x0002 | 0x0008 | 0x0010 | 0x0020 | 0x0400;
    const uint MemCommitReserve = 0x1000 | 0x2000;
    const uint MemRelease = 0x8000;
    const uint PageReadWrite = 0x04;
    const uint WaitTimeout = 0x102;
    const uint LoadTimeoutMs = 10000;

    [DllImport("kernel32.dll", SetLastError = true)]
    static extern IntPtr OpenProcess(uint access, bool inherit, int processId);
    [DllImport("kernel32.dll", SetLastError = true)]
    static extern bool CloseHandle(IntPtr handle);
    [DllImport("kernel32.dll", SetLastError = true)]
    static extern IntPtr VirtualAllocEx(IntPtr process, IntPtr address, UIntPtr size, uint type, uint protect);
    [DllImport("kernel32.dll", SetLastError = true)]
    static extern bool VirtualFreeEx(IntPtr process, IntPtr address, UIntPtr size, uint type);
    [DllImport("kernel32.dll", SetLastError = true)]
    static extern bool WriteProcessMemory(IntPtr process, IntPtr address, byte[] buffer, UIntPtr size, out UIntPtr written);
    [DllImport("kernel32.dll", SetLastError = true)]
    static extern IntPtr CreateRemoteThread(IntPtr process, IntPtr attributes, UIntPtr stackSize, IntPtr start, IntPtr parameter, uint flags, out uint threadId);
    [DllImport("kernel32.dll", SetLastError = true)]
    static extern uint WaitForSingleObject(IntPtr handle, uint milliseconds);
    [DllImport("kernel32.dll", CharSet = CharSet.Unicode, SetLastError = true)]
    static extern IntPtr GetModuleHandle(string name);
    [DllImport("kernel32.dll", CharSet = CharSet.Ansi, SetLastError = true)]
    static extern IntPtr GetProcAddress(IntPtr module, string name);

    public static void Inject(int processId, string fullPath)
    {
        IntPtr process = OpenProcess(InjectAccess, false, processId);
        if (process == IntPtr.Zero)
            throw Failure("Could not open the game process");
        try
        {
            RunRemoteLoadLibrary(process, fullPath);
        }
        finally
        {
            CloseHandle(process);
        }
    }

    static void RunRemoteLoadLibrary(IntPtr process, string fullPath)
    {
        byte[] bytes = Encoding.Unicode.GetBytes(fullPath + "\0");
        UIntPtr size = (UIntPtr)(uint)bytes.Length;
        IntPtr remote = VirtualAllocEx(process, IntPtr.Zero, size, MemCommitReserve, PageReadWrite);
        if (remote == IntPtr.Zero)
            throw Failure("Could not allocate memory in the game process");
        try
        {
            UIntPtr written;
            if (!WriteProcessMemory(process, remote, bytes, size, out written))
                throw Failure("Could not write to the game process");
            IntPtr loadLibrary = GetProcAddress(GetModuleHandle("kernel32.dll"), "LoadLibraryW");
            if (loadLibrary == IntPtr.Zero)
                throw Failure("LoadLibraryW was not found");
            WaitForRemoteThread(process, loadLibrary, remote);
        }
        finally
        {
            VirtualFreeEx(process, remote, UIntPtr.Zero, MemRelease);
        }
    }

    static void WaitForRemoteThread(IntPtr process, IntPtr start, IntPtr parameter)
    {
        uint threadId;
        IntPtr thread = CreateRemoteThread(process, IntPtr.Zero, UIntPtr.Zero, start, parameter, 0, out threadId);
        if (thread == IntPtr.Zero)
            throw Failure("Could not create a thread in the game process");
        try
        {
            if (WaitForSingleObject(thread, LoadTimeoutMs) == WaitTimeout)
                throw new Exception("The game did not finish loading the DLL within 10 seconds.");
        }
        finally
        {
            CloseHandle(thread);
        }
    }

    static Exception Failure(string what)
    {
        return new Exception(what + ": " + new Win32Exception(Marshal.GetLastWin32Error()).Message);
    }
}
'@

# False when the modules cannot be read, for example while the process starts or exits.
function Test-HasModule([System.Diagnostics.Process]$Process, [string[]]$Names) {
    try {
        foreach ($module in $Process.Modules) {
            if ($Names -contains $module.ModuleName) { return $true }
        }
    }
    catch { }
    return $false
}

function Get-GameProcess {
    Get-Process -Name $gameExeName -ErrorAction SilentlyContinue | Select-Object -First 1
}

# Ready means the window is up and the renderer DLL is loaded, as in GameProcessWatcher.cs.
function Test-GameReady([System.Diagnostics.Process]$Process) {
    $Process.Refresh()
    return $Process.MainWindowHandle -ne [IntPtr]::Zero -and (Test-HasModule $Process @('d3d11.dll', 'd3d12.dll'))
}

function Wait-GameReady {
    $deadline = (Get-Date).AddSeconds($windowTimeoutSeconds)
    while ((Get-Date) -lt $deadline) {
        $game = Get-GameProcess
        if ($game -and (Test-GameReady $game)) { return $game }
        Start-Sleep -Milliseconds 500
    }
    throw "The game window did not appear within $windowTimeoutSeconds seconds."
}

function Start-GameExe {
    $exe = Join-Path $GamePath $gameExeRelative
    if (-not (Test-Path $exe)) { throw "Game exe not found: $exe" }
    Write-Host "Starting $exe"
    Start-Process $exe -WorkingDirectory (Split-Path -Parent $exe)
}

# A Steam install is started through Steam, any other install from its exe, as in GameStarter.cs.
function Start-Game {
    if ($GamePath -notlike '*\steamapps\common\*') {
        Start-GameExe
        return
    }
    Write-Host 'Starting System Shock Remake through Steam...'
    try {
        Start-Process $steamLaunchUri
    }
    catch {
        Write-Host 'Steam did not start the game.'
        Start-GameExe
    }
}

function Get-RequiredDll([string]$Name) {
    $path = Join-Path $UevrPath $Name
    if (-not (Test-Path $path)) { throw "$Name was not found in the UEVR folder $UevrPath." }
    return (Resolve-Path $path).Path
}

function Invoke-UevrInjection([System.Diagnostics.Process]$Game) {
    $runtimeDll = Get-RequiredDll $runtimeDllNames[$Runtime]
    $backendDll = Get-RequiredDll $backendDllName
    Write-Host "Injecting UEVR ($Runtime) into process $($Game.Id)..."
    [UevrDllInjector]::Inject($Game.Id, $runtimeDll)
    [UevrDllInjector]::Inject($Game.Id, $backendDll)
    # Process.Modules is cached until Refresh, so the list read before the injection is stale.
    $Game.Refresh()
    if (-not (Test-HasModule $Game @($backendDllName))) { throw "The game did not load $backendDllName." }
    Write-Host "UEVR is injected."
}

$game = Get-GameProcess
if ($game -and (Test-HasModule $game @($backendDllName))) {
    Write-Host "The game is running and UEVR is already injected (process $($game.Id))."
    return
}

if ($game) {
    Write-Host "The game is running without UEVR. Waiting for its window..."
    $game = Wait-GameReady
}
else {
    Start-Game
    Write-Host 'Waiting for the game window...'
    $game = Wait-GameReady
    Write-Host "Waiting $DelaySeconds s before injecting..."
    Start-Sleep -Seconds $DelaySeconds
}

Invoke-UevrInjection $game
