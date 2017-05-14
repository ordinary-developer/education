#include <iostream>

class Widget {
    public:
        // this version of doWork applies 
        // only when *this is an lvalue
        void doWork() &
        {
            std::cout << "Widget->doWork()&" << std::endl;
        }

        // this version of doWork applies 
        // only when *this is an rvalue
        void doWork() && 
        {
            std::cout << "Widget->doWork()&&" << std::endl;
        }
};

Widget makeWidget() {
    Widget widget;
    return widget;
}

int main() {
    // normal object (an lvalue)
    Widget w;

    // calls Widget::doWork for lvalues
    // (i.e., Widget::doWork &)
    w.doWork();

    // calls Widget::doWork for rvalues
    // (i.e., Widget::doWork &&)
    makeWidget().doWork();
}
