#include "Widget.hpp"
#include "Gadget.hpp"

#include <string>
#include <vector>

struct Widget::Impl {
    std::string name;
    std::vector<double> data;
    Gadget g1, g2, g3;
};

Widget::Widget() : pImpl(new Impl) { }

Widget::~Widget() {
    delete pImpl;
    pImpl = nullptr;
}
