#include <memory>
#include <mutex>
#include <condition_variable>
#include <future>
#include <thread>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <cstdint>


template <typename T>
class threadsafe_queue {
    public:
        threadsafe_queue()
            : _head(new node()), _tail(_head.get()) { }
        threadsafe_queue(const threadsafe_queue&) = delete;
        threadsafe_queue& operator=(const threadsafe_queue&) = delete;

        void push(T new_value) {
            std::shared_ptr<T> new_data(
                std::make_shared<T>(std::move(new_value)));
            std::unique_ptr<node> p(new node());

            {
                std::lock_guard<std::mutex> lock(_tail_mutex);
                _tail->data = new_data;
                node* const new_tail = p.get();
                _tail->next = std::move(p);
                _tail = new_tail;
            }

            _data_cond.notify_one();
        }

        std::shared_ptr<T> wait_and_pop() {
            std::unique_ptr<node> const old_head = wait_pop_head();
            return old_head->data;
        }

        void wait_and_pop(T& value) {
            std::unique_ptr<node> const old_head =
                wait_pop_head(value);
        }

        std::shared_ptr<T> try_pop() {
            std::unique_ptr<node> old_head = try_pop_head();
            return old_head ? old_head->data : std::shared_ptr<T>();
        }

        bool try_pop(T& value) {
            std::unique_ptr<node> const old_head = 
                try_pop_head(value);
            return old_head;
        }

        bool empty() {
            std::lock_guard<std::mutex> head_lock(_head_mutex);
            return (_head.get() == get_tail());
        }

    private:
        struct node;

        node* get_tail() {
            std::lock_guard<std::mutex> tail_lock(_tail_mutex);
            return _tail;
        }

        std::unique_ptr<node> pop_head() {
            std::unique_ptr<node> old_head = std::move(_head);
            _head = std::move(old_head->next);
            return old_head;
        }

        std::unique_lock<std::mutex> wait_for_data() {
            std::unique_lock<std::mutex> head_lock(_head_mutex);
            _data_cond.wait(head_lock,
                           [&]() -> bool {
                             return _head.get() != get_tail();
                           });
            return std::move(head_lock);
        }

        std::unique_ptr<node> wait_pop_head() {
            std::unique_lock<std::mutex> head_lock(wait_for_data());
            return pop_head();
        }

        std::unique_ptr<node> wait_pop_head(T& value) {
            std::unique_lock<std::mutex> head_lock(wait_for_data());
            value = std::move(*_head->data);
            return pop_head();
        }


        std::unique_ptr<node> try_pop_head() {
            std::lock_guard<std::mutex> head_lock(_head_mutex);
            return (_head.get() == get_tail()) 
                   ? std::unique_ptr<node>() : pop_head();
        }

        std::unique_ptr<node> try_pop_head(T& value) {
            std::lock_guard<std::mutex> head_lock(_head_mutex);
            if (_head.get() == get_tail())
                return std::unique_ptr<node>();
            value = std::move(*_head->data);
            return pop_head();
        }

        struct node {
            std::shared_ptr<T> data;
            std::unique_ptr<node> next;
        };

        std::unique_ptr<node> _head;
        node* _tail;
        std::mutex _head_mutex;
        std::mutex _tail_mutex;
        std::condition_variable _data_cond;
};

int get_random_int(int min, int max) {
    return min + (rand() % (int)(max - min + 1));
}

int main() {
    threadsafe_queue<uint32_t> queue;

    std::vector<std::future<void>> futures;
    for (uint32_t i = 0; i < 10; ++i) 
        futures.emplace_back(
            std::async(std::launch::async, 
                       [&queue, &i]() -> void {
                         queue.push(i);
                         std::this_thread::sleep_for(
                           std::chrono::seconds(get_random_int(2, 7)));
                         queue.push(i + 1);
                         queue.wait_and_pop();
                         queue.push(i + 2);
                         queue.wait_and_pop();
                       }));

    for (auto& future: futures) 
        future.get();
    std::cout << "[calculating finished]" << std::endl;

    auto p = queue.try_pop();
    while (p) {
        std::cout << *p << std::endl;
        p = queue.try_pop();
    }
    return 0;
}
