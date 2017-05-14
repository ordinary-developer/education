#include <memory>

class Widget { };

template<typename T>
void f(T&& param) { }

int main() {
    Widget w;

    // an lvalue reference
    f(w);

    // an rvalue reference
    f(std::move(w));

    return 0;
}
