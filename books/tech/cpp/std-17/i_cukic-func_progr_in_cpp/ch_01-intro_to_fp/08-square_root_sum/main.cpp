#include <algorithm>
#include <limits>
#include <numeric>
#include <ranges>
#include <vector>
#include <cassert>
#include <cmath>


#include <iostream>
int main() {
    auto const& data = std::vector<double>{ 1.0, 2.0, 3.0 };
    auto const& trans_data = data | std::ranges::views::transform(sqrt);
    auto const& sum = std::accumulate(std::cbegin(trans_data), std::cend(trans_data), 0.0);
    
    assert(std::fabs(4.14626 - sum) < 0.001);
    
    return 0;
}
