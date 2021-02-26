#include <algorithm>
#include <string>
#include <utility>
#include <vector>
#include <cassert>
namespace test {

typedef std::pair<std::string, bool> ListItem;

std::string title(ListItem const& item) {
    return item.first + std::string(item.second, '*');
}

bool isSelected(ListItem const& item) { return item.second; }
bool isNotSelected(ListItem const& item) { return not isSelected(item); }

template <typename It>
void moveSelectedTo(It first, It last, It dest) {
    std::stable_partition(first, dest, isNotSelected);
    std::stable_partition(dest, last, isSelected);
}

void run() {
    std::vector<ListItem> people {
        { "David", true },
        { "Jane", false },
        { "Martha", false },
        { "Peter", false },
        { "Rose", true },
        { "Tom", true } };

    moveSelectedTo(std::begin(people), std::end(people), std::begin(people) + 3);

    const std::vector<ListItem> expected {
        { "Jane", false },
        { "Martha", false },
        { "David", true },
        { "Rose", true },
        { "Tom", true },
        { "Peter", false } };
    assert(expected == people);
}

} // test


#include <iostream>
int main() {
    std::cout << "test => [ok]" << std::endl; test::run(); std::cout << std::endl;

    return 0;
}
