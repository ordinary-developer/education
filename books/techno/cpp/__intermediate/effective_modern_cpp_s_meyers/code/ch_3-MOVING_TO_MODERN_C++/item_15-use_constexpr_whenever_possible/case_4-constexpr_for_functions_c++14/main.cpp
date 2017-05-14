#include <array>
#include <string>

constexpr int pow(int base, int exp) noexcept {
    int result = 1;
    for (int i = 0; i < exp; ++i) {
        result *= base;
    }
    return result;
}

int main() {
    constexpr auto numConds = 5;
    std::array<int, pow(3, numConds)> results;

    return 0;
}
