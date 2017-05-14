#include <vector>
#include <string>

int main() {
    std::vector<std::string> vs;

    vs.push_back("xyzzy");
    vs.push_back(std::string("xyzzy"));

    vs.emplace_back("xyzzy");
    vs.emplace_back(50, 'x');

    return 0;
}
