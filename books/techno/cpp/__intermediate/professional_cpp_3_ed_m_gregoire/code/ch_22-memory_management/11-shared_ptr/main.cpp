#include <memory>
namespace example1 {

class EG { };    

void run() {
    auto ptr = std::make_shared<EG>();
}

} // namespace example1


#include <memory>
namespace example2 {

class Base { };
class Derived : public Base { };

void run() {
    std::shared_ptr<Derived> derivedPtr{ std::make_shared<Derived>() };
    std::shared_ptr<Base> basePtr
      { std::dynamic_pointer_cast<Base>(derivedPtr) };
}

} // namespace example2


#include <memory>
#include <cstdlib>
namespace example3 {

int* malloc_int(int value) {
    int* p{ (int*)malloc(sizeof(int)) };
    *p = value;
    return p;
}

void run() {
    std::shared_ptr<int> ptr{ malloc_int(42), free };
}

} // namespace example3


#include <cstdio>
#include <memory>
#include <iostream>
namespace example4 {

void CloseFile(FILE* filePtr) {
    if (nullptr == filePtr)
        return;

    fclose(filePtr);
    std::cout << "File closed." << std::endl;
}

void run() {
    FILE* f = fopen("data.txt", "w");
    std::shared_ptr<FILE> filePtr{ f, CloseFile };
    if (nullptr == filePtr)
        std::cerr << "Error opening file" << std::endl;
    else
        std::cout << "File opened" << std::endl;
}

} // namespace example4 


#include <memory>
#include <iostream>
namespace example5 {

class Nothing {
    public:
        Nothing() { std::cout << "Nothing::ctor" << std::endl; }
        virtual ~Nothing() { std::cout << "Nothing::dtor" << std::endl; }
};

void run() {
    auto ptr1 = std::make_shared<Nothing>();
    std::shared_ptr<Nothing> ptr2{ ptr1 };
}

} // namespace example5



int main() {
    example1::run();
    example2::run();
    example3::run();
    example4::run();
    example5::run();

    return 0;
}
