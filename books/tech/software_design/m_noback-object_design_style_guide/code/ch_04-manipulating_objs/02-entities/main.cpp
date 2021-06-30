#include <map>
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


class SalesInvoiceId {
public:
    SalesInvoiceId(const std::string& val) : val_(val) {}

    std::string value() const { return val_; }

private:
    const std::string val_;
};


class SalesInvoice {
public:
    static SalesInvoice create(const SalesInvoiceId id) {
        return SalesInvoice(id, false, std::vector<Line>());
    }

    void addLine(const Line& line) {
        if (finalized_)
            throw std::domain_error("finlized_ == true");

        lines_.push_back(line);
    }
    
    void finalize() { finalized_ = true; }

    SalesInvoiceId Id() const { return id_; }

private:
    SalesInvoice(const SalesInvoiceId id, const bool finalized, const std::vector<Line> lines)
        : id_(id), finalized_(finalized), lines_(lines) {}

    const SalesInvoiceId id_;

    bool finalized_;
    std::vector<Line> lines_;
};


class SalesInvoiceRepo {
public:
    // dumb impl
    SalesInvoiceId nextId() const { return SalesInvoiceId("next string"); }

    // dumb impl
    SalesInvoice getBy(const SalesInvoiceId& id) const { return SalesInvoice::create(id); } 

    // dumb impl
    void save(const SalesInvoice& invoice) {}  
};


void run() {
    SalesInvoiceRepo repo;    
    const SalesInvoiceId id = repo.nextId();

    {
    SalesInvoice invoice = SalesInvoice::create(id);
    invoice.addLine(Line::create("item 01"));
    repo.save(invoice);
    }

    {
    SalesInvoice invoice = repo.getBy(id);
    invoice.addLine(Line::create("item 02"));
    repo.save(invoice);
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
