#include "grid_ptr.hpp"

#include <iostream>

int main() {
    Grid<int> myIntGrid{};
    Grid<int*> psGrid{ 2, 2 };

    psGrid.setElementAt(0, 0, std::make_unique<int>(1));
    psGrid.setElementAt(0, 1, std::make_unique<int>(2));
    psGrid.setElementAt(1, 0, std::make_unique<int>(3));

    Grid<int*> psGrid2{ psGrid };
    Grid<int*> psGrid3{};
    psGrid3 = psGrid2;

    auto element = psGrid2.getElementAt(1, 0);
    if (element) {
        std::cout << *element << std::endl;
        *element = 6;
    }
    std::cout << *psGrid.getElementAt(1, 0) << std::endl;
    std::cout << *psGrid2.getElementAt(1, 0) << std::endl;

    return 0;
}
