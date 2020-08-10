#include <iostream>
#include <string>
#include <numeric>

int counter(int const prev_cnt, char const ch) {
    return ('\n' == ch ? prev_cnt + 1 : prev_cnt);
}

int count_lines(std::string const& str) {
    return std::accumulate(
        std::cbegin(str), std::cend(str), 0, counter);
}

int main(int, char**) {
    std::cout << count_lines(
        "an ancient pond \n"
        "a frog jumps in \n"
        "the splash of water\n") << std::endl;

    return 0;
}
