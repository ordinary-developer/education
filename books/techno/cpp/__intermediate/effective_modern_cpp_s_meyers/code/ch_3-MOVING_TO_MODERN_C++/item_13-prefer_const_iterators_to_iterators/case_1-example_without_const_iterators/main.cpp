#include <vector>
#include <algorithm>
#include <iostream>

int main() {
    std::vector<int> values = { 1970, 1983, 1987 };
    std::vector<int>::iterator it = 
        std::find(values.begin(), values.end(), 1983);
    values.insert(it, 1998);

    for (auto& element: values) {
        std::cout << element << std::endl;
    }
}
