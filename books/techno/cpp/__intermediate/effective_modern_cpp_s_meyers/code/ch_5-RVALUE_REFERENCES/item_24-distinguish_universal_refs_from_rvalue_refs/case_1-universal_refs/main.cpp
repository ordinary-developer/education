#include <vector>

class Widget { };

// no type deduction
// rvalue reference
void f(Widget&& param) {
}

// no type deduction
// rvalue reference
template<typename T>
void f(std::vector<T>&& param) { }

// type deduction
// universal reference
template<typename T>
void f(T&& param) { }

int main() {
    // no type deduction
    // rvalue reference
    Widget&& var1 = Widget();

    // type deduction
    // universal reference
    auto&& var2 = var1;

    return 0;
}
