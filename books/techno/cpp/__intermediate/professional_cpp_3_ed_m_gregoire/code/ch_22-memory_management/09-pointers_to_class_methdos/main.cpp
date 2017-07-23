#include "SpreadsheetCell.h"
#include <iostream>
namespace example1 {
void run() {
    SpreadsheetCell myCell{123};
    double (SpreadsheetCell::*methodPtr)() const = 
        &SpreadsheetCell::getValue;
    std::cout << (myCell.*methodPtr)() << std::endl;
}
}

#include "SpreadsheetCell.h"
#include <iostream>
namespace example2 {
void run() {
    SpreadsheetCell myCell{123};
    using PtrToGet = double (SpreadsheetCell::*) () const;
    PtrToGet methodPtr = &SpreadsheetCell::getValue;
    std::cout << (myCell.*methodPtr)() << std::endl;
}
}

#include "SpreadsheetCell.h"
#include <iostream>
namespace example3 {
void run() {
    SpreadsheetCell myCell{123};
    auto methodPtr = &SpreadsheetCell::getValue;
    std::cout << (myCell.*methodPtr)() << std::endl;
}
}

int main() {
    example1::run();
    example2::run();
    example3::run();

    return 0;
}
