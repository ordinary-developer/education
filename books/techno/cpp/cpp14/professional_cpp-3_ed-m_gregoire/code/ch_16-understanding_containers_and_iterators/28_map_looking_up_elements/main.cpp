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
    dataMap[1].setValue(100);

    auto it = dataMap.find(1);
    if (it != end(dataMap)) {
        it->second.setValue(100);
    }

    std::map<int, Data>::iterator iterator = dataMap.find(1);

    return 0;
}
