#include <vector>
#include <iostream>

void process_copy_1(const std::vector<int> vec_) {
    std::vector<int> vec(vec_);
    vec.push_back(42);
}

void process_copy_2(std::vector<int>&& vec) {
    vec.push_back(42);
}

void func1() {
    std::vector<int> vec = { 1, 2, 3, 4, 5 };
    process_copy_1(vec);
    std::cout << vec.size() << std::endl;
}

void func2() {
    process_copy_2({ 1, 2, 3, 4, 5 });
}

void func3() {
    std::vector<int> vec = { 1, 2, 3, 4, 5 };
    process_copy_2(std::move(vec));
    std::cout << vec.size() << std::endl;
}

int main() {
    func1();
    func2();
    func3();

    return 0;
}
