#include <mutex>
#include <condition_variable>
#include <queue>
#include <thread>
#include <thread>


template <typename T>
class threadsafe_queue {
    public:
        void push(T new_value) {
            std::lock_guard<std::mutex> lk(mut);
            data_queue.push(new_value);
            data_cond.notify_one();
        }

        void wait_and_pop(T& value) {
            std::unique_lock<std::mutex> lk(mut);
            data_cond.wait(lk, [this] {
                                          return !data_queue.empty();
                                      });
            value = data_queue.front();
            data_queue.pop();
        }

    private:
        std::mutex mut;
        std::queue<T> data_queue;
        std::condition_variable data_cond;
};



struct data_chunk { };

data_chunk prepare_data() {
    return data_chunk();
}

bool more_data_to_prepare() { return false; }

void process(data_chunk) { }

bool is_last_chunk(data_chunk) { return true; }



threadsafe_queue<data_chunk> data_queue;

void data_preparation_thread() {
    do {
        const data_chunk data = prepare_data();
        data_queue.push(data);
    } while (more_data_to_prepare());
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
