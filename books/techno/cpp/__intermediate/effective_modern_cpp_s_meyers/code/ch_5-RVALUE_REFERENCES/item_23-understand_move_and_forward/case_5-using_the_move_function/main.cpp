#include <iostream>
#include <memory>

class Widget {
    public:
        Widget() { }

        Widget(Widget&& rhs)
            : s(std::move(rhs.s)) 
        {
            ++moveCtorCalls;
            std::cout << "Move ctor was called!" << std::endl;
        }

    private:
        static std::size_t moveCtorCalls;
        std::string s;
};

std::size_t Widget::moveCtorCalls = 0;

int main() {
    Widget widget1;
    Widget widget2(std::move(widget1));

    return 0;
}
