#include <iostream>
#include <map>


void func(const std::map<int, int>& m) {
    // std::cout << m[1] << std::endl;
}

auto main() -> int {
    std::map<int, int> m;

    m[1] = 11;
    m[2] = 22;
    m[3] = 33;
    
    func(m);

    return 0;
}
