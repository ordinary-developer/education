#include <bitset>
#include <iostream>


auto main() -> int {
    std::bitset<10> myBitset;

    myBitset.set(3);
    myBitset.set(6);
    myBitset[8] = true;
    myBitset[9] = myBitset[3];

    if (myBitset.test(3)) {
        std::cout << "Bit 3 is set!" << std::endl;
    }
    std::cout << myBitset << std::endl;

    return 0;
}
