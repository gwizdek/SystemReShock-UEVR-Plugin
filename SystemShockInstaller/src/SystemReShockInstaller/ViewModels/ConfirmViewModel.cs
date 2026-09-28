using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using System.Windows.Input;
using SystemReShockInstaller.Models;

namespace SystemReShockInstaller.ViewModels;

public sealed class ConfirmViewModel : ViewModelBase
{
    private readonly WizardServices _services;
    private readonly InstallPlan _plan;
    private readonly Action<IReadOnlyList<StepResult>> _done;
    private readonly RelayCommand _installCommand;
    private readonly RelayCommand _cancelCommand;
    private bool _isInstalling;
    private string? _blockMessage;

    public ConfirmViewModel(WizardServices services, InstallPlan plan, Action<IReadOnlyList<StepResult>> done, Action cancel)
    {
        _services = services;
        _plan = plan;
        _done = done;
        _installCommand = new RelayCommand(() => _ = InstallAsync(), () => !IsInstalling);
        _cancelCommand = new RelayCommand(cancel, () => !IsInstalling);
        Actions = services.Installer.Steps.Select(s => new PlannedAction(s.Title, s.Describe(plan))).ToList();
    }

    public IReadOnlyList<PlannedAction> Actions { get; }
    public ICommand InstallCommand => _installCommand;
    public ICommand CancelCommand => _cancelCommand;

    public bool IsInstalling
    {
        get => _isInstalling;
        private set
        {
            if (!Set(ref _isInstalling, value))
                return;
            _installCommand.RaiseCanExecuteChanged();
            _cancelCommand.RaiseCanExecuteChanged();
        }
    }

    public string? BlockMessage
    {
        get => _blockMessage;
        private set => Set(ref _blockMessage, value);
    }

    private async Task InstallAsync()
    {
        if (_services.ProcessChecker.IsGameRunning())
        {
            BlockMessage = "System Shock Remake is running. Close the game first, then press Install again.";
            return;
        }
        BlockMessage = null;
        IsInstalling = true;
        var results = await Task.Run(() => _services.Installer.Run(_plan));
        IsInstalling = false;
        _done(results);
    }
}

public sealed class PlannedAction
{
    public PlannedAction(string title, IEnumerable<string> details)
    {
        Title = title;
        Details = details.ToList();
    }

    public string Title { get; }
    public IReadOnlyList<string> Details { get; }
}
