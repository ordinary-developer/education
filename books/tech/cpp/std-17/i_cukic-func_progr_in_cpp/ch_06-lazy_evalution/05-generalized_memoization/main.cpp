#include <map>
#include <tuple>
#include <unordered_map>
#include <cassert>

#include <iostream>
namespace test_01 { // generalized memoization

template <typename Result, typename... Args>
auto make_memoized(Result (*f)(Args...)) {
    std::map<std::tuple<Args...>, Result> cache{};

    return [f, cache](Args... args) mutable -> Result {
        auto const& args_tuple = std::make_tuple(args...);

        auto const& cached = cache.find(args_tuple);
        if (cache.end() == cached) {
            auto const& ret = f(args...);
            cache[args_tuple] = ret;
            return ret;
        }
        else {
            return cached->second;
        }
    };
}

unsigned int fib(unsigned int const n) {
    //std::cout << "calculating " << n << "!\n";

    return (0 == n
            ? 0
            : (1 == n ? 1 : fib(n - 1) + fib(n - 2)));
}

void run() {
    auto fibdemo = make_memoized(fib);
    assert(610 == fibdemo(15));
    assert(610 == fibdemo(15));
}

} // test_01


#include <iostream>
#include <map>
#include <mutex>
#include <tuple>
#include <type_traits>
#include <cassert>
namespace test_02 {

namespace detail {

class null_param{};

template <class Sig, class F>
class memoize_helper;

template <class Result, class... Args, class F>
class memoize_helper<Result(Args...), F> {
private:
    using function_type = F;
    using args_tuple_type = std::tuple<std::decay_t<Args>...>;

    function_type f;

    mutable std::map<args_tuple_type, Result> m_cache;
    mutable std::recursive_mutex m_cache_mutex;

public:
    template <typename Function>
    memoize_helper(Function&& f, null_param) : f{f} {}

    memoize_helper(memoize_helper const& other) : f{other.f} {}

    template <class... InnerArgs>
    Result operator()(InnerArgs&&... args) const {
        std::unique_lock<std::recursive_mutex> lock{m_cache_mutex};

        const auto args_tuple = std::make_tuple(args...);
        const auto cached = m_cache.find(args_tuple);

        if (cached != m_cache.end()) {
            return cached->second;
        }
        else {
            auto&& ret = f(*this, std::forward<InnerArgs>(args)...);
            m_cache[args_tuple] = ret;
            return ret;
        }
    }

};

} // detail

using detail::memoize_helper;

template <class Sig, class F>
memoize_helper<Sig, std::decay_t<F>>
make_memoized_r(F&& f) {
    return { std::forward<F>(f), detail::null_param{} };
}

void run() {
    auto fibmemo = make_memoized_r<unsigned int(unsigned int)>(
        [](auto& fib, unsigned int n) {
            //std::cout << "calculating " << n << "!\n";

            return (0 == n
                    ? 0
                    : (1 == n ? 1 : fib(n - 1) + fib(n - 2)));
        });

    assert(610 == fibmemo(15));
    assert(610 == fibmemo(15));
}

} // test_02


#include <iostream>
int main() {
    std::cout << "test 01 => [ok]" << std::endl; test_01::run(); std::cout << std::endl;
    std::cout << "test 02 => [ok]" << std::endl; test_02::run(); std::cout << std::endl;

    return 0;
}
