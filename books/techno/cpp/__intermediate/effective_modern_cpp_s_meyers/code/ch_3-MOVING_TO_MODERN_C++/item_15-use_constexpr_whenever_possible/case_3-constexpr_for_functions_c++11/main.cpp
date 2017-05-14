#include <array>
#include <string>

constexpr int pow(int base, int exp) noexcept {
    return (0 == exp ? 1 : base * pow(base, exp - 1));
}

int readFromDB(const std::wstring& selector) {
    if (std::wstring(L"base") == selector) {
        return 10;
    }
    else if (std::wstring(L"exponent") == selector) {
        return 20;
    }
    else {
        return 0;
    }
}

int main() {
    constexpr auto numConds = 5;
    std::array<int, pow(3, numConds)> results;

    auto base = readFromDB(L"base");
    auto exp = readFromDB(L"exponent");
    auto baseToExp = pow(base, exp);
}

