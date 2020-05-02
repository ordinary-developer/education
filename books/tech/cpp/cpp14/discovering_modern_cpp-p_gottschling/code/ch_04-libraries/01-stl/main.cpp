#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
namespace example01 {
void run() {
    std::vector<double> vec{ 1, 2, 3, 4, 5 };
    std::list<double> lst{ 1, 2, 3, 4, 5 };
    double vec_sum = std::accumulate(std::begin(vec), std::end(vec), 0.0);
    double lst_sum = std::accumulate(std::begin(lst), std::end(lst), 0.0);
    std::cout << "vec_sum: " << vec_sum << std::endl;
    std::cout << "lst_sum: " << lst_sum << std::endl;
}
} // namespace example01

#include <iostream>
#include <list>
namespace example02 {
void run() {
    std::list<int> l1{ 3, 5, 9, 7 };
    for (auto it = std::begin(l1), e = std::end(l1); it != e; ++it) {
        int i = *it;
        std::cout << i << std::endl;
    }

    const std::list<int>& l2 = l1;
    for (auto it = std::begin(l2), e = std::end(l2); it != e; ++it) {
        int i = *it;
        std::cout << i << std::endl;
    }

    std::list<int> l3{ 3, 5, 9, 7 };
    for (auto it = std::begin(const_cast<const std::list<int>&>(l3)),
               e = std::end(const_cast<const std::list<int>&>(l3));
         it != e;
         ++it)
    {
        int i = *it;
        std::cout << i << std::endl;
    }

    // is not implemented in my compiler
    /*
    for (auto it = std::cbegin(l); it != std::cend(l); ++it) {
        int i = *it;
        std::cout << i << std::endl;
    }
    */

    std::list<int> l4{ 3, 5, 9, 7 };
    for (auto i : l4)
        std::cout << i << std::endl;

    std::list<int> l5{ 3, 5, 9, 7 };
    for (auto& i : l5)
        std::cout << i << std::endl;

    std::list<int> l6{ 3, 5, 9, 7 };
    for (auto const& i : l6)
        std::cout << i << std::endl;
}
} // namespace example02

#include <vector>
#include <iostream>
namespace example03 {
void run() {
    std::vector<int> v1{ 3, 4, 7, 9};
    for (std::vector<int>::size_type i{0}; i < v1.size(); ++i)
        v1[i] *= 2;
    for (auto& x : v1)
        x *= 2;
    for (auto const& x : v1)
        std::cout << x << ", ";
    std::cout << std::endl;

    std::vector<int> v2{};
    for (int i{0}; i < 100; ++i)
        v2.push_back(i);
    for (auto const& x : v2)
        std::cout << x << ", ";
    std::cout << std::endl;
}
} // namespace example03

#include <iostream>
#include <vector>
#include <algorithm>
namespace example04 {
void run() {
    std::vector<int> v{3, 4, 7, 9};
    auto it = std::find(v.begin(), v.end(), 4);
    std::cout << "After " << *it << " commes " << *(it + 1) << std::endl;
    v.insert(it + 1, 5);
    v.erase(v.begin());
    std::cout << "Size = " << v.size() << ", capacity = "
              << v.capacity() << std::endl;
    v.shrink_to_fit();
    v.push_back(7);
    for (auto i : v)
        std::cout << i << ",";
    std::cout << std::endl;
}
} // namespace example04

#include <iostream>
#include <vector>
namespace example05 {

struct matrix {
    matrix(int width, int height) : width{ width }, height{ height } {}

    int width, height;
};

void run() {
    std::vector<matrix> v{};
    v.push_back(matrix{ 3, 7 });
    v.emplace_back(7, 9);
}

} // namespace example05

#include <deque>
#include <iostream>
namespace example06 {

struct matrix {};

struct parameters {};

struct solver {
    solver(matrix const& theMatrix, parameters const& theParameters)
        : matrix_{ theMatrix }, parameters_{ theParameters } {}
    solver(solver const&) = delete;
    solver(solver&&) = delete;

    const matrix& matrix_;
    const parameters& parameters_;
};

// dumb function
void solve_x(solver const&) {}

void run() {
    parameters p1{}, p2{}, p3{};
    matrix A{}, B{}, C{};
    std::deque<solver> solvers{};

    solvers.emplace_back(B, p1);
    solvers.emplace_back(C, p2);
    solvers.emplace_front(A, p3);

    for (auto& s : solvers)
        solve_x(s);
}
} // namespace example06

#include <list>
#include <iostream>
#include <algorithm>
namespace example07 {
void run() {
    std::list<int> l{ 3, 4, 7, 9 };
    auto it1 = std::find(std::begin(l), std::end(l), 4);
    auto it2 = std::find(std::begin(l), std::end(l), 7);
    l.erase(it1);
    std::cout << "it2 still points to " << *it2 << std::endl;
}
} // namespace example07

