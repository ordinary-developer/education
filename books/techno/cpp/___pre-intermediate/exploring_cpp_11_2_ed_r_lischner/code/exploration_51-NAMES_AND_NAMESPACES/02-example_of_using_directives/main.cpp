#include <iostream>

void print(int i) {
    std::cout << "int: " << i << '\n';
}

namespace labeled {
    void print(double d) {
        std::cout << "double: " << d << '\n';
    }
}

namespace simple {
    void print(int i) {
        std::cout << i << '\n';
    }

    void print(double d) {
        std::cout << d << '\n';
    }
}

void test_simple() {
    using namespace simple;
    // print(42);      // error here
    simple::print(42); // no error
    print(3.14159);    // simple::print(double)
}

void test_labeled() {
    using namespace labeled;
    print(42);      // ::print(int)
    print(3.14159); // labeled::print(double)
}


int main() {
    test_simple();
    test_labeled();

    return 0;
}
