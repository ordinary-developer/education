#include <algorithm>
#include <iostream>
#include <string>

int main() {
    std::string myString{ "Bruce Sutherland" };
    auto found = std::find(myString.begin(), myString.end(), 'e');
    while (myString.end() != found) {
        std::cout << "Found: " << *found << std::endl;
        found = std::find(found + 1, myString.end(), 'e');
    }

    return 0;
}
