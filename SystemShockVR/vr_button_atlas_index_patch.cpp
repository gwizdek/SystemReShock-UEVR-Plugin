#include "vr_button_atlas_index_patch.hpp"

#include <cstring>

#include "uevr/API.hpp"

using namespace uevr;

namespace {

constexpr const wchar_t* kFunction =
    L"Function /Game/Blueprints/Utility/FUNCLIB_UserInterface.FUNCLIB_UserInterface_C.GetGamepadButtonAtlasIndex";

// The key that gets the new branch, and its cell in T_VRButtonLayout.
constexpr const wchar_t* kKeyName = L"Gamepad_RightStick_Up";
constexpr int32_t kCell = 24;

// Ticks between two checks of the function.
constexpr int kCheckTicks = 600;

// UStruct::Script, the bytecode of a Blueprint function, in UE 4.27: a TArray<uint8> at 0x60.
constexpr size_t kScriptOffset = 0x60;

struct ScriptArray
{
    uint8_t* data;
    int32_t num;
    int32_t max;
};

// The 12 byte FScriptName in the bytecode: comparison index, display index, number.
struct ScriptName
{
    int32_t comparison;
    int32_t display;
    int32_t number;
};

// Blueprint VM opcodes (EExprToken).
constexpr uint8_t EX_LocalVariable = 0x00;
constexpr uint8_t EX_Return = 0x04;
constexpr uint8_t EX_Jump = 0x06;
constexpr uint8_t EX_JumpIfNot = 0x07;
constexpr uint8_t EX_Nothing = 0x0B;
constexpr uint8_t EX_Let = 0x0F;
constexpr uint8_t EX_LetBool = 0x14;
constexpr uint8_t EX_EndFunctionParms = 0x16;
constexpr uint8_t EX_IntConst = 0x1D;
constexpr uint8_t EX_FloatConst = 0x1E;
constexpr uint8_t EX_NameConst = 0x21;
constexpr uint8_t EX_StructConst = 0x2F;
constexpr uint8_t EX_EndStructConst = 0x30;
constexpr uint8_t EX_LocalOutVariable = 0x48;
constexpr uint8_t EX_CallMath = 0x68;

// Layout of the default: Let Index = -1 (23 bytes), Let Rotation = 0.0 (23), Jump (5).
constexpr int32_t kDefaultSize = 51;
constexpr int32_t kDefaultIndex = 19;
constexpr int32_t kDefaultJump = 46;

// Layout of a key branch: LetBool compare (56 bytes), JumpIfNot (14), Let Index (23),
// Let Rotation (23), Jump (5).
constexpr int32_t kBranchSize = 121;
constexpr int32_t kBranchName = 42;
constexpr int32_t kBranchJumpIfNot = 56;
constexpr int32_t kBranchIndex = 89;
constexpr int32_t kBranchJump = 116;

template<typename T>
T read_at(const uint8_t* at) {
    T value;
    std::memcpy(&value, at, sizeof(value));
    return value;
}

template<typename T>
void write_at(uint8_t* at, const T& value) {
    std::memcpy(at, &value, sizeof(value));
}

bool is_let_out(const uint8_t* p, uint8_t constant) {
    return p[0] == EX_Let && p[9] == EX_LocalOutVariable && p[18] == constant;
}

// True for "Let Index = -1; Let Rotation = 0.0; Jump -> Return" at 'at'.
bool is_default(const ScriptArray& script, int32_t at) {
    if (at + kDefaultSize > script.num) return false;
    const uint8_t* p = script.data + at;
    if (!is_let_out(p, EX_IntConst) || read_at<int32_t>(p + kDefaultIndex) != -1) return false;
    if (!is_let_out(p + 23, EX_FloatConst) || p[kDefaultJump] != EX_Jump) return false;
    const int32_t target = read_at<int32_t>(p + kDefaultJump + 1);
    return target > at && target < script.num && script.data[target] == EX_Return;
}

// True when the kBranchSize bytes before the default form a key branch that jumps to it.
bool is_branch_before(const ScriptArray& script, int32_t default_at) {
    if (default_at < kBranchSize) return false;
    const uint8_t* p = script.data + default_at - kBranchSize;
    const bool compare = p[0] == EX_LetBool && p[1] == EX_LocalVariable && p[10] == EX_CallMath && p[19] == EX_LocalVariable
        && p[28] == EX_StructConst && p[41] == EX_NameConst && p[54] == EX_EndStructConst && p[55] == EX_EndFunctionParms;
    const bool jumps = p[kBranchJumpIfNot] == EX_JumpIfNot && read_at<int32_t>(p + kBranchJumpIfNot + 1) == default_at;
    return compare && jumps && is_let_out(p + 70, EX_IntConst) && is_let_out(p + 93, EX_FloatConst) && p[kBranchJump] == EX_Jump;
}

// The offset of the default that follows a key branch, or -1.
int32_t find_default(const ScriptArray& script) {
    if (script.data == nullptr || script.num <= 0 || script.num > script.max) return -1;
    for (int32_t at = kBranchSize; at + kDefaultSize <= script.num; ++at) {
        if (is_default(script, at) && is_branch_before(script, at)) return at;
    }
    return -1;
}

ScriptName script_name_of(const wchar_t* text) {
    const API::FName name{ text };
    return ScriptName{ name.comparison_index, name.comparison_index, name.number };
}

bool is_patched(const uint8_t* branch, const ScriptName& name) {
    return read_at<int32_t>(branch + kBranchIndex) == kCell && read_at<ScriptName>(branch + kBranchName).comparison == name.comparison;
}

// Writes the new branch at default_at and the default behind it; fills the rest of the dead
// code up to the return with EX_Nothing.
void insert_branch(ScriptArray& script, int32_t default_at, const ScriptName& name) {
    uint8_t branch[kBranchSize];
    uint8_t fallback[kDefaultSize];
    std::memcpy(branch, script.data + default_at - kBranchSize, kBranchSize);
    std::memcpy(fallback, script.data + default_at, kDefaultSize);
    const int32_t return_at = read_at<int32_t>(fallback + kDefaultJump + 1);
    write_at(branch + kBranchName, name);
    write_at(branch + kBranchJumpIfNot + 1, default_at + kBranchSize);
    write_at(branch + kBranchIndex, kCell);
    std::memcpy(script.data + default_at, branch, kBranchSize);
    std::memcpy(script.data + default_at + kBranchSize, fallback, kDefaultSize);
    const int32_t rest = default_at + kBranchSize + kDefaultSize;
    std::memset(script.data + rest, EX_Nothing, static_cast<size_t>(return_at - rest));
}

} // anonymous namespace

