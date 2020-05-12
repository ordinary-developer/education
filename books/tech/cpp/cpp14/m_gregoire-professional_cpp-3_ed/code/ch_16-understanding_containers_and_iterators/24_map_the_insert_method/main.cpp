#include <iostream>
#include <map>


class Data {
    public:
        explicit Data(int value) : _value(value) { }
        int getValue() const { return _value; }
        void setValue(int value) { _value = value; }
    private:
        int _value;
};

auto main() -> int {
    std::map<int, Data> dataMap;

    auto ret = dataMap.insert({1, Data(4) });
    if (ret.second) {
        std::cout << "Insert succeeded!" << std::endl;
    }
    else {
        std::cout << "Insert failed!" << std::endl;
    }

    ret = dataMap.insert(std::make_pair(1, Data(6)));
    if (ret.second) {
        std::cout << "Insert succeeded!" << std::endl;
    }
    else {
        std::cout << "Insert failed!" << std::endl;
    }

    return 0;
}
