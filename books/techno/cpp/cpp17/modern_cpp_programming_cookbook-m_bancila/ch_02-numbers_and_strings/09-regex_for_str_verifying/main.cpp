#include <string>
#include <regex>
#include <iostream>
#include <cassert>
namespace example_01 { // -> base use of std::regex
void run() {
    using namespace std::string_literals;    
    
    auto const pattern{ R"(^[A-Z0-9._%+-]+@[A-Z0-9.-]+\.[A-Z]{2,}$)"s };
    auto const rx_s_case = std::regex{ pattern };
    auto const rx_i_case = std::regex{ pattern, std::regex_constants::icase };
    auto const str_to_check{ "marius@domain.com"s };
    
    assert(
        not std::regex_match(str_to_check, rx_s_case)
        and            
        std::regex_match(str_to_check, rx_i_case));
    
    std::cout << "[ok]" << std::endl;
}
} // example_01

#include <string>
#include <regex>
#include <iostream>
#include <iomanip>
#include <cassert>
namespace example_02 { // -> case-sensitive use of std::regex 
    
using namespace std::string_literals;

bool is_valid_email_fmt(std::string const& email) {
    return std::regex_match(email,
        std::regex{ R"(^[A-Z0-9._%+-]+@[A-Z0-9._]+\.[A-Z]{2,}$)"s });                            
}
    
void run() {
    auto ltest = [](std::string const& email) {
        std::cout << std::setw(30) << std::left
            << email << " : "
            << (is_valid_email_fmt(email) ?
                "valid_format" : "invalid format")
            << std::endl;
    };
    
    std::cout << std::endl;
    ltest("JOHN.DOE@DOMAIN.COM"s);
    ltest("JOHNDOE@DOMAIL.CO.UK"s);
    ltest("JOHNDOE@DOMAIL.INFO"s);
    ltest("J.O.H.N_D.O.E@DOMAIN.INFO"s);
    ltest("ROOT@LOCALHOST"s);
    ltest("john.doe@domain.com"s);
    
    std::cout << "[ok]" << std::endl;
}
} // example_02


#include <string>
#include <regex>
#include <iostream>
#include <iomanip>
namespace example_03 { // case-insensitive use of std::regex
    
using namespace std::string_literals;    
    
bool is_valid_email_fmt(std::string const& email) {
    return std::regex_match(email,
        std::regex{ R"([A-Z0-9._%+-]+@[A-Z0-9.-]+\.[A-Z]{2,}$)"s,
            std::regex_constants::icase });                   
}
void run() {
    auto const ltest = [](std::string const& email) {
        std::cout << std::setw(30) << std::left
            << email << " : "
            << (is_valid_email_fmt(email) ?
                "valid format" : "invalid format")
            << std::endl;
    };
    
    std::cout << std::endl;
    ltest("JOHN.DOE@DOMAIN.COM"s);
    ltest("JOHNDOE@DOMAIL.CO.UK"s);
    ltest("JOHNDOE@DOMAIL.INFO"s);
    ltest("J.O.H.N_D.O.E@DOMAIN.INFO"s);
    ltest("ROOT@LOCALHOST"s);
    ltest("john.doe@domain.com"s);
    
    std::cout << "[ok]" << std::endl;
}
} // example_03


#include <string>
#include <regex>
#include <iostream>
#include <iomanip>
namespace example_04 { // -> using std::regex both for std::string and std::wstring
    
using namespace std::string_literals;    

template <typename char_t>
using string_t = 
    std::basic_string<char_t, std::char_traits<char_t>, std::allocator<char_t>>;
    
template <typename char_t>
bool is_valid_fmt(string_t<char_t> const& pattern, string_t<char_t> const& txt) {
    return std::regex_match(txt, std::basic_regex<char_t>{
        pattern, std::regex_constants::icase });
}

bool is_valid_email_fmt_w(std::wstring const& txt) {
    return is_valid_fmt(
        LR"(^[A-Z0-9._%+-]+@[A-Z0-9.-]+\.[A-Z]{2,}$)"s,
        txt);
}

void run() {
    auto const ltest = [](auto const& email) {
        std::wcout << std::setw(30) << std::left
            << email << L" : "
            << (is_valid_email_fmt_w(email) ? L"valid" : L"invalid")
            << std::endl;
    };
    
    std::wcout << std::endl;
    ltest(L"JOHN.DOE@DOMAIN.COM"s);
    ltest(L"JOHNDOE@DOMAIN.CO.UK"s);
    ltest(L"JOHNDOE@DOMAIN.INFO"s);
    ltest(L"J.O.H.N_D.O.E@DOMAIN.INFO"s);
    ltest(L"ROOT@LOCALHOST"s);
    ltest(L"john.doe@domain.com"s);

    std::cout << "[ok]" << std::endl;
}
} // example_04


#include <string>
#include <regex>
#include <tuple>
#include <iostream>
#include <iomanip>
namespace example_05 { // -> using std::regex with group capturing

using namespace std::string_literals;

std::tuple<bool, std::string, std::string, std::string>
is_valid_email_fmt_with_result(std::string const& email) {
    auto result = std::smatch{};
    auto const success = std::regex_match(email, result,
        std::regex{ R"(^([A-Z0-9._%+-]+)@([A-Z0-9.-]+)\.([A-Z]{2,})$)"s,
            std::regex_constants::icase });
            
    return std::make_tuple(
        success,
        success ? result[1].str() : "nil"s,
        success ? result[2].str() : "nil"s,
        success ? result[3].str() : "nil"s);
}

void run() {
    auto const ltest = [](std::string const& email) {
        auto const [valid, localpart, hostname, dnslabel] = 
            is_valid_email_fmt_with_result(email);
        
        std::cout << std::setw(30) << std::left
            << email << " : "
            << std::setw(10) << (valid ? "valid" : "invalid")
            << "local = " << localpart << ";"
            << "domain = " << hostname << ";"
            << "dns = " << dnslabel << std::endl;
    };
    
    std::cout << std::endl;
    ltest("JOHN.DOE@DOMAIN.COM"s);
    ltest("JOHNDOE@DOMAIL.CO.UK"s);
    ltest("JOHNDOE@DOMAIL.INFO"s);
    ltest("J.O.H.N_D.O.E@DOMAIN.INFO"s);
    ltest("ROOT@LOCALHOST"s);
    ltest("john.doe@domain.com"s);
    std::cout << "[ok]";
}
    
} // example_05


#include <iostream>
int main() {
    std::cout << "example_01 => "; example_01::run(); std::cout << std::endl;
    std::cout << "example_02 => "; example_02::run(); std::cout << std::endl;
    std::cout << "example_03 => "; example_03::run(); std::cout << std::endl;
    std::cout << "example_04 => "; example_04::run(); std::cout << std::endl;
    std::cout << "example_05 => "; example_05::run(); std::cout << std::endl;

    
    return 0;
}