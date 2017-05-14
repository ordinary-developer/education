#include <utility>
#include <vector>

int main() {
    std::vector<int> a{ };
    std::vector<int>().swap(a);

    return 0;
}
