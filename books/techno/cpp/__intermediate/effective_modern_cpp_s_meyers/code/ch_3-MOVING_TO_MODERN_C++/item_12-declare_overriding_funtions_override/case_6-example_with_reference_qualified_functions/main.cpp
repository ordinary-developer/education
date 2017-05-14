#include <vector>

class Widget {
    public:
        using DataType = std::vector<double>;

        // for lvalue Widgets
        DataType& data() & 
        {
            return values;
        }

        // for rvalue Widget
        DataType data() && 
        {
            return std::move(values); 
        }

    private:
        DataType values;
};

Widget makeWidget() {
    Widget widget;
    return widget;
}

int main() {
    Widget w;
    auto values1 = w.data();

    auto values2 = makeWidget().data();
}
