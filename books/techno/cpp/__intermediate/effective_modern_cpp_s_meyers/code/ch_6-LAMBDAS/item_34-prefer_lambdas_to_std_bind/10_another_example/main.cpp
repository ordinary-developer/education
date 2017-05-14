#include <functional>
// a dump class
class Widget { };

// compression level
enum class CompLevel { Low, Normal, High };

Widget compress(const Widget& w, CompLevel lev) {
    return Widget();
}

using namespace std::placeholders;
int main() {
    Widget w;

    // pass by value
    auto compressRateB = std::bind(compress, w, _1);

    // pass by ref
    auto compressRateB2 = std::bind(compress, std::ref(w), _1);

    compressRateB(CompLevel::High);
    compressRateB2(CompLevel::High);

    // using a lambda
    auto compressRateL = [w](CompLevel lev)
    {
        return compress(w, lev);
    };

    compressRateL(CompLevel::High);

    return 0;
}

