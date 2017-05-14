#include <iostream>
#include <map>


class Data {
    public:
        Data(int value = 0) : _value(value) { }
        int getValue() const { return _value; }
        void setValue(int value) { _value = value; }
    private:
        int _value;
};

auto main() -> int {
    std::map<int, Data> dataMap;
    dataMap[1] = Data(4);
    std::cout << "There are " << dataMap.count(1) << " elements with key 1" 
              << std::endl;
    dataMap.erase(1);
    std::cout << "There are " << dataMap.count(1) << " elements with key 1"
              << std::endl;

    return 0;
}
