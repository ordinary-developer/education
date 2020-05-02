#include <algorithm>
#include <vector>
#include <iostream>

int main() {
    std::vector<int> vec(10);
    int state;
    std::generate(vec.begin(),
                  vec.end(), 
                  [&state]() { return ++state; });

    for (auto&& element : vec)
        std::cout << element << ", ";
    std::cout << std::endl;

    return 0;
}
