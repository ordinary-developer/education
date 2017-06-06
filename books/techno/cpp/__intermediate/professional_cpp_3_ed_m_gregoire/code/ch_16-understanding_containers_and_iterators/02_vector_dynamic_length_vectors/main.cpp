#include <vector> // for vector
#include <limits> // for numeric_limits
#include <cstddef> // for size_t
#include <iostream> // for cout


auto main() -> int {
    std::vector<double> doubleVector;
    double max = - std::numeric_limits<double>::infinity();

    for (size_t i = 1; true; i++) {
        double temp;
        std::cout << "Enter score " << i << " (-1 to stop): ";
        std::cin >> temp;
        if (-1 == temp) {
            break;
        }
        doubleVector.push_back(temp);
        if (temp > max) {
            max = temp;
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

