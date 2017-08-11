#include <regex>
#include <string>
#include <iostream>
namespace example1 {
void run() {
    std::regex r{"\\d{4}/(?:0?[1-9]|1[0-2])/(?:0?[1-9]|[1-2][0-9]|3[0-1])"};
    while (true) {
        std::cout << "enter a date (year/month/day) (q = quit): ";
        std::string str{};
        if (not getline(std::cin, str) or "q" == str)
            break;
        std::cout << (std::regex_match(str, r) ? "valid date" : "invalid date")
                  << std::endl;
    }
}
}

#include <regex>
#include <string>
#include <iostream>
namespace example2 {
void run() {
    std::regex r{"(\\d{4})/(0?[1-9]|1[0-2])/(0?[1-9]|[1-2][0-9]|3[0-1])"};    
    while (true) {
        std::cout << "enter a date (year/month/day) (q=quit): ";
        std::string str{};
        if (not getline(std::cin, str) or "q" == str)
            break;

        std::smatch m{};
        if (std::regex_match(str, m, r)) {
            int year = stoi(m[1]);
            int month = stoi(m[2]);
            int day = stoi(m[3]);
            std::cout << " Valid date: Year=" << year
                      << ", month=" << month
                      << ", day=" << day << std::endl;
        }
        else {
            std::cout << " Invalid date!" << std::endl;
        }
    }
}
}

#include <regex>
#include <iostream>
#include <string>
namespace example3 {
void run() {
    std::regex r{"//\\s*(.+)$"};
    while (true) {
        std::cout << "Enter a string with optional code comments (q=quit): ";
        std::string str{};
        if (not getline(std::cin, str) or "q" == str)
            break;

        std::smatch m{};
        if (std::regex_search(str, m, r))
            std::cout << "found comment '" << m[1] << "'" << std::endl;
        else
            std::cout << "no comment found!" << std::endl;
    }
}
}

#include <regex>
#include <string>
#include <iostream>
namespace example4 {
void run() {
    std::regex reg{"[\\w]+"};
    while (true) {
        std::cout << "Enter a string to split (q=quit): ";
        std::string str{};
        if (not getline(std::cin, str) or "q" == str)
            break;

        const std::sregex_iterator end{};
        for (std::sregex_iterator iter(std::begin(str), std::end(str), reg);
             iter != end;
             ++iter)
        {
            std::cout << "\"" << (*iter)[0] << "\"" << std::endl;
        }
    }
}
}

#include <regex>
#include <string>
#include <iostream>
namespace example5 {
void run() {
    std::regex reg{"[\\w]+"};
    while (true) {
        std::cout << "enter a string to split (q=quit): ";
        std::string str{};
        if (not getline(std::cin, str) or "q" == str)
            break;

        std::sregex_token_iterator const end{};
        for (std::sregex_token_iterator iter{std::begin(str), std::end(str), reg };
             end != iter;
             ++iter)
        {
            std::cout << "\"" << *iter << "\"" << std::endl;
        }
    }
}
}

#include <regex>
#include <string>
#include <iostream>
#include <vector>
namespace example6 {
void run() {
    std::regex reg{"^(\\d{4})/(0?[1-9]|1[0-2])/(0?[1-9]|[1-2][0-9]|3[0-1])$"};
    while (true) {
        std::string str{};
        if (not getline(std::cin, str) or "q" == str)
            break;
        std::vector<int> indices{ 2, 3 };
        std::sregex_token_iterator const end{};
        for (std::sregex_token_iterator iter{ std::begin(str), 
                                              std::end(str), 
                                              reg,
                                              indices };
             end != iter;
             ++iter)
        {
            std::cout << "\"" << *iter << "\"" << std::endl;
        }
    }
}
}

#include <regex>
#include <string>
#include <iostream>
namespace example7 {
void run() {
    std::regex reg{ R"(\s*[,;]\s*)" };
    while (true) {
        std::cout << "enter a string to split on ',' and ';' (q=quit): ";
        std::string str{};
        if (not getline(std::cin, str) or "q" == str)
            break;
        std::sregex_token_iterator const end{};
        for (std::sregex_token_iterator iter(std::begin(str), 
                                             std::end(str), 
                                             reg, 
                                             -1);
             iter != end;
             ++iter)
        {
            std::cout << "\"" << *iter << "\"" << std::endl;
        }
    }
}
}

#include <regex>
#include <string>
#include <iostream>
namespace example8 {
void run() {
    std::string const str{ "<body><h1>Header</h1><p>Some text</p></body>" };
    std::regex r{ "<h1>(.*)</h1><p>(.*)</p>" };
    std::string const format{ "H1=$1 and P=$2" };
    std::string result{ std::regex_replace(str, r, format) };
    std::cout << "Original string: '" << str << "'" << std::endl;
    std::cout << "New string :'" << result << "'" << std::endl;
}
}

#include <regex>
#include <string>
#include <iostream>
namespace example9 {
void run() {
    std::string const str{ "<body><h1>Header</h1><p>Some text</p></body>" };
    std::regex r{ "<h1>(.*)</h1><p>(.*)</p>" };
    std::string const format{"H1=$1 and P=$2"};
    std::string result = std::regex_replace(str, 
                                            r, 
                                            format, 
                                            std::regex_constants::format_no_copy);
    std::cout << "Original string: '" << str << "'" << std::endl;
    std::cout << "New string: '" << result << "'" << std::endl;
}
}

#include <regex>
#include <string>
#include <iostream>
namespace example10 {
void run() {
    std::regex reg{ "([\\w]+)" };
    std::string const format{ "$1\n" };
    while (true) {
        std::cout << "enter a string to split over multiple lines (q=quit): ";
        std::string str{};
        if (not getline(std::cin, str) or "q" == str)
            break;
        std::cout << std::regex_replace(str, 
                                        reg,
                                        format,
                                        std::regex_constants::format_no_copy)
                  << std::endl;
    }
}
}

int main() {
    example1::run();
    example2::run();
    example3::run();
    example4::run();
    example5::run();
    example6::run();
    example7::run();
    example8::run();
    example9::run();
    example10::run();

    return 0;
}


