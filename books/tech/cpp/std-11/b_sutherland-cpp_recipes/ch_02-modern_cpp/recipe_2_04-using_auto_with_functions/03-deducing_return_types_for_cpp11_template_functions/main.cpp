#include <iostream>

template <typename T>
auto AutoFunctionFromParameter(T parameter) -> decltype(parameter) {
    return parameter;
}


int main() {
    auto value = AutoFunctionFromParameter(2);
    std::cout << value << std::endl;

    return 0;
}

