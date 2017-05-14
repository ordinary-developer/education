#include <iostream>
#include <array>

auto main() -> int {
    std::array<int, 3> arr = { 9, 8, 7 };
    std::cout << "Array size = " << arr.size() << std::endl;
    for (const auto& i : arr) {
        std::cout << i << std::endl;
    }

    std::cout << "Performing arr.fill(3)..." << std::endl;
    arr.fill(3);
    for (auto iter = begin(arr); iter != end(arr); ++iter) {
        std::cout << *iter << std::endl;
    }

    return 0;
}
