#include <vector>

auto main() -> int {
    std::vector<int> intVector(10);
    intVector.assign(5, 100);
    intVector.assign({1, 2, 3, 4});

    std::vector<int> vector1;
    std::vector<int> vector2;
    vector1.swap(vector2);

    return 0;
}
