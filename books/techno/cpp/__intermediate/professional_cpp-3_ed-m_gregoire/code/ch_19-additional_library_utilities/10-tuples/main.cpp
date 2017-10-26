#include <utility>
#include <iostream>
#include <string>
namespace example1 {
void run() {
    std::pair<int, std::string> p1{ 16, "Hello World" };
    std::pair<bool, float> p2{ true, 0.123f };
    std::cout << "p1 = (" << p1.first << ", " << p1.second << ")" << std::endl;
    std::cout << "p2 = (" << p2.first << ", " << p2.second << ")" << std::endl;
}
}

#include <tuple>
#include <iostream>
#include <string>
#include <typeinfo>
namespace example2 {
void run() {
    using MyTuple = std::tuple<int, std::string, bool>;
    MyTuple t1{ 16, "Test", true };

    std::cout << "t1 = (" << std::get<0>(t1) << ", " << std::get<1>(t1) << ", "
              << std::get<2>(t1) << ")" << std::endl; 

    std::cout << "Type of get<1>(t1) = " << typeid(std::get<1>(t1)).name()
              << std::endl;

    std::cout << "String = " << std::get<std::string>(t1) << std::endl;

    std::cout << "Tuple Size = " << std::tuple_size<MyTuple>::value << std::endl;
}
}

#include <tuple>
#include <functional>
#include <string>
#include <iostream>
namespace example3 {
void run() {
    double d{ 3.14 };
    std::string str1{ "Test" };
    auto t2 = std::make_tuple(16, std::ref(d), std::ref(str1), std::cref(str1));

    std::cout << "d = " << d << std::endl;
    std::get<1>(t2) *= 2;
    std::cout << "d = " << d << std::endl;

    std::cout << "str = " << str1 << std::endl;
    std::get<2>(t2) = "Hello";
    std::cout << "str = " << str1 << std::endl;
}
}

#include <tuple>
#include <string>
#include <vector>
namespace example4 {
void run() {
    std::tuple<std::string, std::vector<int>> t1{ "test", { 1, 2, 3, 4 } };
}
}

#include <tuple>
#include <string>
#include <iostream>
namespace example5 {
void run() {
    std::tuple<int, std::string, bool> t1{ 16, "Test", true };
    int i{0};
    std::string str{};
    bool b{ false };

    std::cout << "Before: i = " << i 
              << ", str = \"" << str 
              << "\", b = " << b << std::endl;
    std::tie(i, str, b) = t1;
    std::cout << "After: i = " << i 
              << ", str = \"" << str 
              << "\", b = " << b << std::endl;
}
}

#include <tuple>
#include <string>
namespace example6 {
void run() {
    std::tuple<int, std::string, bool> t1{ 16, "Test", true };
    std::tuple<double, std::string> t2{ 3.14, "string 2" };
    auto t3 = std::tuple_cat(t1, t2);
}
}

#include <tuple>
#include <string>
#include <iostream>
namespace example7 {
void run() {
    std::tuple<int, std::string> t1{ 123, "def" };
    std::tuple<int, std::string> t2{ 123, "abc" };
    std::cout << (t1 < t2 ? "t1 < t2" : "t1 >= t2") << std::endl;
}
}


int main() {
    example1::run();
    example2::run();
    example3::run();
    example4::run();
    example5::run();
    example6::run();
    example7::run();

    return 0;
}

