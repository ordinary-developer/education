#include <functional>
#include <cassert>

int main() {
    auto times_three = [](int i) { return i * 3; };
    int forty_two{ times_three(14) };
    assert(42 == forty_two);

    std::function<int(int)> times_two{ [](int i) { return i * 2; } };

    return 0;
}
