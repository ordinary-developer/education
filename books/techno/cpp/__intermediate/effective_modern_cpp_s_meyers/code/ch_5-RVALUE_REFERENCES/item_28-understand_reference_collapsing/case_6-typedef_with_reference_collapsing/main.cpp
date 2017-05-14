template <typename T>
class Widget {
    public:
        typedef T&& RvalueRefToT;
};


int main() {
    // here "typedef int& RvalueRefToT" will be
    Widget<int&> w;

    return 0;
}
