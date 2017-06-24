template <char Head, char... Rest>
struct binary_helper {
    constexpr 
      unsigned long long operator()(unsigned long long result) const;
};

template <char Head>
struct binary_helper<Head> {
    constexpr
      unsigned long long operator()(unsigned long long result) const;
};

template <char Head, char... Rest>
constexpr 
  unsigned long long
    binary_helper<Head, Rest...>::operator()(unsigned long long result)
      const
{
    static_assert('0' == Head or '1' == Head, 
                  "_binary must contain only 0 or 1");
    return binary_helper<Rest...>{}(result << 1 | (Head - '0'));
}


template <char Head>
constexpr
  unsigned long long
    binary_helper<Head>::operator()(unsigned long long result) const
{
    static_assert('0' == Head or '1' == Head,
                  "_binary must contain only 0 or 1");
    return result << 1 | (Head - '0');
}

template<char... Digits>
constexpr unsigned long long operator"" _binary() {
    return binary_helper<Digits...>{}(0ULL);
};

#include <iostream>
int main() {
    constexpr int number = 1_binary;
    std::cout << number << std::endl;

    return 0;
}
