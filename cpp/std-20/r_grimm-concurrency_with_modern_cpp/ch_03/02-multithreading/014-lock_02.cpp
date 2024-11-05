#include <chrono>
#include <iostream>
#include <mutex>
#include <thread>


struct CriticalData {
    std::mutex mut;
};

void deadLock(CriticalData& a, CriticalData& b) {
    std::lock(a.mut, b.mut);
    std::cout << "Thread: " << std::this_thread::get_id() << " get both mutex" << std::endl;

    std::lock_guard<std::mutex> guard1(a.mut, std::adopt_lock);
    std::cout << "Thread: " << std::this_thread::get_id() << " first mutex" << std::endl;

    std::lock_guard<std::mutex> guard2(b.mut, std::adopt_lock);
    std::cout << "Thread: " << std::this_thread::get_id() << " second mutex" << std::endl;
}


int main() {
    std::cout << std::endl;

    CriticalData c1;
    CriticalData c2;

    std::thread t1([&] { deadLock(c1, c2); });
    std::thread t2([&] { deadLock(c2, c1); });

    t1.join();
    t2.join();

    std::cout << std::endl;
}
