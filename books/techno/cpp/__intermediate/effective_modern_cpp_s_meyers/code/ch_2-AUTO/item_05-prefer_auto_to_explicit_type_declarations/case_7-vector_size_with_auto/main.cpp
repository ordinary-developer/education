#include <vector>


int main() {
    std::vector<int> v;

    // the type is std::vector<int>::size_type
    // which is 32 bytes on 32-x platforms
    // and 64 bytes on 64-x platforms
    unsigned sz1 = v.size();

    // it is a platform-independent code
    auto sz2 = v.size();
}
