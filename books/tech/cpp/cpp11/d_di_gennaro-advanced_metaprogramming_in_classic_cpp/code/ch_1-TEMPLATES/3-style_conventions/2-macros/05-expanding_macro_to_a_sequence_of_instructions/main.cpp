#include <memory>
#include <iostream>

// not correct example
namespace example1 {
    #define MXT_SORT1(a, b)     if  ((b) < (a)) std::swap((a), (b))
    #define MXT_SORT2(a, b, c)  \
        MXT_SORT1((a), (b));  MXT_SORT1((a), (c)); MXT_SORT1((b), (c))

    void run() {
        std::cout << "example1 => " << std::endl;
        int a = 5, b = 2, c = 3;
        MXT_SORT2(a, b, c);

        std::cout << "a = " << a << std::endl;
        std::cout << "b = " << b << std::endl;
        std::cout << "c = " << c << std::endl;
    }
};

// correct example
namespace example2 {
    #define MXT_SORT3(a, b)     if  ((b) < (a)) std::swap((a), (b))
    #define MXT_SORT4(a, b, c)  \
      do { MXT_SORT3((a), (b)); MXT_SORT3((a), (c)); MXT_SORT3((b), (c)); } \
      while (false)

    void run() {
        std::cout << "example2 => " << std::endl;
        int a = 5, b = 2, c = 3;
        MXT_SORT4(a, b, c);

        std::cout << "a = " << a << std::endl;
        std::cout << "b = " << b << std::endl;
        std::cout << "c = " << c << std::endl;

        // error : b will be incremented more than once
        // MXT_SORT3(a, b++, c);
    }
};

// tackling the "if" macro problem
namespace example3 {
    #define MXT_SORT5(a, b)     if ((b) < (a)) std::swap((a), (b)); else
};

// even better
namespace example4 {
   #define MXT_SORT6(a, b)  if (!((b) < (a))) { } else std::swap((a), (b)) 
};



int main() {
    example1::run();
    example2::run();

    return 0;
}

