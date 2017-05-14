// without using the keyword "delete" 
bool isLucky1(int number) { }

// with using the keyword "delete"
bool isLucky2(int number) { }
bool isLucky2(char) = delete;
bool isLucky2(bool) = delete;
bool isLucky2(double) = delete;

int main() {
    // we can call all overloaded functions
    isLucky1('a');
    isLucky1(true);
    isLucky1(3.5);

    // we can'tcall overloaded functions
    // isLucky2('a');
    // isLucky2(true);
    // isLucky2(3.5);
}

