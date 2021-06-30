#include <string>
#include <stdexcept>
#include <vector>
#include <cassert>
namespace workspace {

class Line {
public:
    static Line create(const std::string& str) { return Line(str); }

    std::string value() const { return val_; }

private:
    Line(const std::string& val) : val_(val) {}

    const std::string val_;
};

class Event {
public:
    Event(const std::string& txt) : txt_(txt) {}

    bool operator==(const Event& other) const { return other.txt_ == txt_; }
private:
    const std::string txt_;
};


class SalesInvoice {
public:
    static SalesInvoice create() {
        return SalesInvoice(false, std::vector<Line>(), std::vector<Event>());
    }

    void addLine(const Line& line) {
        if (finalized_)
            throw std::domain_error("finalized_ == true");

        lines_.push_back(line);

        events_.push_back(Event("add_line"));
    }
    
    void finalize() { 
        finalized_ = true;
        events_.push_back(Event("finalize"));
    }

    std::vector<Event> events() const { return events_; }

private:
    SalesInvoice(
        const bool finalized,
        const std::vector<Line> lines,
        const std::vector<Event>& events
        )
        : finalized_(finalized), lines_(lines), events_(events) {}

    bool finalized_;
    std::vector<Line> lines_;
    std::vector<Event> events_;
};


void run() {
    SalesInvoice invoice = SalesInvoice::create();

    invoice.addLine(Line::create("item"));
    invoice.finalize();

    std::vector<Event> expectedEvents;
    expectedEvents.push_back(Event("add_line"));
    expectedEvents.push_back(Event("finalize"));
    assert((expectedEvents == invoice.events()));
}
} // workspace


#include <iostream>
int main() {
    std::cout << "[test] => ok" << std::endl;
    workspace::run();
    std::cout << std::endl;

    return 0;
}
