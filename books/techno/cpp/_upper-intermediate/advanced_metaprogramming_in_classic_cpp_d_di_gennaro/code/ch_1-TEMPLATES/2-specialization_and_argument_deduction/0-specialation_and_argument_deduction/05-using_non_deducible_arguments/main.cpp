#include <cstddef>
#include <string>

class crc32 { };
class adler { };

template <typename algorithm_t>
size_t hash_using1(const char* x) {
    return 42;
}

template <typename algorithm_t, typename string_t>
int hash_using2(const string_t& x) {
    return 42;
}

int main() {
    size_t j1 = hash_using1<crc32>("this is the string to be hashed");

    std::string arg("hash me, please");
    int j2 = hash_using2<crc32>(arg);

    return 0;
}
