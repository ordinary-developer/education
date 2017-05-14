#include <thread>
#include <string>
#include <iostream>

void f(int i, const std::string& s) {
    std::cout << i << ": " << s << std::endl;
}

int main() {
    char buffer[1024];
    int some_param = 0;
    sprintf(buffer, "%i", some_param);
    std::thread t(f, 3, std::string(buffer));
    // but not
    // std::thread t(f, 3, buffer);
    t.detach();

    return 0;
}
