#include <memory>
#include <string>
#include <vector>

class Widget {
    public:
        void addName(const std::string& newName) {
            names.push_back(newName);
        }

        void addName(std::string&& newName) {
            names.push_back(std::move(newName));
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
