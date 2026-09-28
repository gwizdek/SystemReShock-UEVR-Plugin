using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Threading;
using System.Threading.Tasks;
using SystemReShockInstaller.Models;
using SystemReShockInstaller.Services;
using Xunit;

namespace SystemReShockInstaller.Tests;

public class GameLaunchServiceTests
{
    private static readonly LaunchRequest Request = new(@"C:\uevr", @"C:\game", GameStore.Steam, VrRuntime.OpenVR, delaySeconds: 1);
    private static readonly LaunchRequest GogRequest = new(@"C:\gog", @"D:\GOG\System Shock Remake", GameStore.GOG, VrRuntime.OpenXR, delaySeconds: 1);

    [Fact]
    public async Task Injects_into_already_running_game_without_starting_it()
    {
        var starter = new FakeStarter();
        var injector = new FakeInjector();
        var watcher = new FakeWatcher { Running = Process.GetCurrentProcess() };
        var log = new List<string>();

        await new GameLaunchService(starter, watcher, injector).RunAsync(Request, new Recorder(log), CancellationToken.None);

        Assert.False(starter.Started);
        Assert.Equal(Process.GetCurrentProcess().Id, injector.ProcessId);
        Assert.Equal(VrRuntime.OpenVR, injector.Runtime);
        Assert.Contains("Injecting UEVR in 1 s...", log);
        Assert.Contains(log, line => line.StartsWith("Injecting UEVR (openvr_api.dll)"));
    }

    [Fact]
    public async Task Starts_game_then_waits_then_injects()
    {
        var starter = new FakeStarter();
        var injector = new FakeInjector();
        var watcher = new FakeWatcher { AppearsLater = Process.GetCurrentProcess() };
        var log = new List<string>();

        await new GameLaunchService(starter, watcher, injector).RunAsync(Request, new Recorder(log), CancellationToken.None);

        Assert.True(starter.Started);
        Assert.Equal(@"C:\game", starter.GamePath);
        Assert.Equal(GameStore.Steam, starter.Store);
        Assert.Contains("Starting System Shock Remake through Steam...", log);
        Assert.Contains("Waiting for the game window...", log);
        Assert.NotNull(injector.ProcessId);
    }

    [Fact]
    public async Task Gog_version_is_started_from_the_game_folder()
    {
        var starter = new FakeStarter();
        var watcher = new FakeWatcher { AppearsLater = Process.GetCurrentProcess() };
        var log = new List<string>();

        await new GameLaunchService(starter, watcher, new FakeInjector()).RunAsync(GogRequest, new Recorder(log), CancellationToken.None);

        Assert.Equal(GameStore.GOG, starter.Store);
        Assert.Equal(@"D:\GOG\System Shock Remake", starter.GamePath);
        Assert.Contains("Starting System Shock Remake from the game folder...", log);
    }

    [Fact]
    public async Task Times_out_when_no_window_appears_and_does_not_inject()
    {
        var injector = new FakeInjector();
        var service = new GameLaunchService(new FakeStarter(), new FakeWatcher(), injector);

        await Assert.ThrowsAsync<TimeoutException>(() => service.RunAsync(Request, new Recorder(new List<string>()), CancellationToken.None));

        Assert.Null(injector.ProcessId);
    }

    private sealed class Recorder : IProgress<string>
    {
        private readonly List<string> _log;
        public Recorder(List<string> log) => _log = log;
        public void Report(string value) => _log.Add(value);
    }

    private sealed class FakeStarter : IGameStarter
    {
        public bool Started { get; private set; }
        public string? GamePath { get; private set; }
        public GameStore? Store { get; private set; }

        public void Start(string gamePath, GameStore store)
        {
            Started = true;
            GamePath = gamePath;
            Store = store;
        }
    }

    private sealed class FakeWatcher : IGameProcessWatcher
    {
        public Process? Running { get; set; }
        public Process? AppearsLater { get; set; }

        public Process? FindReadyGameProcess() => Running;

        public Task<Process?> WaitForReadyGameAsync(TimeSpan timeout, CancellationToken cancellation) =>
            Task.FromResult(AppearsLater);
    }

    private sealed class FakeInjector : IUevrInjector
    {
        public int? ProcessId { get; private set; }
        public VrRuntime? Runtime { get; private set; }

        public void Inject(int processId, string uevrPath, VrRuntime runtime)
        {
            ProcessId = processId;
            Runtime = runtime;
        }
    }
}
