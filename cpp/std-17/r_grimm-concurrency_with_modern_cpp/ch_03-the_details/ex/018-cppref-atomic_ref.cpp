#include <atomic>
#include <iostream>
#include <numeric>
#include <thread>
#include <vector>

int main() {
    using Data = std::vector<char>;
    
    auto inc_atomically = [](Data& data) {
        for (Data::value_type& x : data) {
            auto xx = std::atomic_ref<Data::value_type>(x);
            ++xx;
        }
    };
    
    auto test_run = [](const auto Fun) {
        Data data(10'000'000); 
        {
            std::jthread j1{Fun, std::ref(data)};
            std::jthread j2{Fun, std::ref(data)};
            std::jthread j3{Fun, std::ref(data)};
            std::jthread j4{Fun, std::ref(data)};
        }
        std::cout << "sum = " << std::accumulate(cbegin(data), cend(data), 0) << '\n';
    };
    
    test_run(inc_atomically);
}
