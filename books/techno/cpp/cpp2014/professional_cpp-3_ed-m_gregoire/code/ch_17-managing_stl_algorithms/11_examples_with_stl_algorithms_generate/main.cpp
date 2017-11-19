#include <vector>
#include <algorithm>
#include <iostream>


auto main() -> int {
    std::vector<int> vector(10);
    int value = 1;

    generate(begin(vector), end(vector), [&value] { value *= 2; return value; });

    for (const auto& element : vector) {
        std::cout << element << " ";
    }
    std::cout << std::endl;

    return 0;
}
