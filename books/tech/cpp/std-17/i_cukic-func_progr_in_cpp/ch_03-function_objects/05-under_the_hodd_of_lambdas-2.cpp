#include <algorithm>
#include <vector>
#include <cassert>
#include <cctype>
namespace test {

void run() {
    int count{0};
    std::vector<std::string> words{ "An", "ancient", "pond" };

    std::for_each(std::cbegin(words), std::cend(words),
        [count](std::string const& word) mutable {
            if (std::isupper(static_cast<unsigned char>(word[0]))) 
                ++count;
        });
    assert(1 == count);
}

} // test


#include <iostream>
int main() {
    std::cout << "test => [ok]" << std::endl; test::run();     

    return 0;
}
