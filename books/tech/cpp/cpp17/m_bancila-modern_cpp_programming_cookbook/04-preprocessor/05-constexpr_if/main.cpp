#include <type_traits>
#include <iostream>
namespace example_01 { // -> using 'constexpr if' instead of SFINAE

template <typename T>
constexpr auto compute(T const a, T const b) {
    if constexpr (std::is_integral<T>::value)
        return a * b;
    else
        return a + b;
}

void run() {
    auto constexpr const multVal = compute(1, 2);
    static_assert(2 == multVal);

    auto constexpr const plusVal = compute(1.0, 2.0);
    static_assert(plusVal < 3.001 and plusVal > 2.999);

    std::cout << "[ok]" << std::endl;
}
} // example_01


#include <iostream>
namespace example_02 { // -> using 'constexpr if' for simplyfing variadic tmpls

namespace binary {
    using byte8 = unsigned char;

    namespace binary_literals {
        namespace binary_literals_internals {

            template <typename CharT, char curDig, char... bits>
            constexpr CharT binary_eval() {
                if constexpr(sizeof...(bits) == 0)
                    return static_cast<CharT>(curDig - '0');
                else if constexpr('0' == curDig)
                    return binary_eval<CharT, bits...>();
                else if constexpr('1' == curDig)
                    return static_cast<CharT>(
                        (1 << sizeof...(bits)) | binary_eval<CharT, bits...>());
            }
        } // binary_literals_internals

        template<char... bits>
        constexpr byte8 operator""_b8() {
            static_assert(
                sizeof...(bits) <= 8,
                "binary literal b8 must be up to 8 digis long");
            
            return binary_literals_internals::binary_eval<byte8, bits...>();
        }
    } // binary_literals
} // binary

void run() {
    using namespace binary;
    using namespace binary_literals;
    auto constexpr const val = 00000001_b8;
    static_assert(1 == val);
    
    std::cout << "[ok]" << std::endl;
}
} // example_02


#include <iostream>
int main() {
    std::cout << "example_01 =>\n"; example_01::run(); std::cout << "\n";   
    std::cout << "example_02 =>\n"; example_02::run(); std::cout << "\n";   

    return 0;
}