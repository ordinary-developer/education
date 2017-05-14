#include <string>

class Annotation {
    public:
        explicit Annotation(const std::string text)
            : value(std::move(text)) { }
    private:
        std::string value;
};

int main() {
    Annotation a("string");

    return 0;
}
