#include <concepts>
#include <ranges>
#include <type_traits>
#include <list>
#include <vector>
#include <string>

#include <cassert>


template <typename T>
concept NoExceptDestructible = requires(T & value) {
    value.~T();
    noexcept(value.~T());
};

static_assert(NoExceptDestructible<std::string>);
static_assert(NoExceptDestructible<int>);


template <typename C>
concept Character = 
    std::same_as<std::remove_cv_t<C>, char> ||
    std::same_as<std::remove_cv_t<C>, char8_t> ||
    std::same_as<std::remove_cv_t<C>, char16_t> ||
    std::same_as<std::remove_cv_t<C>, char32_t> ||
    std::same_as<std::remove_cv_t<C>, wchar_t>;

static_assert(Character<char>);
static_assert(Character<const char>);


template <typename S>
concept String = std::ranges::range<S> && requires(S & s, const S & cs)
{
    typename S::value_type;

    requires Character<typename S::value_type>;
    cs.length();
    s[0]; cs[0];
    requires 
        std::same_as<decltype(s[0]), typename S::value_type&> &&
        std::convertible_to<decltype(cs[0]), typename S::value_type>;
    s.data(); cs.data();        
    requires 
        std::same_as<decltype(s.data()), typename S::value_type*> &&
        std::same_as<decltype(cs.data()), const typename S::value_type*>;
};

static_assert(String<std::string>);
static_assert(not String<std::vector<char>>);


template <typename Iter>
concept BidirectionalIterator = true;

template <class Iter>
concept RandomAccessIterator = BidirectionalIterator<Iter>
    && requires(const Iter i, const Iter j, Iter k, const int n)
{
    { i - n }; { i + n }; { n + i };
    requires std::same_as<decltype(i - n), Iter>;
    requires std::same_as<decltype(i + n), Iter>;
    requires std::same_as<decltype(n + i), Iter>;
    { k += n }; { k -= n };
    requires std::same_as<decltype(k += n), Iter&>;
    requires std::same_as<decltype(k -= n), Iter&>;
    i[n];
    requires std::same_as<decltype(i[n]), decltype(*i)>;
    i < j; i > j; i <= j; i >= j;
    requires
        std::convertible_to<decltype(i < j), bool> &&
        std::convertible_to<decltype(i > j), bool> &&
        std::convertible_to<decltype(i <= j), bool> &&
        std::convertible_to<decltype(i >= j), bool>;
};

static_assert(RandomAccessIterator<std::vector<int>::iterator>);
static_assert(not RandomAccessIterator<std::list<int>::iterator>);
static_assert(RandomAccessIterator<int*>);


int main() {    
    assert(true);
}
