#include <iostream>
#include <memory>
#include <vector>

class Widget  : public std::enable_shared_from_this<Widget> {
public:
    template<typename... Ts>
    static std::shared_ptr<Widget> create(Ts&&... params) {
    	std::shared_ptr<Widget> ptr(new Widget());
    	return ptr;
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

private:
    Widget() { std::cout << "Default constructor calling\n"; }

};

int main() {
    std::vector<std::shared_ptr<Widget>> processedWidgets;
  
    std::shared_ptr<Widget> pw1 =  Widget::create<int, double>(5, 5.0);
    pw1->process(processedWidgets);

    return 0;
}
