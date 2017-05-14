#include <array>
#include <iostream>

class Widget { 
    public:
        Widget() { }

        Widget(const Widget&&) {
            std::cout << "Move operation" << std::endl;
        }
};

int main() {
    std::array<Widget, 10000> aw1;

    auto aw2 = std::move(aw1);


    return 0;
}


