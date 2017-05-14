#include <memory>
#include <vector>

void c_plus_plus_14() {
    std::vector<double> data;

    auto func = [data = std::move(data)]
                { };
}

void c_plus_plus_11() {
    std::vector<double> data;

    auto func = 
        std::bind(
            [](const std::vector<double>& data) { },
            std::move(data)
        );
}

void c_plus_plus_11_second_way() {
    std::vector<double> data;

    auto func = 
        std::bind(
            [](std::vector<double>& data) mutable { },
            std::move(data)
        );
}

int main() {
    c_plus_plus_14();
    c_plus_plus_11();
    c_plus_plus_11_second_way();

    return 0;
}
