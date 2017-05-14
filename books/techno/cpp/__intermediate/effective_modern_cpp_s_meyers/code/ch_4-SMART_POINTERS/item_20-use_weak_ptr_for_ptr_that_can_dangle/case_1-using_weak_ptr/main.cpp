#include <iostream>
#include <memory>

class Widget { };

int main() {
    auto spw = std::make_shared<Widget>();
    std::weak_ptr<Widget> wpw(spw);
    spw = nullptr;
    if (wpw.expired()) {
        std::cout << "the pointer has expired\n";
    }

    return 0;
}
