#include "CableCompany.hpp"
#include <iostream>


auto main() -> int {
    CableCompany myCC;
    auto basic_pkg =    "1110000000";
    auto premium_pkg = "1111111111";
    auto sports_pkg =  "0000100111";

    myCC.addPackage("basic", std::bitset<NUM_CHANNELS>(basic_pkg));
    myCC.addPackage("premium", std::bitset<NUM_CHANNELS>(premium_pkg));
    myCC.addPackage("sports", std::bitset<NUM_CHANNELS>(sports_pkg));

    myCC.newCustomer("Marc G.", "basic");
    myCC.addPackageToCustomer("Marc G.", "sports");
    std::cout << myCC.getCustomerChannels("Marc G.") << std::endl;

    return 0;
}
