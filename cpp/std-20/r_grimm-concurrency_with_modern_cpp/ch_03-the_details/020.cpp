#include <iostream>
#include <thread>


void helloFunc() {
    std::cout << "Hello from a func" << std::endl;
}

class HelloFuncObj {
    public:
        void operator () () const  {
            std::cout << "Hello from a func obj" << std::endl;
        }
};


int main() {
    std::cout << std::endl;

    std::thread t1{helloFunc};
    
    HelloFuncObj helloFuncObj{};
    std::thread t2{helloFuncObj};

    std::thread t3([]{ std::cout << "Hello from a lambda" << std::endl; });

    if (t1.joinable())
        t1.join();

    if (t2.joinable())
        t2.join();

    if (t3.joinable())
        t3.join();

    std::cout << std::endl;
}
