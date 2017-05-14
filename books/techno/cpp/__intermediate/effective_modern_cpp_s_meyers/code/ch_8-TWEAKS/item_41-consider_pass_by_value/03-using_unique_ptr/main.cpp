#include <memory>
#include <string>

class Widget1 {
    public:
        void setPtr(std::unique_ptr<std::string>&& ptr) {
            p = std::move(ptr);
        }

    private:
        std::unique_ptr<std::string> p;
};

class Widget2 {
    public:
        void setPtr(std::unique_ptr<std::string> ptr) {
            p = std::move(ptr);
        }

    private:
        std::unique_ptr<std::string> p;
};

int main() {
    Widget1 w1;
    w1.setPtr(std::make_unique<std::string>("Modern c++"));

    Widget2 w2;
    w2.setPtr(std::make_unique<std::string>("Modern c++"));

    return 0;
}
