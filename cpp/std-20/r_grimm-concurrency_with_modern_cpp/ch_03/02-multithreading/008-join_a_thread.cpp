#include <iostream>
#include <thread>


int main() {
    std::cout << '\n';
    std::cout << std::boolalpha;

    std::thread t{[] { std::cout << "Joinable std::thread" << '\n'; } };

    std::cout << "t.joinable(): " << t.joinable() << '\n';
    
    t.join();

    std::cout << '\n';
}
