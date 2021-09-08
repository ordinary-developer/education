#include <numeric>
#include <string>
#include <cassert>
namespace test { // folding

int f(int const prevCnt, char const c) {
    return ('\n' != c
        ? prevCnt : prevCnt + 1);
}

int countLines(std::string const& s) {
    return std::accumulate(
        std::cbegin(s), std::cend(s), 0, f);
}

void run() {
    assert(2 == countLines("a\nb\nc"));
}

} // test


#include <iostream>
int main() {
    std::cout << "test_01 => [ok]" << std::endl; test::run(); std::cout << std::endl;

    return 0;
}
