#include <memory>
#include <vector>

template <typename T, typename... Ts>
void doSomeWork(Ts&&... params)
{
    T localObject1(std::forward<Ts>(params)...);
    T localObject2{std::forward<Ts>(params)...};
}

int main() {
    std::vector<int> v;
    doSomeWork<std::vector<int>>(10, 20);
}

