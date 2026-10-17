using System;
using System.Runtime.InteropServices;
using System.Windows;
using System.Windows.Interop;

namespace SystemReShockInstaller.Views;

/// <summary>
/// Gives the window a dark title bar, so it matches the black pages. Windows 10 2004 and newer
/// support the dark mode attribute. The caption and text colours work on Windows 11 only. On older
/// systems the calls fail and the title bar keeps its normal look.
/// </summary>
public static class DarkTitleBar
{
    private const int DwmwaUseImmersiveDarkMode = 20;
    private const int DwmwaCaptionColor = 35;
    private const int DwmwaTextColor = 36;

    // COLORREF values are 0x00BBGGRR.
    private const int CaptionBlack = 0x00000000;
    private const int TextGreen = 0x0084FF00;

    public static void Apply(Window window)
    {
        var handle = new WindowInteropHelper(window).Handle;
        if (handle == IntPtr.Zero) return;
        SetAttribute(handle, DwmwaUseImmersiveDarkMode, 1);
        SetAttribute(handle, DwmwaCaptionColor, CaptionBlack);
        SetAttribute(handle, DwmwaTextColor, TextGreen);
    }

    private static void SetAttribute(IntPtr handle, int attribute, int value) =>
        DwmSetWindowAttribute(handle, attribute, ref value, sizeof(int));

    [DllImport("dwmapi.dll")]
    private static extern int DwmSetWindowAttribute(IntPtr hwnd, int attribute, ref int value, int size);
}
