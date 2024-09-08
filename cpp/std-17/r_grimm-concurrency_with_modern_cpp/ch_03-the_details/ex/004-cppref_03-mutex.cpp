#include <chrono>
#include <iostream>
#include <mutex>
#include <thread>

std::chrono::milliseconds interval(100);

std::mutex mutex;
int job_shared = 0;

int job_exclusive = 0;

void job_1() {
    std::this_thread::sleep_for(interval);

    while (true) {
        if (mutex.try_lock()) {
            std::cout << "job shared (" << job_shared << ")\n";
            mutex.unlock();
            return;
        }
        else {
            ++job_exclusive;
            std::cout << "job exclusive (" << job_exclusive << ")\n";
            std::this_thread::sleep_for(interval);
        }
    }
}

void job_2() {
    mutex.lock();
    std::this_thread::sleep_for(5 * interval);
    ++job_shared;
    mutex.unlock();
}

int main() {
    std::thread thread_1(job_1);
    std::thread thread_2(job_2);
    thread_1.join();
    thread_2.join();
}
