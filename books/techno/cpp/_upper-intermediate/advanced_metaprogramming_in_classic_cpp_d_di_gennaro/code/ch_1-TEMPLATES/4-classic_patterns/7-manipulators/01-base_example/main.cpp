#include <cmath>
constexpr double pi() { return std::atan(1) * 4; }

#include <iostream>
#include <ostream>
namespace example_1 {
    struct precision_proxy_t {
        int prec;
    };

    inline std::ostream& operator<<(std::ostream& o,    
                                    precision_proxy_t p) {
        o.precision(p.prec);
        return o;
    }

    precision_proxy_t set_precision(int p) {
        precision_proxy_t result{ p };
        return result;
    }


    void run() {
        std::cout << set_precision(12) << pi() << std::endl;
    }
}


#include <ostream>
#include <iostream>
namespace example_2 {
    template <typename T, std::ostream& (*FUNC)(std::ostream&, T)>
    struct proxy {
        proxy(const T& a) : arg(a) { }

        T arg;
    };
    
    template <typename T, std::ostream& (*FUNC)(std::ostream&, T)>
    inline std::ostream& operator<<(std::ostream& o, proxy<T, FUNC> p) 
    {
        return FUNC(o, p.arg);
    }
    

    std::ostream& global_setpr(std::ostream& o, int prec) {
        o.precision(prec);
        return o;
    }

    proxy<int, global_setpr> set_precision(int p) {
        return { p };
    }

    
    void run() {
        std::cout << set_precision(12) << pi() << std::endl;
    }
}


#include <ostream>
#include <iostream>
#include <iomanip>
namespace example_3 {
    template <typename T>
    struct proxy {
        T arg;
        std::ostream& (*FUNC)(std::ostream&, T);
    };

    template <typename T>
    inline std::ostream& operator<<(std::ostream& o, proxy<T> p) 
    {
        return p.FUNC(o, p.arg);
    }

    std::ostream& global_setpr(std::ostream& o, int prec) {
        o.precision(prec);
        return o;
    }

    proxy<int> set_precision(int p) {
        return { p, global_setpr };
    }

    proxy<int> set_precision2(int p) {
        return { p, 
                 [](std::ostream& o, int prec) -> std::ostream& {
                    o.precision(prec);
                    return o;
                 }};
    }


    void run() {
        std::cout << set_precision(12) << pi() << std::endl;
        std::cout << set_precision2(12) << pi() << std::endl;
    }
}


int main() {
    example_1::run();
    example_2::run();
    example_3::run();

    return 0;
}
