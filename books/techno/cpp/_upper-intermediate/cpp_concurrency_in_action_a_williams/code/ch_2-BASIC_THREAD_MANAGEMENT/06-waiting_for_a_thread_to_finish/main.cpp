#include <thread>
#include <iostream>

void do_something(int value) {
    std::cout << value << std::endl;
}

struct func {
    int& i;
    
    func(int& i_) : i (i_) { }

    void operator()() {
        for (unsigned j = 0; j < 1000000; ++j) {
            do_something(j);
        }
    }    
};

void do_something_in_current_thread() { }


void f() {
    int some_local_state = 0;
    func my_func(some_local_state);
    std::thread t(my_func);
    try {
        do_something_in_current_thread();
    }
    catch (...) {
        t.join();
        throw;
    }
    t.join();
}

int main() {
    f();

    return 0;
}