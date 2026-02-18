#include <functional>
#include <iostream>
#include <thread>


struct Account {
    int amount;
};

void transferMoney(int amount, Account& from, Account& to) {
    from.amount -= amount;
    to.amount += amount;
}


int main() {
    Account account1{10}, account2{20};
    std::cout << "before: account1.amount = " << account1.amount << ", account2.amount = " << account2.amount << std::endl;

    std::thread t(transferMoney, 5, std::ref(account1), std::ref(account2));
    t.join();

    std::cout << "after: account1.amount = " << account1.amount << ", account2.amount = " << account2.amount << std::endl;
}
