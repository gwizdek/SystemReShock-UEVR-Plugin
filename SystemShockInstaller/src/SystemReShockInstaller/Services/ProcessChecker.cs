using System.Diagnostics;
using System.Linq;
using SystemReShockInstaller.Models;

namespace SystemReShockInstaller.Services;

public interface IProcessChecker
{
    bool IsGameRunning();

    /// <summary>True when a running game process has UEVR's backend DLL loaded.</summary>
    bool IsUevrInjected();
}

public sealed class ProcessChecker : IProcessChecker
{
    public bool IsGameRunning()
    {
        var processes = Process.GetProcessesByName(ModPaths.GameExeName);
        foreach (var p in processes)
            p.Dispose();
        return processes.Length > 0;
    }

    public bool IsUevrInjected()
    {
        var processes = Process.GetProcessesByName(ModPaths.GameExeName);
        try
        {
            return processes.Any(p => ProcessModules.HasAny(p, ModPaths.UevrBackendDll));
        }
        finally
        {
            foreach (var p in processes)
                p.Dispose();
        }
    }
}
