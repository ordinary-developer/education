#include <memory>
#include <string>
#include <string_view>
#include <sstream>
#include <iostream>

class Formatter {
    public:
        virtual ~Formatter() = default;

        Formatter& withCustomerId(std::string_view customerId) {
            this->customerId = customerId;
            return *this;
        }

        Formatter& withForename(std::string_view forename) {
            this->forename = forename;
            return *this;
        }

        Formatter& withSurname(std::string_view surname) {
            this->surname = surname;
            return *this;
        }

        Formatter& withStreet(std::string_view street) {
            this->street = street;
            return *this;
        }

        Formatter& withZipCode(std::string_view zipCode) {
            this->zipCode = zipCode;
            return *this;
        }

        Formatter& withCity(std::string_view city) {
            this->city = city;
            return *this;
        }

        virtual std::string format() const = 0;

    protected:
        std::string customerId{ "000000" };
        std::string forename{ "n/a" };
        std::string surname{ "n/a" };
        std::string street { "n/a" };
        std::string zipCode{ "n/a" };
        std::string city{ "n/a" };
};
using FormatterPtr = std::unique_ptr<Formatter>;

class PlainTextFormatter : public Formatter {
    public:
        virtual std::string format() const override {
            std::stringstream formattedString{};
            formattedString << "[" << customerId << "]: "
                            << forename << " "
                            << surname << ", "
                            << street << ", "
                            << zipCode << " "
                            << city << ".";
            return formattedString.str();
        }
};

class XmlFormatter : public Formatter {
    public:
        virtual std::string format() const override {
            std::stringstream formattedString{};
            formattedString 
                << "<customer id=\"" << customerId << "\">\n"
                << "  <forename>" << forename << "</forename>\n"
                << "  <surname>" << surname << "</surname>\n"
                << "  <street>" << street << "</street>\n"
                << "  <zipcode>" << zipCode << "</zipcode>\n"
                << "  <city>" << city << "</city>\n"
                << "</customer>\n";
            return formattedString.str();
        }
};

class JsonFormatter : public Formatter {
    public:
        virtual std::string format() const override {
            std::stringstream formattedString{};
            formattedString 
                << "{\n" 
                << "  \"CustomerId : \"" << customerId << END_OF_PROPERTY
                << "  \"Forename: \"" << forename << END_OF_PROPERTY
                << "  \"Surname: \"" << surname << END_OF_PROPERTY
                << "  \"Street: \"" << street << END_OF_PROPERTY
                << "  \"ZIP code: \"" << zipCode << END_OF_PROPERTY
                << "  \"City: \"" << city << "\"\n" 
                << "}\n";
            return formattedString.str();
        }

    private:
        static constexpr const char* const END_OF_PROPERTY{ "\",\n" };
};

// dumb realization
class CustomerId {
    public:
        std::string toString() const { return "-1"; }
};

// dumb realization
class Address {
    public:
        std::string getStreet() const { return "Default street"; }
        std::string getZipCodeAsString() const { 
            return "1-22-333-4444-55555";
        }
        std::string getCity() const { return "Default City"; }
};

class Customer {
    public:
        Customer(CustomerId const& customerId,
                 std::string const& forename,
                 std::string const& surname,
                 Address const& address)
            : customerId_{ customerId },
              forename_{ forename },
              surname_{ surname },
              address_{ address }  { }

        std::string 
            getAsFormattedString(FormatterPtr const& formatter) const
        {
            return formatter->withCustomerId(customerId_.toString())
                             .withForename(forename_)
                             .withSurname(surname_)
                             .withStreet(address_.getStreet())
                             .withZipCode(address_.getZipCodeAsString())
                             .withCity(address_.getCity())
                             .format();
        }

    private:
        CustomerId customerId_;
        std::string forename_;
        std::string surname_;
        Address address_;
};

int main() {
    CustomerId customerId{};
    std::string forename{ "default forename" };
    std::string surname{ "default surname" };
    Address address{};

    Customer customer(customerId, forename, surname, address);

    FormatterPtr plainTextFormatter = 
        std::make_unique<PlainTextFormatter>();
    std::cout << customer.getAsFormattedString(plainTextFormatter) 
              << std::endl;

    FormatterPtr xmlFormatter = std::make_unique<XmlFormatter>();
    std::cout << customer.getAsFormattedString(xmlFormatter) << std::endl;

    FormatterPtr jsonFormatter = std::make_unique<JsonFormatter>();
    std::cout << customer.getAsFormattedString(jsonFormatter) << std::endl;

    return 0;
} 
