#include <memory>

class Widget { };

int main() {
    auto widgetDeleter = [](Widget* pw) {
        delete pw;
        pw = nullptr;
    };

    std::unique_ptr<Widget, decltype(widgetDeleter)>
        upw(new Widget, widgetDeleter);
    std::shared_ptr<Widget> spw(new Widget, widgetDeleter);

    return 0;
}
