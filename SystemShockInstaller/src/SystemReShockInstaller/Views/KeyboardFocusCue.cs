using System.Windows;
using System.Windows.Controls;
using System.Windows.Input;

namespace SystemReShockInstaller.Views;

/// <summary>
/// Marks a control that got keyboard focus from the keyboard: Tab, the arrow keys, or Esc and
/// Enter closing a dialog. Styles highlight focus with IsVisible, so a button does not stay yellow
/// after a mouse click, which also gives it focus, or after a dialog it opened is closed with the
/// mouse. Windows shows its own focus rectangles the same way.
/// </summary>
public static class KeyboardFocusCue
{
    private static readonly DependencyPropertyKey IsVisiblePropertyKey = DependencyProperty.RegisterAttachedReadOnly(
        "IsVisible", typeof(bool), typeof(KeyboardFocusCue), new PropertyMetadata(false));

    public static readonly DependencyProperty IsVisibleProperty = IsVisiblePropertyKey.DependencyProperty;

    public static bool GetIsVisible(DependencyObject element) => (bool)element.GetValue(IsVisibleProperty);

    /// <summary>Call once at startup, before any window opens.</summary>
    public static void Register()
    {
        EventManager.RegisterClassHandler(typeof(Control), Keyboard.GotKeyboardFocusEvent,
            new KeyboardFocusChangedEventHandler(OnGotKeyboardFocus));
        EventManager.RegisterClassHandler(typeof(Control), Keyboard.LostKeyboardFocusEvent,
            new KeyboardFocusChangedEventHandler(OnLostKeyboardFocus));
    }

    private static void OnGotKeyboardFocus(object sender, KeyboardFocusChangedEventArgs e)
    {
        if (sender is Control control && ReferenceEquals(e.NewFocus, control))
            control.SetValue(IsVisiblePropertyKey, InputManager.Current.MostRecentInputDevice is KeyboardDevice);
    }

    private static void OnLostKeyboardFocus(object sender, KeyboardFocusChangedEventArgs e)
    {
        if (sender is Control control && ReferenceEquals(e.OldFocus, control))
            control.SetValue(IsVisiblePropertyKey, false);
    }
}
