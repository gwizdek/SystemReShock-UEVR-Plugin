using System;
using System.ComponentModel;
using System.Diagnostics;
using System.Threading;
using System.Threading.Tasks;
using SystemReShockInstaller.Models;

namespace SystemReShockInstaller.Services;

public interface IGameProcessWatcher
{
    /// <summary>The game process once it has a window and a D3D device, or null if there is none yet.</summary>
    Process? FindReadyGameProcess();

    Task<Process?> WaitForReadyGameAsync(TimeSpan timeout, CancellationToken cancellation);
}

/// <summary>
/// A game process counts as ready when it owns a main window and has loaded d3d11 or d3d12.
/// Steam's bootstrap process shares the exe name for a moment, so the name alone is not enough.
/// </summary>
public sealed class GameProcessWatcher : IGameProcessWatcher
{
    private static readonly TimeSpan PollInterval = TimeSpan.FromMilliseconds(500);

    public Process? FindReadyGameProcess()
    {
        Process? ready = null;
        foreach (var process in Process.GetProcessesByName(ModPaths.GameExeName))
        {
            if (ready == null && IsReady(process))
                ready = process;
            else
                process.Dispose();
        }
        return ready;
    }

    public async Task<Process?> WaitForReadyGameAsync(TimeSpan timeout, CancellationToken cancellation)
    {
        var deadline = DateTime.UtcNow + timeout;
        while (DateTime.UtcNow < deadline)
        {
            var process = FindReadyGameProcess();
            if (process != null)
                return process;
            await Task.Delay(PollInterval, cancellation).ConfigureAwait(false);
        }
        return null;
    }

    private static bool IsReady(Process process)
    {
        try
        {
            return process.MainWindowHandle != IntPtr.Zero && HasDirect3D(process);
        }
        catch (Exception ex) when (ex is Win32Exception || ex is InvalidOperationException)
        {
            return false;
        }
    }

    private static bool HasDirect3D(Process process)
    {
        foreach (ProcessModule module in process.Modules)
        {
            var name = module.ModuleName;
            if (string.Equals(name, "d3d11.dll", StringComparison.OrdinalIgnoreCase)
                || string.Equals(name, "d3d12.dll", StringComparison.OrdinalIgnoreCase))
                return true;
        }
        return false;
    }
}
