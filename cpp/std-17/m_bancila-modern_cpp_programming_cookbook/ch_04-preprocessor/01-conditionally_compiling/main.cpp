namespace example_01 { // -> avoiding duplicated macro definitions
    
#if !defined(_UNIQUE_NAME_)
#define _UNIQUE_NAME_
class foo {};
#endif
void run() {
    foo{};
}
} // example_01


#include <iostream>
namespace example_02 { // -> using various compilers
void run() {
#if defined _MSC_VER
    std::cout << "visual c++" << std::endl;
#elif defined __clang__
    std::cout << "CLang" << std::endl;
#elif defined __GNUG__
    std::cout << "GCC" << std::endl;
#else
    std::cout << "unknown compiler" << std::endl;
#endif
}    
} // example_02


#include <iostream>
namespace example_03 { // code for multiple architecture
void run() {
#if defined __MSC_VER
    std::cout << 
    #if defined _M_X64
        "AMD64"
    #elif defined _M_IX86
        "INTEL x86"
    #elif defined _M_ARM
        "ARM"
    #else
        "unknown"
    #endif    
    << std::endl;
#elif defined __clang__ || __GNUG__
    std::cout <<
    #if defined __amd64__
        "AMD64"
    #elif defined __i386__
        "INTEL x86"
    #elif defined __arm__
        "ARM"
    #else
        "unknown"
    #endif
    << std::endl;
#else
    #error Unknown compiler
#endif
}    
} // example_03


#include <iostream>
namespace example_04 { // -> for debug and release
void run() {
    std::cout << 
    #ifdef _DEBUG
        "debug"
    #else
        "release"
    #endif
    << std::endl;
}    
} // example_04


#include <iostream>
int main() {
    std::cout << "example_01 => " << std::endl; example_01::run(); std::cout << std::endl;
    std::cout << "example_02 => " << std::endl; example_02::run(); std::cout << std::endl;
    std::cout << "example_03 => " << std::endl; example_03::run(); std::cout << std::endl;
    std::cout << "example_04 => " << std::endl; example_04::run(); std::cout << std::endl;
    
    return 0;
}