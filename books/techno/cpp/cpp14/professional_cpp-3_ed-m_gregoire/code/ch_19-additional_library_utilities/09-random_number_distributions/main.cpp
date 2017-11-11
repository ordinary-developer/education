#include <random>
#include <functional>
#include <map>
#include <fstream>

int main() {
    const unsigned int kStart{ 1 };
    const unsigned int kEnd{ 99 };
    const unsigned int kIterations{ 1000000 };

    std::random_device randomDevice{};
    std::mt19937 engine{ randomDevice() };
    std::uniform_int_distribution<int> distribution{ kStart, kEnd };
    auto generator = std::bind(distribution, engine);

    std::map<int, int> m{};
    for (unsigned int i{0}; i < kIterations; ++i) {
        int randomNumber = generator();
        ++(m[randomNumber]);
    }

    std::ofstream of("res.csv");
    for (unsigned int i{kStart}; i <= kEnd; ++i) {
        of << i << ",";
        auto res = m.find(i);
        of << (res != std::end(m) ? res->second : 0) << std::endl;
    }

    return 0;
}
