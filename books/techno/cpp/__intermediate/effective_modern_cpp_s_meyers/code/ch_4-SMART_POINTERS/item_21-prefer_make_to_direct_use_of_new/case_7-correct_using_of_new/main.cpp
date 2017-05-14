#include <memory>

class Widget { };

void cusDel(Widget *ptr) {
    delete ptr;
    ptr = nullptr;
}

void processWidget(std::shared_ptr<Widget> spw, int priority) {
    // do nothing
}

int computePriority() {
    return 1;
}

int main() {
    // exception unsafe call
    processWidget(
            std::shared_ptr<Widget>(new Widget, cusDel),
            computePriority());

    // safe way
    std::shared_ptr<Widget> spw(new Widget, cusDel);
    processWidget(spw, computePriority());

    // another safe way
    processWidget(std::move(spw), computePriority());

    return 0;
}
