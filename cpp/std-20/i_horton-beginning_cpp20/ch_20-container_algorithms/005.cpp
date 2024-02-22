#include <iostream>
#include <map>
#include <string>
#include <string_view>
#include <vector>


using Words = std::vector<std::string_view>;
using WordCounts = std::map<std::string_view, std::size_t>;

Words extractWords(std::string_view text, std::string_view separators = " ,.!?\"\n");
WordCounts countWords(const Words & words);
void showWordCounts(const WordCounts & wordCounts);
std::size_t maxWordLength(const WordCounts & wordCounts);


int main() {
    std::string text;

    std::cout << "Enter a string terminated by *:" << std::endl;
    getline(std::cin, text, '*');

    const Words words{ extractWords(text) };
    if (words.empty()) {
        std::cout << "No words in text." << std::endl;
        return 0;
    }

    WordCounts wordCounts = countWords(words);
    showWordCounts(wordCounts);
}


Words extractWords(std::string_view text, std::string_view separators) {
    Words words;

    std::size_t start{ text.find_first_not_of(separators) };
    std::size_t end{};

    while (start != std::string_view::npos) {
        end = text.find_first_of(separators, start + 1);
        if (end == std::string_view::npos)
            end = text.length();
        words.push_back(text.substr(start, end - start));
        start = text.find_first_not_of(separators, end + 1);
    }

    return words;
}

WordCounts countWords(const Words & words) {
    WordCounts result;
    for (auto & word : words)
        ++result[word];
    return result;
}

void showWordCounts(const WordCounts & wordCounts) {
    const std::size_t fieldWidth{maxWordLength(wordCounts) + 1};
    const std::size_t wordsPerLine{5};

    std::size_t wordsInLine{};
    char prevInitial{};

    for (const auto & [word, count] : wordCounts) {
        if (count < 2) 
            continue;

        if((prevInitial && word[0] != prevInitial)
            || wordsInLine++ == wordsPerLine)
        {
            wordsInLine = 0;
            std::cout << std::endl;
        }

        //std::cout << std::format("{:>{}} ({:2})", word, fieldWidth, count);
        std::cout << word << "(" << count << ")" << std::endl;
        prevInitial = word[0];
    }

    std::cout << std::endl;
}

std::size_t maxWordLength(const WordCounts & wordCounts) {
    std::size_t max{};
    for (const auto & [word, count] : wordCounts)
        if (count >= 2 && max < word.length())
            max = word.length();
    return max;
}

