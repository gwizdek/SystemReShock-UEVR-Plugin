#pragma once

#include <string>

namespace pak_hot_reload {

// Finds live objects whose reflected properties point at an object from a package under
// `prefix`, for example "/Game/Mods/". Those references are what keep a package in memory
// after its instances are gone. Logs at most `limit` references, then a total.
// Only UPROPERTY references are visible: object, class and interface properties, arrays
// of them, and structs that hold them. References held in native code are not found.
void log_referencers(const std::wstring& prefix, int limit);

} // namespace pak_hot_reload
