#include <functional>
#include <cassert>
namespace test {

bool greater(double const first, double const second) { return first > second; }

auto greater_curried(double const first) {
    return [first](double const second) { return first > second; };
}

void run() {
    assert(not greater(2, 3));
    assert(not greater_curried(2)(3));
}

} // test_01


#include <iostream>
int main() {
    std::cout << "test => [ok]" << std::endl; test::run(); std::cout << std::endl;

    return 0;
}
