#include <iostream>
#include <string>

template <class T>
void print(std::string const& label, T value) {
    std::cout << label << " = ";
    std::cout << std::dec << value << " = ";
    std::cout.width(8);
    std::cout.fill('0');
    std::cout << std::hex << std::internal << std::showbase 
              << value << '\n';
}

int main() {
    int i{ ~0 };
    unsigned int u{ ~0u };
    print("int >> 15", i >> 15);
    print("unsigned >> 15", u >> 15);

    return 0;
}
