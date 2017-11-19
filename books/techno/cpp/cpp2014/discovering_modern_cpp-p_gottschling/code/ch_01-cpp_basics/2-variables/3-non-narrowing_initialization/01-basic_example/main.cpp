void example1() {
    // compiles despite narrowing (our risk)
    int i1 = 3.14; 

    // Narrowing ERROR: fractional part lost
    // int i1n = { 3.14 };
}

void example2() {
    // compiles despite narrowing (our risk)
    unsigned u2 = -3;

    // Narrowing ERROR: no negative values
    // unsigned u2n = { -3 };
}

void example3() {
    float f = { 3.14f };  // ok

    // error
    // float f1 = { 3.14 };

    double d = 3.14;
    // also error
    // float f2 = { d };
}

void example4() {
    unsigned u3 = { 3 };
    int i2 = { 2 };

    // unsigned u4 = { i2 }; // error
    // int i3 = { u3 }; // error
}

int main() {
    example1();
    example2();
    example3();
    example4();

    return 0;
}

