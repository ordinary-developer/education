#include <iostream>
#include <cstdint>
#include <map>
#include <string>
#include <functional>


class MapObject {
    private:
        std::string m_Name;

    public:
        MapObject(const std::string name)
            : m_Name{ name } { }

        const std::string& GetName() const { return m_Name; }
};

int main() {
    std::map<int32_t, MapObject, std::greater<int32_t>> myMap
    {
        std::pair<int32_t, MapObject>(6, MapObject("Six")),
        std::pair<int32_t, MapObject>(3, MapObject("Three")),
        std::pair<int32_t, MapObject>(4, MapObject("Four")),
        std::pair<int32_t, MapObject>(1, MapObject("One")),
        std::pair<int32_t, MapObject>(2, MapObject("Two"))
    };
    for (auto&& number : myMap)
        std::cout << number.second.GetName() << std::endl;
    std::cout << std::endl;

    myMap.emplace(std::pair<int32_t, MapObject>(5, MapObject("Five")));
    for (auto&& number : myMap)
        std::cout << number.second.GetName() << std::endl;
    std::cout << std::endl;

    auto iter = myMap.find(3);
    if (iter != myMap.end())
        std::cout << "Found: " << iter->second.GetName() << std::endl;

    return 0;
}
