#include <string>

template <typename T>
void foo(T&& t) { }


int main() {
    // calling with rvalues
    // foo<int>(42)
    foo(42);

    // foo<double>(3.14159)
    foo(3.14159);

    // foo<std::string>(std::string())
    foo(std::string()); 

    // calling with lvalues
    // foo<int&>(i)
    int i = 42;
    foo(i);

    return 0;

}
