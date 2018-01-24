#include <string>
#include <memory>
#include <optional>
#include <iostream>

// dumb class
class CustomerId {
    public:
        bool isValid() const { return true; }
};

// dumb class
class Address {
    public:
        bool isValid() { return true; }
};

class Customer {
    public:
        virtual ~Customer() = default;

        virtual bool isPersistable() const noexcept {
            return (customerId_.isValid() and
                    not forename_.empty() and
                    not surname_.empty() and
                    billingAddress_->isValid() and
                    shippingAddress_->isValid());
        }

    private:
        CustomerId customerId_;
        std::string forename_;
        std::string surname_;
        std::shared_ptr<Address> billingAddress_;
        std::shared_ptr<Address> shippingAddress_;
};

class NotFoundCustomer final : public Customer {
    public:
        virtual bool isPersistable() const noexcept override {
            return false;
        }
};
using CusomterPtr = std::unique_ptr<Customer>;

using OptionalCustomer = std::optional<Customer>;

class CustomerRepository {
    public:
        OptionalCustomer findCustomerByName(std::string const& name) {
            return {};
        }
};

int main() {
    CustomerRepository repository{};
    auto optionalCustomer = repository.findCustomerByName("John Doe");

    try {
        auto customer = optionalCustomer.value();
    }
    catch (std::bad_optional_access& ex) {
        std::cerr << ex.what() << std::endl;
    }

    auto customer = optionalCustomer.value_or(NotFoundCustomer());

    return 0;
}
