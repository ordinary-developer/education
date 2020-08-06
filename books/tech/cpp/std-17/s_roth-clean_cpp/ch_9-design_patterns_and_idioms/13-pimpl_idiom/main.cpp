#include <iostream>
#include <memory>
#include <string>

class Address;


class Customer {
    public:
        Customer();
        virtual ~Customer() = default;
    
        std::string getFullName() const;
        void setShippingAddress(Address const& address);
    
    private:
        class Impl;
        
        std::unique_ptr<Impl> impl_;
};


//--------------------------------
// a dumb class
class Address {};

// a dumb class
class Identifier {};

class Customer::Impl final {
    public:
        std::string getFullName() const;
        void setShippingAddress(Address const& address);
    
    private:
        Identifier customerId_;
        std::string forename_;
        std::string surname_;
        Address shippingAddress_;
};

std::string Customer::Impl::getFullName() const {
    return forename_ + " " + surname_;
}

void Customer::Impl::setShippingAddress(Address const& address) {
    shippingAddress_ = address;
}

Customer::Customer()
    : impl_{ std::make_unique<Customer::Impl>() } {}

std::string Customer::getFullName() const {
    return impl_->getFullName();
}

void Customer::setShippingAddress(Address const& address) {
    impl_->setShippingAddress(address);
}



int main() {
    auto customer = std::make_shared<Customer>();
    
    std::cout << "[OK] - all done" << std::endl;
    
    return 0;
}