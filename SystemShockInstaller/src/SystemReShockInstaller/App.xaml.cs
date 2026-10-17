using System;
using System.Linq;
using System.Reflection;
using System.Windows;
using SystemReShockInstaller.Models;
using SystemReShockInstaller.Services;
using SystemReShockInstaller.ViewModels;

namespace SystemReShockInstaller;

public partial class App : Application
{
    private const string ForceInstallFlag = "--install";

    /// <summary>Testing aid: points the settings and profile folders somewhere other than %AppData%.</summary>
    private const string AppDataOverrideVariable = "SYSTEMRESHOCKVR_APPDATA";

    private const string AppTitle = "System Shock Remake VR Mod";
    private const string AlreadyRunningMessage =
        "System Shock Remake VR Mod is already running. Use the window that is already open.";

    private ModBundle? _bundle;
    private SingleInstanceGuard? _instance;

    protected override void OnStartup(StartupEventArgs e)
    {
        base.OnStartup(e);
        _instance = new SingleInstanceGuard(ModPaths.SingleInstanceMutexName);
        if (!_instance.IsFirstInstance)
        {
            new MessageBoxDialogs().Warn(AppTitle, AlreadyRunningMessage);
            Shutdown();
            return;
        }
        _bundle = ModBundle.FromEmbeddedResource();
        var forceInstall = e.Args.Any(a => a.Equals(ForceInstallFlag, StringComparison.OrdinalIgnoreCase));
        var shell = new ShellViewModel(ComposeServices(_bundle), Shutdown, forceInstall);
        MainWindow = new MainWindow { DataContext = shell };
        MainWindow.Show();
    }

    protected override void OnExit(ExitEventArgs e)
    {
        _bundle?.Dispose();
        _instance?.Dispose();
        base.OnExit(e);
    }

    private static WizardServices ComposeServices(IModBundle bundle)
    {
        var version = InformationalVersion();
        var appData = AppDataRoot();
        var settingsStore = new SettingsStore();
        return new WizardServices
        {
            Installer = ComposeInstaller(bundle, settingsStore, version),
            Uninstaller = ComposeUninstaller(bundle),
            Dialogs = new MessageBoxDialogs(),
            SettingsStore = settingsStore,
            FolderPicker = new FolderPicker(),
            ProcessChecker = new ProcessChecker(),
            LocateGame = GameLocators.Locate,
            StateResolver = new InstallStateResolver(settingsStore, new InstallVerifier(bundle), appData, version),
            Launcher = new GameLaunchService(new GameStarter(), new GameProcessWatcher(), new UevrInjector(new DllInjector())),
            AppDataRoot = appData,
            Version = version,
        };
    }

    private static InstallService ComposeInstaller(IModBundle bundle, ISettingsStore settingsStore, string version) =>
        new(new IInstallStep[]
        {
            new PakInstallStep(bundle),
            new ProfileInstallStep(bundle),
            new SettingsSaveStep(settingsStore, version),
        });

    private static InstallService ComposeUninstaller(IModBundle bundle) =>
        new(new IInstallStep[]
        {
            new PakRemoveStep(bundle),
            new ProfileRemoveStep(),
            new SettingsRemoveStep(),
        });

    private static string AppDataRoot()
    {
        var overridden = Environment.GetEnvironmentVariable(AppDataOverrideVariable);
        return string.IsNullOrWhiteSpace(overridden)
            ? Environment.GetFolderPath(Environment.SpecialFolder.ApplicationData)
            : overridden!;
    }

    private static string InformationalVersion() =>
        Assembly.GetExecutingAssembly()
            .GetCustomAttribute<AssemblyInformationalVersionAttribute>()?.InformationalVersion
        ?? Assembly.GetExecutingAssembly().GetName().Version.ToString();
}
