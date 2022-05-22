#include <iostream>
#include <span>
#include <cassert>
namespace example_01 { // -> std::span

void copy_n([[maybe_unused]] const int * src, [[maybe_unused]] int * dst, [[maybe_unused]] int n) { 
    std::cout << "\"copy_n\" func" << std::endl;
}
void copy([[maybe_unused]] std::span<const int> src, [[maybe_unused]] std::span<int> dst) { 
    std::cout << "\"copy\" func" << std::endl;
}

void run() {
    int arr1[] = {1, 2, 3};
    int arr2[] = {3, 4, 5};
    copy_n(arr1, arr2, 3);
    copy(arr1, arr2);
} }


#include <iostream>
#include <utility>
namespace example_02 { // -> arithmetic utilities

void run() {
    int x = -3;
    unsigned int y = 7;


    std::cout << (x < y ? "expected" : "not expected") << std::endl;
    std::cout << (std::cmp_less(x, y) ? "expected" : "not expected") << std::endl;
} }


#include <bit>
#include <bitset>
#include <iostream>
namespace example_03 { // -> bit manipulation

void run() {
    std::uint8_t num = 0b10110010;

    std::cout << std::has_single_bit(num) << '\n';
    std::cout << std::bit_width(unsigned(5)) << '\n';
    std::cout << std::bitset<8>(std::rotl(num, 2)) << '\n';
    std::cout << std::bitset<8>(std::rotr(num, 2)) << '\n';
} }


#include <iostream>
#include <chrono>
#include <ctime>
namespace example_04 { // -> calendar and time zones

std::string toStr(const auto & time) {
    const std::time_t ctime = std::chrono::system_clock::to_time_t(time);
    std::string ret(30, '\0');
    std::strftime(&ret[0], ret.size(), "%Y-%m-%d %H:%M:%S", std::localtime(&ctime));
    return ret;
}

void run() {
    auto time = std::chrono::floor<std::chrono::milliseconds>(std::chrono::system_clock::now());

    std::cout << toStr(time) << std::endl;
} }



#include <iostream>
int main() {
    std::cout << "example 01 => [ok]" << std::endl;
    example_01::run();
    std::cout << std::endl;
    
    std::cout << "example 02 => [ok]" << std::endl;
    example_02::run();
    std::cout << std::endl;
    
    std::cout << "example 03 => [ok]" << std::endl;
    example_03::run();
    std::cout << std::endl;
    
    std::cout << "example 04 => [ok]" << std::endl;
    example_04::run();
    std::cout << std::endl;
}