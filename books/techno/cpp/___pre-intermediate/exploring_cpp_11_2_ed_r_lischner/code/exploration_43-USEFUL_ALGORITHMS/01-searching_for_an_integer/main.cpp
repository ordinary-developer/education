#include <algorithm>
#include <iostream>

#include "data.hpp"


int main() {
    intvector data{};
    read_data(data);
    write_data(data);
    auto iter(std::find(data.begin(), data.end(), 42));
    if (data.end() == iter)
        std::cout << "Value 42 not found\n";
    else {
        *iter = 0;
        std::cout << "Value 42 changed to 0:\n";
        write_data(data);
    }

    return 0;
}
