#include <memory>
#include <iostream>
#include <mutex>

class Widget { };

int f1(std::shared_ptr<Widget> spw) {
    std::cout << "int f1(shared_ptr<Widget>)" << std::endl;
    return 0;
}

double f2(std::unique_ptr<Widget> upw) {
    std::cout << "f2(unique_ptr<Widget>)" << std::endl;
    return 0.0;
}

bool f3(Widget* w) {
    std::cout << "f3(Widget* w)" << std::endl;
    return true;
}

using MuxGuard = std::lock_guard<std::mutex>;

// C++11 version
template <typename FuncType,
          typename MuxType,
          typename PtrType>
auto lockAndCall(FuncType func,
                  MuxType& mutex,
                  PtrType ptr) -> decltype(func(ptr))
{
    MuxGuard g(mutex);
    return func(ptr);
}

int main() {
    std::mutex f1m, f2m, f3m;

    int value = 1;

    if (1 == value) {
        lockAndCall(f1, f1m, nullptr);
    }
    else if (2 == value) {
        lockAndCall(f2, f2m, nullptr);
    }
    else {
        lockAndCall(f3, f3m, nullptr);
    }

    // compilationerror
    // lockAndCall(f1, f1m, 0);
    
    // compilation error
    // lockAndCall(f1, f1m, NULL);
}
