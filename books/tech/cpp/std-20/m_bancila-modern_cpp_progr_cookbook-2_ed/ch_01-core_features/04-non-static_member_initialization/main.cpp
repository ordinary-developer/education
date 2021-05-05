#include <string>
namespace example_01 { // -> the "how to do it" section

void run() {
    struct Control {
        enum class TxtVertAlign { Top, Middle, Bottom };
        enum class TxtHorAlign { Left, Middle, Right };

        const int DefaultHeight = 14;
        const int DefaultWidth = 80;

        TxtVertAlign valign = TxtVertAlign::Middle;
        TxtHorAlign halign = TxtHorAlign::Left;

        std::string txt;

        Control(std::string const & t) : txt(t) {}

        Control(std::string const & t, TxtVertAlign const va, TxtHorAlign const ha)
            : txt(t), valign(va), halign(ha) {}
    };
}    
} // example_01


#include <iostream>
#include <string>
namespace example_02 { // -> the "how it works..."

void run() {
    struct Point {
        double X, Y;
        Point(double const x = 0.0, double const y = 0.0) : X(x), Y(y) {}
    };
    
    struct foo {
        foo() { std::cout << "default ctor\n"; }
        foo(std::string const & txt) { std::cout << "ctor '" << txt << "\n"; }
        foo(foo const & other) { std::cout << "copy ctor\n"; }
        foo(foo&& other) { std::cout << "move ctor\n"; }
        foo& operator=(foo const & other) { std::cout << "assignment\n"; return *this; }
        foo& operator=(foo&& other) { std::cout << "move assignment\n"; return *this; }

        ~foo() { std::cout << "dtor\n"; }
    };

    {
        struct bar {
            foo f;

            bar(foo const & value) { f = value; }
        };

        foo f; bar b(f);
    }

    
    {
        std::cout << "\n";
        struct bar {
            foo f;
            bar(foo const & value) : f(value) {}
        };
        foo f; bar b(f);
    }

    {
        enum class TxtFlow { LeftToRight, RightToLeft };

        struct Control {
            int const DefaultHeight = 20;
            int const DefaultWidth = 100;

            TxtFlow txtFlow = TxtFlow::LeftToRight;
            std::string txt;

            Control(std::string t) : txt(t) {}
        };
    }

    {
        std::cout << "\n";
        struct bar {
            foo f{"default value"};

            bar() : f{"ctor initializer"} {}
        };
        bar b;
    }

}
} // example_02


int main() {
    example_01::run();
    example_02::run();

    return 0;
}
