#include <algorithm>

#include "data.hpp"
#include "sequence.hpp"

int main() {
    intvector data(100);
    std::generate(data.begin(), data.end(), sequence{ 1, 1 });
    write_data(data);
    std::random_shuffle(data.begin(), data.end());
    write_data(data);

    return 0;
}
