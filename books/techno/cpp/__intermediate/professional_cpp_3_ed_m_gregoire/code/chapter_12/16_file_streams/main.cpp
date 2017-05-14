#include <iostream>
#include <fstream>

auto main(int argc, char* argv[]) -> int {
    std::ofstream outFile("test.txt", std::ios_base::trunc);
    if (!outFile.good()) {
        std::cerr << "Error while opening output file!" << std::endl;
        return -1;
    }
    outFile << "There were " << argc << " arguments to this program." << std::endl;
    outFile << "They are: " << std::endl;
    for (int i = 0; i < argc; i++) {
        outFile << argv[i] << std::endl;
    }

    return 0;
}
