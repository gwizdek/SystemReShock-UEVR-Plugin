#pragma once

#include <string>
#include <vector>

namespace pak_hot_reload {

// Asks the engine's pak layer about each file and logs whether it exists and its size.
// `when` is a short label such as "before mount".
void log_file_probes(void* pak_platform_file, const std::vector<std::wstring>& file_paths, const char* when);

// Logs every package object in memory whose name starts with `prefix`, for example
// "/Game/Mods/". A package that is still loaded is not read from disk again, so its
// classes keep the old content even after a new pak is mounted.
void log_loaded_packages(const std::wstring& prefix);

// Logs live objects whose class comes from a package under `prefix`: actors, components,
// widgets and other instances, but not the classes themselves or their default objects.
// These are what keep the packages alive. At most `limit` lines are written.
void log_live_instances(const std::wstring& prefix, int limit);

// Asks the engine to run a garbage collection on its next tick, through the
// Blueprint-callable KismetSystemLibrary::CollectGarbage. Returns false when the
// function is not found.
bool request_garbage_collection();

} // namespace pak_hot_reload
