#include <atomic>

int main() {
    std::atomic<bool> b(true);
    b = false;

    return 0;
}

