#include "SpreadsheetCell.hpp"


auto main() -> int {
    int i, j = 4;
    i = -j;
    i = +i;
    j = +(-i);
    j = -(-i);

    i = i + 1;
    i += 1;
    ++i;
    i++;

    SpreadsheetCell c1(4);
    SpreadsheetCell c2(4);
    c1++;
    ++c2;

    return 0;
}
