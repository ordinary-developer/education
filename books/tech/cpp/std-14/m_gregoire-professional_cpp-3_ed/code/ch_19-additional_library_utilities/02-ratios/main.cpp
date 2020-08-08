#include <ratio>
#include <iostream>
namespace example1 {

void run() {
    typedef std::ratio<1, 60> r0;
    std::intmax_t num{ r0::num };
    std::intmax_t den{ r0::den };

    std::intmax_t const n{ 1 };
    std::intmax_t const d{ 60 };
    typedef std::ratio<n, d> r00;

    typedef std::ratio<1, 60> r1;
    typedef std::ratio<1, 30> r2;
    typedef std::ratio_add<r1, r2>::type result;
    typedef std::ratio_less<r2, r1> res;
    std::cout << std::boolalpha << res::value;
}
}


#include <ratio>
#include <iostream>
namespace example2 {
void run() {
    typedef std::ratio<1, 60> r1;
    std::cout << "1) " << r1::num << "/" << r1::den << std::endl;

    intmax_t num{ r1::num };
    intmax_t den { r1::den };
    std::cout << "2) " << num << "/" << den << std::endl;

    typedef std::ratio<1, 30> r2;
    std::cout << "3) " << r2::num << "/" << r2::den << std::endl;
    typedef std::ratio_add<r1, r2>::type result;
    std::cout << "4) " << result::num << "/" << result::den << std::endl;

    typedef std::ratio_less<r2, r1> res;
    std::cout << "5) " << std::boolalpha << res::value << std::endl;
}
}


int main() {
    example1::run();
    example2::run();

    return 0;
}
    
