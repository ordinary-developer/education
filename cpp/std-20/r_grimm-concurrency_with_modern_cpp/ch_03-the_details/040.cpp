#include <iostream>
#include <future>
#include <numeric>
#include <random>
#include <vector>

static const int NUM = 100000000;

long long getDotProduct(std::vector<int> & v, std::vector<int> & w) {
    auto vSize = v.size();

    auto fut1 = std::async([&] {
        return std::inner_product(&v[0], &v[vSize / 4], &w[0], 0LL);        
    });

    auto fut2 = std::async([&]{
        return std::inner_product(&v[vSize / 4], &v[vSize / 2], &w[vSize / 4], 0LL);
    });

    auto fut3 = std::async([&] {
        return std::inner_product(&v[vSize / 2], &v[vSize * 3/4], &w[vSize / 2], 0LL);
    });

    auto fut4 = std::async([&]{
        return std::inner_product(&v[vSize * 3/4], &v[vSize], &w[vSize * 3/4], 0LL);
    });

    return fut1.get() + fut2.get() + fut3.get() + fut4.get();
}

int main() {
    std::cout << std::endl;

    std::random_device seed{};
    std::mt19937 engine{seed()};
    std::uniform_int_distribution<int> dist{0, 100};

    std::vector<int> v, w;
    v.reserve(NUM);
    w.reserve(NUM);
    for (int i = 0; i < NUM; ++i) {
        v.push_back(dist(engine));
        w.push_back(dist(engine));
    }

    std::cout << "getDotProduct(v, w): " << getDotProduct(v, w) << std::endl;

    std::cout << std::endl; 
}
