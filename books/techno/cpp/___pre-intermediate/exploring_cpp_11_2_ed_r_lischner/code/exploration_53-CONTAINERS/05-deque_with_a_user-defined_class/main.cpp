#include "card.hpp"
#include "randomint.hpp"

#include <deque>
#include <iostream>


int main() {
    std::deque<card> deck(52);
    std::generate(deck.begin(), deck.end(), card_generator{});

    for (int i{ 0 }; i != 10; ++i) {
        std::deque<card>::iterator pick{ deck.begin() + 
                                         randomint{ 0, deck.size() - 1 }() };
        card computer_card{ *pick };
        deck.erase(pick);
        std::cout << "I picked " << computer_card << '\n';

        pick = deck.begin() + randomint{ 0, deck.size() - 1 }();
        card user_card{ *pick };
        deck.erase(pick);
        std::cout << "You picked " << user_card << '\n';

        if (acehigh_compare(computer_card, user_card))
            std::cout << "You win.\n";
        else
            std::cout << "I win.\n";
    }

    return 0;
}
