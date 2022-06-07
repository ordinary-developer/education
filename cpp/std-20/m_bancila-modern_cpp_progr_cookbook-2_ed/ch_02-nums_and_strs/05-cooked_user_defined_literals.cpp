#include <array>
#include <cstddef>
namespace example_01 { // -> the "how to do it" section

namespace compunits {
    constexpr std::size_t operator "" _KB(unsigned long long const size) {
        return static_cast<std::size_t>(size * 1024);
    }
}
    
void run() {
    using namespace compunits;
    
    auto size{ 4_KB };
    
    using byte = unsigned char;
    auto buffer = std::array<byte, 1_KB>{};
}

} // example_01



namespace example_02 { // -> the "how it works..." section

namespace units {
    enum class unit { kilogram, liter, meter, piece };
    
    template <unit U>
    class quantity {
        double const amount;
    public:
        constexpr explicit quantity(double const a) : amount{a} {}
        
        explicit operator double() const { return amount; }
    };
    
    template <unit U>
    constexpr quantity<U> operator+(quantity<U> const& q1, quantity<U> const& q2) {
        return quantity<U>{ static_cast<double>(q1) + static_cast<double>(q2) };
    }
    
    template <unit U>
    constexpr quantity<U> operator-(quantity<U> const& q1, quantity<U> const& q2) {
        return quantity<U>{ static_cast<double>(q1) - static_cast<double>(q2) };
    }
    
    namespace unit_literals {
        constexpr quantity<unit::kilogram> operator "" _kg(long double const amount) {
            return quantity<unit::kilogram>{ static_cast<double>(amount) };
        }
        
        constexpr quantity<unit::kilogram> operator "" _kg(unsigned long long const amount) {
            return quantity<unit::kilogram>{ static_cast<double>(amount) };
        }
        
        constexpr quantity<unit::liter> operator "" _l(long double const amount) {
            return quantity<unit::liter>{ static_cast<double>(amount) };
        }
        
        constexpr quantity<unit::meter> operator "" _m(long double const amount) {
            return quantity<unit::meter>{ static_cast<double>(amount) };
        }
        
        constexpr quantity<unit::piece> operator "" _pcs(unsigned long long const amount) {
            return quantity<unit::piece>{ static_cast<double>(amount) };
        }
    }
}
    
void run() {
    using namespace units;
    using namespace unit_literals;
    
    auto q1{ 1_kg };
    auto q2{ 4.5_kg };
    auto q3{ q1 + q2 };
    auto q4{ q2 - q1 };
    
    // error, cannot add meters and pieces
    // auto q5{ 1.0_m + 1_pcs };
    
    // error, cannot have an integer number of liters
    // auto q6{ 1_l };
    
    // error, can only have an integer number of pieces
    // auto q7{ 2.0_pcs };
}
} // example_02


#include <string>
#include <chrono>
#include <complex>
namespace example_03 { // -> the "there's more..." section

void run() {    
    using namespace std::string_literals;
    auto s1{  "text"s }; // std::string
    auto s2{ L"text"s }; // std::wstring
    auto s3{ u"text"s }; // std::u16string
    auto s4{ U"text"s }; // std::u32string
    
    using namespace std::string_view_literals;
    auto s5{ "text"sv }; // std::string_view
    
    using namespace std::chrono_literals;
    auto timer{ 2h + 42min + 15s };
    
    auto year{ 2020y };
    auto day{ 15d };
    
    using namespace std::complex_literals;
    auto c{ 12.0 + 4.5i };
    
}    
} // example_03


#include <iostream>
int main() {
    std::cout << "example_01 => [ok]" << std::endl;
    example_01::run();
    std::cout << std::endl << std::endl;
    
    std::cout << "example_02 => [ok]" << std::endl;
    example_02::run();
    std::cout << std::endl << std::endl;
    
    std::cout << "example_03 => [ok]" << std::endl;
    example_03::run();
    std::cout << std::endl << std::endl;
    
	return 0;
}
