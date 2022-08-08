#include "BankDB.hpp"

#include <iostream>


auto main() -> int {
    BankDB db;

    db.addAccount(BankAccount(100, "Nicholas Solter"));
    db.addAccount(BankAccount(200, "Scott Kleper"));

    try {
        auto& account_1 = db.findAccount(100);
        std::cout << "Found account 100" << std::endl;
        account_1.setClientName("Nicholas A Solter");

        auto& account_2 = db.findAccount("Scott Kleper");
        std::cout << "Found account of Scott Kelper" << std::endl;

        auto& account_3 = db.findAccount(1000);
    }
    catch (const std::out_of_range&) {
        std::cout << "Unable to find the account" << std::endl;
    }

    return 0;
}
