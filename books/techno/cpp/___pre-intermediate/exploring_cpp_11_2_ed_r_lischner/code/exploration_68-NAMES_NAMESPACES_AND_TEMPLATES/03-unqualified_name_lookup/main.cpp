#include <iostream>

namespace outer {
    namespace inner {
        struct point { int x, y; };
        inline std::ostream& operator<<(std::ostream& stream,
                                        point const& p)
        {
            return stream << '(' << p.x << ", " << p.y << ')';
        }
    }
}

typedef int Integer;

int main() {
    const int multiplier{2};
    for (Integer i : {1, 2, 3}) 
        std::cout << outer::inner::point{ i, i * multiplier } << '\n';
    
    return 0;
}
