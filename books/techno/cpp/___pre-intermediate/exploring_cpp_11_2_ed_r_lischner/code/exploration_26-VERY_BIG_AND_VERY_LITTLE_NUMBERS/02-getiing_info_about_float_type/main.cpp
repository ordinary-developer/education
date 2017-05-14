#include <iostream>
#include <limits>
#include <locale>

int main() {
    std::cout.imbue(std::locale{""});
    std::cout << std::boolalpha;
    typedef float T;

    std::cout << "min=" << std::numeric_limits<T>::min() << '\n'
              << "max=" << std::numeric_limits<T>::max() << '\n'
              << "IEC 60559? "
              << std::numeric_limits<T>::is_iec559 << '\n'
              << "max exponent=" 
              << std::numeric_limits<T>::max_exponent << '\n'
              << "min exponent="
              << std::numeric_limits<T>::min_exponent << '\n'
              << "matissa places=" 
              << std::numeric_limits<T>::digits << '\n'
              << "radix=" << std::numeric_limits<T>::radix << '\n'
              << "has infinity? "
              << std::numeric_limits<T>::has_infinity << '\n'
              << "has quiet NaN? " 
              << std::numeric_limits<T>::has_quiet_NaN << '\n'
              << "has signaling NaN? "
              << std::numeric_limits<T>::has_signaling_NaN << '\n';

    if (std::numeric_limits<T>::has_infinity) {
        T zero{ 0 };
        T one { 1 };
        T inf{ std::numeric_limits<T>::infinity() };
        if (one / zero == inf)
            std::cout << "1.0/0.0 = infinity\n";
        if (inf + inf == inf)
            std::cout << "infinity + infinity = infinity\n";
    }

    if (std::numeric_limits<T>::has_quiet_NaN) {
        T zero{};
        T inf{ std::numeric_limits<T>::infinity() };
        std::cout << "zero/zero = " << zero/zero << '\n';
        std::cout << "inf/inf = " << inf/inf << '\n';
    }

    return 0;
}

