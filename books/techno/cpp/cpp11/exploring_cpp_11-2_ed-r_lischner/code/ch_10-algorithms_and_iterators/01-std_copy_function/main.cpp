#include <algorithm>
#include <cassert>
#include <vector>


int main() {
    std::vector<int> input{ 10, 20, 30 };
    std::vector<int> output{};

    output.resize(input.size());
    std::copy(std::begin(input), std::end(input), std::begin(output));
    assert(input == output);

    return 0;
}
