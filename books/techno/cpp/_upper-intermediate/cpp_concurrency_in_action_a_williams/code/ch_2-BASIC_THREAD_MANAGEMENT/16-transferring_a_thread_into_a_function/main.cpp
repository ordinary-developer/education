#include <thread>
#include <iostream>

void some_function() {
    std::cout << "some_function()" << std::endl;
}

void f(std::thread t) {
}

void g() {
    f(std::thread(some_function));
    std::thread t(some_function);
    f(std::move(t));
}

int main() {
    g();

    return 0;
}
