#include <iostream>

#define PRINT_PREFIX() \
{                                                               \
    std::cout << std::endl << "[" << (__LINE__ + 1) << "]"      \
              << std::endl << "\t";                             \
}

class Widget {
    public:
        Widget() 
        {
            std::cout << "Widget()" << std::endl;
        }

        Widget(std::initializer_list<int> initializerList)
        {
            std::cout << "Widget(initializerList)" << std::endl;
        }
};

int main() {
    // calls the default constructor
    PRINT_PREFIX();
    Widget w1;

    // also calls the default constructor
    PRINT_PREFIX();
    Widget w2{};

    // declare a function
    Widget w3();

    // call std::initializer constructor with an empty list
    PRINT_PREFIX();
    Widget w4({});

    // ditto
    PRINT_PREFIX();
    Widget w5{{}};
}
