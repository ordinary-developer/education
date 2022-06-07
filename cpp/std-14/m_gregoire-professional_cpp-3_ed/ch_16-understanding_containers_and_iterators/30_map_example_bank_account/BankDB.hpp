#ifndef BANK_DB_HPP
#define BANK_DB_HPP

#include <string>
#include <map>


class BankAccount {
    public:
        BankAccount(int accountNumber, const std::string& clientName) 
            : _accountNumber(accountNumber), _clientName(clientName) { }

        void setAccountNumber(int number) { _accountNumber = number; }
        int getAccountNumber() const { return _accountNumber; }

        void setClientName(const std::string& name) { _clientName = name; }
        const std::string& getClientName() { return _clientName; }
    private:
        int _accountNumber;
        std::string _clientName;
};

class BankDB {
    public:
        bool addAccount(const BankAccount& account);
        void deleteAccount(int accountNumber);
        BankAccount& findAccount(int accountNumber);
        BankAccount& findAccount(const std::string& name);

        void mergeDatabase(BankDB& db);
    private:
        std::map<int, BankAccount> _accounts;
};
#endif
