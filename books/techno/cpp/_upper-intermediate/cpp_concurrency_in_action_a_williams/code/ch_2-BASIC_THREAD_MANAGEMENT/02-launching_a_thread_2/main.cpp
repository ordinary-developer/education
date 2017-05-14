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
    background_task f;
    std::thread my_thread(f);
    my_thread.join();

    return 0;
}
