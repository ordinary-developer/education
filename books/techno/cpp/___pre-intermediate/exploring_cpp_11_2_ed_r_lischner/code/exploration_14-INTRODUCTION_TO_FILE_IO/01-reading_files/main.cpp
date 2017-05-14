#include <cstdio>
#include <fstream>
#include <iostream>


int main() {
    std::ifstream in{ "list1401.in" };
    if (not in)
        std::perror("list1401.in");
    else {
        int x{};
        while (in >> x)
            std::cout << x << '\n';
        in.close();
    }

    return 0;
}
