#include <iostream>

#include "Grid.hpp"


constexpr size_t getHeight() { return 10; }

auto main() -> int {
    Grid<int, 10, 10> myGrid;
    Grid<int, 10, 10> anotherGrid;
    myGrid.setElementAt(2, 3, 45);
    anotherGrid = myGrid;
    std::cout << anotherGrid.getElementAt(2, 3) << std::endl;

    // will not compile
    // size_t height = 10;
    // Grid<int, 10, height> testGrid;
    
    const size_t height = 10;
    Grid<int, 10, height> testGrid;

    Grid<double, 2, getHeight()> myDoubleGrid;

    return 0;
}
