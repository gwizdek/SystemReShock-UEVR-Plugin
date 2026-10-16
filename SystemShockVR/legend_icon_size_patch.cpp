#include "legend_icon_size_patch.hpp"

#include <cstdint>
#include <cstdlib>
#include <cstring>
#include <string>

#include "uevr/API.hpp"
#include "mINI/ini.h"

using namespace uevr;

namespace {

constexpr const wchar_t* kIniFileName = L"tutorial_messages.ini";
constexpr const char* kPopupSection = "popup";
constexpr const char* kIconSizeKey = "icon_size";

constexpr const wchar_t* kUpdateLegend =
    L"Function /Game/Blueprints/UI/HUD/Widgets/ButtonLegend/WIDGET_ButtonLegend_Key.WIDGET_ButtonLegend_Key_C.UpdateLegend";
constexpr const wchar_t* kTryUpdateLegendSize =
    L"Function /Game/Blueprints/UI/HUD/Widgets/ButtonLegend/WIDGET_ButtonLegend_Key.WIDGET_ButtonLegend_Key_C.TryUpdateLegendSize";

// The literals of UpdateLegend: mouse button and gamepad key size.
constexpr float kGameMouseSize = 30.0f;
constexpr float kGameGamepadSize = 38.0f;

// The literals of TryUpdateLegendSize: size of the key picture without and with key text.
constexpr float kGameIconPictureSize = 64.0f;
constexpr float kGameTextPictureSize = 128.0f;

// Ticks between two checks of the functions.
constexpr int kCheckTicks = 600;

// UStruct::Script, the bytecode of a Blueprint function, in UE 4.27: a TArray<uint8> at 0x60.
constexpr size_t kScriptOffset = 0x60;

struct ScriptArray
{
    uint8_t* data;
    int32_t num;
    int32_t max;
};

// Blueprint VM opcodes (EExprToken).
constexpr uint8_t EX_LocalVariable = 0x00;
constexpr uint8_t EX_Let = 0x0F;
constexpr uint8_t EX_FloatConst = 0x1E;
constexpr uint8_t EX_StructConst = 0x2F;
constexpr uint8_t EX_EndStructConst = 0x30;

// "Let Local = FloatConst x": opcode, 8 byte property pointer, local variable opcode, 8 byte
// property pointer, float opcode, 4 byte float.
constexpr int32_t kLetFloatSize = 1 + 8 + 1 + 8 + 1 + 4;
constexpr int32_t kLetFloatValue = 19;

// "Let Local = StructConst Vector2D{x, y}": the same start, then the struct opcode, 8 byte
// struct pointer, 4 byte serialized size, two float constants and the end opcode.
constexpr int32_t kLetVectorSize = 1 + 8 + 1 + 8 + 1 + 8 + 4 + 5 + 5 + 1;
constexpr int32_t kLetVectorX = 32;
constexpr int32_t kLetVectorY = 37;

float float_at(const uint8_t* at) {
    float value;
    std::memcpy(&value, at, sizeof(value));
    return value;
}

void write_float(uint8_t* at, float value) {
    std::memcpy(at, &value, sizeof(value));
}

bool is_let_local(const uint8_t* p) {
    return p[0] == EX_Let && p[9] == EX_LocalVariable;
}

bool is_let_float(const uint8_t* p, float value) {
    return is_let_local(p) && p[18] == EX_FloatConst && float_at(p + kLetFloatValue) == value;
}

bool is_let_vector(const uint8_t* p, float value) {
    return is_let_local(p) && p[18] == EX_StructConst && p[31] == EX_FloatConst && p[36] == EX_FloatConst
        && p[41] == EX_EndStructConst && float_at(p + kLetVectorX) == value && float_at(p + kLetVectorY) == value;
}

bool is_valid(const ScriptArray& script) {
    return script.data != nullptr && script.num > 0 && script.num <= script.max;
}

// The start of "Temp_float_Variable_1 = <gamepad_size>", found after "Temp_float_Variable = 30.0", or -1.
int32_t find_gamepad_size(const ScriptArray& script, float gamepad_size) {
    if (!is_valid(script)) return -1;
    for (int32_t at = 0; at + 2 * kLetFloatSize <= script.num; ++at) {
        const uint8_t* p = script.data + at;
        if (is_let_float(p, kGameMouseSize) && is_let_float(p + kLetFloatSize, gamepad_size)) return at + kLetFloatSize;
    }
    return -1;
}

// The start of "Temp_struct_Variable = {<picture_size>, <picture_size>}", found before
// "Temp_struct_Variable_1 = {128, 128}", or -1.
int32_t find_picture_size(const ScriptArray& script, float picture_size) {
    if (!is_valid(script)) return -1;
    for (int32_t at = 0; at + 2 * kLetVectorSize <= script.num; ++at) {
        const uint8_t* p = script.data + at;
        if (is_let_vector(p, picture_size) && is_let_vector(p + kLetVectorSize, kGameTextPictureSize)) return at;
    }
    return -1;
}

ScriptArray* script_of(const wchar_t* function_name) {
    auto* function = API::get()->find_uobject<API::UFunction>(function_name);
    if (function == nullptr) return nullptr;   // class not loaded yet
    return reinterpret_cast<ScriptArray*>(reinterpret_cast<uint8_t*>(function) + kScriptOffset);
}

} // anonymous namespace

