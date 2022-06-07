#include <algorithm>
#include <functional>
#include <random>
#include <vector>
#include <cassert>
namespace test {
    
template <typename BeginIt, typename EndIt, typename MidIt>
void sort_until(BeginIt begin, MidIt mid, EndIt end) {
    std::nth_element(begin, mid, end);
    std::sort(begin, mid);
}

void run() {
    std::vector<int> vals{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    
    std::random_device rd{};
    std::mt19937 g(rd());
    std::shuffle(std::begin(vals), std::end(vals), g);    
    
    sort_until(std::begin(vals), std::begin(vals) + 3, std::end(vals));
    assert(0 == vals[0] and 1 == vals[1] and 2 == vals[2]);    
}
} // test


#include <iostream>
int main() {
    std::cout << "test => [ok]" << std::endl; test::run(); std::cout << std::endl;

    return 0;
}
