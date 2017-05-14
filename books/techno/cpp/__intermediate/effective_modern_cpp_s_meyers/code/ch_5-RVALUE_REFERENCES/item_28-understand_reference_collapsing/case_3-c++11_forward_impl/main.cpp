#include <type_traits>


// C++11 implementation
template <typename T>
T&& my_forward(typename std::remove_reference<T>::type& param) {
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

