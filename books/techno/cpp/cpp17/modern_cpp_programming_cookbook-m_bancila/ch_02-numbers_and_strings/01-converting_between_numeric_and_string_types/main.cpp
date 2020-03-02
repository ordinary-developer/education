#include <string>
#include <iostream>
namespace example_01 { // int, float -> string
void run() {
    auto si = std::to_string(42);
    auto sl = std::to_string(42l);
    auto su = std::to_string(42u);
    auto sd = std::to_wstring(42.0);
    auto sld = std::to_wstring(42.0l);
    
    std::cout << si << std::endl;
    std::cout << sl << std::endl;
    std::cout << su << std::endl;
    std::wcout << sd << std::endl;
    std::wcout << sld << std::endl;
}
} // example_01


#include <string>
#include <iostream>
namespace example_02 { // string -> int
void run() {
    auto i1 = std::stoi("42");
    auto i2 = std::stoi("101010", nullptr, 2);
    auto i3 = std::stoi("052", nullptr, 8);
    auto i4 = std::stoi("0x2A", nullptr, 16);
    
    std::cout << i1 << std::endl;
    std::cout << i2 << std::endl;
    std::cout << i3 << std::endl;
    std::cout << i4 << std::endl;
}
} // example_02


#include <string>
#include <iostream>
namespace example_03 { // string -> float
void run() {
    auto d1 = std::stod("123.45");
    auto d2 = std::stod("1.2345e+2");
    auto d3 = std::stod("0xF.6E6666p3");
    
    std::cout << d1 << std::endl;
    std::cout << d2 << std::endl;
    std::cout << d3 << std::endl;
}
} // example_03


#include <string>
#include <iostream>
namespace example_04 { // only the "integer" type itself -> string
void run() {
    auto i1 = std::stoi("42");
    auto i2 = std::stoi("      42");
    auto i3 = std::stoi("      42fortytwo");
    auto i4 = std::stoi("+42");
    auto i5 = std::stoi("-42");
    
    std::cout << i1 << std::endl;
    std::cout << i2 << std::endl;
    std::cout << i3 << std::endl;
    std::cout << i4 << std::endl;
    std::cout << i5 << std::endl;
}
} // example_04


#include <string>
#include <iostream>
namespace example_05 { // more examples of int -> string convertion
void run() {
    auto i6 = std::stoi("052", nullptr, 8);
    auto i7 = std::stoi("052", nullptr, 0);
    auto i8 = std::stoi("0x2A", nullptr, 16);
    auto i9 = std::stoi("0x2A", nullptr, 0);
    auto i10 = std::stoi("101010", nullptr, 2);
    auto i11 = std::stoi("22", nullptr, 20);
    auto i12 = std::stoi("-22", nullptr, 20);
    std::cout << i6 << std::endl;
    std::cout << i7 << std::endl;
    std::cout << i8 << std::endl;
    std::cout << i9 << std::endl;
    std::cout << i10 << std::endl;
    std::cout << i11 << std::endl;
    std::cout << i12 << std::endl;
    
    auto pos = std::size_t{ 0 };
    
    auto i13 = std::stoi("42", &pos);
    std::cout << i13 << " " << pos << std::endl;
    
    auto i14 = std::stoi("-42", &pos);
    std::cout << i14 << " " << pos << std::endl;
    
    auto i15 = std::stoi("  +42dec", &pos);
    std::cout << i15 << " " << pos << std::endl;
}
} // example_05


#include <string>
#include <exception>
#include <iostream>
namespace example_06 { // exceptions
void run() {
    // std::invalid_argument
    {
        try {
            auto i16 = std::stoi("");
            (void)i16;
        }
        catch (std::exception const& e) {
            std::cout << e.what() << std::endl;
        }
    }
    
    // std::out_of_range
    {
        try {
            auto i17 = std::stoll("12345678901234"); // OK
            (void)i17;
            
            auto i18 = std::stoi("12345678901234"); // std::out_of_range
            (void)i18;
        }
        catch (std::exception const& e) {
            std::cout << e.what() << std::endl;
        }
    }
}
} // example_06


#include <string>
#include <iostream>
namespace example_07 { // more examples for double to string
void run() {
    auto d1 = std::stod("123.45");
    auto d2 = std::stod("+123.45");
    auto d3 = std::stod("-123.45");
    auto d4 = std::stod("  123.45");
    auto d5 = std::stod("  -123.45abc");
    auto d6 = std::stod("1.2345e+2");
    auto d7 = std::stod("0xF.6E6666p3");
    
    auto d8 = std::stod("INF");
    auto d9 = std::stod("-infinity");
    auto d10 = std::stod("NAN");
    auto d11 = std::stod("-nanabc");
    
    std::cout << d1 << std::endl;
    std::cout << d2 << std::endl;
    std::cout << d3 << std::endl;
    std::cout << d4 << std::endl;
    std::cout << d5 << std::endl;
    std::cout << d6 << std::endl;
    std::cout << d7 << std::endl;
    std::cout << d8 << std::endl;
    std::cout << d9 << std::endl;
    std::cout << d10 << std::endl;
    std::cout << d11 << std::endl;
}
} // example_07


#include <iostream>
int main() {
    std::cout << "example_01 =>\r\n"; example_01::run(); std::cout << "\r\n";
    std::cout << "example_02 =>\r\n"; example_02::run(); std::cout << "\r\n";
    std::cout << "example_03 =>\r\n"; example_03::run(); std::cout << "\r\n";
    std::cout << "example_04 =>\r\n"; example_04::run(); std::cout << "\r\n";
    std::cout << "example_05 =>\r\n"; example_05::run(); std::cout << "\r\n";
    std::cout << "example_06 =>\r\n"; example_06::run(); std::cout << "\r\n";
    std::cout << "example_07 =>\r\n"; example_07::run(); std::cout << "\r\n";
    
    
    return 0;
}