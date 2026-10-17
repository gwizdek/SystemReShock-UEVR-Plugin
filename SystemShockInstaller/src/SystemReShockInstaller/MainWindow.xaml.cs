using System;
using System.Windows;
using SystemReShockInstaller.Views;

namespace SystemReShockInstaller;

public partial class MainWindow : Window
{
    public MainWindow() => InitializeComponent();

    protected override void OnSourceInitialized(EventArgs e)
    {
        base.OnSourceInitialized(e);
        DarkTitleBar.Apply(this);
    }
}
