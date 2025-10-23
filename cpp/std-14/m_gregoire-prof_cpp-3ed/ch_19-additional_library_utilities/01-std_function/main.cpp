#include <functional>
#include <string>
#include <iostream>
namespace example1 {

void func(int num, std::string const& str) {
    std::cout << "func(" << num << ", " << str << ")" << std::endl;
}

void run() {
    std::function<void(int, std::string const&)> f1{ func };
    f1(1, "test");
}

} // namespace example1

#include <functional>
#include <vector>
#include <iostream>
#include <numeric>
#include <algorithm>
namespace example2 {

bool isEven(int num) { return 0 == num % 2; }

void run() {
    std::vector<int> vec(10);
    std::iota(std::begin(vec), std::end(vec), 0);
    std::function<bool(int)> f2{ isEven };
    int count = std::count_if(std::begin(vec), std::end(vec), f2);
    std::cout << count << " even numbers" << std::endl;
}

} // namespace example2


#include <functional>
#include <vector>
#include <numeric>
#include <iostream>
namespace example3 {

void process(std::vector<int> const& vec, std::function<void(int)> f) {
    for (auto& i : vec)
        f(i);
}

void print(int num) { std::cout << num << " "; }

void run() {
    std::vector<int> vec(10);
    std::iota(std::begin(vec), std::end(vec), 0);
    process(vec, print);
    std::cout << std::endl;

    int sum{0};
    process(vec, [&sum](int num) { sum += num; });
    std::cout << "sum = " << sum << std::endl;
}
    
}


int main() {
    example1::run();
    example2::run();
    example3::run();

    return 0;
}

