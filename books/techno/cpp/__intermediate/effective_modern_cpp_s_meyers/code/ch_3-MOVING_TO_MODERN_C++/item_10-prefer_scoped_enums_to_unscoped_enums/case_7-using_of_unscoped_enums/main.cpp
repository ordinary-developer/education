#include <tuple>
#include <string>

using UserInfo = std::tuple<std::string, 
                            std::string,
                            std::size_t>;

// unscoped enumeration
enum unscopedUserInfoFields { unscopedName, 
                              unscopedEmail,
                              unscopedReputation
                            };

// scoped enumeration
enum class scopedUserInfoFields { scopedName,
                                  scopedEmail,
                                  scopedReputation
                                };

int main() {
    UserInfo uInfo;
    
    // without enumerations
    auto value_1 = std::get<1>(uInfo);

    // with an unscoped enumeration
    auto value_2 = std::get<unscopedEmail>(uInfo);

    // with a scoped enumeration
    auto value_3 = std::get<static_cast<std::size_t>(
                 scopedUserInfoFields::scopedEmail)>(uInfo);
}
