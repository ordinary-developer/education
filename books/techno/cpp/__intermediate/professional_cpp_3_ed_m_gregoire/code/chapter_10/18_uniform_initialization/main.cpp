#include <vector>
#include <string>

struct CircleStruct {
    int x, y;
    double radius;
};

class CircleClass {
    public:
        CircleClass(int x, int y, double radius) 
            : mX(x), mY(y), mRadius(radius) { }
    private:
        int mX, mY;
        double mRadius;
};

void func(int i) { }

class MyClass {
    public:
        MyClass() : mArray{0, 1, 2, 3} { }
    private:
        int mArray[4];
};

auto main() -> int {
    // old style
    CircleStruct myCircle1 = {10, 10, 2.5};
    CircleClass myCircle(10, 10, 2.5);
    // new style
    CircleStruct myCircle3 = {10, 10, 2.5};
    CircleClass myCircle4 = {10, 10, 2.5};
    // another variant
    CircleStruct myCircle5{10, 10, 2.5};
    CircleClass myCircle6{10, 10, 2.5};

    int a = 3;
    int b(3);
    int c = {3};
    int d{3};

    int e{};

    int x = 3.14;
    func(3.14);
    // will be a warning
    //int x2 = {3.14};
    //func({3.14});

    std::vector<std::string> myVec;
    myVec.push_back("String 1");
    myVec.push_back("String 2");
    myVec.push_back("String 3");

    std::vector<std::string> myVec3 = { "String 1", "String 2", "String 3" };

    int* pArray = new int[4] { 0, 1, 2, 3 };

    return 0;
}
