#include <iostream>
#include <functional>
#include <thread>

struct Account {
    int amount;
};

void transferMoney(int amount, Account& from, Account& to) {
    from.amount -= amount;
    to.amount += amount;
}

int main() {
    Account acc1{10}, acc2{20};
    std::cout << "before: account1.amount = " << acc1.amount << ", account2.amount = " << acc2.amount << std::endl;

    std::thread t(transferMoney, 5, std::ref(acc1), std::ref(acc2));
    t.join();

    std::cout << "after: account1.amount = " << acc1.amount << ", account2.amount = " << acc2.amount << std::endl;
}
