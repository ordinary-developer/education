// 1-st section
#include <vector>


// 2-nd section
class Widget { 

    private:
        int x { 0 };
        int y = 0;
        // an error will be
        // int z(0);
};


// 3-d section
#include <atomic>


// 4-th section
// ...


// 5-th section
class WidgetExample {
    public:
        WidgetExample() { }

        WidgetExample(int value) { } 

        void act() { }
};

int main() {
    // 1-st section
    std::vector<int> v { 1, 2, 3 };


    // 2-nd section
    // ...
    

    // [3-d section] region
    std::atomic<int> ai1 { 0 }; 
    std::atomic<int> ai2(0);
    // here an error will be
    // std::atomic<int> ai3 = 0;
    std::atomic<int> ai4 = { 0 };
    // end [3-d section] region
    

    // [4-th section] region
    double x, y, z;
    // prohibition of narrowing conversion
    // int sum1 { x + y + z };
    
    // value of the expression will be truncated to in
    int sum2(x + y + z);

    // ditto
    int sum3 = x + y + z;

    // also an error will arise
    // int sum4 = { x + y + z };
    // end [4-th section] region
    

    // [5-th section] region
    WidgetExample w1(10); // call widget's ctor with argument 10
    
    // declares a function named w2 that returns a Widget
    WidgetExample w2();
    // here an error will be
    // w2.act();
    
    WidgetExample w3{ }; // call Widget ctor with no args
    w3.act();
    // end [5-th section] region
}
