#include <iostream>

void f(int) {
    std::cout << "f(int)" << std::endl;
}

void f(bool) {
    std::cout << "f(bool)" << std::endl;
}

void f(void*) {
    std::cout << "f(void*)" << std::endl;
}


int main() {
    // calls f(int), not f(void*)
    f(0);

    // might not compiles
    // but typically calls f(int), never calls f(void*)
    // f(NULL);
    
    // call f(void*)
    f(nullptr);
}
