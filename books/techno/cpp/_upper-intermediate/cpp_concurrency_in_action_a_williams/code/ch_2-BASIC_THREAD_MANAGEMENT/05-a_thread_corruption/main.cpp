#include <thread>
#include <iostream> 

void do_something(int value) { 
    std::cout << value << std::endl;
}

struct func {
    int& i;
    
    func(int& i_) : i(i_) { }
    
    void operator()() {
        for (unsigned j = 0; j < 1000000; ++j) {
            // potential access to dangling reference
            do_something(i);
        }
    }
};

void oops() {
    int some_local_state = 0;
    func my_func(some_local_state);
    std::thread my_thread(my_func);
    my_thread.detach();
}

int main() {
    oops();

    return 0;
}