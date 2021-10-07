// region [how to do it]
#include <iostream>
#include <string>
namespace example_01 {
    
enum class TextVAlignment { Up, Middle, Bottom };
enum class TextHAlignment { Rigth, Left };
    
struct Control {
    int const DefaultHeight = 14;
    int const DefaultWidth = 80;
    
    std::string text;
    
    TextVAlignment valign = TextVAlignment::Middle;
    TextHAlignment halign = TextHAlignment::Left;
    
    Control(std::string const& t) : text{ t } {}
    Control(std::string const& t, TextVAlignment const va, TextHAlignment const ha)
        : text{ t }, valign{ va }, halign{ ha } {}
};
    
void run() {
    Control("example");
}
} // example_01
// endregion [how to do it]


// region [how it works]
namespace example_02 {
    
struct Point {
    double X, Y;
    Point(double const x = 0.0, double const y = 0.0) : X{ x }, Y{ y } {}
};
    
void run() {
    Point();
    
}    
} // example_02

#include <iostream>
#include <string>
namespace example_03 {
   
struct foo {
    foo() {
        std::cout << "default ctor" << std::endl;         
    }
    
    foo(std::string const& text) {
        std::cout << "ctor '" << text << "'" << std::endl;
    }
    
    foo(foo const & other) {
        std::cout << "copy ctor" << std::endl;
    }
    
    foo(foo&& other) {
        std::cout << "move constructor" << std::endl;
    }
    
    foo& operator=(foo const& other) {
        std::cout << "assignment" << std::endl;
        return *this;
    }
    
    foo& operator=(foo&& other) {
        std::cout << "move assignment" << std::endl;
        return *this;
    }
    
    ~foo() {
        std::cout << "dtor" << std::endl;
    }
};
    
struct bar {
    foo f;
    
    bar(foo const& value) {
        f = value;
    }
};
    
void run() {
    foo f{};
    bar b{ f };
}
    
} // example_03

#include <iostream>
#include <string>
namespace example_04 {
    
struct foo {
    foo() {
        std::cout << "default ctor" << std::endl;         
    }
    
    foo(std::string const& text) {
        std::cout << "ctor '" << text << "'" << std::endl;
    }
    
    foo(foo const & other) {
        std::cout << "copy ctor" << std::endl;
    }
    
    foo(foo&& other) {
        std::cout << "move constructor" << std::endl;
    }
    
    foo& operator=(foo const& other) {
        std::cout << "assignment" << std::endl;
        return *this;
    }
    
    foo& operator=(foo&& other) {
        std::cout << "move assignment" << std::endl;
        return *this;
    }
    
    ~foo() {
        std::cout << "dtor" << std::endl;
    }
};
    
struct bar {
    foo f;
    
    bar(foo const& value) 
        : f{ value } {}
};
    
void run() {
    foo f{};
    bar b{ f };
}
} // example_04

#include <string>
namespace example_05 {
    
enum class TextFlow { LeftToRight, RightToLeft };    
    
struct Control {
    int const DefaultHeight{ 20 };
    int const DefaultWidth{ 100 };
    
    TextFlow textFlow{ TextFlow::LeftToRight };
    std::string text;
    
    Control(std::string const& t) : text{ t } {}
};
    
void run() {
    Control("");
}    
} // example_05

#include <iostream>
#include <string>
namespace example_06 {
    
struct foo {
    foo() {
        std::cout << "default ctor" << std::endl;         
    }
    
    foo(std::string const& text) {
        std::cout << "ctor '" << text << "'" << std::endl;
    }
    
    foo(foo const & other) {
        std::cout << "copy ctor" << std::endl;
    }
    
    foo(foo&& other) {
        std::cout << "move constructor" << std::endl;
    }
    
    foo& operator=(foo const& other) {
        std::cout << "assignment" << std::endl;
        return *this;
    }
    
    foo& operator=(foo&& other) {
        std::cout << "move assignment" << std::endl;
        return *this;
    }
    
    ~foo() {
        std::cout << "dtor" << std::endl;
    }
};
    
struct bar {
    foo f{ "default value" };
    
    bar() : f{ "construct initializer" } {}
};
    
void run() {
    bar b{};
}    
} // example_06
// endregion [how it works]

#include <iostream>
int main() {
    example_01::run();
    example_02::run();
    example_03::run();
    example_04::run();
    example_05::run();
    example_06::run();
    
    std::cout << "DONE" << std::endl;
    
    return 0;
}

