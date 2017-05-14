#include "BuddyList.hpp"

#include <iostream>


auto main() -> int { 
    BuddyList buddies;

    buddies.addBuddy("Harry Potter", "Ron Weasley");
    buddies.addBuddy("Harry Potter", "Hermione Granger");
    buddies.addBuddy("Harry Potter", "Hagrid");
    buddies.addBuddy("Harry Potter", "Draco Malfoy");

    buddies.removeBuddy("Harry Potter", "Draco Malfoy");

    buddies.addBuddy("Hagrid", "Harry Potter");
    buddies.addBuddy("Hagrid", "Ron Weasley");
    buddies.addBuddy("Hagrid", "Hermione Granger");

    auto harryBuddies = buddies.getBuddies("Harry Potter");
    std::cout << "Harry's friends: " << std::endl;
    for (const auto& name : harryBuddies) {
        std::cout << "\t" << name << std::endl;
    }

    return 0;
}
