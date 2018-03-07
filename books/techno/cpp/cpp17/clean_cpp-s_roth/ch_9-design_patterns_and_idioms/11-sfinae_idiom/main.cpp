#include <iostream>
namespace example01 {
    
template <typename T>
void print(typename T::type) {
    std::cout << "calling print(typename::type)" << std::endl;
}

template <typename T>
void print(T) {
    std::cout << "calling print(T)" << std::endl;
}

struct AStruct {
    using type = int;    
};
    
void run() {
    std::cout << "# example01" << std::endl;
    
    print<AStruct>(42);
    print<int>(42);
    print(42);
    
    std::cout << std::endl;
}

} // example01


#include <iostream>
#include <type_traits>
namespace example02 {
    
template <typename T>
void print(T var, typename std::enable_if<std::is_enum<T>::value, T>::type* = nullptr) {
    std::cout << "calling overloaded print() for enumerations" << std::endl;
}
    
template <typename T>
void print(T var, typename std::enable_if<std::is_integral<T>::value,T>::type* = nullptr) {
    std::cout << "calling overloaded print() for integral types" << std::endl;
    
}
    
template <typename T>
void print(T var, typename std::enable_if<std::is_floating_point<T>::value>::type* = nullptr) {
    std::cout << "calling overlaoded print() for floating point types" << std::endl;
}
    
template <typename T>
void print(T const& var, typename std::enable_if<std::is_class<T>::value, T>::type* = nullptr) {
    std::cout << "calling overloaded print() for classes" << std::endl;
    
}
    
enum Enumeration1 { Literal1, Literal2 };
enum class Enumeration2 : int { Literal1, Literal2 };    
class Clazz{};    
    
void run() {
    std::cout << "# example02" << std::endl;
    
    Enumeration1 enumVar1{};
    print(enumVar1);
    
    Enumeration2 enumVar2{};
    print(enumVar2);
    
    print(42);
    
    print(42.0f) ;
    print(42.0);
    
    
    
    std::cout << std::endl;
}    
}

int main() {
    example01::run();
    example02::run();
    
    std::cout << "[OK] all done" << std::endl;
    
    return 0;
}