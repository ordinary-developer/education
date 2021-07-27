#include <regex>
#include <string>
#include <cassert>
namespace example_01 { // the "how to do it..." section

void run() {
    using namespace std::string_literals;
    
    auto pattern{ R"(^[A-Z0-9._%+-]+@[A-Z0-9.-]+\.[A-Z]{2,}$)"s };
    auto rx = std::regex{pattern};
    auto rxAux = std::regex{ pattern, std::regex_constants::icase };
    
    auto valid = std::regex_match("marius@domain.com"s, rx);
    assert(not valid);
    
    auto validAux = std::regex_match("marius@domain.com"s, rxAux);
    assert(validAux);
}
    
} // example_01


#include <iostream>
#include <iomanip>
#include <regex>
#include <string>
#include <cassert>
namespace example_02 { // the "how it works..." section

bool is_valid_email_format(std::string const & email) {
    using namespace std::string_literals;
    
    auto pattern{ R"(^[A-Z0-9._%+-]+@[A-Z0-9.-]+\.[A-Z]{2,}$)"s };
    auto rx = std::regex{ pattern, std::regex_constants::icase };
    return std::regex_match(email, rx);
}

auto ltest = [](std::string const & email) {
    std::cout << std::setw(30) << std::left << email << " : "
        << (is_valid_email_format(email) ? "valid format" : "invalid format") << '\n';
};

void run() {
    using namespace std::string_literals;
    
    ltest("JOHN.DOE@DOMAIN.COM"s);
    ltest("JOHNDOE@DOMAIL.CO.OK"s);
    ltest("JOHNDOE@DOMAIL.INFO"s);
    ltest("J.O.H.N_D.O.E@DOMAIN.INFO"s);
    ltest("ROOT@LOCALHOST"s);
    ltest("john.doe@domain.com"s);
}
    
} // example_02



#include <iostream>
int main() {
    std::cout << "example 01 => [ok]" << std::endl;
    example_01::run();
    std::cout << std::endl;
    
    std::cout << "example 02 => [ok]" << std::endl;
    example_02::run();
    std::cout << std::endl;
    
	return 0;
}
