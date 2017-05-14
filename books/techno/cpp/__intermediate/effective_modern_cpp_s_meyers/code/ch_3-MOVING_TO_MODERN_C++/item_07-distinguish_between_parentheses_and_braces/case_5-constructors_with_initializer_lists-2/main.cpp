#include <iostream>

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

        Widget(std::initializer_list<bool> initializerList)
        {
            std::cout << "Widget(initializer_list<bool>)" << std::endl;
            for (auto& element: initializerList) {
                std::cout << element << std::endl;
            }
        }
};

int main() {
    // here an error will be
    // or a warning
    Widget w{ 10, 5.0 };
}
