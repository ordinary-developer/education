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
    auto loggingDel = [] (Widget* pw) 
                      {
		          delete pw;
	              };

    auto pw = new Widget();
    // create a control block for *pw
    std::shared_ptr<Widget> spw(pw, loggingDel);
    // WRONG
    // create the 2-nd control block for *pw!
    //std::shared_ptr<Widget> spw2(pw, loggingDel);

    // RIGHT
    std::shared_ptr<Widget> spw1(new Widget, loggingDel);
    std::shared_ptr<Widget> swp2(spw1);

    return 0;
}
