#include "framework1.hpp"
#include "framework2.hpp"
#include "framework3.hpp"


int main() {
    framework3::EmptyString s;

    // here a compile error will be
    // framework2::do_something(s);

    return 0;
}
