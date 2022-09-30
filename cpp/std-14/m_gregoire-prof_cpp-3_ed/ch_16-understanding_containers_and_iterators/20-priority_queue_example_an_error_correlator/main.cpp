#include "ErrorCorrelator.hpp"

#include <stdexcept>
#include <iostream>


auto main() -> int {
    ErrorCorrelator ec;
    ec.addError(Error(3, "Unable to read file"));
    ec.addError(Error(1, "Incorrect entry from user"));
    ec.addError(Error(10, "Unable to allocate memory!"));

    while (true) {
        try {
            Error e = ec.getError();
            std::cout << e << std::endl;
        }
        catch (const std::out_of_range&) {
            std::cout << "Finished processing errors" << std::endl;
            break;
        }
    }

    return 0;
}
