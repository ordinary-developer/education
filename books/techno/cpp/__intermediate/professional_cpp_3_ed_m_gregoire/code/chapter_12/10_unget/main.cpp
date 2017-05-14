#include <iostream>
#include <string>

void getReservationData() {
    std::string guestName;
    int partySize = 0;
    char ch;
    std::cin >> std::noskipws;
    while (std::cin >> ch) {
        if (isdigit(ch)) {
            std::cin.unget();
            if (std::cin.fail()) {
                std::cout << "unget() failed" << std::endl;
            }
            break;
        }
        guestName += ch;
    }
    std::cin >> partySize;

    std::cout << "Thank you '" << guestName
              << "', party of " << partySize << std::endl;
    if (partySize > 10) {
        std::cout << "An extra gratuity will apply." << std::endl;
    }
}

auto main() -> int {
    getReservationData();

    return 0;
}
