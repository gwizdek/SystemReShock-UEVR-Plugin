using System.Collections.Generic;
using System.Threading.Tasks;
using SystemReShockInstaller.Models;

namespace SystemReShockInstaller.ViewModels;

/// <summary>
/// Removes the mod after one confirmation. Shared by the Welcome page and the launcher.
/// Refuses while the game runs, because the pak files are locked then.
/// </summary>
public sealed class UninstallFlow
{
    private const string Title = "Uninstall the mod";
    public const string Question = "Are you sure you want to uninstall the mod and all of its components?";
    private readonly WizardServices _services;

    public UninstallFlow(WizardServices services) => _services = services;

    /// <summary>Null when nothing was done: the game is running or the user said No.</summary>
    public async Task<IReadOnlyList<StepResult>?> RunAsync(InstallPlan plan)
    {
        if (_services.ProcessChecker.IsGameRunning())
        {
            _services.Dialogs.Warn(Title, "System Shock Remake is running. Close the game first, then try again.");
            return null;
        }
        if (!_services.Dialogs.Confirm(Title, Question))
            return null;
        return await Task.Run(() => _services.Uninstaller.Run(plan)).ConfigureAwait(true);
    }
}
