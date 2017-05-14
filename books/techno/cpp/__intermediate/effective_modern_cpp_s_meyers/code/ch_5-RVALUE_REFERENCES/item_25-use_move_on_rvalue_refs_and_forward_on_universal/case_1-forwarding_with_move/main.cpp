#include <memory>
#include <string>
#include <iostream>

class SomeDataStructure { };

class Widget {
    public:
        Widget() { }

        Widget(Widget&& rhs)
            : name(std::move(rhs.name)),
              p(std::move(rhs.p))
        {
            std::cout << "Move constructor was called\n";
        }

    private:
        std::string name;
        std::shared_ptr<SomeDataStructure> p;
};


auto main() -> int {
    Widget w1;
    Widget w2(std::move(w1));

    return 0;
}
