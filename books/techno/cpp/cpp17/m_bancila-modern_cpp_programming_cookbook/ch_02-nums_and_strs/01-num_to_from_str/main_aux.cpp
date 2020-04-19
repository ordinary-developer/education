#ifdef NDEBUG
#undef NDEBUG
#endif

#include <limits>
#include <cmath>
namespace { // -> utility func
template <typename T>
bool approx_equal(T const val1, T const val2, T const epsilon = std::numeric_limits<T>::epsilon()) {
    return std::abs(val1 - val2) < epsilon;
}
} // anonymous namespace


#include <string>
#include <type_traits>
#include <iostream>
#include <cassert>
namespace example_01 { // -> example_01: converting to string
    
void run() {
    for (auto const& elem : { std::to_string(42), std::to_string(42l), std::to_string(42u) }) 
        assert((std::is_same_v<std::string const&, decltype(elem)>)
            and "42" == elem);
            
    for (auto const& elem : { std::to_wstring(42.0), std::to_wstring(42.0l) })
        assert((std::is_same_v<std::wstring const&, decltype(elem)>) 
            and L"42" == elem.substr(0, 2));
    
    std::cout << "[ok]";
}
} // example_01


#include <string>
#include <type_traits>
#include <iostream>
#include <cassert>
namespace example_02 { // -> example_02: converting from string to int

void run() {
    auto const list = { std::stoi("42"), std::stoi("101010", nullptr, 2),
        std::stoi("052", nullptr, 8), std::stoi("0x2a", nullptr, 16) };
    for (auto const& elem : list)
        assert((std::is_same_v<int const&, decltype(elem)>)
            and 42 == elem);
        
    std::cout << "[ok]";
}
    
} // example_02


#include <string>
#include <type_traits>
#include <iostream>
#include <cassert>
namespace example_03 { // -> example_03: converting from string to double

void run() {
    for (auto const& elem : { std::stod("123.45"), std::stod("1.2345e+2") })
        assert((std::is_same_v<double const&, decltype(elem)>)
            and approx_equal(123.45, elem));
    
    auto const d = std::stod("0xF.6E6666p3");
    assert((std::is_same_v<double const, decltype(d)>) and approx_equal(123.45, d, 0.000001));
    assert(not approx_equal(123.45, d, 0.0000001));
    
    std::cout << "[ok]";    
 }

} // example_03


#include <string>
#include <type_traits>
#include <cassert>
namespace example_04 {
void run() {
    for (auto const& elem: { std::stoi("42"), std::stoi("   42"), std::stoi("    42fortytwo"), std::stoi("+42") })
        assert((std::is_same_v<int const&, decltype(elem)>) and 42 == elem);
        
    auto const neg_val = std::stoi("-42"); 
    assert((std::is_same_v<int const, decltype(neg_val)>) and -42 == neg_val);
        
    std::cout << "[ok]";
}    
    
} // example_04


#include <string>
#include <type_traits>
#include <cassert>
namespace example_05 {
    
void run() {
    auto const data = { std::stoi("052", nullptr, 8), std::stoi("052", nullptr, 0),
        std::stoi("0x2a", nullptr, 16), std::stoi("0x2a", nullptr, 0) };
    for (auto const& elem : data)
        assert((std::is_same_v<int const&, decltype(elem)>)and 42 == elem);
        
    auto const neg_val = std::stoi("-22", nullptr, 20);
    assert((std::is_same_v<int const, decltype(neg_val)>) and -42 == neg_val);
        
    std::cout << "[ok]";
}    

} // example_05


#include <string>
#include <type_traits>
#include <cstddef>
#include <cassert>
namespace example_06 {
    
void run() {
    auto pos = std::size_t{0};    
    
    auto const val1{ std::stoi("42", &pos) };
    assert((std::is_same_v<int const, decltype(val1)>) and 42 == val1 and 2 == pos);
    
    auto const val2{ std::stoi("-42", &pos) };
    assert((std::is_same_v<int const, decltype(val2)>) and -42 == val2 and 3 == pos);

    auto const val3{ std::stoi("  +42dec", &pos) };
    assert((std::is_same_v<int const, decltype(val3)>) and 42 == val3 and 5 == pos);
    
    std::cout << "[ok]";
}    
    
} // example_06


#include <string>
#include <stdexcept>
#include <iostream>
#include <cassert>
namespace example_07 {
void run() {
    try {
        std::stoi("");
        assert(false);
    }    
    catch (std::invalid_argument const& e) { assert(true); }
    
    try {
        std::stoi("1234567890");
        assert(true);
    }
    catch (std::out_of_range const& e) { assert(false); }
    
    try {
        std::stoi("12345678901");
        assert(false);
    }
    catch (std::out_of_range const& e) { assert(true); }
    
    std::cout << "[ok]";
}    
    
} // example_07


#include <string>
#include <type_traits>
#include <iostream>
#include <cassert>
namespace example_08 {
    
void run() {    
    for (auto const& elem : { std::stod("123.45"), std::stod("+123.45"), std::stod("   123.45"), std::stod("1.2345e+2")} )
        assert((std::is_same_v<double const&, decltype(elem)>) and approx_equal(123.45, elem));
        
    for (auto const& elem : { std::stod("-123.45"), std::stod("  -123.45abc") })
        assert(approx_equal(-123.45, elem));
        
    auto const d = std::stod("0xF.6E6666p3");
    assert(approx_equal(123.45, d, 0.000001));
    assert(not approx_equal(123.45, d, 0.0000001));
        
    std::cout << "[ok]";
}    
}


#include <string>
#include <limits>
#include <type_traits>
#include <iostream>
#include <cassert>
namespace example_09 {
    
void run() {
    for (auto const& elem : { std::stod("infinity"), std::stod("INF") })
        assert((std::is_same_v<double const&, decltype(elem)>) and std::isinf(elem) and std::numeric_limits<double>::infinity() == elem);
        
    for (auto const& elem : { std::stod("-infinity"), std::stod("-INF") })
        assert((std::is_same_v<double const&, decltype(elem)>) and std::isinf(elem) and -std::numeric_limits<double>::infinity() == elem);

    for (auto const& elem : { std::stod("NAN"), std::stod("-nanabc") })
        assert((std::is_same_v<double const&, decltype(elem)>) and std::isnan(elem));
        
    std::cout << "[ok]" << std::endl;
}    
} // example_09


#include <iostream>
int main() {
    std::cout << "example_01 => "; example_01::run(); std::cout << std::endl;
    std::cout << "example_02 => "; example_02::run(); std::cout << std::endl;
    std::cout << "example_03 => "; example_03::run(); std::cout << std::endl;
    std::cout << "example_04 => "; example_04::run(); std::cout << std::endl;
    std::cout << "example_05 => "; example_05::run(); std::cout << std::endl;
    std::cout << "example_06 => "; example_06::run(); std::cout << std::endl;
    std::cout << "example_07 => "; example_07::run(); std::cout << std::endl;
    std::cout << "example_08 => "; example_08::run(); std::cout << std::endl;
    std::cout << "example_09 => "; example_09::run(); std::cout << std::endl;
    
    return 0;
}
