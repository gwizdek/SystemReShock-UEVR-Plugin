using System;
using System.ComponentModel;
using System.Diagnostics;
using System.IO;
using SystemReShockInstaller.Models;

namespace SystemReShockInstaller.Services;

public interface IGameStarter
{
    void Start(string gamePath);
}

/// <summary>Starts the game through Steam so DRM, overlay, and cloud saves work. Falls back to the exe.</summary>
public sealed class GameStarter : IGameStarter
{
    public void Start(string gamePath)
    {
        try
        {
            Launch(ModPaths.SteamLaunchUri);
        }
        catch (Exception ex) when (ex is Win32Exception || ex is InvalidOperationException)
        {
            Launch(Path.Combine(gamePath, ModPaths.GameExeRelative));
        }
    }

    private static void Launch(string target)
    {
        using var process = Process.Start(new ProcessStartInfo(target) { UseShellExecute = true });
    }
}
