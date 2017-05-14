#include <string>
#include <vector>


class Widget {
    public:
        void addName(std::string newName) {
            if ((newName.length() >= MIN_LEN) &&
                (newName.length() <= MAX_LEN))
            {
                names.push_back(std::move(newName));
            }
        }

    private:
        static const unsigned int MIN_LEN = 10;
        static const unsigned int MAX_LEN = 100;

        std::vector<std::string> names;
};

int main() {
    Widget w;
    w.addName(std::string("abc"));
    w.addName(std::string("abcabcabcabcabc"));

    return 0;
}

