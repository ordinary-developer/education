#include <future>
#include <iostream>

void f() {
    std::cout << "running f" << std::endl;
}

template <typename F, typename... Ts>
inline
std::future<typename std::result_of<F(Ts...)>::type>
reallyAsync(F&& f, Ts&&... params) 
{
    return std::async(std::launch::async,
                      std::forward<F>(f),
                      std::forward<Ts>(params)...);
}

int main() {
    auto fut = reallyAsync(f);

    return 0;
}
