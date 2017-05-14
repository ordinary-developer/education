#include <thread>
#include <iostream>

class thread_guard {
    std::thread& t;
public:
    explicit thread_guard(std::thread& t_) : t(t_) {
    	std::cout << "We are in a constructor\n";
    } 

    ~thread_guard() {
        std::cout << "We are in a destructor\n";
        if (t.joinable()) {
	    t.join();
	}
    }

    thread_guard(thread_guard const&) = delete;
    thread_guard& operator= (thread_guard const&) = delete;
};

struct func {
    int& i;

    func(int& i_) : i(i_) { }

    void operator()() {
        for (unsigned j = 0; j < 1000000; ++j) {
	    do_something(i);
	}
    }

    void do_something(int value) { }
};

void do_something_in_current_thread() {
    throw std::exception();
}

void f() {
    int some_local_stage = 0;
    func my_func(some_local_stage);
    std::thread t(my_func);
    thread_guard g(t);

    do_something_in_current_thread();
}

int main() {
    try {
    	f();
    }
    catch (std::exception&) {
	std::cout << "the exception was cought\n";
    }

    return 0;
}
