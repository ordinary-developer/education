#include <iostream>
#include <fstream>
#include <string>


bool changeNumberForID(const std::string& inFileName, int inID,
        const std::string& inNewNumber);

auto main() -> int {
    changeNumberForID("data.txt", 263, "415-555-3333");

    return 0;
}

bool changeNumberForID(const std::string& inFileName, int inID,
        const std::string& inNewNumber)
{
    std::fstream ioData(inFileName.c_str());
    if (!ioData) {
        std::cerr << "Error while opening file " << inFileName << std::endl;
        return false;
    }
    
    while (ioData.good()) {
        int id;
        std::string number;
        ioData >> id;
        if (id == inID) {
            ioData.seekp(ioData.tellg());
            ioData << " " << inNewNumber;
            break;
        }
        ioData >> number;
    }
    return true;
}

