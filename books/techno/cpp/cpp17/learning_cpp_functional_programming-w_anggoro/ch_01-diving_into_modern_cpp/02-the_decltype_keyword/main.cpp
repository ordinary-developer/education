namespace example_01 {

int var = 0;
    
int func1() { return 0; } 
const int& func2() { return var; }    
int i;
    
struct X { double d; };
const X* x = new X();
    
void run() {
    decltype(func1()) f1;
    decltype(func2()) f2 = 0;
    decltype(i) i1;
    decltype(x->d) d1;
    decltype((x->d)) d2 = 0;
}
} // example_01

#include <iostream>
namespace example_02 {
    
template <typename I, typename J, typename K>
K add(I i, J j) {
    return i + j;
}    
    
void run() {
    auto d = add<int, double, double>(2, 2.5);
    std::cout << d << std::endl;
}    
} // example_02

#include <iostream>
namespace example_03 {
    
template <typename I, typename J>
auto add(I i, J j) -> decltype(i + j) {
    return i + j;
}    
    
void run() {
    auto d = add<int, double>(2, 2.5);
    std::cout << d << std::endl;
}    
}    

int main() {
    example_01::run();
    example_02::run();
    example_03::run();
    
    return 0;
}