#include <cstdio>
#include <fstream>
#include <iostream>


int main() {
    std::ifstream in{ "list1403.in" };
    if (not in)
        std::perror("list1403.in");
    else {
        std::ofstream out{ "list1403.out" };
        if (not out)
            std::perror("list1403.out");
        else {
            int x{};
            while (in >> x)
                out << x << '\n';
            out.close();
            if (not out)
                std::perror("list1403.out");
        }
    }

    return 0;
}
