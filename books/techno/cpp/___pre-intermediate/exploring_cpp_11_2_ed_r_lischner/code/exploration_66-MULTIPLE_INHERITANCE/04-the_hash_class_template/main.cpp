#include "hash.hpp"
#include "string_pool.hpp"

#include <iostream>
#include <istream>
#include <utility>


int main() {
    string_pool pool{};
    std::string str{};
    hash<std::string> hasher{};

    while (std::cin >> str) {
        std::cout << "hash of \"" << str << "\" = "
                  << hasher(str) << '\n';
        pool.add(std::move(str));
    }

    return 0;
}
