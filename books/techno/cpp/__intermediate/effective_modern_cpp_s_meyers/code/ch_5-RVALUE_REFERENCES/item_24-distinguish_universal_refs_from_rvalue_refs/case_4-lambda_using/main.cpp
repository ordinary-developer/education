#include <memory>
#include <iostream>

int function(int value) {
    std::cout << "simple function: " << value << std::endl;
}

int main() {
    auto timeFuncInvocation =
        [](auto&& func, auto&&... params)
    {
        // start timer
        std::forward<decltype(func)>(func)(
        std::forward<decltype(params)>(params)...);
        // stop timer
    };

    timeFuncInvocation(function, 3);

    return 0;
}
