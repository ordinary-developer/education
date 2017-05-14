#include <future>
#include <iostream>


void f() { 
    std::cout << "f calling" << std::endl;
}


int main() {
    auto fut1 = std::async(f);
    auto fut2 = std::async(std::launch::async | std::launch::deferred,
                           f);

    return 0;    
}
