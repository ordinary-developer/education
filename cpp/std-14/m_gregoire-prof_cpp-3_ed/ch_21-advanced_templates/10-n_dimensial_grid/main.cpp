#include "ndgrid.hpp"

#include <iostream>

int main() {
    NDGrid<int, 3> my3DGrid{};
    my3DGrid[2][1][2] = 5;
    my3DGrid[1][1][1] = 5;
    std::cout << my3DGrid[2][1][2] << std::endl;

    return 0;
}
