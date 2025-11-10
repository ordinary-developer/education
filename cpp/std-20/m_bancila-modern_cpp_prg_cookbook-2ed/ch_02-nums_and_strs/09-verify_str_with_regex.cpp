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
#include <tuple>
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


bool is_valid_email_format_no_case(std::string const & email) {
    using namespace std::string_literals;
    auto rx = std::regex{ R"(^[A-Z0-9._%+-]+@[A-Z0-9.-]+\.[A-Z]{2,}$)"s,
        std::regex_constants::icase };
        
    return std::regex_match(email, rx);
}

auto ltest_no_case = [](std::string const & email) {
    std::cout << std::setw(30) << std::left << email << " : "
        << (is_valid_email_format_no_case(email) ? "valid format" : "invalid format") << '\n';
};


template <typename CharT>
using tstring = std::basic_string<CharT, std::char_traits<CharT>, std::allocator<CharT>>;

template <typename CharT>
bool is_valid_format_tmpl(tstring<CharT> const & pattern, tstring<CharT> const & txt) {
    auto rx = std::basic_regex<CharT>{
        pattern, std::regex_constants::icase };
    
    return std::regex_match(txt, rx);
}

bool is_valid_email_format_w(std::wstring const & txt) {
    using namespace std::string_literals;
    
    return is_valid_format_tmpl(LR"(^[A-Z0-9._%+-]+@[A-Z0-9.-]+\.[A-Z]{2,}$)"s, txt);
}

auto ltest_w = [](std::wstring const & email) {
    std::wcout << std::setw(30) << std::left << email << L" : "
        << (is_valid_email_format_w(email) ? L"valid" : L"invalid") << '\n';
};

std::tuple<bool, std::string, std::string, std::string> is_valid_email_format_with_result(std::string const & email) {
    using namespace std::string_literals;
    
    auto rx = std::regex{ R"(^([A-Z0-9._%+-]+)@([A-Z0-9.-]+)\.([A-Z]{2,}$))"s, std::regex_constants::icase };
    auto result = std::smatch{};
    auto success = std::regex_match(email, result, rx);
    
    return std::make_tuple(
        success,
        success ? result[1].str() : "",
        success ? result[2].str() : "",
        success ? result[3].str() : "");
}

auto ltest_with_matches = [](std::string const & email) {
    auto [valid, localpart, hostname, dnslabel ] = 
        is_valid_email_format_with_result(email);
        
    std::cout << std::setw(30) << std::left
        << email << " : "
        << std::setw(10) << (valid ? "valid" : "invalid" )
        << '\n' << " local = " << localpart << "; domain = " << hostname << "; dns = " << dnslabel
        << '\n';
};


void run() {
    {
        using namespace std::string_literals;
    
        ltest("JOHN.DOE@DOMAIN.COM"s);
        ltest("JOHNDOE@DOMAIL.CO.OK"s);
        ltest("JOHNDOE@DOMAIL.INFO"s);
        ltest("J.O.H.N_D.O.E@DOMAIN.INFO"s);
        ltest("ROOT@LOCALHOST"s);
        ltest("john.doe@domain.com"s);
    }
    
    {
        using namespace std::string_literals;
    
        ltest_no_case("JOHN.DOE@DOMAIN.COM"s);
        ltest_no_case("JOHNDOE@DOMAIL.CO.OK"s);
        ltest_no_case("JOHNDOE@DOMAIL.INFO"s);
        ltest_no_case("J.O.H.N_D.O.E@DOMAIN.INFO"s);
        ltest_no_case("ROOT@LOCALHOST"s);
        ltest_no_case("john.doe@domain.com"s);
    }
    
    {
        using namespace std::string_literals;
        
        ltest_w(L"JOHN.DOE@DOMAIN.COM"s);
        ltest_w(L"JOHNDOE@DOMAIL.CO.UK"s);
        ltest_w(L"JOHNDOE@DOMAIL.INFO"s);
        ltest_w(L"J.O.H.N_D.O.E@DOMAIN.INFO"s);
        ltest_w(L"ROOT@LOCALHOST"s);
        ltest_w(L"john.doe@domain.com"s);
    }
    
    {
        using namespace std::string_literals;
        
        ltest_with_matches("JOHN.DOE@DOMAIN.COM"s);
        ltest_with_matches("JOHNDOE@DOMAIL.CO.UK"s);
        ltest_with_matches("JOHNDOE@DOMAIL.INFO"s);
        ltest_with_matches("J.O.H.N_D.O.E@DOMAIN.INFO"s);
        ltest_with_matches("ROOT@LOCALHOST"s);
        ltest_with_matches("john.doe@domain.com"s);
    }   
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
