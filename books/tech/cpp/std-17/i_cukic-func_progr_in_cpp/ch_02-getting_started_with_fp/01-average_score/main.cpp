// calculating the average score imperatively
#include <vector>
#include <cassert>
#include <cmath>
namespace test_01 {

double average_score(std::vector<int> const& scores) {
    int sum{0};

    for (int score : scores)
        sum += score;

    return sum / (double)scores.size();
}

void run() {
    double const val = average_score({ 1, 2, 3, 4, 5 });

    assert(std::abs(3. - val) < 0.001);
}
} // test_01


// calculating the average score functionally
#include <numeric>
#include <vector>
#include <cassert>
#include <cmath>
namespace test_02 {

double average_score(std::vector<int> const& scores) {
    return 
        std::accumulate(std::cbegin(scores), std::cend(scores), 0)
        / (double)scores.size();
}

void run() {
    double const val = average_score({ 1, 2, 3, 4, 5 });

    assert(std::abs(3. - val) < 0.001);
}

} // test_02


// calculating the product of all scores
#include <functional>
#include <numeric>
#include <vector>
#include <cmath>
#include <cassert>
namespace test_03 {

double scores_product(std::vector<int> const& scores) {
    return std::accumulate(
        std::cbegin(scores), 
        std::cend(scores), 
        1, 
        std::multiplies<int>{});
}

void run() { assert(120 == scores_product({ 1, 2, 3, 4, 5 })); }

} // test_03


#include <iostream>
int main() {
    std::cout << "test_01 => [ok]" << std::endl; test_01::run(); std::cout << std::endl;
    std::cout << "test_02 => [ok]" << std::endl; test_02::run(); std::cout << std::endl;
    std::cout << "test_03 => [ok]" << std::endl; test_03::run(); std::cout << std::endl;

    return 0;
}
