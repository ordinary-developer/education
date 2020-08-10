#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

typedef std::pair<std::string, bool> list_item;

std::string title(list_item const& item) {
    return item.first + std::string(item.second, '*');
}

bool is_selected(list_item const& item) { return item.second; }
bool is_not_selected(list_item const& item) { return not is_selected(item); }

template <typename It>
void move_selected_to(It first, It last, It dest) {
    std::stable_partition(first, dest, is_not_selected);
    std::stable_partition(dest, last, is_selected);
} 

int main() {
    std::vector<list_item> people {
        { "David",  true  },
        { "Jane",   false },
        { "Martha", false },
        { "Peter",  false },
        { "Rose",   true  },
        { "Tom",    true  }
    };

    move_selected_to(people.begin(), people.end(), people.begin() + 3);

    for (auto const& person : people)
        std::cout << title(person) << std::endl;

    return 0;
}
