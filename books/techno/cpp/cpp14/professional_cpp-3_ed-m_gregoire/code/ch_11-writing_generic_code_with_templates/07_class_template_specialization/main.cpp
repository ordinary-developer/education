#include "GridString.hpp"

#include <iostream>


auto main() -> int {
    Grid<int> myIntGrid;
    Grid<const char*> stringGrid1(2, 2);

    const char* dummy = "dummy";
    stringGrid1.setElementAt(0, 0, "hello");
    stringGrid1.setElementAt(0, 1, dummy);
    stringGrid1.setElementAt(1, 0, dummy);
    stringGrid1.setElementAt(1, 1, "there");

    Grid<const char*> stringGrid2(stringGrid1);

    std::cout << stringGrid1.getElementAt(0, 1) << std::endl;
    std::cout << stringGrid2.getElementAt(0, 1) << std::endl;

    return 0;
}
