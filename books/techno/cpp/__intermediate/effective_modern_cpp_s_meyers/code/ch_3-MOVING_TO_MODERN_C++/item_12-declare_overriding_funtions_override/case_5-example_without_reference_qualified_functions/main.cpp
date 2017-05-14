#include <vector>

class Widget {
    public:
        using DataType = std::vector<double>;

        DataType& data() { return values; }

    private:
        DataType values;
};


Widget makeWidget()
{
    Widget widget;
    return widget;
}

int main() {
    Widget w;
    auto values1 = w.data();

    auto values2 = makeWidget().data();
}
