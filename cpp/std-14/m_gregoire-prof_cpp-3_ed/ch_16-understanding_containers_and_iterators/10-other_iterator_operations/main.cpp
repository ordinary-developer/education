#include <vector>


auto main() -> int {
    std::vector<int> intVector(10);
    
    auto it = begin(intVector);
    it += 5;
    --it;
    *it = 4;

    return 0;
}
