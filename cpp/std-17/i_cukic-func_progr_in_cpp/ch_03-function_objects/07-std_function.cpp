
#include <functional>
#include <string>
#include <cassert>
#include <cmath>
namespace test {

void run() {
    std::function<float(float, float)> test_func;

    test_func = std::fmaxf;
    test_func = std::multiplies<float>{};
    test_func = std::multiplies<>{};

    const int x = 5;
    test_func = [x] (float a, float b) { return a * x + b; };
    test_func = [x] (auto a, auto b) { return a * x + b; };

    std::string str{ "a small pond" };
    std::function<bool(std::string)> f{};
    f = &std::string::empty;
    assert(not f(str));
}

} // test


#include <iostream>
int main() {
    std::cout << "test => [ok]" << std::endl; test::run();     

    return 0;
}
