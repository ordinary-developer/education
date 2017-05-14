#include <cstddef>
#include <vector>
#include <iostream>


auto main() -> int {
    const size_t count = 10;
    unsigned int arr[count];
    for(unsigned int i = 0; i < count; i++) {
        arr[i] = i;
    }
    
    std::vector<int> vec;
    vec.insert(end(vec), arr, arr + count);
    // will be compiled only in GCC 5.0 or later
    // vec.insert(end(vec), std::cbegin(arr), std::cend(arr));
    for (const auto& i : vec) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    return 0;
}
