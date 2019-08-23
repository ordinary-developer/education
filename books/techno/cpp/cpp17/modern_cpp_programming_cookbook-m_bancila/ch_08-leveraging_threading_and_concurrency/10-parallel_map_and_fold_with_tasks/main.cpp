#include <thread>
#include <future>
#include <chrono>
#include <algorithm>
#include <numeric>
#include <vector>
#include <iomanip>
#include <iostream>
#include <cassert>


namespace workspace {
    
template <
    typename Time = std::chrono::microseconds,
    typename Clock = std::chrono::high_resolution_clock>
struct perf_timer {
    template <typename F, typename... Args>
    static Time duration(F&& f, Args... args)
    {
        auto const start = Clock::now();
        std::invoke(std::forward<F>(f), std::forward<Args>(args)...);
        auto const end = Clock::now();
        
        return std::chrono::duration_cast<Time>(end - start);
    }
}; 
    
unsigned get_num_of_threads() { return std::thread::hardware_concurrency(); }    
    
namespace version1 {
    template <typename Iter, typename F>
    void parallel_map(Iter begin, Iter end, F f)
    {
        const auto size = std::distance(begin, end);
        
        if (size <= 10000) {
            std::transform(begin, end, begin, std::forward<F>(f));
            return;
        }
        
        auto const num_of_tasks = get_num_of_threads();
        auto const part = size / num_of_tasks;
        
        std::vector<std::future<void>> tasks{};
        auto last = begin;
        for (unsigned i{0}; i < num_of_tasks; ++i, begin = last) {
            if ( num_of_tasks - 1 == i)
                last = end;
            else
                std::advance(last, part);
            
            tasks.emplace_back(std::async(
                std::launch::async,
                [=, &f] { std::transform(begin, last, begin, std::forward<F>(f)); }));
        }
        
        for (auto& t : tasks)
            t.wait();
    }
    
    template <typename Iter, typename R, typename F>
    auto parallel_reduce(Iter begin, Iter end, R init, F op)
    {
        auto const size = std::distance(begin, end);
        
        if (size <= 10000)
            return std::accumulate(begin, end, init, std::forward<F>(op));
        
        auto const num_of_tasks = get_num_of_threads();
        auto const part = size / num_of_tasks;
        
        std::vector<std::future<R>> tasks{};
        auto last = begin;
        for (unsigned i{0}; i < num_of_tasks; ++i, begin = last) {
            if (num_of_tasks - 1 == i)
                last = end;
            else
                std::advance(last, part);
            
            tasks.emplace_back(std::async(
                std::launch::async,
                [=, &op] { return std::accumulate(begin, last, R{}, std::forward<F>(op)); }));
        }
        
        std::vector<R> values;
        for (auto& t : tasks)
            values.push_back(t.get());
        
        return std::accumulate(std::begin(values), std::end(values), init, std::forward<F>(op));
    }
}
    
namespace version2 {
    template <typename Iter, typename F>
    void parallel_map(Iter begin, Iter end, F f)
    {
        auto const size = std::distance(begin, end);
        
        if (size <= 10000) {
            std::transform(begin, end, begin, std::forward<F>(f));
            return;
        }
        
        auto middle = begin;
        std::advance(middle, size / 2);
        
        auto const result = std::async(std::launch::deferred, 
            parallel_map<Iter, F>, begin, middle, std::forward<F>(f));
        parallel_map(middle, end, std::forward<F>(f));
        result.wait();
    }
    
    template <typename Iter, typename R, typename F>
    auto parallel_reduce(Iter begin, Iter end, R init, F op)
    {
        auto const size = std::distance(begin, end);
        
        if (size <= 10000) 
            return std::accumulate(begin, end, init, std::forward<F>(op));
        
        auto middle = begin;
        std::advance(middle, size / 2);
        
        auto result1 = std::async(
            std::launch::async,
            parallel_reduce<Iter, R, F>,
            begin,
            middle,
            R{},
            std::forward<F>(op));
        
        auto result2 = version2::parallel_reduce(middle, end, init, std::forward<F>(op));
        return result1.get() + result2;
    }
}
    
void run() {
    std::vector<int> sizes {
        10000, 100000, 500000,
        1000000, 2000000, 5000000,
        10000000
    };
    
    std::cout
        << std::right << std::setw(12) << std::setfill(' ') << "size"
        << std::right << std::setw(12) << "s map"
        << std::right << std::setw(12) << "p1 map"
        << std::right << std::setw(12) << "p2 map"
        << std::right << std::setw(12) << "s fold"
        << std::right << std::setw(12) << "p1 fold"
        << std::right << std::setw(12) << "p2 fold"
        << std::endl;
    
    for (auto const size : sizes) {
        std::vector<int> v(size);
        std::iota(std::begin(v), std::end(v), 1);
        
        auto v1 = v;
        auto s1 = 0LL;
        
        auto tsm = perf_timer<>::duration([&] {
            std::transform(std::begin(v1), std::end(v1), std::begin(v1),
                [](int const val) { return val + val; });                           
        });
        auto tsf = perf_timer<>::duration([&] {
            s1 = std::accumulate(std::begin(v1), std::end(v1), 0LL, std::plus<>()); });
        
        auto v2 = v;
        auto s2 = 0LL;
        auto tp1m = perf_timer<>::duration([&] {
            version1::parallel_map(std::begin(v2), std::end(v2), [](int const val) { return val + val; }); });
        auto tp1f = perf_timer<>::duration([&] {
            s2 = version1::parallel_reduce(std::begin(v2), std::end(v2), 0LL, std::plus<>()); });
        
        auto v3 = v;
        auto s3 = 0LL;
        auto tp2m = perf_timer<>::duration([&] {
            version2::parallel_map(std::begin(v3), std::end(v3), [](int const val) { return val + val; }); });
        auto tp2f = perf_timer<>::duration([&] {
            s3 = version2::parallel_reduce(std::begin(v3), std::end(v3), 0LL, std::plus<>()); });
        
        // assert (v1 == v2);
        // assert (v1 == v3);
        // assert (s1 == s2);
        // assert (s1 == s3);
        
        std::cout
            << std::right << std::setw(12) << std::setfill(' ') << size
            << std::right << std::setw(12) << std::chrono::duration<double, std::micro>(tsm).count()
            << std::right << std::setw(12) << std::chrono::duration<double, std::micro>(tp1m).count()
            << std::right << std::setw(12) << std::chrono::duration<double, std::micro>(tp2m).count()
            << std::right << std::setw(12) << std::chrono::duration<double, std::micro>(tsf).count()
            << std::right << std::setw(12) << std::chrono::duration<double, std::micro>(tp1f).count()
            << std::right << std::setw(12) << std::chrono::duration<double, std::micro>(tp2f).count()
            << std::endl;
    }
}    
} // workspace


int main() {
    workspace::run();
    
    return 0;
}
