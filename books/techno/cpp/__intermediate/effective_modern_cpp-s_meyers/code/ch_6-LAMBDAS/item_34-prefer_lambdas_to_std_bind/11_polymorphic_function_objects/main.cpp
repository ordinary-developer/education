#include <functional>
using namespace std::placeholders;

class PolyWidget {
    public:
        template <typename T>
        void operator() (const T& param) { }
};

int main() {
    PolyWidget pw;

    auto boundPW = std::bind(pw, _1);

    boundPW(1930);
    boundPW(nullptr);
    boundPW("Rosebud");

    // using a C++14 lambda
    auto boundPWL = [pw](const auto& param)
    {
        pw(param);
    };

    return 0;
}
