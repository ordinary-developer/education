#include <iostream>


class Widget {
    public:
        void setName(const std::string& newName) 
        {
            name = newName;
        }

        void setName(std::string&& newName)
        {
            name = std::move(newName);
        }

    private:
        std::string name;
};

int main() {
    Widget w;
    w.setName("Adela Novak");

    return 0;
}
