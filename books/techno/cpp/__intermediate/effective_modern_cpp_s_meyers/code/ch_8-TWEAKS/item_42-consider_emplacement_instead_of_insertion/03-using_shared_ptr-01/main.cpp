#include <memory>
#include <list>

class Widget { };
void killWidget(Widget* pWidget) { 
    delete pWidget;
    pWidget = nullptr;
}

int main() {
    std::list<std::shared_ptr<Widget>> ptrs;

    ptrs.push_back(std::shared_ptr<Widget>(new Widget,
                                           killWidget));
    ptrs.push_back({ new Widget, killWidget });

    ptrs.emplace_back(new Widget, killWidget);

    return 0;
}
