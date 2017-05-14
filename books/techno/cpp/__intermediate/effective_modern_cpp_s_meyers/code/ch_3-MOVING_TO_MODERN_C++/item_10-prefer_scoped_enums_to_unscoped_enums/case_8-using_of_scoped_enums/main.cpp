#include <tuple>
#include <string>
//#include <type_traits>
#include <iostream>

using UserInfo = std::tuple<std::string,
                            std::string,
                            std::size_t>;

enum class UserInfoFields { uiName, uiEmail, uiReputation };

// C++11
template <typename E>
constexpr typename std::underlying_type<E>::type
    toUType1(E enumerator) noexcept
{
    return 
        static_cast<typename
                    std::underlying_type<E>::type>(enumerator);
}   

// C++14
template <typename E>
constexpr std::underlying_type_t<E>
    toUType2(E enumerator) noexcept
{
    return static_cast<std::underlying_type_t<E>>(enumerator);
}

// another C++14 
template <typename E>
constexpr auto
    toUType3(E enumerator) noexcept
{
    return static_cast<std::underlying_type_t<E>>(enumerator);
}

int main() {
    UserInfo uInfo;

    auto value1 = std::get<toUType1(UserInfoFields::uiEmail)>(uInfo);

    auto value2 = std::get<toUType2(UserInfoFields::uiEmail)>(uInfo);

    auto value3 = std::get<toUType3(UserInfoFields::uiEmail)>(uInfo);

    std::cout << value1 << std::endl;
    std::cout << value2 << std::endl;
    std::cout << value3 << std::endl;
}

