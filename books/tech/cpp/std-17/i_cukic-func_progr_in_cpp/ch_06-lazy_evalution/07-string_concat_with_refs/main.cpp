#include <algorithm>
#include <iostream>
#include <string>
#include <tuple>

#include <cassert>
namespace test {

template <typename... Strings>
class lazy_string_concat_helper;

template <typename LastString, typename... Strings>
class lazy_string_concat_helper<LastString, Strings...> {
private:
    const LastString& data;
    lazy_string_concat_helper<Strings...> tail;

public:
    lazy_string_concat_helper(
        const LastString& data,
        lazy_string_concat_helper<Strings...> tail
    ) : data{data}, tail{tail} {}

    int size() const { return data.size() + tail.size(); }

    template <typename It>
    void save(It end) const {
        auto const begin = end - data.size();
        std::copy(std::cbegin(data), std::cend(data), begin);
        tail.save(begin);
    }

    operator std::string() const {
        std::string result(size(), '\0');
        save(result.end());
        return result;
    }

    lazy_string_concat_helper<std::string, LastString, Strings...>
    operator + (std::string const& other) const {
        return lazy_string_concat_helper<std::string, LastString, Strings...>(other, *this);
    }
};

template <>
class lazy_string_concat_helper<> {
public:
    lazy_string_concat_helper() {}

    int size() const { return 0; }

    template <typename It> void save(It) const {}

    lazy_string_concat_helper<std::string>
    operator + (std::string const& other) const {
        return lazy_string_concat_helper<std::string>(other, *this);
    }
};

lazy_string_concat_helper<> lazy_concat;

void run() {
    std::string name{ "Jane" }, surname{ "Smith" };
    
    auto const fullname = lazy_concat + surname + ", " + name;

    name = "John";

    assert("Smith, John" == std::string(fullname));

    std::cout << std::string(fullname) << std::endl;
}

} // test


#include <iostream>
int main() {
    std::cout << "test => [ok]" << std::endl; test::run(); std::cout << std::endl;

    return 0;
}
