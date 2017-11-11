#include "hash_map.hpp"

#include <iostream>
#include <string>
int main() {
    std::cout << my_hash::hash<double>{}(0.35) << std::endl;
    std::cout << my_hash::hash<std::string>{}("example") << std::endl;

    return 0;
}
