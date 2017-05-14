#include <mutex>
#include <memory>>
template <typename T>
class threadsafe_list {
    public:
        threadsafe_list() = default;
        threadsafe_list(const threadsafe_list&) = delete;
        threadsafe_list& operator=(const threadsafe_list&) = delete;
        ~threadsafe_list() { 
            remove_if([](const node&) {
                          return true;
                        }
                     );
        }

        void push_front(const T& value) { 
            std::unique_ptr<node> new_node(new node(value));
            std::lock_guard<std::mutex> lock(head.m);
            new_node->next = std::move(head.next);
            head.next = std::move(new_node);
        }

        template <typename Function>
        void for_each(Function f) {
            node* current = &head;
            std::unique_lock<std::mutex> lock(head.m);
            while (node* const next = current->next.get()) {
                std::unique_lock<std::mutex> next_lock(next->m);
                lock.unlock();
                f(*next->data);
                current = next;
                lock = std::move(next_lock);
            }
        }

        template <typename Predicate>
        std::shared_ptr<T> find_first_if(Predicate p) {
            node* current = &head;
            std::unique_lock<std::mutex> lock(head.m);
            while (node* const next = current->next.get()) {
                std::unique_lock<std::mutex> next_lock(next->m);
                lock.unlock();
                if (p(*next->data)) {
                    return next->data;
                }
                current = next;
                lock = std::move(next_lock);
            }
            return std::shared_ptr<T>();
        }

        template <typename Predicate>
        void remove_if(Predicate p) {
            node* current = &head;
            std::unique_lock<std::mutex> lock(head.m);
            while (node* const next = current->next.get()) {
                std::unique_lock<std::mutex> next_lock(next->m);
                if (p(*next->data)) {
                    std::unique_ptr<node> old_next = 
                        std::move(current->next);
                    current->next = std::move(next->next);
                    next_lock.unlock();
                }
                else {
                    lock.unlock();
                    current = next;
                    lock = std::move(next_lock);
                }
            }
        }

    private:
        struct node {
            node() 
                : next() { }
            node(const T& value) 
                : data(std::make_shared<T>(value)) { }

            std::mutex m;
            std::shared_ptr<T> data;
            std::unique_ptr<node> next;
        };

        node head;
};


#include <cstdint>
#include <iostream>

void run_single_thread() {
    threadsafe_list<uint32_t> list;

    list.push_front(uint32_t(0));
    list.push_front(uint32_t(1));
    list.push_front(uint32_t(2));
    list.push_front(uint32_t(0));
    list.push_front(uint32_t(1));
    list.push_front(uint32_t(2));

    list.for_each([](const auto& item) -> auto {
                      std::cout << item << std::endl;       
                    }
                 );

    auto element = list.find_first_if([](const auto item) -> auto
                                        {
                                          return 2 == item;
                                        });
    if (element)
        std::cout << *element;
    else
        std::cout << "no such element";
    std::cout << std::endl;

    std::cout << "[ok] - finished one thread" << std::endl;
}


#include <iostream>
#include <cstdint>
#include <cstdlib>
#include <vector>
#include <chrono>
#include <future>

int get_random_int(int min, int max) {
    return min + (rand() % (int)(max - min + 1));
}

void run_multiple_threads() {
    threadsafe_list<uint32_t> list;

    std::vector<std::future<void>> futures;
    for (uint32_t i = 0; i < 10; ++i) {
        futures.emplace_back(
            std::async(std::launch::async,
                       [&list, i]() -> void {
                         list.push_front(i);                         
                         std::this_thread::sleep_for(
                             std::chrono::seconds(
                                 get_random_int(1, 3)));
                         list.push_front(i + 1);
                       }));
    }
    
    for (auto& future : futures)
        future.get();

    list.for_each([](const auto& item) -> void {
                      std::cout << item << std::endl;
                    });
    std::cout << "[ok] - finished multiple threads";
}



int main() {
    run_single_thread();
    run_multiple_threads();

    return 0;
}
