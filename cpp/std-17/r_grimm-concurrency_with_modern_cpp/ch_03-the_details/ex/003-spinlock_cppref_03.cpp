#include <atomic>

std::atomic_flag static_flag = ATOMIC_FLAG_INIT;

int main() {
    std::atomic_flag automatic_flag = ATOMIC_FLAG_INIT;
}
