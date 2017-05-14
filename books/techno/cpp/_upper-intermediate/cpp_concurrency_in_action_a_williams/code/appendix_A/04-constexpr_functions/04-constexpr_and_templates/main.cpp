template <typename T>
constexpr T sum(T a, T b) { return a + b; }

#include <string>
int main() {
    constexpr int i = sum(3, 42);
    std::string s = sum(std::string{"hello"},
                        std::string{" world"});

    return 0;
}
