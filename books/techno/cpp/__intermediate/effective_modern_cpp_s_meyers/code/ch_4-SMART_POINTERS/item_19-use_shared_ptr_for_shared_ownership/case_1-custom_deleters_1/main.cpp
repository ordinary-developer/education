#include <iostream>
#include <memory>

class Widget {
public:
    Widget() { std::cout << "Widget default constructor calling" << std::endl; }
    ~Widget() { std::cout << "Widget destructor calling" << std::endl; }
};

void makeLogEntry(Widget* pw) { }

int main() {
  auto loggingDel = [] (Widget* pw)
                    {
		        makeLogEntry(pw);
			delete pw;
		    };

  std::unique_ptr<Widget, decltype(loggingDel)> upw(new Widget, loggingDel);

  std::shared_ptr<Widget> spw(new Widget, loggingDel);

  return 0;
}
