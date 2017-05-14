class Widget { };

Widget widgetFactory() {
    Widget w;
    return w;
}

int main() {
    Widget w;

    // w1 is lvalue
    // type for auto is "Widget&"
    auto&& w1 = w;

    // w2 is rlvalue
    // type for auto is "Widget"
    auto&& w2 = widgetFactory();

    return 0;
}
