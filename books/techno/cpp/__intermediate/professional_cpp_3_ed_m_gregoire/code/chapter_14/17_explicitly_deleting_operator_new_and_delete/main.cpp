#include <new>
#include <cstddef>

class MyClass {
    public:
        void* operator new (std::size_t size) = delete;
        void* operator new[] (std::size_t size) = delete;
};

auto main() -> int { 
    MyClass classOnStack;

    // will not compile
    // MyClass* p1 = new MyClass;
    // MyClass* pArray = new MyClass[2];

    return 0;
}
