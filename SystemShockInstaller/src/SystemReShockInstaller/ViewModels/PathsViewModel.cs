using System;
using System.IO;
using System.Windows.Input;
using SystemReShockInstaller.Models;
using SystemReShockInstaller.Services;

namespace SystemReShockInstaller.ViewModels;

public sealed class PathsViewModel : ViewModelBase
{
    private readonly WizardServices _services;
    private readonly Action<InstallPlan> _next;
    private readonly RelayCommand _nextCommand;
    private string _uevrPath = string.Empty;
    private string _gamePath = string.Empty;
    private string? _uevrError;
    private string? _gameError;

    public PathsViewModel(WizardServices services, Action<InstallPlan> next, Action cancel)
    {
        _services = services;
        _next = next;
        _nextCommand = new RelayCommand(GoNext, () => UevrError == null && GameError == null);
        BrowseUevrCommand = new RelayCommand(BrowseUevr);
        BrowseGameCommand = new RelayCommand(BrowseGame);
        CancelCommand = new RelayCommand(cancel);
        Prefill();
    }

    public string UevrNightlyUrl => ModPaths.UevrNightlyUrl;
    public ICommand BrowseUevrCommand { get; }
    public ICommand BrowseGameCommand { get; }
    public ICommand NextCommand => _nextCommand;
    public ICommand CancelCommand { get; }

    public string UevrPath
    {
        get => _uevrPath;
        set
        {
            if (Set(ref _uevrPath, value))
                Revalidate();
        }
    }

    public string GamePath
    {
        get => _gamePath;
        set
        {
            if (Set(ref _gamePath, value))
                Revalidate();
        }
    }

    public string? UevrError
    {
        get => _uevrError;
        private set => Set(ref _uevrError, value);
    }

    public string? GameError
    {
        get => _gameError;
        private set => Set(ref _gameError, value);
    }

    private void Prefill()
    {
        var settingsPath = Path.Combine(_services.AppDataRoot, ModPaths.SettingsDirName, ModPaths.SettingsFileName);
        var saved = _services.SettingsStore.Load(settingsPath);
        UevrPath = saved?.UevrPath ?? string.Empty;
        GamePath = saved?.GamePath ?? _services.LocateSteamGame() ?? string.Empty;
        Revalidate();
    }

    private void Revalidate()
    {
        UevrError = PathValidator.ValidateUevrFolder(UevrPath);
        GameError = PathValidator.ValidateGameFolder(GamePath);
        _nextCommand.RaiseCanExecuteChanged();
    }

    private void BrowseUevr()
    {
        var picked = _services.FolderPicker.Pick("Select the UEVR folder", UevrPath);
        if (picked != null)
            UevrPath = picked;
    }

    private void BrowseGame()
    {
        var picked = _services.FolderPicker.Pick("Select the System Shock Remake folder", GamePath);
        if (picked != null)
            GamePath = picked;
    }

    private void GoNext() =>
        _next(new InstallPlan(UevrPath.Trim(), GamePath.Trim(), _services.AppDataRoot));
}
