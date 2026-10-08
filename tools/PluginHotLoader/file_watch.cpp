#include <windows.h>

#include "file_watch.hpp"

namespace plugin_hot_load {
namespace {

// True when no other process has the file open. Opening with no sharing fails while a
// writer still holds it, which keeps a copy in progress from being picked up.
bool nobody_has_open(const std::filesystem::path& file) {
    HANDLE handle = CreateFileW(file.c_str(), GENERIC_READ, 0, nullptr, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, nullptr);
    if (handle == INVALID_HANDLE_VALUE) return false;
    CloseHandle(handle);
    return true;
}

} // namespace

FileWatch::FileWatch(std::filesystem::path file, std::chrono::milliseconds settle)
    : m_file(std::move(file)), m_settle(settle) {}

void FileWatch::accept() {
    m_accepted = current_write_time();
    m_candidate.reset();
}

bool FileWatch::changed_and_settled() {
    const auto now_time = current_write_time();
    if (!now_time || now_time == m_accepted) {
        m_candidate.reset();
        return false;
    }
    if (now_time != m_candidate) {
        m_candidate = now_time;
        m_candidate_since = Clock::now();
        return false;
    }
    return Clock::now() - m_candidate_since >= m_settle && nobody_has_open(m_file);
}

std::optional<FileWatch::WriteTime> FileWatch::current_write_time() const {
    std::error_code ec;
    const auto time = std::filesystem::last_write_time(m_file, ec);
    if (ec) return std::nullopt;
    return time;
}

} // namespace plugin_hot_load
