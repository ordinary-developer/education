#include <iostream>
#include <vector>

int main() {
    using MyVector = std::vector<int>;

    MyVector vectorA(1);
    std::cout << vectorA.size() << " " << vectorA[0] << std::endl;

    MyVector vectorB(1, 10);
    std::cout << vectorB.size() << " " << vectorB[0] << std::endl;

    return 0;
}
