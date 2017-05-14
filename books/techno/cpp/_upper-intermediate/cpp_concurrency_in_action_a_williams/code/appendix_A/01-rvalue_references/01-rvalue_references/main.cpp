#include <cassert>
#include <string>

void print(const std::string& s) { }

int main() {
    int var = 42;
    int& ref = var;
    ref = 99;
    assert(var == 99);

    // will not compile
    // int& i = 42;

    const int& i1 = 42;
    int const& i2 = 42;

    print("hello");

    int&& i = 42;

    int j = 42;
    // will not compile
    //int&& k = j;

    return 0;
}
