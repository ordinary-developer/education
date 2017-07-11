#include "grid.hpp"

#include <iostream>
int main() {
    Grid<int, 10, 10> myGrid{};
    Grid<int, 10, 10> anotherGrid{};

    myGrid.setElementAt(2, 3, 45);
    anotherGrid = myGrid;
    
    std::cout << anotherGrid.getElementAt(2, 3);

    Grid<const char*, 2, 2> myStringGrid{};
    myStringGrid.setElementAt(1, 1, "Hello");
    Grid<const char*, 2, 2> myStringGridCopy{myStringGrid};
    myStringGridCopy.setElementAt(1, 1, "World.");
    
    std::cout << myStringGrid.getElementAt(1, 1) << std::endl;
    std::cout << myStringGridCopy.getElementAt(1, 1) << std::endl;

    return 0;
}
