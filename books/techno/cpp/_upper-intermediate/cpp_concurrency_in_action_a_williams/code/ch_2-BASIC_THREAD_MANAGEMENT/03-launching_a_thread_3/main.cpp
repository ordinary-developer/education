#include <thread>
#include <iostream>

class background_task {
    public:
        void operator() () const {
            do_something();
            do_something_else();
        }
    private:
        void do_something() const {
            std::cout << "do_something\n";
        }

        void do_something_else() const {
            std::cout << "do_something_else\n";
        }
};


int main() {
    // it is a function
    std::thread my_thread1(background_task());

    std::thread my_thread2 {background_task()};
    my_thread2.join();

    return 0;
}
