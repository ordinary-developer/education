#include <thread>
#include <iostream>


void some_function() {
    std::cout << "some_function" << std::endl;
}

void some_other_function(int value) {
    std::cout << "some_other_function(" << value << ")" 
              << std::endl;
}

std::thread f() {
    return std::thread(some_function);
}

std::thread g() {
    std::thread t(some_other_function, 42);
    return t;
}


int main() {
    std::thread t1 = f();
    std::thread t2 = g();
    t1.join();
    t2.join();

    return 0;
}
