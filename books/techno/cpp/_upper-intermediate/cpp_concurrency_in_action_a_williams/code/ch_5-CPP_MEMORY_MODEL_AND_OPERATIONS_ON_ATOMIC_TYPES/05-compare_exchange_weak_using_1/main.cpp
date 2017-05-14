#include <atomic>

int main() {
    bool expected = false;
    std::atomic<bool> b(false);
    while (b.compare_exchange_weak(expected, true) && expected);

    return 0;
}
