#include "sdk_bootstrap.hpp"

#include <algorithm>
#include <cstdint>
#include <cstring>
#include <string>

#include "SDK/Basic.hpp"
#include "SDK/CoreUObject_classes.hpp"
#include "SDK/Engine_classes.hpp"
#include "uevr/API.hpp"

namespace
{
using API = uevr::API;

// Same memory layout as the TArray<wchar_t> behind SDK::FString. The fields there
// are protected, so the result of a name lookup is written through this view.
struct RawWideArray
{
    wchar_t* data;
    int32_t num;
    int32_t max;
};
static_assert(sizeof(SDK::FString) == sizeof(RawWideArray), "SDK::FString layout changed");

// Stands in for the game's FName::AppendString. Dumper-7 calls it as
// void(const FName*, FString&) with a preallocated buffer and reads it back as a
// null-terminated string.
void append_string_via_uevr(const SDK::FName* name, SDK::FString& out)
{
    auto& raw = reinterpret_cast<RawWideArray&>(out);
    if (raw.data == nullptr || raw.max <= 0) {
        return;
    }
    const std::wstring text = reinterpret_cast<const API::FName*>(name)->to_string();
    const int32_t count = static_cast<int32_t>(std::min<size_t>(text.size(), raw.max - 1));
    std::memcpy(raw.data, text.data(), count * sizeof(wchar_t));
    raw.data[count] = L'\0';
    raw.num = count + 1;
}

// Dumper-7 expects the TUObjectArray (the chunked array of FUObjectItem) that sits
// inside the engine's FUObjectArray. UEVR reports where it is.
SDK::TUObjectArray* find_object_array()
{
    API::FUObjectArray* uevr_array = API::FUObjectArray::get();
    if (uevr_array == nullptr) {
        API::get()->log_error("[sdk_bootstrap][find_object_array] UEVR has no object array");
        return nullptr;
    }
    if (!API::FUObjectArray::is_chunked()) {
        API::get()->log_error("[sdk_bootstrap][find_object_array] object array is not chunked; SDK layout does not match");
        return nullptr;
    }
    auto* base = reinterpret_cast<uint8_t*>(uevr_array);
    return reinterpret_cast<SDK::TUObjectArray*>(base + API::FUObjectArray::get_objects_offset());
}

bool counts_match(SDK::TUObjectArray* sdk_array)
{
    const int32_t sdk_count = sdk_array->Num();
    const int32_t uevr_count = API::FUObjectArray::get()->get_object_count();
    API::get()->log_warn("[sdk_bootstrap][counts_match] objects: SDK=%d UEVR=%d", sdk_count, uevr_count);
    return sdk_count == uevr_count;
}
}

namespace SdkBootstrap
{
bool initialize()
{
    SDK::FName::InitManually(reinterpret_cast<void*>(&append_string_via_uevr));

    SDK::TUObjectArray* sdk_array = find_object_array();
    if (sdk_array == nullptr || !counts_match(sdk_array)) {
        API::get()->log_error("[sdk_bootstrap][initialize] keeping the object array address from the dump");
        return false;
    }
    SDK::UObject::GObjects.InitManually(sdk_array);

    SDK::UClass* object_class = SDK::UObject::FindClassFast("Object");
    const std::string probe = object_class != nullptr ? object_class->GetName() : "<not found>";
    API::get()->log_warn("[sdk_bootstrap][initialize] SDK bound to UEVR; CoreUObject.Object resolves as '%s'", probe.c_str());
    return true;
}

SDK::UWorld* get_world()
{
    auto* engine = reinterpret_cast<SDK::UEngine*>(API::get()->get_engine());
    if (engine == nullptr || engine->GameViewport == nullptr) {
        return nullptr;
    }
    return engine->GameViewport->World;
}
}
