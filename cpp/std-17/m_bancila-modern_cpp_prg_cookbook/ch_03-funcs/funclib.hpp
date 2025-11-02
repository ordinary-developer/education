#pragma once

#include <algorithm>
#include <memory>
#include <map>
#include <numeric>
#include <queue>
namespace funclib {

// #region map
template <typename F, typename R> // for std::array, std::vector, std::list, c-like array
constexpr R mapf(F&& f, R const& r) {
    R ret{r};
    std::transform(
        std::begin(ret), std::end(ret), std::begin(ret),
        std::forward<F>(f));
    return ret;        
}

template <typename F, typename T, typename U> // for std::map
constexpr std::map<T, U> mapf(F&& f, std::map<T, U> const& m) {
    std::map<T, U> ret{};
    for (auto const& kvp : m)
        ret.insert(f(kvp));
    return ret;
}

template <typename F, typename T> // for std::queue
constexpr std::queue<T> mapf(F&& f, std::queue<T> const& q) {
    std::queue<T> ret{};
    std::queue<T> q_tmp{q};
    while (not q_tmp.empty()) {
        ret.push(f(q_tmp.front()));
        q_tmp.pop();
    }
    return ret;
}
// #endregion
 
// #region [fold]
template <typename F, typename R, typename T> // for std::array, std::vector, std::list, std::map
constexpr T foldl(F&& f, R&& r, T i) {
    return std::accumulate(
        std::cbegin(r), std::cend(r), std::move(i), std::forward<F>(f));
}

template <typename F, typename R, typename T>
constexpr T foldr(F&& f, R&& r, T i) {
    return std::accumulate(
        std::crbegin(r), std::crend(r), std::move(i), std::forward<F>(f));
}
// #endregion

// #region [compose]
template <typename F, typename G> 
constexpr auto compose(F&& f, G&& g) {
    return [=](auto const& x) { return f(g(x)); };
}

template <typename F, typename... R>
constexpr auto compose(F&& f, R&&... r) {
    return [=](auto const& x) { return f(compose(r...)(x)); };
}
// #endregion

} // #end funclib 
