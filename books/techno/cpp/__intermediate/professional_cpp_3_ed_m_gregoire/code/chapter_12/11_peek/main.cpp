#include <iostream>
#include <string>

void getReservationData() {
    std::string guestName;
    int partySize = 0;
    char ch;
    std::cin >> std::noskipws;
    while (true) {
        ch = static_cast<char>(std::cin.peek());
        if (!std::cin.good()) {
            break;
        }
        if (isdigit(ch)) {
            break;
        }
        std::cin >> ch;
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
