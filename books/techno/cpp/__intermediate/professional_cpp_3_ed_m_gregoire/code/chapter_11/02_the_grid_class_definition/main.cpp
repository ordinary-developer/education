#include "Grid.hpp"
#include <vector>
#include <memory>


auto main() -> int {
    Grid<int> myIntGrid;
    Grid<double> myDoubleGrid(11, 11);
    myIntGrid.setElementAt(0, 0, 10);
    int x = myIntGrid.getElementAt(0, 0);
    Grid<int> grid2(myIntGrid);
    Grid<int> anotherIntGrid;
    anotherIntGrid = grid2;

    Grid<const char*> myStringGrid;
    myStringGrid.setElementAt(2, 2, "Hello");

    Grid<std::vector<int>> gridOfVectors;
    std::vector<int> myVector{1, 2, 3, 4 };
    gridOfVectors.setElementAt(5, 6, myVector);

    auto myGridp = std::make_unique<Grid<int>>(2, 2);
    myGridp->setElementAt(0, 0, 10);
    int y = myGridp->getElementAt(0, 0);
    
    return 0;
}
