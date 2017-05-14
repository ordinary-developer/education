#include <array>

int main() {
    int sz;
    const auto arraySize = sz;

    // here an error will occur
    // std::array<int, arraySize> data;
}
