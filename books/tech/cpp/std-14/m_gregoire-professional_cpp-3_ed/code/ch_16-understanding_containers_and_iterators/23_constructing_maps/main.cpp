#include <map>
#include <string>
#include <iostream>


#include <cstdio>

class Data {
    public:
        explicit Data(int value = 0) { _value = value; }
        int getValue() const { return _value; }
        void setValue(int value) { _value = value; }
    private:
        int _value;
};

auto main() -> int {
    std::map<int, Data> dataMap;

    std::map<std::string, int> m = {
        { "Marc G.", 123 },
        { "Warren B.", 456 },
        { "Peter V.W.", 789 }
    };
    for (const auto& p : m) {
        std::cout << p.first << " = " << p.second << std::endl;
    }

    return 0;
}
