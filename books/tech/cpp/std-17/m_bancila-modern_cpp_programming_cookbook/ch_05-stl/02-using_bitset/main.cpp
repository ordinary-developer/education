#include <bitset>
#include <string>
#include <cassert>
#include <iostream>
namespace example_01 { // -> std::bitset initializing
void run() {
    using namespace std::literals::string_literals;
    
    std::bitset<8> b1;
    assert(("00000000" == b1.to_string()));
    
    std::bitset<8> b2{10};
    assert(("00001010" == b2.to_string()));
    
    std::bitset<8> b3{"1010"s};
    assert(("00001010" == b3.to_string()));
    
    std::bitset<8> b4{
        "ooooxoxo"s, 0, std::string::npos, 'o', 'x' };
    assert(("00001010" == b4.to_string()));
    
    assert((b2 == b3 and b3 == b4));
    
    std::cout << "[ok]";
}    
} // example_01


#include <bitset>
#include <string>
#include <cassert>
#include <iostream>
namespace example_02 { // -> std::bitset testing
void run() {
    std::bitset<8> bs{10};
    
    assert(2 == bs.count()); 
    assert(bs.any());
    assert(not bs.all());
    assert(not bs.none());
    assert(not bs.test(0));
    assert(not bs[0]);
    
    std::cout << "[ok]";
}
} // example_02


#include <bitset>
#include <cassert>
#include <iostream>
namespace example_03 { // -> std::bitset modification
void run() {
    std::bitset<8> b1{42};
    std::bitset<8> b2{11};
    assert(("00101010" == b1.to_string()));
    assert(("00001011" == b2.to_string()));
    
    auto const b3 = b1 | b2;
    auto const b4 = b1 & b2;
    auto const b5 = b1 ^ b2;
    auto const b6 = ~b1;
    assert(("00101011" == b3.to_string()));
    assert(("00001010" == b4.to_string()));
    assert(("00100001" == b5.to_string()));
    assert(("11010101" == b6.to_string()));
    
    auto const b7 = b1 << 2;
    assert(("10101000" == b7.to_string()));
    auto const b8 = b1 >> 2;
    assert(("00001010" == b8.to_string()));
    
    b1.flip();
    assert(("11010101" == b1.to_string()));
    b1.flip(0);
    assert(("11010100" == b1.to_string()));
    
    b1.set(0, true);
    assert(("11010101" == b1.to_string()));
    b1.set(0, false);
    assert(("11010100" == b1.to_string()));
    
    b1.reset(2);
    assert(("11010000" == b1.to_string()));
    
    std::bitset<8> bs{42};
    auto n1 = bs.to_ulong();
    auto n2 = bs.to_ullong();
    assert(42 == n1);
    assert(42 == n2);
    
    auto const& s1 = bs.to_string();
    assert("00101010" == s1);
    auto const& s2 = bs.to_string('o', 'x');
    assert("ooxoxoxo" == s2);
     
    std::cout << "[ok]";
}
} // example_03


#include <string>
#include <cassert>
#include <iostream>
namespace example_04 { // -> an example without std::bitset
    
#define BORDER_NONE   0x00
#define BORDER_LEFT   0x01
#define BORDER_TOP    0x02
#define BORDER_RIGHT  0x04
#define BORDER_BOTTOM 0x08
    
void apply_style(unsigned int const style) {
    for (std::size_t i{BORDER_NONE}; i < BORDER_BOTTOM + 1; ++i)
        if (i & style)
            std::cout << "\napply " << i << " style\n";
}
    
void run() {
    unsigned int style = BORDER_NONE;
    
    style = BORDER_BOTTOM;
    style |= BORDER_LEFT | BORDER_RIGHT | BORDER_TOP;
    style &= ~BORDER_LEFT;
    style &= ~BORDER_RIGHT;
    apply_style(style);
    
    assert((BORDER_BOTTOM == (style & BORDER_BOTTOM)));
    std::cout << "[ok]";
}
} // example_04


#include <bitset>
#include <string>
#include <iostream>
namespace example_05 { // -> the previous example but with std::bitset
    
void apply_style(unsigned int const style) {
    for (std::size_t i{0}; i < 8 + 1; ++i)
        if (i & style)
            std::cout << "\napply " << i << " style\n";
}
    
struct border_flags {
    static int const left = 0;
    static int const top = 1;
    static int const right = 2;
    static int const bottom = 3;
};
    
    
void run() {
    std::bitset<4> style{};
    
    style.set(border_flags::bottom);
    style
        .set(border_flags::left)
        .set(border_flags::top)
        .set(border_flags::right);
    style[border_flags::left] = 0;
    style.reset(border_flags::right);
    apply_style(style.to_ulong());
    
    assert((style.test(border_flags::bottom)));
    
    std::cout << "[ok]";
}    
} // example_05


#include <bitset>
#include <vector>
#include <iostream>
namespace example_06 { // -> arbitrary 'std::bitset' to 'unsigned long'
    
template <size_t N>
std::vector<unsigned long> bitset_to_vectorulong(std::bitset<N> bs) {
    auto ret = std::vector<unsigned long>{};
    auto constexpr const size = 8 * sizeof(unsigned long);
    auto constexpr const mask = std::bitset<N>{ static_cast<unsigned long>(-1) };
    
    auto totalbits = 0;
    while (totalbits < N) {
        auto val = (bs & mask).to_ulong();
        ret.push_back(val);
        bs >>= size;
        totalbits += size;
    }
    
    return ret;
}
    
void run() {
    std::bitset<128> bs = 
        (std::bitset<128>(0xFEDC) << 96) |
        (std::bitset<128>(0xBA98) << 64) |
        (std::bitset<128>(0x7654) << 32) |
        std::bitset<128>(0x3210);
    
    std::cout << bs << std::endl;
    
    auto const ret = bitset_to_vectorulong(bs);
    for (auto const& val : ret)
        std::cout << std::hex << val << std::endl;
    
    std::cout << "[ok]";
}
} // example_06



#include <iostream>
int main() {
    std::cout << "example_01 =>" << std::endl; example_01::run(); std::cout << std::endl << std::endl;
    std::cout << "example_02 =>" << std::endl; example_02::run(); std::cout << std::endl << std::endl;
    std::cout << "example_03 =>" << std::endl; example_03::run(); std::cout << std::endl << std::endl;
    std::cout << "example_04 =>" << std::endl; example_04::run(); std::cout << std::endl << std::endl;
    std::cout << "example_05 =>" << std::endl; example_05::run(); std::cout << std::endl << std::endl;
    std::cout << "example_06 =>" << std::endl; example_06::run(); std::cout << std::endl << std::endl;
    
	return 0;
}
