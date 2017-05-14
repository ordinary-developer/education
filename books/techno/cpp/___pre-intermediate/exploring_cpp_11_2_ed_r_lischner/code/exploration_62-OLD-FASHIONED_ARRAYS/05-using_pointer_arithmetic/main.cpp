#include <cstddef>
#include <iostream>

std::size_t my_std_strlen(char const* str) {
    char const* start{str};
    while (0 != *str)
        ++str;
    return str - start;
}

int main() {
    std::cout << my_std_strlen("12345") << std::endl;
    return 0;
}
