#include <memory>
#include <iostream>

class Widget { };

int processWidget(std::shared_ptr<Widget> spw, int priority) { }

int computePriority() {
    throw new std::exception();
}

int main() {
    // incorrect approach
    // (may lead to a memory leak)
    try {
        processWidget(std::shared_ptr<Widget>(new Widget), 
/                     computePriority());
    } 
    catch (std::exception&) {
        std::cout << "An exception was thrown!" << std::endl;
    }

    // correct way
    try {
        processWidget(std::make_shared<Widget>(), computePriority());
    }
    catch (std::exception&) {
        std::cout << "An exception was thrown!" << std::endl;
    }

    return 0;
}
