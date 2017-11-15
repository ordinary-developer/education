#include <climits>
#include <limits>
#include <cstdlib>


static const int x = INT_MAX;                         // static
static const int y = std::numeric_limits<int>::max(); // dynamic;
static const int z = rand();                          // dynamic


int main() {
    double data1[x];
    double data2[y];
    double data3[z];

    return 0;
}
