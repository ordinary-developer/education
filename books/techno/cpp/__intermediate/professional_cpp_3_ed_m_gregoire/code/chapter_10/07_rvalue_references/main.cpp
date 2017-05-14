#include <iostream>

void incr(int& value) {
    std::cout << "increment with lvalue reference" << std::endl;
    ++value;
}

void incr(int&& value) {
    std::cout << "increment with rvalue reference" << std::endl;
    ++value;
}

auto main() -> int {
    int a = 10, b = 20;
    incr(a);

    incr(a + b);
    incr(3);

    incr(std::move(b));

    // will be illegal
    // int& i = 2;
    // int c = 2, d = 3;
    // int& j = c + d;
    
    //correct code
    int&& i = 2;
    int c = 2, d = 3;
    int&& j = c + d;

    return 0;
}
