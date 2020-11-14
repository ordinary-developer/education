#include <thread>
#include <string>
#include <iostream>

void f(int i, std::string const& s) {
    std::cout << i << ": " << s << std::endl;
}

int main() {
    std::thread t(f, 3, "hello");
    t.join();

    return 0;
}
