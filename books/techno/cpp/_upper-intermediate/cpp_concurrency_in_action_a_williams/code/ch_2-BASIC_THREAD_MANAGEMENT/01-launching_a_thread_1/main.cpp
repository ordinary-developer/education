#include <thread>
#include <iostream>

void do_some_work() {
    std::cout << "Inside a thread" << std::endl;
}

int main() {
    std::thread my_thread(do_some_work);
    my_thread.join();

    return 0;
}
