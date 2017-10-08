namespace example01 {

namespace GUI {
    class window{};
}

namespace statistics {
    class window{};
}

void run() {
    GUI::window win1{};
    (void)win1;

    statistics::window win2{};
    (void)win2;
}
} // example01

namespace example02 {

struct global{};

namespace c1 {
    struct clc{};
    namespace c2 {
        struct c2c{};
        struct cc {
            global x;
            clc y;
            c2c z;
        };
    } // c2
} // c1

void run() {
    global var1{};
    (void)var1;

    c1::clc var2{};
    (void)var2;

    c1::c2::c2c var3{};
    (void)var3;

    c1::c2::cc var4;
    (void)var4;
}
} // example02

namespace example03 {

struct same{};

namespace c1 {
    struct same{};
    namespace c2 {
        struct same{};
        struct csame {
            example03::same x;
            c1::same y;
            same z;
        };
    } // c2
} // c1

void run() {
    same var1{};
    (void)var1;

    c1::same var2{};
    (void)var2;

    c1::c2::same var3{};
    (void)var3;

    c1::c2::csame var4;
    (void)var4;
}
} // example03

namespace example04 {

struct same{};

namespace c1 {
    struct same{};
    namespace c2 {
        struct same{};
        namespace c1{} // hides ::c1
        struct csame {
            example04::same x;
            // c1::same y; // Error: c1::c2::c1::same is not defined
            example04::c1::same y;
            same z;
        };
    } // c2
} // c1

void run() {
    same var1{};
    (void)var1;

    c1::same var2{};
    (void)var2;

    c1::c2::same var3{};
    (void)var3;

    c1::c2::csame var4;
    (void)var4;
}

} // example04

namespace example05 {
namespace c1 {
    struct cc{};
    namespace c2 {
        struct cc{};
    } // c2
} // c1

void fun1() {
    using c1::c2::cc;

    cc x{};
    (void)x;
}

void fun2() {
    using namespace c1::c2;

    cc x{};
    (void)x;
}

void fun3() {
    namespace c1_newName = c1;
    namespace c2_newName = c1::c2;

    c1_newName::cc x{};
    (void)x;

    c2_newName::cc y{};
    (void)y;
}

void run() {
    fun1();
    fun2();
    fun3();
}
} // example05

int main() {
    example01::run();
    example02::run();
    example03::run();
    example04::run();
    example05::run();

    return 0;
}
