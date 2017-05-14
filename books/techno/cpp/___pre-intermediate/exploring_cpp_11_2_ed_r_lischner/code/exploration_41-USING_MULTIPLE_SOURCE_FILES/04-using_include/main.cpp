#include "generate_id.hpp"

#include <iostream>


int main() {
    generate_id gen{};
    for (int i{ 0 }; i != 10; ++i)
        std::cout << gen.next() << '\n';

    return 0;
}

