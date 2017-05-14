#include <iostream>
#include <functional>


std::function<int(void)> multiplyBy2Lambda(int x) {
    return [x] { return 2 * x; };
}

auto main() -> int {
    std::function<int(void)> fn1 = multiplyBy2Lambda(5);
    std::cout << fn1() << std::endl;

    auto fn2 = multiplyBy2Lambda(5);
    std::cout << fn2() << std::endl;

    return 0;
}

