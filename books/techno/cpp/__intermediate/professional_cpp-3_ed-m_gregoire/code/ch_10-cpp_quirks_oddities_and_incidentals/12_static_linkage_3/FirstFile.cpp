// without this string the program will not compile
#include "AnotherFile.cpp"

void f();
auto main() -> int {
    f();
    return 0;
}
