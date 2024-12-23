#pragma once

typedef enum ModEvent {
    MOD_EVENT_VR_HUD_HIDE_DASHBOARDS,
    MOD_EVENT_VR_HUD_INITIALIZE,
    MOD_EVENT_SHOW_MFD,
    MOD_EVENT_SHOW_IN_GAME_MENU,
    MOD_EVENT_MOUSE_ACTIVE,
} ModEvent;

// unused
typedef enum ModInputContext {
    MOD_INPUT_CONTEXT_MAIN,
    MOD_INPUT_CONTEXT_CYBERSPACE,
    MOD_INPUT_CONTEXT_MFD,
    MOD_INPUT_CONTEXT_MONTAGE,
    MOD_INPUT_CONTEXT_MENU,
} ModInputContext;

// unused
typedef enum ModInputSubContext {
    MOD_INPUT_SUBCONTEXT_MFD_INV,
    MOD_INPUT_SUBCONTEXT_MFD_INV_POPUP,
    MOD_INPUT_SUBCONTEXT_MFD_INV_ACTIVE_ITEM,
    MOD_INPUT_SUBCONTEXT_MFD_MAP,
    MOD_INPUT_SUBCONTEXT_MFD_STATUS,
    MOD_INPUT_SUBCONTEXT_MFD_MEDIA,
    MOD_INPUT_SUBCONTEXT_MFD_WARES
} ModInputSubContext;

using namespace uevr;

template<class T>
struct MemoProperty
{
    T value;
    T prev_value;

    MemoProperty(T _value, T _prev_value) {
        value = _value;
        prev_value = _prev_value;
    }

    bool has_changed() {
        return value != prev_value;
    }

    void set_value(T new_value) {
        prev_value = value;
        value = new_value;
    }

    // consumes the value change so has_changed() won't return true when called downstream
    void consume() {
        prev_value = value;
    }

    bool matches_any(std::vector<T> searched_values) {
        return std::find(searched_values.begin(), searched_values.end(), value) != std::end(searched_values);
    }

    bool matches_none(std::vector<T> searched_values) {
        return std::find(searched_values.begin(), searched_values.end(), value) == std::end(searched_values);
    }
};

struct MemoInput : public MemoProperty<bool>
{
    WORD wButton;
    bool m_logging{ false };
    // button name for loggin purpose
    std::string m_btn_name{ "UNDEFINED BTN" };

    MemoInput(WORD _wButton, std::string btn_name)
        : MemoProperty<bool>(false, false) {
        wButton = _wButton;
        m_btn_name = btn_name;
    }

    void set_logging(bool enabled) {
        m_logging = enabled;
    }

    void set(XINPUT_STATE* state) {
        MemoProperty::set_value(state->Gamepad.wButtons & wButton);
    }

    void set_and_mute_state(XINPUT_STATE* state) {
        MemoProperty::set_value(state->Gamepad.wButtons & wButton);
        mute_state(state);
    }

    bool is_held() {
        if (!MemoProperty::has_changed() && MemoProperty::value) {
            if (m_logging) {
                API::get()->log_info("### Button [%s] is held", m_btn_name);
            }
            return true;
        }
        else {
            return false;
        }
    }

    bool is_pressed() {
        if (MemoProperty::has_changed() && MemoProperty::value) {
            if (m_logging) {
                API::get()->log_info("### Button [%s] pressed", m_btn_name);
            }
            return true;
        }
        else {
            return false;
        }
    }

    bool is_released() {
        if (MemoProperty::has_changed() && !MemoProperty::value) {
            if (m_logging) {
                API::get()->log_info("### Button [%s] released", m_btn_name);
            }
            return true;
        }
        else {
            return false;
        }
    }

    void mute_state(XINPUT_STATE* state) {
        if (m_logging) {
            API::get()->log_info("### Button [%s] state muted", m_btn_name);
        }
        state->Gamepad.wButtons &= ~wButton;
    }

    void force_state(XINPUT_STATE* state) {
        if (m_logging) {
            API::get()->log_info("### Button [%s] state forced", m_btn_name);
        }
        state->Gamepad.wButtons |= wButton;
    }

    void when_pressed_send(XINPUT_STATE* state, WORD _wButton) {
        if (is_pressed()) {
            if (m_logging) {
                API::get()->log_info("### Button [%s] sending different state", m_btn_name);
            }
            state->Gamepad.wButtons |= _wButton;
        }
    }

    void when_held_send(XINPUT_STATE* state, WORD _wButton) {
        if (is_held()) {
            if (m_logging) {
                API::get()->log_info("### Button [%s] sending different state", m_btn_name);
            }
            state->Gamepad.wButtons |= _wButton;
        }
    }
};


struct MemoDualInput : public MemoInput
{
    // is used as a timer to check long vs short presses
    std::chrono::steady_clock::time_point press_time;

    const float m_min_long_press_duration{ 0.5f };

    bool is_counting{ false };
    float press_duration{ 0.f };

    bool short_pressed{ false }, long_pressed{ false };

    MemoDualInput(WORD _wButton, std::string btn_name)
        : MemoInput(_wButton, btn_name) {
    }

    void set_and_mute_state(XINPUT_STATE* state) {
        MemoDualInput::set(state);
        MemoInput::mute_state(state);
    }

    void add_delta(float delta) {
        if (MemoInput::is_held() && is_counting) {
            //API::get()->log_info("Adding delta | %f | %f", delta, press_duration);
            press_duration += delta;
        }
    }

    void set(XINPUT_STATE* state) {
        MemoInput::set(state);

        // button pressed down so check if it's a long press
        if (MemoInput::is_held() && is_counting) {
            if (press_duration >= m_min_long_press_duration) {
                short_pressed = false;
                long_pressed = true;
                return;
            }
            else {
                long_pressed = false;
            }
        }

        if (MemoProperty::has_changed()) {
            // pressed
            if (MemoProperty::value) {
                if (m_logging) {
                    API::get()->log_info("### Dual Button [%s] pressed", m_btn_name);
                }
                // store press time
                press_duration = 0.f;
                short_pressed = false;
                long_pressed = false;
                is_counting = true;
            }
            // released
            else {
                // button up, so check if it's a short press
                if (press_duration < m_min_long_press_duration && is_counting) {
                    if (m_logging) {
                        API::get()->log_info("### Dual Button [%s] released", m_btn_name);
                    }
                    // reset timer
                    press_duration = 0.f;
                    is_counting = false;
                    long_pressed = false;
                    short_pressed = true;
                }
            }
        }
    }

    void reset() {
        press_duration = 0.f;
        is_counting = false;
        short_pressed = false;
        long_pressed = false;
    }

    bool is_short_pressed() {
        if (short_pressed) {
            if (m_logging) {
                API::get()->log_info("### Dual Button [%s] short pressed", m_btn_name);
            }
            reset();
            return true;
        }
        return false;
    }

    bool is_long_pressed(float duration) {
        if (long_pressed && press_duration >= duration) {
            if (m_logging) {
                API::get()->log_info("### Dual Button [%s] long pressed", m_btn_name);
            }
            reset();
            return true;
        }
        return false;
    }
};