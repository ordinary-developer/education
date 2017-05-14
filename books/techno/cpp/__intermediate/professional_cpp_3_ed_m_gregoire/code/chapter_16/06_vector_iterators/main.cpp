#include <iostream>
#include <vector>
#include <limits>
#include <cstddef>


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

    for(std::vector<double>::iterator iter = begin(doubleVector);
        end(doubleVector) != iter; ++iter)
    {
        *iter /= max;
        std::cout << *iter << " ";
    }
    std::cout << std::endl;

    return 0;
}
