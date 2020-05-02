#include <cstdint>
#include <functional>
#include <iostream>
#include <string>
#include <unordered_set>

class SetObject;
namespace std
{
    template <>
    class hash<SetObject> {
        public:
            template <typename... Args>
            size_t operator()(Args&... setObject) const {
             return 
              hash<std::string>()((forward<Args...>(setObject...)).GetName());
            }
    };
}

class SetObject {
    public:
        SetObject(const std::string& name)
            : m_Name(name),
              m_Hash(std::hash<SetObject>()(*this)) { }

        const std::string& GetName() const { return m_Name; }
        const size_t& GetHash() const { return m_Hash; }

        bool operator==(const SetObject& other) const {
            return m_Hash == other.m_Hash;
        }

    private:
        std::string m_Name;
        size_t m_Hash{};
};

int main() {
    std::unordered_set<SetObject> mySet{};
    mySet.emplace("Five");
    mySet.emplace("Three");
    mySet.emplace("Four");
    mySet.emplace("One");
    mySet.emplace("Two");

    std::cout << std::showbase << std::hex;
    for (auto&& number : mySet)
        std::cout << number.GetName() << " - " 
                  << number.GetHash() << std::endl;

    auto iter = mySet.find({ "Three" });
    if (iter != mySet.end())
        std::cout << "Found: " << iter->GetName()
                  << " with hash: " << iter->GetHash() << std::endl;

    return 0;
}
