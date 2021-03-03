#include <algorithm>
#include <string>
#include <cassert>

#include <iostream>
namespace test {

unsigned int lev(unsigned int const m, unsigned int const n, std::string const& a, std::string const& b) {
    return
     (m == 0
      ? n
      : (n == 0
         ? m
         : std::min( { lev(m - 1, n, a, b) + 1, lev(m, n - 1, a, b) + 1, lev(m - 1, n - 1, a, b) + (a[m - 1] != b[n - 1]) })));
}

void run() {
    std::string const a{"abc"};
    std::string const b{"defgh"};
    std::cout << lev(a.size(), b.size(), a, b) << std::endl;    
}
}


#include <iostream>
int main() {
    std::cout << "test => [ok]" << std::endl; test::run(); std::cout << std::endl;

    return 0;
}
