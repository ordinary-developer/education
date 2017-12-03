#include <tuple>
#include <memory>
namespace example01 {

class matrix {};
class vector {};

std::tuple<matrix, vector> lu1(matrix const& A) {
    matrix LU{A};
    vector p{};

    return std::tuple<matrix, vector>{ LU, p };
}

std::tuple<matrix, vector> lu2(matrix const& A) {
    matrix LU{A};
    vector p{};

    return std::make_tuple(LU, p);
}

std::tuple<matrix, vector> lu3(matrix const& A) {
    matrix LU{A};
    vector p{};

    return std::make_tuple(std::move(LU), std::move(p));
}

void run() {
    matrix A{};

    std::tuple<matrix, vector> t1{ lu1(A) };
    matrix LU1{ std::get<0>(t1) };
    vector p1{ std::get<1>(t1) };

    auto t2 = lu2(A);
    auto LU2 = std::get<matrix>(t2);
    auto p2 = std::get<vector>(t2);

    matrix LU{};
    vector p{};
    std::tie(LU, p) = lu3(A);
}

}

#include <functional>
#include <iostream>
#include <vector>
#include <cmath>
namespace example02 {

double add(double x, double y) { return x + y; }

inline double sub(double x, double y) { return x - y; }

struct mult {
    double operator()(double x, double y) const { return x * y; }
};

template <typename Value>
struct power {
    Value operator() (Value x, Value y) const { return std::pow(x, y); }
};

struct greater_t {
    template <typename Value>
    Value operator()(Value x, Value y) const { return x > y; }
} greater_than;

void run() {
    using bin_fun = std::function<double(double, double)>;

    bin_fun f = &add;
    std::cout << "f(6, 3) = " << f(6, 3) << std::endl;

    std::vector<bin_fun> functions{};
    functions.push_back(&add);
    functions.push_back(add);
    functions.push_back(sub);
    functions.push_back(mult{});
    functions.push_back(power<double>{});
    functions.push_back(greater_than);
    functions.push_back([](double x, double y) { return x / y; });
    for (auto& f : functions)
        std::cout << "f(6, 3) = " << f(6, 3) << std::endl;
}
}

#include <functional>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <map>
namespace example03 {

void run() {
    std::vector<std::reference_wrapper<std::vector<int>>> vv{};

    std::vector<int> v1{ 2, 3, 4}, v2{ 5, 6 }, v3{ 7, 8 };
    vv.push_back(v1);
    vv.push_back(v2);
    vv.push_back(v3);
    vv.push_back(v2);
    vv.push_back(v1);

    for (auto const& vr : vv) {
        std::copy(std::cbegin(vr.get()),     
                  std::cend(vr.get()),
                  std::ostream_iterator<int>{ std::cout, ", "});
        std::cout << std::endl;
    }

    for (std::vector<int> const& vr : vv) {
        std::copy(std::cbegin(vr),
                  std::cend(vr),
                  std::ostream_iterator<int>{ std::cout, ", "});
        std::cout << std::endl;
    }
}

}

#include <functional>
#include <vector>
#include <map>
#include <utility>
#include <iostream>
#include <iterator>
#include <algorithm>
namespace example04 {

void run() {
    std::vector<int> v1{ 2, 3, 4}, v2{ 5, 6 }, v3{ 7, 8 };

    std::map<int, decltype(std::ref(v1))> mv{};
    mv.emplace(std::make_pair(4, std::ref(v1)));
    mv.emplace(std::make_pair(7, std::ref(v2)));
    mv.insert(std::make_pair(8, std::ref(v3)));
    mv.insert(std::make_pair(9, std::ref(v2)));

    for (auto const& vr : mv) {
        for (auto i : vr.second.get())
            std::cout << i << ", ";
        std::cout << std::endl;
    }

    auto& e7 = mv.find(7)->second;
    std::copy(std::cbegin(e7.get()),
              std::cend(e7.get()),
              std::ostream_iterator<int>{std::cout, ", "});
    std::cout << std::endl;
}
}


int main() {
    example01::run();
    example02::run();
    example03::run();
    example04::run();

    return 0;
}
