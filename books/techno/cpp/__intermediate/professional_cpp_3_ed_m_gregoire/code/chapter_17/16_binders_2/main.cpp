#include <algorithm>
#include <vector>
#include <iostream>
#include <functional>

void increment(int& value) {
    ++value;
}

auto main() -> int {
    int index = 0;
    increment(index);

    auto increment1 = std::bind(increment, index);
    increment1();

    auto increment2 = std::bind(increment, std::ref(index));
    increment2();

    return 0;
}
