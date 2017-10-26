#include <ctime>
#include <chrono>
#include <iostream>
#include <iomanip>
namespace example1 {
void run() {
    std::chrono::system_clock::time_point tpoint{ std::chrono::system_clock::now() };
    time_t tt{ std::chrono::system_clock::to_time_t(tpoint) };
    tm* t{ localtime(&tt) };
    //std::cout << put_time(t, "%H:%M:%S") << std::endl;
}
}

#include <ctime>
#include <chrono>
#include <iostream>
#include <iomanip>
#include <iostream>
namespace example2 {
void run() {
    std::chrono::system_clock::time_point tpoint{ std::chrono::system_clock::now() };
    time_t tt{ std::chrono::system_clock::to_time_t(tpoint) };
    tm* t = localtime(&tt);
    char buffer[80] = { 0 };
    strftime(buffer, sizeof(buffer), "%H:%M:%S", t);
    std::cout << buffer << std::endl;
}
}

#include <chrono>
#include <ratio>
#include <math.h>
namespace example3 {
void run() {
    auto start = std::chrono::system_clock::now();

    double d{0};
    for (int i{0}; i < 1000000; ++i)
        d += sqrt(sin(i) * cos(i));

    auto end = std::chrono::system_clock::now();
    auto diff = end - start;
    std::cout << std::chrono::duration<double, std::milli>(diff).count() << "ms" << std::endl;
}
}


int main() {
    example1::run();
    example2::run();
    example3::run();

    return 0;
}
