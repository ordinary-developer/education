#include <iostream>
#include <string>


void getReservationData() {
    std::string guestName;
    int partySize;
    std::cout << "Name and number of guests: ";
    std::cin >> guestName >> partySize;
    std::cout << "Thank you, " << guestName << "." << std::endl;
    if (partySize > 10) {
        std::cout << "An extra gratuity will apply." << std::endl;
    }
}

auto main() -> int {
    std::string userInput;
    std::cin >> userInput;
    std::cout << "User input was " << userInput << std::endl;

    int userIntInput;
    std::cin >> userIntInput;
    std::cout << "User input was " << userIntInput << std::endl;

    getReservationData();

    return 0;
}
