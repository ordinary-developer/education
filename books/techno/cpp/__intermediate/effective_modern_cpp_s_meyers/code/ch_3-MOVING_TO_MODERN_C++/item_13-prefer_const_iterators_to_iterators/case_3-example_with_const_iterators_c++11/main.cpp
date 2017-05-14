#include <vector>
#include <iostream>
#include <algorithm>

int main() {
    std::vector<int> values = { 1970, 1983, 1989 };

    auto it = std::find(values.cbegin(), values.cend(), 1983);

    values.insert(it, 1998);

    for (auto& element: values) {
        std::cout << element << std::endl; 
    }
}
