#include <iostream>
#include <thread>

int main() {
    std::thread t([]{ std::cout << std::this_thread::get_id() << '\n'; });
    t.join();
}