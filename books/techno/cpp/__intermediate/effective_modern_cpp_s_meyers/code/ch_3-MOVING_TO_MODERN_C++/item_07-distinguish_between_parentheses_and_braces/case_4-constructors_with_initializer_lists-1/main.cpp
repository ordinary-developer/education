#include <iostream>

#define PRINT_PREFIX() \
{                                                               \
    std::cout << std::endl << "[" << (__LINE__ + 1) << "]"      \
              << std::endl << "\t";                             \
}

class Widget {
    public:
        Widget(int i, bool b) 
        {
            std::cout << "Widget(int, bool)" << " " << __LINE__
                      << std::endl;
        }

        Widget(int i, double d)
        {
            std::cout << "Widget(int, double)" << " " << __LINE__
                      << std::endl;
        }

        Widget(std::initializer_list<long double> initializer_list)
        {
            std::cout << "Widget(std::initializer_list<long double>)"
                      << " " << __LINE__ << std::endl;
        }

        // a stub operator
        operator float() const { return 5; }
};


int main() {
    // calls the 1-st constructor
    PRINT_PREFIX();
    Widget w1(10, true);

    // calls the "std::initializer_list" constructor
    // (10 and true convert to long double)
    PRINT_PREFIX();
    Widget w2 { 10, true };

    // ditto
    PRINT_PREFIX();
    Widget w2_2 = { 10, true };

    // calls the 2-nd constructor
    PRINT_PREFIX();
    Widget w3(10, 5.0);

    // calls the "std::initializer_list" constructor
    // (10 and 5.0 convert to long double)
    PRINT_PREFIX();
    Widget w4 { 10, 5.0 };

    // ditto
    PRINT_PREFIX();
    Widget w4_2 = { 10, 5.0 };

    // calls the copy constructor
    PRINT_PREFIX();
    Widget w5(w4);

    // calls the "std::initialzier_list" constructor
    // (w4 converts to float and float converts to long double)
    PRINT_PREFIX();
    Widget w6{ w4 };

    // calls the move constructor
    PRINT_PREFIX();
    Widget w7(std::move(w4));

    // calls the "std::initializer_list" constructor
    // (for the same reason as w6)
    PRINT_PREFIX();
    Widget w8{ std::move(w4) };
}
