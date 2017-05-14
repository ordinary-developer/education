#include <initializer_list>

int makeSum(std::initializer_list<int> lst) {
    int total = 0;
    for (const auto& value : lst) {
        total += value;
    }
    return total;
}

auto main() -> int {
    int a = makeSum({1, 2, 3});
    int b = makeSum({10, 20, 30, 40, 50, 60});

    //here a compile warning will be
    // int c = makeSum({1, 2, 3.0});
    return 0;
}
