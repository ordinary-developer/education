#include <iostream>
#include <cstring>

void rawWrite(const char* data, int dataSize) {
    std::cout.write(data, dataSize);
}

int main() {
    const char* test = "hello there\n";
    rawWrite(test, strlen(test));

    return 0;
}
