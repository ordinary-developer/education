#include <iostream>


auto AutoFunctionFromReturn(int parameter) {
    return parameter;
}


int main() {
    auto value = AutoFunctionFromReturn(1);
    std::cout << value << std::endl;

    return 0;
}
