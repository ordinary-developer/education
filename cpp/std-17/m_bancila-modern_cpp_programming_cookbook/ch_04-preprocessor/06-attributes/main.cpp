#include <iostream>
namespace example_01 { // -> the "nodiscard" attribute
    
[[nodiscard]] int get_value1() { return 42; }    
    
enum class[[nodiscard]] ReturnCodes{ OK, NoData, Eror };
ReturnCodes get_value2() { return ReturnCodes::OK; }
    
struct [[nodiscard]] Item {};
Item get_value3() { return Item{}; }
    
void run() {
    get_value1(); // here a warning will be
    get_value2(); // here a warning will be
    get_value3(); // here a warning will be
    
    std::cout << "[ok]" << std::endl;
} 
} // example_01


#include <iostream>
namespace example_02 { // -> the "deprecated" attribute
    
[[deprecated("use func2() instead")]] void func() {}    
    
class [[deprecated]] foo {}; 
    
void run() {
    func(); // here a warning will be
    foo f{}; // here a warning will be
    
    std::cout << "[ok]" << std::endl;
}    
    
} // example_02


#include <iostream>
namespace example_03 { // -> the "maybed_unused" attribute
    
double func([[maybe_unused]] int a, double b) { return 2 * b; }    
void run() {
    func(1, 2);
    [[maybe_unused]] auto constexpr const i{42};

    std::cout << "[ok]" << std::endl;
}    
} // example_03


#include <iostream>
namespace example_04 { // -> the "fallthrough" attribute
    
void option1() {}
void option2() {}

void run() {
    int const alternative = 0;
    switch (alternative) {
        case 1:
            option1();
            [[fallthrough]]; // this is intentional
        case 2:
            option2();
    }
    
    std::cout << "[ok]" << std::endl;
}    
} // example_04


#include <iostream>
int main() {
    std::cout << "example_01 =>" << std::endl; example_01::run(); std::cout << std::endl << std::endl; 
    std::cout << "example_02 =>" << std::endl; example_02::run(); std::cout << std::endl << std::endl; 
    std::cout << "example_03 =>" << std::endl; example_03::run(); std::cout << std::endl << std::endl; 
    
    return 0;
}
