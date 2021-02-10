#include <iostream>
#include <fstream>
#include <string>
#include <vector>
namespace test { // -> imperatively read from a file 

std::vector<int> countLines(std::vector<std::string> const& files) {
    std::vector<int> ret{};
    char c{0};

    for (auto const& file : files) {
        std::ifstream in{file};

        int lineCnt{0};
        while (in.get(c))
            if ('\n' == c)
                ++lineCnt;

        ret.push_back(lineCnt);
    }

    return ret;
}

void run() {
    for (auto const cnt : countLines({ "main.cpp", "main.cpp", "main.cpp" }))
        std::cout << "line count: " << cnt << std::endl;

}
} // test


int main() {
    std::cout << "test => [ok]" << std::endl; test::run(); std::cout << std::endl;

    return 0;
}
