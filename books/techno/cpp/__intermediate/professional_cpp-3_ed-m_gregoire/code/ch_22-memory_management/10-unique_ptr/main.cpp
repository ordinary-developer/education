#include <memory>
namespace example1 {

class ExampleClass { };

void run() {
    auto ptr1 = std::make_unique<ExampleClass>();
    std::unique_ptr<ExampleClass> ptr2{ new ExampleClass{} };
}

}

#include <memory>
#include <cstdlib>
namespace example2 {

int* malloc_int(int value) {
    int* p{ (int*)malloc(sizeof(int)) };
    *p = value;
    return p;
}

void run() {
    auto deleter = [](int* p) { free(p); };
    std::unique_ptr<int, decltype(deleter)> intPointer{ malloc_int(42),
                                                        deleter };
}

}

int main() {
    example1::run();
    example2::run();

    return 0;
}
