#include <limits>
#include <iostream>
namespace example_01 { // numeric limits with min and max
template <typename T, typename I>
T minimum(I const start, I const end) {
    T minval = std::numeric_limits<T>::max();
    for (auto i{start}; i < end; ++i)
        if (*i < minval)
            minval = *i;
    return minval; 
}
    
void run() {
    constexpr int len = std::numeric_limits<char>::max() + 1;
    std::cout << "len = " << len << std::endl;
    
    constexpr int range[len] = {0};
    int const minval = minimum<int, const int* const>(&range[0], &range[0] + len);
    std::cout << "minval = " << minval << std::endl;
}    
} // example_01


#include <limits>
#include <bitset>
#include <typeinfo>
#include <iostream>
namespace example_02 { // std::numeric_limits and bitsets
void run() {
    auto constexpr n{42};
    std::cout << "n typeid = " << typeid(n).name() << std::endl;
    
    auto constexpr dgt_cnt{ std::numeric_limits<decltype(n)>::digits };
    std::cout << "dgt_cnt = " << dgt_cnt << std::endl;
    std::cout << "dgt_cnt typeid = " << typeid(dgt_cnt).name() << std::endl;
    
    std::bitset<std::numeric_limits<decltype(n)>::digits> constexpr bits{
        static_cast<unsigned long long>(n) };        
    std::cout << "bitset size = " << bits.size() << std::endl;
    for (std::size_t i{0}; i < bits.size(); ++i)
        std::cout << bits.test(i);
    std::cout << std::endl;
}    
} // example_02


#include <limits>
#include <typeinfo>
#include <iostream>
namespace example_03 {
    
template <typename T>
void print_type_properties() {
    std::cout << typeid(T).name() << ": " << std::endl 
        << "min = " << std::numeric_limits<T>::min() << std::endl
        << "max = " << std::numeric_limits<T>::max() << std::endl
        << "bits = " << std::numeric_limits<T>::digits << std::endl
        << "decdigits = " << std::numeric_limits<T>::digits10 << std::endl
        << "integral = " << std::numeric_limits<T>::is_integer << std::endl
        << "signed = " << std::numeric_limits<T>::is_signed << std::endl
        << "exact = " << std::numeric_limits<T>::is_exact << std::endl
        << "infinity = " << std::numeric_limits<T>::has_infinity << std::endl;
    
    std::cout << std::endl;
}

void run() {
    print_type_properties<unsigned short>();
    print_type_properties<int>();
    print_type_properties<double>();
}    
} // example_03


#include <iostream>
int main() {
    std::cout << "example_01 =>\r\n"; example_01::run(); std::cout << "\r\n";
    std::cout << "example_02 =>\r\n"; example_02::run(); std::cout << "\r\n";
    std::cout << "example_03 =>\r\n"; example_03::run(); std::cout << "\r\n";
    
    
    return 0;
}