#include <iostream>
#include <vector>
#include <algorithm>

typedef std::vector<int>::iterator IterT;
typedef std::vector<int>::const_iterator ConstIterT;

int main() {
    std::vector<int> values = { 1970, 1983, 2011 };

    ConstIterT ci =
        std::find(static_cast<ConstIterT>(values.begin()),
                  static_cast<ConstIterT>(values.end()), 1983);
    // will not compile
    //values.insert(static_cast<IterT>(ci), 1998);
}
