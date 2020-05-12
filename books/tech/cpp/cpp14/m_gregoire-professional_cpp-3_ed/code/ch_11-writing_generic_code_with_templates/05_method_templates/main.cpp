#include "Grid.hpp"


auto main() -> int {
    Grid<int> myIntGrid;
    Grid<double> myDoubleGrid;

    myDoubleGrid = myIntGrid;
    Grid<double> newDoubleGrid(myIntGrid);

    return 0;
}
