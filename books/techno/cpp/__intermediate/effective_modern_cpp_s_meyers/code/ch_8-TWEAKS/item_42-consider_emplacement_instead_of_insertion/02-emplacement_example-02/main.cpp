#include <vector>
#include <string>

int main() {
    std::vector<std::string> vs;
    std::string queenOfDisco("Donna Summer");

    vs.push_back(queenOfDisco);
    vs.emplace_back(queenOfDisco);

    return 0;
}
