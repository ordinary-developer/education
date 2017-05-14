#include <vector>
#include <iostream>
#include <functional>
#include <algorithm>


void testCallback(const std::vector<int>& vector,
        const std::function<bool(int)>& callback) 
{
    for (const auto& i : vector) {
        if (!callback(i)) {
            break;
        }
        std::cout << i << " " << std::endl;
    }
}

void testCallback2(const std::vector<int>& vector,
    const std::function<bool(int)>& callback)
{
    for (auto iterator = vector.begin(); vector.end() != iterator; ++iterator) {
        if (!callback(*iterator)) {
            break;
        }
        std::cout << *iterator << " " << std::endl;
    }
}

auto main() -> int {
    std::vector<int> vector {1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    testCallback(vector, [](int i) { return i < 6; });

    testCallback2(vector, [] (int i) { return i >  ; });

    return 0;
}

