using System;
using System.Diagnostics;
using System.IO;
using System.Linq;
using SystemReShockInstaller.Services;
using Xunit;

namespace SystemReShockInstaller.Tests;

public class DllInjectorTests
{
    [Fact]
    public void Loads_a_system_dll_into_a_child_process()
    {
        var dll = Path.Combine(Environment.SystemDirectory, "winmm.dll");
        using var child = StartSleepingChild();
        try
        {
            var baseAddress = new DllInjector().Inject(child.Id, dll);

            Assert.NotEqual(IntPtr.Zero, baseAddress);
            child.Refresh();
            Assert.Contains(child.Modules.Cast<ProcessModule>(), m => string.Equals(m.FileName, dll, StringComparison.OrdinalIgnoreCase));
        }
        finally
        {
            child.Kill();
        }
    }

    [Fact]
    public void Missing_dll_fails_before_touching_the_process()
    {
        Assert.Throws<FileNotFoundException>(() => new DllInjector().Inject(Process.GetCurrentProcess().Id, @"C:\does\not\exist.dll"));
    }

    [Fact]
    public void Dead_process_fails_with_injection_exception()
    {
        var dll = Path.Combine(Environment.SystemDirectory, "winmm.dll");
        using var child = StartSleepingChild();
        child.Kill();
        child.WaitForExit();

        Assert.Throws<InjectionException>(() => new DllInjector().Inject(child.Id, dll));
    }

    private static Process StartSleepingChild()
    {
        var info = new ProcessStartInfo("powershell.exe", "-NoProfile -NonInteractive -Command Start-Sleep -Seconds 60")
        {
            UseShellExecute = false,
            CreateNoWindow = true,
        };
        var process = Process.Start(info)!;
        WaitUntilInitialized(process);
        return process;
    }

    /// <summary>A console child has no message loop, so poll until its loader has mapped kernel32.</summary>
    private static void WaitUntilInitialized(Process process)
    {
        for (var attempt = 0; attempt < 50; attempt++)
        {
            try
            {
                process.Refresh();
                if (process.Modules.Cast<ProcessModule>().Any(m => m.ModuleName.Equals("kernel32.dll", StringComparison.OrdinalIgnoreCase)))
                    return;
            }
            catch (System.ComponentModel.Win32Exception)
            {
                // Still starting up.
            }
            System.Threading.Thread.Sleep(100);
        }
    }
}
