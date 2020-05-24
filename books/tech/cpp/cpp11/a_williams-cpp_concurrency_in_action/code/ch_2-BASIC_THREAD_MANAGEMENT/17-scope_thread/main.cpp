#include <thread>
#include <iostream>
#include <memory>

class scoped_thread {
        std::thread t;
    public:
        explicit scoped_thread(std::thread t_):
            t(std::move(t_))
        {
            if (!t.joinable())
                throw std::logic_error("No thread");
        }
        ~scoped_thread()
        {
            std::cout << "destructor calling" << std::endl;
            t.join();
        }

        scoped_thread(const scoped_thread&) = delete;
        scoped_thread& operator= (scoped_thread const&) = delete;
};

struct func {
    int& i;

    func(int& i_) : i(i_) { }

    void operator() () {
        for (unsigned j = 0; j < 1000000; ++j) {
            do_something();
        }
    }

    void do_something() {
        std::cout << "[another thread]: " << " working" << std::endl;
    }
};

void do_something_in_current_thread() {
    std::cout << "[current thread]: " << " working" << std::endl;
}

void f() {
    int some_local_state;
    auto scoped_thread_ptr = std::make_unique<scoped_thread>(
        std::thread(func(some_local_state)));

    do_something_in_current_thread();
}

int main() { 
    f();

    return 0;
}
