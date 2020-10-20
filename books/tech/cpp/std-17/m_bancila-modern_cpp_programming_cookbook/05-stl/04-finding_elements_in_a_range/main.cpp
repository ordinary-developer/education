#include <vector>
#include <algorithm>
#include <iostream>
namespace example_01 { // std::find
void run() {
    std::vector<int> const v{ 1, 1, 2, 3, 5, 8, 13 };
    auto const it = std::find(std::cbegin(v), std::cend(v), 3);
    if (std::cend(v) != it) {
        std::cout << "found " << *it
            << " at index " <<  std::distance(std::cbegin(v), it) << std::endl;
    }
}
} // example_02    
    

#include <vector>
#include <algorithm>
#include <iostream>
namespace example_02 { // std::find_if
void run() {
    std::vector<int> const v{ 1, 1, 2, 3, 5, 8, 13 };
    auto const it = std::find_if(std::cbegin(v), std::cend(v),
        [](int const num) { return num > 10; });
    if (std::cend(v) != it) {
        std::cout << "found " << *it
            << " at index " <<  std::distance(std::cbegin(v), it) << std::endl;
    }
}
} // example_02
    
    
#include <vector>
#include <algorithm>
#include <iostream>
namespace example_03 { // std::find_if_not
void run() {
    std::vector<int> const v{ 1, 1, 2, 3, 5, 8, 13 };
    auto const it = std::find_if_not(std::cbegin(v), std::cend(v),
        [](int const num) { return num % 2 == 1; });
    if (std::cend(v) != it) {
        std::cout << "found " << *it
            << " at index " <<  std::distance(std::cbegin(v), it) << std::endl;
    }
}
} // example_03


#include <vector>
#include <algorithm>
#include <iostream>
namespace example_04 { // std::find_first_of
void run() {    
    std::vector<int> const v{ 1, 1, 2, 3, 5, 8, 13 };
    std::vector<int> const p{ 5, 7, 11 };
    
    auto const it = std::find_first_of(std::cbegin(v), std::cend(v),
        std::cbegin(p), std::cend(p));
    if (std::cend(v) != it) {
        std::cout << "found " << *it
            << " at index " << std::distance(std::cbegin(v), it) << std::endl;
    }
}
} // example_04
    
    
#include <vector>
#include <algorithm>
#include <iostream>
namespace example_05 { // std::find_end
void run() {
    std::vector<int> const v1{ 1, 1, 0, 0, 1, 0, 1, 0, 1, 0, 1, 1 };
    std::vector<int> const v2{ 1, 0, 1 };
    
    auto const it = std::find_end(std::cbegin(v1), std::cend(v1),
        std::cbegin(v2), std::cend(v2));
    if (std::cend(v1) != it) {
        std::cout << "found at index "
            << std::distance(std::cbegin(v1), it) << std::endl;
    }
}
} // example_01


#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
namespace example_06 { // std::search
void run() {
    using namespace std::literals::string_literals;
    auto const text = "The quick brow fox jumps over the lazy dog"s;
    auto const word = "over"s;
    
    auto const it = std::search(std::cbegin(text), std::cend(text),
        std::cbegin(word), std::cend(word));
    if (std::cend(text) != it) {
        std::cout << "found " << word
            << " at index "
            << std::distance(std::cbegin(text), it) << std::endl;
    }
}
} // example_06


#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
namespace example_07 { // std::search with std::boyer_moore_searcher
void run() {
    using namespace std::literals::string_literals;
    
    auto const text = "The quick brown fox jumps over the lazy dog"s;
    auto const word = "over"s;
    
    auto const it = std::search(
        std::cbegin(text), std::cend(text),
        std::boyer_moore_searcher(std::cbegin(word), std::cend(word)));
    if (std::cend(text) != it) {
        std::cout << "found " << word
            << " at index "
            << std::distance(std::cbegin(text), it) << std::endl;
    }
        
}
} // example_07


#include <vector>
#include <algorithm>
#include <iostream>
namespace example_08 { // std::search_n
void run() {
    std::vector<int> const v{ 1, 1, 0, 0, 1, 0, 1, 0, 1, 0, 1, 1 };
    
    auto const it = std::search_n(std::cbegin(v), std::cend(v), 2, 0);
    if (std::cend(v) != it) {
        std::cout << "found at index "
            << std::distance(std::cbegin(v), it) << std::endl;
    }
}
} // example_08


