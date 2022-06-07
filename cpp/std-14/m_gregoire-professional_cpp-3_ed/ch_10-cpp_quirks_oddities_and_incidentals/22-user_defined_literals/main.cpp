#include <complex>
#include <string>

std::complex<double> operator"" _i(long double d) {
    return std::complex<double>(0, d);
}

std::string operator"" _s(const char* str, size_t len) {
    return std::string(str, len);
}

auto main() -> int {
    std::complex<double> c1 = 9.634_i;
    auto c2 = 1.23_i;

    std::string str1 = "hello world"_s;
    auto str2 = "Hello World"_s;

    auto str3 = "Hello World!";

    return 0;
}
