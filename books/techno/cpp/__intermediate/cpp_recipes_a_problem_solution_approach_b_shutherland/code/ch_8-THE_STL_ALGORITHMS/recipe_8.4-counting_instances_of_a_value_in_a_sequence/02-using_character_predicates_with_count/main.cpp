#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>


int main() {
    std::string myString{ "Bruce Sutherland!" };
    
    auto numberOfCapitals = 
        std::count_if(myString.begin(),
                      myString.end(),
                      [](auto&& character) {
                        return static_cast<bool>(isupper(character));
                      });
    std::cout << "The number of capitals: " << numberOfCapitals 
              << std::endl;

    auto numberOfLowerCase = 
        std::count_if(myString.begin(),
                      myString.end(),
                      [](auto&& character) {
                        return static_cast<bool>(islower(character));
                      });
    std::cout << "The number of lower case letters: "
              << numberOfLowerCase << std::endl;

    auto numberOfAlphaNumerics = 
        std::count_if(myString.begin(),
                      myString.end(),
                      [](auto&& character) {
                        return static_cast<bool>(isalpha(character));
                      });
    std::cout << "The number of alpha numeric characters: "
              << numberOfAlphaNumerics << std::endl;

    auto numberOfPunctuationMarks = 
        std::count_if(myString.begin(),
                      myString.end(),
                      [](auto&& character) {
                        return static_cast<bool>(ispunct(character));
                      });
    std::cout << "The number of punctuation marks: " 
              << numberOfPunctuationMarks << std::endl;

    auto numberOfWhiteSpaceCharacters = 
        std::count_if(myString.begin(),
                      myString.end(),
                      [](auto&& character) {
                        return static_cast<bool>(isspace(character));
                      });
    std::cout << "The number of white space characters: "
              << numberOfWhiteSpaceCharacters << std::endl;

    return 0;
}
