namespace SystemReShockInstaller.Models;

/// <summary>Everything the launch flow needs, resolved from settings before Launch is pressed.</summary>
public sealed class LaunchRequest
{
    public LaunchRequest(string uevrPath, string gamePath, VrRuntime runtime, int delaySeconds)
    {
        UevrPath = uevrPath;
        GamePath = gamePath;
        Runtime = runtime;
        DelaySeconds = delaySeconds;
    }

    public string UevrPath { get; }
    public string GamePath { get; }
    public VrRuntime Runtime { get; }
    public int DelaySeconds { get; }
}
