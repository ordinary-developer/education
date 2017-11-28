#include <functional>

using namespace std::placeholders;

int main() {
    int lowVal = 0, highVal = 10;

    // using a lambda
    auto betweenL = [lowVal, highVal](int val)
    {
        return lowVal <= val && val <= highVal;
    };

    // using std::bind
    auto betweenB = std::bind(std::logical_and<bool>(),
                              std::bind(std::less_equal<int>(),
                                        lowVal,
                                        _1),
                              std::bind(std::less_equal<int>(),
                                        _1, 
                                        highVal));

    return 0;
}
