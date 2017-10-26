#include <iostream>
#include <sstream>
#include <string>

class Muffin {
    public:
        const std::string& getDescription() const;
        void setDescription(const std::string& inDesc);

        int getSize() const;
        void setSize(int inSize);

        bool getHasChocolateChips() const;
        void setHasChocolateChips(bool inChips);

        void output();

    private:
        std::string mDesc;
        int mSize;
        bool mHasChocolateChips;
};

const std::string& Muffin::getDescription() const { return mDesc; }
void Muffin::setDescription(const std::string& inDesc) { mDesc = inDesc; }
int Muffin::getSize() const { return mSize; }
void Muffin::setSize(int inSize) { mSize = inSize; }
bool Muffin::getHasChocolateChips() const { return mHasChocolateChips; }
void Muffin::setHasChocolateChips(bool inChips) { mHasChocolateChips = inChips; }

void Muffin::output() {
    printf("%s, Size is %d, %s\n", getDescription().c_str(), getSize(),
            (getHasChocolateChips() ? "has chips" : "no chips"));
}

Muffin createMuffin(std::istringstream& inStream) {
    Muffin muffin;
    std::string description;
    int size;
    bool hasChips;

    inStream >> description >> size >> std::boolalpha >> hasChips;
    muffin.setSize(size);
    muffin.setDescription(description);
    muffin.setHasChocolateChips(hasChips);

    return muffin;
}

auto main() -> int {
    std::cout << "First, let's create a muffin in code and output it. " << std::endl;

    Muffin m;
    m.setDescription("Gian_Blueberry_Muffin");
    m.setSize(42);
    m.setHasChocolateChips(false);
    m.output();

    std::cout << "Now we'll create a muffin from a string stream" << std::endl;
    std::istringstream instream("My_Muffin 2 true");
    Muffin m2 = createMuffin(instream);
    m2.output();

    return 0;
}
