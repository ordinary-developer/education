#include <vector>

enum class Color { black, white, red };

std::vector<std::size_t> primeFactors(std::size_t x) 
{
    std::vector<std::size_t> result;
    return result;
}

int main() {
    Color c = Color::red;

    // here two errors will be
    // 1-st: in conditional statement
    // 2-nd: in primeFactors calling
    // if (c < 14.5) {
    //    auto factors = primeFactors(c);
    // }
   
    if (static_cast<double>(c) < 14.5) {
        auto factors = primeFactors(static_case<std::size_t>(c));
    }
}



