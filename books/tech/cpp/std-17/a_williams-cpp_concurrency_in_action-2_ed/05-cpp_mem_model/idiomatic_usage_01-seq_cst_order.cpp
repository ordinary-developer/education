#include <atomic>
#include <chrono>
#include <thread>
#include <cassert>
namespace workspace {

int data{};
std::atomic<bool> data_ready{false};

void writer_thread() {
    data = 42;
    data_ready = true;
}

void reader_thread() {
    while (not data_ready.load()) // std::memory_order_seq_cst
        std::this_thread::sleep_for(std::chrono::milliseconds{1});

    assert(42 == data);
}
    
void run() {
    std::thread t1{ reader_thread }, t2{ writer_thread };
    t1.join(), t2.join();
}
} // workspace


int main() {
    workspace::run();

    return 0;
}
