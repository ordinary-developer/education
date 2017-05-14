void func(const int param) { } 

auto main() -> int {
    const double PI = 3.141592;

    int* ip;
    ip = new int[10];
    ip[4] = 5;

    const int* ip1;
    ip1 = new int[10];
    // does not compile
    // ip1[4] = 5; 
    
    int const* ip2;
    ip2 = new int[10];
    // does not compile
    // ip2[4] = 5;
    
    int* const ip3 = nullptr;
    // does not compile
    // ip3 = new int[10];
    //will produce an error
    // ip3[4] = 5;
    
    int* const ip4 = new int[10];
    ip4[4] = 5;

    int const* const ip5 = nullptr;
    // or
    const int* const ip6 = nullptr;

    int z;
    const int& zRef = z;
    // does not compile
    // zRef = 4;
    

    return 0;
}
