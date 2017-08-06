#include <ratio>
#include <chrono>
#include <iostream>
namespace example1 {
void run() {
    std::chrono::duration<long, std::ratio<60>> d1{123};
    std::cout << d1.count() << std::endl;

    std::chrono::duration<double> d2{};
    d2 = d2.max();
    std::cout << d2.count() << std::endl;

    std::chrono::duration<long, std::ratio<60>> d3{10};
    std::chrono::duration<long, std::ratio<1>> d4{14};

    if (d3 > d4)
        std::cout << "d3 > d4" << std::endl;
    else
        std::cout << "de <= d4" << std::endl;

    ++d4;
    d4 *= 2;

    std::chrono::duration<double, std::ratio<60>> d5{ d3 + d4 };
    
    std::chrono::duration<long, std::ratio<1>> d6 = d3 + d4;
    std::cout << d3.count() << " minutes + " 
              << d4.count() << " seconds = "
              << d5.count() << " minutes or " 
              << d6.count() << " seconds" << std::endl;
    std::chrono::duration<long> d7{30};
    std::chrono::duration<double, std::ratio<50>> d8{d7};
    std::cout << d7.count() << " seconds = " 
              << d8.count() << " minutes" << std::endl;
}
}

#include <ratio>
#include <chrono>
#include <iostream>
namespace example2 {
void run() {
    auto t = std::chrono::hours{1} + std::chrono::minutes{23} + std::chrono::seconds{45};
    std::cout << std::chrono::seconds{t}.count() << " seconds" << std::endl;
}
}


int main() {
    example1::run();
    example2::run();
    
    return 0;
}
