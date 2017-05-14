#include <list>
#include <string>
#include <iostream>


auto main() -> int {
    std::list<std::string> dictionary { "aardvark", "ambulance" };
    std::list<std::string> bWords { "bathos", "balderdash" };

    dictionary.push_back("canticle");
    dictionary.push_back("consumersim");

    if (bWords.size() > 0) {
        auto iterLastB = --(std::end(bWords));
        auto it = std::begin(dictionary);
        for (; it != std::end(dictionary); ++it) {
            if (*it > *iterLastB) {
                break;
            }
        }
        dictionary.splice(it, bWords);
    }

    for (const auto& word : dictionary) {
        std::cout << word << std::endl;
    }

    return 0;
}
