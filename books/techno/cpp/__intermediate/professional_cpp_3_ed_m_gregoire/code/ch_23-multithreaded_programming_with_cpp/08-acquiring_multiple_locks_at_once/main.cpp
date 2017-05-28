#include <mutex>

std::mutex mutex1{};
std::mutex mutex2{};
void process() {
    std::unique_lock<std::mutex> lock1{ mutex1, std::defer_lock_t{} };
    std::unique_lock<std::mutex> lock2{ mutex2, std::defer_lock_t{} };
    lock(lock1, lock2);
}

int main() {
    process();

    return 0;
}
