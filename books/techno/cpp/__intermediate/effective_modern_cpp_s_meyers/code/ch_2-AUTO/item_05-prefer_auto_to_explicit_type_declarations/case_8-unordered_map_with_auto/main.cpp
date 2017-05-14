#include <unordered_map>
#include <string>

int main() {
    std::unordered_map<std::string, int> m;

    // without auto
    for (const std::pair<std::string, int>& p : m) {
    }
    // but must be
    // for (const std::pair<const std::string, int>& p : m)
    
    // with auto
    for (const auto& p : m) {
    }
}
