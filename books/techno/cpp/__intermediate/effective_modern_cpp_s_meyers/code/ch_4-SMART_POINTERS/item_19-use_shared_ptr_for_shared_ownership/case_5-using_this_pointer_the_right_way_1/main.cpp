#include <iostream>
#include <memory>
#include <vector>

class Widget : public std::enable_shared_from_this<Widget> {
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

    void process(std::vector<std::shared_ptr<Widget>>& processedWidgets) {
    	// RIGHT
	processedWidgets.emplace_back(shared_from_this());
    }
};

int main() {
    std::vector<std::shared_ptr<Widget>> processedWidgets;

    // Error: 
    // a control block must be alread exist
    // (i.e., at least one shared_ptr must be already exist)
    // Widget widget;
    // Widget* pwidget = new Widget();
    // widget.process(processedWidgets);
    // pwidget->process(processWidgets);

    std::shared_ptr<Widget> pw1(new Widget());
    std::shared_ptr<Widget> pw2 = std::make_shared<Widget>();

    pw1->process(processedWidgets);
    pw2->process(processedWidgets);

    return 0;
}
