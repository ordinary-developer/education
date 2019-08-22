#include <thread>
#include <atomic>
#include <vector>
#include <iostream>
namespace example_01 { // <- atomic operations

void run() {
    std::atomic<int> counter{0};
    
    std::vector<std::thread> threads{};
    for (int i{0}; i < 10; ++i)
        threads.emplace_back([&counter](){
            for (int i{0}; i < 10; ++i)
                ++counter;
        });
    
    for (auto& t : threads)
        t.join();
    
    std::cout << counter << std::endl;
}
} // example_01


#include <thread>
#include <atomic>
#include <vector>
#include <iostream>
namespace example_02 { // <- atomic_flag (atomic for bool)

void run() {
    std::atomic_flag lock = ATOMIC_FLAG_INIT;
    int counter{0};
    std::vector<std::thread> threads{};
    
    for (int i{0}; i < 10; ++i)
        threads.emplace_back([&](){
            while (lock.test_and_set(std::memory_order_acquire));
            ++counter;
            lock.clear(std::memory_order_release);
        });
    
    for (auto& t : threads)
        t.join();
    
    std::cout << counter << std::endl;
}    
} // example_02


#include <thread>
#include <atomic>
#include <vector>
#include <random>
#include <algorithm>
#include <iostream>
#include <cstddef>
#include <cassert>
namespace example_03 { // <- atomic addition
    
std::vector<int> generate_random() {
    std::random_device rd{};
    auto gen = std::mt19937{ rd() };
    auto dis = std::uniform_int_distribution<>{ 1, 99 };
    std::vector<int> numbers(100000, 0);
    std::generate(std::begin(numbers), std::end(numbers), 
          [&dis, &gen] { return dis(gen); });
    
    return numbers;
}
    
void run() {
    std::vector<int> numbers = generate_random();
    
    auto const sum_expected = std::accumulate(std::begin(numbers), std::end(numbers), 0);
    
    std::atomic<int> sum{0};
    std::size_t const size = numbers.size();
    std::vector<std::thread> threads{};
    
    for (int i{0}; i < 10; ++i) 
        threads.emplace_back(
            [&sum, &numbers](std::size_t const start, std::size_t const end) {
                for (std::size_t i{start}; i < end; ++i) 
                    std::atomic_fetch_add_explicit(&sum, numbers[i], std::memory_order_acquire);
            },
            i * (size / 10),
            (i + 1) * (size / 10));
    
    for (auto & t : threads)
        t.join();
    
    assert(sum == sum_expected);
    std::cout << sum << std::endl;
    std::cout << sum_expected << std::endl;
}
} // example_03


#include <thread>
#include <atomic>
#include <vector>
namespace example_04 { // <- set of atomic operations
    
template
<typename T,
 typename I = typename std::enable_if<std::is_integral<T>::value>::type>
class atomic_counter {
    std::atomic<T> counter{0};
    
public:
    T increment() { return counter.fetch_add(1); }
    T decrement() { return counter.fetch_sub(1); }
    T get() { return counter.load(); }
};
    
    
void run() {
    atomic_counter<int> counter{};
    
    std::vector<std::thread> threads{};
    for (int i{0}; i < 10; ++i) 
        threads.emplace_back([&counter](){
            for (int i{0}; i < 10; ++i)
                counter.increment();
        });
        
    for (auto & t : threads)
        t.join();
        
    std::cout << counter.get() << std::endl;        
}    
} // example_04

#include <functional>
#include <string>
#include <iostream>
int main() {
    using FuncDelegate = std::function<void(void)>;
    
    FuncDelegate const funcs[] {
        example_01::run, example_02::run, example_03::run, example_04::run
    };
    
    unsigned int i{0};
    for (auto const& func : funcs) {
        std::string const exampleName = "example_" + std::to_string(i++);
        std::cout << exampleName << " =>\n";
        func();
        std::cout << "[ok] - " << exampleName << "\n\n";
    }
    
    return 0;
}
