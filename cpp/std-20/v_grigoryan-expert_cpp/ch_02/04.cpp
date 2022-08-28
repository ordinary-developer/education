#include <iostream>


struct BeforeMain {
    BeforeMain() {
        std::cout << "Constructing BeforeMain" << std::endl;
    }

    void test() {
        std::cout << "test function" << std::endl;
    }
};

BeforeMain b{};

// a compiler error
//b.test();

int main(){
    std::cout << "Calling main()" << std::endl;
    return 0;
}
