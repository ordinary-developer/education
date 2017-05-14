#include <memory>
#include <iostream>
#include <string>

class Widget {
    public:
        template<typename T>
        void setName(T&& newName)
        {
            name = std::forward<T>(newName);
            std::cout << name << std::endl;
        }

    private:
        std::string name;
};

auto main() -> int {
    Widget widget;
    widget.setName<std::string>("rvalue");

    std::string lvalue = "lvalue";
    widget.setName<std::string>(std::forward<std::string>(lvalue));

    return 0;
}
