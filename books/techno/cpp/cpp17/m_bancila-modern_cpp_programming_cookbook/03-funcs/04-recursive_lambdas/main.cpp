// code for assert working
#ifdef NDEBUG
#undef NDEBUG
#endif


#include <functional>
#include <utility>
#include <iostream>
#include <cassert>
namespace example_01 { // -> a recursive lambda expresssion in the scope of a function 
void run() {
    // arrange
    std::function<int(int const)> const lambda = [&lambda = std::as_const(lambda)](int const n) {
        return n <= 2 ? 1 : lambda(n - 1) + lambda(n - 2);
    };
    
    // act - assert
    assert(55 == lambda(10));
    
    std::cout << "[ok]";
}    
} // example_01


#include <functional>
#include <utility>
#include <iostream>
#include <cassert>
namespace example_02 { // 
    
std::function<int(int const)> fib_create() {
    std::function<int(int const)> const func = [](int const n) {
        std::function<int(int const)> const lambda = [&lambda = std::as_const(lambda)](int n) {
            return n <= 2 ? 1 : lambda(n - 1) + lambda(n - 2);
        };
        
        return lambda(n);
    };
    
    return func;
}
    
void run() {
    assert(55 == fib_create()(10));
    
    std::cout << "[ok]";
}
} // example_02


#include <iostream>
int main() {
    std::cout << "example_01 => " << std::endl; example_01::run(); std::cout << std::endl;
    std::cout << "example_02 => " << std::endl; example_02::run(); std::cout << std::endl;

    return 0;
}
