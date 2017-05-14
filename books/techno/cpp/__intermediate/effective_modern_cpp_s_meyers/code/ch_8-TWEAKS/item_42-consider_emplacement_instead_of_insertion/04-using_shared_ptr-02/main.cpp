#include <memory>
#include <list>

class Widget { };
void killWidget(Widget* pWidget) { }

int main() {
    std::list<std::shared_ptr<Widget>> ptrs;

    std::shared_ptr<Widget> spw1(new Widget,
                                killWidget);
    ptrs.push_back(std::move(spw1));

    std::shared_ptr<Widget> spw2(new Widget,
                                 killWidget);
    ptr.emplace_back(std::move(spw));

    return 0;
}
