#include <iostream>
#include <vector>
namespace example_01 {

void run() {
    auto v = std::vector<int>{3, 4, 5};
    const std::vector<int>::size_type size = v.size();
    std::cout << "[ ok ] example 01" << std::endl;
}

} // example 01



#include <iostream>
#include <vector>
namespace example_02 {

void run() {
    auto v = std::vector<int>{3, 4, 5};
    const auto size = v.size();
    std::cout << "[ ok ] example 02" << std::endl;
}

} // example 02



#include <concepts>
#include <iostream>
#include <vector>
namespace example_03 {

void run() {
    auto v = std::vector<int>{3, 4, 5};
    const std::integral auto size = v.size();
    std::cout << "[ ok ] example 03" << std::endl;
}

}



int main() {
    example_01::run();
    example_02::run();
    example_03::run();
}