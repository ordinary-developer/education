#include <algorithm>
#include <functional>
#include <vector>
#include <cassert>
namespace test {

void run() {
    auto const& bound = [] { return std::greater<double>{}(6, 42); };
    bool const is_6_greater_than_42 = bound();
    assert(not is_6_greater_than_42);

    auto const& is_greater_than_42 = [](double const value) {
        return std::greater<double>{}(value, 42);
    };
    assert(not is_greater_than_42(6));

    auto const& is_less_than_42 = [](double const value) {
        return std::greater<double>{}(42, value);
    };
    assert(is_less_than_42(6));

    std::vector<int> nums{ 5, 5, 3, 2, 1 };
    std::sort(std::begin(nums), std::end(nums), [](double const value1, double const value2) {
        return std::greater<double>{}(value2, value1);
    });
    assert((std::vector<int>{ 1, 2, 3, 4, 5 } == nums));
}

} // test_01


#include <iostream>
int main() {
    std::cout << "test => [ok]" << std::endl; test::run(); std::cout << std::endl;

    return 0;
}
