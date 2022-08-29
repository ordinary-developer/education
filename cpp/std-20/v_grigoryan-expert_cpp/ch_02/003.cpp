#include <iostream>


void foo() {
    std::cout << "Risky foo" << std::endl;
}

// a compiler error
//foo();

int main(){
    std::cout << "Calling main" << std::endl;
    return 0;
}