bool LegendIconSizePatch::s_ini_read{ false };
float LegendIconSizePatch::s_icon_size{ 0.0f };
int LegendIconSizePatch::s_ticks_until_check{ 1 };

void LegendIconSizePatch::handle() {
    if (--s_ticks_until_check > 0) return;
    s_ticks_until_check = kCheckTicks;
    try {
        if (!s_ini_read) read_ini();
        if (s_icon_size <= 0.0f) return;
        patch_panel_size();
        patch_picture_size();
    }
    catch (...) {
        API::get()->log_error("[legend_icon_size_patch][handle] Exception");
    }
}

// Reads [popup] icon_size once. A missing file, key, a value of 0 or the game's own size
// leaves the functions as they are.
void LegendIconSizePatch::read_ini() {
    s_ini_read = true;
    const std::string path = API::get()->get_persistent_dir(kIniFileName).string();
    mINI::INIFile file(path);
    mINI::INIStructure ini;
    if (file.read(ini) && ini.has(kPopupSection)) {
        s_icon_size = static_cast<float>(std::atof(ini.get(kPopupSection).get(kIconSizeKey).c_str()));
    }
    if (s_icon_size == kGameGamepadSize) s_icon_size = 0.0f;
    if (s_icon_size > 0.0f) {
        API::get()->log_warn("[legend_icon_size_patch][read_ini] Gamepad button icons are %g x %g", s_icon_size, s_icon_size);
    }
    else {
        API::get()->log_warn("[legend_icon_size_patch][read_ini] No icon_size in %s; gamepad button icons keep the game's %g x %g", path.c_str(), kGameGamepadSize, kGameGamepadSize);
    }
}

// UpdateLegend: the space a gamepad key takes in the text, 38 -> icon_size.
void LegendIconSizePatch::patch_panel_size() {
    ScriptArray* script = script_of(kUpdateLegend);
    if (script == nullptr || find_gamepad_size(*script, s_icon_size) >= 0) return;
    const int32_t at = find_gamepad_size(*script, kGameGamepadSize);
    if (at < 0) {
        API::get()->log_error("[legend_icon_size_patch][patch_panel_size] UpdateLegend has no gamepad size statement, not patched");
        s_icon_size = 0.0f;
        return;
    }
    write_float(script->data + at + kLetFloatValue, s_icon_size);
    API::get()->log_warn("[legend_icon_size_patch][patch_panel_size] UpdateLegend now sizes gamepad keys %g x %g (offset %d)", s_icon_size, s_icon_size, at);
}

// TryUpdateLegendSize: the size of the key picture, 64 -> 64 * icon_size / 38, so the picture
// grows with the space around it.
void LegendIconSizePatch::patch_picture_size() {
    ScriptArray* script = script_of(kTryUpdateLegendSize);
    const float picture_size = kGameIconPictureSize * s_icon_size / kGameGamepadSize;
    if (script == nullptr || find_picture_size(*script, picture_size) >= 0) return;
    const int32_t at = find_picture_size(*script, kGameIconPictureSize);
    if (at < 0) {
        API::get()->log_error("[legend_icon_size_patch][patch_picture_size] TryUpdateLegendSize has no picture size statement, not patched");
        return;
    }
    write_float(script->data + at + kLetVectorX, picture_size);
    write_float(script->data + at + kLetVectorY, picture_size);
    API::get()->log_warn("[legend_icon_size_patch][patch_picture_size] TryUpdateLegendSize now sizes key pictures %g x %g (offset %d)", picture_size, picture_size, at);
}
