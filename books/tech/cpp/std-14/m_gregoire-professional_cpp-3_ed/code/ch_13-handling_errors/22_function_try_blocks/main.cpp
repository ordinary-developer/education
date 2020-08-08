#include <iostream>
#include <exception>
#include <stdexcept>


class SubObject {
    public:
        SubObject(int i);
};

SubObject::SubObject(int i) {
    throw std::runtime_error("Exception by SubObject ctor");
}


class MyClass {
    public:
        MyClass();
    private:
        SubObject mSubObject;
};

MyClass::MyClass() 
    try 
        : mSubObject(42)
    {
        /* contructor's body */
    }
    catch (const std::exception& e) {
        std::cout << "function try-block caught: '" << e.what() << "'" << std::endl;
    }


auto main() -> int {
    try {
        MyClass m;
    }
    catch (const std::exception& e) {
        std::cout << "main() caught: '" << e.what() << "'" << std::endl;
    }

    return 0;
}
