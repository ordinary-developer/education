#include <future>
#include <iostream>

using namespace std::literals;

void f() {
    std::cout << "begin running f" << std::endl;
    std::this_thread::sleep_for(2s);
    std::cout << "end running f" << std::endl;
}

template <typename F, typename... Ts>
inline
auto reallyAsync(F&& f, Ts&&... params)
{
    return std::async(std::launch::async,
                      std::forward<F>(f),
                      std::forward<Ts>(params)...);
}

int main() {
    auto fut = reallyAsync(f);

    return 0;
}
