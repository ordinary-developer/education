#include <iostream>
#include <typeinfo>
namespace example_01 {
    
void run() {
    std::cout << "[auto.cpp]" << std::endl;
    
    auto a = 1;
    auto b = 1.0;
    auto c = a + b;
    auto d = { b, c };
    
    std::cout << "type of a: " << typeid(a).name() << std::endl;
    std::cout << "type of b: " << typeid(b).name() << std::endl;
    std::cout << "type of c: " << typeid(c).name() << std::endl;
    std::cout << "type of d: " << typeid(d).name() << std::endl;
}    
} // example_01


namespace example_02 {
    
int add1(int i, int j) {
    return i + j;    
}
    
auto add2(int i, int j) {
    return i + j;    
}
    
auto add3(int i, int j) -> int {
    return i + j;   
}
    
void run() {
    int a1 = add1(1, 2);
    std::cout << a1 << std::endl;
    
    int a2 = add2(1, 2);
    std::cout << a2 << std::endl;
    
    int a3 = add3(1, 2);
    std::cout << a3 << std::endl;
}
} // example_02

int main() {
    example_01::run();
    example_02::run();
    
    std::cout << "done" << std::endl;
}