#include "Widget.cpp"

int main() {
    Widget w1;
    auto w2(std::move(w1));
    w1 = std::move(w2);

    return 0;
}
