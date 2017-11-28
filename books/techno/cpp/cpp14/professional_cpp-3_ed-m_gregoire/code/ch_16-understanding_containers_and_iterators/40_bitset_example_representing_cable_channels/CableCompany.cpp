#include "CableCompany.hpp"

#include <stdexcept>


void CableCompany::addPackage(const std::string& packageName,
        const std::bitset<NUM_CHANNELS>& channels) 
{
    _packages.insert({ packageName, channels });
}

void CableCompany::removePackage(const std::string& packageName) {
    _packages.erase(packageName);
}

void CableCompany::newCustomer(
        const std::string& name, const std::string& package) 
{
    auto iterator = _packages.find(package);
    if (end(_packages) == iterator) {
        throw std::out_of_range("Invalid package");
    }

    auto result = _customers.insert({ name, iterator->second });
    if (!result.second) {
        throw std::invalid_argument("Duplicate customer");
    }
}

void CableCompany::newCustomer(const std::string& name,
    const std::bitset<NUM_CHANNELS>& channels) 
{
    auto result = _customers.insert({ name, channels });
    if (!result.second) {
        throw std::invalid_argument("Dupclicate customer");
    }
}

void CableCompany::addChannel(const std::string& name, int channel) {
    auto iterator = _customers.find(name);
    if (iterator != end(_customers)) {
        iterator->second.set(channel);
    }
    else {
        throw std::invalid_argument("Unknown customer");
    }
}

void CableCompany::removeChannel(const std::string& name, int channel) {
    auto iterator = _customers.find(name);
    if (iterator != end(_customers)) {
        iterator->second.reset(channel);
    }
    else {
        throw std::invalid_argument("Unknown customer");
    }
}

void CableCompany::addPackageToCustomer(const std::string& name, const std::string& package) {
    auto itPack = _packages.find(package);
    if (itPack == end(_packages)) {
        throw std::out_of_range("Invalid package");
    }

    auto itCust = _customers.find(name);
    if (itCust != end(_customers)) {
        itCust->second |= itPack->second;
    }
    else {
        throw std::invalid_argument("Unknown customer");
    }
}

void CableCompany::deleteCustomer(const std::string& name) {
    _customers.erase(name);
}

std::bitset<NUM_CHANNELS>& CableCompany::getCustomerChannels(const std::string& name) {
    auto it = _customers.find(name);
    if (it != end(_customers)) {
        return it->second;
    }
    throw std::invalid_argument("Unknown customer");
}
