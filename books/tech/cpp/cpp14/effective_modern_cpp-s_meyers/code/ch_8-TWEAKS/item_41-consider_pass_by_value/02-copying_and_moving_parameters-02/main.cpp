#include <memory>
#include <string>
#include <vector>

class Widget {
    public:
        template <typename T>
        void addName(T&& newName) {
            names.push_back(std::forward<T>(newName));
        }

    private:
        std::vector<std::string> names;
};

int main() {
    Widget w;
    std::string s = "jack";
    w.addName(s);
    w.addName(std::string("jack"));

    return 0;
}
