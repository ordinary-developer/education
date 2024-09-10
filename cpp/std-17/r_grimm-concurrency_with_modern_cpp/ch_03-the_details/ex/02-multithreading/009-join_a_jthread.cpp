#include <iostream>
#include <thread>

int main() {
    std::cout << '\n';
    std::cout << std::boolalpha;
    
    std::jthread t{[] { std::cout << "Joinable std::thread" << '\n'; }};
    std::cout << "t.joinable(): " << t.joinable() << '\n';
    
    std::cout << '\n';
}
