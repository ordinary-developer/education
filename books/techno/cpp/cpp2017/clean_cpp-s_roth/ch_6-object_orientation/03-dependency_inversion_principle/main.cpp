#include <string>
#include <memory>
namespace example01 {

class Owner {
    public:
        virtual ~Owner() = default;
        virtual std::string getName() const = 0;
};
using OwnerPtr = std::shared_ptr<Owner>;

class Account {
    public:
        void setOwner(OwnerPtr owner) {
            this->owner_ = owner;
        }

    private:
        OwnerPtr owner_;
};
using AccountPtr = std::shared_ptr<Account>;

class Customer : public Owner {
    public:
        void setAccount(AccountPtr account) {
            customerAccount_ = account;
        }

        virtual std::string getName() const override {
            return "";
        }

    private:
        AccountPtr customerAccount_;
};
using CustomerPtr = std::shared_ptr<Customer>;

void run() {
    CustomerPtr customer = std::make_shared<Customer>();
    AccountPtr account = std::make_shared<Account>();
    customer->setAccount(account);
    account->setOwner(customer);
}
}

int main() {
    example01::run();

    return 0;
}
