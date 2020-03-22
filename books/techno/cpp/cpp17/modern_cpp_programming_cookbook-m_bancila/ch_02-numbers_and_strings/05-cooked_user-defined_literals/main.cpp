#include <cstddef>
#include <array>
#include <iostream>
namespace example_01 {
    
namespace compunits {
    constexpr size_t operator "" _KB(unsigned long long const size) {
        return static_cast<std::size_t>(size * 1024);
    }
}
    
void run() {
    using namespace compunits;
    
    constexpr auto size{ 4_KB };
    std::cout << size << std::endl;
    
    using byte = unsigned char;
    constexpr auto buffer = std::array<byte, 1_KB>{};
    for (auto const& elem : buffer) 
        std::cout << static_cast<int>(elem) << " ";
    std::cout << std::endl;
    
}
} // example_01


#include <iostream>
namespace example_02 {
enum class unit { kilogram, liter, meter, piece, };

template <unit U>
class quantity {
    double const amount_;
    public:
        constexpr explicit quantity(double const amount)
            : amount_{amount} {}
        explicit operator double() const { return amount_; }
};
    
template <unit U>
constexpr quantity<U> operator+(
    quantity<U> const &q1, quantity<U> const &q2)
{
    return quantity<U>(
        static_cast<double>(q1) + static_cast<double>(q2));
}
    
template <unit U>
constexpr quantity<U> operator-(
    quantity<U> const &q1, quantity<U> const &q2)
{
    return quantity<U>(
        static_cast<double>(q1) - static_cast<double>(q2));
}
    
namespace unit_literals {
    constexpr quantity<unit::kilogram> operator "" _kg (
        long double const amount)
    {
        return quantity<unit::kilogram>
            { static_cast<double>(amount) };
    }
    
    constexpr quantity<unit::kilogram> operator "" _kg (
        unsigned long long const amount)
    {
        return quantity<unit::kilogram>
            { static_cast<double>(amount) };
    }
    
    constexpr quantity<unit::liter> operator "" _l(
        long double const amount)
    {
        return quantity<unit::liter>
            { static_cast<double>(amount) };
    }
    
    constexpr quantity<unit::meter> operator "" _m(
        long double const amount)
    {
        return quantity<unit::meter>
            { static_cast<double>(amount) };
    }
    
    constexpr quantity<unit::piece> operator "" _pcs(
        unsigned long long const amount)
    {
        return quantity<unit::piece>
            { static_cast<double>(amount) };
    }
}
    
void run() {
    using namespace unit_literals;
    
    auto q_kg_1{ 15._kg };
    auto q_kg_2{ 17_kg };
    auto q_kg_3{ q_kg_1 + q_kg_2 };
    auto q_kg_4{ q_kg_1 - q_kg_2 };
    std::cout << static_cast<double>(q_kg_1) << std::endl;
    std::cout << static_cast<double>(q_kg_2) << std::endl;
    std::cout << static_cast<double>(q_kg_3) << std::endl;
    std::cout << static_cast<double>(q_kg_4) << std::endl;
    
    auto q_l_1{ 15._l };
    auto q_l_2{ 17._l };
    auto q_l_3{ q_l_1 + q_l_2 };
    auto q_l_4{ q_l_1 - q_l_2 };
    std::cout << static_cast<double>(q_l_1) << std::endl;
    std::cout << static_cast<double>(q_l_2) << std::endl;
    std::cout << static_cast<double>(q_l_3) << std::endl;
    std::cout << static_cast<double>(q_l_4) << std::endl;
    
    auto q_m_1{ 15._m };
    auto q_m_2{ 17._m };
    auto q_m_3{ q_m_1 + q_m_2 };
    auto q_m_4{ q_m_1 - q_m_2 };
    std::cout << static_cast<double>(q_m_1) << std::endl;
    std::cout << static_cast<double>(q_m_2) << std::endl;
    std::cout << static_cast<double>(q_m_3) << std::endl;
    std::cout << static_cast<double>(q_m_4) << std::endl;
    
    auto q_p_1{ 15_pcs };
    auto q_p_2{ 17_pcs };
    auto q_p_3{ q_p_1 + q_p_2 };
    auto q_p_4{ q_p_1 - q_p_2 };
    std::cout << static_cast<double>(q_p_1) << std::endl;
    std::cout << static_cast<double>(q_p_2) << std::endl;
    std::cout << static_cast<double>(q_p_3) << std::endl;
    std::cout << static_cast<double>(q_p_4) << std::endl;
}
} // example_02


#include <string>
#include <typeinfo>
#include <iostream>
namespace example_03 {
void run() {
    using namespace std::string_literals;
    
    auto s1{ "text"s };
    auto s2{ L"text"s };
    auto s3{ u"text"s };
    auto s4{ U"text"s };
    
    std::cout << typeid(s1).name() << std::endl;
    std::cout << typeid(s2).name() << std::endl;
    std::cout << typeid(s3).name() << std::endl;
    std::cout << typeid(s4).name() << std::endl;
}
} // example_03


#include <chrono>
#include <typeinfo>
#include <iostream>
namespace example_04 {
void run() {
    using namespace std::literals::chrono_literals;
    
    constexpr auto timer{ 2h + 42min + 15s };
    std::cout << typeid(timer).name() << std::endl;
}
} // example_04


#include <complex>
#include <typeinfo>
#include <iostream>
namespace example_05 {
void run() {
    using namespace std::literals::complex_literals;
    
    auto c{ 12.0 + 4.5i };
    std::cout << typeid(c).name() << std::endl;
}
} // example_05



int main() {
    std::cout << "example 01 => " << std::endl; example_01::run(); std::cout << std::endl;
    std::cout << "example 02 => " << std::endl; example_02::run(); std::cout << std::endl;
    std::cout << "example 03 => " << std::endl; example_03::run(); std::cout << std::endl;
    std::cout << "example 04 => " << std::endl; example_04::run(); std::cout << std::endl;
    std::cout << "example 05 => " << std::endl; example_05::run(); std::cout << std::endl;
    
    return 0;
}