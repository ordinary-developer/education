#include <map>
#include <string>
#include <cassert>
namespace workspace {

struct ScheduleMeetup {
    std::string title;
    std::string date;

    std::map<std::string, std::string> validate() const {
        std::map<std::string, std::string> errs;

        if (this->title.empty())
            errs["title"] = "validation.empty_title";

        if (this->date.empty())
            errs["date"] = "validation.empty_date";

        return errs;
    }    
};


void run() {
  {
    const std::map<std::string, std::string> errs = 
        ScheduleMeetup().validate();
    assert(2 == errs.size());
  }

  {
    ScheduleMeetup scheduleMeetup;
    scheduleMeetup.title = "title";
    scheduleMeetup.date = "date";

    const std::map<std::string, std::string> errs = scheduleMeetup.validate();

    assert((errs.empty()));
  }

}
} // workspace


#include <iostream>
int main() {
    std::cout << "[test] => ok" << std::endl;
    workspace::run();
    std::cout << std::endl;

    return 0;
}
