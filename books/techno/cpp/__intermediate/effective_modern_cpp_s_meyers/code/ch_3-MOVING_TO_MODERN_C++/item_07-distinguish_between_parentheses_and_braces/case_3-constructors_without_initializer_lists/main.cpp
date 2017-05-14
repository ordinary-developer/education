#include <iostream>

class Widget {
    public:
        // constructors without 
        // "std::initalizer_list" parameters
        Widget(int i, bool b) 
        {
            std::cout << "Widget(int, bool)" << std::endl;
        }

        Widget(int i, double d) 
        {
            std::cout << "Widget(int, double)" << std::endl;
        }
};

int main() {
    // calls the 1-st constructor
    Widget w1(10, true);

    // also calls the 1-st constructor
    Widget w2{ 10, true };

    // also calls the 1-st constructor
    Widget w3 = { 10, true };

    // also calls the 2-nd constructor
    Widget w4(10, 5.0);

    // also calls the 2-nd constructor
    Widget w5{ 10, 5.0 };

    // also calls the 2-nd constructor
    Widget w6 = { 10, 5.0 };
}
