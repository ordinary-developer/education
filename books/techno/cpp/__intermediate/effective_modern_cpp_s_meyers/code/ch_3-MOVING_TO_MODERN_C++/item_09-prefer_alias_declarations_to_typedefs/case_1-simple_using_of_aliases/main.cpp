#include <memory>
#include <unordered_map>
#include <string>

typedef 
    std::unique_ptr<std::unordered_map<std::string, std::string>> 
        UPtrMapSS;

using UPtrMapSS = 
    std::unique_ptr<std::unordered_map<std::string, std::string>>; 


int main() {
    UPtrMapSS object;
}
