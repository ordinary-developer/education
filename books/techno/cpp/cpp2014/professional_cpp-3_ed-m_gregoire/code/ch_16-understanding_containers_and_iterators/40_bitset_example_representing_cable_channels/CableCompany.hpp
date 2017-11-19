#ifndef CABLE_COMPANY_HPP
#define CABLE_COMPANY_HPP

#include <cstddef>
#include <bitset>
#include <map>
#include <string>

const size_t NUM_CHANNELS = 10;

class CableCompany {
    public:
        void addPackage(const std::string& packageName,
                const std::bitset<NUM_CHANNELS>& channels); 
        void removePackage(const std::string& packageName);

        void newCustomer(const std::string& name, const std::string& package);
        void newCustomer(
           const std::string& name, const std::bitset<NUM_CHANNELS>& channels);

        void addChannel(const std::string& name, int channel);
        void removeChannel(const std::string& name, int channel);

        void addPackageToCustomer(const std::string& name, 
                const std::string& package);

        void deleteCustomer(const std::string& name);

        std::bitset<NUM_CHANNELS>& getCustomerChannels(const std::string& name);
    private:
        typedef std::map<std::string, std::bitset<NUM_CHANNELS>> MapType;
        MapType _packages, _customers;
};

#endif
