#include <iostream>

#include <stdexcept>
#include <fstream>


auto main() -> int {
    if (std::cout.good()) {
        std::cout << "All good" << std::endl;
    }

    std::cout.flush();
    if (std::cout.fail()) {
        std::cerr << "Unable to flush to standard out" << std::endl;
    }

    std::cout.exceptions(std::ios::failbit | std::ios::badbit | std::ios::eofbit);
    try {
        std::cout << "Hello world" << std::endl;
    }
    catch (const std::ios_base::failure& ex) {
        std::cerr << "Caught exception: " << ex.what() << std::endl;
    }
    std::cout.clear();

    return 0;
}
