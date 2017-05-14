#include <array>

int main(int argc, char** argv) {
    int sz;

    // here an error will occur
    // constexpr auto arraySize1 = sz;
    
    // here an error will occur
    // std::array<int, sz> data1;
    
    constexpr auto arraySize2 = 10;
    std::array<int, arraySize2> data2;
}
