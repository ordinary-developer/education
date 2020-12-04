#include <mutex>
#include <condition_variable>
#include <thread>
#include <queue>
#include <memory>
#include <iostream>
#include <stdlib.h>
#include <time.h>


template <typename T>
class threadsafe_queue {
    public:
        threadsafe_queue() = default;

        threadsafe_queue(const threadsafe_queue& other) {
            std::lock_guard<std::mutex> lk(other.mut);
            data_queue = other.data_queue;
        }

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

        std::shared_ptr<T> wait_and_pop() {
            std::unique_lock<std::mutex> lk(mut);
            data_cond.wait(lk, [this] {
                                        return !data_queue.empty();
                                      });
            std::shared_ptr<T> res(std::make_shared<T>(
                                        data_queue.front()));
            data_queue.pop();
            return res;
        }

        bool try_pop(T& value) {
            std::lock_guard<std::mutex> lk(mut);
            if (data_queue.empty()) {
                return false;
            }
            value = data_queue.front();
            data_queue.pop();
        }

        std::shared_ptr<T> try_pop() {
            std::lock_guard<std::mutex> lk(mut);
            if (data_queue.empty()) {
                return std::shared_ptr<T>();
            }
            std::shared_ptr<T> res(std::make_shared<T>(
                                        data_queue.front()));
            data_queue.pop();
            return res;
        }

        bool empty() const 
        {
            std::lock_guard<std::mutex> lk(mut);
            return data_queue.empty();
        }

    private:
        mutable std::mutex mut;
        std::queue<T> data_queue;
        std::condition_variable data_cond;
};


class data_chunk {
    public:
        data_chunk(unsigned int i = 0) : _i(i) { }

        unsigned int getNumber() { return _i; }
            
    private:
        unsigned int _i;
};


template <typename T>
class data_preparation_thread {
    public:
        data_preparation_thread(
            std::unique_ptr<threadsafe_queue<T>>& queue,
            unsigned int upperBound)
        : _queue(queue), _upperBound(upperBound)
        { } 

        void operator () () {
            unsigned int i = 0;
            while (more_data_to_prepare(i)) {
                const data_chunk data = prepare_data(i++);
                _queue->push(data);
            }
        }

    private:
        T prepare_data(unsigned int i) {
            return T(i);
        }

        bool more_data_to_prepare(unsigned int i) {
            return (i < _upperBound);
        }

        std::unique_ptr<threadsafe_queue<T>>& _queue;
        unsigned int _upperBound;
};


template <typename T>
class data_processing_thread {
    public:
        data_processing_thread(
            std::unique_ptr<threadsafe_queue<T>>& queue,
            unsigned int upperBound)
        : _queue(queue), _upperBound(upperBound) 
        { } 

        void operator() () {
            while (true) {
                T value;
                _queue->wait_and_pop(value);
                process(value);
                if (is_last_portion(value)) {
                    break;
                }
            }
        }

    private:
        void process(T value) {
            std::cout << "Processing value" << std::endl;
        }

        bool is_last_portion(T value) {
            return value.getNumber() == (_upperBound - 1);
        }

        std::unique_ptr<threadsafe_queue<T>>& _queue;
        unsigned int _upperBound;
};



int main() {
    std::unique_ptr<threadsafe_queue<data_chunk>> queue = 
        std::make_unique<threadsafe_queue<data_chunk>>();
    unsigned int upperBound = 10;

    data_preparation_thread<data_chunk> preparation(queue, upperBound);
    data_processing_thread<data_chunk> processing(queue, upperBound);
    std::thread t1(preparation);
    std::thread t2(processing);
    t1.join();
    t2.join();

    return 0;
}

