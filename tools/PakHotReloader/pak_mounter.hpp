#pragma once

#include <cstdint>
#include <filesystem>

#include "engine_resolver.hpp"

namespace pak_hot_reload {

// Mounts rebuilt pak files into the running game.
//
// The game keeps every mounted pak open, so a pak cannot be overwritten in place.
// Each mount therefore copies the source pak into a staging folder under a new name
// and mounts the copy with a higher order than everything mounted before it. Older
// copies stay mounted but are shadowed; nothing is unmounted.
class PakMounter {
public:
    PakMounter(const EngineFunctions& functions, std::filesystem::path staging_dir);

    // Copies `source_pak` into the staging folder and mounts the copy.
    // Returns false, and logs the reason, when the copy or the mount fails.
    bool mount_copy(const std::filesystem::path& source_pak);

    // Deletes copies left behind by earlier game sessions. Call before the first mount.
    void clear_staging_dir();

    // The engine's FPakPlatformFile instance, or null when the lookup fails.
    void* pak_platform_file() const;

private:
    std::filesystem::path next_staging_path(const std::filesystem::path& source_pak);

    EngineFunctions m_functions;
    std::filesystem::path m_staging_dir;
    uint32_t m_mount_count{0};
};

} // namespace pak_hot_reload
