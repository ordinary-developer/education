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


class SalesInvoice {
public:
    static SalesInvoice create() {
        return SalesInvoice(false, std::vector<Line>());
    }

    void addLine(const Line& line) {
        if (finalized_)
            throw std::domain_error("finlized_ == true");

        lines_.push_back(line);
    }
    
    void finalize() { finalized_ = true; }

private:
    SalesInvoice(const bool finalized, const std::vector<Line> lines)
        : finalized_(finalized), lines_(lines) {}

    bool finalized_;
    std::vector<Line> lines_;
};


void run() {
  {
    SalesInvoice invoice = SalesInvoice::create();
    invoice.addLine(Line::create("item"));
    invoice.finalize();
  }

  {
    SalesInvoice invoice = SalesInvoice::create();
    invoice.addLine(Line::create("item 01"));


    bool wasEx = false;
    invoice.finalize();
    try {
        invoice.addLine(Line::create("item 02"));
    }
    catch (const std::domain_error&) { assert((wasEx = true)); }
    catch (...) { assert(false); }
    assert(wasEx);
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
