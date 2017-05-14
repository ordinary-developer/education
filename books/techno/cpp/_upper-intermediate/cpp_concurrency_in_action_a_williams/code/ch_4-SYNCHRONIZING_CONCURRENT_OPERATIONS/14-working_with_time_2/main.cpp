#include <chrono>
#include <future>
#include <iostream>

int some_task() {
    std::cout << "doing the work" << std::endl;
    return 42;
}

void do_something_with(int value) {
    std::cout << value << std::endl;
}

int main() {
    std::future<int> f = std::async(some_task);
    if (std::future_status::ready == 
            f.wait_for(std::chrono::milliseconds(35)))
    {
        do_something_with(f.get());
    }

    return 0;
}
