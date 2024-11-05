#include <chrono>
#include <iostream>
#include <mutex>
#include <thread>


struct CriticalData {
    std::mutex mut;
};

void deadLock(CriticalData& a, CriticalData& b) {
    std::cout << "Thread: " << std::this_thread::get_id() << " first mutex" << std::endl;
    std::cout << "Thread: " << std::this_thread::get_id() << " second mutex" << std::endl;

    std::this_thread::sleep_for(std::chrono::milliseconds{1});

    std::cout << "Thread: " << std::this_thread::get_id() << " get both mutex" << std::endl;
    std::scoped_lock(a.mut, b.mut);
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
