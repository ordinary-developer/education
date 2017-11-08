#include <complex>
#include <string>

void example1() {
    auto var1 = 2;      // int
    auto var2 = 2u;     // unsigned
    auto var3 = 2l;     // long
    auto var4 = 2ul;    // unsigned long
    auto var5 = 2.0;    // double
    auto var6 = 2.0f;   // floag
    auto var7 = 2.0l;   // long double
}

void example2() {
    std::complex<float> z(1.3, 2.4), z2;
    // z2 = 2 * z;     // error: no int * complex<float>
    // z2 = 2.0 * z;   // error: no double * complex<floag>
    z2 = 2.0f * z;     // okay:  float * complex<float>
}

void example3() {
    long double third1 = 0.333333333333;
    long double third2 = 0.333333333333l;
}

void example4() {
    int o1 = 042;
    // int o2 = 084; // error

    int h1 = 0x42;
    int h2 = 0xfa;

    // cpp-14
    //int b1 = 0b11111010;

    // cpp-14
    // long d = 6'546'687'616'861'129l;
    // unsigned long ulx = 0x139'ae3b'2ab0'94f3;
    // int b = 0b101'1001'0011'1010'1101'1010'0001;
    // const long double pi = 3.141'592'653'589'793'238'462l;
}

void example5() {
    char s1[] = "Old C style";
    std::string s2 = "In C++ better like this";
    std::string s3 = "This is a very long an clumsy text"
                     "that is too long for one line.";
}


int main() {
    example1();
    example2();
    example3();
    example4();
    example5();

    return 0;
}
