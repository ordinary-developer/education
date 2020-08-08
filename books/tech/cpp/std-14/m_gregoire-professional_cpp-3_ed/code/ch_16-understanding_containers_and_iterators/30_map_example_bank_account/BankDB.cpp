#include "BankDB.hpp"

#include <stdexcept>


bool BankDB::addAccount(const BankAccount& account) {
    auto res = _accounts.insert(
            std::make_pair(account.getAccountNumber(), account));
    return res.second;
}

void BankDB::deleteAccount(int accountNumber) {
    _accounts.erase(accountNumber);
}

BankAccount& BankDB::findAccount(int accountNumber) {
    auto iterator = _accounts.find(accountNumber);
    if (end(_accounts) == iterator) {
        throw std::out_of_range("No account with that number.");
    }
    return iterator->second;
}

BankAccount& BankDB::findAccount(const std::string& name) {
    for (auto& p : _accounts) {
        if (p.second.getClientName() == name) {
            return p.second;
        }
    }

    throw std::out_of_range("No account with that name.");
}

void BankDB::mergeDatabase(BankDB& db) {
    _accounts.insert(begin(db._accounts), end(db._accounts));
    db._accounts.clear();
}
