#include <thread>
#include <iostream>

void do_something() {
    std::cout << "do_something()" << std::endl;
}

void do_something_else() {
    std::cout << "do_something_else()" << std::endl;
}

int main() {
    std::thread my_thread([] {
        do_something();
        do_something_else();
    });
    my_thread.join();

    return 0;
}
