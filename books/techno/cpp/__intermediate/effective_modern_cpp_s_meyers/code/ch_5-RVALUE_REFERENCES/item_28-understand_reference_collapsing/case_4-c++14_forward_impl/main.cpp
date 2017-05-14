#include <type_traits>


// C++14 implementation
template <typename T>
T&& my_forward(std::remove_reference_t<T>& param) {
    return static_cast<T&&>(param);
}

template <typename T>
void f2(T&& fParam) {
}

template <typename T>
void f1(T&& fParam) {
    f2(my_forward<T>(fParam));
}



class Widget { };

Widget makeWidget() 
{
    Widget w;
    return w;
}


int main() {
    Widget w;
    f1(w);

    f1(makeWidget());

    return 0;
}

