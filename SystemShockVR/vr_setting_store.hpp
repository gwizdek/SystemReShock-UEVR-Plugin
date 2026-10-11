#pragma once

#include <optional>
#include <string>

// Where the value of one VR options row lives. The row's SettingName is the key. The options
// page reads every row from its store when it opens, and writes a row back after Apply.
class SettingStore
{
public:
    virtual ~SettingStore() = default;

    // Empty when the store has no value for the key; the row then keeps its own value.
    virtual std::optional<float> get_float(const std::string& key) const = 0;
    virtual std::optional<bool> get_bool(const std::string& key) const = 0;
    // Change the value in memory and mark the store for save_if_changed().
    virtual void set_float(const std::string& key, float value) = 0;
    virtual void set_bool(const std::string& key, bool value) = 0;
    // Writes the store's file when a set_* call changed something since the last save.
    virtual void save_if_changed() = 0;
};

// One section of system_reshock_vr_config.ini, through VRSettings.
class IniSectionStore final : public SettingStore
{
public:
    explicit IniSectionStore(const char* section) : m_section(section) {}

    std::optional<float> get_float(const std::string& key) const override;
    std::optional<bool> get_bool(const std::string& key) const override;
    void set_float(const std::string& key, float value) override;
    void set_bool(const std::string& key, bool value) override;
    void save_if_changed() override;

private:
    const char* m_section;
    bool m_changed{ false };
};

// UEVR's own settings, for example VR_SnapTurn. A set applies at once in the running UEVR;
// the save writes UEVR's config.txt in the profile folder.
class UevrSettingStore final : public SettingStore
{
public:
    std::optional<float> get_float(const std::string& key) const override;
    std::optional<bool> get_bool(const std::string& key) const override;
    void set_float(const std::string& key, float value) override;
    void set_bool(const std::string& key, bool value) override;
    void save_if_changed() override;

private:
    bool m_changed{ false };
};
