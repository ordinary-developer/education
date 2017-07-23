namespace example1 {
void run() {
    int* myArray{ new int[8] };
    myArray[2] = 33;
    *(myArray + 2) = 33;
}
}

#include <cstring>
#include <cstddef>
#include <iostream>
namespace example2 {
    char* toCaps(const char* inString) {
        size_t size{ strlen(inString) + 1 };
        char* result{ new char[size] };
        strcpy(result, inString);

        return result;
    }

    void run() {
        const char* myString{ "Hello, World!" };
        std::cout << toCaps(myString) << std::endl;
        std::cout << toCaps(myString + 7) << std::endl;
    }
}


int main() {
    example1::run();
    example2::run();

    return 0;
}
