#include <cstdint>
#include <iostream>
#include <string>
#include <unordered_map>

class MapObject {
    public:
        MapObject(const std::string& name)
            : m_Name(name) { }

        const std::string& GetName() const {
            return m_Name;
        }

    private:
        std::string m_Name;
};

int main() {
    std::unordered_map<int32_t, MapObject> myMap;
    myMap.emplace(std::pair<int32_t, MapObject>(5, MapObject("Five")));
    myMap.emplace(std::pair<int32_t, MapObject>(3, MapObject("Three")));
    myMap.emplace(std::pair<int32_t, MapObject>(4, MapObject("Four")));
    myMap.emplace(std::pair<int32_t, MapObject>(1, MapObject("One")));
    myMap.emplace(std::pair<int32_t, MapObject>(2, MapObject("Two")));

    std::cout << std::showbase << std::hex;
    for (auto&& number : myMap)
        std::cout << number.second.GetName() << std::endl;
    
    auto iter = myMap.find(3);
    if (iter != myMap.end())
        std::cout << "Found: " << iter->second.GetName() << std::endl;

    return 0;
}
