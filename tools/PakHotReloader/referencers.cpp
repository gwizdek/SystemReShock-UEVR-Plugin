#include <cstdint>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include "uevr/API.hpp"
#include "referencers.hpp"

using namespace uevr;

namespace pak_hot_reload {
namespace {

constexpr int kMaxStructDepth = 4;
constexpr int32_t kMaxArrayElements = 100000;

// How a property can hold an object reference.
enum class Kind { Skip, Object, Interface, Array, Struct };

struct Slot {
    Kind kind;
    int32_t offset;
    API::FProperty* prop;
};

using Layout = std::vector<Slot>;

// The UEVR log takes char. Object names are ASCII in practice.
std::string narrow(const std::wstring& wide) {
    std::string out;
    out.reserve(wide.size());
    for (const wchar_t c : wide) out.push_back(c < 128 ? static_cast<char>(c) : '?');
    return out;
}

Kind kind_of(API::FProperty* prop) {
    const auto name = prop->get_class()->get_name();
    if (name == L"ObjectProperty" || name == L"ClassProperty") return Kind::Object;
    if (name == L"InterfaceProperty") return Kind::Interface;   // FScriptInterface: the object pointer comes first
    if (name == L"ArrayProperty") return Kind::Array;
    if (name == L"StructProperty") return Kind::Struct;
    return Kind::Skip;   // weak, soft and lazy references do not keep an object alive; maps and sets are not walked
}

int32_t align_up(int32_t value, int32_t alignment) {
    alignment = alignment > 0 ? alignment : 1;
    return (value + alignment - 1) / alignment * alignment;
}

API::UObject* outermost(API::UObject* object) {
    while (object->get_outer() != nullptr) object = object->get_outer();
    return object;
}

class ReferenceScanner {
public:
    ReferenceScanner(const std::wstring& prefix, int limit) : m_prefix(prefix), m_limit(limit) {}

    void run() {
        auto* objects = API::FUObjectArray::get();
        const int32_t count = objects->get_object_count();
        collect_targets(objects, count);
        for (int32_t i = 0; i < count; ++i) {
            auto* object = objects->get_object(i);
            if (object == nullptr || m_targets.count(object) != 0) continue;
            scan_struct(object->get_class(), reinterpret_cast<uint8_t*>(object), object, L"", 0);
        }
        API::get()->log_warn("[referencers][log_referencers] %zu object(s) under %s, %d reference(s) to them from outside (%d listed)",
            m_targets.size(), narrow(m_prefix).c_str(), m_found, m_found < m_limit ? m_found : m_limit);
    }

private:
    // Every live object that lives in a package under the prefix: packages, classes,
    // default objects, templates and assets.
    void collect_targets(API::FUObjectArray* objects, int32_t count) {
        for (int32_t i = 0; i < count; ++i) {
            auto* object = objects->get_object(i);
            if (object == nullptr) continue;
            const auto package = outermost(object)->get_fname()->to_string();
            if (package.compare(0, m_prefix.size(), m_prefix) == 0) m_targets.insert(object);
        }
    }

    // Reference-holding properties of a struct and its parents, computed once per struct.
    const Layout& layout_of(API::UStruct* type) {
        auto it = m_layouts.find(type);
        if (it != m_layouts.end()) return it->second;
        Layout layout;
        for (API::UStruct* s = type; s != nullptr; s = s->get_super_struct()) {
            for (API::FField* field = s->get_child_properties(); field != nullptr; field = field->get_next()) {
                auto* prop = reinterpret_cast<API::FProperty*>(field);
                const Kind kind = kind_of(prop);
                if (kind != Kind::Skip) layout.push_back({kind, prop->get_offset(), prop});
            }
        }
        return m_layouts.emplace(type, std::move(layout)).first->second;
    }

    void scan_struct(API::UStruct* type, uint8_t* base, API::UObject* owner, const std::wstring& path, int depth) {
        if (type == nullptr || depth > kMaxStructDepth) return;
        for (const Slot& slot : layout_of(type)) {
            const auto name = path + slot.prop->get_fname()->to_string();
            scan_slot(slot, base + slot.offset, owner, name, depth);
        }
    }

    void scan_slot(const Slot& slot, uint8_t* address, API::UObject* owner, const std::wstring& path, int depth) {
        switch (slot.kind) {
        case Kind::Object:
        case Kind::Interface:
            check_pointer(*reinterpret_cast<API::UObject**>(address), owner, path);
            break;
        case Kind::Struct:
            scan_struct(static_cast<API::FStructProperty*>(slot.prop)->get_struct(), address, owner, path + L".", depth + 1);
            break;
        case Kind::Array:
            scan_array(static_cast<API::FArrayProperty*>(slot.prop), address, owner, path, depth);
            break;
        default:
            break;
        }
    }

    void scan_array(API::FArrayProperty* prop, uint8_t* address, API::UObject* owner, const std::wstring& path, int depth) {
        struct RawArray { uint8_t* data; int32_t num; int32_t max; };
        const auto* array = reinterpret_cast<const RawArray*>(address);
        if (array->data == nullptr || array->num <= 0 || array->num > kMaxArrayElements) return;
        API::FProperty* inner = prop->get_inner();
        const Kind kind = kind_of(inner);
        if (kind == Kind::Object || kind == Kind::Interface) {
            const int32_t stride = kind == Kind::Interface ? 16 : 8;
            for (int32_t i = 0; i < array->num; ++i) {
                check_pointer(*reinterpret_cast<API::UObject**>(array->data + i * stride), owner, path + L"[" + std::to_wstring(i) + L"]");
            }
        } else if (kind == Kind::Struct) {
            auto* type = static_cast<API::FStructProperty*>(inner)->get_struct();
            const int32_t stride = align_up(type->get_properties_size(), type->get_min_alignment());
            for (int32_t i = 0; i < array->num; ++i) {
                scan_struct(type, array->data + i * stride, owner, path + L"[" + std::to_wstring(i) + L"].", depth + 1);
            }
        }
    }

    void check_pointer(API::UObject* value, API::UObject* owner, const std::wstring& path) {
        if (value == nullptr || m_targets.count(value) == 0) return;
        ++m_found;
        if (m_found > m_limit) return;
        API::get()->log_warn("[referencers][log_referencers] %s .%s -> %s",
            narrow(owner->get_full_name()).c_str(), narrow(path).c_str(), narrow(value->get_full_name()).c_str());
    }

    std::wstring m_prefix;
    int m_limit;
    int m_found{0};
    std::unordered_set<API::UObject*> m_targets;
    std::unordered_map<API::UStruct*, Layout> m_layouts;
};

} // namespace

void log_referencers(const std::wstring& prefix, int limit) {
    if (prefix.empty()) return;
    ReferenceScanner scanner(prefix, limit);
    scanner.run();
}

} // namespace pak_hot_reload