int VRButtonAtlasIndexPatch::s_ticks_until_check{ 1 };

void VRButtonAtlasIndexPatch::handle() {
    if (--s_ticks_until_check > 0) return;
    s_ticks_until_check = kCheckTicks;
    try {
        patch();
    }
    catch (...) {
        API::get()->log_error("[vr_button_atlas_index_patch][handle] Exception");
    }
}

void VRButtonAtlasIndexPatch::patch() {
    auto* function = API::get()->find_uobject<API::UFunction>(kFunction);
    if (function == nullptr) return;   // class not loaded yet
    auto& script = *reinterpret_cast<ScriptArray*>(reinterpret_cast<uint8_t*>(function) + kScriptOffset);
    const int32_t default_at = find_default(script);
    if (default_at < 0) {
        API::get()->log_error("[vr_button_atlas_index_patch][patch] GetGamepadButtonAtlasIndex has no key branch before the default, not patched");
        s_ticks_until_check = INT32_MAX;
        return;
    }
    const ScriptName name = script_name_of(kKeyName);
    if (is_patched(script.data + default_at - kBranchSize, name)) return;
    const int32_t return_at = read_at<int32_t>(script.data + default_at + kDefaultJump + 1);
    if (return_at - default_at < kBranchSize + kDefaultSize) {
        API::get()->log_error("[vr_button_atlas_index_patch][patch] No room behind the default (%d bytes), not patched", return_at - default_at);
        s_ticks_until_check = INT32_MAX;
        return;
    }
    insert_branch(script, default_at, name);
    API::get()->log_warn("[vr_button_atlas_index_patch][patch] GetGamepadButtonAtlasIndex now maps %ls to cell %d (offset %d)", kKeyName, kCell, default_at);
}
