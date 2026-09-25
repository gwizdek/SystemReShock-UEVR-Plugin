using System.Diagnostics;
using SystemReShockInstaller.Models;

namespace SystemReShockInstaller.Services;

public interface IProcessChecker
{
    bool IsGameRunning();
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
}
