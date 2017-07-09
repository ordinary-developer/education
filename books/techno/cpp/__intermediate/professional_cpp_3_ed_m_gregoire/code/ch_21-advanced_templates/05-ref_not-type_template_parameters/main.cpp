#include "SpreadsheetCell.h"
#include "Grid.h"

namespace {
    int defaultInt = 11;
    SpreadsheetCell defaultCell(1.2);
}

int main() {
    Grid<int, defaultInt> myIntGrid{};
    Grid<SpreadsheetCell, defaultCell> mySpreadsheet{};
    Grid<int, defaultInt> myIntGrid2{ myIntGrid };

    return 0;
}
