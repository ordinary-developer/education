#include <map>
#include <iostream>


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

    for (auto iter = begin(dataMap); iter != end(dataMap); ++iter) {
        std::cout << iter->second.getValue() << std::endl;
    }

    for (const auto& p : dataMap) {
        std::cout << p.second.getValue() << std::endl;
    }

    // the old version
    for (std::map<int, Data>::const_iterator iter = dataMap.begin();
            iter != dataMap.end(); ++iter)
    {
            std::cout << iter->second.getValue() << std::endl;
    }

    return 0;
}
