#include <vector>
// old style
enum Color { black, white, red };

std::vector<std::size_t> primeFactors(std::size_t x) 
{
    std::vector<std::size_t> result;
    return result;
}

int main() {
    Color c = red;

    // compare Color to double
    if (c < 14.5) { 
        // coerce Color to std::size_t
        auto factors = primeFactors(c);
    }
}
