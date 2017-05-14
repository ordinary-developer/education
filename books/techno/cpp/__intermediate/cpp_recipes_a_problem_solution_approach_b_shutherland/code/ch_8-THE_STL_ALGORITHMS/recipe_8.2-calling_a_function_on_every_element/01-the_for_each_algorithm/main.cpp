#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>


int main() {
    std::vector<int32_t> myVector { 1, 2, 3, 4, 5 };

    std::for_each(myVector.begin(), 
                  myVector.end(),
                  [](int32_t value) {
                    std::cout << value << std::endl;
                  });

    return 0;
}
