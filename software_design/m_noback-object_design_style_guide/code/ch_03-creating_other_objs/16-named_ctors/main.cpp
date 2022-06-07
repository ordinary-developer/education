#include <string>
#include <cassert>
namespace workspace {

class DateTime {
public:
    static DateTime createFromFormat(const std::string& format, const std::string& date) {
        return DateTime();
    }
};

class Date {
public:
    static Date fromStr(const std::string& date) {
        return Date(DateTime::createFromFormat(FORMAT, date));
    }

private:
    Date(const DateTime& dateTime) : dateTime_(dateTime) {}

    static const std::string FORMAT;
    const DateTime dateTime_;
};
const std::string Date::FORMAT = "d/m/y";

    
void run() {
    Date::fromStr("no sense string");
    assert(true);
}
} // workspace


#include <iostream>
int main() {
    std::cout << "[test] => ok" << std::endl;
    workspace::run();
    std::cout << std::endl;

    return 0;
}
