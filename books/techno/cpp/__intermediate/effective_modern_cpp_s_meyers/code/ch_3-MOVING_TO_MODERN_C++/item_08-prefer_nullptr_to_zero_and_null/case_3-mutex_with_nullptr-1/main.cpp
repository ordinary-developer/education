#include <memory>
#include <iostream>
#include <mutex>

using MuxGuard = std::lock_guard<std::mutex>;

class Widget {
};

int f1(std::shared_ptr<Widget> spw) {
    std::cout << "f1(shared_ptr<Widget>)" << std::endl;
    return 1;
}

double f2(std::unique_ptr<Widget> upw) {
    std::cout << "f2(unique_ptr<Widget>)" << std::endl;
    return 1.0;
}

bool f3(Widget* pw) {
    std::cout << "f3(Widget*)" << std::endl;
    return true;
}


int main() {
    std::mutex f1m, f2m, f3m;
    
    int value = 1;

    if (1 == value) {
        MuxGuard g(f1m);
        // can't use "nullptr" (WHY?)
        auto result = f1(0);
    }
    else if (2 == value) {
        MuxGuard g(f2m);
        // can't use "nullptr" (WHY?)
        auto result = f2(NULL);
    }
    else {
        MuxGuard g(f3m);
        auto result = f3(nullptr);
    }

}
