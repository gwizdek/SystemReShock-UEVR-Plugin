namespace SystemReShockInstaller.Services;

public interface IFolderPicker
{
    /// <summary>Shows the system folder dialog. Returns null when the user cancels.</summary>
    string? Pick(string title, string? initialFolder);
}
