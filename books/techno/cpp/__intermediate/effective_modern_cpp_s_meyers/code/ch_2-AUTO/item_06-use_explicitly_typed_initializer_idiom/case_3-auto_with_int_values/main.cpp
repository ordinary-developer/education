#include <vector>
#include <iostream>

int main() {
    std::vector<int> c(10, 20);
    double d = 0.5;

    int index1 = d * c.size();
    std::cout << index1 << std::endl;

    auto index2 = static_cast<int>(d * c.size());
    std::cout << index1 << std::endl;
}
