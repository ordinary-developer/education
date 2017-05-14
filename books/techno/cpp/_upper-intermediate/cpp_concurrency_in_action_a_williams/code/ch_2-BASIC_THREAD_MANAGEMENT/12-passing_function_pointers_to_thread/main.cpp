#include <thread>
#include <iostream>

class X {
    public:
        void do_lengthy_work() 
        {
            std::cout << "I am doing a lengthy work" << std::endl;
        }
};

int main() {
    X my_x;
    std::thread t(&X::do_lengthy_work, &my_x);
    t.join();

    return 0;
}
