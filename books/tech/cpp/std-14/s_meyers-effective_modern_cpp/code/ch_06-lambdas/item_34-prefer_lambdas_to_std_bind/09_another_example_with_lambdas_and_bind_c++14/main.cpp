#include <functional>

int main() {
    int lowVal = 0, highVal = 10;

    // using a lambda
    auto betweenL = [lowVal, highVal](const auto& val)
    {
        return lowVal <= val && val <= highVal;
    };

    // using std::bind
    using namespace std::placeholders;
    auto betweenB = std::bind(std::logical_and<>(),
                              std::bind(std::less_equal<>(),
                                        lowVal,
                                        _1),
                              std::bind(std::less_equal<>(),
                                        _1,
                                        highVal)
                             );

    return 0;
}
