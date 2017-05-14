#include <vector>
#include <string>


class Element {
    public:
        Element(int i, const std::string& str)
            : mI(i), mStr(str) { }
    private:
        int mI;
        std::string mStr;
};

auto main() -> int {
    std::vector<Element> vec;

    Element myElement(12, "Twelve");
    vec.push_back(myElement);

    vec.push_back(std::move(myElement));
    vec.push_back(Element(12, "Twelve"));
    vec.push_back({12, "Twelve"});

    vec.emplace_back(12, "Twelve");

    return 0;
}
