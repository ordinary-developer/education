// region [how to do it]
#include <tuple>
#include <iostream>
namespace example_01
{
std::tuple<int, std::string, double> find() {
    return std::make_tuple(1, "marius", 1234.5);
}    
    
std::tuple<int, std::string, double> find2() {
    return std::make_tuple(1, "marius2", 1234.5);
}
    
void run() {
    auto [id, name, score] = find();
    std::cout << name << std::endl;
    
    if (auto [id, name, score] = find2(); score > 1000) {
        std::cout << name << std::endl;
    }
}  
} // example_01
// endregion [how to do it]

// region [how it works]
#include <map>
#include <string>
namespace example_02
{
void run() {
    std::map<int, std::string> m{};
    
    auto result = m.insert({ 1, "one" });
    std::cout << "inserted = " << result.second << std::endl
              << "value = " << result.first->second << std::endl;
}    
} // example_02

#include <map>
#include <string>
namespace example_03 {
void run() {
    std::map<int, std::string> m{};
    std::map<int, std::string>::iterator it{};
    bool inserted{};
    
    std::tie(it, inserted) = m.insert({ 1, "one" });
    std::cout << "inserted = " << inserted << std::endl
              << "value = " << it->second << std::endl;
    
    std::tie(it, inserted) = m.insert({ 1, "two" });
    std::cout << "inserted = " << inserted << std::endl
              << "value = " << it->second << std::endl;
}
} // example_03

#include <map>
#include <string>
namespace example_04
{
void run() {
    std::map<int, std::string> m{};
    
    {
        auto [it, inserted] = m.insert({ 1, "one" });
        std::cout << "inserted = " << inserted << std::endl
                  << "value = " << it->second << std::endl;
    }
    
    {
        auto [it, inserted] = m.insert({ 1, "two" });
        std::cout << "inserted = " << inserted << std::endl
                  << "value = " << it->second << std::endl;
    }
}    
} // example_04

#include <iostream>
#include <map>
#include <string>
namespace example_05 {
    
void run() {
    std::map<int, std::string> m{};
    
    if (auto [it, inserted] = m.insert({ 1, "two" }); inserted) {
        std::cout << it->second << std::endl;
    }
}    
    
} // namespace example_05
// endregion [how it dorks]

#include <iostream>
int main() {
    std::cout << "example_01 =>" << std::endl;
    example_01::run();
    std::cout << std::endl << std::endl;
    
    std::cout << "example_02 =>" << std::endl;
    example_02::run();
    std::cout << std::endl << std::endl;
    
    std::cout << "example_03 =>" << std::endl;
    example_03::run();
    std::cout << std::endl << std::endl;
    
    std::cout << "example_04 =>" << std::endl;
    example_04::run();
    std::cout << std::endl << std::endl;
    
    std::cout << "example_05 =>" << std::endl;
    example_05::run();
    std::cout << std::endl << std::endl;
    
    std::cout << "DONE" << std::endl;
    
    return 0;
}