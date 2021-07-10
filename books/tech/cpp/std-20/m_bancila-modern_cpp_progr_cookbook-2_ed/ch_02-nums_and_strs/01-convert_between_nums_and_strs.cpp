#include <string>
#include <cassert>
namespace example_01 { // the "how to do it" section

void run() {
    {
        auto si = std::to_string(42);
        assert(("42" == si));

        auto sl = std::to_string(42L);
        assert(("42" == sl));

        auto su = std::to_string(42u);
        assert(("42" == su));

        auto sd = std::to_wstring(42.0);
        assert((L"42.000000" == sd));

        auto sld = std::to_wstring(42.0L);
        assert((    L"42.000000" == sld));
    }

    {
        auto i1 = std::stoi("42");
        assert((42 == i1));

        auto i2 = std::stoi("101010", nullptr, 2);
        assert((42 == i2));
        
        auto i3 = std::stoi("052", nullptr, 8);
        assert((42 == i3));

        auto i4 = std::stoi("0x2a", nullptr, 16);
        assert((42 == i4));
    }

    {
        auto const cmpFn = [](const double lhs, const double rhs) {
            return std::abs(lhs - rhs) <= 0.001;
        };

        auto d1 = std::stod("123.45");
        assert((cmpFn(123.45, d1)));

        auto d2 = std::stod("1.2345e+2");
        assert((cmpFn(123.45, d2)));

        auto d3 = std::stod("0xf.6e6666p3");
        assert((cmpFn(123.45, d3)));
    }
}
} // example_01


#include <stdexcept>
#include <string>
#include <cassert>
#include <cmath>
namespace example_02 { // -> the "how it works" section

void run() {
    {
        auto i1 = std::stoi("42");
        assert((42 == i1));

        auto i2 = std::stoi("   42");
        assert((42 == i2));

        auto i3 = std::stoi("   42fortytwo");
        assert((42 == i3));

        auto i4 = std::stoi("+42");
        assert((42 == i4));

        auto i5 = std::stoi("-42");
        assert((-42 == i5));

        auto i6 = std::stoi("052", nullptr, 8);
        assert((42 == i6));

        auto i7 = std::stoi("052", nullptr, 0);
        assert((42 == i7));

        auto i8 = std::stoi("0x2a", nullptr, 16);
        assert((42 == i8));

        auto i9 = std::stoi("0x2a", nullptr, 0);
        assert((42 == i9));

        auto i10 = std::stoi("101010", nullptr, 2);
        assert((42 == i10));

        auto i11 = std::stoi("22", nullptr, 20);
        assert((42 == i11));

        auto i12 = std::stoi("-22", nullptr, 20);
        assert((-42 == i12));

        auto pos = std::size_t{0};

        auto i13 = std::stoi("42", &pos);
        assert((42 == i13 and 2 == pos));

        auto i14 = std::stoi("-42", &pos);
        assert((-42 == i14 and 3 == pos));

        auto i15 = std::stoi("  +42dec", &pos);
        assert((42 == i15 and 5 == pos));

        try {
            auto i16 = std::stoi("");
            assert((false));
        } 
        catch (std::invalid_argument const &) { assert((true)); }
        catch (std::exception const &)  { assert((false)); }

        try {
            auto i17 = std::stoll("12345678901234");
            assert((true));
            assert((12345678901234 == i17));
        } catch (std::exception const &) { assert((false)); }

        try {
            auto i18 = std::stoi("12345678901234");
            assert((false));
        } 
        catch (std::out_of_range const &) { assert((true)); }
        catch (std::exception const &) { assert((false)); }
    }

    {
        auto const cmpFn = [](const double lhs, const double rhs) {
            return std::abs(lhs - rhs) <= 0.001;
        };

        auto d1 = std::stod("123.45");
        assert((cmpFn(123.45, d1)));

        auto d2 = std::stod("+123.45");
        assert((cmpFn(123.45, d2)));

        auto d3 = std::stod("-123.45");
        assert((cmpFn(-123.45, d3)));

        auto d4 = std::stod("  123.45");
        assert((cmpFn(123.45, d4)));

        auto d5 = std::stod("  -123.45abc");
        assert((cmpFn(-123.45, d5)));

        auto d6 = std::stod("1.2345e+2");
        assert((cmpFn(123.45, d6)));

        auto d7 = std::stod("0xf.6e6666p3");
        assert((cmpFn(123.45, d7)));

        auto d8 = std::stod("INF");
        assert((std::isinf(d8)));

        auto d9 = std::stod("-infinity");
        assert((std::isinf(d9)));

        auto d10 = std::stod("NAN");
        assert((std::isnan(d10)));

        auto d11 = std::stod("-nanabc");
        assert((std::isnan(d11)));
    }
}
} // example_02


#include <iostream>
int main() {
    std::cout << "example 01 => [ok]"; example_01::run(); std::cout << std::endl << std::endl;
    std::cout << "example 02 => [ok]"; example_02::run(); std::cout << std::endl << std::endl;

    return 0;
}
