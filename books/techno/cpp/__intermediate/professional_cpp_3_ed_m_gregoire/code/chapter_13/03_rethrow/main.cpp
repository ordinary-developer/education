#include <iostream>
#include <stdexcept>

void g() { 
    throw std::invalid_argument("Some exception");
}

void f() {
    try {
        g();
    }
    catch (const std::invalid_argument& e) {
        std::cout << "caught in f: " << e.what() << std::endl;
        throw;
    }
}

auto main() -> int {
    try {
        f();
    }
    catch (const std::invalid_argument& e) {
        std::cout << "caught in main: " << e.what() << std::endl;
    }

    return 0;
}
