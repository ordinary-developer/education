#include <cstddef>
#include <vector>


std::vector<int> createVectorOfSize(size_t size) {
    std::vector<int> vec(size);
    int contents = 0;
    for (auto& i : vec) {
        i = contents++;
    }
    return vec;
}

auto main() -> int { 
    std::vector<int> myVector;
    myVector = createVectorOfSize(123);

    return 0;
}
