#include <algorithm>
#include <iostream>
#include <iterator>
#include <locale>
#include <string>
#include <vector>

void sort_words(std::vector<std::string> words, std::locale loc) {
    std::sort(words.begin(), words.end(), loc);
    std::cout << loc.name() << ":\n";
    std::copy(words.begin(), 
              words.end(),
              std::ostream_iterator<std::string>(std::cout, "\n"));
}

int main() {
    std::vector<std::string> words {
        "circus",
        "\u00e5ngstrom",
        "\u00e7irc\u00ea",
        "angle",
        "assen",
        "ether",
        "\u00e6ther",
        "aether",
        "e\u00defen"
    };

    sort_words(words, std::locale::classic());

    // here errors will be
    // sort_words(words, std::locale{ "en_GB.utf8" });
    // sort_words(words, std::locale{ "no_NO.utf8" });

    return 0;
}
