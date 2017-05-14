#include <iostream>
#include <string>

#define PRINT_PREFIX() \
{                                                               \
    std::cout << std::endl << "[" << (__LINE__ + 1) << "]"      \
              << std::endl << "\t";                             \
}

class Widget {
    public:
        Widget(int i, bool b) 
        {
            std::cout << "Widget(int, bool)" << std::endl;
        }

        Widget(int i, double d)
        {
            std::cout << "Widget(int, double)" << std::endl;
        }

        Widget(std::initializer_list<std::string>
                initializerList)
        {
            std::cout << "Widget(initializerList)" << std::endl;
        }
};

int main() {
    // calls the 1-st constructor
    PRINT_PREFIX();
    Widget w1(10, true);

    // calls the 1-st constructor
    PRINT_PREFIX();
    Widget w2{ 10, true };

    // calls the 2-nd constructor
    PRINT_PREFIX();
    Widget w3(10, 5.0);

    // calls the 3-d constructor
    PRINT_PREFIX();
    Widget w4{ 10, 5.0 };
}
