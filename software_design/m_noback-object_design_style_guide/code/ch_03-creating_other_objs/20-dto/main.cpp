#include <map>
#include <string>
#include <cassert>
namespace workspace {

struct ScheduleMeetup {
    std::string title;
    std::string date;

    static ScheduleMeetup fromRawData(const std::map<std::string, std::string>& rawData) {
        std::map<std::string, std::string> raw(rawData);

        ScheduleMeetup scheduleMeetup;
        scheduleMeetup.title = raw["title"];
        scheduleMeetup.date = raw["date"];

        return scheduleMeetup;
    }
};


void run() {
    std::map<std::string, std::string> data;
    data["title"] = "title_val";
    data["date"] = "date_val";

    ScheduleMeetup scheduleMeetup = ScheduleMeetup::fromRawData(data);

    assert("title_val" == scheduleMeetup.title);
    assert("date_val" == scheduleMeetup.date);
}
} // workspace


#include <iostream>
int main() {
    std::cout << "[test] => ok" << std::endl;
    workspace::run();
    std::cout << std::endl;

    return 0;
}
