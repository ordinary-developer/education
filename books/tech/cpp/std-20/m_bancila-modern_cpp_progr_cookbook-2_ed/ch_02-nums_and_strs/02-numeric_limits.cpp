#include <bitset>
#include <initializer_list>
#include <limits>
#include <cassert>
namespace example_01 {  // -> the "how to do it" section
    
template <typename T, typename Iter>
T minimum(Iter const start, Iter const end) {
    T minval = std::numeric_limits<T>::max();
    for (auto i = start; i < end; ++i)
        if (*i < minval)
            minval = *i;
            
    return minval;
}

int get_value() { return 0; }


void run() {
    {
        auto const data = { 3, 2, 1 };
        auto const minVal = minimum<int>(std::begin(data), std::end(data));
        assert((1 == minVal));
        
        [[maybe_unused]] int range[std::numeric_limits<char>::max() + 1] = { 0 };
        switch (get_value()) {
            case std::numeric_limits<int>::min():
            break;
        }
    }
    
    {
        auto n = 42;
        std::bitset<std::numeric_limits<decltype(n)>::digits> bits{
                static_cast<unsigned long long>(n) };
    }
}
    
} // example_01


#include <iostream>
#include <limits>
namespace example_02 { // the "how it works" section

template <typename T>
void print_type_properties() {
    std::cout 
        << "min       = " << std::numeric_limits<T>::min()        << '\n'
        << "max       = " << std::numeric_limits<T>::max()        << '\n'
        << "bits      = " << std::numeric_limits<T>::digits       << '\n'
        << "decdigits = " << std::numeric_limits<T>::digits10     << '\n'
        << "integral  = " << std::numeric_limits<T>::is_integer   << '\n'
        << "signed    = " << std::numeric_limits<T>::is_signed    << '\n'
        << "exact     = " << std::numeric_limits<T>::is_exact     << '\n'
        << "infinity  = " << std::numeric_limits<T>::has_infinity << '\n';
}
    
void run() {
    std::cout << "unsigned short -> " << std::endl;
    print_type_properties<unsigned short>();        
    std::cout << std::endl;
    
    std::cout << "double -> " << std::endl;
    print_type_properties<double>();        
    std::cout << std::endl;
    
    std::cout << "int -> " << std::endl;
    print_type_properties<int>();        
    std::cout << std::endl;
}

} // example_02


#include <iostream>
int main() {
    std::cout << "example 01 => [ok]" << std::endl;
    example_01::run();
    std::cout << std::endl;
    
    std::cout << "example 02 => [ok]" << std::endl;
    example_02::run();
    std::cout << std::endl;
    
	return 0;
}
