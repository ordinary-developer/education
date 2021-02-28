#include <algorithm>
#include <functional>
#include <memory>
#include <vector>
#include <cassert>
#include <cmath>
#include <cstddef>
namespace test {

template <typename Function, typename SecondArgType>
class partial_application_bind2nd_impl {
private:
    Function m_function;
    SecondArgType m_second_arg;

public:
    partial_application_bind2nd_impl(Function function, SecondArgType second_arg)
        : m_function{function}, m_second_arg{second_arg} {}

    template <typename FirstArgType>
    auto operator()(FirstArgType&& first_arg) const
        -> decltype(m_function(std::forward<FirstArgType>(first_arg), m_second_arg))
    {
        return m_function(std::forward<FirstArgType>(first_arg), m_second_arg);
    }    
};

template <typename Function, typename SecondArgType>
partial_application_bind2nd_impl<Function, SecondArgType>
bind2nd(Function&& function, SecondArgType&& second_arg)
{
    return partial_application_bind2nd_impl<Function, SecondArgType>(
        std::forward<Function>(function),
        std::forward<SecondArgType>(second_arg));
}

void run() {
    {
    auto const& greater_than_42 = bind2nd(std::greater<int>{}, 42);
    assert(not greater_than_42(1));
    assert(greater_than_42(50));

    std::vector<int> ages{ 2, 10, 3, 11, 4, 12, 5, 6, 5 };
    std::stable_partition(std::begin(ages), std::end(ages), bind2nd(std::greater<int>{}, 6));

    std::vector<int> const expected{ 10, 11, 12, 2, 3, 4, 5, 6, 5 };
    assert(expected == ages);
    }

    {
    std::vector<double> degrees{ 0, 30, 45, 60 };
    std::vector<double> radians(degrees.size());
    std::transform(std::cbegin(degrees), std::cend(degrees),
        std::begin(radians),
        bind2nd(std::multiplies<double>(), M_PI / 180));
    
    std::vector<double> const expected{ 0, 0.523, 0.785, 1.047 };
    for (std::size_t i{0}, in = expected.size(); i < in; ++i)
        assert((std::abs(expected[i] - radians[i]) < 0.001));
    }
}

} // test


#include <iostream>
int main() {
    std::cout << "test => [ok]";
    test::run();
    std::cout << std::endl;

    return 0;
}
