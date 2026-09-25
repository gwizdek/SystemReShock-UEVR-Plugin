using System;
using System.ComponentModel;
using System.Diagnostics;
using System.IO;
using System.Runtime.InteropServices;
using System.Text;
using SystemReShockInstaller.Interop;

namespace SystemReShockInstaller.Services;

public sealed class InjectionException : Exception
{
    public InjectionException(string message) : base(message) { }
    public InjectionException(string message, Exception inner) : base(message, inner) { }
}

public interface IDllInjector
{
    /// <summary>Loads the DLL into the process and returns its base address there.</summary>
    IntPtr Inject(int processId, string dllPath);
}

/// <summary>
/// Classic remote-thread injection, the same technique the UEVR frontend uses: write the DLL path
/// into the target, then start a thread there at LoadLibraryW. Both processes must be 64-bit.
/// </summary>
public sealed class DllInjector : IDllInjector
{
    private const uint LoadTimeoutMs = 10_000;

    public IntPtr Inject(int processId, string dllPath)
    {
        var fullPath = Path.GetFullPath(dllPath);
        if (!File.Exists(fullPath))
            throw new FileNotFoundException("DLL not found: " + fullPath, fullPath);

        var process = NativeMethods.OpenProcess(NativeMethods.InjectAccess, false, processId);
        if (process == IntPtr.Zero)
            throw Failure("Could not open the game process");
        try
        {
            RunRemoteLoadLibrary(process, fullPath);
        }
        finally
        {
            NativeMethods.CloseHandle(process);
        }
        return FindModuleBase(processId, fullPath)
            ?? throw new InjectionException("The game did not load " + Path.GetFileName(fullPath) + ".");
    }

    private static void RunRemoteLoadLibrary(IntPtr process, string fullPath)
    {
        var pathBytes = Encoding.Unicode.GetBytes(fullPath + "\0");
        var remotePath = WriteRemoteBytes(process, pathBytes);
        try
        {
            var loadLibrary = NativeMethods.GetProcAddress(NativeMethods.GetModuleHandle("kernel32.dll"), "LoadLibraryW");
            if (loadLibrary == IntPtr.Zero)
                throw Failure("LoadLibraryW was not found");
            WaitForRemoteThread(process, loadLibrary, remotePath);
        }
        finally
        {
            NativeMethods.VirtualFreeEx(process, remotePath, UIntPtr.Zero, NativeMethods.MemRelease);
        }
    }

    private static IntPtr WriteRemoteBytes(IntPtr process, byte[] bytes)
    {
        var size = (UIntPtr)(uint)bytes.Length;
        var remote = NativeMethods.VirtualAllocEx(process, IntPtr.Zero, size, NativeMethods.MemCommit | NativeMethods.MemReserve, NativeMethods.PageReadWrite);
        if (remote == IntPtr.Zero)
            throw Failure("Could not allocate memory in the game process");
        if (!NativeMethods.WriteProcessMemory(process, remote, bytes, size, out _))
        {
            NativeMethods.VirtualFreeEx(process, remote, UIntPtr.Zero, NativeMethods.MemRelease);
            throw Failure("Could not write to the game process");
        }
        return remote;
    }

    private static void WaitForRemoteThread(IntPtr process, IntPtr start, IntPtr parameter)
    {
        var thread = NativeMethods.CreateRemoteThread(process, IntPtr.Zero, UIntPtr.Zero, start, parameter, 0, out _);
        if (thread == IntPtr.Zero)
            throw Failure("Could not create a thread in the game process");
        try
        {
            if (NativeMethods.WaitForSingleObject(thread, LoadTimeoutMs) == NativeMethods.WaitTimeout)
                throw new InjectionException("The game did not finish loading the DLL within 10 seconds.");
        }
        finally
        {
            NativeMethods.CloseHandle(thread);
        }
    }

    private static IntPtr? FindModuleBase(int processId, string fullPath)
    {
        using var process = Process.GetProcessById(processId);
        foreach (ProcessModule module in process.Modules)
        {
            if (string.Equals(module.FileName, fullPath, StringComparison.OrdinalIgnoreCase))
                return module.BaseAddress;
        }
        return null;
    }

    private static InjectionException Failure(string what)
    {
        var inner = new Win32Exception(Marshal.GetLastWin32Error());
        return new InjectionException(what + ": " + inner.Message, inner);
    }
}
