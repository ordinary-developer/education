#define MXT_NAMESPACE_NULL_BEGIN()      namespace x {
#define MXT_NAMESPACE_NULL_END()        }

// directive
MXT_NAMESPACE_NULL_BEGIN()
MXT_NAMESPACE_NULL_END()

// not a directive
#define MXT_PI  3.1415926

#define MXT_INT_I(k)    int i = (k)

#include <cmath>
int main() {
    const double x = std::cos(MXT_PI);

    MXT_INT_I(0);

    return 0;
}
