#include <iostream>


class Widget { };

Widget widgetFactory() {
    Widget w;
    return w;
}

template <typename T>
void func(T&& param) { }

int main() {
    Widget w;

    // call func with lvalue
    // T deduced to be Widget&
    func(w);

    // call func with rvalue;
    // T deduced to be Widget
    func(widgetFactory());

    return 0;
}

