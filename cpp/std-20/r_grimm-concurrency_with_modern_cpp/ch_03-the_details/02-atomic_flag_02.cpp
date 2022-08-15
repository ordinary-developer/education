#include <chrono>
#include <mutex>
#include <thread>


std::mutex mut{};

void workOnRes() {
    mut.lock();
    std::this_thread::sleep_for(std::chrono::milliseconds{5000});
    mut.unlock();
}


int main(){
    std::thread t1(workOnRes);
    std::thread t2(workOnRes);
    t1.join();
    t2.join();
}
