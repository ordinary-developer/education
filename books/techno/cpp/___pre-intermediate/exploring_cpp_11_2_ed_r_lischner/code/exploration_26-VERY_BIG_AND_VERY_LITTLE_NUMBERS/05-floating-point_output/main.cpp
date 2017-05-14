#include <iostream>

void print(int precision, float value) {
    std::cout.precision(precision);
    std::cout << std::scientific << value << '\t'
              << std::fixed      << value << '\t';
    
    std::cout.unsetf(std::ios_base::floatfield);
    std::cout << value << '\n';
}

int main() {
    print(6, 123456.789f);
    print(4, 123456.789f);
    print(2, 123456.789f);
    print(5, 123456.789f);

    return 0;
}
