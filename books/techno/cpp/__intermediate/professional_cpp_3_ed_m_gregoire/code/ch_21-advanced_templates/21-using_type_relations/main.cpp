#include <type_traits>
#include <iostream>

template <typename T1, typename T2>
void same(T1 const& t1, T2 const& t2) {
    bool areTypesTheSame = std::is_same<T1, T2>::value;
    std::cout << "'" << t1 << "' and '" << t2 << "' are ";
    std::cout << (areTypesTheSame ? "the same types." : "different types.")
              << std::endl;
}

int main() {
    same(1, 32);
    same(1, 3.01);
    same(3.01, std::string{ "Test" });

    return 0;
}
