#include <iostream>
#include <memory>

class Widget { };

int main() {
    auto spw = std::make_shared<Widget>();
    std::weak_ptr<Widget> wpw(spw);

    spw = nullptr;

    std::shared_ptr<Widget> spw1 = wpw.lock();
    if (nullptr == spw1) {
        std::cout << "spw1 is null\n";
    }
    auto spw2 = wpw.lock();
    if (nullptr == spw2) {
      	std::cout << "spw2 is null\n";
    }

    try {
    	std::shared_ptr<Widget> spw3(wpw);
    }
    catch (std::bad_weak_ptr&) {
        std::cout << "bad_weak_ptr was thrown\n";
    }

    return 0;
}
