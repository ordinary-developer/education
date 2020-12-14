#include <iostream>

class Simple
{
    public:
        Simple() { 
            std::cout << "Simple constructor called!" << std::endl; 
        }
        virtual ~Simple() {
            std::cout << "Simple destructor called!" << std::endl; 
        }
};

void example1() {
    Simple* mySimpleArray = new Simple[4];
    delete [] mySimpleArray;
    mySimpleArray = nullptr;
}

#include <cstddef>
void example2() {
    size_t arraySize{4};

    Simple** mySimplePtrArray = new Simple*[arraySize];
    for (size_t i{0}; i < arraySize; ++i)
        mySimplePtrArray[i] = new Simple{};

    for (size_t i{0}; i < arraySize; ++i) {
        delete mySimplePtrArray[i];
        mySimplePtrArray[i] = nullptr;
    }

    delete [] mySimplePtrArray;
    mySimplePtrArray = nullptr;
}

int main() {
    example1();    
    example2();

    return 0;
}
