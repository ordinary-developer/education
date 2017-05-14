#include <mutex>
#include <condition_variable>
#include <thread>
#include <queue>
#include <iostream>
#include <chrono>

bool more_data_to_prepare() { return false; }

struct data_chunk { };

data_chunk prepare_data() { return data_chunk(); }

void process(data_chunk&) { 
    std::cout << "[OK] - begin processing data" << std::endl; 
    std::this_thread::sleep_for(std::chrono::milliseconds(3000));
    std::cout << "[OK] - end processing data" << std::endl; 
} 

bool is_last_chunk(data_chunk&) { return true; }


std::mutex mutex;
std::queue<data_chunk> data_queue;
std::condition_variable data_condition;

void dataPreparationThread() {
    do {
        const data_chunk data = prepare_data();
        std::lock_guard<std::mutex> lock(mutex);
        std::cout << "[ok] - {producer} start locking" << std::endl;
        data_queue.push(data);
        data_condition.notify_one();
        std::cout << "[ok] - {producer} stop locking" << std::endl;
    } while (more_data_to_prepare());
}

void dataProcessingThread() {
    while (true) {
        std::unique_lock<std::mutex> lock(mutex);
        data_condition.wait(lock, [] {
                                        return !data_queue.empty();
                                     });
        std::cout << "[ok] - {consumer} start locking" << std::endl;
        data_chunk data = data_queue.front();
        data_queue.pop();
        std::cout << "[ok] - {consumer} stop locking" << std::endl;
        lock.unlock();
        process(data);
        if (is_last_chunk(data)) {
            break;
        }
    }
}

int main() { 
    std::thread t1(dataPreparationThread);
    std::thread t2(dataProcessingThread);

    t1.join();
    t2.join();

    return 0;
}

