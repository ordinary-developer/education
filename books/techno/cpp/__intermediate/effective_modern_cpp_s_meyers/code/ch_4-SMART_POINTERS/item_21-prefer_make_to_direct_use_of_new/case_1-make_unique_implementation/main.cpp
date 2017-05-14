#include <memory>

template <typename T, typename... Ts>
std::unique_ptr<T> make_unique(Ts&&... params) {
    return std::unique_ptr<T>(new T(std::forward<Ts>(params)...));
}

class ExempliGratia { };

int main() {
    auto ptr = make_unique<ExempliGratia>();

    return 0;
}
