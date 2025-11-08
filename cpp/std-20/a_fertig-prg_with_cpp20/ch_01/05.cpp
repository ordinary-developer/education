#include <array>
#include <iostream>
#include <cassert>
namespace example_01 {

constexpr auto GetSize(const auto& t = {})
{
    return t.size();
}

template <typename T, std::size_t N>
concept SizeCheck = (GetSize<T>() == N);

void SendOnePing(const SizeCheck<1> auto& cont)
{
    assert(true);
}


void run() {
    std::array<int, 1> data;
    SendOnePing(data);
    std::cout << "[ ok ] example 01" << std::endl;
}

} // example_01



int main() {
    example_01::run();
}