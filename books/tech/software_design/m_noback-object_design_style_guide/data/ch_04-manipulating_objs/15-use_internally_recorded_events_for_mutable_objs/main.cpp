#include <string>
#include <vector>
#include <cassert>
#include <cstdio>
#include <iostream>
namespace workspace {
    
class Position {
public:
    Position(const int x, const int y) : x_(x), y_(y) {}
    
    Position toTheLeft(const int steps) const { return Position(x_ - steps, y_); }

    Position& operator = (const Position& other) {
        x_ = other.x_;
        y_ = other.y_;     
        
        return *this;
    }
    
    std::string asStr() const {
        char buf[0xff];
        sprintf(buf, "(%d, %d)", x_, y_);
        
        return std::string(buf);
    }
    
private:
    int x_;
    int y_;
};

struct Event {
    Event(const std::string& txt) : txt(txt) {}
    
    std::string txt;    
};

    
class Player {
public:
    Player(const Position& position) : position_(position) {}
    
    void moveLeft(const int steps) {
        position_ = position_.toTheLeft(steps);
        events_.push_back(Event(std::string("move_to_next_position: ") + position_.asStr()));
    }
    
    std::vector<Event> recordedEvents() const { return events_; }
 
private:
    Position position_;    
    std::vector<Event> events_;
};

void run() {
    Player player(Position(10, 20));
    
    player.moveLeft(4);
    
    const std::vector<Event>& events = player.recordedEvents();
    assert(1 == events.size());
    const std::string& txt = events.begin()->txt;
    assert(std::string("move_to_next_position: (6, 20)") == txt);
}

} // workspace



#include <iostream>
int main() {
    std::cout << "test => [ok]" << std::endl;
    workspace::run();
    std::cout << std::endl;
    
    return 0;
}
