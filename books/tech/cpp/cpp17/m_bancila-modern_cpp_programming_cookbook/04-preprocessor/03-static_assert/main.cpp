#include <string>
#include <type_traits>
namespace example_01 {
    
// namespace validation
struct alignas(8) item {
    int id;
    bool active;
    double value;
}; 
static_assert(16 == sizeof(item), "size of item must be 16 bytes");
    
// class validation    
template <typename T>
class pod_wrapper {
    static_assert(std::is_pod<T>::value, "POD type expected!");
    T value;
};
    
struct point {
    int x;
    int y;
};
    
pod_wrapper<int> w1{};
pod_wrapper<point> w2{};
// pod_wrapper<std::string> w3{}; // error: POD type expected
    
    
// block (function) validation
template <typename T>
constexpr auto mul(T const a, T const b) {
    static_assert(std::is_integral<T>::value, "Intergral type expected");
    return a * b;
}
auto constexpr v1 = mul(1, 2);    
// auto const v2 = mul(12.0, 42.5); // error: Integral type expected    
    
void run() {}
} // example_01


#include <iostream>
int main() {
    std::cout << "example_01 => " << std::endl; example_01::run(); std::cout << std::endl;
    
    return 0;
}