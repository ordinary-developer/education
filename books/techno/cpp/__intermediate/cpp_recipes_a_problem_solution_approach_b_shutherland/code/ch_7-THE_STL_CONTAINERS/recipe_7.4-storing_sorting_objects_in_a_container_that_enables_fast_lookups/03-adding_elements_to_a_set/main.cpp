#include <iostream>
#include <cstdint>
#include <set>
#include <string>
#include <functional>

class SetObject {
    private:
        std::string m_Name;
        int32_t m_Key{};

    public:
        SetObject(int32_t key, const std::string& name)
            : m_Name{ name }, m_Key{ key } { }

        SetObject(int32_t key) 
            : SetObject(key, "") { }

        const std::string& GetName() const { return m_Name; }

        int32_t GetKey() const { return m_Key; }

        bool operator<(const SetObject& other) const {
            return m_Key < other.m_Key;
        }

        bool operator>(const SetObject& other) const {
            return m_Key > other.m_Key;
        }
};

int main() {
    std::set<SetObject, std::greater<SetObject>> mySet 
    {
        { 6, "Six" },
        { 3, "Three" },
        { 4, "Four" },
        { 1, "One" },
        { 2, "Two" }
    };
    for (auto&& number : mySet) 
        std::cout << number.GetName() << std::endl;
    std::cout << std::endl;

    mySet.emplace(SetObject(5, "Five"));
    for (auto&& number : mySet) 
        std::cout << number.GetName() << std::endl;
    std::cout << std::endl;

    auto iter = mySet.find(3);
    if (iter != mySet.end())
        std::cout << "Found: " << iter->GetName() << std::endl;

    return 0;
}
