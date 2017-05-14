#include <iostream>
#include <map>


class Data {
    public:
        explicit Data(int value = 0) : _value(value) { }
        int getValue() const { return _value; }
        void setValue(int value) { _value = value; }
    private:
        int _value;
};

auto main() -> int {
    std::map<int, Data> dataMap;

    dataMap[1] = Data(4);
    dataMap[1] = Data(6);

    return 0;
}
