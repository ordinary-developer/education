#include <iostream>
#include <memory>
#include <vector>

class Widget {
public:
    Widget() {
        std::cout << "Default constructor calling\n";
    }

    ~Widget() {
    	std::cout << "Destructor calling\n";
    }

    Widget(const Widget& rhs) {
    	std::cout << "Copy constructor calling\n";
    }

    Widget& operator= (const Widget& rhs) {
    	std::cout << "Copy assignment operator calling\n";
	return *this;
    }

    Widget(const Widget&& rhs) {
    	std::cout << "Move constructor calling\n";
    }

    void process(std::vector<std::shared_ptr<Widget>>& processWidgets) {
    	// WRONG
    	// processWidgets.emplace_back(this);
    }
};

int main() {
    std::vector<std::shared_ptr<Widget>> processWidgets;

    Widget widget;
    Widget* pwidget = new Widget();

    widget.process(processWidgets);
    pwidget->process(processWidgets);

    return 0;
}
