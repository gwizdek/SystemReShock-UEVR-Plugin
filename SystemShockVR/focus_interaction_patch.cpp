#include "focus_interaction_patch.hpp"
#include "object_lookup.hpp"

#include "uevr/API.hpp"

using namespace uevr;

namespace {

constexpr const wchar_t* kFunctions[] = {
    L"Function /Game/Blueprints/Interactables/INTERACT_Focusable_Base.INTERACT_Focusable_Base_C.ShouldFocusOnInteract",
    L"Function /Game/Blueprints/Interactables/Keypads/INTERACT_Keypad.INTERACT_Keypad_C.ShouldFocusOnInteract",
    L"Function /Game/Blueprints/Interactables/Puzzles/PUZZLE_Base.PUZZLE_Base_C.ShouldFocusOnInteract",
};

// Ticks between two checks of the three functions.
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
constexpr uint8_t EX_Return = 0x04;
constexpr uint8_t EX_Jump = 0x06;
constexpr uint8_t EX_LetBool = 0x14;
constexpr uint8_t EX_False = 0x28;
constexpr uint8_t EX_LocalOutVariable = 0x48;

// "LetBool Result(out) = False": opcode, out-variable opcode, 8 byte property pointer, False.
constexpr int32_t kLetFalseSize = 1 + 1 + 8 + 1;

// Jump with a 32 bit target; the 5 bytes the patch writes at the start of the script.
constexpr int32_t kJumpSize = 1 + 4;

int32_t jump_target(const uint8_t* at) {
    return *reinterpret_cast<const int32_t*>(at + 1);
}

// True when the instruction at 'at' ends the function: a return, or a jump to a return.
bool returns_after(const ScriptArray& script, int32_t at) {
    if (script.data[at] == EX_Return) return true;
    if (script.data[at] != EX_Jump || at + kJumpSize > script.num) return false;
    const int32_t target = jump_target(script.data + at);
    return target >= 0 && target < script.num && script.data[target] == EX_Return;
}

// The offset of a "Result = false" followed by a return, or -1. The scripts set Result either
// in an epilogue at the end or in a branch that jumps to the shared return.
int32_t find_return_false(const ScriptArray& script) {
    if (script.data == nullptr || script.num <= kJumpSize || script.num > script.max) return -1;
    for (int32_t at = 0; at + kLetFalseSize < script.num; ++at) {
        const uint8_t* p = script.data + at;
        if (p[0] != EX_LetBool || p[1] != EX_LocalOutVariable || p[kLetFalseSize - 1] != EX_False) continue;
        if (returns_after(script, at + kLetFalseSize)) return at;
    }
    return -1;
}

bool is_patched(const ScriptArray& script, int32_t target) {
    return script.data[0] == EX_Jump && jump_target(script.data) == target;
}

} // anonymous namespace

int FocusInteractionPatch::s_ticks_until_check{ 0 };

void FocusInteractionPatch::handle() {
    if (--s_ticks_until_check > 0) return;
    s_ticks_until_check = kCheckTicks;
    try {
        patch_all();
    }
    catch (...) {
        API::get()->log_error("[focus_interaction_patch][handle] Exception");
    }
}

void FocusInteractionPatch::patch_all() {
    for (const wchar_t* name : kFunctions) {
        patch(name);
    }
}

bool FocusInteractionPatch::patch(const wchar_t* function_name) {
    auto* function = ObjectLookup::find<API::UFunction>(function_name);
    if (function == nullptr) return false;   // class not loaded yet
    auto& script = *reinterpret_cast<ScriptArray*>(reinterpret_cast<uint8_t*>(function) + kScriptOffset);
    const int32_t target = find_return_false(script);
    if (target < 0) {
        API::get()->log_error("[focus_interaction_patch][patch] %ls has no 'Result = false; return', not patched", function_name);
        return false;
    }
    if (is_patched(script, target)) return true;
    script.data[0] = EX_Jump;
    *reinterpret_cast<int32_t*>(script.data + 1) = target;
    API::get()->log_warn("[focus_interaction_patch][patch] %ls now always returns false (jump to offset %d)", function_name, target);
    return true;
}
