#include <atomic>
#include <cassert>
#include <csignal>

std::atomic<bool> a{false};
std::atomic<bool> b{false};

extern "C" void handler(int) {
    if (a.load(std::memory_order_relaxed)) {
        std::atomic_signal_fence(std::memory_order_acquire);
        assert(b.load(std::memory_order_relaxed));
    }
}


int main() {
    std::signal(SIGTERM, handler);

    b.store(true, std::memory_order_relaxed);
    std::atomic_signal_fence(std::memory_order_release);
    a.store(true, std::memory_order_relaxed);
}
