#include <vector>


auto main() -> int {
    std::vector<int> intVector;
    auto iter = end(intVector);
    //*iter = 10; // here a bug will produced

    std::vector<int> vectorOne(10);
    std::vector<int> vectorTwo(10);
    // here an error will be
    // an infinite loop
    for (auto iter = begin(vectorTwo); iter != end(vectorOne); ++iter) {
        // loop body
    }

    return 0;
}
