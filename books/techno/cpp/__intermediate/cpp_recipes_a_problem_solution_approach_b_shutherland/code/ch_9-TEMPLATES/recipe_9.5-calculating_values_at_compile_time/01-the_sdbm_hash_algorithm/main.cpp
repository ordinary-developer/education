#include <iostream>
#include <string>

unsigned int SDBMHash(const std::string& key) {
    unsigned int result{ 0 };
    for (unsigned int character: key) 
        result = character + (result << 6) + (result << 16) - result;

    return result;
}


int main(int argc, char* argv[]) {
    std::string data{ "Bruce Sutherland" };
    unsigned int sdbmHash{ SDBMHash(data) };

    std::cout << "The hash of " << data << " is " << sdbmHash << std::endl;

    return 0;
}
