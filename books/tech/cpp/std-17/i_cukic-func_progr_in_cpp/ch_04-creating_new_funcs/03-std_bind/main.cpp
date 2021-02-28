#include <algorithm>
#include <functional>
#include <vector>
#include <cassert>
namespace test {

void run() {
    {
    auto const& bound = std::bind(std::greater<double>{}, 6, 42);
    bool const is_6_greater_than_42 = bound();
    assert(not is_6_greater_than_42);
    }

    {
    using namespace std::placeholders;
    
    auto const& is_greater_than_42 = 
        std::bind(std::greater<double>{}, _1, 42);
    auto const& is_less_than_42 =
        std::bind(std::greater<double>{}, 42, _1);

    assert(is_less_than_42(6));
    assert(not is_greater_than_42(6));
    }

    {
        using namespace std::placeholders;

        std::vector<int> vals{ 5, 4, 3, 2, 1 };
        std::sort(std::begin(vals), std::end(vals), std::bind(std::greater<int>{}, _2, _1));
        assert((std::vector<int>{ 1, 2, 3, 4, 5 } == vals));
    }
}

} // test


#include <iostream>
int main() {
    std::cout << "test => [ok]";
    test::run();
    std::cout << std::endl;

    return 0;
}
