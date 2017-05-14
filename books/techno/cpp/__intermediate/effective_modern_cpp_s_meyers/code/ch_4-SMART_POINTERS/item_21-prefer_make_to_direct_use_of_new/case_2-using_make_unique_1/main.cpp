#include <memory>

class Widget { };

int main() {
    auto upw1(std::make_unique<Widget>());
    std::unique_ptr<Widget> upw2(new Widget);

    auto spw1(std::make_shared<Widget>());
    std::shared_ptr<Widget> spw2(new Widget);

    return 0;
}
