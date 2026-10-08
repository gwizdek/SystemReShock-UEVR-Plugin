#pragma once

#include <chrono>
#include <filesystem>
#include <optional>

namespace plugin_hot_load {

// Reports a file as changed once its last write time differs from the one last accepted, has
// then stayed the same for the settle time, and nobody holds the file open any more. A file
// that is still being written is therefore not reported. A missing file is never reported.
class FileWatch {
public:
    FileWatch(std::filesystem::path file, std::chrono::milliseconds settle);

    // Remembers the file's current write time as the accepted one.
    void accept();

    // Call on every poll. True once per accepted change.
    bool changed_and_settled();

private:
    using WriteTime = std::filesystem::file_time_type;
    using Clock = std::chrono::steady_clock;

    std::optional<WriteTime> current_write_time() const;

    std::filesystem::path m_file;
    std::chrono::milliseconds m_settle;
    std::optional<WriteTime> m_accepted;
    std::optional<WriteTime> m_candidate;
    Clock::time_point m_candidate_since{};
};

} // namespace plugin_hot_load
