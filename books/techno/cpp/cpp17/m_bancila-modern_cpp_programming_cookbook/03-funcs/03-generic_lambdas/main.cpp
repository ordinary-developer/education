// code for assert working
#ifdef NDEBUG
#undef NDEBUG
#endif

#include <string>
#include <vector>
#include <numeric>
#include <iostream>
#include <cassert>
namespace example_01 { // -> base use of generic lambdas
void run() {
    using namespace std::string_literals;
    
    // arrange
    auto const nums = 
        std::vector<int>{ 0, 2, -3, 5, -1, 6, 8, -4, 9 };
    auto const txts =
        std::vector<std::string>{ "hello"s, " "s, "world"s, "!"s };
    
    auto const sum_lambda = [](auto const& first, auto const& second) { return first + second; };
    
    // act
    auto const sum = std::accumulate(
        std::cbegin(nums), std::cend(nums), 0, sum_lambda);
    
    auto const txt = std::accumulate(
        std::cbegin(txts), std::cend(txts), ""s, sum_lambda);
    
    // assert
    assert(22 == sum);
    assert("hello world!"s == txt);
    
    std::cout << "[ok]";
}    
} // example_01


#include <string>
#include <vector>
#include <numeric>
#include <iostream>
#include <cassert>
namespace example_02 { // -> the same as example_01 but without lambdas
    
struct lambda {
    template <typename T1, typename T2>
    auto operator()(T1 const& first, T2 const& second) const { return first + second; }
    
    lambda() = default;
    ~lambda() = default;
    
    lambda(lambda const&) = default;
    lambda(lambda&&) = default;
    lambda& operator=(lambda const&) = delete;
};
    
void run() {
    using namespace std::string_literals;
    
    // arrange
    auto const nums = 
        std::vector<int>{ 0, 2 -3, 5, -1, 6, 8, -4, 9 };
    auto const txts =
        std::vector<std::string>{ "hello"s, " "s, "world"s, "!"s };
    
    lambda const lambda_obj;
    
    // act
    auto const sum = std::accumulate(
        std::cbegin(nums), std::cend(nums), 0, lambda_obj);
    auto const txt = std::accumulate(
        std::cbegin(txts), std::cend(txts), ""s, lambda_obj);
    
    // assert
    assert(22 == sum);
    assert("hello world!"s == txt);
    
    std::cout << "[ok]";
}
} // example_02


#include <iostream>
int main() {
    std::cout << "example_01 => " << std::endl; example_01::run(); std::cout << std::endl;
    std::cout << "example_02 => " << std::endl; example_02::run(); std::cout << std::endl;
   
    return 0;
}
