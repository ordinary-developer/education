#include <mutex>
#include <condition_variable>
#include <queue>
#include <thread>
#include <iostream>


template <typename T>
class threadsafe_queue {
    public:
        void push(T new_value) {
            std::lock_guard<std::mutex> lock(mutex);
            std::cout << "[OK] - start to push value" << std::endl;
            data_queue.push(new_value);
            data_condition.notify_one();
            std::cout << "[OK] - finish to push value" << std::endl;
        }

        void wait_and_pop(T& value) {
            std::unique_lock<std::mutex> lock(mutex);
            data_condition.wait(lock,
                                [this] {
                                           return !data_queue.empty();
                                       }); 
            std::cout << "[OK] - start to pop value" << std::endl;
            value = data_queue.front();
            data_queue.pop();
            std::cout << "[OK] - finish to pop value" << std::endl;
        }

    private:
        std::mutex mutex;
        std::queue<T> data_queue;
        std::condition_variable data_condition;
};


struct data_chunk { 
    unsigned int number;
};

data_chunk prepare_data(unsigned int i) {
    data_chunk data;
    data.number = i;
    return data;
}

bool more_data_to_prepare(unsigned int counter) {
    const unsigned int upperBound = 10;
    return (upperBound != counter); 
}

void process(data_chunk&) { }

bool is_last_chunk(data_chunk& data) {
    const unsigned int upperBound = 10;
    return ((upperBound - 1)== data.number);
}


threadsafe_queue<data_chunk> data_queue;

void data_preparation_thread() {
    unsigned int i = 0;
    while (more_data_to_prepare(i)) {
        const data_chunk data = prepare_data(i);
        data_queue.push(data);
        i++;
    }
}

void data_processing_thread() {
    while (true) {
        data_chunk data;
        data_queue.wait_and_pop(data);
        process(data);
        if (is_last_chunk(data))
            break;
    }
}

int main() {
    std::thread t1(data_preparation_thread);
    std::thread t2(data_processing_thread);

    t1.join();
    t2.join();

    return 0;
}
