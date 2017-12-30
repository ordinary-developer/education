#include <chrono>
#include <ctime>
#include <iostream>
namespace example01 {
void run() {
    std::chrono::time_point<std::chrono::system_clock> now =
        std::chrono::system_clock::now();
    std::chrono::time_point<std::chrono::system_clock> then = 
        now + std::chrono::hours{2};

    time_t then_time = std::chrono::system_clock::to_time_t(then);

    std::cout << "Darling, I'll be with you at " << ctime(&then_time) 
              << std::endl;
    
}
} // namespace example01

#include <cstdlib>
#include <chrono>
#include <iostream>
namespace example02 {
inline double my_root(double x, double eps = 1e-12) {
    double sq{ 1.0 }, sqo{};
    do {
        sqo = sq;
        sq = 0.5 * (sqo + x / sqo);
    } while (abs(sq - sqo) > eps);
    return sqo;
}

void run() {
    std::chrono::time_point<std::chrono::steady_clock> start = 
        std::chrono::steady_clock::now();
    double r3{};
    int rep = 10;
    for (int i{0}; i < rep; ++i)
        r3 = my_root(3.0);
    auto end = std::chrono::steady_clock::now();
    std::cout << "my_root(3.0) = " << r3 << ", the calculation took "
              << ((end - start) / rep).count() << " ticks\n";
    std::cout << "my_root(3.0) = " << r3 << ", the calculation took "
              << std::chrono::duration_cast<std::chrono::microseconds>
                    ((end - start) / rep).count() << std::endl;
    std::cout << "my_root(3.0) = " << r3 << ", the calculation took "
              << std::chrono::duration_cast<std::chrono::nanoseconds>
                    ((end - start) / rep).count() / 1000 << std::endl;
}
} // namespace example02

#include <chrono>
#include <iostream>
namespace example03 {
void run() {
    using P = std::chrono::steady_clock::period;
    std::cout << "Resolution is  " << double{P::num} / P::den << "s.\n";
} // namespace example02

int main() {
    example01::run();
    example02::run();
    example03::run();

    return 0;
}
