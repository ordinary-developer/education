#include <memory>

class Widget { };

Widget makeWidget() {
    Widget w;
    
    // don't do this
    // return std::move(w);
    
    // do like this
    return w;
}

Widget makeWidget(Widget w) {
    // ..
    //
    // don't to this
    // return std::move(w)
    
    // do like this
    return w;
}

int main() {
    Widget w1 = makeWidget();
    Widget w2 = makeWidget(w1);

    return 0;
}