#include <vector>
#include <algorithm>
#include <iostream>
namespace example_09 { // std::adjacent_find
inline bool IsPrime(int const number) {
    if (((!(number & 1)) && number != 2) || (number < 2) || (number % 3 == 0 && number != 3))
        return (false);

    for (int k = 1; 36 * k*k - 12 * k < number; ++k)
        if ((number % (6 * k + 1) == 0) || (number % (6 * k - 1) == 0))
            return (false);

    return true;
}

void run() {
    {
    std::vector<int> const v{ 1, 1, 2, 3, 5, 8, 13 };
    auto const it = std::adjacent_find(std::cbegin(v), std::cend(v));
    if (std::cend(v) != it) {
        std::cout << "found at index "
            << std::distance(std::cbegin(v), it) << std::endl;
    }
    }
    
    {
    std::vector<int> const v{ 1, 1, 2, 3, 5, 8, 13 };
    auto const it = std::adjacent_find(
        std::cbegin(v), std::cend(v),
        [](int const a, int const b) { return IsPrime(a) and IsPrime(b); });
    if (std::cend(v) != it) {
        std::cout << "found at index "
            << std::distance(std::cbegin(v), it) << std::endl;
    }
    }
}
} // example_09


#include <vector>
#include <algorithm>
#include <iostream>
namespace example_10 { // std::binary_search
void run() {
    std::vector<int> const v{ 1, 1, 2, 3, 5, 8, 13 };
    auto const success = std::binary_search(std::cbegin(v), std::cend(v), 8);
    if (success)
        std::cout << "found" << std::endl;
}
} // example_10


#include <vector>
#include <algorithm>
#include <iostream>
namespace example_11 { // std::lower_bound
void run() {
    std::vector<int> const v{ 1, 1, 2, 3, 5, 8, 13 };
    
    auto const it = std::lower_bound(std::cbegin(v), std::cend(v), 1);
    if (std::cend(v) != it)
        std::cout << "lower bound at "
            << std::distance(std::cbegin(v), it) << std::endl;
}
} // example_11


#include <vector>
#include <algorithm>
#include <iostream>
namespace example_12 { // std::upper_bound
void run() {
    std::vector<int> const v{ 1, 1, 2, 3, 5, 8, 13 };
    
    auto const it = std::upper_bound(std::cbegin(v), std::cend(v), 1);
    if (std::cend(v) != it)
        std::cout << "upper bound at "
            << std::distance(std::cbegin(v), it) << std::endl;
}
} // example_12


#include <vector>
#include <algorithm>
#include <iostream>
namespace example_13 { // std::equal_range
void run() {
    std::vector<int> const v{ 1, 1, 2, 3, 5, 8, 13 };
    
    auto const bounds = std::equal_range(std::cbegin(v), std::cend(v), 1);
    std::cout << "range between indices "
        << std::distance(std::cbegin(v), bounds.first)
        << " and "
        << std::distance(std::cbegin(v), bounds.second)
        << std::endl;
}
} // example_13


#include <iostream>
int main() {
    std::cout << "[ok] - example_01 =>" << std::endl; example_01::run(); std::cout << std::endl << std::endl;
    std::cout << "[ok] - example_02 =>" << std::endl; example_02::run(); std::cout << std::endl << std::endl;
    std::cout << "[ok] - example_03 =>" << std::endl; example_03::run(); std::cout << std::endl << std::endl;
    std::cout << "[ok] - example_04 =>" << std::endl; example_04::run(); std::cout << std::endl << std::endl;
    std::cout << "[ok] - example_05 =>" << std::endl; example_05::run(); std::cout << std::endl << std::endl;
    std::cout << "[ok] - example_06 =>" << std::endl; example_06::run(); std::cout << std::endl << std::endl;
    std::cout << "[ok] - example_07 =>" << std::endl; example_07::run(); std::cout << std::endl << std::endl;
    std::cout << "[ok] - example_08 =>" << std::endl; example_08::run(); std::cout << std::endl << std::endl;
    std::cout << "[ok] - example_09 =>" << std::endl; example_09::run(); std::cout << std::endl << std::endl;
    std::cout << "[ok] - example_10 =>" << std::endl; example_10::run(); std::cout << std::endl << std::endl;
    std::cout << "[ok] - example_11 =>" << std::endl; example_11::run(); std::cout << std::endl << std::endl;
    std::cout << "[ok] - example_12 =>" << std::endl; example_12::run(); std::cout << std::endl << std::endl;
    std::cout << "[ok] - example_13 =>" << std::endl; example_13::run(); std::cout << std::endl << std::endl;
    
    return 0;
}
