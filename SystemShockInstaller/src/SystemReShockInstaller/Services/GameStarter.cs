using System;
using System.ComponentModel;
using System.Diagnostics;
using System.IO;
using SystemReShockInstaller.Models;

namespace SystemReShockInstaller.Services;

public interface IGameStarter
{
    void Start(string gamePath, GameStore store);
}

/// <summary>
/// The Steam version starts through Steam so DRM, overlay and cloud saves work, with the exe as fallback.
/// Every other version starts the shipping exe directly; GOG games are DRM-free and need no client.
/// </summary>
public sealed class GameStarter : IGameStarter
{
    public void Start(string gamePath, GameStore store)
    {
        if (!GameStores.StartsThroughSteam(store))
        {
            StartExe(gamePath);
            return;
        }
        try
        {
            Launch(new ProcessStartInfo(ModPaths.SteamLaunchUri));
        }
        catch (Exception ex) when (ex is Win32Exception || ex is InvalidOperationException)
        {
            StartExe(gamePath);
        }
    }

    private static void StartExe(string gamePath)
    {
        var exe = Path.Combine(gamePath, ModPaths.GameExeRelative);
        Launch(new ProcessStartInfo(exe) { WorkingDirectory = Path.GetDirectoryName(exe) });
    }

    private static void Launch(ProcessStartInfo info)
    {
        info.UseShellExecute = true;
        using var process = Process.Start(info);
    }
}
