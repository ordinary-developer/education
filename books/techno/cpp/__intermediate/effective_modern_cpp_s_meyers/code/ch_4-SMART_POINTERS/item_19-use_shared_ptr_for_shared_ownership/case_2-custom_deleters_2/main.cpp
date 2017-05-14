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
};

int main() {
  auto customDeleter1 = [] (Widget* pw) { delete pw; };
  auto customDeleter2 = [] (Widget* pw) { delete pw; };

  std::shared_ptr<Widget> pw1(new Widget, customDeleter1);
  std::shared_ptr<Widget> pw2(new Widget, customDeleter2);

  std::vector<std::shared_ptr<Widget>> vpw { pw1, pw2 };

  return 0;
}
