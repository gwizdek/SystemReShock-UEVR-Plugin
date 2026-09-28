using System;
using System.Threading;
using System.Threading.Tasks;
using SystemReShockInstaller.Models;

namespace SystemReShockInstaller.Services;

/// <summary>Start the game if needed, wait for its window, count down, inject. Reports each stage as text.</summary>
public sealed class GameLaunchService
{
    private readonly IGameStarter _starter;
    private readonly IGameProcessWatcher _watcher;
    private readonly IUevrInjector _injector;

    public GameLaunchService(IGameStarter starter, IGameProcessWatcher watcher, IUevrInjector injector)
    {
        _starter = starter;
        _watcher = watcher;
        _injector = injector;
    }

    public async Task RunAsync(LaunchRequest request, IProgress<string> status, CancellationToken cancellation)
    {
        using var game = await FindOrStartGameAsync(request, status, cancellation).ConfigureAwait(false);
        await CountdownAsync(request.DelaySeconds, status, cancellation).ConfigureAwait(false);
        status.Report("Injecting UEVR (" + VrRuntimes.DllName(request.Runtime) + ")...");
        _injector.Inject(game.Id, request.UevrPath, request.Runtime);
    }

    private async Task<System.Diagnostics.Process> FindOrStartGameAsync(LaunchRequest request, IProgress<string> status, CancellationToken cancellation)
    {
        var running = _watcher.FindReadyGameProcess();
        if (running != null)
        {
            status.Report("The game is already running.");
            return running;
        }
        status.Report("Starting System Shock Remake " + GameStores.LaunchVia(request.Store) + "...");
        _starter.Start(request.GamePath, request.Store);
        status.Report("Waiting for the game window...");
        return await _watcher.WaitForReadyGameAsync(ModPaths.GameWindowTimeout, cancellation).ConfigureAwait(false)
            ?? throw new TimeoutException("The game window did not appear within " + ModPaths.GameWindowTimeout.TotalMinutes + " minutes.");
    }

    private static async Task CountdownAsync(int seconds, IProgress<string> status, CancellationToken cancellation)
    {
        for (var remaining = seconds; remaining > 0; remaining--)
        {
            status.Report("Injecting UEVR in " + remaining + " s...");
            await Task.Delay(TimeSpan.FromSeconds(1), cancellation).ConfigureAwait(false);
        }
    }
}
