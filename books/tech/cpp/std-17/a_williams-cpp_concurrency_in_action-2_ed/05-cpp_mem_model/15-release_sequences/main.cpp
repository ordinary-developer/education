#include <atomic>
#include <thread>
#include <vector>
namespace workspace {
    
std::vector<int> queue_data{};
std::atomic<int> count{};
    
void wait_for_more_items() {}
void process(int const) {}
    
void populate_queue() {
    unsigned constexpr num_of_items{20};
    
    queue_data.clear();
    for (unsigned i{0}; i < num_of_items; ++i)
        queue_data.push_back(i);
    
    count.store(num_of_items, std::memory_order_release);
}
    
void consume_queue_items() {
    while (true) {
        int item_index{};
        if ((item_index = count.fetch_sub(1, std::memory_order_acquire)) <= 0) {
            wait_for_more_items();
            break;
        }
        process(queue_data[item_index - 1]);
    }
}
    
void run() {
    std::thread t1{ populate_queue }, t2{ consume_queue_items }, t3{ consume_queue_items };
    t1.join(), t2.join(), t3.join();
}
} // workspace


#include <iostream>
int main() {    
    std::cout << "[ok] - workspace" << std::endl; workspace::run(); std::cout << std::endl << std::endl;
   
    return 0;
}
