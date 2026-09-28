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
    private string? _detectedStoreText;

    public PathsViewModel(WizardServices services, Action<InstallPlan> next, Action cancel)
    {
        _services = services;
        _next = next;
        _nextCommand = new RelayCommand(GoNext, () => UevrError == null && GameError == null);
        BrowseUevrCommand = new RelayCommand(BrowseUevr);
        BrowseGameCommand = new RelayCommand(BrowseGame);
        CancelCommand = new RelayCommand(cancel);
        SteamFolder = services.LocateGame(GameStore.Steam);
        GogFolder = services.LocateGame(GameStore.GOG);
        UseSteamCommand = new RelayCommand(() => GamePath = SteamFolder ?? string.Empty);
        UseGogCommand = new RelayCommand(() => GamePath = GogFolder ?? string.Empty);
        Prefill();
    }

    public string UevrNightlyUrl => ModPaths.UevrNightlyUrl;
    public ICommand BrowseUevrCommand { get; }
    public ICommand BrowseGameCommand { get; }
    public ICommand NextCommand => _nextCommand;
    public ICommand CancelCommand { get; }
    public ICommand UseSteamCommand { get; }
    public ICommand UseGogCommand { get; }

    public string? SteamFolder { get; }
    public string? GogFolder { get; }

    /// <summary>Both stores have the game, so the player picks one with a click.</summary>
    public bool ShowsStoreButtons => SteamFolder != null && GogFolder != null;

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

    /// <summary>Which version the chosen folder holds. Null while the folder is not valid.</summary>
    public string? DetectedStoreText
    {
        get => _detectedStoreText;
        private set => Set(ref _detectedStoreText, value);
    }

    private void Prefill()
    {
        var settingsPath = Path.Combine(_services.AppDataRoot, ModPaths.SettingsDirName, ModPaths.SettingsFileName);
        var saved = _services.SettingsStore.Load(settingsPath);
        UevrPath = saved?.UevrPath ?? string.Empty;
        GamePath = saved?.GamePath ?? DetectedGameFolder();
        Revalidate();
    }

    /// <summary>One store found: use it. Both found: leave the field empty and let the buttons decide.</summary>
    private string DetectedGameFolder() =>
        ShowsStoreButtons ? string.Empty : SteamFolder ?? GogFolder ?? string.Empty;

    private void Revalidate()
    {
        UevrError = PathValidator.ValidateUevrFolder(UevrPath);
        GameError = PathValidator.ValidateGameFolder(GamePath);
        DetectedStoreText = GameError == null ? StoreText(GameStoreDetector.Detect(GamePath)) : null;
        _nextCommand.RaiseCanExecuteChanged();
    }

    private static string StoreText(GameStore store) => store == GameStore.Other
        ? GameStores.Label(store) + ". The launcher will start the game from its exe."
        : GameStores.Label(store) + " found.";

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

    private void GoNext()
    {
        var gamePath = GamePath.Trim();
        _next(new InstallPlan(UevrPath.Trim(), gamePath, _services.AppDataRoot, GameStoreDetector.Detect(gamePath)));
    }
}
