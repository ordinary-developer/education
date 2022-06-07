#include <iostream>
#include <map>
#include <optional>
#include <string>
#include <vector>
namespace example_01 { // the "how to do it" section

template <typename K, typename V>
std::optional<V> my_find(int const key, std::map<K, V> const & m) {
    auto const pos = m.find(key);
    
    if (m.end() != pos) {
        return pos->second;
    }
    return {};
}

std::string extract(std::string const & text,
    std::optional<int> start, std::optional<int> end)
{
    auto const s = start.value_or(0);
    auto const e = end.value_or(text.length());
    return text.substr(s, e - s);
}

void run() {
    {
        std::optional<int> v1{};
        std::optional<int> v2{42};
        v1 = 42;
        std::optional<int> v3 = v2;
    }
    
    {
        std::optional<int> v1{42};
        std::cout << *v1 << '\n';
        
        struct foo { int a; double b; };
        std::optional<foo> v2{ foo{ 42, 10.5 } };
        std::cout << v2->a << ", " << v2->b << '\n';
    }
    
    {
        using namespace std::string_literals;
        
        std::optional<std::string> v1{ "text"s };
        std::cout << v1.value() << '\n';
        
        std::optional<std::string> v2{};
        std::cout << v2.value_or("default"s) << '\n';
    }
    
    {
        struct foo {
            int a;
            double b;
        };
        
        std::optional<int> v1{42};
        if (v1) {
            std::cout << *v1 << '\n';
        }
        
        std::optional<foo> v2{ foo{ 42, 10.5 } };
        if (v2.has_value()) {
            std::cout << v2->a << ", " << v2->b << '\n';
        }
    }
    
    {
        std::optional<int> v{42};
        v.reset();
    }
    
    {
        using namespace std::string_literals;
        
        std::map<int, std::string> m{
            { 1, "one"s }, { 2, "two"s }, { 3, "three"s } };
        
        auto value = my_find(2, m);
        if (value)
            std::cout << *value << '\n';
            
        value = my_find(4, m);
        if (value)
            std::cout << *value << '\n';
    }
    
    {
        using namespace std::string_literals;
        
        auto v1 = extract("sample"s, {}, {});
        std::cout << v1 << '\n';
        
        auto v2 = extract("sample"s, 1, {});
        std::cout << v2 << '\n';
        
        auto v3 = extract("sample"s, 1, 4);
        std::cout << v3 << '\n';
    }
    
    {
        struct work {
            std::string title;
            std::optional<std::string> subtitle;
            std::vector<std::string> authors;
            std::string publisher;
            std::string isbn;
            std::optional<int> pages;
            std::optional<int> year;
        };
    }
}

} // example_01


#include <iostream>
#include <optional>
namespace example_02 { // the "how it works" section

struct bar {};
void process(std::optional<bar> const & arg) {}

void run() {
    std::optional<bar> b1{ bar{} };
    bar b2{};
    
    process(b1); // no copy
    process(b); // copy construction
}

} // example_02


#include <iostream>
int main() {
    std::cout << "example 01 => [ok]" << std::endl; example_01::run(); std::cout << std::endl;
    std::cout << "example 02 => [ok]" << std::endl; example_02::run(); std::cout << std::endl;
    
    return 0;
}
