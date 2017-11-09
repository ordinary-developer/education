#include <array>
#include <cassert>
#include <iostream>


int main() {
    std::array<int, 5> data{ {1, 2, 3, 4, 5} };

    assert(5 == data.size());
    
    try {
        data.at(10);
    } catch (...) { std::cout << "exception here" << std::endl; }

    for (auto x: data)
        std::cout << x << '\n';

    std::array<int, 0> look_ma_no_elements;
    assert(0 == look_ma_no_elements.size());

    return 0;
}
