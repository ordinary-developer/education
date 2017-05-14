#include "card.hpp"

#include <iostream>

void card::assign(rank r, suit s) {
    rank_ = r;
    suit_ = s;
}

bool operator==(card a, card b) {
    return a.get_rank() == b.get_rank() and 
           a.get_suit() == b.get_suit();
}

bool operator!=(card a, card b) {
    return not (a == b);
}

std::ostream& operator<<(std::ostream& out, card c) {
    out << int(c.get_rank()) << " " << int(c.get_suit());
    return out;
}

std::istream& operator>>(std::istream& in, card c) {
    char s{}, r{};
    in >> r;
    in >> s;
    c.assign(r, s);

    return in;
}

bool acehigh_compare(card a, card b) {
    return a.get_rank() < b.get_rank();
}

bool acelow_compare(card a, card b) {
    return (card::ace == a.get_rank()) 
           ? true 
           : a.get_rank() < b.get_rank();
}


card_generator::card_generator() 
    : rankIndex_{ 2 }, suitIndex_{ card::diamonds } { }

card card_generator::operator()() {
    card c = card(rankIndex_, suitIndex_);

    if(++rankIndex_ > card::ace) {
        if (card::spades == suitIndex_) {
            rankIndex_ = 2;
            suitIndex_ = card::diamonds;
        }
        else {
            rankIndex_ = 2;
            ++suitIndex_;
        }
    }

    return c;
}
