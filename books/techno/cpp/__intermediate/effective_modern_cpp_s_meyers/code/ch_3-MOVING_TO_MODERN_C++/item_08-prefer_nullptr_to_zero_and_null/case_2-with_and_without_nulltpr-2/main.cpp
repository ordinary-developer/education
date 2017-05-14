#include <iostream>

class Record { };

Record* findRecord() {
    return nullptr;
}

int main() {
    // without nullptr
    auto result1 = findRecord();
    if (result1 == 0) {
        std::cout << __LINE__ << std::endl;
    }

    // with nullptr
    auto result2 = findRecord();
    if (result2 == nullptr) {
        std::cout << __LINE__ << std::endl;
    }
}
