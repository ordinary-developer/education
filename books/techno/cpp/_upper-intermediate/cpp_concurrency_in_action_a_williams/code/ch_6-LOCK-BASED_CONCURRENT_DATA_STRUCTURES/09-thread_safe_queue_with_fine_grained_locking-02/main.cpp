#include <memory>
#include <mutex>
#include <vector>
#include <functional>
#include <cstdint>
#include <future>
#include <thread>
#include <chrono>
#include <iostream>

template <typename T>
class threadsafe_queue {
    public:
        threadsafe_queue()
            : _head(new node()), _tail(_head.get()) { }
        threadsafe_queue(const threadsafe_queue&) = delete;
        threadsafe_queue& operator=(const threadsafe_queue&) = delete;

        std::shared_ptr<T> try_and_pop() {
            std::unique_ptr<node> old_head = pop_head();
            return old_head ? old_head->data : std::shared_ptr<T>();
        }

        void push(T new_value) {
            std::shared_ptr<T> new_data(
                std::make_shared<T>(std::move(new_value)));
            std::unique_ptr<node> p(new node());
            node* new_tail = p.get();
            std::lock_guard<std::mutex> lock(_tail_mutex);
            _tail->data = new_data;
            _tail->next = std::move(p);
            _tail = new_tail;
        }

    private:
        struct node;

        node* get_tail() {
            std::lock_guard<std::mutex> lock(_tail_mutex);
            return _tail;
        }

        std::unique_ptr<node> pop_head() {
            std::lock_guard<std::mutex> lock(_head_mutex);

            if (_head.get() == get_tail())
                return nullptr;

            std::unique_ptr<node> old_head = std::move(_head);
            _head = std::move(old_head->next);
            return old_head;
        }

        struct node {
            std::shared_ptr<T> data;
            std::unique_ptr<node> next;
        };

        std::unique_ptr<node> _head;
        node* _tail;
        std::mutex _head_mutex;
        std::mutex _tail_mutex;
};

int main() {
    threadsafe_queue<uint32_t> queue;

    std::vector<std::future<void>> futures;
    for (uint32_t i = 0; i < 10; ++i) 
        futures.emplace_back(
            std::async(std::launch::async, 
                       [&queue, &i]() -> void 
                       {
                         queue.push(i);
                         queue.push(i + 1);
                         queue.push(i + 2);
                         std::this_thread::sleep_for(
                           std::chrono::seconds(3));
                         queue.try_and_pop();
                       }));

    for (auto& future: futures) 
        future.get();
    std::cout << "[calculating finished]" << std::endl;

    auto p = queue.try_and_pop();
    while (p) {
        std::cout << *p << std::endl;
        p = queue.try_and_pop();
    }

    return 0;
}
