#include <limits> // for numeric_limits
#include <iostream> // for cout
#include <vector> // for vector
#include <cstddef> // for size_t


auto main() -> int {
    std::vector<double> doubleVector(10);

    double max = -std::numeric_limits<double>::infinity();
    for (size_t i = 0; i < doubleVector.size(); i++) {
        std::cout << "Enter score " << i + 1 << ": ";
        std::cin >> doubleVector[i];
        if (doubleVector[i] > max) {
            max = doubleVector[i];
        }
    }

    max /= 100.0;
    for (auto& element : doubleVector) {
        element /= max;
        std::cout << element << " ";
    }
    std::cout << std::endl;

    return 0;
}
