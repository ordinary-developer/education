#include <algorithm>
#include <iostream>
#include <iterator>
#include <fstream>
#include <string>
#include <vector>
namespace test { // -> declaritvely read from a file

int countLines(std::string const& file) {
    std::ifstream in{file};

    return std::count(
        std::istreambuf_iterator<char>{in},
        std::istreambuf_iterator<char>{},
        '\n');
}

std::vector<int> countLines(std::vector<std::string> const& files) {
    std::vector<int> ret{};

    for (auto const& file : files)
        ret.push_back(countLines(file));

    return ret;
}

void run() {
    for (auto const cnt : countLines( { "main.cpp", "main.cpp", "main.cpp"}))
        std::cout << "line count: " << cnt << std::endl;
}
} // test


int main() {
    std::cout << "test => [ok]" << std::endl; test::run(); std::cout << std::endl;

    return 0;
}