#include <set>
#include <iostream>
namespace example08 {
void run() {
    std::set<int> s{ 1, 3, 4, 7, 9 };
    s.insert(5);
    for (int i{0}; i < 6; ++i)
        std::cout << i << " appears " << s.count(i) << " times" << '\n';
}
} // namespace example08

#include <set>
#include <iostream>
namespace example09 {

void run() {
    std::multiset<int> s{ 1, 3, 4, 7, 9, 1, 1, 4 };
    s.insert(4);
    for (int i{0}; i < 6; ++i)
        std::cout << i << " appears " << s.count(i) << " times" << '\n';
}

} // namespace example09

#include <map>
#include <string>
#include <iostream>
namespace example10 {
void run() {
    std::map<std::string, double> constants =
        {{"e", 2.7}, {"pi", 3.14}, {"h", 6.6e-34}};
    std::cout << "The Planck constant is " << constants["h"] << std::endl;

    constants["c"] = 299792458;

    std::cout << "The Coulomb constant is " << constants["k"] << '\n';

    std::cout << "The value of pi is " 
              << constants.find("pi")->second << '\n';

    auto it_phi = constants.find("phi");
    if (constants.end() != it_phi)
        std::cout << "Golden ratio is " << it_phi->second << '\n';

    std::cout << "The Euler constant is "
              << constants.at("e") << "\n\n";

    for (auto& c : constants)
        std::cout << "The value of " << c.first << " is "
                  << c.second << '\n';
}
} // namespace example10

#include <map>
#include <iostream>
namespace example11 {
void run() {
    std::multimap<int, double> mm = 
        {{3, 1.3}, {2, 4.1}, {3, 1.8}, {4, 9.2}, {3, 1.5}};
    for (auto it = mm.lower_bound(3), end = mm.upper_bound(3);
         it != end;
         ++it)
    {
        std::cout << "The value is " << it->second << '\n';
    }
}
} // namespace example11

#include <unordered_map>
#include <string>
#include <iostream>
namespace example12 {
void run() {
    std::unordered_map<std::string, double> constants =
        {{"e", 2.7}, {"pi", 3.14}, {"h", 6.6e-34}};
    std::cout << "The Planck constant is " << constants["h"] << '\n';
    constants["c"] = 299792458;
    std::cout << "The Euler constant is " << constants.at("e") << '\n';
}
} // namespace example12

#include <vector>
#include <iostream>
namespace example13 {
template <typename InputIterator, typename T>
InputIterator my_find(InputIterator first, 
                      InputIterator last, 
                      T const& value)
{
    while (first != last and *first != value)
        ++first;
    return first;
}
void run() {
    std::vector<int> v1{ 1, 2, 3, 4, 5 };
    auto it1 = my_find(v1.cbegin(), v1.cend(), 5);
    std::cout << *it1 << std::endl;

    std::vector<int> v2{ 1, 2, 3, 4, 5 };
    auto it2 = my_find(std::begin(v2), std::end(v2), 5);
    *it2 = 7;
    for (auto const& element : v2)
        std::cout << element << ", ";
    std::cout << std::endl;
}
} // namespace example13

#include <vector>
#include <algorithm>
#include <iostream>
namespace example14 {
void run() {
    std::vector<int> seq = {3, 4, 7, 9, 2, 5, 7, 8 };
    auto it = std::find(seq.begin(), seq.end(), 7);
    auto end = std::find(it + 1, seq.end(), 7);
    for (auto past = end + 1; it != past; ++it)
        std::cout << *it << ' ';
    std::cout << std::endl;
}
} // namespace example14

#include <list>
#include <algorithm>
#include <iostream>
namespace example15 {
void run() {
    std::list<int> seq = { 3, 4, 7, 9, 2, 5, 7, 8 };
    auto it = std::find(seq.begin(), seq.end(), 7);
    auto it2 = it;
    ++it2;
    auto end = std::find(it2, seq.end(), 7);
    ++end;
    for (; it != end; ++it)
        std::cout << *it << ' ';
    std::cout << std::endl;
}
} // namespace example15

#include <list>
#include <algorithm>
#include <iostream>
#include <sstream>
namespace example16 {

struct value_not_found {};
struct value_not_found_twice {};

template <typename Range, typename Value>
void print_interval(Range const& r, 
                    Value const& v,
                    std::ostream& os = std::cout)
{
    auto it = std::find(std::begin(r), std::end(r), v);
    auto it2 = it;

    if (it == std::end(r))
        throw value_not_found{};
    
    ++it2;
    auto past = std::find(it2, std::end(r), v);
    if (past == std::end(r))
        throw value_not_found_twice{};

    ++past;
    for (; it != past; ++it)
        os << *it << ' ';
    os << std::endl;
}

void run() {
    std::list<int> seq{ 3, 4, 7, 9, 2, 5, 7, 8 };
    print_interval(seq, 7);

    int array[] = { 3, 4, 7, 9, 2, 5, 7, 8 };
    std::stringstream ss{};
    print_interval(array, 7, ss);
    std::cout << ss.str() << std::endl;
}
} // namespace example16

