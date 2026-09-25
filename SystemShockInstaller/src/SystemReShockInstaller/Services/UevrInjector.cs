using System.IO;
using SystemReShockInstaller.Models;

namespace SystemReShockInstaller.Services;

public interface IUevrInjector
{
    void Inject(int processId, string uevrPath, VrRuntime runtime);
}

/// <summary>Injects UEVR the way its frontend does: the runtime loader first, then UEVRBackend.dll.</summary>
public sealed class UevrInjector : IUevrInjector
{
    private readonly IDllInjector _dll;

    public UevrInjector(IDllInjector dll) => _dll = dll;

    public void Inject(int processId, string uevrPath, VrRuntime runtime)
    {
        var runtimeDll = Require(uevrPath, VrRuntimes.DllName(runtime));
        var backendDll = Require(uevrPath, ModPaths.UevrBackendDll);
        _dll.Inject(processId, runtimeDll);
        _dll.Inject(processId, backendDll);
    }

    private static string Require(string uevrPath, string fileName)
    {
        var path = Path.Combine(uevrPath, fileName);
        if (!File.Exists(path))
            throw new FileNotFoundException(fileName + " was not found in the UEVR folder " + uevrPath + ".", path);
        return path;
    }
}
