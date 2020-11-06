#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
namespace example_01 { // -> initialize a container with std::fill
void run() {
    std::vector<int> v(5);
    std::fill(std::begin(v), std::end(v), 42);

    assert((std::vector<int>{ 42, 42, 42, 42, 42 } == v));
}
} // example_01


#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
namespace example_02 { // -> initialize a container with std::fill_n
void run() {
    std::vector<int> v(10);
    std::fill_n(std::begin(v), 5, 42);

    assert((std::vector<int>{ 42, 42, 42, 42, 42, 0, 0, 0, 0, 0} == v));
}
} // example_02


#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <cassert>
namespace example_03 { // -> initialize a container with std::generate
void run() {
    std::random_device rd{};
    std::mt19937 mt{ rd() };
    std::uniform_int_distribution<> ud{ 1, 10 };
    std::vector<int> v(5);
    std::generate(std::begin(v), std::end(v), 
        [&ud, &mt] { return ud(mt); });
    
    std::for_each(std::cbegin(v), std::cend(v), 
        [](auto const& val) { assert((1 <= val and val <= 10)); });
}
} // example_03


#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <cassert>
namespace example_04 { // -> initialize a container with std::generate_n
void run() {
    std::vector<int> v(5);
    auto i = 1;
    std::generate_n(std::begin(v), v.size(), [&i] { return i * i++;});

    assert((std::vector<int>{ 1, 4, 9, 16, 25 } == v));
}
} // example_04


#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
namespace example_05 {
void run() {
    std::vector<int> v(5);
    std::iota(std::begin(v), std::end(v), 1);

    assert((std::vector<int>{ 1, 2, 3, 4, 5 } == v));
}
} // example_05


#include <iostream>
int main() {
    std::cout << "[ok] - example_01 =>" << std::endl; example_01::run(); std::cout << std::endl << std::endl;
    std::cout << "[ok] - example_02 =>" << std::endl; example_02::run(); std::cout << std::endl << std::endl;
    std::cout << "[ok] - example_03 =>" << std::endl; example_03::run(); std::cout << std::endl << std::endl;
    std::cout << "[ok] - example_04 =>" << std::endl; example_04::run(); std::cout << std::endl << std::endl;
    std::cout << "[ok] - example_05 =>" << std::endl; example_05::run(); std::cout << std::endl << std::endl;
}