#include <list>
#include <algorithm>
#include <iostream>
namespace example17 {

bool check(int i) { return i > 4 and i < 7; }

void run() {
    std::list<int> seq{ 3, 4, 7, 9, 2, 5, 7, 8 };

    auto it1 = std::find_if(std::begin(seq), std::end(seq), check);
    std::cout << "The first value in range is " << *it1 << std::endl;

    auto it2 = std::find_if(std::begin(seq),
                            std::end(seq),
                            [](int i) { return i > 4 and i < 7; });

    std::cout << "The first value in range is " << *it2 << std::endl;
}

} // namespace example17

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
namespace example18 {

void run() {
    std::vector<int> seq{ 3, 4, 7, 9, 2, 5, 7, 8 }, v{};
    v.resize(seq.size());
    std::copy(std::begin(seq), std::end(seq), v.begin());
    
    for (auto const& element : v)
        std::cout << element << " ";
    std::cout << std::endl;

    std::copy(std::begin(seq), 
              std::end(seq),
              std::ostream_iterator<int>(std::cout, ", "));
    std::cout << std::endl;
}

} // namespace example18

#include <vector>
#include <algorithm>
#include <iostream>
namespace example19 {

template <typename Seq>
void make_unique_sequence(Seq& seq) {
    std::sort(std::begin(seq), std::end(seq));
    auto it = std::unique(std::begin(seq), std::end(seq));
    seq.resize(std::distance(std::begin(seq), it));
}

void run() {
    std::vector<int> seq{ 3, 4, 7, 9, 2, 5, 7, 8, 3, 4, 3, 9 };

    auto seq1 = seq;
    std::sort(std::begin(seq1), std::end(seq1));
    auto it = std::unique(std::begin(seq1), std::end(seq1));
    seq1.resize(std::distance(std::begin(seq1), it));
    for (auto const& element : seq1)
        std::cout << element << ' ';
    std::cout << std::endl;

    auto seq2 = seq;
    make_unique_sequence(seq2);
    for (auto const& element : seq2)
        std::cout << element << ' ';
    std::cout << std::endl;
}

} // namespace example19

#include <vector>
#include <algorithm>
#include <complex>
#include <cstdlib>
namespace example20 {
void run() {
    std::vector<int> seq{ 3, 4, 7, 9, 2, 5, 7, 8, 3, 4, 3, 9 };
    std::sort(std::begin(seq), 
              std::end(seq),
              [](int x, int y) { return x > y; });
    for (auto const& element : seq)
        std::cout << element << ' ';
    std::cout << std::endl;

    std::vector<std::complex<float>> v =
        {{3, 4}, {7, 9}, {2, 5}, {7, 8}};

    std::sort(std::begin(v), 
              std::end(v), 
              [](auto x, auto y) { return abs(x) < abs(y); });
    for (auto const& element : v)
        std::cout << element << ' ';
    std::cout << std::endl;

    auto lex = [](std::complex<float> x, std::complex<float> y) {
        return real(x) < real(y) or 
               (real(x) == real(y) && imag(x) < imag(y));
    };
    std::sort(std::begin(v), std::end(v), lex);
    for (auto const& element : v)
        std::cout << element << ' ';
    std::cout << std::endl;
}
} // namespace example20

#include <vector>
#include <numeric>
#include <iostream>
namespace example21 {
void run() {
    std::vector<float> v{ 3.1, 4.2, 7, 9.3, 2, 5, 7, 8, 3, 4 };
    std::vector<float> w(10), x(10), y(10);

    std::iota(std::begin(w), std::end(w), 12.1);
    for (auto const& element : w)
        std::cout << element << ' ';
    std::cout << std::endl;

    std::partial_sum(std::begin(v), std::end(v), std::begin(x));
    for (auto const& element : x)
        std::cout << element << ' ';
    std::cout << std::endl;

    std::adjacent_difference(std::begin(v), std::end(v), std::begin(y));
    for (auto const& element : y)
        std::cout << element << ' ';
    std::cout << std::endl;

    float alpha = std::inner_product(std::begin(w), 
                                     std::end(w), 
                                     std::begin(v),
                                     0.0f);
    std::cout << alpha << std::endl;

    float sum_w = std::accumulate(std::begin(w), std::end(w), 0.0f);
    std::cout << sum_w << std::endl;

    float product_w = 
        std::accumulate(std::begin(w),
                        std::end(w),
                        1.0f,
                        [](float x, float y) { return x * y; });
    std::cout << product_w << std::endl;
}
} // namespace example21


int main() {
    example01::run();
    example02::run();
    example03::run();
    example04::run();
    example05::run();
    example06::run();
    example07::run();
    example08::run();
    example09::run();
    example10::run();
    example11::run();
    example12::run();
    example13::run();
    example14::run();
    example15::run();
    example16::run();
    example17::run();
    example18::run();
    example19::run();
    example20::run();
    example21::run();

    return 0;
}
