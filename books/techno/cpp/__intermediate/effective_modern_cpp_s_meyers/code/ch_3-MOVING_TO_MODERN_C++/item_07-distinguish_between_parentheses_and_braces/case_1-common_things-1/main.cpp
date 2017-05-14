class Widget { };

int main() {
    // 1-st section
    int x(0);      // initializer is in parentheses
    int y = 0;     // initializer follows "="
    int z1 { 0 };   // initializer is in braces
    int z2 = { 0 }; // initializer uses "=" and braces

    // 2-nd section
    Widget w1;      // call the default constructor
    Widget w2 = w1; // not an assignment; calls the copy constructor
    w1 = w2;        // an assignment; calls the copy operator
}
