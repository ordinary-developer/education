#include <algorithm>
#include <iostream>
#include <iterator>
#include <fstream>
#include <string>
#include <vector>
namespace test_01 { // declaratively read from a file (with a normal func for std::transform)

int countLinesImpl(std::string const& file) {
    std::ifstream in{file};

    return std::count(
        std::istreambuf_iterator<char>{in},
        std::istreambuf_iterator<char>{},
        '\n');
}

std::vector<int> countLines(std::vector<std::string> const& files) {
    std::vector<int> ret(files.size());

    std::transform(std::cbegin(files), std::cend(files), ret.begin(), countLinesImpl);

    return ret;
}

void run() {
    for (auto const cnt: countLines( { "main.cpp", "main.cpp", "main.cpp" }))
        std::cout << "line count: " << cnt << std::endl;
}   
} // test_01


#include <algorithm>
#include <iostream>
#include <iterator>
#include <fstream>
#include <string>
#include <vector>
namespace test_02 { // declaratively read from a file (with a lambda func for std::transform)

std::vector<int> countLines(std::vector<std::string> const& files) {
    std::vector<int> ret(files.size());

    std::transform(
        std::cbegin(files),
        std::cend(files),
        std::begin(ret),
        [](auto const& file) {
            std::ifstream in{file};

            return std::count(
                std::istreambuf_iterator<char>{in},
                std::istreambuf_iterator<char>{},
                '\n');
        });

    return ret;
}

void run() {
    for (auto const cnt: countLines( { "main.cpp", "main.cpp", "main.cpp" }))
        std::cout << "line count: " << cnt << std::endl;
}    
} // test_02


int main() {
    std::cout << "test 01 => [ok]" << std::endl; test_01::run(); std::cout << std::endl;
    std::cout << "test 02 => [ok]" << std::endl; test_02::run(); std::cout << std::endl;

    return 0;
}
