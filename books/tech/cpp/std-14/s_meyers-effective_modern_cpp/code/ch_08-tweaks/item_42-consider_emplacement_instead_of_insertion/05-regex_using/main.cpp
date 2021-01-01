#include <regex>
#include <vector>

int main() {
    std::vector<std::regex> regexes;

    regexes.emplace_back(nullptr); // will comple
    // equivalent to
    std::regex r(nullptr);
    regexes.emplace_back(r);

    // will not compile
    //regexes.push_back(nullptr);

    // will not compile
    //std::regex r = nullptr;
    
    std::regex upperCaseWord("[A-Z]+");

    return 0;
}

