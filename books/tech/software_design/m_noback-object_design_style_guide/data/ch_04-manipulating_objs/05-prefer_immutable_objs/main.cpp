#include <cassert>
namespace workspace {

class Year {
public:
    Year(const int year) : year_(year) {}

    Year next() const { return Year(year_ + 1); }

    bool operator == (const Year& other) const { return other.year_ == year_; }

private:
    int year_;
};

class Journal {
public:
    Journal(const Year& currentYear) : currentYear_(currentYear) {}

    void closeFinYear() { 
        // make some actions
        currentYear_ = currentYear_.next();
    }

    Year currentYear() const { return currentYear_; }


private:
    Year currentYear_;
};



void run() {
  {
    const Year year(2019);
    year.next();
    assert((Year(2019) == year));

    const Year nextYear = year.next();
    assert((Year(2019 + 1) == nextYear));
  }

  {
    Journal journal(Year(2019));
    journal.closeFinYear();

    assert((Year(2019 + 1) == journal.currentYear()));
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
