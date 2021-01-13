// code for assert working
#ifdef NDEBUG
#undef NDEBUG
#endif

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
namespace example_01 { // -> base use of lambdas
void run() {
    // arrage
    auto const nums = std::vector<int>{ 0, 2, -3, 5, -1, 6, 8, -4, 9 };

    // act - assert
    {
    auto const positives = std::count_if(
        std::cbegin(nums), std::cend(nums), [](int const n) { return n > 0; });
    assert(5 == positives);
    }

    // act - assert
    {
    auto const is_positive = [](int const n) { return n > 0; };
    auto const positives = std::count_if(
        std::cbegin(nums), std::cend(nums), is_positive);
    assert(5 == positives);        
    }

    // act - assert
    {
    auto const positives = std::count_if(
        std::cbegin(nums), std::cend(nums), [](auto const n) { return n > 0; });
    assert(5 == positives);        
    }

    std::cout << "[ok]";
}
} // example_01


#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
namespace example_02 { // -> the same as example_01 but without lambdas
void run() {
    // arrange
    auto const nums = std::vector<int>{ 0, 2, -3, 5, -1, 6, 8, -4, 9 };

    // act
    struct lambda {
        bool operator()(int const n) const { return n > 0; };
    };
    auto const positives = std::count_if(
        std::cbegin(nums), std::cend(nums), lambda{});

    // assert
    assert(5 == positives);

    std::cout << "[ok]";
}
} // example_02


#include <vector>
#include <algorithm>
#include <iostream>
#include <cassert>
namespace example_03 { // -> lambdas with capturing
void run() {
    // arrange
    auto const nums = std::vector<int>{ 0, 2, -3, 5, -1, 6, 8, -4, 9 };    

    // act
    auto const start{5}, stop{10};
    auto const inrange = std::count_if(std::cbegin(nums), std::cend(nums),
        [start, stop](int const n) { return n >= start && n <= stop; });

    // assert
    assert(4 == inrange);

    std::cout << "[ok]";
}
} // example_03


#include <vector>
#include <algorithm>
#include <iostream>
#include <cassert>
namespace example_04 { // -> the same as example_03 but without lambdas
void run() {
    // arrange
    auto const start{5}, stop{10};
    auto const nums = std::vector<int>{ 0, 2, -3, 5, -1, 6, 8, -4, 9 };

    // act
    class lambda {
        public:
            explicit lambda(int const start, int const stop)
                : start_{start}, stop_{stop} {}
            ~lambda() = default;
            
            lambda(lambda const&) = default;
            lambda(lambda&&) = default;
            lambda& operator=(lambda const&) = delete;

            bool operator()(int const n) const { return n >= start_ and n <= stop_; }
        private:
            int const start_;
            int const stop_;
    };

    auto const inrange = std::count_if(std::cbegin(nums), std::cend(nums),
        lambda{ start, stop });

    // assert
    assert(4 == inrange);

    std::cout << "[ok]";
}
} // example_04


#include <iostream>
int main() {
    std::cout << "example_01 => " << std::endl; example_01::run(); std::cout << std::endl;
    std::cout << "example_02 => " << std::endl; example_02::run(); std::cout << std::endl;
    std::cout << "example_03 => " << std::endl; example_03::run(); std::cout << std::endl;
    std::cout << "example_04 => " << std::endl; example_04::run(); std::cout << std::endl;

    return 0;
}
