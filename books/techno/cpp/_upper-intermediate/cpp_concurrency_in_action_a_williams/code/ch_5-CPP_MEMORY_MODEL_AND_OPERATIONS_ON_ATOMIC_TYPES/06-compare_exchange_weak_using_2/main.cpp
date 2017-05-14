#include <atomic>

int main() {
    std::atomic<bool> b(true);
    bool expected = false;
    b.compare_exchange_weak(expected, true,
            std::memory_order_acq_rel, std::memory_order_acquire);
    b.compare_exchange_weak(expected, true, std::memory_order_acq_rel);

    return 0;
}
