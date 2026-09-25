using SystemReShockInstaller.Models;

namespace SystemReShockInstaller.Services;

public interface ISettingsStore
{
    InstallerSettings? Load(string path);
    void Save(string path, InstallerSettings settings);
}
