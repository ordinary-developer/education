#include <atomic>


int main() {
    std::atomic<bool> b;
    bool x = b.load(std::memory_order_acquire);
    b.store(true);
    x = b.exchange(false, std::memory_order_acq_rel);

    return 0;
}

