#include <memory>
#include <string>
#include <iostream>

class SomeDataStructure { };

class Widget {
    public:
        template<typename T>
        void setName(T&& newName)
        {
            // bad, bad, bad
            name = std::move(newName);
        }
    private:
        std::string name;
        std::shared_ptr<SomeDataStructure> p;
};

std::string getWidgetName() {
    return std::string("example value");
}

auto main() -> int {
    Widget w;
    // n is a local variable
    auto n = getWidgetName();
    // moves n into w
    w.setName(n);
    // n's value is now unknown
    std::cout << n << std::endl;

    return 0;
}
