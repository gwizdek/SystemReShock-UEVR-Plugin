#pragma once

#include <windows.h>

#include <atomic>
#include <shared_mutex>

// An exclusive lock that the thread holding it may take again. Built on std::shared_mutex,
// which is SRWLock based and works with the game's old MSVCP140; std::mutex and
// std::recursive_mutex do not (see .claude/rules/build.md).
//
// Needed for the ImGui lock: ImGui's Win32 handler calls SetCapture and ReleaseCapture,
// and Windows then delivers WM_CAPTURECHANGED to the same window from inside that call,
// which re-enters on_message on the thread that already holds the lock.
//
// Meets BasicLockable, so std::unique_lock works with it.
class ReentrantLock {
public:
    void lock() {
        const DWORD me = GetCurrentThreadId();
        if (m_owner.load(std::memory_order_relaxed) == me) {
            ++m_depth;
            return;
        }
        m_mutex.lock();
        m_owner.store(me, std::memory_order_relaxed);
        m_depth = 1;
    }

    void unlock() {
        if (--m_depth > 0) return;
        m_owner.store(0, std::memory_order_relaxed);
        m_mutex.unlock();
    }

private:
    std::shared_mutex m_mutex;
    std::atomic<DWORD> m_owner{ 0 };
    int m_depth{ 0 };   // only touched by the owner
};
