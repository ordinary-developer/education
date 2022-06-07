#include <map>
#include <string>
namespace workspace {

struct ScheduleMeetup {
    std::string title;
    std::string date;
};

class ScheduleMeetupService {
public:
    void execute(const ScheduleMeetup& scheduleMeetup) const { }
};

class MeetupController {
public:
    MeetupController(const ScheduleMeetupService& scheduleMeetupService)
        : scheduleMeetupService_(scheduleMeetupService) {}

    void scheduleMeetupAction(const std::map<std::string, std::string>& rawData) const {
        std::map<std::string, std::string> raw(rawData);

        ScheduleMeetup scheduleMeetup;
        scheduleMeetup.title = raw["title"];
        scheduleMeetup.date = raw["date"];

        this->scheduleMeetupService_.execute(scheduleMeetup);
    }

private:
    ScheduleMeetupService scheduleMeetupService_;
};


void run() {
    std::map<std::string, std::string> rawData;
    rawData["title"] = "title";
    rawData["date"] = "date";

    MeetupController(ScheduleMeetupService()).scheduleMeetupAction(rawData);
}
} // workspace


#include <iostream>
int main() {
    std::cout << "[test] => ok" << std::endl;
    workspace::run();
    std::cout << std::endl;

    return 0;
}
