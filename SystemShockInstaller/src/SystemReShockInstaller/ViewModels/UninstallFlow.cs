using System.Collections.Generic;
using System.Text;
using System.Threading.Tasks;
using SystemReShockInstaller.Models;
using SystemReShockInstaller.Services;

namespace SystemReShockInstaller.ViewModels;

/// <summary>
/// Removes the mod after one confirmation. Shared by the Welcome page and the launcher.
/// Refuses while the game runs, because the pak files are locked then.
/// </summary>
public sealed class UninstallFlow
{
    private const string Title = "Remove the mod?";
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
        if (!_services.Dialogs.Confirm(Title, Message(plan)))
            return null;
        return await Task.Run(() => _services.Uninstaller.Run(plan)).ConfigureAwait(true);
    }

    /// <summary>The same step descriptions the Confirm page shows for an install, as one message.</summary>
    public string Message(InstallPlan plan)
    {
        var text = new StringBuilder("This removes the System Shock Remake VR mod:\n");
        foreach (var step in _services.Uninstaller.Steps)
        {
            text.Append('\n').Append(step.Title).Append('\n');
            foreach (var line in step.Describe(plan))
                text.Append("    ").Append(line).Append('\n');
        }
        return text.Append("\nYour game files and save games are not touched. Continue?").ToString();
    }
}
