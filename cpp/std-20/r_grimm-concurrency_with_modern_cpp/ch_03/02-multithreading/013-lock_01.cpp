#include <chrono>
#include <iostream>
#include <mutex>
#include <thread>


struct CriticalData {
    std::mutex mut;
};

void deadLock(CriticalData& a, CriticalData& b) {
    std::unique_lock<std::mutex> guard1(a.mut, std::defer_lock);
    std::cout << "Thread: " << std::this_thread::get_id() << " first mutex" << '\n';

    std::this_thread::sleep_for(std::chrono::milliseconds(1));

    std::unique_lock<std::mutex> guard2(b.mut, std::defer_lock);
    std::cout << "  Thread: " << std::this_thread::get_id() << " second mutex" << '\n';

    std::cout << "    Thread: " << std::this_thread::get_id() << " get both mutex" << '\n';
    std::lock(guard1, guard2);
}

int main() {
    std::cout << '\n';

    CriticalData c1;
    CriticalData c2;

    std::thread t1([&] { deadLock(c1, c2); });
    std::thread t2([&] { deadLock(c2, c1); });

    t1.join();
    t2.join();

    std::cout << '\n';
}
